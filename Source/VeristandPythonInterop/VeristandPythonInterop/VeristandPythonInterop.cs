using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.CompilerServices;
using Microsoft.Win32;
using System.Diagnostics;
using NationalInstruments.VeriStand;
using NationalInstruments.VeriStand.ClientAPI;
using NationalInstruments.VeriStand.ClientAPI.Logging;
using NationalInstruments.VeriStand.SystemDefinitionAPI;
using System.Threading;
using System.IO;
using NationalInstruments.VeriStand.StimulusProfileDefinitionApi;
using NationalInstruments.VeriStand.Data;

[assembly: InternalsVisibleTo("VeristandPythonInteropTest")]
namespace VeristandPythonInterop
{
    public class VeriStandInterop
    {
        #region Properties

        internal Factory Factory { get; set; }
        internal Process VeriStandProcess { get; set; }
        internal IProject Project { get; set; }
        internal IWorkspace2 WorkSpace { get; set; }
        internal IModelManager2 ModelManager { get; set; }
        internal IDataLogging LoggingManager { get; set; }

        internal int MaxVeriStandLaunchTimeout { get; set; }
        internal int MaxVeriStandCloseTimeout { get; set; }
        private IDictionary<string, object> VSVariableList { get; set; }
        internal IList<string> channelsToRead = new List<string>();
        internal IList<string> channelsToWrite = new List<string>();
        internal string projectPath { get; set; }

        internal bool VeristandIsNotLaunched {
            get
            {                
                return (Process.GetProcessesByName("NI VeriStand").Length == 0);
            }
        }
        
        internal bool ProjectIsOpened {
            get {

                string[] activeProject = this.Factory.GetActiveProjects("");
                return (activeProject.Length > 0);
            }            
        }

        internal  StimulusProfile activeStimulus { get; set; }
        internal IStimulusProfileSession activeRTSequence { get; set; }

        #endregion 

        #region Constructor

        internal VeriStandInterop()        
        {
            this.MaxVeriStandLaunchTimeout = 2;
            this.MaxVeriStandCloseTimeout = 2;
            //this.VeristandIsNotLaunched = true;
            //this.ProjectIsOpened = false;
        }

        public static VeriStandInterop GetVeristandInterop()
        {
            if (VeriStandInterop.veriStand == null)
                VeriStandInterop.veriStand = new VeriStandInterop();

            return VeriStandInterop.veriStand;
        }

        public static VeriStandInterop GetNewVeristandInterop()
        {
            VeriStandInterop.veriStand = new VeriStandInterop();

            return VeriStandInterop.veriStand;
        }

        private static VeriStandInterop veriStand { get; set; }

        #endregion

        #region Public Methods

        public void DeployProject()
        {
            this.DeployProjectWithProgress(false);
        }

        public void DeployProjectWithProgress(bool showProgress)
        {
            ThrowExceptionIfVeriStandIsNotLaunched();

            ThrowExceptionIfProjectIsNotOpened();
            channelsToRead.Clear();
            channelsToWrite.Clear();

            string[] activeProject = this.Factory.GetActiveProjects("");
            if (activeProject[0] != this.projectPath) throw new InvalidOperationException(ErrorMessages.ErrorMessageDifferentProject);

            try
            {
                string[] activeSessions = this.Factory.GetAllDeployedSessions("");
            }
            catch (VeriStandException)
            {
                ErrChk(this.Project.Deploy());             
            }            
        }
        
        public void UndeployProject()
        {
            ThrowExceptionIfVeriStandIsNotLaunched();

            ThrowExceptionIfProjectIsNotOpened();

            ErrChk(this.Project.Undeploy());
            Thread.Sleep(500);
        }

        public void OpenWorkspace()
        {
            ThrowExceptionIfVeriStandIsNotLaunched();

            ThrowExceptionIfProjectIsNotOpened();

            ErrChk(this.Project.OpenWorkspace());
        }

        public void CloseWorkspace()
        {
            ThrowExceptionIfVeriStandIsNotLaunched();

            ThrowExceptionIfProjectIsNotOpened();

            ErrChk(this.Project.CloseWorkspace());
        }

        public void Connect()
        {
            ThrowExceptionIfVeriStandIsNotLaunched();

            ThrowExceptionIfProjectIsNotOpened();

            string[] activeProject = this.Factory.GetActiveProjects("");
            if (activeProject[0] != this.projectPath) throw new InvalidOperationException(ErrorMessages.ErrorMessageDifferentProject);

            try
            {
                string[] activeSessions = this.Factory.GetAllDeployedSessions("");
            }
            catch (VeriStandException)
            {
                if (GetTargetIP() == "localhost")
                {
                    ErrChk(this.Project.Deploy());
                }
                else
	            {
                    //Doesn't work for localhost
                    ErrChk(this.Project.Connect());
	            }
                
            }            
        }

        public void Disconnect()
        {
            ThrowExceptionIfVeriStandIsNotLaunched();

            ThrowExceptionIfProjectIsNotOpened();

            ErrChk(this.Project.Disconnect());
            Thread.Sleep(200);
        }



        public double GetChannelValue(string channelIdentidier)
        {
            ThrowExceptionIfVeriStandIsNotLaunched();

            double value = double.NaN;
            
            ErrChk(this.WorkSpace.GetSingleChannelValue(channelIdentidier, out value));

            return value;
        }

        public double GetTargetRate()
        {
            ThrowExceptionIfVeriStandIsNotLaunched(); 
            ThrowExceptionIfProjectIsNotOpened();
            SystemState state;
            string sysdef;
            string[] targetsArray;

            WorkSpace.GetSystemState(out state, out sysdef, out targetsArray);
            
            double value = double.NaN;

            SystemDefinition sysDef = new SystemDefinition(sysdef);
            Targets targets = sysDef.Root.GetTargets();
            Target target = targets.GetTargetList()[0];
            value = target.TargetRate;

            //ErrChk(this.WorkSpace.GetSingleChannelValue(channelIdentidier, out value));

            return value;
        }

        public string GetTargetIP()
        {
            ThrowExceptionIfVeriStandIsNotLaunched(); 
            ThrowExceptionIfProjectIsNotOpened();
            //SystemState state;
            string sysdef;            
            //string[] targetsArray;

            //WorkSpace.GetSystemState(out state, out sysdef, out targetsArray);

            SystemDefinition projDef = new SystemDefinition(this.projectPath);
            BaseNode[] projBaseNode = projDef.Root.FindChildrenByGUID("3a41ca74-36ec-4aff-9219-9d05c8f91208");

            string projDirectoryName = Path.GetDirectoryName(this.projectPath);
            sysdef = projDirectoryName + "\\" + projBaseNode[0].Name;             

            string value = "";

            SystemDefinition sysDef = new SystemDefinition(sysdef);
            Targets targets = sysDef.Root.GetTargets();
            Target target = targets.GetTargetList()[0];
            value = target.IPAddress;            

            //ErrChk(this.WorkSpace.GetSingleChannelValue(channelIdentidier, out value));

            return value;
        }

        public double [] GetMultipleChannelValues(string[] names)
        {
            ThrowExceptionIfVeriStandIsNotLaunched();

            double [] values;

            ErrChk(this.WorkSpace.GetMultipleChannelValues(names, out values));

            return values;
        }

        public string[] GetActiveProjects()
        {
            ThrowExceptionIfVeriStandIsNotLaunched();                     
            
            string[] activeProject = this.Factory.GetActiveProjects("");            
            
            return activeProject;
        }

        public string[] GetAllDeployedSessions()
        {
            ThrowExceptionIfVeriStandIsNotLaunched();

            string[] sessions = this.Factory.GetAllDeployedSessions("");

            return sessions;
        }

        public void SetMultipleChannelValues(string[] names, double[] values)
        {
            if (names == null || values == null)
                throw new ArgumentNullException();

            if (names.Length != values.Length)
                throw new ArgumentException(ErrorMessages.ErrorMessageArraySizeDoesNotEqual);

            ThrowExceptionIfVeriStandIsNotLaunched();

            ErrChk(this.WorkSpace.SetMultipleChannelValues(names, values));
        }

        public void SetMultipleChannelValuesSynch(string[] names, double[] values, out double writeTime)
        {
            if (names == null || values == null)
                throw new ArgumentNullException();

            if (names.Length != values.Length)
                throw new ArgumentException(ErrorMessages.ErrorMessageArraySizeDoesNotEqual);

            writeTime = -1;

            ThrowExceptionIfVeriStandIsNotLaunched();
            
            ErrChk(this.WorkSpace.SetMultipleChannelValues(names, values));

            bool writeFailed = true;
            Stopwatch sw = Stopwatch.StartNew();
            while (sw.Elapsed < TimeSpan.FromMilliseconds(10000))
            {
                double[] valuesGet = GetMultipleChannelValues(names);
                bool isEqual = Enumerable.SequenceEqual(values, valuesGet);
                if (isEqual)
                {
                    writeFailed = false;                    
                    writeTime = sw.ElapsedMilliseconds;
                    break;
                }

            }

            if (writeFailed) throw new InvalidOperationException(ErrorMessages.ErrorMessageChannelSynchWrite);
                       
        }

        public void SetChannelValue(string channelIdentifier, double value)
        {
            ThrowExceptionIfVeriStandIsNotLaunched();
            bool channel = true;
            if (channelIdentifier.Contains("/Simulation Models/") & channelIdentifier.Contains("/Parameters/")) channel = false;

            if (channel)
            {
                ErrChk(this.WorkSpace.SetSingleChannelValue(channelIdentifier, value));
            }
            else
            {
                ErrChk(ModelManager.SetSingleParameterValue(ChannelToParam(channelIdentifier), value));
            }
        }

        public void SetChannelValueSynch(string channelIdentifier, double value, out double writeTime)
        {            
            ThrowExceptionIfVeriStandIsNotLaunched();

            bool channel = true;
            if (channelIdentifier.Contains("/Simulation Models/") & channelIdentifier.Contains("/Parameters/")) channel = false;

            if (channel)
            {
                ErrChk(this.WorkSpace.SetSingleChannelValue(channelIdentifier, value));
            }
            else
            {
                ErrChk(ModelManager.SetSingleParameterValue(ChannelToParam(channelIdentifier), value));
            }
            
            bool writeFailed = true;
            writeTime = 0;

            Stopwatch sw = Stopwatch.StartNew();                        
            while (sw.Elapsed < TimeSpan.FromMilliseconds(1000))
            {
                double valueGet = GetChannelValue(channelIdentifier);
                if (valueGet == value) { 
                    writeFailed = false;
                    writeTime = sw.ElapsedMilliseconds;
                    break;
                }                  
                    
            }

            if (writeFailed) throw new InvalidOperationException(ErrorMessages.ErrorMessageChannelSynchWrite);

        }

        public void LaunchVeriStand()
        {
            this.LaunchVeriStand(false);
        }

        public void LaunchVeriStand(bool runAs)
        {
            // Console.WriteLine("LaunchVeriStand");
            /*if (Process.GetProcessesByName("NI VeriStand").Length != 0)
            {
                Console.WriteLine("CloseVeristand in launch");
                CloseVeristand();                
            }*/

            this.VeriStandProcess = new Process();
            //this.VeriStandProcess.StartInfo.UseShellExecute = false;
            if (runAs) { this.VeriStandProcess.StartInfo.UseShellExecute = true; }
            else { this.VeriStandProcess.StartInfo.UseShellExecute = false; };
            this.VeriStandProcess.StartInfo.FileName = this.ReadVeriStandLocationFromRegistry();
            this.VeriStandProcess.StartInfo.CreateNoWindow = false;
            
            if (runAs) this.VeriStandProcess.StartInfo.Verb = "runas";
            
            this.VeriStandProcess.Start();

            this.Factory = null;
            this.Factory = new Factory();

            Stopwatch sw = Stopwatch.StartNew();

            bool veristandHasThrownException = true;

            while (sw.Elapsed < TimeSpan.FromMinutes(this.MaxVeriStandLaunchTimeout))
            {
                veristandHasThrownException = false;

                try
                {
                    this.Factory.GetIWorkspace2();
                    this.Factory.GetActiveProjects("");
                    //this.Factory.GetIAlarm();
                    this.Factory.GetIAlarmManager2("");
                    this.Factory.GetIModelManager2("");
                    this.Factory.GetIStimulus2("");
                    this.Factory.GetIWorkspace2("");

                }
                catch (VeriStandException)
                {
                    veristandHasThrownException = true;
                }

                catch (System.Exception)
                {
                    Console.WriteLine("System Exception");
                    veristandHasThrownException = true;
                    this.CloseVeristand();
                    this.LaunchVeriStand(); //Is this correct? Deadlock
                }

                if (veristandHasThrownException == false)
                    break;
            }

            if (veristandHasThrownException == true)
                throw new InvalidOperationException(ErrorMessages.ErrorMessageVeriStandLaunch);

            string[] activeProject = this.Factory.GetActiveProjects("");
            if (activeProject.Length > 0) 
                {
                    this.Project = this.Factory.GetIProject("", activeProject[0], "", "");
                    this.Project.Close();
                }

            //this.ProjectIsOpened = false;
            //this.VeristandIsNotLaunched = false;
        }

        public void RunProject()
        {
            ThrowExceptionIfVeriStandIsNotLaunched();

            ThrowExceptionIfProjectIsNotOpened();
            channelsToRead.Clear();
            channelsToWrite.Clear();

            ErrChk(this.Project.Run());
        }

        public void CloseVeristand()
        {
            //Console.WriteLine("CloseVeristand");
            if (this.VeristandIsNotLaunched)
                return;

            if (this.ProjectIsOpened == false)
            {  //we need to open a project in order to quit....
                string pathPublic = System.Environment.GetFolderPath(Environment.SpecialFolder.CommonDocuments);
                string exampleProjectPath = pathPublic + @"\National Instruments\NI VeriStand 2014\Projects\Example\Sinewave Delay.nivsproj";
                this.OpenProject(exampleProjectPath);
            }

            ErrChk(this.Project.Quit());

            //this.ProjectIsOpened = false;
            //this.VeristandIsNotLaunched = true;

            //this.Project = null;

            TimeSpan maxDuration = TimeSpan.FromMinutes(this.MaxVeriStandCloseTimeout);
            //Console.WriteLine(this.MaxVeriStandCloseTimeout.ToString());

            Stopwatch sw = Stopwatch.StartNew();

            while (sw.Elapsed < TimeSpan.FromMinutes(this.MaxVeriStandCloseTimeout))
            {
                if (Process.GetProcessesByName("NI VeriStand").Length == 0)
                {
                    try
                    {
                        this.Factory.GetIWorkspace2();
                        Thread.Sleep(200);
                    }
                    catch (VeriStandException)
                    {
                        return;
                    }                   
                    
                }
            }            

            throw new InvalidOperationException(ErrorMessages.ErrorMessageVeriStandClose);
        }

        public void OpenProject(string projectPath)
        {
            ThrowExceptionIfVeriStandIsNotLaunched();

            if (this.ProjectIsOpened == true)
            {
                ErrChk(this.Project.Close());
                //this.ProjectIsOpened = false;
            }

            this.Project = this.Factory.GetIProject("", projectPath, "", "");
            this.projectPath = projectPath;

            this.WorkSpace = this.Factory.GetIWorkspace2();
            this.ModelManager = this.Factory.GetIModelManager2("");
            this.LoggingManager = this.Factory.GetIDataLogging("");

            //this.ProjectIsOpened = true;
        }

        public void CloseProject()
        {
            ThrowExceptionIfVeriStandIsNotLaunched();
            ThrowExceptionIfProjectIsNotOpened();
                
            ErrChk(this.Project.Close());
            //this.ProjectIsOpened = false;
            this.Project = null;
            this.projectPath = null;   
            
        }

        public void ShowProjectWindow()
        {
            ThrowExceptionIfVeriStandIsNotLaunched();

            ThrowExceptionIfProjectIsNotOpened();

            this.Project.Visible = true;

            Thread.Sleep(500);
        }

        public void StartDataLogging(string logConfigName, string lDescription, string lFilePath, double lTriggerHighLimit, double lTriggerLowLimit, 
            bool lReplaceFile, LogInfo.trigger lTriggerType, string lTriggerChannel, double lRate, string[] lFilePropertiesNames, string[] lFilePropertiesValues, 
            string[] lChannelsToLog)
        {            
            LogInfo lInfo = new LogInfo();            
            lInfo.description = lDescription;
            lInfo.file_path = lFilePath;
            lInfo.high_limit = lTriggerHighLimit;
            lInfo.low_limit = lTriggerLowLimit;
            lInfo.replace_file = lReplaceFile;
            lInfo.trigger_type = lTriggerType;
            lInfo.trigger_channel = lTriggerChannel;
            lInfo.rate = lRate;

            VSLogChannel[] lChannels;
            uint j = 0;
            IList<string> tempPrVariables = new List<string>(lChannelsToLog);

            
            int varCount = tempPrVariables.Count;
            lChannels = new VSLogChannel[varCount];
            foreach (string Channel in tempPrVariables)
            {
                VSLogChannel vSLogChan = new VSLogChannel();
                string[,] vSLogChanProperties = new string[1, 2] { { "channelName", Channel } };
                vSLogChan.FillParams(Channel, "", "", vSLogChanProperties);
                lChannels[j] = vSLogChan;
                j++;
            }

            LogChannel[] logChannels = new LogChannel[lChannels.GetLength(0)];

            for (int i = 0; i < lFilePropertiesNames.GetLength(0); i++)
            {
                lInfo.root_properties.Add(lFilePropertiesNames[i], lFilePropertiesValues[i]);
            }

            for (int i = 0; i < lChannels.GetLength(0); i++)
            {
                logChannels[i] = lChannels[i].lLogChannel;
            }

            lInfo.channels = logChannels;

            ErrChk(this.WorkSpace.StartDataLogging(logConfigName, lInfo));

        }

        public void StartDataLogging2(string logConfigName, string lDescription, string lFilePath, double fTriggerLevel,
            int iTriggerSlope, string lTriggerChannel, double lRate,string[] lFilePropertiesNames, string[] lFilePropertiesValues, string[] lChannelsToLog,
            double lDuration, double lPreTriggerDuration, bool lReplaceFile, string[] lChannelShortNames)
        {
            //VeriStand 2013 and later, logging for EXAM startMeasurement
            FileConflictOperation fileConflict = new FileConflictOperation();            

            if (lReplaceFile)
            {
                fileConflict = FileConflictOperation.OverwriteExisting;
            }
            else
            {
                fileConflict = FileConflictOperation.CreateUnique;
            }

            TdmsLogFile logFile = new TdmsLogFile(lFilePath, fileConflict);
            DataLoggingSpecification loggingSpec = new DataLoggingSpecification(logFile);
            DefaultTrigger defStopTrigger = new DefaultTrigger(false);
            Slope triggerSlope = new Slope();
            TdmsChannelGroup logChannelGroup = new TdmsChannelGroup("EXAM_Data");
            TdmsChannelGroup logChannelGroupInt = new TdmsChannelGroup("EXAM_Data_Internal");
            //Internal info channel
            logChannelGroupInt.AddChannel("System Time","Targets/Controller/System Channels/System Time");
            
            if (iTriggerSlope < 0){
                triggerSlope = Slope.Falling;

            }
            else 
            {
                triggerSlope = Slope.Rising; // Rising = 0
            }

            string lTriggerChannelLower = lTriggerChannel.ToLower();

            if (lTriggerChannel.Trim() != "" && lTriggerChannelLower.Trim() != "notrigger")
            {                
                //Console.WriteLine("@@" + lTriggerChannel+"@@");
                AnalogEdgeTrigger startTrigger = new AnalogEdgeTrigger(lTriggerChannel.Trim(), fTriggerLevel, triggerSlope, true);
                loggingSpec.StartTrigger = startTrigger;
            }
            else 
            {
                DefaultTrigger startTrigger = new DefaultTrigger(true);
                loggingSpec.StartTrigger = startTrigger;
            }             
            
            if (lDuration > 0) 
            {
                loggingSpec.PostTriggerDuration = lDuration;
                defStopTrigger.DefaultResult = true;
            }

            loggingSpec.StopTrigger = defStopTrigger;
            loggingSpec.PreTriggerDuration = lPreTriggerDuration;
            loggingSpec.Retriggerable = false;
            loggingSpec.LogDataAtTargetRate = false;
            loggingSpec.SegmentFileOnTrigger = false;
            loggingSpec.LogDataAgainstAbsoluteTimeBase = true;
            loggingSpec.CustomRate = lRate;
                                    
            uint j = 0;
            IList<string> tempPrVariables = new List<string>(lChannelsToLog);            
            int varCount = tempPrVariables.Count;
            
            foreach (string Channel in tempPrVariables)
            {
                //string channelName = Channel.Replace(@"/", @"_");
                //channelName = channelName.Replace(@" ", @"_"); 
                //TdmsChannel vSLogChan = new TdmsChannel(channelName,Channel);
                TdmsChannel vSLogChan = new TdmsChannel(Channel, Channel);                
                //TdmsProperty vSProperty = new TdmsProperty("channelName",TdmsPropertyDataType.String,(String)Channel);
                //vSLogChan.AddProperty(vSProperty);
                TdmsProperty vSProperty = new TdmsProperty("ChannelShortName", TdmsPropertyDataType.String, (String)lChannelShortNames[j]);
                vSLogChan.AddProperty(vSProperty);                
                logChannelGroup.AddChannel(vSLogChan);
                j++;
            }
            j = 0;

            for (int i = 0; i < lFilePropertiesNames.GetLength(0); i++)
            {               
                TdmsProperty vSProperty = new TdmsProperty(lFilePropertiesNames[i], TdmsPropertyDataType.String, (String)lFilePropertiesValues[i]);
                logFile.AddProperty(vSProperty);
            }
          
            logFile.AddChannelGroup(logChannelGroup);
            logFile.AddChannelGroup(logChannelGroupInt);
            logFile.Description = lDescription;
            loggingSpec.LogFile = logFile;            
            ErrChk(this.LoggingManager.StartDataLoggingSession(logConfigName,loggingSpec));

        }

        public string GetDataLogging2SessionState(string logConfigName)
        {
            DataLoggingSessionState sessionState;
            ErrChk(this.LoggingManager.GetDataLoggingSessionState(logConfigName,out sessionState));
            return sessionState.ToString();
        
        }

        public int GetDataLogging2State(string LogConfigName)
        {
            DataLoggingSessionState sessionState = new DataLoggingSessionState();
            ErrChk(this.LoggingManager.GetDataLoggingSessionState(LogConfigName, out sessionState));
            return Convert.ToInt32(sessionState);

        }

        public void StopDataLogging(string LogConfigName)
        {
            ErrChk(this.WorkSpace.StopDataLogging(LogConfigName));

        }

        public void StopDataLogging2(string LogConfigName)
        {
            string[] logFiles;
            ErrChk(this.LoggingManager.StopDataLoggingSession(LogConfigName, out logFiles));

        }

       

        public string GetAvailableChannelToRead(int channelIndex, out int availableChannelCount)
        {
            if (channelsToRead.Count == 0) GetAvailableChannelsToReadCount();
            availableChannelCount = channelsToRead.Count;
            return channelsToRead[channelIndex];
        }

        public string GetAvailableChannelToWrite(int channelIndex, out int availableChannelCount)
        {
            if (channelsToWrite.Count == 0) GetAvailableChannelsToWriteCount();
            availableChannelCount = channelsToWrite.Count;
            return channelsToWrite[channelIndex];
        }

        public int GetAvailableChannelsToReadCount() 
        {
            channelsToRead.Clear();
            channelsToRead = GetAvailableChannels(false);
            return channelsToRead.Count;
        }
        
        public int GetAvailableChannelsToWriteCount()
        {
            channelsToWrite.Clear();
            channelsToWrite = GetAvailableChannels(true);
            return channelsToWrite.Count;
        }

        public void StimulusExecuteAsynch(string stimulusFile, string uutSerialNumber)
        {
            this.activeStimulus = null;
            ThrowExceptionIfVeriStandIsNotLaunched();
            ThrowExceptionIfProjectIsNotOpened();
                        
            StimulusProfile myStimulus = new StimulusProfile(stimulusFile);
            this.activeStimulus = myStimulus;
            myStimulus.ExecuteAsync("", uutSerialNumber);
            
        }
        public int StimulusState()
        {
            ThrowExceptionIfVeriStandIsNotLaunched();
            ThrowExceptionIfProjectIsNotOpened();

            StepExecutionState activeStimulusState = this.activeStimulus.State;
            return (int)activeStimulusState;

        }

        public void RTSequenceExecuteAsynch(string RTSequenceFile, string[] ParamNames, string[] ParamValues, string[] ParamTypes)
        {
            this.activeRTSequence = null;
            ThrowExceptionIfVeriStandIsNotLaunched();
            ThrowExceptionIfProjectIsNotOpened();

            try { this.activeRTSequence.Undeploy(); }
            catch {};

            SequenceParameterAssignmentInfo[] basicParameters = new SequenceParameterAssignmentInfo[ParamNames.Count()];

            int j = 0;
            foreach (string Param in ParamNames)
            {                             

                switch (ParamTypes[j])
                    {
                        case "Path": ;
                              basicParameters[j] = new SequenceParameterAssignmentInfo(Param, new SystemDefinitionChannelResource(ParamValues[j]));
                        break;

                        case "Double":
                              basicParameters[j] = new SequenceParameterAssignmentInfo(Param, new DoubleValue(Convert.ToDouble(ParamValues[j])));
                        break;

                        default: ;
                        break;
                }                               
                
                j++;
            }
            
            //Specify sequences used
            SequenceCallInfo basicEngine = new SequenceCallInfo(RTSequenceFile,"Controller",basicParameters,false,10000);

            SequenceCallInfo[] mySequences = new SequenceCallInfo[1]; // {basicEngine};   
            mySequences[0] = basicEngine;

            //Create a Stimulus Profile Session            
            IStimulusProfileSession mySession = this.Factory.GetIStimulusProfileSession("", "PythonTestSession", mySequences, "");

            //Deploy the Stimulus Profile Session to the target
            string sessionID = "";
            Error myError;
            mySession.Deploy(false, out sessionID, out myError);            
            ErrChk(myError);

            //Run the session
            mySession.Run(out myError);
            ErrChk(myError);
            this.activeRTSequence = mySession;

        }
        public int RTSequenceState()
        {
            ThrowExceptionIfVeriStandIsNotLaunched();
            ThrowExceptionIfProjectIsNotOpened();

            string activeRTSequenceName = this.activeRTSequence.SequenceNames[0];
            SequenceState activeRTSequenceState = this.activeRTSequence[activeRTSequenceName].State;
            return (int)activeRTSequenceState;

        }

        public double RTSequenceGetReturnValue()
        {
            ThrowExceptionIfVeriStandIsNotLaunched();
            ThrowExceptionIfProjectIsNotOpened();

            string activeRTSequenceName = this.activeRTSequence.SequenceNames[0];
            ISequenceControl activeRTSequenceControl = this.activeRTSequence[activeRTSequenceName];
            DataValue RTSequenceReturnValue = activeRTSequenceControl.GetReturnValue();
            ScalarDataValue RTSequenceScalarReturnValue = (ScalarDataValue)RTSequenceReturnValue;
            return RTSequenceScalarReturnValue.ToDouble();

        }

        public void RTSequenceUndeploy()
        {
            ThrowExceptionIfVeriStandIsNotLaunched();
            ThrowExceptionIfProjectIsNotOpened();

            this.activeRTSequence.Undeploy();
            //return (int)activeStimulusState;

        }

        private static void ErrChk(Error error)
        {
            if (error.IsError)
                throw new Exception(String.Format("{0:X}", error.Code) + ": " + error.Message);
        }

        private List<string> GetAvailableChannels(bool onlyWriteEnabled)
        {            
            IWorkspace2 Workspace = this.WorkSpace;            
            string[] aliasOut = { };
            string[] channelOut = { };
            NodeInfo[] myNodeInfo = { };
            List<string> channelList = new List<string>();

            ThrowExceptionIfVeriStandIsNotLaunched();
           
            //Jiri: It is enough to add aliases names to list directly. It can be used as variable name. I tested that            
                        
            Workspace.GetAliasList(out aliasOut, out channelOut);            
            channelList = new List<string>();
            
            if (!onlyWriteEnabled)
            {
                foreach (string alias in aliasOut)
                {                
                    channelList.Add("Aliases/" + alias);
                }
                //This is tricky, because I dind't find a way how to chech if the alias is read only. So the aliases will be published as read only
                //TODO: Alias chceck?
            }

            Workspace.GetSystemNodeChannelList("", out myNodeInfo);
            
            foreach (NodeInfo node in myNodeInfo)
            {
                if (node.IsChannel)
                {
                    if (onlyWriteEnabled) 
                    {
                        if (node.IsWritable) channelList.Add(node.FullPath);
                    }
                    else
                    {
                        channelList.Add(node.FullPath);
                    }
                };
            }

            //channelCount = channelList.Count;
            return channelList;
        }

        #endregion

        #region Private Methods        
        internal string ReadVeriStandLocationFromRegistry()
        {
            string veriStandInstallFilePath = "";

            try
            {
                /*RegistryKey registryKey = Registry.LocalMachine.OpenSubKey("Software")
                    .OpenSubKey("National Instruments")
                    .OpenSubKey("VeriStand")
                    .OpenSubKey("2013");

                veriStandInstallFilePath = (string)registryKey.GetValue("InstallDir");*/
                veriStandInstallFilePath = NationalInstruments.VeriStand.Internal.DirectoryUtilities.InstallationDirectory;
            }
            catch (NullReferenceException)
            {
                throw new InvalidOperationException(ErrorMessages.ErrorMessageRegistryKeyMissing);
            }

            return veriStandInstallFilePath + @"\NI VeriStand.exe"; ;
        }

        internal string ChannelToParam(string variableName)
        {
            int index = variableName.IndexOf("/Simulation Models/Models/");
            variableName = variableName.Remove(0, index + 26);

            string removeString = "/Parameters";
            index = variableName.IndexOf(removeString);
            string variableNameParam = "";

            variableNameParam = (index < 0)
                    ? variableName
                    : variableName.Remove(index, removeString.Length);

            int instances = variableNameParam.Split('/').Length - 1;

            if (instances < 2) 
            {
                variableNameParam = variableNameParam.Split('/')[1];
            }                     
            return variableNameParam;
        }


        private void ThrowExceptionIfVeriStandIsNotLaunched()
        {
            if (this.VeristandIsNotLaunched)
                throw new InvalidOperationException(ErrorMessages.ErrorMessageVeriStandIsNotLaunched);
        }

        private void ThrowExceptionIfProjectIsNotOpened()
        {
            if (this.ProjectIsOpened == false)
                throw new InvalidOperationException(ErrorMessages.ErrorMessageShowHide);
        }              

        #endregion
    }

    public class VSLogChannel
    {
        public LogChannel lLogChannel;

        public void FillParams(string channelPath, string customName, string customGroup, string[,] lProperties)
        {
            LogChannel lLogChannel1 = new LogChannel(channelPath);
            lLogChannel1.channel_name = customName;
            lLogChannel1.channel_group = customGroup;

            for (int i = 0; i < lProperties.GetLength(0); i++)
            {
                lLogChannel1.properties.Add(lProperties[i, 0], lProperties[i, 1]);
            }

            this.lLogChannel = lLogChannel1;            
        }
    }

}

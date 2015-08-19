using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using NUnit.Framework;
using VeristandPythonInterop;
using NationalInstruments.VeriStand;
using System.Threading;
using NationalInstruments.VeriStand.ClientAPI;

namespace VeristandPythonInteropTest
{
    [TestFixture]
    public class VeriStandInteropIntegrationTests
    {
        VeriStandInterop VeriStandInterop { get; set; }

        private static string ExampleVeriStandProjectPath = @"d:\NI Projects\EXAM & cPython\Python development\cPython-Interface-for-NI-VeriStand\VS\Sinewave UnitTest.nivsproj"; 
        //private static string ExampleVeriStandProjectPath = @"C:\NI Projects\EXAM\EXAM Platform Interface\VS\EngineEXAM.nivsproj"; 
        

        [TestFixtureSetUp]
        public void SetupFixture()
        {
            //this.VeriStandInterop = VeriStandInterop.GetVeristandInterop();
            this.VeriStandInterop = VeriStandInterop.GetNewVeristandInterop();
            this.VeriStandInterop.LaunchVeriStand(false);
        }

        [TestFixtureTearDown]
        public void TearDownFixture()
        {
            this.VeriStandInterop.CloseVeristand();
        }

        [Test]
        public void OpenProjectShouldThrowExceptionIfProjectIsInvalid()
        {
            Assert.Throws<VeriStandException>(() =>
            {
                this.VeriStandInterop.OpenProject(@"this is an invalid project path");
            });

        }

        [Test]
        public void OpenProjectShouldOpenProject()
        {
            OpenExampleProject();

            Assert.IsNotNull(this.VeriStandInterop.Project);
        }

        [Test]
        public void RunShouldRunOpenedProject()
        {
            OpenExampleProject();

            this.VeriStandInterop.ShowProjectWindow();
            this.VeriStandInterop.RunProject();
        }

        [Test]
        public void CloseShouldCloseOpenedProject()
        {
            OpenExampleProject();

            this.VeriStandInterop.ShowProjectWindow();
            this.VeriStandInterop.CloseProject();
            Assert.IsNull(this.VeriStandInterop.Project);
        }

        [Test]
        public void CloseProjectShouldThrowExceptionIfProjectIsNotOpen()
        {
            Exception e = Assert.Throws<InvalidOperationException>(() =>
            {
                this.VeriStandInterop.CloseProject();
            });

            Assert.AreEqual(ErrorMessages.ErrorMessageProjectIsNotOpen, e.Message);
        }


        private void OpenExampleProject()
        {
            this.VeriStandInterop.OpenProject(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath);
        }

        [Test]
        public void GetChannelValue()
        {
            double valueToSet = 54.3;
            double writeTime = 0;

            OpenExampleProject();

            this.VeriStandInterop.RunProject();

            this.VeriStandInterop.SetChannelValueSynch("Aliases/UnitTest", valueToSet, out writeTime);

            //Thread.Sleep(61); // Synchronization delay for Workspace update

            double value = this.VeriStandInterop.GetChannelValue("Aliases/UnitTest");

            Assert.AreEqual(valueToSet, value);
        }

        [Test]
        public void GetAvailableChannelsShouldReturnChannelsToRead()
        {            
            OpenExampleProject();
            int retChannelCount = 0; 

            this.VeriStandInterop.RunProject();
            int channelCount = this.VeriStandInterop.GetAvailableChannelsToReadCount();
            string channel = this.VeriStandInterop.GetAvailableChannelToRead(5, out retChannelCount);

            Assert.AreEqual("Aliases/Sinewave Input", channel);
            Assert.AreEqual(348, channelCount);
            Assert.AreEqual(retChannelCount, channelCount);

            Exception e = Assert.Throws<System.ArgumentOutOfRangeException>(() =>
            {
                channel = this.VeriStandInterop.GetAvailableChannelToRead(10000, out retChannelCount);
            }, "");

            Assert.IsNotNull(e, "");
        }

        [Test]
        public void GetAvailableChannelsTrueShouldReturnChannelsToWrite()
        {
            OpenExampleProject();
            int retChannelCount = 0; 

            this.VeriStandInterop.RunProject();
            int channelCount = this.VeriStandInterop.GetAvailableChannelsToWriteCount();
            string channel = this.VeriStandInterop.GetAvailableChannelToWrite(5, out retChannelCount);

            Assert.AreEqual("Targets/Controller/System Channels/Tripped Low Value", channel);
            Assert.AreEqual(202, channelCount);
            Assert.AreEqual(retChannelCount, channelCount);

            Exception e = Assert.Throws<System.ArgumentOutOfRangeException>(() =>
            {
                channel = this.VeriStandInterop.GetAvailableChannelToWrite(10000, out retChannelCount);
            }, "");

            Assert.IsNotNull(e, "");
        }

        [Test]
        public void SetChannelValueSynch()
        {
            OpenExampleProject();
            
            double valueToSet = 54.3;
            double writeTime = 0;

            this.VeriStandInterop.RunProject();

            this.VeriStandInterop.SetChannelValueSynch("Aliases/UnitTest", valueToSet, out writeTime);

            double value = this.VeriStandInterop.GetChannelValue("Aliases/UnitTest");

            Assert.AreEqual(valueToSet, value);
        }

        [Test]
        public void SetParamValueSynch()
        {
            OpenExampleProject();

            double valueToSet = 54.3;
            double writeTime = 0;

            this.VeriStandInterop.RunProject();

            this.VeriStandInterop.SetChannelValueSynch("Targets/Controller/Simulation Models/Models/delay_sinewave/Parameters/z-block/Order", valueToSet, out writeTime);

            double value = this.VeriStandInterop.GetChannelValue("Targets/Controller/Simulation Models/Models/delay_sinewave/Parameters/z-block/Order");

            this.VeriStandInterop.SetChannelValueSynch("Targets/Controller/Simulation Models/Models/random/Parameters/Amplitude", valueToSet, out writeTime);

            value = this.VeriStandInterop.GetChannelValue("Targets/Controller/Simulation Models/Models/random/Parameters/Amplitude");

            Assert.AreEqual(valueToSet, value);
        }

        [Test]
        public void SetParamValue()
        {
            OpenExampleProject();

            double valueToSet = 54.3;           

            this.VeriStandInterop.RunProject();

            this.VeriStandInterop.SetChannelValue("Targets/Controller/Simulation Models/Models/delay_sinewave/Parameters/z-block/Order", valueToSet);
            Thread.Sleep(100);
            double value = this.VeriStandInterop.GetChannelValue("Targets/Controller/Simulation Models/Models/delay_sinewave/Parameters/z-block/Order");

            this.VeriStandInterop.SetChannelValue("Targets/Controller/Simulation Models/Models/random/Parameters/Amplitude", valueToSet);
            Thread.Sleep(100);
            value = this.VeriStandInterop.GetChannelValue("Targets/Controller/Simulation Models/Models/random/Parameters/Amplitude");

            Assert.AreEqual(valueToSet, value);
        }

        [Test]
        public void GetMultipleChannelValues()
        {
            OpenExampleProject();
            
            this.VeriStandInterop.RunProject();

            string[] channels = { "Aliases/UnitTest", "Aliases/UnitTest1" };

            double[] values = this.VeriStandInterop.GetMultipleChannelValues(channels);

            double timeSynch = 0;
            this.VeriStandInterop.SetMultipleChannelValuesSynch(channels, values, out timeSynch);
            
            //values = this.VeriStandInterop.GetMultipleChannelValues(channels);

            Assert.AreEqual(channels.Length, values.Length);
        }

        [Test]
        public void SetMultipleChannelValuesSynch()
        {
            OpenExampleProject();

            this.VeriStandInterop.RunProject();

            double[] valuesToSet = { -6, -9 };
            double WriteTime = 0;

            string[] channels = { "Aliases/UnitTest", "Aliases/UnitTest1" };

            this.VeriStandInterop.SetMultipleChannelValuesSynch(channels, valuesToSet, out WriteTime);
            double[] values = this.VeriStandInterop.GetMultipleChannelValues(channels);

            double[] temp = { 0, 0 };
            this.VeriStandInterop.SetMultipleChannelValuesSynch(channels, temp, out WriteTime);
            
            Assert.AreEqual(valuesToSet, values);
        }

        [Test]
        public void DeployShouldDeployProject()
        {
            this.VeriStandInterop.OpenProject(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath);

            this.VeriStandInterop.ShowProjectWindow();
            
            this.VeriStandInterop.DeployProject();            

            string[] activeSessions = this.VeriStandInterop.Factory.GetAllDeployedSessions("");
            string[] activeProject = this.VeriStandInterop.Factory.GetActiveProjects("");
            
            Assert.AreEqual(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath, activeProject[0]);
            Assert.AreEqual(1, activeProject.Length);
        }
        
        [Test]
        public void GetTargetRateShouldReturnTargetRate()
        {            
            this.VeriStandInterop.OpenProject(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath);
                     
            this.VeriStandInterop.ShowProjectWindow();

            this.VeriStandInterop.DeployProjectWithProgress(true);
            //this.VeriStandInterop.DeployProject();
                        
            Assert.AreEqual(100, this.VeriStandInterop.GetTargetRate());
        }

        [Test]
        public void DeployWithProgressShouldDeployProjectWithProgress()
        {
            this.VeriStandInterop.OpenProject(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath);

            this.VeriStandInterop.ShowProjectWindow();

            this.VeriStandInterop.DeployProjectWithProgress(true);

            string[] activeSessions = this.VeriStandInterop.Factory.GetAllDeployedSessions("");
            string[] activeProject = this.VeriStandInterop.Factory.GetActiveProjects("");

            Assert.AreEqual(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath, activeProject[0]);
            Assert.AreEqual(1, activeProject.Length);
        }

        [Test]
        public void DisconnectAndConnectShouldDisconnectAndReconnectToProject()
        {
            this.VeriStandInterop.OpenProject(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath);

            this.VeriStandInterop.ShowProjectWindow();

            this.VeriStandInterop.DeployProject();

            string[] activeSessions = this.VeriStandInterop.Factory.GetAllDeployedSessions("");
            string[] activeProject = this.VeriStandInterop.Factory.GetActiveProjects("");

            Assert.AreEqual(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath, activeProject[0]);
            Assert.AreEqual(1, activeProject.Length);

            this.VeriStandInterop.Disconnect();

            Exception e = Assert.Throws<VeriStandException>(() =>
            {
                activeSessions = this.VeriStandInterop.Factory.GetAllDeployedSessions("");
            }, ErrorMessages.ErrorMessageVeriStandUndeploy);

            Assert.IsNotNull(e, ErrorMessages.ErrorMessageVeriStandUndeploy);            

            this.VeriStandInterop.Connect();

            activeSessions = this.VeriStandInterop.Factory.GetAllDeployedSessions("");
            activeProject = this.VeriStandInterop.Factory.GetActiveProjects("");

            Assert.AreEqual(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath, activeProject[0]);
            Assert.AreEqual(1, activeProject.Length);
        }

        [Test]
        public void UnDeployShouldUnDeployProject()
        {
            this.VeriStandInterop.OpenProject(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath);

            this.VeriStandInterop.ShowProjectWindow();
            this.VeriStandInterop.DeployProject();
            Thread.Sleep(5000);

            this.VeriStandInterop.UndeployProject();

            Exception e = Assert.Throws<VeriStandException>(() =>
            {
                string[] activeSessions = this.VeriStandInterop.Factory.GetAllDeployedSessions("");
            },ErrorMessages.ErrorMessageVeriStandUndeploy);

            Assert.IsNotNull(e, ErrorMessages.ErrorMessageVeriStandUndeploy);
        }

        [Test]
        public void GetActiveProjectShouldReturnProjects()
        {
            this.VeriStandInterop.OpenProject(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath);

            this.VeriStandInterop.ShowProjectWindow();
            string[] activeProject = this.VeriStandInterop.GetActiveProjects();

            Assert.AreEqual(1, activeProject.Length);

            Assert.AreEqual(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath, activeProject[0]);            
        }

        [Test]
        public void OpenShouldClosePreviouslyOpenedProject()
        {
            OpenExampleProject();
            OpenExampleProject();

            Assert.AreEqual(1, this.VeriStandInterop.Factory.GetActiveProjects("").Length);
        }

        [Test]
        public void ShowProjectWindowShouldShowWindow()
        {
            OpenExampleProject();

            this.VeriStandInterop.ShowProjectWindow();

            Assert.IsTrue(this.VeriStandInterop.Project.Visible);
        }

        [Test]
        public void StartAndStopLoggingShouldStartAndStopLogging()
        {
            string logPath = @"C:\Temp\EXAM\Test.tdms";
            double lRate = 100;                   
            string[] lFilePropertiesNames, lFilePropertiesValues,lChannelsToLog;
            string taskName = "testLog";

            this.VeriStandInterop.OpenProject(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath);
            //this.VeriStandInterop.ShowProjectWindow();
            this.VeriStandInterop.DeployProject();
            //this.VeriStandInterop.OpenWorkspace();

            lChannelsToLog = new string [4] {"Targets/Controller/System Channels/System Time", "Targets/Controller/System Channels/HP Count",
            "Targets/Controller/System Channels/LP Count", "Targets/Controller/System Channels/Model Count"};
            lFilePropertiesNames = new string[3] { "LogPath", "LRate","TaskName"};
            lFilePropertiesValues = new string[3] { logPath , lRate.ToString() , taskName };

            this.VeriStandInterop.StartDataLogging(taskName, taskName, logPath, 0.5, -0.5, true, LogInfo.trigger.none, "", lRate, lFilePropertiesNames, lFilePropertiesValues, lChannelsToLog);
            
            Thread.Sleep(4000);
            this.VeriStandInterop.StopDataLogging(taskName);
            
        }

        [Test]
        public void StartAndStopLogging2ShouldStartAndStopLogging2()
        {
            string logPath = @"C:\Temp\EXAM\Test2.tdms";
            double lRate = 100;
            string[] lFilePropertiesNames, lFilePropertiesValues, lChannelsToLog, lChannelsToLogNames;
            string taskName = "testLog";

            this.VeriStandInterop.OpenProject(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath);
            //this.VeriStandInterop.ShowProjectWindow();
            this.VeriStandInterop.DeployProject();
            //this.VeriStandInterop.OpenWorkspace();

            lChannelsToLog = new string[4] {"Targets/Controller/System Channels/System Time", "Targets/Controller/System Channels/HP Count",
            "Targets/Controller/System Channels/LP Count", "Targets/Controller/System Channels/Model Count"};
            string[] lChannelShortNames = new string[4] {"System Time", "HP Count","LP Count", "Model Count"};
            lChannelsToLogNames = new string[4] {"System Time", "HP Count","LP Count", "Model Count"};
            lFilePropertiesNames = new string[3] { "LogPath", "LRate", "TaskName" };
            lFilePropertiesValues = new string[3] { logPath, lRate.ToString(), taskName };

            //this.VeriStandInterop.StartDataLogging2(taskName, taskName, logPath, 0.5, -0.5, true,LogInfo.trigger.none, "", lRate, lFilePropertiesNames, lFilePropertiesValues, lChannelsToLog, lChannelsToLogNames, 10, 4);
            this.VeriStandInterop.StartDataLogging2(taskName, taskName, logPath, 0.5, 1, "", lRate, lFilePropertiesNames, lFilePropertiesValues, lChannelsToLog, -1, 0, true, lChannelShortNames);
            //this.VeriStandInterop.StartDataLogging2(taskName, taskName, logPath, 0.5, 1, "", lRate, lFilePropertiesNames, lFilePropertiesValues, lChannelsToLog, 0, 0, true);
            int sessionState = this.VeriStandInterop.GetDataLogging2State(taskName);
            Console.WriteLine(sessionState.ToString());
            Thread.Sleep(4000);            
            sessionState = this.VeriStandInterop.GetDataLogging2State(taskName);
            Console.WriteLine(sessionState.ToString());
            Thread.Sleep(12000);
            sessionState = this.VeriStandInterop.GetDataLogging2State(taskName);
            Console.WriteLine(sessionState.ToString());
            this.VeriStandInterop.StopDataLogging(taskName);
            /*sessionState = this.VeriStandInterop.GetDataLogging2State(taskName);
            Console.WriteLine(sessionState.ToString());*/

        }

        [Test]
        public void StartAndStopLogging2TriggeredShouldStartAndStopLogging2Triggered()
        {
            string logPath = @"C:\Temp\EXAM\Test2T.tdms";
            double lRate = 100;
            string[] lFilePropertiesNames, lFilePropertiesValues, lChannelsToLog, lChannelsToLogNames;
            string taskName = "testLogTriggered";

            this.VeriStandInterop.OpenProject(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath);
            //this.VeriStandInterop.ShowProjectWindow();
            this.VeriStandInterop.DeployProject();
            //this.VeriStandInterop.OpenWorkspace();

            lChannelsToLog = new string[4] {"Targets/Controller/System Channels/System Time", "Targets/Controller/System Channels/HP Count",
            "Targets/Controller/System Channels/LP Count", "Targets/Controller/System Channels/Model Count"};
            string[] lChannelShortNames = new string[4] { "System Time", "HP Count", "LP Count", "Model Count" };
            lChannelsToLogNames = new string[4] { "System Time", "HP Count", "LP Count", "Model Count" };
            lFilePropertiesNames = new string[3] { "LogPath", "LRate", "TaskName" };
            lFilePropertiesValues = new string[3] { logPath, lRate.ToString(), taskName };

            
            this.VeriStandInterop.StartDataLogging2(taskName, taskName, logPath, 10, 1, "Targets/Controller/System Channels/System Time",
                lRate, lFilePropertiesNames, lFilePropertiesValues, lChannelsToLog, 9, 3, true, lChannelShortNames);
            
            int sessionState = this.VeriStandInterop.GetDataLogging2State(taskName);
            Console.WriteLine(sessionState.ToString());
            string sSessionState = this.VeriStandInterop.GetDataLogging2SessionState(taskName);
            Console.WriteLine(sSessionState);
            Thread.Sleep(4000);
            sessionState = this.VeriStandInterop.GetDataLogging2State(taskName);
            Console.WriteLine(sessionState.ToString());
            sSessionState = this.VeriStandInterop.GetDataLogging2SessionState(taskName);
            Console.WriteLine(sSessionState);            
            Thread.Sleep(20000);
            sessionState = this.VeriStandInterop.GetDataLogging2State(taskName);
            Console.WriteLine(sessionState.ToString());
            sSessionState = this.VeriStandInterop.GetDataLogging2SessionState(taskName);
            Console.WriteLine(sSessionState);            
            this.VeriStandInterop.StopDataLogging(taskName);
            /*sessionState = this.VeriStandInterop.GetDataLogging2State(taskName);
            Console.WriteLine(sessionState.ToString());*/

        }

        [Test]
        public void StimulusExecuteAsynchShouldStartStimulus()
        {
            string logPath = @"d:\NI Projects\EXAM & cPython\Python development\cPython-Interface-for-NI-VeriStand\VS\Stimulus Profiles\RT Sequence and Stimulus profile\Test Stimulus.nivsstimprof";

            this.VeriStandInterop.OpenProject(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath);
            this.VeriStandInterop.DeployProject();
            this.VeriStandInterop.OpenWorkspace();

            this.VeriStandInterop.StimulusExecuteAsynch(logPath, "10");

            Thread.Sleep(2000);

            Assert.AreEqual(2, this.VeriStandInterop.StimulusState());
            Thread.Sleep(10000);


        }

        [Test] 
        public void RTSequenceExecuteAsynchShouldStartRTSequence() 
        {
            string filePath = @"d:\NI Projects\EXAM & cPython\Python development\cPython-Interface-for-NI-VeriStand\VS\Stimulus Profiles\RT Sequence and Stimulus profile\Test  RT seq.nivsseq";

            this.VeriStandInterop.OpenProject(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath);
            this.VeriStandInterop.DeployProject();
            this.VeriStandInterop.OpenWorkspace();

            string[] paramNames = new string[2] {"UnitTest", "WaitParam"};
            string[] paramValues = new string[2] { "Aliases/UnitTest1", "5" };
            string[] paramTypes = new string[2] { "Path", "Double" };
            

            this.VeriStandInterop.RTSequenceExecuteAsynch(filePath,paramNames,paramValues,paramTypes);

            Thread.Sleep(2000);

            Assert.AreEqual(1, this.VeriStandInterop.RTSequenceState());
            Thread.Sleep(15000);
            Assert.AreEqual(4, this.VeriStandInterop.RTSequenceState());
            this.VeriStandInterop.RTSequenceUndeploy();            
        }

        [Test]
        public void RTSequenceExecuteAsynchShouldReturnValue()
        {
            string filePath = @"d:\NI Projects\EXAM & cPython\Python development\cPython-Interface-for-NI-VeriStand\VS\Stimulus Profiles\RT Sequence and Stimulus profile\Test  RT seq.nivsseq";

            this.VeriStandInterop.OpenProject(VeriStandInteropIntegrationTests.ExampleVeriStandProjectPath);
            this.VeriStandInterop.DeployProject();
            this.VeriStandInterop.OpenWorkspace();

            string[] paramNames = new string[2] { "UnitTest", "WaitParam" };
            string[] paramValues = new string[2] { "Aliases/UnitTest1", "5" };
            string[] paramTypes = new string[2] { "Path", "Double" };


            this.VeriStandInterop.RTSequenceExecuteAsynch(filePath, paramNames, paramValues, paramTypes);

            Thread.Sleep(2000);

            Assert.AreEqual(1, this.VeriStandInterop.RTSequenceState());
            Thread.Sleep(15000);
            Assert.AreEqual(4, this.VeriStandInterop.RTSequenceState());
            Assert.AreEqual(1, this.VeriStandInterop.RTSequenceGetReturnValue());
            this.VeriStandInterop.RTSequenceUndeploy();
        }
    }

    [TestFixture]
    public class VeriStandInteropLoggingTests
    {
        [Test]
        public void TDMSHandlerShouldReturnLineLogData()
        {
            string ExampleLogPath = @"d:\NI Projects\EXAM & cPython\Python development\cPython-Interface-for-NI-VeriStand\VS\Logs\EXAM_TEMP__NIVS_testMeas.tdms";
            VeriStandTDMSHandler TDMSHandler = new VeriStandTDMSHandler();
            TDMSHandler.TDMSOpen(ExampleLogPath);
            double[] logLine;
            double[] toCompare = { 1300, 2500, 20.51 };
            logLine = TDMSHandler.TDMSReadLine(600);
            TDMSHandler.TDMSClose();
            Assert.AreEqual(logLine, toCompare);

        }

        [Test]
        public void TDMSHandlerShouldReturnColumnLogData()
        {
            string ExampleLogPath = @"d:\NI Projects\EXAM & cPython\Python development\cPython-Interface-for-NI-VeriStand\VS\Logs\EXAM_TEMP__NIVS_testMeas_column.tdms";
            VeriStandTDMSHandler TDMSHandler = new VeriStandTDMSHandler();
            TDMSHandler.TDMSOpen(ExampleLogPath);
            double[] logColumn;
            double[] toCompare = { 20.43, 20.45, 20.47, 20.49, 20.51 };
            logColumn = TDMSHandler.TDMSReadColumn(2);
            TDMSHandler.TDMSClose();

            decimal[] logColumnDec = Array.ConvertAll(logColumn, x => (decimal)x);
            decimal[] toCompareDec = Array.ConvertAll(toCompare, x => (decimal)x);
            Assert.AreEqual(logColumnDec, toCompareDec);

        }       

        [Test]
        public void TDMSHandlerTimeShouldReturnColumnTimeLogData()
        {
            string ExampleLogPath = @"d:\NI Projects\EXAM & cPython\Python development\cPython-Interface-for-NI-VeriStand\VS\Logs\EXAM_TEMP__NIVS_testMeasTime.tdms";
            VeriStandTDMSHandler TDMSHandler = new VeriStandTDMSHandler();
            TDMSHandler.TDMSOpen(ExampleLogPath);
            double[] logColumn;
            double[] toCompare = { 4.05, 4.06, 4.07, 4.08, 4.09};
            logColumn = TDMSHandler.TDMSTimeColumn();
            TDMSHandler.TDMSClose();            

            var logColumnSubset = new double[toCompare.Count()];
            Array.Copy(logColumn, 0, logColumnSubset, 0, logColumnSubset.Length);

            decimal[] logColumnDec = Array.ConvertAll(logColumnSubset, x => (decimal)x);
            decimal[] toCompareDec = Array.ConvertAll(toCompare, x => (decimal)x);
            Assert.AreEqual(logColumnDec, toCompareDec);

        }

        [Test]
        public void TDMSLoggingPropertiesTest()
        {
            string ExampleLogPath = @"d:\NI Projects\EXAM & cPython\Python development\cPython-Interface-for-NI-VeriStand\VS\Logs\EXAM_TEMP__NIVS_testMeas_column.tdms";
            VeriStandTDMSHandler TDMSHandler = new VeriStandTDMSHandler();
            TDMSHandler.TDMSOpen(ExampleLogPath);
            
            double loggingRate = TDMSHandler.GetTDMSLoggingRate();
            long logLength = TDMSHandler.GetTDMSLogLength();
            int logChannelCount = TDMSHandler.GetTDMSLogChannelCount();
            string TDMSprop = TDMSHandler.GetTDMSLogChannelProperty(1,"datatype");

            TDMSHandler.TDMSClose();
                        
            Assert.AreEqual((decimal)loggingRate, 50);
            Assert.AreEqual((decimal)logLength, 5);
            Assert.AreEqual((decimal)logChannelCount, 3);
            Assert.AreEqual(TDMSprop, "DT_DOUBLE");

        }
    }
}

from ctypes import *
import datetime
import traceback
import sys
import os.path

from time import sleep

def errorCheck(stat):
    """Check the error status and print if error"""
    if stat != 0:
        print stat
        print c_char_p(veristandInterOp.GetLastErrorMessage())    
        quit()

#print os.path.abspath(file)
print "TestScript - CVI dll - test functions 1.8.py"
veristandInterOp = cdll.LoadLibrary("..\VeristandPythonInterop\Binaries\VeriStandCviDll.dll")
print veristandInterOp

print "LaunchVeriStand"
errorCheck(veristandInterOp.LaunchVeriStand())


print "OpenProject"
errorCheck(veristandInterOp.OpenProject("d:\\NI Projects\\EXAM & cPython\\Python development\\cPython-Interface-for-NI-VeriStand\\VS\\Sinewave UnitTest.nivsproj"))

print "ShowProjectWindow"
errorCheck(veristandInterOp.ShowProjectWindow())

print "DeployProject"
errorCheck(veristandInterOp.DeployProject())

print "OpenWorkspace"
errorCheck(veristandInterOp.OpenWorkspace())
sleep(2)

print "CloseWorkspace"
errorCheck(veristandInterOp.CloseWorkspace())
sleep(4)

print "OpenWorkspace"
errorCheck(veristandInterOp.OpenWorkspace())


print "GetChannelValue"
hValue = c_double(0.0)
errorCheck(veristandInterOp.GetChannelValue("Aliases/UnitTest", byref(hValue)))
print "value Aliases/UnitTest is: "
print hValue

print "SetChannelValue"
cValue = c_double(-4.0)
errorCheck(veristandInterOp.SetChannelValue("Aliases/UnitTest", cValue))

print "GetChannelValue"
errorCheck(veristandInterOp.GetChannelValue("Aliases/UnitTest", byref(hValue)))
print "value Aliases/UnitTest is: "
print hValue

print "SetChannelValueSynch"
cValue = c_double(-4.0)
cTime = c_double(0.0)
#cpTime =  pointer(cTime)
errorCheck(veristandInterOp.SetChannelValueSynch("Aliases/UnitTest", cValue, byref(cTime)))
print cTime

print "GetChannelValue"
errorCheck(veristandInterOp.GetChannelValue("Aliases/UnitTest", byref(hValue)))
print "value Aliases/UnitTest is: "
print hValue


hNumOfChannels = 2
hNumOfCharacters = 255
hChannels = ((c_char * hNumOfCharacters) * hNumOfChannels)() #must match longest channel
hChannels[0].value = "Aliases/UnitTest"
hChannels[1].value = "Aliases/UnitTest1"

hValues = (c_double * hNumOfChannels)()
for i in range(hNumOfChannels):
   hValues[i]=i+7
   print hValues[i]
   print hChannels[i].value
print hValues

hReturnValues = (c_double * hNumOfChannels)()
hpChannels =  pointer(hChannels)

print "GetMultipleChannels"
errorCheck(veristandInterOp.GetMultipleChannelValues(byref(hpChannels),hReturnValues, hNumOfChannels,hNumOfCharacters))
print "value Aliases/UnitTest is: "
print hReturnValues[0]
print "value Aliases/UnitTest1 is: "
print hReturnValues[1]

print "SetMultipleChannels"
errorCheck(veristandInterOp.SetMultipleChannelValues(byref(hpChannels),hValues, hNumOfChannels,hNumOfCharacters))

print "GetMultipleChannels"
errorCheck(veristandInterOp.GetMultipleChannelValues(byref(hpChannels),hReturnValues, hNumOfChannels,hNumOfCharacters))
print "value Aliases/UnitTest is: "
print hReturnValues[0]
print "value Aliases/UnitTest1 is: "
print hReturnValues[1]

print "SetMultipleChannelsSynch"
for i in range(hNumOfChannels):
   hValues[i]=i+2

errorCheck(veristandInterOp.SetMultipleChannelValuesSynch(byref(hpChannels),hValues, hNumOfChannels,hNumOfCharacters,byref(cTime)))
print cTime

print "GetMultipleChannels"
errorCheck(veristandInterOp.GetMultipleChannelValues(byref(hpChannels),hReturnValues, hNumOfChannels,hNumOfCharacters))
print "value Aliases/UnitTest is: "
print hReturnValues[0]
print "value Aliases/UnitTest1 is: "
print hReturnValues[1]


print "GetActiveProjects"
vNumberOfProjects=c_int(0)
vProject = (c_char * hNumOfCharacters)() 
errorCheck(veristandInterOp.GetActiveProject(byref(vProject),0, byref(vNumberOfProjects)))
print "Active projects are: "
print vProject.value

print "Is Open Project Running?"
vRunning=c_int(0)
errorCheck(veristandInterOp.IsOpenProjectRunning(byref(vRunning)))
print vRunning

print "ConfigureDatalogging"

lNumOfChannels = 2
lNumOfCharacters = 255
lRate = c_double(100.0)
lRateString = "100.0"
lFilePropertiesNamesLineLength = 255
lFilePropertiesValuesLineLength = 255
lChannelsToLogLineLength = 255
lFilePropertiesNamesLength = 3
lFilePropertiesValuesLength = 3
lChannelsToLogLength = 4
taskName = "testLog"
taskName2 = "testLog2"
taskName3 = "testLog3"
logPath = "C:\\Temp\\cPython\\pyTest.tdms"
logPath2 = "C:\\Temp\\cPython\\pyTest2.tdms"
logPath2T = "C:\\Temp\\cPython\\pyTest2T.tdms"
lTriggerHighLimit = c_double(0.5)
lTriggerLowLimit = c_double(-0.5)
lReplaceFile = c_int(1)
lTriggerType = c_int(0)
lTriggerChannel = " "
fTriggerLevel = c_double(60)
iTriggerSlope = c_int(1) #Raising
fDuration = c_double(-1)
fPreTriggerDuration = c_double(0)

lChannelsToLog = ((c_char * lChannelsToLogLineLength) * lChannelsToLogLength)() #must match longest channel
lChannelsToLog[0].value = "Targets/Controller/System Channels/System Time"
lChannelsToLog[1].value = "Targets/Controller/System Channels/HP Count"
lChannelsToLog[2].value =  "Targets/Controller/System Channels/LP Count"
lChannelsToLog[3].value = "Targets/Controller/System Channels/Model Count"
plChannelsToLog =  pointer(lChannelsToLog)

lFilePropertiesNames = ((c_char * lFilePropertiesNamesLineLength) * lFilePropertiesNamesLength)() #must match longest channel			
lFilePropertiesNames[0].value = "LogPath"
lFilePropertiesNames[1].value = "LRate"
lFilePropertiesNames[2].value = "TaskName"
plFilePropertiesNames =  pointer(lFilePropertiesNames)

lFilePropertiesValues = ((c_char * lFilePropertiesValuesLineLength) * lFilePropertiesValuesLength)() #must match longest channel			
lFilePropertiesValues[0].value = logPath
lFilePropertiesValues[1].value = lRateString
lFilePropertiesValues[2].value = taskName
plFilePropertiesValues =  pointer(lFilePropertiesValues)

lShortNames = ((c_char * lChannelsToLogLineLength) * lChannelsToLogLength)() #must match longest channel
lShortNames[0].value = "System Time"
lShortNames[1].value = "HP Count"
lShortNames[2].value = "LP Count"
lShortNames[3].value = "Model Count"
               
plShortNames =  pointer(lShortNames)

print "StartDatalogging"
errorCheck(veristandInterOp.StartDataLogging(taskName,taskName, logPath, lTriggerHighLimit,lTriggerLowLimit, lReplaceFile, lTriggerType,
                                             lTriggerChannel,lRate, byref(plFilePropertiesNames),lFilePropertiesNamesLength,
                                             lFilePropertiesNamesLineLength,byref(plFilePropertiesValues),
                                             lFilePropertiesValuesLength,lFilePropertiesValuesLineLength,
                                             byref(plChannelsToLog),lChannelsToLogLength,lChannelsToLogLineLength))
sleep(5)
print "StopDatalogging"
errorCheck(veristandInterOp.StopDataLogging(taskName))

print "StartDatalogging2"
errorCheck(veristandInterOp.StartDataLogging2(taskName2,taskName2, logPath2, fTriggerLevel, lReplaceFile,iTriggerSlope,
                                              lTriggerChannel,lRate, byref(plFilePropertiesNames),lFilePropertiesNamesLength,
                                              lFilePropertiesNamesLineLength,byref(plFilePropertiesValues),
                                              lFilePropertiesValuesLength,lFilePropertiesValuesLineLength,
                                              byref(plChannelsToLog),lChannelsToLogLength,lChannelsToLogLineLength,fDuration,fPreTriggerDuration,
                                              byref(plShortNames),lChannelsToLogLength,lChannelsToLogLineLength))
sleep(5)
print "StopDatalogging2"
errorCheck(veristandInterOp.StopDataLogging2(taskName2))

lTriggerChannel = "Targets/Controller/System Channels/System Time"
fTriggerLevel = c_double(30)
iTriggerSlope = c_int(1) #Raising
fDuration = c_double(9)
fPreTriggerDuration = c_double(3)

print "StartDatalogging2Triggered"
errorCheck(veristandInterOp.StartDataLogging2(taskName3,taskName3, logPath2T, fTriggerLevel, lReplaceFile,iTriggerSlope,
                                              lTriggerChannel,lRate, byref(plFilePropertiesNames),lFilePropertiesNamesLength,
                                              lFilePropertiesNamesLineLength,byref(plFilePropertiesValues),
                                              lFilePropertiesValuesLength,lFilePropertiesValuesLineLength,
                                              byref(plChannelsToLog),lChannelsToLogLength,lChannelsToLogLineLength,fDuration,fPreTriggerDuration,
                                              byref(plShortNames),lChannelsToLogLength,lChannelsToLogLineLength))

sLogStatus = (c_char * hNumOfCharacters)()
iLogStatus=c_int(0)
errorCheck(veristandInterOp.GetDataLogging2SessionState(taskName3,byref(sLogStatus)))
errorCheck(veristandInterOp.GetDataLogging2State(taskName3,byref(iLogStatus)))
print sLogStatus.value
print iLogStatus
sleep(15)
errorCheck(veristandInterOp.GetDataLogging2SessionState(taskName3,byref(sLogStatus)))
errorCheck(veristandInterOp.GetDataLogging2State(taskName3,byref(iLogStatus)))
print sLogStatus.value
print iLogStatus
sleep(30)
errorCheck(veristandInterOp.GetDataLogging2SessionState(taskName3,byref(sLogStatus)))
errorCheck(veristandInterOp.GetDataLogging2State(taskName3,byref(iLogStatus)))
print sLogStatus.value
print iLogStatus
print "StopDatalogging2Triggered"
errorCheck(veristandInterOp.StopDataLogging2(taskName3))

RTsequencePath = "d:\\NI Projects\\EXAM & cPython\\Python development\\cPython-Interface-for-NI-VeriStand\\VS\\Stimulus Profiles\\RT Sequence and Stimulus profile\\Test  RT seq.nivsseq"
stimulusPath = "d:\\NI Projects\\EXAM & cPython\\Python development\\cPython-Interface-for-NI-VeriStand\\VS\\Stimulus Profiles\\RT Sequence and Stimulus profile\\Test Stimulus.nivsstimprof"
UUTnumber = "010"
iStimulusState=c_int(0)
iRTSequenceState=c_int(0)
lParamNamesLineLength = 255
lParamValuesLineLength = 255
lParamTypesLineLength = 255
lParamNamesLength = 2
lParamValuesLength = 2
lParamTypesLength = 2

lParamNames = ((c_char * lParamNamesLineLength) * lParamNamesLength)() #must match longest channel
lParamNames[0].value = "UnitTest"
lParamNames[1].value = "WaitParam"
plParamNames =  pointer(lParamNames)

lParamValues = ((c_char * lParamValuesLineLength) * lParamValuesLength)() #must match longest channel
lParamValues[0].value = "Aliases/UnitTest1"
lParamValues[1].value = "5"
plParamValues =  pointer(lParamValues)

lParamTypes = ((c_char * lParamTypesLineLength) * lParamTypesLength)() #must match longest channel
lParamTypes[0].value = "Path"
lParamTypes[1].value = "Double"
plParamTypes =  pointer(lParamTypes)

#StimulusExecuteAsynch
errorCheck(veristandInterOp.StimulusExecuteAsynch(stimulusPath,UUTnumber))
print "Stimulus started"
sleep(2)
errorCheck(veristandInterOp.GetStimulusState(byref(iStimulusState)))
print iStimulusState
sleep(10)
errorCheck(veristandInterOp.GetStimulusState(byref(iStimulusState)))
print iStimulusState

#RTSequenceExecuteAsynch

errorCheck(veristandInterOp.RTSequenceExecuteAsynch(RTsequencePath,byref(plParamNames),lParamNamesLength, lParamNamesLineLength,
                                                    byref(plParamValues),lParamValuesLength, lParamValuesLineLength,
                                                    byref(plParamTypes),lParamTypesLength,lParamTypesLineLength))
print "RT Sequence started"
sleep(2)
errorCheck(veristandInterOp.GetRTSequenceState(byref(iRTSequenceState)))
print iRTSequenceState
sleep(15)
errorCheck(veristandInterOp.GetRTSequenceState(byref(iRTSequenceState)))
print iRTSequenceState
errorCheck(veristandInterOp.GetStimulusState(byref(iStimulusState)))

#mandatory
print "RT Sequence undeploy"
errorCheck(veristandInterOp.RTSequenceUndeploy())


print "CloseWorkspace"
errorCheck(veristandInterOp.CloseWorkspace())

print "UndeployProject"
errorCheck(veristandInterOp.UndeployProject())

print "CloseProject"
errorCheck(veristandInterOp.CloseProject())

print "CloseVeriStand"
errorCheck(veristandInterOp.CloseVeriStand())
print "Exit"


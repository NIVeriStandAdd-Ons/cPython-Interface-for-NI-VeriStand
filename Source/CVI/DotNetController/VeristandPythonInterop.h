// CVI wrapper header file for .NET assembly: VeristandPythonInterop, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
//
// This is specified by the '__assemblyName' constant in the generated source file.
// If there are multiple versions of this assembly, and you want .NET to determine 
// the appropriate one to load, then you can remove the version, culture, and public 
// key token information from the constant and just specify the name of the assembly.
//
// Other assemblies referenced by the target assembly:
// Name: NationalInstruments.VeriStand.ClientAPI, Location: C:\WINDOWS\Microsoft.Net\assembly\GAC_MSIL\NationalInstruments.VeriStand.ClientAPI\v4.0_2014.0.0.0__a6d690c380daa308\NationalInstruments.VeriStand.ClientAPI.dll
//
// If any assembly, including the target assembly, is not installed in the
// Global Assembly Cache (GAC) or in the application directory, and the wrapper
// code needs to load the assembly to convert types like arrays and enums, then
// you must register the path of the assembly with the CVI .NET library by
// calling CDotNetRegisterAssemblyPath before calling the wrapper code.
//
// Types exposed by the target assembly but defined in other assemblies:
// CVI name: NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger, .NET name: NationalInstruments.VeriStand.ClientAPI.LogInfo+trigger, Assembly: NationalInstruments.VeriStand.ClientAPI, Module: Global Assembly Cache
// CVI name: NationalInstruments_VeriStand_ClientAPI_LogChannel, .NET name: NationalInstruments.VeriStand.ClientAPI.LogChannel, Assembly: NationalInstruments.VeriStand.ClientAPI, Module: Global Assembly Cache

#include <cvidotnet.h>

#ifdef __cplusplus
extern "C" {
#endif

// Type definitions
typedef struct __VeristandPythonInterop_VeriStandInterop * VeristandPythonInterop_VeriStandInterop;
typedef struct __VeristandPythonInterop_VSLogChannel * VeristandPythonInterop_VSLogChannel;
typedef struct __NationalInstruments_VeriStand_ClientAPI_LogChannel * NationalInstruments_VeriStand_ClientAPI_LogChannel;
typedef struct __VeristandPythonInterop_VeriStandTDMSHandler * VeristandPythonInterop_VeriStandTDMSHandler;

// C wrapper for enumeration type NationalInstruments.VeriStand.ClientAPI.LogInfo+trigger
#ifndef NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger_DEFINED
#define NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger_DEFINED
typedef enum NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger
{
	NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger_none = 0x0,
	NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger_in_limits = 0x1,
	NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger_out_of_limits = 0x2,
} NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger;
#endif // NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger_DEFINED




// Global Functions
int CVIFUNC Initialize_VeristandPythonInterop(void);
int CVIFUNC Close_VeristandPythonInterop(void);

// Type: VeristandPythonInterop.VeriStandInterop
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetVeristandInterop(
	VeristandPythonInterop_VeriStandInterop * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetNewVeristandInterop(
	VeristandPythonInterop_VeriStandInterop * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_DeployProject(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_DeployProjectWithProgress(
	VeristandPythonInterop_VeriStandInterop __instance,
	int showProgress,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_UndeployProject(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_OpenWorkspace(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_CloseWorkspace(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_Connect(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_Disconnect(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetChannelValue(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * channelIdentidier,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetTargetRate(
	VeristandPythonInterop_VeriStandInterop __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetTargetIP(
	VeristandPythonInterop_VeriStandInterop __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetMultipleChannelValues(
	VeristandPythonInterop_VeriStandInterop __instance,
	char ** names,
	ssize_t __namesLength,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetActiveProjects(
	VeristandPythonInterop_VeriStandInterop __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetAllDeployedSessions(
	VeristandPythonInterop_VeriStandInterop __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_SetMultipleChannelValues(
	VeristandPythonInterop_VeriStandInterop __instance,
	char ** names,
	ssize_t __namesLength,
	double * values,
	ssize_t __valuesLength,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_SetMultipleChannelValuesSynch(
	VeristandPythonInterop_VeriStandInterop __instance,
	char ** names,
	ssize_t __namesLength,
	double * values,
	ssize_t __valuesLength,
	double * writeTime,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_SetChannelValue(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * channelIdentifier,
	double value,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_SetChannelValueSynch(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * channelIdentifier,
	double value,
	double * writeTime,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_LaunchVeriStand(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_LaunchVeriStand_1(
	VeristandPythonInterop_VeriStandInterop __instance,
	int runAs,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_RunProject(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_CloseVeristand(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_OpenProject(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * projectPath,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_CloseProject(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_ShowProjectWindow(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_StartDataLogging(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * logConfigName,
	char * lDescription,
	char * lFilePath,
	double lTriggerHighLimit,
	double lTriggerLowLimit,
	int lReplaceFile,
	NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger lTriggerType,
	char * lTriggerChannel,
	double lRate,
	char ** lFilePropertiesNames,
	ssize_t __lFilePropertiesNamesLength,
	char ** lFilePropertiesValues,
	ssize_t __lFilePropertiesValuesLength,
	char ** lChannelsToLog,
	ssize_t __lChannelsToLogLength,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_StartDataLogging2(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * logConfigName,
	char * lDescription,
	char * lFilePath,
	double fTriggerLevel,
	int iTriggerSlope,
	char * lTriggerChannel,
	double lRate,
	char ** lFilePropertiesNames,
	ssize_t __lFilePropertiesNamesLength,
	char ** lFilePropertiesValues,
	ssize_t __lFilePropertiesValuesLength,
	char ** lChannelsToLog,
	ssize_t __lChannelsToLogLength,
	double lDuration,
	double lPreTriggerDuration,
	int lReplaceFile,
	char ** lChannelShortNames,
	ssize_t __lChannelShortNamesLength,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetDataLogging2SessionState(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * logConfigName,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetDataLogging2State(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * LogConfigName,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_StopDataLogging(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * LogConfigName,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_StopDataLogging2(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * LogConfigName,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetAvailableChannelToRead(
	VeristandPythonInterop_VeriStandInterop __instance,
	int channelIndex,
	int * availableChannelCount,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetAvailableChannelToWrite(
	VeristandPythonInterop_VeriStandInterop __instance,
	int channelIndex,
	int * availableChannelCount,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetAvailableChannelsToReadCount(
	VeristandPythonInterop_VeriStandInterop __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetAvailableChannelsToWriteCount(
	VeristandPythonInterop_VeriStandInterop __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_StimulusExecuteAsynch(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * stimulusFile,
	char * uutSerialNumber,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_StimulusState(
	VeristandPythonInterop_VeriStandInterop __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_RTSequenceExecuteAsynch(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * RTSequenceFile,
	char ** ParamNames,
	ssize_t __ParamNamesLength,
	char ** ParamValues,
	ssize_t __ParamValuesLength,
	char ** ParamTypes,
	ssize_t __ParamTypesLength,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_RTSequenceState(
	VeristandPythonInterop_VeriStandInterop __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_RTSequenceGetReturnValue(
	VeristandPythonInterop_VeriStandInterop __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandInterop_RTSequenceUndeploy(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception);

// Type: VeristandPythonInterop.VSLogChannel
int CVIFUNC VeristandPythonInterop_VSLogChannel__Create(
	VeristandPythonInterop_VSLogChannel * __instance,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VSLogChannel_FillParams(
	VeristandPythonInterop_VSLogChannel __instance,
	char * channelPath,
	char * customName,
	char * customGroup,
	char ** lProperties,
	ssize_t __lPropertiesLength1,
	ssize_t __lPropertiesLength2,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VSLogChannel__Get__lLogChannel(
	VeristandPythonInterop_VSLogChannel __instance,
	NationalInstruments_VeriStand_ClientAPI_LogChannel * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VSLogChannel__Set__lLogChannel(
	VeristandPythonInterop_VSLogChannel __instance,
	NationalInstruments_VeriStand_ClientAPI_LogChannel lLogChannel,
	CDotNetHandle * __exception);

// Type: VeristandPythonInterop.VeriStandTDMSHandler
int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler__Create(
	VeristandPythonInterop_VeriStandTDMSHandler * __instance,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_TDMSOpen(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	char * filePath,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_TDMSClose(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_GetTDMSLoggingRate(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_GetTDMSLogChannelCount(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_GetTDMSLogLength(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_GetTDMSLogChannelProperty(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	int channelIndex,
	char * propertyName,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_TDMSReadLine(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	int reqLine,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_TDMSReadColumn(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	int reqColumn,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_TDMSTimeColumn(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);


#ifdef __cplusplus
}
#endif

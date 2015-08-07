//==============================================================================
//
// Title:       VeriStandCviDll
// Purpose:     A short description of the interface.
//
// Created on:  by Jiøí Keprt.
// Copyright:   National Instruments (Czech Republic), s. r.o.. All Rights Reserved.
//
//==============================================================================

#define  POPUPDEBUGDLL                       1	 	  /* 1 show popup, 0 no popup */           

#ifndef _CVI_VeriStand_PROTO_H
#define _CVI_VeriStand_PROTO_H

#include "VeristandPythonInterop.h"

/******************************************************************************/
/* Function Prototypes                                                        */
/******************************************************************************/

int LaunchVeriStand(void);
int OpenProject(char *pszFileName);
int CloseVeriStand(void);
int RunProject(void);
int CloseProject(void);
int ShowProjectWindow(void);
int Connect(void);
int Disconnect(void);
int GetChannelValue(char *pszChannelName, double *pdValue);
int SetChannelValue(char *pszChannelName, double dValue);
int SetChannelValueSynch(char *pszChannelName, double dValue, double *pWriteTime);
int OpenWorkspace(void);
int CloseWorkspace(void);
int DeployProject(void);
int DeployProjectWithProgress(void);
int UndeployProject(void);
int StopDataLogging(char *logConfigName);
int StopDataLogging2(char *logConfigName);
int SetMultipleChannelValues(char **channelNames, double dValues[], int iLength, int iCharLineLength);
int SetMultipleChannelValuesSynch(char **channelNames, double dValues[], int iLength, int iCharLineLength, double *pWriteTime);
int GetMultipleChannelValues(char **channelNames, double dValues[], int iLength, int iCharLineLength);
int GetActiveProject(char *ActiveProject,int RequestedProjectIndex, int *numberOfProjects);
int GetAllDeployedSessions(char *DeployedSession,int RequestedSessionIndex, int *numberOfSessions);
int StartDataLogging(char *logConfigName, char *logDescription,char *logFilePath,double lTriggerHighLimit, double lTriggerLowLimit,int lReplaceFile, NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger
             lTriggerType, char *lTriggerChannel, double lRate,char ** lFilePropertiesNames,int lFilePropertiesNamesLength, int lFilePropertiesNamesLineLength, char ** lFilePropertiesValues,int lFilePropertiesValuesLength,
			 int lFilePropertiesValuesLineLength, char ** lChannelsToLog,int lChannelsToLogLength, int lChannelsToLogLineLength);
int StartDataLogging2(char *logConfigName, char *logDescription,char *logFilePath,double fTriggerLevel,int lReplaceFile, 
	int iTriggerSlope, char *lTriggerChannel, double lRate,char ** lFilePropertiesNames,
	int lFilePropertiesNamesLength, int lFilePropertiesNamesLineLength, char ** lFilePropertiesValues,int lFilePropertiesValuesLength,
	int lFilePropertiesValuesLineLength, char ** lChannelsToLog,int lChannelsToLogLength, int lChannelsToLogLineLength, double fDuration, 
	double fPreTriggerDuration,char ** lChannelShortNames,int lChannelShortNamesLength, int lChannelShortNamesLineLength);
char* GetLastErrorMessage (void);
int IsOpenProjectRunning(int *running);
int GetAvailableChannelsToReadCount(int *numberOfChannels);
int GetTargetRate(double *TargetRate);
int GetAvailableChannelsToWriteCount(int *numberOfChannels);
int GetAvailableChannelToRead(char *channel,int requestedChannelIndex);
int GetAvailableChannelToWrite(char *channel,int requestedChannelIndex);
int GetDataLogging2SessionState(char *sLogConfigName,char *sSessionState);
int GetDataLogging2State(char *sLogConfigName,int *sessionState);
int StimulusExecuteAsynch(char *filePath, char *UUTSerialNumber);
int GetStimulusState(int *stimulusState);						 
int RTSequenceExecuteAsynch(char *filePath, char ** lParamNames,int lParamNamesLength, int lParamNamesLineLength,
							char ** lParamValues,int lParamValuesLength, int lParamValuesLineLength,
							char ** lParamTypes,int lParamTypesLength, int lParamTypesLineLength);
int GetRTSequenceState(int *RTSequenceState);
int RTSequenceUndeploy(void);
							 
int GetTDMSLoggingRate(double *loggingRate);
int GetTDMSLogChannelCount(int *logChannelCount);
int GetTDMSLogLength(__int64 *logLength);
int GetTDMSLogChannelProperty(int channelIndex, char *propertyName, char *propertyValue);
int TDMSOpen(char *filePath);
int TDMSClose(void);
int TDMSReadColumn(double logColumnData[],int iColumnLength,int channelIndex);
int TDMSReadTimeColumn(double logColumnData[],int iColumnLength);
//int TDMSReadLine(double[] logLine,int reqLine);	   

/*int Get2DChar(char **channelNames, int iLength, int iCharLength);
int GetDoubleArray(double dValues[]); 
int GetInt(int iLength);*/

#endif /* _CVI_VeriStand_PROTO_H */ 
														

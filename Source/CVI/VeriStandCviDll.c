//==============================================================================
//
// Title:       	VeriStandCviDll
// Purpose:     	Platform interface library for cPython
//
// Created on:  	by Jiøí Keprt (CZKeprtJ)
// Copyright:   	National Instruments (Czech Republic), s. r.o.. All Rights Reserved.
//
// Last Modified :	22Aug2012 CZKeprtJ 
//
//==============================================================================

//==============================================================================
// Include files


#include <cviauto.h>
#include <cvirte.h>
#include <utility.h>
#include <ansi_c.h>
#include <cvidotnet.h>
#include <userint.h>

#include "VeriStandCviDll.h"
#include "VeristandPythonInterop.h"
#include "VeriStandHelper.h"
#include <formatio.h>
//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

#define MAXERRORMSGLENGTH 500   
#define STATUS_OK 0

//Has to be static?
VeristandPythonInterop_VeriStandInterop					  		instance_handle;
VeristandPythonInterop_VeriStandTDMSHandler				  		instance_handle_TDMS;
static HINSTANCE 												hinstDLL_;

int maxErrorLength = 500;


//char szLastErrorMessage [MAXERRORMSGLENGTH] = "No Error.";
char szLastErrorMessage [500] = "No Error."; //Has to match maxErrorLength


//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

char* GetLastErrorMessage ()
{
	return szLastErrorMessage;
}

//==============================================================================
// VS Library Functions
	
int CloseVeriStand(void)
{
	CDotNetHandle exception_Handle;
	int iStatus = 0;

	iStatus = VeristandPythonInterop_VeriStandInterop_CloseVeristand(
		instance_handle,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 
}
	

int RunProject(void)
{
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_RunProject(
		instance_handle,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}

	return STATUS_OK;                 

}

int CloseProject(void)
{
	CDotNetHandle exception_Handle;
	int iStatus = 0;

	
	
	iStatus = VeristandPythonInterop_VeriStandInterop_CloseProject(
		instance_handle,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 

}

int ShowProjectWindow(void)
{
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_ShowProjectWindow(
		instance_handle,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 

}

int OpenWorkspace(void)
{
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_OpenWorkspace(
		instance_handle,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 

}

int Connect(void)
{
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_Connect(
		instance_handle,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 

}

int Disconnect(void)
{
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_Disconnect(
		instance_handle,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 

}

int CloseWorkspace(void)
{
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_CloseWorkspace(
		instance_handle,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 

}

int DeployProject(void)
{
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_DeployProject(
		instance_handle,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 

}

int DeployProjectWithProgress(void)
{
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_DeployProjectWithProgress(
		instance_handle, 1,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 

}


int UndeployProject(void)
{
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_UndeployProject(
		instance_handle,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 

}

int GetChannelValue(char *pszChannelName, double *pdValue)
{
	CDotNetHandle exception_Handle;
	int iStatus = 0;

	iStatus = VeristandPythonInterop_VeriStandInterop_GetChannelValue(
		instance_handle,
		pszChannelName,
		pdValue,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 
}

int GetMultipleChannelValues(char **channelNames, double dValues[], int iLength, int iCharLineLength)
{
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	int	arrayRefLength, i;
	char ** arrayRef;
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	int returniLength = 0;
	int *pReturniLength = &returniLength; 
	double *returndValues;
	char **pchannelNames;
	
	//Allocating pointers to array based on the size to able to use it from Python
	pchannelNames = (char **)malloc(sizeof(char *) * (iLength));
	if (pchannelNames == NULL) return -1;
	for (i = 0; i < iLength; ++i)
	{
		//testPointer = *channelNames+(i*iCharLineLength);
		pchannelNames[i] = *channelNames+(i*iCharLineLength);
	}
	
	arrayRefLength = iLength;
	arrayRef = CDotNetAllocateMemory(sizeof(char *) * iLength);
	if (arrayRef == NULL) return -1;
	
	/*Allocate storage for returned channel values */
	//returndValues = CDotNetAllocateMemory(sizeof(double) * iLength);
	
	for (i = 0; i < arrayRefLength; ++i)
	{
		arrayRef[i] = CDotNetAllocateMemory(sizeof(char) * iCharLineLength);
		if (arrayRef[i] == NULL) return -1;
		//strcpy(arrayRef[i], pchannelNames[i]);
		strncpy(arrayRef[i], pchannelNames[i], strlen(pchannelNames[i]));
		arrayRef[i][strlen(pchannelNames[i])] = '\0';
	}
	
	
	
	iStatus = VeristandPythonInterop_VeriStandInterop_GetMultipleChannelValues(
		instance_handle,
		arrayRef,
		iLength,
		&returndValues, //Is this correct?
		pReturniLength,
		&exception_Handle);
		
	for (i = 0; i < arrayRefLength; ++i) 
	{
		CDotNetFreeMemory(arrayRef[i]);
		dValues[i] = returndValues[i];
	} 

	CDotNetFreeMemory(arrayRef);
	CDotNetFreeMemory(returndValues);
	free(pchannelNames);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 
}

int GetActiveProject(char *ActiveProject,int RequestedProjectIndex, int *numberOfProjects)
{
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	int i;
	int stringLength = 0;
	char ** arrayRef;
	CDotNetHandle exception_Handle;
	char **activeProjectsNames;
	
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_GetActiveProjects(
		instance_handle,
		&arrayRef,
		numberOfProjects,
		&exception_Handle);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
		CDotNetFreeMemory(arrayRef);
		for (i = 0; i < *numberOfProjects; ++i) 
		{   
			CDotNetFreeMemory(arrayRef[i]);		 
		}
		return iStatus;             
	}											 
	
	if (RequestedProjectIndex < *numberOfProjects)
	{   
		
		strncpy(ActiveProject, arrayRef[RequestedProjectIndex], strlen(arrayRef[RequestedProjectIndex]));
		ActiveProject[strlen(arrayRef[RequestedProjectIndex])] = '\0';
		
	}
	else 
	{
	
		iStatus = -100;
	}
	
	for (i = 0; i < *numberOfProjects; ++i) 
	{   
		CDotNetFreeMemory(arrayRef[i]);		 
	} 
	
	
	CDotNetFreeMemory(arrayRef);
	
	
	return iStatus;                 
}

int GetDataLogging2SessionState(char *sLogConfigName,char *sSessionState)
{
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	int i;
	int stringLength = 0;
	char * arrayRef;
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_GetDataLogging2SessionState(
		instance_handle,
		sLogConfigName,
		&arrayRef,
		&exception_Handle);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
		CDotNetFreeMemory(arrayRef); 
		return iStatus;             
	}	
	
	strncpy(sSessionState, arrayRef, strlen(arrayRef));
	sSessionState[strlen(arrayRef)] = '\0';
	
	CDotNetFreeMemory(arrayRef); 
	return iStatus;                 
}

int GetDataLogging2State(char *sLogConfigName,int *sessionState)
{
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_GetDataLogging2State(
		instance_handle,
		sLogConfigName,
		sessionState,
		&exception_Handle);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
		return iStatus;             
	}	
	
	return iStatus;                 
}


int GetAllDeployedSessions(char *DeployedSession,int RequestedSessionIndex, int *numberOfSessions)
{
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	int i;
	int stringLength = 0;
	char ** arrayRef;
	CDotNetHandle exception_Handle;
	char **activeSessionsNames;
	
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_GetAllDeployedSessions(
		instance_handle,
		&arrayRef,
		numberOfSessions,
		&exception_Handle);
	
	//Allocate memory for return
	
	
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
		for (i = 0; i < *numberOfSessions; ++i) 
		{   
			CDotNetFreeMemory(arrayRef[i]);		 
		} 
		CDotNetFreeMemory(arrayRef);
	
		return iStatus;                 
	}											 
	
	if ((RequestedSessionIndex < *numberOfSessions))
	{   
		//strcpy(DeployedSession, arrayRef[RequestedSessionIndex]);
		strncpy(DeployedSession, arrayRef[RequestedSessionIndex], strlen(arrayRef[RequestedSessionIndex]));
		DeployedSession[strlen(arrayRef[RequestedSessionIndex])] = '\0';
	}
	else 
	{
		if (iStatus == STATUS_OK)
		{
			if (!((*numberOfSessions==0)&&(iStatus==0)&&(RequestedSessionIndex==0))) iStatus = -100;
		}
	}
	
	for (i = 0; i < *numberOfSessions; ++i) 
	{   
		CDotNetFreeMemory(arrayRef[i]);		 
	} 
	
	
	CDotNetFreeMemory(arrayRef);
	
	return iStatus;                 
}

int GetAvailableChannelsToReadCount(int *numberOfChannels)
{
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	CDotNetHandle exception_Handle;
	
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_GetAvailableChannelsToReadCount(
		instance_handle,
		numberOfChannels,
		&exception_Handle);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
	}											 
	
	return iStatus;                 
}

int GetAvailableChannelsToWriteCount(int *numberOfChannels)
{
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	CDotNetHandle exception_Handle;
	
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_GetAvailableChannelsToWriteCount(
		instance_handle,
		numberOfChannels,
		&exception_Handle);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
	}											 
	
	return iStatus;                 
}

int GetTargetRate(double *TargetRate)
{
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	CDotNetHandle exception_Handle;
	
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_GetTargetRate(
		instance_handle,
		TargetRate,
		&exception_Handle);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
	}											 
	
	return iStatus;                 
}


int GetAvailableChannelToRead(char *channel,int requestedChannelIndex)
{
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	int i;
	int numberOfChannels;
	int stringLength = 0;
	char *retChannel;
	retChannel = (char *) CDotNetAllocateMemory(255);
	CDotNetHandle exception_Handle;
	
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_GetAvailableChannelToRead(
		instance_handle,
		requestedChannelIndex,
		&numberOfChannels,
		&retChannel,
		&exception_Handle);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
		CDotNetFreeMemory(retChannel);
		return iStatus;                 
	}											 
	
	strncpy(channel, retChannel, strlen(retChannel));
	channel[strlen(retChannel)] = '\0';
	
	CDotNetFreeMemory(retChannel);
	return iStatus;                 
}

int GetAvailableChannelToWrite(char *channel,int requestedChannelIndex)
{
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	int i;
	int numberOfChannels;
	int stringLength = 0;
	char *retChannel;
	retChannel = (char *) CDotNetAllocateMemory(255);
	CDotNetHandle exception_Handle;
	
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandInterop_GetAvailableChannelToWrite(
		instance_handle,
		requestedChannelIndex,
		&numberOfChannels,
		&retChannel,
		&exception_Handle);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
		CDotNetFreeMemory(retChannel);
		return iStatus;                 
	}											 
	
	strncpy(channel, retChannel, strlen(retChannel));
	channel[strlen(retChannel)] = '\0';
	
	CDotNetFreeMemory(retChannel);
	return iStatus;                 
}


int IsOpenProjectRunning(int *running)
{
	char 	*activeSession = 0;
	int activeSessionsNum = 0;
	activeSession = (char *) malloc(255);
	*running = 0;
	int status = 0;

	if (activeSession == NULL) return -1;
	
	status = GetAllDeployedSessions(activeSession,0,&activeSessionsNum);	
	if (status==0) *running = 1;
		
	
	return STATUS_OK;                 
}



int SetChannelValue(char *pszChannelName, double dValue)
{
	CDotNetHandle exception_Handle;
	int iStatus = 0;

	iStatus = VeristandPythonInterop_VeriStandInterop_SetChannelValue(
		instance_handle,
		pszChannelName,
		dValue,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 
}

int SetChannelValueSynch(char *pszChannelName, double dValue, double *pWriteTime)
{
	CDotNetHandle exception_Handle;
	int iStatus = 0;

	iStatus = VeristandPythonInterop_VeriStandInterop_SetChannelValueSynch(
		instance_handle,
		pszChannelName,
		dValue,
		pWriteTime,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 
}			

int SetMultipleChannelValues(char **channelNames, double dValues[], int iLength, int iCharLineLength)
{
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	int	arrayRefLength=0, i=0;
	char ** arrayRef;
	//char *testPointer;
	char **pchannelNames;
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	
	//Allocating pointers to array based on the size to able to use it from Python
	pchannelNames = (char **)malloc(sizeof(char *) * (iLength));
	if (pchannelNames == NULL) return -1;
	
	for (i = 0; i < iLength; ++i)
	{
		//testPointer = *channelNames+(i*iCharLineLength);
		pchannelNames[i] = *channelNames+(i*iCharLineLength);
	}
	
	arrayRefLength = iLength;
	arrayRef = CDotNetAllocateMemory(sizeof(char *) * iLength);
	if (arrayRef == NULL) return -1;
	
	for (i = 0; i < arrayRefLength; ++i)
	{
		arrayRef[i] = CDotNetAllocateMemory(sizeof(char) * iCharLineLength);
		if (arrayRef[i] == NULL) return -1;
		//strcpy(arrayRef[i], pchannelNames[i]);
		strncpy(arrayRef[i], pchannelNames[i], strlen(pchannelNames[i]));
		arrayRef[i][strlen(pchannelNames[i])] = '\0';
	}
	
	iStatus = VeristandPythonInterop_VeriStandInterop_SetMultipleChannelValues(
		instance_handle,
		arrayRef,
		iLength,
		dValues,
		iLength,
		&exception_Handle);
		
	for (i = 0; i < arrayRefLength; ++i)
		CDotNetFreeMemory(arrayRef[i]);

	CDotNetFreeMemory(arrayRef);
	free(pchannelNames);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;
}

int SetMultipleChannelValuesSynch(char **channelNames, double dValues[], int iLength, int iCharLineLength, double *pWriteTime)
{
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	int	arrayRefLength=0, i=0;
	char ** arrayRef;
	//char *testPointer;
	char **pchannelNames;
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	
	//Allocating pointers to array based on the size to able to use it from Python
	pchannelNames = (char **)malloc(sizeof(char *) * (iLength));
	if (pchannelNames == NULL) return -1;
	
	for (i = 0; i < iLength; ++i)
	{
		//testPointer = *channelNames+(i*iCharLineLength);
		pchannelNames[i] = *channelNames+(i*iCharLineLength);
	}
	
	arrayRefLength = iLength;
	arrayRef = CDotNetAllocateMemory(sizeof(char *) * iLength);
	if (arrayRef == NULL) return -1;
	for (i = 0; i < arrayRefLength; ++i)
	{
		arrayRef[i] = CDotNetAllocateMemory(sizeof(char) * iCharLineLength);
		if (arrayRef[i] == NULL) return -1;
		//strcpy(arrayRef[i], pchannelNames[i]);
		strncpy(arrayRef[i], pchannelNames[i], strlen(pchannelNames[i]));
		arrayRef[i][strlen(pchannelNames[i])] = '\0';
	}
	
	iStatus = VeristandPythonInterop_VeriStandInterop_SetMultipleChannelValuesSynch(
		instance_handle,
		arrayRef,
		iLength,
		dValues,
		iLength,
		pWriteTime,
		&exception_Handle);
		
	for (i = 0; i < arrayRefLength; ++i)
		CDotNetFreeMemory(arrayRef[i]);

	CDotNetFreeMemory(arrayRef);
	free(pchannelNames);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;
}


int OpenProject(char *pszFileName)
{
	CDotNetHandle exception_Handle;

	int iStatus = 0;

	iStatus = VeristandPythonInterop_VeriStandInterop_OpenProject(
		instance_handle,
		pszFileName,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 
}

int StartDataLogging(char *logConfigName, char *logDescription,char *logFilePath,double lTriggerHighLimit, double lTriggerLowLimit,int lReplaceFile, NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger
             lTriggerType, char *lTriggerChannel, double lRate,char ** lFilePropertiesNames,int lFilePropertiesNamesLength, int lFilePropertiesNamesLineLength, char ** lFilePropertiesValues,int lFilePropertiesValuesLength,
			 int lFilePropertiesValuesLineLength, char ** lChannelsToLog,int lChannelsToLogLength, int lChannelsToLogLineLength)
{   
	CDotNetHandle exception_Handle;
	int iStatus = 0, i=0;
	
	char ** lFilePropertiesNamesTemp = 0;
	char **	lFilePropertiesValuesTemp = 0;
	char **	lChannelsToLogTemp = 0;
	
	lFilePropertiesNamesTemp = (char **)malloc(sizeof(char *) * (lFilePropertiesNamesLength));
	if (lFilePropertiesNamesTemp == NULL) return -1;
	for (i = 0; i < lFilePropertiesNamesLength; ++i)
	{
		lFilePropertiesNamesTemp[i] = *lFilePropertiesNames+(i*lFilePropertiesNamesLineLength);
	};
	
	lFilePropertiesValuesTemp = (char **)malloc(sizeof(char *) * (lFilePropertiesValuesLength));
	if (lFilePropertiesValuesTemp == NULL) return -1;
	for (i = 0; i < lFilePropertiesValuesLength; ++i)
	{
		lFilePropertiesValuesTemp[i] = *lFilePropertiesValues+(i*lFilePropertiesValuesLineLength);
	};
	
	lChannelsToLogTemp = (char **)malloc(sizeof(char *) * (lChannelsToLogLength));
	if (lChannelsToLogTemp == NULL) return -1;	
	for (i = 0; i < lChannelsToLogLength; ++i)
	{
		lChannelsToLogTemp[i] = *lChannelsToLog+(i*lChannelsToLogLineLength);
	};
	
	
	iStatus = VeristandPythonInterop_VeriStandInterop_StartDataLogging(
		instance_handle,
		logConfigName,logDescription,logFilePath,lTriggerHighLimit, lTriggerLowLimit,lReplaceFile, lTriggerType,
		lTriggerChannel, lRate, 
		lFilePropertiesNamesTemp, lFilePropertiesNamesLength,lFilePropertiesValuesTemp,
		lFilePropertiesValuesLength,lChannelsToLogTemp,  lChannelsToLogLength,
		&exception_Handle);
	
	free(lFilePropertiesNamesTemp);
	free(lFilePropertiesValuesTemp);
	free(lChannelsToLogTemp);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 
}			

int StartDataLogging2(char *logConfigName, char *logDescription,char *logFilePath,double fTriggerLevel,int lReplaceFile, 
	int iTriggerSlope, char *lTriggerChannel, double lRate,char ** lFilePropertiesNames,
	int lFilePropertiesNamesLength, int lFilePropertiesNamesLineLength, char ** lFilePropertiesValues,int lFilePropertiesValuesLength,
	int lFilePropertiesValuesLineLength, char ** lChannelsToLog,int lChannelsToLogLength, int lChannelsToLogLineLength, double fDuration, 
	double fPreTriggerDuration,char ** lChannelShortNames,int lChannelShortNamesLength, int lChannelShortNamesLineLength)
{   
	CDotNetHandle exception_Handle;
	int iStatus = 0, i=0;
	
	char ** lFilePropertiesNamesTemp = 0;
	char **	lFilePropertiesValuesTemp = 0;
	char **	lChannelsToLogTemp = 0;
	char **	lChannelShortNamesTemp = 0;
	
	lFilePropertiesNamesTemp = (char **)malloc(sizeof(char *) * (lFilePropertiesNamesLength));
	if (lFilePropertiesNamesTemp == NULL) return -1;
	for (i = 0; i < lFilePropertiesNamesLength; ++i)
	{
		lFilePropertiesNamesTemp[i] = *lFilePropertiesNames+(i*lFilePropertiesNamesLineLength);
	};
	
	lFilePropertiesValuesTemp = (char **)malloc(sizeof(char *) * (lFilePropertiesValuesLength));
	if (lFilePropertiesValuesTemp == NULL) return -1;
	for (i = 0; i < lFilePropertiesValuesLength; ++i)
	{
		lFilePropertiesValuesTemp[i] = *lFilePropertiesValues+(i*lFilePropertiesValuesLineLength);
	};
	
	lChannelShortNamesTemp = (char **)malloc(sizeof(char *) * (lChannelShortNamesLength));
	if (lChannelShortNamesTemp == NULL) return -1;
	for (i = 0; i < lChannelShortNamesLength; ++i)
	{
		lChannelShortNamesTemp[i] = *lChannelShortNames+(i*lChannelShortNamesLineLength);
	};
	
	lChannelsToLogTemp = (char **)malloc(sizeof(char *) * (lChannelsToLogLength));
	if (lChannelsToLogTemp == NULL) return -1;	
	for (i = 0; i < lChannelsToLogLength; ++i)
	{
		lChannelsToLogTemp[i] = *lChannelsToLog+(i*lChannelsToLogLineLength);
	};
	
	
	iStatus = VeristandPythonInterop_VeriStandInterop_StartDataLogging2(
		instance_handle,logConfigName,logDescription,logFilePath,
		fTriggerLevel,iTriggerSlope,lTriggerChannel,lRate,
		lFilePropertiesNamesTemp, lFilePropertiesNamesLength,lFilePropertiesValuesTemp,lFilePropertiesValuesLength,
		lChannelsToLogTemp, lChannelsToLogLength,fDuration,fPreTriggerDuration,lReplaceFile, lChannelShortNamesTemp,lChannelShortNamesLength, 
		&exception_Handle);
	
	free(lFilePropertiesNamesTemp);
	free(lFilePropertiesValuesTemp);
	free(lChannelsToLogTemp);
	free(lChannelShortNamesTemp);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 
}			


int StopDataLogging(char *logConfigName)
{
	CDotNetHandle exception_Handle;

	int iStatus = 0;

	iStatus = VeristandPythonInterop_VeriStandInterop_StopDataLogging(
		instance_handle,
		logConfigName,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 
}

int StopDataLogging2(char *logConfigName)
{
	CDotNetHandle exception_Handle;

	int iStatus = 0;

	iStatus = VeristandPythonInterop_VeriStandInterop_StopDataLogging2(
		instance_handle,
		logConfigName,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 
}


int TDMSOpen(char *filePath)
{
	CDotNetHandle exception_Handle;

	int iStatus = 0;
		
	iStatus = VeristandPythonInterop_VeriStandTDMSHandler__Create(&instance_handle_TDMS,&exception_Handle);

	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
		return iStatus; 
	}
	
	iStatus = VeristandPythonInterop_VeriStandTDMSHandler_TDMSOpen(
		instance_handle_TDMS,
		filePath,
		&exception_Handle);
		
	if (iStatus != STATUS_OK)  
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 
}

int TDMSClose(void)
{
	CDotNetHandle exception_Handle;

	int iStatus = 0;
	
	iStatus =  VeristandPythonInterop_VeriStandTDMSHandler_TDMSClose(
		instance_handle_TDMS,
		&exception_Handle);
		
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 
}

int GetTDMSLoggingRate(double *loggingRate)
{
	CDotNetHandle exception_Handle;
	
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandTDMSHandler_GetTDMSLoggingRate(
		instance_handle_TDMS,
		loggingRate,
		&exception_Handle);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
	}											 
	
	return iStatus;                 
}

int GetTDMSLogChannelCount(int *logChannelCount)
{
	CDotNetHandle exception_Handle;
	
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandTDMSHandler_GetTDMSLogChannelCount(
		instance_handle_TDMS,
		logChannelCount,
		&exception_Handle);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
	}											 
	
	return iStatus;                 
}

int GetTDMSLogLength(__int64 *logLength)
{
	CDotNetHandle exception_Handle;
	
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandTDMSHandler_GetTDMSLogLength(
		instance_handle_TDMS,
		logLength,
		&exception_Handle);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
	}											 
	
	return iStatus;                 
}

int GetTDMSLogChannelProperty(int channelIndex, char *propertyName, char *propertyValue)
{
	  
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	int i;
	int stringLength = 0;
	char * arrayRef;
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	
	iStatus = VeristandPythonInterop_VeriStandTDMSHandler_GetTDMSLogChannelProperty(
		instance_handle_TDMS,
		channelIndex,
		propertyName,
		&arrayRef,
		&exception_Handle);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
		CDotNetFreeMemory(arrayRef); 
		return iStatus;             
	}	
	
	strncpy(propertyValue, arrayRef, strlen(arrayRef));
	propertyValue[strlen(arrayRef)] = '\0';
	
	CDotNetFreeMemory(arrayRef); 
	return iStatus;                 
	
	
}

int TDMSReadColumn(double logColumnData[],int iColumnLength,int channelIndex)
{
	//int GetMultipleChannelValues(char **channelNames, double dValues[], int iLength, int iCharLineLength);
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	int	arrayRefLength, i;
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	int returniLength = 0;
	int *pReturniLength = &returniLength; 
	double *returndValues;
	
	arrayRefLength = iColumnLength;
	
	/*Allocate storage for returned channel values */
	//returndValues = CDotNetAllocateMemory(sizeof(double) * iLength);
	
	iStatus = VeristandPythonInterop_VeriStandTDMSHandler_TDMSReadColumn(
		instance_handle_TDMS,
		channelIndex,
		&returndValues, //Is this correct?
		pReturniLength,
		&exception_Handle);
	
	/*iStatus = VeristandPythonInterop_VeriStandInterop_GetMultipleChannelValues(
		instance_handle,
		arrayRef,
		iLength,
		&returndValues, //Is this correct?
		pReturniLength,
		&exception_Handle);*/
		
	for (i = 0; i < arrayRefLength; ++i) 
	{   
		logColumnData[i] = returndValues[i];
	} 
	
	CDotNetFreeMemory(returndValues);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 
}

int TDMSReadTimeColumn(double logColumnData[],int iColumnLength)
{
	//int GetMultipleChannelValues(char **channelNames, double dValues[], int iLength, int iCharLineLength);
	// NOTE - Reference arguments must be allocated using CDotNetAllocateMemory
	int	arrayRefLength, i;
	CDotNetHandle exception_Handle;
	int iStatus = 0;
	int returniLength = 0;
	int *pReturniLength = &returniLength; 
	double *returndValues;
	
	arrayRefLength = iColumnLength;
	
	/*Allocate storage for returned channel values */
	//returndValues = CDotNetAllocateMemory(sizeof(double) * iLength);
	
	iStatus = VeristandPythonInterop_VeriStandTDMSHandler_TDMSTimeColumn(
		instance_handle_TDMS,
		&returndValues, //Is this correct?
		pReturniLength,
		&exception_Handle);
	
	/*iStatus = VeristandPythonInterop_VeriStandInterop_GetMultipleChannelValues(
		instance_handle,
		arrayRef,
		iLength,
		&returndValues, //Is this correct?
		pReturniLength,
		&exception_Handle);*/
		
	for (i = 0; i < arrayRefLength; ++i) 
	{   
		logColumnData[i] = returndValues[i];
	} 
	
	CDotNetFreeMemory(returndValues);
	
	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);

		return iStatus; 
	}
	
	return STATUS_OK;                 
}


/*****************************************************************************
  FUNCTION NAME          : LaunchVeriStand
  DESCRIPTION            : Launches NIVS. 
  PARAMETERS DESCRIPTION : 
  Return Value           : int:  0 = Success, Other = Failure
******************************************************************************/
int LaunchVeriStand(void)
{
  	CDotNetHandle exception_Handle;

	int iStatus = 0;

	char dllPath[MAX_FILENAME_LEN];
	char driveName[MAX_DRIVENAME_LEN];
	char dirName[MAX_DIRNAME_LEN];
	char assemblyPath[MAX_FILENAME_LEN];

	GetModuleFileName(hinstDLL_, dllPath, 300);
	SplitPath (dllPath, driveName, dirName, NULL);
	strcpy(assemblyPath,driveName);
	strcat(assemblyPath,dirName);
	strcat(assemblyPath,"\\VeristandPythonInterop.dll");	
	
	CDotNetRegisterAssemblyPath("VeristandPythonInterop, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null",assemblyPath);
	
	iStatus = Initialize_VeristandPythonInterop();
	
	if (iStatus != STATUS_OK) 
	{
		StoreErrorForGetLastError(__FUNCTION__, "Failed to Initialize .NET Veristand Interop API"); 
		return iStatus; 
	}

	iStatus =  VeristandPythonInterop_VeriStandInterop_GetVeristandInterop(&instance_handle,&exception_Handle);

	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
		return iStatus; 
	}
	
	iStatus = VeristandPythonInterop_VeriStandInterop_LaunchVeriStand(instance_handle, &exception_Handle);

	if (iStatus != STATUS_OK) 
	{ 
		StoreErrorForGetLastErrorFromDotNetHandle (__FUNCTION__, exception_Handle);
		return iStatus; 
	}
	
	return STATUS_OK;                 
}

//==============================================================================
// Debug Functions
/*
int Get2DChar(char **channelNames, int iLength, int iCharLength)
{
	int i = 0;
	char **pchannelNames;
	
	pchannelNames = (char **)malloc(sizeof(char *) * (iLength));
	if (pchannelNames == NULL) return -1;
	for (i = 0; i < iLength; ++i)
	{
		pchannelNames[i] = *channelNames+(i*iCharLength);
	}
	
	printf("%i", iLength);
	
	for (i = 0; i < iLength; ++i)
	{
		printf("\nDLL:%s\n", pchannelNames[i]);	
	}
	
	free(pchannelNames);

	return STATUS_OK;                 
}


int GetDoubleArray(double dValues[])
{
	
	printf("\n%f\n", dValues[0]);
	printf("\n%f\n", dValues[1]);

	return STATUS_OK;                 
}

int GetInt(int iLength)
{
	
	printf("%i", iLength);

	return STATUS_OK;                 
}*/

//==============================================================================
// DllMain

int __stdcall DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason) {
		case DLL_PROCESS_ATTACH:
			if (InitCVIRTE (hinstDLL, 0, 0) == 0)
				return 0;	  /* out of memory */
			
			hinstDLL_ = hinstDLL;			
			break;
		case DLL_PROCESS_DETACH:
			CloseCVIRTE ();
			break;
	}
	
	return 1;
}


// End of file.

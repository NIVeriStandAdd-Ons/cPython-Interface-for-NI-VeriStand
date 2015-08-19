//==============================================================================
//
// Title:		IntegrationTest.c
// Purpose:		Integrations Test for VS dll
//
// Created on:	11/9/2012 at 10:15:25 AM by Jiri Keprt.
// Copyright:	NI. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <cvidotnet.h>
#include <formatio.h>
#include <utility.h>
#include <ansi_c.h>
#include "IntegrationTest.h" 
#include "VeriStandCviDll.h"
#include "CUnit.h"
						   

//==============================================================================
// Constants
#define MAXERRORMSGLENGTH 500  
//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

char *prj = "d:\\NI Projects\\EXAM & cPython\\Python development\\cPython-Interface-for-NI-VeriStand\\VS\\Sinewave UnitTest.nivsproj";
//char *prj = "C:\\NI Projects\\EXAM\\EXAM Platform Interface\\VS\\EngineEXAM.nivsproj";
//char *prj = "D:\\NI Projects\\EXAM\\EXAM CVI dotnet\\VS\\sdfbhj.nivsproj"; 
char cdescription[MAXERRORMSGLENGTH];
char *pcdescription = cdescription;
int status = 0;
//char szLastErrorMessage [MAXERRORMSGLENGTH] = "No Error."; 
//char *pszLastErrorMessage = szLastErrorMessage;
char *pszLastErrorMessage;



//==============================================================================
// Global functions

void RunProjectShouldRunProject (void)
{			
			char 	*activeProject;
			int activeProjectsNum = 0;
			char 	*activeSession = 0;
			int activeSessionsNum = 0;
			
			activeProject = (char *) malloc(255);
			activeSession = (char *) malloc(255);
	
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;

			status = DeployProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetActiveProject(activeProject,0,&activeProjectsNum);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetAllDeployedSessions(activeSession,0,&activeSessionsNum);
			if(HandleError(status,__FUNCTION__)) return;
			
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			CU_ASSERT_STRING_EQUAL(prj, activeProject);
			CU_ASSERT_EQUAL(1, activeProjectsNum);
			free(activeProject);
			free(activeSession);
			
}

void CloseShouldCloseOpenedProject (void)
{
	  		status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;

			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			Delay(5);               
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			CU_ASSERT_EQUAL(0, status);
			
}

void CloseOpenWorkspaceShouldCloseOpenRunningProject (void)
{
	  		status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;

			status = DeployProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			Delay(5);      
			
			status = OpenWorkspace();
			if(HandleError(status,__FUNCTION__)) return;
			
			Delay(2);
			
			status = CloseWorkspace();
			if(HandleError(status,__FUNCTION__)) return;
			
			Delay(2);      
			
			status = UndeployProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			Delay(2);      
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			CU_ASSERT_EQUAL(0, status);
			
}

void SetGetChannelValueShouldSetAndGetChannelValue (void)
{
	  		char 	cChanlName[255],		*pcChanlName = cChanlName;
			double	dValue = 0.0; 
			double *pdValue = &dValue;
			strcpy (pcChanlName,"Aliases/UnitTest");
			
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n%f\n",*pdValue);
			
			status = SetChannelValue(pcChanlName,-5.0);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("%f\n",*pdValue);
			
			Delay(0.1);
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("%f\n",*pdValue);
			
			status = SetChannelValue(pcChanlName,0.0);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			
			CU_ASSERT_EQUAL(-5.0, *pdValue);
			
}

void SetGetParamValueShouldSetAndGetParamValue (void)
{
	  		char 	cChanlName[255],		*pcChanlName = cChanlName;
			double	dValue = 0.0; 
			double *pdValue = &dValue;
			strcpy (pcChanlName,"Targets/Controller/Simulation Models/Models/delay_sinewave/Parameters/z-block/Order");
			
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n%f\n",*pdValue);
			
			status = SetChannelValue(pcChanlName,-5.0);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("%f\n",*pdValue);
			
			Delay(0.1);
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("%f\n",*pdValue);
			
			status = SetChannelValue(pcChanlName,0.0);
			if(HandleError(status,__FUNCTION__)) return;
			
			strcpy (pcChanlName,"Targets/Controller/Simulation Models/Models/random/Parameters/Amplitude");
			
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n%f\n",*pdValue);
			
			status = SetChannelValue(pcChanlName,-5.0);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("%f\n",*pdValue);
			
			Delay(0.1);
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("%f\n",*pdValue);
			
			status = SetChannelValue(pcChanlName,0.0);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			
			CU_ASSERT_EQUAL(-5.0, *pdValue);
			
}

void SetGetParamValueSynchShouldSetAndGetParamValueSynch (void)
{
	  		char 	cChanlName[255],		*pcChanlName = cChanlName;
			double	dValue = 0.0; 
			double *pdValue = &dValue;
			double writeTime = 0;
			
			strcpy (pcChanlName,"Targets/Controller/Simulation Models/Models/delay_sinewave/Parameters/z-block/Order");
			
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n%f\n",*pdValue);
			
			status = SetChannelValueSynch(pcChanlName,-5.0,&writeTime);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("%f\n",*pdValue);
			
			status = SetChannelValueSynch(pcChanlName,0.0, &writeTime);
			if(HandleError(status,__FUNCTION__)) return;
			
			strcpy (pcChanlName,"Targets/Controller/Simulation Models/Models/random/Parameters/Amplitude");		
			
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n%f\n",*pdValue);
			
			status = SetChannelValueSynch(pcChanlName,-5.0,&writeTime);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("%f\n",*pdValue);
			
			status = SetChannelValueSynch(pcChanlName,0.0, &writeTime);
			if(HandleError(status,__FUNCTION__)) return;
			
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			
			CU_ASSERT_EQUAL(-5.0, *pdValue);
			
}

void SetGetChannelValueSynchShouldSetAndGetChannelValueSynch (void)
{
	  		char 	cChanlName[255],		*pcChanlName = cChanlName;
			double	dValue = 0.0; 
			double *pdValue = &dValue;
			double writeTime = 0;
			
			strcpy (pcChanlName,"Aliases/UnitTest");	  
			
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n%f\n",*pdValue);
			
			status = SetChannelValueSynch(pcChanlName,-5.0,&writeTime);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetChannelValue(pcChanlName,pdValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("%f\n",*pdValue);
			
			status = SetChannelValueSynch(pcChanlName,0.0, &writeTime);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			
			CU_ASSERT_EQUAL(-5.0, *pdValue);
			
}


void GetActiveProjectShouldReturnProjects(void)
{
			char 	*activeProject;
			int activeProjectsNum = 0;
			
			activeProject = (char *) malloc(255);
			
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetActiveProject(activeProject,0,&activeProjectsNum);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n%i open project: %s\n",activeProjectsNum, activeProject);
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			CU_ASSERT_STRING_EQUAL(prj, activeProject);
			CU_ASSERT_EQUAL(1, activeProjectsNum);
			
			free(activeProject);
			
}

void GetAvailableChannelsToReadCountShouldReturnCount(void)
{			
			int channelCount = 0;
			
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetAvailableChannelsToReadCount(&channelCount);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n%i channels\n",channelCount);
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			CU_ASSERT_EQUAL(348, channelCount);
			
}

void GetAvailableChannelsToWriteCountShouldReturnCount(void)
{			
			int channelCount = 0;
			
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetAvailableChannelsToWriteCount(&channelCount);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n %i channels to write\n",channelCount);
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			CU_ASSERT_EQUAL(202, channelCount);
			
}

void GetAvailableChannelToReadShouldReturnChannel(void)
{
			char *expectedChannel = "Aliases/Sinewave Input";
			char *activeChannel;
			activeChannel = (char *) malloc(255);

			
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetAvailableChannelToRead(activeChannel,5);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n active channel: %s\n",activeChannel);
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			CU_ASSERT_STRING_EQUAL(expectedChannel, activeChannel);
			
			free(activeChannel);
}

void GetAvailableChannelToWriteShouldReturnChannel(void)
{
			char *expectedChannel = "Targets/Controller/System Channels/Tripped Low Value";
			char *activeChannel;
			activeChannel = (char *) malloc(255);

			
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetAvailableChannelToWrite(activeChannel,5);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n active channel: %s\n",activeChannel);
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			CU_ASSERT_STRING_EQUAL(expectedChannel, activeChannel);
			
			free(activeChannel);
}			

void StartAndStopLoggingShouldStartAndStopLogging(void)
{			
			char *logPath = "C:\\Temp\\Test.tdms";
			double lRate = 100; 
			int i = 0;
            char *taskName = "testLog";
			char lRateString[10];

			int	lFilePropertiesNamesLineLength = 255,lFilePropertiesValuesLineLength = 255,lChannelsToLogLineLength = 255;
			
			int  lFilePropertiesNamesLength = 3, 	lFilePropertiesValuesLength = 3, 	lChannelsToLogLength = 4;
			char *lFilePropertiesNames[3], 			*lFilePropertiesValues[3], 			*lChannelsToLog[4]; 		//Must match Lengths!
			char *lFilePropertiesNamesBlock, 		*lFilePropertiesValuesBlock, 		*lChannelsToLogBlock; 
			
			//Need to allocate array in one block because of Python
			lFilePropertiesNamesBlock = malloc(lFilePropertiesNamesLength*lFilePropertiesNamesLineLength* sizeof(*lFilePropertiesNamesBlock));
			//lFilePropertiesNames[0] = &lFilePropertiesNamesBlock[0]; //How to length size of this to 255?
			for (i = 0; i < lFilePropertiesNamesLength; ++i)
			{
				lFilePropertiesNames[i] = &lFilePropertiesNamesBlock[i*lFilePropertiesNamesLineLength];
				lFilePropertiesNames[i][0] = '\0';
			}
			
			//Need to allocate array in one block because of Python
			lFilePropertiesValuesBlock = malloc(lFilePropertiesValuesLength*lFilePropertiesValuesLineLength* sizeof(*lFilePropertiesValuesBlock));
			for (i = 0; i < lFilePropertiesValuesLength; ++i)
			{
				lFilePropertiesValues[i] = &lFilePropertiesValuesBlock[i*lFilePropertiesValuesLineLength];
				lFilePropertiesValues[i][0] = '\0';
			}
			
			//Need to allocate array in one block because of Python
			lChannelsToLogBlock = malloc(lChannelsToLogLength*lChannelsToLogLineLength* sizeof(*lChannelsToLogBlock));
			for (i = 0; i < lChannelsToLogLength; ++i)
			{
				lChannelsToLog[i] = &lChannelsToLogBlock[i*lChannelsToLogLineLength];
				lChannelsToLog[i][0] = '\0';
			}
			
			strcpy(lChannelsToLog[0], "Targets/Controller/System Channels/System Time");
			strcpy(lChannelsToLog[1], "Targets/Controller/System Channels/HP Count");
			strcpy(lChannelsToLog[2], "Targets/Controller/System Channels/LP Count");
			strcpy(lChannelsToLog[3], "Targets/Controller/System Channels/Model Count");
			
			strcpy(lFilePropertiesNames[0], "LogPath");
			strcpy(lFilePropertiesNames[1], "LRate");
			strcpy(lFilePropertiesNames[2], "TaskName");

			Fmt(lRateString, "%f", lRate); 

			strcpy(lFilePropertiesValues[0], logPath);
			strcpy(lFilePropertiesValues[1], lRateString);
			strcpy(lFilePropertiesValues[2], taskName);

			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;

			status = StartDataLogging(taskName, taskName, logPath, 0.5, -0.5, TRUE, NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger_none, "", 
				lRate, lFilePropertiesNames,lFilePropertiesNamesLength,lFilePropertiesNamesLineLength,lFilePropertiesValues,lFilePropertiesValuesLength,lFilePropertiesValuesLineLength,lChannelsToLog, 
				lChannelsToLogLength,lChannelsToLogLineLength);
			if(HandleError(status,__FUNCTION__)) return;
			
			Delay(5);   
			
			status = StopDataLogging(taskName);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
}

void StartAndStopLogging2ShouldStartAndStopLogging2(void)
{			
			char *logPath = "C:\\Temp\\Test.tdms";
			double lRate = 100; 
			int i = 0;
            char *taskName = "testLog";
			char lRateString[10];

			int	lFilePropertiesNamesLineLength = 255,lFilePropertiesValuesLineLength = 255,lChannelsToLogLineLength = 255, lChannelShortNamesLineLength = 255;
			
			int  lFilePropertiesNamesLength = 3, 	lFilePropertiesValuesLength = 3, 	lChannelsToLogLength = 4, 	lChannelShortNamesLength = 4;
			char *lFilePropertiesNames[3], 			*lFilePropertiesValues[3], 			*lChannelsToLog[4],			*lChannelShortNames[4];	//Must match Lengths!
			char *lFilePropertiesNamesBlock, 		*lFilePropertiesValuesBlock, 		*lChannelsToLogBlock, 		*lChannelShortNamesBlock; 
			
			//Need to allocate array in one block because of Python
			lFilePropertiesNamesBlock = malloc(lFilePropertiesNamesLength*lFilePropertiesNamesLineLength* sizeof(*lFilePropertiesNamesBlock));
			//lFilePropertiesNames[0] = &lFilePropertiesNamesBlock[0]; //How to length size of this to 255?
			for (i = 0; i < lFilePropertiesNamesLength; ++i)
			{
				lFilePropertiesNames[i] = &lFilePropertiesNamesBlock[i*lFilePropertiesNamesLineLength];
				lFilePropertiesNames[i][0] = '\0';
			}
			
			//Need to allocate array in one block because of Python
			lFilePropertiesValuesBlock = malloc(lFilePropertiesValuesLength*lFilePropertiesValuesLineLength* sizeof(*lFilePropertiesValuesBlock));
			for (i = 0; i < lFilePropertiesValuesLength; ++i)
			{
				lFilePropertiesValues[i] = &lFilePropertiesValuesBlock[i*lFilePropertiesValuesLineLength];
				lFilePropertiesValues[i][0] = '\0';
			}
			
			//Need to allocate array in one block because of Python
			lChannelShortNamesBlock = malloc(lChannelShortNamesLength*lChannelShortNamesLineLength* sizeof(*lChannelShortNamesBlock));
			for (i = 0; i < lChannelShortNamesLength; ++i)
			{
				lChannelShortNames[i] = &lChannelShortNamesBlock[i*lChannelShortNamesLineLength];
				lChannelShortNames[i][0] = '\0';
			}
			
			//Need to allocate array in one block because of Python
			lChannelsToLogBlock = malloc(lChannelsToLogLength*lChannelsToLogLineLength* sizeof(*lChannelsToLogBlock));
			for (i = 0; i < lChannelsToLogLength; ++i)
			{
				lChannelsToLog[i] = &lChannelsToLogBlock[i*lChannelsToLogLineLength];
				lChannelsToLog[i][0] = '\0';
			}
			
			strcpy(lChannelsToLog[0], "Targets/Controller/System Channels/System Time");
			strcpy(lChannelsToLog[1], "Targets/Controller/System Channels/HP Count");
			strcpy(lChannelsToLog[2], "Targets/Controller/System Channels/LP Count");
			strcpy(lChannelsToLog[3], "Targets/Controller/System Channels/Model Count");
			
			strcpy(lChannelShortNames[0], "System Time");
			strcpy(lChannelShortNames[1], "HP Count");
			strcpy(lChannelShortNames[2], "LP Count");
			strcpy(lChannelShortNames[3], "Model Count");
			
			strcpy(lFilePropertiesNames[0], "LogPath");
			strcpy(lFilePropertiesNames[1], "LRate");
			strcpy(lFilePropertiesNames[2], "TaskName");

			Fmt(lRateString, "%f", lRate); 

			strcpy(lFilePropertiesValues[0], logPath);
			strcpy(lFilePropertiesValues[1], lRateString);
			strcpy(lFilePropertiesValues[2], taskName);

			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;

			status = StartDataLogging2(taskName, taskName, logPath, 0.5, TRUE, 1, "", 
				lRate, lFilePropertiesNames,lFilePropertiesNamesLength,lFilePropertiesNamesLineLength,lFilePropertiesValues,lFilePropertiesValuesLength,
				lFilePropertiesValuesLineLength,lChannelsToLog,lChannelsToLogLength,lChannelsToLogLineLength, 0, 0, lChannelShortNames,lChannelShortNamesLength,
				lChannelShortNamesLineLength);
			if(HandleError(status,__FUNCTION__)) return;
			
			Delay(5);   
			
			status = StopDataLogging2(taskName);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			free(lFilePropertiesNamesBlock);
			free(lFilePropertiesValuesBlock);
			free(lChannelShortNamesBlock);
			free(lChannelsToLogBlock);
			
}

void RTSequenceExecuteAsynchShouldStartRTSequence(void)
{			
			
			char *filePath = "d:\\NI Projects\\EXAM & cPython\\Python development\\cPython-Interface-for-NI-VeriStand\\VS\\Stimulus Profiles\\RT Sequence and Stimulus profile\\Test  RT seq.nivsseq";
			
//			char *UUT = "010";
			int stimState = 0;
			int i = 0;
			
			int	lParamNamesLineLength = 255,lParamValuesLineLength = 255,lParamTypesLineLength = 255;
			
			int  lParamNamesLength = 2, 	lParamValuesLength = 2, 	lParamTypesLength = 2;
			char *lParamNames[2], 			*lParamValues[2], 			*lParamTypes[2];	//Must match Lengths!
			char *lParamNamesBlock, 		*lParamValuesBlock, 		*lParamTypesBlock; 
			
			//Need to allocate array in one block because of Python
			lParamNamesBlock = malloc(lParamNamesLength*lParamNamesLineLength* sizeof(*lParamNamesBlock));
			for (i = 0; i < lParamNamesLength; ++i)
			{
				lParamNames[i] = &lParamNamesBlock[i*lParamNamesLineLength];
				lParamNames[i][0] = '\0';
			}
			
			//Need to allocate array in one block because of Python
			lParamValuesBlock = malloc(lParamValuesLength*lParamValuesLineLength* sizeof(*lParamValuesBlock));
			for (i = 0; i < lParamValuesLength; ++i)
			{
				lParamValues[i] = &lParamValuesBlock[i*lParamValuesLineLength];
				lParamValues[i][0] = '\0';
			}
			
			//Need to allocate array in one block because of Python
			lParamTypesBlock = malloc(lParamTypesLength*lParamTypesLineLength* sizeof(*lParamTypesBlock));
			for (i = 0; i < lParamTypesLength; ++i)
			{
				lParamTypes[i] = &lParamTypesBlock[i*lParamTypesLineLength];
				lParamTypes[i][0] = '\0';
			}
			
			
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			/*string[] paramNames = new string[2] {"UnitTest", "WaitParam"};
            string[] paramValues = new string[2] { "Aliases/UnitTest1", "5" };
            string[] paramTypes = new string[2] { "Path", "Double" };*/
			
			strcpy(lParamNames[0], "UnitTest");
			strcpy(lParamNames[1], "WaitParam");
			
			strcpy(lParamValues[0], "Aliases/UnitTest1");
			strcpy(lParamValues[1], "5");
			
			strcpy(lParamTypes[0], "Path");
			strcpy(lParamTypes[1], "Double");
			
			
			status = RTSequenceExecuteAsynch(filePath, lParamNames,lParamNamesLength, lParamNamesLineLength,
							lParamValues,lParamValuesLength, lParamValuesLineLength,
							lParamTypes,lParamTypesLength,lParamTypesLineLength);
			if(HandleError(status,__FUNCTION__)) return;
			
			free(lParamNamesBlock);
			free(lParamValuesBlock);
			free(lParamTypesBlock);
			
			Delay(2);   
			
			status = GetRTSequenceState(&stimState);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n Stimulus State: %d\n",stimState);
			
			CU_ASSERT_EQUAL(1, stimState);
						
			Delay(15);   
			
			status = GetRTSequenceState(&stimState);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n Stimulus State: %d\n",stimState);
			
			CU_ASSERT_EQUAL(4, stimState);
			
			status = RTSequenceUndeploy();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
	
}

void RTSequenceExecuteAsynchShouldReturnValue(void)
{			
			
			char *filePath = "d:\\NI Projects\\EXAM & cPython\\Python development\\cPython-Interface-for-NI-VeriStand\\VS\\Stimulus Profiles\\RT Sequence and Stimulus profile\\Test  RT seq.nivsseq";
			
//			char *UUT = "010";
			int stimState = 0;
			double sequenceReturnValue = 0;
			int i = 0;
			
			int	lParamNamesLineLength = 255,lParamValuesLineLength = 255,lParamTypesLineLength = 255;
			
			int  lParamNamesLength = 2, 	lParamValuesLength = 2, 	lParamTypesLength = 2;
			char *lParamNames[2], 			*lParamValues[2], 			*lParamTypes[2];	//Must match Lengths!
			char *lParamNamesBlock, 		*lParamValuesBlock, 		*lParamTypesBlock; 
			
			//Need to allocate array in one block because of Python
			lParamNamesBlock = malloc(lParamNamesLength*lParamNamesLineLength* sizeof(*lParamNamesBlock));
			for (i = 0; i < lParamNamesLength; ++i)
			{
				lParamNames[i] = &lParamNamesBlock[i*lParamNamesLineLength];
				lParamNames[i][0] = '\0';
			}
			
			//Need to allocate array in one block because of Python
			lParamValuesBlock = malloc(lParamValuesLength*lParamValuesLineLength* sizeof(*lParamValuesBlock));
			for (i = 0; i < lParamValuesLength; ++i)
			{
				lParamValues[i] = &lParamValuesBlock[i*lParamValuesLineLength];
				lParamValues[i][0] = '\0';
			}
			
			//Need to allocate array in one block because of Python
			lParamTypesBlock = malloc(lParamTypesLength*lParamTypesLineLength* sizeof(*lParamTypesBlock));
			for (i = 0; i < lParamTypesLength; ++i)
			{
				lParamTypes[i] = &lParamTypesBlock[i*lParamTypesLineLength];
				lParamTypes[i][0] = '\0';
			}
			
			
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			/*string[] paramNames = new string[2] {"UnitTest", "WaitParam"};
            string[] paramValues = new string[2] { "Aliases/UnitTest1", "5" };
            string[] paramTypes = new string[2] { "Path", "Double" };*/
			
			strcpy(lParamNames[0], "UnitTest");
			strcpy(lParamNames[1], "WaitParam");
			
			strcpy(lParamValues[0], "Aliases/UnitTest1");
			strcpy(lParamValues[1], "5");
			
			strcpy(lParamTypes[0], "Path");
			strcpy(lParamTypes[1], "Double");
			
			
			status = RTSequenceExecuteAsynch(filePath, lParamNames,lParamNamesLength, lParamNamesLineLength,
							lParamValues,lParamValuesLength, lParamValuesLineLength,
							lParamTypes,lParamTypesLength,lParamTypesLineLength);
			if(HandleError(status,__FUNCTION__)) return;
			
			free(lParamNamesBlock);
			free(lParamValuesBlock);
			free(lParamTypesBlock);
			
			Delay(2);   
			
			status = GetRTSequenceState(&stimState);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n Stimulus State: %d\n",stimState);
			
			CU_ASSERT_EQUAL(1, stimState);
						
			Delay(15);   
			
			status = GetRTSequenceState(&stimState);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n Stimulus State: %d\n",stimState);
			
			CU_ASSERT_EQUAL(4, stimState);
			
			status = GetRTSequenceReturnValue(&sequenceReturnValue);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n Return value: %f\n",sequenceReturnValue);
			
			CU_ASSERT_EQUAL(1, sequenceReturnValue);
			
			status = RTSequenceUndeploy();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
	
}

void  StimulusExecuteAsynchShouldStartStimulus(void)
{
			char *filePath = "d:\\NI Projects\\EXAM & cPython\\Python development\\cPython-Interface-for-NI-VeriStand\\VS\\Stimulus Profiles\\RT Sequence and Stimulus profile\\Test Stimulus.nivsstimprof";
			
			char *UUT = "010";
			int stimState = 0;
			
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			
			status = StimulusExecuteAsynch(filePath,UUT);
			if(HandleError(status,__FUNCTION__)) return;
			
			
			Delay(2);   
			
			status = GetStimulusState(&stimState);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n Stimulus State: %d\n",stimState);
			
			CU_ASSERT_EQUAL(2, stimState);
						
			Delay(10);   
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
}

void GetTDMSShouldReturnTDMSProperties(void)
{
			char *filePath = "d:\\NI Projects\\EXAM & cPython\\Python development\\cPython-Interface-for-NI-VeriStand\\VS\\Logs\\EXAM_TEMP__NIVS_testMeas_column.tdms";
			
			char *expectedProperty = "DT_DOUBLE";
			char *propertyName = "datatype";
			char *activeProperty;
			
			double loggingRate = 0; 
			int	logChannelCount = 0;
			__int64 logLength = 0;
			
			activeProperty = (char *) malloc(255);
			
			status = TDMSOpen(filePath);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetTDMSLoggingRate(&loggingRate);
			if(HandleError(status,__FUNCTION__)) return;
			printf("\n loggingRate: %f\n",loggingRate);
			CU_ASSERT_EQUAL(50, loggingRate);
			
			status = GetTDMSLogChannelCount(&logChannelCount);
			if(HandleError(status,__FUNCTION__)) return;
			printf("\n logChannelCount: %i\n",logChannelCount);
			CU_ASSERT_EQUAL(3, logChannelCount);
			
			status = GetTDMSLogLength(&logLength);
			if(HandleError(status,__FUNCTION__)) return;
			printf("\n logLength: %I64d\n",logLength);
			CU_ASSERT_EQUAL(5, logLength);
			
			status = GetTDMSLogChannelProperty(1,propertyName, activeProperty);
			if(HandleError(status,__FUNCTION__)) return;
			printf("\n propertyValue: %s\n",activeProperty);
			CU_ASSERT_STRING_EQUAL(activeProperty, expectedProperty);
			
			status = TDMSClose();
			if(HandleError(status,__FUNCTION__)) return;
			
			free(activeProperty);
}

void TDMSReadColumnShouldReturnTDMSColumn(void)
{
			char *filePath = "d:\\NI Projects\\EXAM & cPython\\Python development\\cPython-Interface-for-NI-VeriStand\\VS\\Logs\\EXAM_TEMP__NIVS_testMeas_column.tdms";
			double	*returnDValues;  
			
			double loggingRate = 0; 
			int	logChannelCount = 0;
			__int64 logLength = 0;
			
			status = TDMSOpen(filePath);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetTDMSLogLength(&logLength);
			if(HandleError(status,__FUNCTION__)) return;
			returnDValues = (double *) malloc((size_t)logLength * sizeof(double));    
			
			status =  TDMSReadColumn(returnDValues ,(int)logLength,2);
			if(HandleError(status,__FUNCTION__)) return;
			
			//int TDMSReadColumn(double logColumnData[],int iColumnLength,int channelIndex);

			printf("\n%f,%f\n",returnDValues[0],returnDValues[1]);
			
			status = TDMSClose();
			if(HandleError(status,__FUNCTION__)) return;
			
			CU_ASSERT_EQUAL(returnDValues[0], 20.43);
			CU_ASSERT_EQUAL(returnDValues[1], 20.45);
			CU_ASSERT_EQUAL(0, status);
			
			free((void *)returnDValues);
}

void TDMSReadTimeColumnShouldReturnTDMSTimeColumn(void)
{
			char *filePath = "d:\\NI Projects\\EXAM & cPython\\Python development\\cPython-Interface-for-NI-VeriStand\\VS\\Logs\\EXAM_TEMP__NIVS_testMeasTime.tdms";
			double	*returnDValues;  
			
			double loggingRate = 0; 
			int	logChannelCount = 0;
			__int64 logLength = 0;
			
			status = TDMSOpen(filePath);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetTDMSLogLength(&logLength);
			if(HandleError(status,__FUNCTION__)) return;
			returnDValues = (double *) malloc((size_t)logLength * sizeof(double));    
			
			status =  TDMSReadTimeColumn(returnDValues ,(int)logLength);
			if(HandleError(status,__FUNCTION__)) return;
			
			//int TDMSReadColumn(double logColumnData[],int iColumnLength,int channelIndex);

			printf("\n%f,%f\n",returnDValues[0],returnDValues[1]);
			
			status = TDMSClose();
			if(HandleError(status,__FUNCTION__)) return;
			
			//Should use if (Abs(x - y) <= Max(absTol, relTol * Max(Abs(x), Abs(y)))) …
			CU_ASSERT_EQUAL(returnDValues[0], 4.050000);
			CU_ASSERT_EQUAL(returnDValues[2], 4.070000);
			CU_ASSERT_EQUAL(0, status);
			
			free((void *)returnDValues);
}

void UnDeployShouldUnDeployProject(void)
{
			char 	*activeProject;
			int activeProjectsNum = 0;
			char 	*activeSession = 0;
			int activeSessionsNum = 0;
			
			activeProject = (char *) malloc(255);
			activeSession = (char *) malloc(255);
	  		status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;

			status = DeployProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetActiveProject(activeProject,0,&activeProjectsNum);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n%i open project: %s\n",activeProjectsNum, activeProject);
			
			status = GetAllDeployedSessions(activeSession,0,&activeSessionsNum);
			if(HandleError(status,__FUNCTION__)) return;
			
			//printf("\n%i open sessions: %s\n",activeSessionsNum, activeSession);
			CU_ASSERT_EQUAL(0, status);
			
			
			status = UndeployProject();
			if(HandleError(status,__FUNCTION__)) return;

			status = GetAllDeployedSessions(activeSession,0,&activeSessionsNum);
			/*printf("\n%i open sessions: %s\n",activeSessionsNum, activeSessions[0]);*/
			CU_ASSERT_EQUAL(-6571, status);
			status=0;

			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			CU_ASSERT_EQUAL(0, status);
			free(activeProject);
			free(activeSession); 

}

void DisconnectAndConnectShouldDisconnectAndReconnectToProject(void)
{
			char 	*activeProject;
			int activeProjectsNum = 0;
			char 	*activeSession = 0;
			int activeSessionsNum = 0;
			
			activeProject = (char *) malloc(255);
			activeSession = (char *) malloc(255);
	  		status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;

			status = DeployProjectWithProgress();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetActiveProject(activeProject,0,&activeProjectsNum);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n%i open project: %s\n",activeProjectsNum, activeProject);
			
			status = GetAllDeployedSessions(activeSession,0,&activeSessionsNum);
			if(HandleError(status,__FUNCTION__)) return;
			
			//printf("\n%i open sessions: %s\n",activeSessionsNum, activeSession);
			CU_ASSERT_EQUAL(0, status);
			
			
			status = Disconnect();
			if(HandleError(status,__FUNCTION__)) return;

			status = GetAllDeployedSessions(activeSession,0,&activeSessionsNum);
			/*printf("\n%i open sessions: %s\n",activeSessionsNum, activeSessions[0]);*/
			CU_ASSERT_EQUAL(-6571, status);
			status=0;
			
			status = Connect();
			if(HandleError(status,__FUNCTION__)) return;

			status = GetActiveProject(activeProject,0,&activeProjectsNum);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n%i open project: %s\n",activeProjectsNum, activeProject);
			
			status = GetAllDeployedSessions(activeSession,0,&activeSessionsNum);
			if(HandleError(status,__FUNCTION__)) return;
			
			//printf("\n%i open sessions: %s\n",activeSessionsNum, activeSession);
			CU_ASSERT_EQUAL(0, status);
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			CU_ASSERT_EQUAL(0, status);
			free(activeProject);
			free(activeSession); 

}


void SetMultipleChannelsValueShouldSetMultipleChannelsValue (void)
{
	  		int iLength = 2;   
			char *channelArray[2]; //Must match iLength
			char *channelArrayBlock;
			double	dValues [2];  //Must match iLength
			double	*returnDValues,*returnDValues1;
			int iCharLineLength = 255;
			
			returnDValues = (double *) malloc(iLength * sizeof(double));
			returnDValues1 = (double *) malloc(iLength * sizeof(double));
			
			//Need to allocate array in one block because of Python
			channelArrayBlock = malloc(2*iCharLineLength* sizeof(*channelArrayBlock));
			channelArray[0] = &channelArrayBlock[0]; //How to length size of this to 255?
			channelArray[0][0] = '\0';
			channelArray[1] = &channelArrayBlock[1*iCharLineLength];
			
	/*		if(array == NULL) {        
      		fprintf(stderr, "out of memory\n");    
        	/*exit or return*/

			dValues [0] = -3.0;
			dValues [1] = -6.0; 
			
			strcpy(channelArray[0], "Aliases/UnitTest");
			strcpy(channelArray[1], "Aliases/UnitTest1");
			
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetMultipleChannelValues(channelArray,returnDValues ,iLength,iCharLineLength);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = SetMultipleChannelValues(channelArray,dValues,iLength,iCharLineLength);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetMultipleChannelValues(channelArray,returnDValues1 ,iLength,iCharLineLength);
			if(HandleError(status,__FUNCTION__)) return;
			
			//CU_ASSERT_EQUAL(returnDValues[0], returnDValues1[0]);
			//CU_ASSERT_EQUAL(returnDValues[1], returnDValues1[1]);
			
			Delay(0.2);   
			
			status = GetMultipleChannelValues(channelArray,returnDValues ,iLength,iCharLineLength);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n%f,%f\n",returnDValues[0],returnDValues[1]);
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			
			CU_ASSERT_EQUAL(returnDValues[0], dValues[0]);
			CU_ASSERT_EQUAL(returnDValues[1], dValues[1]);
			CU_ASSERT_EQUAL(0, status);
			
			free((void *)returnDValues);
			
}	  													 

void SetMultipleChannelsValueSynchShouldSetMultipleChannelsValueSynch (void)
{
	  		int iLength = 2;   
			char *channelArray[2]; //Must match iLength
			char *channelArrayBlock;
			double	dValues [2];  //Must match iLength
			double	*returnDValues;
			int iCharLineLength = 255;
			double writeTime = 0;
			
			returnDValues = (double *) malloc(iLength * sizeof(double));
			
			//Need to allocate array in one block because of Python
			channelArrayBlock = malloc(2*iCharLineLength* sizeof(*channelArrayBlock));
			channelArray[0] = &channelArrayBlock[0]; //How to length size of this to 255?
			channelArray[0][0] = '\0';
			channelArray[1] = &channelArrayBlock[1*iCharLineLength];
			
	/*		if(array == NULL) {        
      		fprintf(stderr, "out of memory\n");    
        	/*exit or return*/

			dValues [0] = -5.0;
			dValues [1] = -8.0; 
			
			strcpy(channelArray[0], "Aliases/UnitTest");
			strcpy(channelArray[1], "Aliases/UnitTest1");
			
			status = OpenProject(prj);
			if(HandleError(status,__FUNCTION__)) return;

			status = ShowProjectWindow();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = RunProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetMultipleChannelValues(channelArray,returnDValues ,iLength,iCharLineLength);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = SetMultipleChannelValuesSynch(channelArray,dValues,iLength,iCharLineLength,&writeTime);
			if(HandleError(status,__FUNCTION__)) return;
			
			status = GetMultipleChannelValues(channelArray,returnDValues ,iLength,iCharLineLength);
			if(HandleError(status,__FUNCTION__)) return;
			
			printf("\n%f,%f\n",returnDValues[0],returnDValues[1]);
			
			status = CloseProject();
			if(HandleError(status,__FUNCTION__)) return;
			
			CU_ASSERT_EQUAL(returnDValues[0], dValues[0]);
			CU_ASSERT_EQUAL(returnDValues[1], dValues[1]);
			CU_ASSERT_EQUAL(0, status);
			
			free((void *)returnDValues);
			
}	  													 



 int HandleError(int status, char *pszFunctionName)
{
  if (status !=0)
			{	
				printf("\n********************\nFunction: %s\n********************\n", pszFunctionName);
				
				sprintf(cdescription, "\nError (%d): %s\n", status, CDotNetGetErrorDescription(status));
				printf("%s\n",pcdescription);				
				
				/*pszLastErrorMessage = GetLastErrorMessage();
				printf("%s",pszLastErrorMessage);*/
				
				CU_ASSERT_EQUAL(0, status);				
				return TRUE;
				//return;
			}
  else 
  {
	  return FALSE;
  }
}


   		

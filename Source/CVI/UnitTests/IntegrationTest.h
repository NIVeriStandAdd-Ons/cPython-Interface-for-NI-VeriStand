//==============================================================================
//
// Title:		IntegrationTest.h
// Purpose:		A short description of the interface.
//
// Created on:	11/9/2012 at 10:15:25 AM by Jiri Keprt.
// Copyright:	NI. All Rights Reserved.
//
//==============================================================================

#ifndef __IntegrationTest_H__
#define __IntegrationTest_H__

//#include "TestDB.h" 

/******************************************************************************/
/* Function Prototypes                                                        */
/******************************************************************************/

void RunProjectShouldRunProject (void);
void CloseShouldCloseOpenedProject (void);
void CloseOpenWorkspaceShouldCloseOpenRunningProject(void);
int  HandleError(int status, char *pszFunctionName);
void SetGetChannelValueShouldSetAndGetChannelValue (void);
void SetGetChannelValueSynchShouldSetAndGetChannelValueSynch (void);
void SetMultipleChannelsValueSynchShouldSetMultipleChannelsValueSynch(void);
void SetMultipleChannelsValueShouldSetMultipleChannelsValue (void);
void GetActiveProjectShouldReturnProjects(void);
void UnDeployShouldUnDeployProject(void);
void StartAndStopLoggingShouldStartAndStopLogging(void);
void StartAndStopLogging2ShouldStartAndStopLogging2(void);
void GetTDMSShouldReturnTDMSProperties(void);
void GetAvailableChannelsToReadCountShouldReturnCount(void);
void GetAvailableChannelsToWriteCountShouldReturnCount(void);
void GetAvailableChannelToReadShouldReturnChannel(void);
void GetAvailableChannelToWriteShouldReturnChannel(void);
void DisconnectAndConnectShouldDisconnectAndReconnectToProject(void);
void SetGetParamValueSynchShouldSetAndGetParamValueSynch (void);
void SetGetParamValueShouldSetAndGetParamValue (void);
void TDMSReadColumnShouldReturnTDMSColumn (void);
void TDMSReadTimeColumnShouldReturnTDMSTimeColumn(void);

#endif  /* ndef __IntegrationTest_H__ */

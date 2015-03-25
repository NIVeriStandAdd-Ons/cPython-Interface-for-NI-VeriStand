#include <cvidotnet.h>
#include "VeristandPythonInterop.h"
#include <ansi_c.h>
//==============================================================================
//
// Title:		VeriStandHelper.c
// Purpose:		A short description of the implementation.
//
// Created on:	10.4.2013 at 13:35:51 by Jiri Keprt.
// Copyright:	NI. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include "VeriStandHelper.h"
#include "VeriStandCviDll.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

#define STATUS_OK 0

extern VeristandPythonInterop_VeriStandInterop					instance_handle;
extern char 													szLastErrorMessage [500];
extern int 														maxErrorLength;

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

			 

void StoreErrorForGetLastErrorFromDotNetHandle(char *pszFunctionName, CDotNetHandle *exceptionHandle)
{
	CDotNetHandle exception_Handle;

	char *pszExceptionMessage = NULL;
	char *pszSource = NULL;
	char *pszStack_trace = NULL;
	
	if (exceptionHandle == NULL)
	{
		sprintf (szLastErrorMessage, "Error occured, however can not retrieve error message.");
		return;
	}
	
	if (CDotNetGetExceptionInfo(exceptionHandle, 0, &pszExceptionMessage, &pszSource, &pszStack_trace, 0, 0) != 0)
	//if (CDotNetGetExceptionInfo(exceptionHandle, 0, &pszExceptionMessage, 0, 0, 0, 0) != 0)
	{
		sprintf (szLastErrorMessage, "Error occured, but failed to retrieve error message.");
		return;
	}
	
	snprintf (szLastErrorMessage, maxErrorLength, 
		"\nError: Function Name: %s\n\
		Error Message: %s\n\
		Source: %s \n\
		Stack Trace: %s\n", 
		pszFunctionName, pszExceptionMessage, pszSource, pszStack_trace);
	
	LogErrorMessage(szLastErrorMessage);
	
	CDotNetFreeMemory(pszExceptionMessage);
	CDotNetFreeMemory(pszSource);
	CDotNetFreeMemory(pszStack_trace);
	
}

void LogErrorMessage(char* pszErrorMessage)
{
	fprintf(stderr, "%s", pszErrorMessage);
	//if (POPUPDEBUGDLL) MessagePopup ("CVI DLL", pszErrorMessage);
}

void StoreErrorForGetLastError(char *pszFunctionName, char *pszErrorMessage)
{
	snprintf (szLastErrorMessage, maxErrorLength, 
		"Function Name: %s\n Error Message: %s", pszFunctionName, pszErrorMessage);
	
	LogErrorMessage(szLastErrorMessage);
}

//==============================================================================
//
// Title:		VeriStandHelper.h
// Purpose:		A short description of the interface.
//
// Created on:	10.4.2013 at 13:35:51 by Jiri Keprt.
// Copyright:	NI. All Rights Reserved.
//
//==============================================================================

#ifndef __VeriStandHelper_H__
#define __VeriStandHelper_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// External variables

//==============================================================================
// Global functions

void StoreErrorForGetLastErrorFromDotNetHandle(char *pszFunctionName, CDotNetHandle *exceptionHandle);
void LogErrorMessage(char* pszErrorMessage);
void StoreErrorForGetLastError(char *pszFunctionName, char *pszErrorMessage);


#ifdef __cplusplus
    }
#endif

#endif  /* ndef __VeriStandHelper_H__ */

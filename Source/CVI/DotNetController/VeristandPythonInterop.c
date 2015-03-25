// CVI wrapper source file for .NET assembly: VeristandPythonInterop, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null

#include "VeristandPythonInterop.h"
#include <stdarg.h>

// Macros
#ifndef __errChk
#define __errChk(f) if (__error = (f), __error < 0) goto __Error; else
#endif
#ifndef __nullChk
#define __nullChk(p) if (!(p)) { __error = CDotNetOutOfMemoryError; goto __Error; } else
#endif

// Constants
static const char * __assemblyName = "VeristandPythonInterop, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null";

// Static Variables
static CDotNetAssemblyHandle __assemblyHandle = 0;

// Forward declarations
static int CVIFUNC NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger__Create(
	NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static void _CDotNetGenDisposeScalar(void * scalar, unsigned int typeId);
static void CVIFUNC_C _CDotNetGenDisposeArray(void * array, unsigned int typeId, size_t nDims, ...);

// Global Functions
int CVIFUNC Initialize_VeristandPythonInterop(void)
{
	int __error = 0;


	if (__assemblyHandle == 0)
		__errChk(CDotNetLoadAssembly(
			__assemblyName, 
			&__assemblyHandle));



__Error:
	return __error;
}

int CVIFUNC Close_VeristandPythonInterop(void)
{
	int __error = 0;


	if (__assemblyHandle) {
		__errChk(CDotNetDiscardAssemblyHandle(__assemblyHandle));
		__assemblyHandle = 0;
	}



__Error:
	return __error;
}


// Type: VeristandPythonInterop.VeriStandTDMSHandler
int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler__Create(
	VeristandPythonInterop_VeriStandTDMSHandler * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandTDMSHandler", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_TDMSOpen(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	char * filePath,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: filePath
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &filePath;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandTDMSHandler", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TDMSOpen", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_TDMSClose(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandTDMSHandler", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TDMSClose", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_GetTDMSLoggingRate(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandTDMSHandler", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetTDMSLoggingRate", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_GetTDMSLogChannelCount(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandTDMSHandler", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetTDMSLogChannelCount", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_GetTDMSLogLength(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	__int64 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT64;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandTDMSHandler", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetTDMSLogLength", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_GetTDMSLogChannelProperty(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	int channelIndex,
	char * propertyName,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: channelIndex
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channelIndex;

	// Pre-process parameter: propertyName
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &propertyName;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandTDMSHandler", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetTDMSLogChannelProperty", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_TDMSReadLine(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	int reqLine,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process parameter: reqLine
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &reqLine;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandTDMSHandler", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TDMSReadLine", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_DOUBLE, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_DOUBLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_TDMSReadColumn(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	int reqColumn,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process parameter: reqColumn
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &reqColumn;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandTDMSHandler", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TDMSReadColumn", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_DOUBLE, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_DOUBLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandTDMSHandler_TDMSTimeColumn(
	VeristandPythonInterop_VeriStandTDMSHandler __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandTDMSHandler", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TDMSTimeColumn", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_DOUBLE, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_DOUBLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}


// Type: VeristandPythonInterop.VeriStandInterop
int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetVeristandInterop(
	VeristandPythonInterop_VeriStandInterop * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"GetVeristandInterop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetNewVeristandInterop(
	VeristandPythonInterop_VeriStandInterop * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"GetNewVeristandInterop", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_DeployProject(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"DeployProject", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_DeployProjectWithProgress(
	VeristandPythonInterop_VeriStandInterop __instance,
	int showProgress,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: showProgress
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &showProgress;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"DeployProjectWithProgress", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_UndeployProject(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"UndeployProject", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_OpenWorkspace(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"OpenWorkspace", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_CloseWorkspace(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CloseWorkspace", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_Connect(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Connect", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_Disconnect(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Disconnect", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetChannelValue(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * channelIdentidier,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channelIdentidier
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &channelIdentidier;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetChannelValue", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetTargetRate(
	VeristandPythonInterop_VeriStandInterop __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetTargetRate", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetTargetIP(
	VeristandPythonInterop_VeriStandInterop __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetTargetIP", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetMultipleChannelValues(
	VeristandPythonInterop_VeriStandInterop __instance,
	char ** names,
	ssize_t __namesLength,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle names__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process parameter: names
	if (names)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__namesLength, 
			names, 
			&names__));
	__parameterTypeNames[0] = "System.String[]";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[0] = &names__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetMultipleChannelValues", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_DOUBLE, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (names__)
		CDotNetDiscardHandle(names__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_DOUBLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetActiveProjects(
	VeristandPythonInterop_VeriStandInterop __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetActiveProjects", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_STRING, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_STRING, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetAllDeployedSessions(
	VeristandPythonInterop_VeriStandInterop __instance,
	char *** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetAllDeployedSessions", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_STRING, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_STRING, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_SetMultipleChannelValues(
	VeristandPythonInterop_VeriStandInterop __instance,
	char ** names,
	ssize_t __namesLength,
	double * values,
	ssize_t __valuesLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle names__ = 0;
	CDotNetHandle values__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: names
	if (names)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__namesLength, 
			names, 
			&names__));
	__parameterTypeNames[0] = "System.String[]";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[0] = &names__;

	// Pre-process parameter: values
	if (values)
		__errChk(CDotNetCreateArray(
			CDOTNET_DOUBLE, 
			1, 
			0, 
			&__valuesLength, 
			values, 
			&values__));
	__parameterTypeNames[1] = "System.Double[]";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_ARRAY);
	__parameters[1] = &values__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetMultipleChannelValues", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (names__)
		CDotNetDiscardHandle(names__);
	if (values__)
		CDotNetDiscardHandle(values__);
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_SetMultipleChannelValuesSynch(
	VeristandPythonInterop_VeriStandInterop __instance,
	char ** names,
	ssize_t __namesLength,
	double * values,
	ssize_t __valuesLength,
	double * writeTime,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle names__ = 0;
	CDotNetHandle values__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: names
	if (names)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__namesLength, 
			names, 
			&names__));
	__parameterTypeNames[0] = "System.String[]";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[0] = &names__;

	// Pre-process parameter: values
	if (values)
		__errChk(CDotNetCreateArray(
			CDOTNET_DOUBLE, 
			1, 
			0, 
			&__valuesLength, 
			values, 
			&values__));
	__parameterTypeNames[1] = "System.Double[]";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_ARRAY);
	__parameters[1] = &values__;

	// Pre-process parameter: writeTime
	__parameterTypeNames[2] = "System.Double&";
	__parameterTypes[2] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[2] = writeTime;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetMultipleChannelValuesSynch", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (names__)
		CDotNetDiscardHandle(names__);
	if (values__)
		CDotNetDiscardHandle(values__);
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_SetChannelValue(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * channelIdentifier,
	double value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channelIdentifier
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &channelIdentifier;

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetChannelValue", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_SetChannelValueSynch(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * channelIdentifier,
	double value,
	double * writeTime,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channelIdentifier
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &channelIdentifier;

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &value;

	// Pre-process parameter: writeTime
	__parameterTypeNames[2] = "System.Double&";
	__parameterTypes[2] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[2] = writeTime;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetChannelValueSynch", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_LaunchVeriStand(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"LaunchVeriStand", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_RunProject(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RunProject", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_CloseVeristand(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CloseVeristand", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_OpenProject(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * projectPath,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: projectPath
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &projectPath;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"OpenProject", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_CloseProject(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CloseProject", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_ShowProjectWindow(
	VeristandPythonInterop_VeriStandInterop __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ShowProjectWindow", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[12] = {0};
	unsigned int __parameterTypes[12];
	void * __parameters[12];
	CDotNetHandle lTriggerType__ = 0;
	CDotNetHandle lFilePropertiesNames__ = 0;
	CDotNetHandle lFilePropertiesValues__ = 0;
	CDotNetHandle lChannelsToLog__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: logConfigName
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &logConfigName;

	// Pre-process parameter: lDescription
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &lDescription;

	// Pre-process parameter: lFilePath
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &lFilePath;

	// Pre-process parameter: lTriggerHighLimit
	__parameterTypeNames[3] = "System.Double";
	__parameterTypes[3] = (CDOTNET_DOUBLE);
	__parameters[3] = &lTriggerHighLimit;

	// Pre-process parameter: lTriggerLowLimit
	__parameterTypeNames[4] = "System.Double";
	__parameterTypes[4] = (CDOTNET_DOUBLE);
	__parameters[4] = &lTriggerLowLimit;

	// Pre-process parameter: lReplaceFile
	__parameterTypeNames[5] = "System.Boolean";
	__parameterTypes[5] = (CDOTNET_BOOLEAN);
	__parameters[5] = &lReplaceFile;

	// Pre-process parameter: lTriggerType
	__errChk(NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger__Create(
		&lTriggerType, 
		&lTriggerType__, 
		__exception));
	__parameterTypeNames[6] = "NationalInstruments.VeriStand.ClientAPI.LogInfo+trigger,NationalInstruments.VeriStand.ClientAPI, Version=2013.1.0.0, Culture=neutral, PublicKeyToken=a6d690c380daa308";
	__parameterTypes[6] = (CDOTNET_ENUM);
	__parameters[6] = &lTriggerType__;

	// Pre-process parameter: lTriggerChannel
	__parameterTypeNames[7] = "System.String";
	__parameterTypes[7] = (CDOTNET_STRING);
	__parameters[7] = &lTriggerChannel;

	// Pre-process parameter: lRate
	__parameterTypeNames[8] = "System.Double";
	__parameterTypes[8] = (CDOTNET_DOUBLE);
	__parameters[8] = &lRate;

	// Pre-process parameter: lFilePropertiesNames
	if (lFilePropertiesNames)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__lFilePropertiesNamesLength, 
			lFilePropertiesNames, 
			&lFilePropertiesNames__));
	__parameterTypeNames[9] = "System.String[]";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[9] = &lFilePropertiesNames__;

	// Pre-process parameter: lFilePropertiesValues
	if (lFilePropertiesValues)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__lFilePropertiesValuesLength, 
			lFilePropertiesValues, 
			&lFilePropertiesValues__));
	__parameterTypeNames[10] = "System.String[]";
	__parameterTypes[10] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[10] = &lFilePropertiesValues__;

	// Pre-process parameter: lChannelsToLog
	if (lChannelsToLog)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__lChannelsToLogLength, 
			lChannelsToLog, 
			&lChannelsToLog__));
	__parameterTypeNames[11] = "System.String[]";
	__parameterTypes[11] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[11] = &lChannelsToLog__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"StartDataLogging", 
		0, 
		0, 
		12, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (lTriggerType__)
		CDotNetDiscardHandle(lTriggerType__);
	if (lFilePropertiesNames__)
		CDotNetDiscardHandle(lFilePropertiesNames__);
	if (lFilePropertiesValues__)
		CDotNetDiscardHandle(lFilePropertiesValues__);
	if (lChannelsToLog__)
		CDotNetDiscardHandle(lChannelsToLog__);
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[14] = {0};
	unsigned int __parameterTypes[14];
	void * __parameters[14];
	CDotNetHandle lFilePropertiesNames__ = 0;
	CDotNetHandle lFilePropertiesValues__ = 0;
	CDotNetHandle lChannelsToLog__ = 0;
	CDotNetHandle lChannelShortNames__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: logConfigName
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &logConfigName;

	// Pre-process parameter: lDescription
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &lDescription;

	// Pre-process parameter: lFilePath
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &lFilePath;

	// Pre-process parameter: fTriggerLevel
	__parameterTypeNames[3] = "System.Double";
	__parameterTypes[3] = (CDOTNET_DOUBLE);
	__parameters[3] = &fTriggerLevel;

	// Pre-process parameter: iTriggerSlope
	__parameterTypeNames[4] = "System.Int32";
	__parameterTypes[4] = (CDOTNET_INT32);
	__parameters[4] = &iTriggerSlope;

	// Pre-process parameter: lTriggerChannel
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &lTriggerChannel;

	// Pre-process parameter: lRate
	__parameterTypeNames[6] = "System.Double";
	__parameterTypes[6] = (CDOTNET_DOUBLE);
	__parameters[6] = &lRate;

	// Pre-process parameter: lFilePropertiesNames
	if (lFilePropertiesNames)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__lFilePropertiesNamesLength, 
			lFilePropertiesNames, 
			&lFilePropertiesNames__));
	__parameterTypeNames[7] = "System.String[]";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[7] = &lFilePropertiesNames__;

	// Pre-process parameter: lFilePropertiesValues
	if (lFilePropertiesValues)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__lFilePropertiesValuesLength, 
			lFilePropertiesValues, 
			&lFilePropertiesValues__));
	__parameterTypeNames[8] = "System.String[]";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[8] = &lFilePropertiesValues__;

	// Pre-process parameter: lChannelsToLog
	if (lChannelsToLog)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__lChannelsToLogLength, 
			lChannelsToLog, 
			&lChannelsToLog__));
	__parameterTypeNames[9] = "System.String[]";
	__parameterTypes[9] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[9] = &lChannelsToLog__;

	// Pre-process parameter: lDuration
	__parameterTypeNames[10] = "System.Double";
	__parameterTypes[10] = (CDOTNET_DOUBLE);
	__parameters[10] = &lDuration;

	// Pre-process parameter: lPreTriggerDuration
	__parameterTypeNames[11] = "System.Double";
	__parameterTypes[11] = (CDOTNET_DOUBLE);
	__parameters[11] = &lPreTriggerDuration;

	// Pre-process parameter: lReplaceFile
	__parameterTypeNames[12] = "System.Boolean";
	__parameterTypes[12] = (CDOTNET_BOOLEAN);
	__parameters[12] = &lReplaceFile;

	// Pre-process parameter: lChannelShortNames
	if (lChannelShortNames)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			1, 
			0, 
			&__lChannelShortNamesLength, 
			lChannelShortNames, 
			&lChannelShortNames__));
	__parameterTypeNames[13] = "System.String[]";
	__parameterTypes[13] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[13] = &lChannelShortNames__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"StartDataLogging2", 
		0, 
		0, 
		14, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (lFilePropertiesNames__)
		CDotNetDiscardHandle(lFilePropertiesNames__);
	if (lFilePropertiesValues__)
		CDotNetDiscardHandle(lFilePropertiesValues__);
	if (lChannelsToLog__)
		CDotNetDiscardHandle(lChannelsToLog__);
	if (lChannelShortNames__)
		CDotNetDiscardHandle(lChannelShortNames__);
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetDataLogging2SessionState(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * logConfigName,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: logConfigName
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &logConfigName;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetDataLogging2SessionState", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetDataLogging2State(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * LogConfigName,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: LogConfigName
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &LogConfigName;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetDataLogging2State", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_StopDataLogging(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * LogConfigName,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: LogConfigName
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &LogConfigName;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"StopDataLogging", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_StopDataLogging2(
	VeristandPythonInterop_VeriStandInterop __instance,
	char * LogConfigName,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: LogConfigName
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &LogConfigName;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"StopDataLogging2", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetAvailableChannelToRead(
	VeristandPythonInterop_VeriStandInterop __instance,
	int channelIndex,
	int * availableChannelCount,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: channelIndex
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channelIndex;

	// Pre-process parameter: availableChannelCount
	__parameterTypeNames[1] = "System.Int32&";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[1] = availableChannelCount;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetAvailableChannelToRead", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetAvailableChannelToWrite(
	VeristandPythonInterop_VeriStandInterop __instance,
	int channelIndex,
	int * availableChannelCount,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: channelIndex
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &channelIndex;

	// Pre-process parameter: availableChannelCount
	__parameterTypeNames[1] = "System.Int32&";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[1] = availableChannelCount;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetAvailableChannelToWrite", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetAvailableChannelsToReadCount(
	VeristandPythonInterop_VeriStandInterop __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetAvailableChannelsToReadCount", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VeriStandInterop_GetAvailableChannelsToWriteCount(
	VeristandPythonInterop_VeriStandInterop __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VeriStandInterop", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetAvailableChannelsToWriteCount", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: VeristandPythonInterop.VSLogChannel
int CVIFUNC VeristandPythonInterop_VSLogChannel__Create(
	VeristandPythonInterop_VSLogChannel * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"VeristandPythonInterop.VSLogChannel", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC VeristandPythonInterop_VSLogChannel_FillParams(
	VeristandPythonInterop_VSLogChannel __instance,
	char * channelPath,
	char * customName,
	char * customGroup,
	char ** lProperties,
	ssize_t __lPropertiesLength1,
	ssize_t __lPropertiesLength2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle lProperties__ = 0;
	ssize_t __lPropertiesLengths[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: channelPath
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &channelPath;

	// Pre-process parameter: customName
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &customName;

	// Pre-process parameter: customGroup
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &customGroup;

	// Pre-process parameter: lProperties
	__lPropertiesLengths[0] = __lPropertiesLength1;
	__lPropertiesLengths[1] = __lPropertiesLength2;
	if (lProperties)
		__errChk(CDotNetCreateArray(
			CDOTNET_STRING, 
			2, 
			0, 
			__lPropertiesLengths, 
			lProperties, 
			&lProperties__));
	__parameterTypeNames[3] = "System.String[,]";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_ARRAY);
	__parameters[3] = &lProperties__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VSLogChannel", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"FillParams", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (lProperties__)
		CDotNetDiscardHandle(lProperties__);
	return __error;
}

int CVIFUNC VeristandPythonInterop_VSLogChannel__Get__lLogChannel(
	VeristandPythonInterop_VSLogChannel __instance,
	NationalInstruments_VeriStand_ClientAPI_LogChannel * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VSLogChannel", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"lLogChannel", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC VeristandPythonInterop_VSLogChannel__Set__lLogChannel(
	VeristandPythonInterop_VSLogChannel __instance,
	NationalInstruments_VeriStand_ClientAPI_LogChannel lLogChannel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: lLogChannel
	__parameterTypeNames[0] = "NationalInstruments.VeriStand.ClientAPI.LogChannel,NationalInstruments.VeriStand.ClientAPI, Version=2013.1.0.0, Culture=neutral, PublicKeyToken=a6d690c380daa308";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &lLogChannel;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"VeristandPythonInterop.VSLogChannel", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"lLogChannel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}



// Internal functions
static int CVIFUNC NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger__Create(
	NationalInstruments_VeriStand_ClientAPI_LogInfo_trigger * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		"NationalInstruments.VeriStand.ClientAPI, Version=2013.1.0.0, Culture=neutral, PublicKeyToken=a6d690c380daa308", 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"NationalInstruments.VeriStand.ClientAPI.LogInfo+trigger", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static void _CDotNetGenDisposeScalar(void * scalar, unsigned int typeId)
{
	if (!*(void **)scalar)
		return;

	typeId &= CDOTNET_BASIC_TYPE_MASK;
	if (typeId == CDOTNET_STRING) {
		CDotNetFreeMemory(*(char **)scalar);
		*(char **)scalar = 0;
	}
	else if (typeId == CDOTNET_OBJECT || typeId == CDOTNET_STRUCT) {
		CDotNetDiscardHandle(*(CDotNetHandle *)scalar);
		*(CDotNetHandle *)scalar = 0;
	}
}

static void CVIFUNC_C _CDotNetGenDisposeArray(void * array, unsigned int typeId, size_t nDims, ...)
{
	size_t i;
	ssize_t totalLength = 1;
	va_list list;

	if (!*(void **)array)
		return;

	va_start(list, nDims);
	for (i = 0; i < nDims; ++i) {
		ssize_t * lenPtr = va_arg(list, ssize_t*);

		totalLength *= *lenPtr;
		*lenPtr = 0;
	}
	va_end(list);

	typeId &= CDOTNET_BASIC_TYPE_MASK;
	if (typeId == CDOTNET_STRING)
		while (--totalLength >= 0)
			CDotNetFreeMemory((*(char ***)array)[totalLength]);
	else if (typeId > CDOTNET_ENUM)
		while (--totalLength >= 0)
			CDotNetDiscardHandle((*(CDotNetHandle **)array)[totalLength]);

	CDotNetFreeMemory(*(void**)array);
	*(void**)array = 0;
}


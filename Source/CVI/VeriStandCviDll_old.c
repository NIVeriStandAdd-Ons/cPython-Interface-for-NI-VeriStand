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
#include "NationalInstruments.VeriStand.ClientAPI.h"
//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

/*static NationalInstruments_VeriStand_ClientAPI_Factory FactoryHandle;
static NationalInstruments_VeriStand_ClientAPI_IWorkspace2 WorkSpaceInst;
static NationalInstruments_VeriStand_ClientAPI_IProject  VsProjectHandle;
static NationalInstruments_VeriStand_Error VeriStandErrorHandle = 0;
static CDotNetHandle ExceptionHandle = 0;
static double newVal;
static int i = 0;*/

static NationalInstruments_VeriStand_ClientAPI_Factory			instance_handle;
static NationalInstruments_VeriStand_ClientAPI_IWorkspace2		VSworkspace2_Handle;
static NationalInstruments_VeriStand_ClientAPI_IProject			IProject_Handle;
static NationalInstruments_VeriStand_ClientAPI_IModel			IModel_Handle;
static NationalInstruments_VeriStand_ClientAPI_IChannelFault   	VSchannelfault_Handle;
static CDotNetHandle											exception_Handle;
static char														cBuffer[300];
static char  													*pcBuffer = cBuffer;		



//==============================================================================
// Static functions

//==============================================================================
// Global variables
/*char gatewayIP[] = "localhost";
char sineWavePath[] = "C:\\Users\\Public\\Documents\\National Instruments\\NI VeriStand 2011\\Projects\\Example\\Sinewave Delay.nivssdf";
double val;
int newValueLength;*/

int	 	VSHandle = 0;  
char 	*VSfilename = "D:\\Program Files (x86)\\National Instruments\\VeriStand 2011\\NI VeriStand";	//Win 7 Has to load as parameters
char	*cpGateway = "localhost";	   // "localhost" if running on local host or IP address of processor.
char	*cpName = "Administrator";	   // valid cws login ID
char	*cpPassword = "";			   // valid login password.


//==============================================================================
// Global functions

/*
int __stdcall InitPlatform (void)
{   

	//printf("Time[%f]", Timer());
    MessagePopup ("Inside InitPlatform", "1");
	static int                                  error = 0;
	char* names[] = { "Aliases/Delay_Random Output", "Aliases/Delay_Sinewave Output", "Aliases/SineWave" };
	int namesLength = 3;
	char name[] = "Aliases/Delay_Random Output";


	double * valuesRef = (double*)calloc (4, sizeof(double));
	double val;
	double newVal;
	int newValueLength;
	int i, j;
	unsigned int timeout = 60000;

	Initialize_NationalInstruments_VeriStand_ClientAPI();
	NationalInstruments_VeriStand_ClientAPI_Factory__Create(&FactoryHandle, &ExceptionHandle);
	NationalInstruments_VeriStand_ClientAPI_Factory_GetIWorkspace2_1(FactoryHandle, gatewayIP ,&WorkSpaceInst,&ExceptionHandle);
	NationalInstruments_VeriStand_ClientAPI_IWorkspace2_ConnectToSystem (WorkSpaceInst, sineWavePath, 0, timeout, &VeriStandErrorHandle,&ExceptionHandle);
	return 0;

}

int __stdcall DeinitPlatform (void)
{
	MessagePopup ("Inside DeinitPlatform", "2"); 
  	NationalInstruments_VeriStand_ClientAPI_IWorkspace2_DisconnectFromSystem(WorkSpaceInst, NULL, 1, &VeriStandErrorHandle, &ExceptionHandle);  
	Close_NationalInstruments_VeriStand_ClientAPI();
	i = 0; 
	return 0;
}

/*
int __stdcall DownloadProject (void)
{
	MessagePopup ("Inside DownloadProject", "3");  
	int newValueLength;
	char sineProjectPath[] =  "C:\\Users\\Public\\Documents\\National Instruments\\NI VeriStand 2011\\Projects\\Example\\Sinewave Delay.nivsproj";
	char** activeProjects[] =  { "", "", "" };
	NationalInstruments_VeriStand_ClientAPI_Factory_GetIProject_1(FactoryHandle,gatewayIP,sineProjectPath,"","", &VeriStandErrorHandle,&VsProjectHandle,&ExceptionHandle);
	NationalInstruments_VeriStand_ClientAPI_IProject_Set_Visible(VsProjectHandle,1,&ExceptionHandle);
	NationalInstruments_VeriStand_ClientAPI_Factory_GetActiveProjects_1(FactoryHandle,gatewayIP,&activeProjects,&newValueLength,&ExceptionHandle);
	NationalInstruments_VeriStand_ClientAPI_IProject_Connect_1(VsProjectHandle,1,&VeriStandErrorHandle,&ExceptionHandle);

	return 0;	
}



double __stdcall ReadValue (void)
{
	//i++;
	char name[] = "Aliases/Delay_Random Output";
	NationalInstruments_VeriStand_ClientAPI_IWorkspace2_GetSingleChannelValue(WorkSpaceInst,name,&newVal,&VeriStandErrorHandle,&ExceptionHandle);  
    //printf("Time[%f] - ", Timer());
	//fprintf(stderr, "Iteration: %d: %f \n",i, newVal);
	return newVal;
}
*/

/*****************************************************************************
  FUNCTION NAME          : CviVeristandOpen
  DESCRIPTION            : Creates New Veristand objects, obtains handle(s) to object(s). 
  PARAMETERS DESCRIPTION : 
  						 : 
						 : C:\Users\Public\Documents\National Instruments\NI VeriStand 2011\Examples\Stimulus Profile\Engine Demo\Engine Demo.nivssdf 
						 : 
						 : 
  						 : pcBuffer:  Returns name of call that failed.
  Return Value           : HRESULT:  0 = Success, Negative = Failure
******************************************************************************/
int CviVeristandOpen()
{

	int Hstatus = 0;
	char	cdescription[300];
	const char *pcdescription;
	static int                                  error = 0;

	pcdescription = cdescription;
	
	LaunchExecutableEx (VSfilename, LE_SHOWNORMAL, &VSHandle);
	//Delay (5.5);
	
//	Hstatus = Initialize_NationalInstruments_VeriStand ();
//	if (Hstatus != 0 ) { strcpy	(pcBuffer, "Initialize_VeriStand"); goto Error; }

//	Hstatus = Initialize_NationalInstruments_VeriStand_APIInterface ();
//	if (Hstatus != 0 ) { strcpy	(pcBuffer, "Initialize_APIInterface"); goto Error; }
		 
	Hstatus = Initialize_NationalInstruments_VeriStand_ClientAPI ();
	if (Hstatus != 0 ) { strcpy	(pcBuffer, "Initialize_ClientAPI"); goto Error; }

	Hstatus = NationalInstruments_VeriStand_ClientAPI_Factory__Create (&instance_handle, &exception_Handle);
	if (Hstatus != 0 ) { strcpy	(pcBuffer, "ClientAPI_Factory_Create"); goto Error; }
	
	Delay (1.5);
	
	//Test of VS startup
	
	for (int i = 1; i <= 50; i++) 
	{

		Hstatus = NationalInstruments_VeriStand_ClientAPI_Factory_GetIWorkspace2 (instance_handle,
															&VSworkspace2_Handle,&exception_Handle);
		if (Hstatus == 0) break;
		Delay (1);
	
	}
	
	
	Hstatus = NationalInstruments_VeriStand_ClientAPI_Factory_GetIWorkspace2 (instance_handle,
															&VSworkspace2_Handle,&exception_Handle);
	if (Hstatus != 0 ) { strcpy	(pcBuffer, "ClientAPI_Factory_GetIWorkspace2"); goto Error; }
	
	Hstatus = NationalInstruments_VeriStand_ClientAPI_Factory_GetIChannelFault (instance_handle,
															&VSchannelfault_Handle,&exception_Handle);
	if (Hstatus != 0 ) { strcpy	(pcBuffer, "ClientAPI_Factory_GetIChannelFault"); goto Error; }

	return Hstatus;
	
Error:
       // Handle error
        sprintf(cdescription, "Error (%d): %s\n", error, CDotNetGetErrorDescription(error));
		printf(cdescription);
		strcat(pcBuffer,cdescription);
        if(Hstatus <0)
	{
		if (exception_Handle)
	       	 {
			char * exceptionMessage = 0;
			char * source = 0;
			char * stack_trace = 0;
	            		CDotNetGetExceptionInfo(exception_Handle, 0, &exceptionMessage, &source, &stack_trace, 0, 0);
			sprintf(cdescription,"Exception: %s\n", exceptionMessage); 
			printf(cdescription);
			if (POPUPDEBUGDLL) MessagePopup ("CVI DLL",cdescription);			
			fprintf(stderr, "Source: %s\n", source);
			fprintf(stderr, "Stack Trace: %s\n\n", stack_trace);              
	            		CDotNetFreeMemory(exceptionMessage);
	       	 }
	}	

return Hstatus;
}

/*****************************************************************************
  FUNCTION NAME          : VeriStand Exit.
  DESCRIPTION            : Exit the VeriStand Application.
  PARAMETERS DESCRIPTION : pcBuffer - ptr to char string containing error description. 
  Return Value           : HRESULT: 0 = Success, Non-Zero = Failure.
******************************************************************************/ 
int CviVeristandExit()
{

int IStatus = 0;

 		/*IStatus =Close_NationalInstruments_VeriStand ();
		if (IStatus != 0 ) { strcpy	(pcBuffer, "Close_VeriStand"); return IStatus; }
		
		IStatus =Close_NationalInstruments_VeriStand_APIInterface ();
		if (IStatus != 0 ) { strcpy	(pcBuffer, "Close_APIInterface"); return IStatus; }*/
		 
		IStatus = Close_NationalInstruments_VeriStand_ClientAPI ();
		if (IStatus != 0 ) { strcpy	(pcBuffer, "Close_ClientAPI"); return IStatus; }

		CDotNetDiscardHandle(instance_handle);
 		CDotNetDiscardHandle(VSworkspace2_Handle);
		CDotNetDiscardHandle(IProject_Handle);
		CDotNetDiscardHandle(IModel_Handle);
		CDotNetDiscardHandle(VSchannelfault_Handle);
		CDotNetDiscardHandle(exception_Handle);
		
		TerminateExecutable (VSHandle);
		RetireExecutableHandle (VSHandle);

return IStatus;
}

/*****************************************************************************
  FUNCTION NAME          : CviVeristand_Project
  DESCRIPTION            : Connect to model or project, obtains handle to the model. 
  PARAMETERS DESCRIPTION : pcBuffer - ptr to char string containing error description.
  Return Value           : HRESULT:  0 = Success, Negative = Failure
******************************************************************************/

long CviVeristand_Project(char *proj_file_path, long lDeploy,
							unsigned int uiTimeout)
{
NationalInstruments_VeriStand_Error					NIVS_Error = 0;

long 	xlStatus = 0;

		xlStatus = NationalInstruments_VeriStand_ClientAPI_Factory_GetIProject (instance_handle, cpGateway, proj_file_path, 
							cpName, cpPassword, &IProject_Handle, exception_Handle);

		if (xlStatus != 0) {  // Expand error
        sprintf(pcBuffer, "%s  Error (%d): %s\n","ClientAPI_GetIProject", xlStatus, CDotNetGetErrorDescription(xlStatus));
		}

		/*xlStatus = NationalInstruments_VeriStand_ClientAPI_Factory_GetIModel (instance_handle, model_name, &IModel_Handle, exception_Handle);

		if (xlStatus != 0) {  // Expand error
        sprintf(pcBuffer, "%s  Error (%d): %s\n","ClientAPI_GetIModel", xlStatus, CDotNetGetErrorDescription(xlStatus));
		}																												
		*/

return xlStatus;
}

/*****************************************************************************
  FUNCTION NAME          : CviVeristand_Run
  DESCRIPTION            : Run the project or model.
  						 :  
  PARAMETERS DESCRIPTION : pcBuffer - ptr to char string containing error description.
  Return Value           : HRESULT:  0 = Success, Negative = Failure
******************************************************************************/  

long CviVeristand_Run()
{
NationalInstruments_VeriStand_Error					NIVS_Error = 0;

long 	xlStatus = 0;

		xlStatus = NationalInstruments_VeriStand_ClientAPI_IProject_Run (IProject_Handle, &NIVS_Error, exception_Handle);

		if (xlStatus != 0) {  // Expand error
        sprintf(pcBuffer, "%s  Error (%d): %s\n","IProject_Run", xlStatus, CDotNetGetErrorDescription(xlStatus));
		}
		
return xlStatus;
}

/*****************************************************************************
  FUNCTION NAME          : CviVeristand_Close
  DESCRIPTION            : Close the model
  						 :  
  PARAMETERS DESCRIPTION : pcBuffer - ptr to char string containing error description.
  Return Value           : HRESULT:  0 = Success, Negative = Failure
******************************************************************************/  

long CviVeristand_Close()
{
NationalInstruments_VeriStand_Error					NIVS_Error = 0;

long 	xlStatus = 0;

		xlStatus = NationalInstruments_VeriStand_ClientAPI_IProject_Close (IProject_Handle, &NIVS_Error, exception_Handle);
		
		if (xlStatus != 0) {  // Expand error
        sprintf(pcBuffer, "%s  Error (%d): %s\n","IProject_Close", xlStatus, CDotNetGetErrorDescription(xlStatus));
		}

return xlStatus;
}

/*****************************************************************************
  FUNCTION NAME          : CviVeristand_Connect
  DESCRIPTION            : Connect the model activity. 
  PARAMETERS DESCRIPTION : pcBuffer - ptr to char string containing error description.
  Return Value           : HRESULT:  0 = Success, Negative = Failure
******************************************************************************/  

long CviVeristand_Connect()
{
NationalInstruments_VeriStand_Error					NIVS_Error = 0;

long 	xlStatus = 0;

		xlStatus = NationalInstruments_VeriStand_ClientAPI_IProject_Connect (IProject_Handle, &NIVS_Error, exception_Handle);
		
		if (xlStatus != 0) {  // Expand error
        sprintf(pcBuffer, "%s  Error (%d): %s\n","IProject_Connect", xlStatus, CDotNetGetErrorDescription(xlStatus));
		}

return xlStatus;
}

/*****************************************************************************
  FUNCTION NAME          : CviVeristand_DisConnect
  DESCRIPTION            : DisConnect the model activity. 
  PARAMETERS DESCRIPTION : pcBuffer - ptr to char string containing error description.
  Return Value           : HRESULT:  0 = Success, Negative = Failure
******************************************************************************/  

long CviVeristand_DisConnect()
{
NationalInstruments_VeriStand_Error					NIVS_Error = 0;

long 	xlStatus = 0;

		xlStatus = NationalInstruments_VeriStand_ClientAPI_IProject_Disconnect (IProject_Handle, &NIVS_Error, exception_Handle);
		
		if (xlStatus != 0) {  // Expand error
        sprintf(pcBuffer, "%s  Error (%d): %s\n","IProject_DisConnect", xlStatus, CDotNetGetErrorDescription(xlStatus));
		}

return xlStatus;
}

/*****************************************************************************
  FUNCTION NAME          : CviVeristand_Deploy
  DESCRIPTION            : Deploy the model activity. 
  PARAMETERS DESCRIPTION : pcBuffer - ptr to char string containing error description.
  Return Value           : HRESULT:  0 = Success, Negative = Failure
******************************************************************************/  

long CviVeristand_Deploy()
{
NationalInstruments_VeriStand_Error					NIVS_Error = 0;

long 	xlStatus = 0;

		xlStatus = NationalInstruments_VeriStand_ClientAPI_IProject_Deploy (IProject_Handle, &NIVS_Error, exception_Handle);
		
		if (xlStatus != 0) {  // Expand error
        sprintf(pcBuffer, "%s  Error (%d): %s\n","IProject_Deploy", xlStatus, CDotNetGetErrorDescription(xlStatus));
		}

return xlStatus;
}

/*****************************************************************************
  FUNCTION NAME          : CviVeristand_UnDeploy
  DESCRIPTION            : UnDeploy the model activity. 
  PARAMETERS DESCRIPTION : pcBuffer - ptr to char string containing error description.
  Return Value           : HRESULT:  0 = Success, Negative = Failure
******************************************************************************/  

long CviVeristand_UnDeploy()
{
NationalInstruments_VeriStand_Error					NIVS_Error = 0;

long 	xlStatus = 0;

		xlStatus = NationalInstruments_VeriStand_ClientAPI_IProject_Undeploy (IProject_Handle, &NIVS_Error, exception_Handle);
		
		if (xlStatus != 0) {  // Expand error
        sprintf(pcBuffer, "%s  Error (%d): %s\n","IProject_UnDeploy", xlStatus, CDotNetGetErrorDescription(xlStatus));
		}

return xlStatus;
}

/*****************************************************************************
  FUNCTION NAME          : CviVeristand_GetChannelValue
  DESCRIPTION            : Get a Single Channel Value. 
  PARAMETERS DESCRIPTION : cpChanlName - ptr to char string containg a channel name.
  						 : dValue - double varable containing value returned.
  Return Value           : HRESULT:  0 = Success, Negative = Failure
******************************************************************************/  

long CviVeristand_GetChannelValue(char *cpChanlName, double *dValue)
{
NationalInstruments_VeriStand_Error					NIVS_Error = 0;
double	dNewValue = 0;
long 	xlStatus = 0;

		xlStatus = NationalInstruments_VeriStand_ClientAPI_IWorkspace2_GetSingleChannelValue (VSworkspace2_Handle,
							cpChanlName, &dNewValue, &NIVS_Error, exception_Handle);
		
		*dValue = dNewValue;
return xlStatus;
}

/*long CviVeristand_GetChannelValue(char *cpChanlName, double dValue)
{
NationalInstruments_VeriStand_Error					NIVS_Error = 0;
double	dNewValue = 0;
long 	xlStatus = 0;

		xlStatus = NationalInstruments_VeriStand_ClientAPI_IWorkspace2_GetSingleChannelValue (VSworkspace2_Handle,
							cpChanlName, &dNewValue, &NIVS_Error, exception_Handle);
		
		dValue = dNewValue;
return xlStatus;
}*/



/*****************************************************************************
  FUNCTION NAME          : CviVeristand_GetChannelValueMultiple
  DESCRIPTION            : Get Multiple Channel Values. 
  PARAMETERS DESCRIPTION : VSChannelList - A ptr to a list or array of channel names.
  						 : iNamesLength - integer length of the list of names
						 : dValuesList - A list or array of channel values
						 : iValuesLength - integer length of the list of values
  Return Value           : HRESULT:  0 = Success, Negative = Failure
******************************************************************************/  

long CviVeristand_GetChannelValueMultiple(ChnlNames_t VGChannelList, double VdValues[], int iLength)
{
NationalInstruments_VeriStand_Error					NIVS_Error = 0;

char	**ppVGChannelList = 0;
double	**ppdValues = 0;
int		piValuesLength = 0;
int		j,k;
long 	xlStatus = 0;

			/*Allocate storage for VGChannelList */
			ppVGChannelList = malloc(iLength * sizeof(char *));
			for(j = 0; j<iLength; j++) {
				ppVGChannelList[j] = malloc(VSNSIZE * sizeof(char));
				strcpy (ppVGChannelList[j], VGChannelList.VName[j] );
			} // end 'for(j = 0...
			
			/*Allocate storage for returned channel values */
			ppdValues = malloc(sizeof(double *));
				ppdValues[0] = (double *) malloc(iLength * sizeof(double));
			
		xlStatus = NationalInstruments_VeriStand_ClientAPI_IWorkspace2_GetMultipleChannelValues (VSworkspace2_Handle,
							ppVGChannelList, iLength, ppdValues, &piValuesLength, &NIVS_Error, exception_Handle);

		for (k=0; k<piValuesLength; k++) {
			if (ppdValues[0][k] != NAN) { VdValues[k] = ppdValues[0][k]; }
			else VdValues[k] = 0;
		}
		
		free(ppVGChannelList);
		free(ppdValues);
		
return xlStatus;
}

/*****************************************************************************
  FUNCTION NAME          : CviVeristand_SetChannelValue
  DESCRIPTION            : Set a Single Channel Value. 
  PARAMETERS DESCRIPTION : cpChanlName - ptr to char string containg a channel name.
  						 : dValue - double varable containing new value.
  Return Value           : HRESULT:  0 = Success, Negative = Failure
******************************************************************************/  

long CviVeristand_SetChannelValue(char *cpChanlName, double dValue)
{
NationalInstruments_VeriStand_Error					NIVS_Error = 0;

long 	xlStatus = 0;

		xlStatus = NationalInstruments_VeriStand_ClientAPI_IWorkspace2_SetSingleChannelValue (VSworkspace2_Handle,
							cpChanlName, dValue, &NIVS_Error, exception_Handle);
		
return xlStatus;
}

/*****************************************************************************
  FUNCTION NAME          : CviVeristand_SetChannelValueMultiple
  DESCRIPTION            : Set a Multiple Channel Values. 
  PARAMETERS DESCRIPTION : VSChannelList - A ptr to a list or array of channel names.
 						 : dValuesList - A list or array of channel values
						 : iLength - integer length of the list of values and names, must be the same length.
  Return Value           : HRESULT:  0 = Success, Negative = Failure
******************************************************************************/  

long CviVeristand_SetChannelValueMultiple(ChnlNames_t VSChannelList, double VdValues[], int iLength)
{
NationalInstruments_VeriStand_Error					NIVS_Error = 0;

char	**ppVSChannelList = 0;
double	*pdValues = 0;
int		piValuesLength = 0;
int		j,k;
long 	xlStatus = 0;

			/*Allocate storage for VGChannelList */
			ppVSChannelList = malloc(iLength * sizeof(char *));
			for(j = 0; j<iLength; j++) {
				ppVSChannelList[j] = malloc(VSNSIZE * sizeof(char));
				strcpy (ppVSChannelList[j], VSChannelList.VName[j] );
			} // end 'for(j = 0...

			/*Allocate storage for returned channel values */
			pdValues = malloc(iLength * sizeof(double));

			for(k = 0; k<iLength; k++) {
				pdValues[k] = VdValues[k];
			} // end 'for(k = 0...

		xlStatus = NationalInstruments_VeriStand_ClientAPI_IWorkspace2_SetMultipleChannelValues (VSworkspace2_Handle,
							ppVSChannelList, iLength, pdValues, iLength, &NIVS_Error, exception_Handle);
		
		free(ppVSChannelList);
		free(pdValues);
		
return xlStatus;
}

//==============================================================================
// DLL main entry-point functions

int __stdcall DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            if (InitCVIRTE (hinstDLL, 0, 0) == 0)
                return 0;     /* out of memory */
            break;
        case DLL_PROCESS_DETACH:
            if (!CVIRTEHasBeenDetached ())
                CloseCVIRTE (); 
            break;
    }
     
	/* Return 1 to indicate successful initialization */
    return 1;
}

int __stdcall DllEntryPoint (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    /* Included for compatibility with Borland */

    return DllMain (hinstDLL, fdwReason, lpvReserved);
}

// End of file.

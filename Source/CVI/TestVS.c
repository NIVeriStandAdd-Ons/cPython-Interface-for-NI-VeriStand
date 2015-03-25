/*---------------------------------------------------------------------------*/
/*                                                                           */
/* FILE:    TestVS.c                                                   */
/*                                                                           */
/* PURPOSE: TestCall to VS dll.                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Include files                                                             */
/*---------------------------------------------------------------------------*/
#include <cvirte.h>
#include <userint.h>
#include <utility.h>        
#include <ansi_c.h>    
#include <analysis.h>
#include "TestVS.h"
#include "VeriStandCviDll.h"

/*---------------------------------------------------------------------------*/
/* Defines                                                                   */
/*---------------------------------------------------------------------------*/
#define TRUE   1
#define FALSE  0
#define  POPUPDEBUG		0  /* 1 show popup, 0 no popup */           

/*---------------------------------------------------------------------------*/
/* Internal function prototypes                                              */
/*---------------------------------------------------------------------------*/

/*****************************************************************************
*									GLOBAL VARIABLES						 *
******************************************************************************/



/*---------------------------------------------------------------------------*/
/* This is the application's entry-point.  Notice that all event-processing  */
/* is handled here, with no additional UI callback functions.                */
/*---------------------------------------------------------------------------*/
int main (int argc, char *argv[])
{
    int    done   = FALSE;
    int    hpanel;
    int    eventPanel;
    int    eventCtrl;
    double cycles;
    double waveform[100];
	int	   result = 0;
	
	int	SrvrInitStatus;
	char *prj = "C:\\Users\\Public\\Documents\\National Instruments\\NI VeriStand 2011\\Projects\\Example\\Sinewave Delay.nivsproj";
	long	lDeploy = 1, lLaunch = 1;
	unsigned int uiTimeout = 10000;
    
	char 	cChanlName[VSNSIZE],		*pcChanlName = cChanlName;
	double	dValue = 0;
	int 	error = 0;
	
	
    if (InitCVIRTE (0, argv, 0) == 0) 
        return -1; 
    if ((hpanel = LoadPanel (0, "TestVS.uir", PNL)) <= 0)
        return -1;
    
    /* Display the panel and then loop to wait for events */
    DisplayPanel (hpanel);
    while (done == FALSE)
        {
        int _tmp2;
        
        /* Wait for a commit event to occur on one of our controls */
        GetUserEvent (1, &eventPanel, &eventCtrl);

        /* We received an event, eventPanel and eventCtrl contain the panel  */
        /* and control on which the event occurred */
		
        switch (eventCtrl)
            {
            case PNL_VSSTART:
                
				if (POPUPDEBUG) MessagePopup ("Using a CVI DLL", "Ready to call CviVeristandOpen");
				SrvrInitStatus = LaunchVeriStand();
			
				SrvrInitStatus = OpenProject(prj);
				
				/*if (POPUPDEBUG) MessagePopup ("Using a CVI DLL", "Ready to call CviVeristand_Project");  
				SrvrInitStatus = CviVeristand_Project(prj, lDeploy, uiTimeout);
				Delay (5.0);
				
				if (POPUPDEBUG) MessagePopup ("Using a CVI DLL", "Ready to call CviVeristand_Run");  
				SrvrInitStatus = CviVeristand_Run();*/
    			
                break;

			case PNL_VSCLOSE:
                
				/*if (POPUPDEBUG) MessagePopup ("Using a CVI DLL", "Ready to call Close");
				CviVeristand_Close();
				Delay (5);
				CviVeristandExit();*/
            
				break;
				
			case PNL_VSREAD:
                
				/*strcpy (pcChanlName,"Aliases/SineWave");
				error = CviVeristand_GetChannelValue(pcChanlName,&dValue);
				_tmp2 = SetCtrlVal (hpanel, PNL_CHANNEL_VALUE, dValue);*/
				            
				break;
				
			case PNL_QUIT:
                done = TRUE;
            
				break;
            }
        }

    /* Free resources and return */
    DiscardPanel (hpanel);
    CloseCVIRTE ();
    return 0;
}


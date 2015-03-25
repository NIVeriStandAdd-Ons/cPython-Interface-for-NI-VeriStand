//==============================================================================
//
// Title:		CUnitTests
// Purpose:		Unit Test for CVI dll.
//
// Created on:	11/8/2012 at 4:10:48 PM by Jiri Keprt.
// Copyright:	NI. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

//#include <cvirte.h>
//#include <userint.h>
//#include <utility.h>        
#include <ansi_c.h>    
//#include <analysis.h>
#include "CUError.h"
//#include "CUError.c"
#include "CUnit.h"
#include "MyMem.h"
//#include "MyMem.c"
#include "TestDB.h"
//#include "TestDB.c"
#include "TestRun.h"
//#include "TestRun.c"
#include "Util.h"
//#include "Util.c"
#include "Automated.h"
#include "Basic.h"
//#include "Automated.c"
#include "VeriStandCviDll.h"
#include "IntegrationTest.h"
//#include "IntegrationTest.c"

//#include "d:\NI Projects\EXAM\EXAM CVI dotnet\CVI\CUnit\Headers\Basic.h"

//==============================================================================
// Constants

#define MAXERRORMSGLENGTH 500

//==============================================================================
// Types

//==============================================================================
// Static global variables

/* Pointer to the file used by the tests. */
static FILE* temp_file = NULL;
int	VSStatus;

//==============================================================================
// Static functions

static void testFail(void)
{
        CU_ASSERT(0);
}

//Suite Definitions
static CU_TestInfo tests_GenList[] = {
  { "Should Fail", testFail },
    CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites[] = {
  { "Generic List Suites",  NULL, NULL, tests_GenList },
    CU_SUITE_INFO_NULL,
};

void AddTests(void)
{
  assert(NULL != CU_get_registry());
  assert(!CU_is_test_running());

    /* Register suites. */
    if (CU_register_suites(suites) != CUE_SUCCESS) {
        fprintf(stderr, "suite registration failed - %s\n",
            CU_get_error_msg());
        exit(EXIT_FAILURE);
    }
}


//==============================================================================
// Global variables

CU_pSuite pSuite = NULL;

//==============================================================================
// Global functions

int AddIntegrationTests (CU_pSuite pSuiteT)   
{   
   		if (     (NULL == CU_add_test(pSuiteT, "RunProjectShouldRunProject", RunProjectShouldRunProject)) 
			  || (NULL == CU_add_test(pSuiteT, "CloseShouldCloseOpenedProject", CloseShouldCloseOpenedProject)) 
			  || (NULL == CU_add_test(pSuiteT, "CloseOpenWorkspaceShouldCloseOpenRunningProject", CloseOpenWorkspaceShouldCloseOpenRunningProject)) 
  			  || (NULL == CU_add_test(pSuiteT, "SetGetChannelValueShouldSetAndGetChannelValue", SetGetChannelValueShouldSetAndGetChannelValue))
			  || (NULL == CU_add_test(pSuiteT, "SetGetParamValueShouldSetAndGetParamValue", SetGetParamValueShouldSetAndGetParamValue))
			  || (NULL == CU_add_test(pSuiteT, "SetGetParamValueSynchShouldSetAndGetParamValueSynch", SetGetParamValueSynchShouldSetAndGetParamValueSynch))
			  || (NULL == CU_add_test(pSuiteT, "SetMultipleChannelsValueShouldSetMultipleChannelsValue", SetMultipleChannelsValueShouldSetMultipleChannelsValue))
			  || (NULL == CU_add_test(pSuiteT, "SetMultipleChannelsValueSynchShouldSetMultipleChannelsValueSynch", SetMultipleChannelsValueSynchShouldSetMultipleChannelsValueSynch))
			  || (NULL == CU_add_test(pSuiteT, "SetGetChannelValueSynchShouldSetAndGetChannelValueSynch", SetGetChannelValueSynchShouldSetAndGetChannelValueSynch))
			  || (NULL == CU_add_test(pSuiteT, "GetActiveProjectShouldReturnProjects", GetActiveProjectShouldReturnProjects))
			  || (NULL == CU_add_test(pSuiteT, "UnDeployShouldUnDeployProject", UnDeployShouldUnDeployProject))
			  || (NULL == CU_add_test(pSuiteT, "StartAndStopLoggingShouldStartAndStopLogging", StartAndStopLoggingShouldStartAndStopLogging))
			  || (NULL == CU_add_test(pSuiteT, "GetAvailableChannelsToReadCountShouldReturnCount", GetAvailableChannelsToReadCountShouldReturnCount))
			  || (NULL == CU_add_test(pSuiteT, "GetAvailableChannelsToWriteCountShouldReturnCount", GetAvailableChannelsToWriteCountShouldReturnCount))
			  || (NULL == CU_add_test(pSuiteT, "GetAvailableChannelToReadShouldReturnChannel", GetAvailableChannelToReadShouldReturnChannel))
			  || (NULL == CU_add_test(pSuiteT, "GetAvailableChannelToWriteShouldReturnChannel", GetAvailableChannelToWriteShouldReturnChannel))
			  || (NULL == CU_add_test(pSuiteT, "DisconnectAndConnectShouldDisconnectAndReconnectToProject", DisconnectAndConnectShouldDisconnectAndReconnectToProject))
			  || (NULL == CU_add_test(pSuiteT, "StartAndStopLogging2ShouldStartAndStopLogging2", StartAndStopLogging2ShouldStartAndStopLogging2))
			  || (NULL == CU_add_test(pSuiteT, "GetTDMSShouldReturnTDMSProperties", GetTDMSShouldReturnTDMSProperties))
			  || (NULL == CU_add_test(pSuiteT, "TDMSReadColumnShouldReturnTDMSColumn", TDMSReadColumnShouldReturnTDMSColumn))
			  || (NULL == CU_add_test(pSuiteT, "TDMSReadTimeColumnShouldReturnTDMSTimeColumn", TDMSReadTimeColumnShouldReturnTDMSTimeColumn))
			  
			)
   		{
      		CU_cleanup_registry();
      		return CU_get_error(); 
   		}
		
		else 
		{ return 0;}
		
}


/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_IntegrationTestSuite(void)  
{  
    return LaunchVeriStand();
	return 0;
}	 

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_IntegrationTestSuite(void)
{
   return CloseVeriStand();
	
   return 0;
}


int main (int argc, char *argv[])
{
	if (argc < 2 || argc > 3)
	{	
		CU_set_output_filename("C:\\NI Projects\\EXAM\\EXAM CVI dotnet\\CVI\\UnitTests\\Results");
	    
   		/* initialize the CUnit test registry */
   		if (CUE_SUCCESS != CU_initialize_registry())
      		return CU_get_error();

   		/* add a suite to the registry */
   		pSuite = CU_add_suite("IntegrationTestSuite", init_IntegrationTestSuite, clean_IntegrationTestSuite);
   		if (NULL == pSuite) {
      		CU_cleanup_registry();
      		return CU_get_error();
   		}

   		/* add the tests to the suite */
   		if (AddIntegrationTests(pSuite)!= 0) return CU_get_error();
		//if (AddIntegrationTests(1)!= 0) return CU_get_error(); 
		//DOLADIT Return!

   		/* Run all tests using the CUnit Basic interface */
   		CU_basic_set_mode(CU_BRM_VERBOSE);
   		CU_basic_run_tests();
		printf("\n");
   		CU_basic_show_failures(CU_get_failure_list());
   		printf("\n\n");
		
		/* Run all tests using the automated interface */
   		/*CU_automated_run_tests();
   		CU_list_tests_to_file();*/
		
		/* Run all tests using the console interface */
	    //CU_console_run_tests(); Duplicates declarations
		
   		CU_cleanup_registry();
		printf("Press Enter to exit.");
		getchar();
		
   		return CU_get_error();
		
	}
	return 0;
}


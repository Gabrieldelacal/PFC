/* Include files */

#include "Qmoddef_sfun.h"
#include "c1_Qmoddef.h"
#include "c2_Qmoddef.h"
#include "c3_Qmoddef.h"
#include "c4_Qmoddef.h"
#include "c5_Qmoddef.h"
#include "c6_Qmoddef.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _QmoddefMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Qmoddef_initializer(void)
{
}

void Qmoddef_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Qmoddef_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Qmoddef_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Qmoddef_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Qmoddef_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Qmoddef_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Qmoddef_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_Qmoddef_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Qmoddef_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3146248211U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1682293626U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3950031241U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3174654664U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(488142323U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2962988838U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1154466790U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1433145152U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Qmoddef_get_check_sum(mxArray *plhs[]);
          sf_c1_Qmoddef_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Qmoddef_get_check_sum(mxArray *plhs[]);
          sf_c2_Qmoddef_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Qmoddef_get_check_sum(mxArray *plhs[]);
          sf_c3_Qmoddef_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Qmoddef_get_check_sum(mxArray *plhs[]);
          sf_c4_Qmoddef_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Qmoddef_get_check_sum(mxArray *plhs[]);
          sf_c5_Qmoddef_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_Qmoddef_get_check_sum(mxArray *plhs[]);
          sf_c6_Qmoddef_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2489875624U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2228534703U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4090430839U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2859128611U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Qmoddef_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "zTxPu3jxa2z7mjvyjHdTKC") == 0) {
          extern mxArray *sf_c1_Qmoddef_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Qmoddef_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "IjNVcN8CB5Ul7Mmo8pySk") == 0) {
          extern mxArray *sf_c2_Qmoddef_get_autoinheritance_info(void);
          plhs[0] = sf_c2_Qmoddef_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "ZrD7nG5KFaGz8Hab4NX6sH") == 0) {
          extern mxArray *sf_c3_Qmoddef_get_autoinheritance_info(void);
          plhs[0] = sf_c3_Qmoddef_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "RF4dl8MxuTG0AVE78lBQi") == 0) {
          extern mxArray *sf_c4_Qmoddef_get_autoinheritance_info(void);
          plhs[0] = sf_c4_Qmoddef_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "OdV7GO3nAVWJ8yxmu60LRC") == 0) {
          extern mxArray *sf_c5_Qmoddef_get_autoinheritance_info(void);
          plhs[0] = sf_c5_Qmoddef_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "vIf5jJvAuHz96QsFgktYAB") == 0) {
          extern mxArray *sf_c6_Qmoddef_get_autoinheritance_info(void);
          plhs[0] = sf_c6_Qmoddef_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Qmoddef_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_Qmoddef_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Qmoddef_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_Qmoddef_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Qmoddef_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_Qmoddef_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Qmoddef_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_Qmoddef_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Qmoddef_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_Qmoddef_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Qmoddef_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_Qmoddef_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_Qmoddef_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void Qmoddef_debug_initialize(void)
{
  _QmoddefMachineNumber_ = sf_debug_initialize_machine("Qmoddef","sfun",0,6,0,0,
    0);
  sf_debug_set_machine_event_thresholds(_QmoddefMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_QmoddefMachineNumber_,0);
}

void Qmoddef_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Qmoddef_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("Qmoddef",
      "Qmoddef");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Qmoddef_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

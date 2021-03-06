#ifndef __c6_Qmod3_h__
#define __c6_Qmod3_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  int32_T c6_sfEvent;
  boolean_T c6_isStable;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_Qmod3;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
} SFc6_Qmod3InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_Qmod3_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_Qmod3_get_check_sum(mxArray *plhs[]);
extern void c6_Qmod3_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

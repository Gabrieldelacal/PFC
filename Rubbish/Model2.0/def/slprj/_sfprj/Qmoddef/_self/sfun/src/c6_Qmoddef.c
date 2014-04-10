/* Include files */

#include "blascompat32.h"
#include "Qmoddef_sfun.h"
#include "c6_Qmoddef.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Qmoddef_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[7] = { "nargin", "nargout", "w", "l",
  "b", "k", "Tau" };

/* Function Declarations */
static void initialize_c6_Qmoddef(SFc6_QmoddefInstanceStruct *chartInstance);
static void initialize_params_c6_Qmoddef(SFc6_QmoddefInstanceStruct
  *chartInstance);
static void enable_c6_Qmoddef(SFc6_QmoddefInstanceStruct *chartInstance);
static void disable_c6_Qmoddef(SFc6_QmoddefInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_Qmoddef(SFc6_QmoddefInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_Qmoddef(SFc6_QmoddefInstanceStruct
  *chartInstance);
static void set_sim_state_c6_Qmoddef(SFc6_QmoddefInstanceStruct *chartInstance,
  const mxArray *c6_st);
static void finalize_c6_Qmoddef(SFc6_QmoddefInstanceStruct *chartInstance);
static void sf_c6_Qmoddef(SFc6_QmoddefInstanceStruct *chartInstance);
static void initSimStructsc6_Qmoddef(SFc6_QmoddefInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_QmoddefInstanceStruct *chartInstance, const
  mxArray *c6_Tau, const char_T *c6_identifier, real_T c6_y[3]);
static void c6_b_emlrt_marshallIn(SFc6_QmoddefInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[3]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_c_emlrt_marshallIn(SFc6_QmoddefInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static real_T c6_mpower(SFc6_QmoddefInstanceStruct *chartInstance, real_T c6_a);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_d_emlrt_marshallIn(SFc6_QmoddefInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_e_emlrt_marshallIn(SFc6_QmoddefInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_Qmoddef, const char_T *c6_identifier);
static uint8_T c6_f_emlrt_marshallIn(SFc6_QmoddefInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_QmoddefInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_Qmoddef(SFc6_QmoddefInstanceStruct *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_Qmoddef = 0U;
}

static void initialize_params_c6_Qmoddef(SFc6_QmoddefInstanceStruct
  *chartInstance)
{
}

static void enable_c6_Qmoddef(SFc6_QmoddefInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_Qmoddef(SFc6_QmoddefInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_Qmoddef(SFc6_QmoddefInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c6_Qmoddef(SFc6_QmoddefInstanceStruct
  *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  real_T c6_u[3];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T (*c6_Tau)[3];
  c6_Tau = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2), FALSE);
  for (c6_i0 = 0; c6_i0 < 3; c6_i0++) {
    c6_u[c6_i0] = (*c6_Tau)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_Qmoddef;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_Qmoddef(SFc6_QmoddefInstanceStruct *chartInstance,
  const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[3];
  int32_T c6_i1;
  real_T (*c6_Tau)[3];
  c6_Tau = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)), "Tau",
                      c6_dv0);
  for (c6_i1 = 0; c6_i1 < 3; c6_i1++) {
    (*c6_Tau)[c6_i1] = c6_dv0[c6_i1];
  }

  chartInstance->c6_is_active_c6_Qmoddef = c6_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 1)), "is_active_c6_Qmoddef");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_Qmoddef(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_Qmoddef(SFc6_QmoddefInstanceStruct *chartInstance)
{
}

static void sf_c6_Qmoddef(SFc6_QmoddefInstanceStruct *chartInstance)
{
  int32_T c6_i2;
  int32_T c6_i3;
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  real_T c6_c_hoistedGlobal;
  int32_T c6_i4;
  real_T c6_w[4];
  real_T c6_l;
  real_T c6_b;
  real_T c6_k;
  uint32_T c6_debug_family_var_map[7];
  real_T c6_nargin = 4.0;
  real_T c6_nargout = 1.0;
  real_T c6_Tau[3];
  real_T c6_a;
  real_T c6_b_b;
  real_T c6_y;
  real_T c6_b_a;
  real_T c6_c_b;
  real_T c6_b_y;
  real_T c6_c_a;
  real_T c6_d_b;
  real_T c6_c_y;
  real_T c6_d_a;
  real_T c6_e_b;
  real_T c6_d_y;
  real_T c6_e_a;
  real_T c6_f_b;
  real_T c6_e_y;
  int32_T c6_i5;
  real_T *c6_b_l;
  real_T *c6_g_b;
  real_T *c6_b_k;
  real_T (*c6_b_Tau)[3];
  real_T (*c6_b_w)[4];
  c6_b_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c6_g_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_b_l = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_b_Tau = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_b_w = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i2 = 0; c6_i2 < 4; c6_i2++) {
    _SFD_DATA_RANGE_CHECK((*c6_b_w)[c6_i2], 0U);
  }

  for (c6_i3 = 0; c6_i3 < 3; c6_i3++) {
    _SFD_DATA_RANGE_CHECK((*c6_b_Tau)[c6_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c6_b_l, 2U);
  _SFD_DATA_RANGE_CHECK(*c6_g_b, 3U);
  _SFD_DATA_RANGE_CHECK(*c6_b_k, 4U);
  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  c6_hoistedGlobal = *c6_b_l;
  c6_b_hoistedGlobal = *c6_g_b;
  c6_c_hoistedGlobal = *c6_b_k;
  for (c6_i4 = 0; c6_i4 < 4; c6_i4++) {
    c6_w[c6_i4] = (*c6_b_w)[c6_i4];
  }

  c6_l = c6_hoistedGlobal;
  c6_b = c6_b_hoistedGlobal;
  c6_k = c6_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c6_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargin, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargout, 1U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c6_w, 2U, c6_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_l, 3U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_b, 4U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_k, 5U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c6_Tau, 6U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_a = c6_l;
  c6_b_b = c6_k;
  c6_y = c6_a * c6_b_b;
  c6_b_a = c6_y;
  c6_c_b = c6_mpower(chartInstance, c6_w[3]) - c6_mpower(chartInstance, c6_w[1]);
  c6_b_y = c6_b_a * c6_c_b;
  c6_c_a = c6_l;
  c6_d_b = c6_k;
  c6_c_y = c6_c_a * c6_d_b;
  c6_d_a = c6_c_y;
  c6_e_b = c6_mpower(chartInstance, c6_w[2]) - c6_mpower(chartInstance, c6_w[0]);
  c6_d_y = c6_d_a * c6_e_b;
  c6_e_a = c6_b;
  c6_f_b = ((c6_mpower(chartInstance, c6_w[0]) - c6_mpower(chartInstance, c6_w[1]))
            + c6_mpower(chartInstance, c6_w[2])) - c6_mpower(chartInstance,
    c6_w[3]);
  c6_e_y = c6_e_a * c6_f_b;
  c6_Tau[0] = c6_b_y;
  c6_Tau[1] = c6_d_y;
  c6_Tau[2] = c6_e_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  for (c6_i5 = 0; c6_i5 < 3; c6_i5++) {
    (*c6_b_Tau)[c6_i5] = c6_Tau[c6_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  sf_debug_check_for_state_inconsistency(_QmoddefMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc6_Qmoddef(SFc6_QmoddefInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i6;
  real_T c6_b_inData[3];
  int32_T c6_i7;
  real_T c6_u[3];
  const mxArray *c6_y = NULL;
  SFc6_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc6_QmoddefInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i6 = 0; c6_i6 < 3; c6_i6++) {
    c6_b_inData[c6_i6] = (*(real_T (*)[3])c6_inData)[c6_i6];
  }

  for (c6_i7 = 0; c6_i7 < 3; c6_i7++) {
    c6_u[c6_i7] = c6_b_inData[c6_i7];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_QmoddefInstanceStruct *chartInstance, const
  mxArray *c6_Tau, const char_T *c6_identifier, real_T c6_y[3])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_Tau), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_Tau);
}

static void c6_b_emlrt_marshallIn(SFc6_QmoddefInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[3])
{
  real_T c6_dv1[3];
  int32_T c6_i8;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c6_i8 = 0; c6_i8 < 3; c6_i8++) {
    c6_y[c6_i8] = c6_dv1[c6_i8];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_Tau;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[3];
  int32_T c6_i9;
  SFc6_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc6_QmoddefInstanceStruct *)chartInstanceVoid;
  c6_Tau = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_Tau), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_Tau);
  for (c6_i9 = 0; c6_i9 < 3; c6_i9++) {
    (*(real_T (*)[3])c6_outData)[c6_i9] = c6_y[c6_i9];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc6_QmoddefInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i10;
  real_T c6_b_inData[4];
  int32_T c6_i11;
  real_T c6_u[4];
  const mxArray *c6_y = NULL;
  SFc6_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc6_QmoddefInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i10 = 0; c6_i10 < 4; c6_i10++) {
    c6_b_inData[c6_i10] = (*(real_T (*)[4])c6_inData)[c6_i10];
  }

  for (c6_i11 = 0; c6_i11 < 4; c6_i11++) {
    c6_u[c6_i11] = c6_b_inData[c6_i11];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_c_emlrt_marshallIn(SFc6_QmoddefInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc6_QmoddefInstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_Qmoddef_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[6];
  c6_ResolvedFunctionInfo (*c6_b_info)[6];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i12;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_b_info = (c6_ResolvedFunctionInfo (*)[6])c6_info;
  (*c6_b_info)[0].context = "";
  (*c6_b_info)[0].name = "mtimes";
  (*c6_b_info)[0].dominantType = "double";
  (*c6_b_info)[0].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c6_b_info)[0].fileTimeLo = 1289519692U;
  (*c6_b_info)[0].fileTimeHi = 0U;
  (*c6_b_info)[0].mFileTimeLo = 0U;
  (*c6_b_info)[0].mFileTimeHi = 0U;
  (*c6_b_info)[1].context = "";
  (*c6_b_info)[1].name = "mpower";
  (*c6_b_info)[1].dominantType = "double";
  (*c6_b_info)[1].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c6_b_info)[1].fileTimeLo = 1286818842U;
  (*c6_b_info)[1].fileTimeHi = 0U;
  (*c6_b_info)[1].mFileTimeLo = 0U;
  (*c6_b_info)[1].mFileTimeHi = 0U;
  (*c6_b_info)[2].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c6_b_info)[2].name = "power";
  (*c6_b_info)[2].dominantType = "double";
  (*c6_b_info)[2].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/power.m";
  (*c6_b_info)[2].fileTimeLo = 1307651240U;
  (*c6_b_info)[2].fileTimeHi = 0U;
  (*c6_b_info)[2].mFileTimeLo = 0U;
  (*c6_b_info)[2].mFileTimeHi = 0U;
  (*c6_b_info)[3].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/power.m";
  (*c6_b_info)[3].name = "eml_scalar_eg";
  (*c6_b_info)[3].dominantType = "double";
  (*c6_b_info)[3].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c6_b_info)[3].fileTimeLo = 1286818796U;
  (*c6_b_info)[3].fileTimeHi = 0U;
  (*c6_b_info)[3].mFileTimeLo = 0U;
  (*c6_b_info)[3].mFileTimeHi = 0U;
  (*c6_b_info)[4].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/power.m";
  (*c6_b_info)[4].name = "eml_scalexp_alloc";
  (*c6_b_info)[4].dominantType = "double";
  (*c6_b_info)[4].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c6_b_info)[4].fileTimeLo = 1286818796U;
  (*c6_b_info)[4].fileTimeHi = 0U;
  (*c6_b_info)[4].mFileTimeLo = 0U;
  (*c6_b_info)[4].mFileTimeHi = 0U;
  (*c6_b_info)[5].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/power.m";
  (*c6_b_info)[5].name = "eml_scalar_floor";
  (*c6_b_info)[5].dominantType = "double";
  (*c6_b_info)[5].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c6_b_info)[5].fileTimeLo = 1286818726U;
  (*c6_b_info)[5].fileTimeHi = 0U;
  (*c6_b_info)[5].mFileTimeLo = 0U;
  (*c6_b_info)[5].mFileTimeHi = 0U;
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 6), FALSE);
  for (c6_i12 = 0; c6_i12 < 6; c6_i12++) {
    c6_r0 = &c6_info[c6_i12];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i12);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i12);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i12);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i12);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i12);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i12);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i12);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i12);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static real_T c6_mpower(SFc6_QmoddefInstanceStruct *chartInstance, real_T c6_a)
{
  real_T c6_b_a;
  real_T c6_ak;
  c6_b_a = c6_a;
  c6_ak = c6_b_a;
  return muDoubleScalarPower(c6_ak, 2.0);
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc6_QmoddefInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static int32_T c6_d_emlrt_marshallIn(SFc6_QmoddefInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i13;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i13, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i13;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc6_QmoddefInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_e_emlrt_marshallIn(SFc6_QmoddefInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_Qmoddef, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_Qmoddef), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_Qmoddef);
  return c6_y;
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_QmoddefInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_QmoddefInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_Qmoddef_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4214046533U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2960791551U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4089198966U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1956422674U);
}

mxArray *sf_c6_Qmoddef_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("vIf5jJvAuHz96QsFgktYAB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c6_Qmoddef(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Tau\",},{M[8],M[0],T\"is_active_c6_Qmoddef\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_Qmoddef_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_QmoddefInstanceStruct *chartInstance;
    chartInstance = (SFc6_QmoddefInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_QmoddefMachineNumber_,
          6,
          1,
          1,
          5,
          0,
          0,
          0,
          0,
          0,
          &(chartInstance->chartNumber),
          &(chartInstance->instanceNumber),
          ssGetPath(S),
          (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_QmoddefMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_QmoddefMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_QmoddefMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"w");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Tau");
          _SFD_SET_DATA_PROPS(2,1,1,0,"l");
          _SFD_SET_DATA_PROPS(3,1,1,0,"b");
          _SFD_SET_DATA_PROPS(4,1,1,0,"k");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,133);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c6_l;
          real_T *c6_b;
          real_T *c6_k;
          real_T (*c6_w)[4];
          real_T (*c6_Tau)[3];
          c6_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c6_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c6_l = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c6_Tau = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c6_w = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c6_w);
          _SFD_SET_DATA_VALUE_PTR(1U, *c6_Tau);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_l);
          _SFD_SET_DATA_VALUE_PTR(3U, c6_b);
          _SFD_SET_DATA_VALUE_PTR(4U, c6_k);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_QmoddefMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "Gw9mJ7gioRH0Kj1OX8BHj";
}

static void sf_opaque_initialize_c6_Qmoddef(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_QmoddefInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c6_Qmoddef((SFc6_QmoddefInstanceStruct*) chartInstanceVar);
  initialize_c6_Qmoddef((SFc6_QmoddefInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_Qmoddef(void *chartInstanceVar)
{
  enable_c6_Qmoddef((SFc6_QmoddefInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_Qmoddef(void *chartInstanceVar)
{
  disable_c6_Qmoddef((SFc6_QmoddefInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_Qmoddef(void *chartInstanceVar)
{
  sf_c6_Qmoddef((SFc6_QmoddefInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_Qmoddef(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_Qmoddef((SFc6_QmoddefInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_Qmoddef();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c6_Qmoddef(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_Qmoddef();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_Qmoddef((SFc6_QmoddefInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_Qmoddef(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_Qmoddef(S);
}

static void sf_opaque_set_sim_state_c6_Qmoddef(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c6_Qmoddef(S, st);
}

static void sf_opaque_terminate_c6_Qmoddef(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_QmoddefInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_Qmoddef((SFc6_QmoddefInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Qmoddef_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_Qmoddef((SFc6_QmoddefInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_Qmoddef(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_Qmoddef((SFc6_QmoddefInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_Qmoddef(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Qmoddef_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,6,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2789258298U));
  ssSetChecksum1(S,(2113268616U));
  ssSetChecksum2(S,(4080684926U));
  ssSetChecksum3(S,(1119861547U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_Qmoddef(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_Qmoddef(SimStruct *S)
{
  SFc6_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc6_QmoddefInstanceStruct *)malloc(sizeof
    (SFc6_QmoddefInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_QmoddefInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_Qmoddef;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_Qmoddef;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_Qmoddef;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_Qmoddef;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_Qmoddef;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_Qmoddef;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_Qmoddef;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_Qmoddef;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_Qmoddef;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_Qmoddef;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_Qmoddef;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c6_Qmoddef_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_Qmoddef(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_Qmoddef(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_Qmoddef(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_Qmoddef_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

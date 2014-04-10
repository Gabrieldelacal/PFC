/* Include files */

#include "blascompat32.h"
#include "Qmoddef_sfun.h"
#include "c5_Qmoddef.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Qmoddef_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[9] = { "nargin", "nargout", "dPhi",
  "dTheta", "dPsi", "C", "J", "Tau", "ddEta" };

/* Function Declarations */
static void initialize_c5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance);
static void initialize_params_c5_Qmoddef(SFc5_QmoddefInstanceStruct
  *chartInstance);
static void enable_c5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance);
static void disable_c5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_Qmoddef(SFc5_QmoddefInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_Qmoddef(SFc5_QmoddefInstanceStruct
  *chartInstance);
static void set_sim_state_c5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_st);
static void finalize_c5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance);
static void sf_c5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance);
static void c5_chartstep_c5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance);
static void initSimStructsc5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance, const
  mxArray *c5_ddEta, const char_T *c5_identifier, real_T c5_y[3]);
static void c5_b_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[3]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[30]);
static void c5_inv(SFc5_QmoddefInstanceStruct *chartInstance, real_T c5_x[9],
                   real_T c5_y[9]);
static void c5_inv3x3(SFc5_QmoddefInstanceStruct *chartInstance, real_T c5_x[9],
                      real_T c5_y[9]);
static real_T c5_norm(SFc5_QmoddefInstanceStruct *chartInstance, real_T c5_x[9]);
static void c5_eml_warning(SFc5_QmoddefInstanceStruct *chartInstance);
static void c5_b_eml_warning(SFc5_QmoddefInstanceStruct *chartInstance, char_T
  c5_varargin_2[14]);
static void c5_eml_scalar_eg(SFc5_QmoddefInstanceStruct *chartInstance);
static void c5_d_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_sprintf, const char_T *c5_identifier, char_T c5_y[14]);
static void c5_e_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, char_T c5_y[14]);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_f_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_g_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_Qmoddef, const char_T *c5_identifier);
static uint8_T c5_h_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_QmoddefInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_Qmoddef = 0U;
}

static void initialize_params_c5_Qmoddef(SFc5_QmoddefInstanceStruct
  *chartInstance)
{
}

static void enable_c5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_Qmoddef(SFc5_QmoddefInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c5_Qmoddef(SFc5_QmoddefInstanceStruct
  *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_u[3];
  const mxArray *c5_b_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T (*c5_ddEta)[3];
  c5_ddEta = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2), FALSE);
  for (c5_i0 = 0; c5_i0 < 3; c5_i0++) {
    c5_u[c5_i0] = (*c5_ddEta)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_Qmoddef;
  c5_b_u = c5_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[3];
  int32_T c5_i1;
  real_T (*c5_ddEta)[3];
  c5_ddEta = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
                      "ddEta", c5_dv0);
  for (c5_i1 = 0; c5_i1 < 3; c5_i1++) {
    (*c5_ddEta)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_Qmoddef = c5_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 1)), "is_active_c5_Qmoddef");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_Qmoddef(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance)
{
}

static void sf_c5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance)
{
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  real_T *c5_dPhi;
  real_T *c5_dTheta;
  real_T *c5_dPsi;
  real_T (*c5_Tau)[3];
  real_T (*c5_J)[9];
  real_T (*c5_C)[9];
  real_T (*c5_ddEta)[3];
  c5_Tau = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c5_J = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c5_C = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 3);
  c5_ddEta = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_dPsi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_dTheta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_dPhi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_dPhi, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_dTheta, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_dPsi, 2U);
  for (c5_i2 = 0; c5_i2 < 3; c5_i2++) {
    _SFD_DATA_RANGE_CHECK((*c5_ddEta)[c5_i2], 3U);
  }

  for (c5_i3 = 0; c5_i3 < 9; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((*c5_C)[c5_i3], 4U);
  }

  for (c5_i4 = 0; c5_i4 < 9; c5_i4++) {
    _SFD_DATA_RANGE_CHECK((*c5_J)[c5_i4], 5U);
  }

  for (c5_i5 = 0; c5_i5 < 3; c5_i5++) {
    _SFD_DATA_RANGE_CHECK((*c5_Tau)[c5_i5], 6U);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_Qmoddef(chartInstance);
  sf_debug_check_for_state_inconsistency(_QmoddefMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_chartstep_c5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_dPhi;
  real_T c5_dTheta;
  real_T c5_dPsi;
  int32_T c5_i6;
  real_T c5_C[9];
  int32_T c5_i7;
  real_T c5_J[9];
  int32_T c5_i8;
  real_T c5_Tau[3];
  uint32_T c5_debug_family_var_map[9];
  real_T c5_nargin = 6.0;
  real_T c5_nargout = 1.0;
  real_T c5_ddEta[3];
  int32_T c5_i9;
  real_T c5_a[9];
  real_T c5_b[3];
  int32_T c5_i10;
  real_T c5_y[3];
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  real_T c5_b_J[9];
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  real_T *c5_b_dPhi;
  real_T *c5_b_dTheta;
  real_T *c5_b_dPsi;
  real_T (*c5_b_ddEta)[3];
  real_T (*c5_b_Tau)[3];
  real_T (*c5_c_J)[9];
  real_T (*c5_b_C)[9];
  c5_b_Tau = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c5_c_J = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c5_b_C = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 3);
  c5_b_ddEta = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_dPsi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_dTheta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_dPhi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_dPhi;
  c5_b_hoistedGlobal = *c5_b_dTheta;
  c5_c_hoistedGlobal = *c5_b_dPsi;
  c5_dPhi = c5_hoistedGlobal;
  c5_dTheta = c5_b_hoistedGlobal;
  c5_dPsi = c5_c_hoistedGlobal;
  for (c5_i6 = 0; c5_i6 < 9; c5_i6++) {
    c5_C[c5_i6] = (*c5_b_C)[c5_i6];
  }

  for (c5_i7 = 0; c5_i7 < 9; c5_i7++) {
    c5_J[c5_i7] = (*c5_c_J)[c5_i7];
  }

  for (c5_i8 = 0; c5_i8 < 3; c5_i8++) {
    c5_Tau[c5_i8] = (*c5_b_Tau)[c5_i8];
  }

  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_dPhi, 2U, c5_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_dTheta, 3U, c5_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_dPsi, 4U, c5_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_C, 5U, c5_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_J, 6U, c5_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_Tau, 7U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c5_ddEta, 8U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  for (c5_i9 = 0; c5_i9 < 9; c5_i9++) {
    c5_a[c5_i9] = c5_C[c5_i9];
  }

  c5_b[0] = c5_dPhi;
  c5_b[1] = c5_dTheta;
  c5_b[2] = c5_dPsi;
  c5_eml_scalar_eg(chartInstance);
  c5_eml_scalar_eg(chartInstance);
  for (c5_i10 = 0; c5_i10 < 3; c5_i10++) {
    c5_y[c5_i10] = 0.0;
    c5_i11 = 0;
    for (c5_i12 = 0; c5_i12 < 3; c5_i12++) {
      c5_y[c5_i10] += c5_a[c5_i11 + c5_i10] * c5_b[c5_i12];
      c5_i11 += 3;
    }
  }

  for (c5_i13 = 0; c5_i13 < 9; c5_i13++) {
    c5_b_J[c5_i13] = c5_J[c5_i13];
  }

  c5_inv(chartInstance, c5_b_J, c5_a);
  for (c5_i14 = 0; c5_i14 < 3; c5_i14++) {
    c5_y[c5_i14] = c5_Tau[c5_i14] - c5_y[c5_i14];
  }

  c5_eml_scalar_eg(chartInstance);
  c5_eml_scalar_eg(chartInstance);
  for (c5_i15 = 0; c5_i15 < 3; c5_i15++) {
    c5_ddEta[c5_i15] = 0.0;
  }

  for (c5_i16 = 0; c5_i16 < 3; c5_i16++) {
    c5_ddEta[c5_i16] = 0.0;
  }

  for (c5_i17 = 0; c5_i17 < 3; c5_i17++) {
    c5_b[c5_i17] = c5_ddEta[c5_i17];
  }

  for (c5_i18 = 0; c5_i18 < 3; c5_i18++) {
    c5_ddEta[c5_i18] = c5_b[c5_i18];
  }

  for (c5_i19 = 0; c5_i19 < 3; c5_i19++) {
    c5_b[c5_i19] = c5_ddEta[c5_i19];
  }

  for (c5_i20 = 0; c5_i20 < 3; c5_i20++) {
    c5_ddEta[c5_i20] = c5_b[c5_i20];
  }

  for (c5_i21 = 0; c5_i21 < 3; c5_i21++) {
    c5_ddEta[c5_i21] = 0.0;
    c5_i22 = 0;
    for (c5_i23 = 0; c5_i23 < 3; c5_i23++) {
      c5_ddEta[c5_i21] += c5_a[c5_i22 + c5_i21] * c5_y[c5_i23];
      c5_i22 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  for (c5_i24 = 0; c5_i24 < 3; c5_i24++) {
    (*c5_b_ddEta)[c5_i24] = c5_ddEta[c5_i24];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_Qmoddef(SFc5_QmoddefInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i25;
  real_T c5_b_inData[3];
  int32_T c5_i26;
  real_T c5_u[3];
  const mxArray *c5_y = NULL;
  SFc5_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc5_QmoddefInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i25 = 0; c5_i25 < 3; c5_i25++) {
    c5_b_inData[c5_i25] = (*(real_T (*)[3])c5_inData)[c5_i25];
  }

  for (c5_i26 = 0; c5_i26 < 3; c5_i26++) {
    c5_u[c5_i26] = c5_b_inData[c5_i26];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance, const
  mxArray *c5_ddEta, const char_T *c5_identifier, real_T c5_y[3])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_ddEta), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_ddEta);
}

static void c5_b_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[3])
{
  real_T c5_dv1[3];
  int32_T c5_i27;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c5_i27 = 0; c5_i27 < 3; c5_i27++) {
    c5_y[c5_i27] = c5_dv1[c5_i27];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_ddEta;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[3];
  int32_T c5_i28;
  SFc5_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc5_QmoddefInstanceStruct *)chartInstanceVoid;
  c5_ddEta = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_ddEta), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_ddEta);
  for (c5_i28 = 0; c5_i28 < 3; c5_i28++) {
    (*(real_T (*)[3])c5_outData)[c5_i28] = c5_y[c5_i28];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i29;
  int32_T c5_i30;
  int32_T c5_i31;
  real_T c5_b_inData[9];
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  real_T c5_u[9];
  const mxArray *c5_y = NULL;
  SFc5_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc5_QmoddefInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i29 = 0;
  for (c5_i30 = 0; c5_i30 < 3; c5_i30++) {
    for (c5_i31 = 0; c5_i31 < 3; c5_i31++) {
      c5_b_inData[c5_i31 + c5_i29] = (*(real_T (*)[9])c5_inData)[c5_i31 + c5_i29];
    }

    c5_i29 += 3;
  }

  c5_i32 = 0;
  for (c5_i33 = 0; c5_i33 < 3; c5_i33++) {
    for (c5_i34 = 0; c5_i34 < 3; c5_i34++) {
      c5_u[c5_i34 + c5_i32] = c5_b_inData[c5_i34 + c5_i32];
    }

    c5_i32 += 3;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc5_QmoddefInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc5_QmoddefInstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_Qmoddef_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[30];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i35;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 30), FALSE);
  for (c5_i35 = 0; c5_i35 < 30; c5_i35++) {
    c5_r0 = &c5_info[c5_i35];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i35);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i35);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i35);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i35);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i35);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i35);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i35);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i35);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[30])
{
  c5_info[0].context = "";
  c5_info[0].name = "inv";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m";
  c5_info[0].fileTimeLo = 1305318000U;
  c5_info[0].fileTimeHi = 0U;
  c5_info[0].mFileTimeLo = 0U;
  c5_info[0].mFileTimeHi = 0U;
  c5_info[1].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c5_info[1].name = "eml_index_class";
  c5_info[1].dominantType = "";
  c5_info[1].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[1].fileTimeLo = 1286818778U;
  c5_info[1].fileTimeHi = 0U;
  c5_info[1].mFileTimeLo = 0U;
  c5_info[1].mFileTimeHi = 0U;
  c5_info[2].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c5_info[2].name = "abs";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[2].fileTimeLo = 1286818694U;
  c5_info[2].fileTimeHi = 0U;
  c5_info[2].mFileTimeLo = 0U;
  c5_info[2].mFileTimeHi = 0U;
  c5_info[3].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[3].name = "eml_scalar_abs";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c5_info[3].fileTimeLo = 1286818712U;
  c5_info[3].fileTimeHi = 0U;
  c5_info[3].mFileTimeLo = 0U;
  c5_info[3].mFileTimeHi = 0U;
  c5_info[4].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c5_info[4].name = "eml_div";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[4].fileTimeLo = 1313347810U;
  c5_info[4].fileTimeHi = 0U;
  c5_info[4].mFileTimeLo = 0U;
  c5_info[4].mFileTimeHi = 0U;
  c5_info[5].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c5_info[5].name = "mtimes";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[5].fileTimeLo = 1289519692U;
  c5_info[5].fileTimeHi = 0U;
  c5_info[5].mFileTimeLo = 0U;
  c5_info[5].mFileTimeHi = 0U;
  c5_info[6].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c5_info[6].name = "eml_index_plus";
  c5_info[6].dominantType = "int32";
  c5_info[6].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[6].fileTimeLo = 1286818778U;
  c5_info[6].fileTimeHi = 0U;
  c5_info[6].mFileTimeLo = 0U;
  c5_info[6].mFileTimeHi = 0U;
  c5_info[7].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[7].name = "eml_index_class";
  c5_info[7].dominantType = "";
  c5_info[7].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[7].fileTimeLo = 1286818778U;
  c5_info[7].fileTimeHi = 0U;
  c5_info[7].mFileTimeLo = 0U;
  c5_info[7].mFileTimeHi = 0U;
  c5_info[8].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c5_info[8].name = "norm";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/norm.m";
  c5_info[8].fileTimeLo = 1286818826U;
  c5_info[8].fileTimeHi = 0U;
  c5_info[8].mFileTimeLo = 0U;
  c5_info[8].mFileTimeHi = 0U;
  c5_info[9].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c5_info[9].name = "abs";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[9].fileTimeLo = 1286818694U;
  c5_info[9].fileTimeHi = 0U;
  c5_info[9].mFileTimeLo = 0U;
  c5_info[9].mFileTimeHi = 0U;
  c5_info[10].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c5_info[10].name = "isnan";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elmat/isnan.m";
  c5_info[10].fileTimeLo = 1286818760U;
  c5_info[10].fileTimeHi = 0U;
  c5_info[10].mFileTimeLo = 0U;
  c5_info[10].mFileTimeHi = 0U;
  c5_info[11].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c5_info[11].name = "eml_guarded_nan";
  c5_info[11].dominantType = "char";
  c5_info[11].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c5_info[11].fileTimeLo = 1286818776U;
  c5_info[11].fileTimeHi = 0U;
  c5_info[11].mFileTimeLo = 0U;
  c5_info[11].mFileTimeHi = 0U;
  c5_info[12].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c5_info[12].name = "eml_is_float_class";
  c5_info[12].dominantType = "char";
  c5_info[12].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c5_info[12].fileTimeLo = 1286818782U;
  c5_info[12].fileTimeHi = 0U;
  c5_info[12].mFileTimeLo = 0U;
  c5_info[12].mFileTimeHi = 0U;
  c5_info[13].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c5_info[13].name = "mtimes";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[13].fileTimeLo = 1289519692U;
  c5_info[13].fileTimeHi = 0U;
  c5_info[13].mFileTimeLo = 0U;
  c5_info[13].mFileTimeHi = 0U;
  c5_info[14].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c5_info[14].name = "eml_warning";
  c5_info[14].dominantType = "char";
  c5_info[14].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c5_info[14].fileTimeLo = 1286818802U;
  c5_info[14].fileTimeHi = 0U;
  c5_info[14].mFileTimeLo = 0U;
  c5_info[14].mFileTimeHi = 0U;
  c5_info[15].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c5_info[15].name = "isnan";
  c5_info[15].dominantType = "double";
  c5_info[15].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elmat/isnan.m";
  c5_info[15].fileTimeLo = 1286818760U;
  c5_info[15].fileTimeHi = 0U;
  c5_info[15].mFileTimeLo = 0U;
  c5_info[15].mFileTimeHi = 0U;
  c5_info[16].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c5_info[16].name = "eps";
  c5_info[16].dominantType = "char";
  c5_info[16].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[16].fileTimeLo = 1307651240U;
  c5_info[16].fileTimeHi = 0U;
  c5_info[16].mFileTimeLo = 0U;
  c5_info[16].mFileTimeHi = 0U;
  c5_info[17].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[17].name = "eml_is_float_class";
  c5_info[17].dominantType = "char";
  c5_info[17].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c5_info[17].fileTimeLo = 1286818782U;
  c5_info[17].fileTimeHi = 0U;
  c5_info[17].mFileTimeLo = 0U;
  c5_info[17].mFileTimeHi = 0U;
  c5_info[18].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[18].name = "eml_eps";
  c5_info[18].dominantType = "char";
  c5_info[18].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c5_info[18].fileTimeLo = 1307651240U;
  c5_info[18].fileTimeHi = 0U;
  c5_info[18].mFileTimeLo = 0U;
  c5_info[18].mFileTimeHi = 0U;
  c5_info[19].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c5_info[19].name = "eml_float_model";
  c5_info[19].dominantType = "char";
  c5_info[19].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c5_info[19].fileTimeLo = 1307651242U;
  c5_info[19].fileTimeHi = 0U;
  c5_info[19].mFileTimeLo = 0U;
  c5_info[19].mFileTimeHi = 0U;
  c5_info[20].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c5_info[20].name = "eml_flt2str";
  c5_info[20].dominantType = "double";
  c5_info[20].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c5_info[20].fileTimeLo = 1309451196U;
  c5_info[20].fileTimeHi = 0U;
  c5_info[20].mFileTimeLo = 0U;
  c5_info[20].mFileTimeHi = 0U;
  c5_info[21].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c5_info[21].name = "char";
  c5_info[21].dominantType = "double";
  c5_info[21].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/strfun/char.m";
  c5_info[21].fileTimeLo = 1319729968U;
  c5_info[21].fileTimeHi = 0U;
  c5_info[21].mFileTimeLo = 0U;
  c5_info[21].mFileTimeHi = 0U;
  c5_info[22].context = "";
  c5_info[22].name = "mtimes";
  c5_info[22].dominantType = "double";
  c5_info[22].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[22].fileTimeLo = 1289519692U;
  c5_info[22].fileTimeHi = 0U;
  c5_info[22].mFileTimeLo = 0U;
  c5_info[22].mFileTimeHi = 0U;
  c5_info[23].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[23].name = "eml_index_class";
  c5_info[23].dominantType = "";
  c5_info[23].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[23].fileTimeLo = 1286818778U;
  c5_info[23].fileTimeHi = 0U;
  c5_info[23].mFileTimeLo = 0U;
  c5_info[23].mFileTimeHi = 0U;
  c5_info[24].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[24].name = "eml_scalar_eg";
  c5_info[24].dominantType = "double";
  c5_info[24].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[24].fileTimeLo = 1286818796U;
  c5_info[24].fileTimeHi = 0U;
  c5_info[24].mFileTimeLo = 0U;
  c5_info[24].mFileTimeHi = 0U;
  c5_info[25].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[25].name = "eml_xgemm";
  c5_info[25].dominantType = "int32";
  c5_info[25].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c5_info[25].fileTimeLo = 1299076772U;
  c5_info[25].fileTimeHi = 0U;
  c5_info[25].mFileTimeLo = 0U;
  c5_info[25].mFileTimeHi = 0U;
  c5_info[26].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c5_info[26].name = "eml_blas_inline";
  c5_info[26].dominantType = "";
  c5_info[26].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c5_info[26].fileTimeLo = 1299076768U;
  c5_info[26].fileTimeHi = 0U;
  c5_info[26].mFileTimeLo = 0U;
  c5_info[26].mFileTimeHi = 0U;
  c5_info[27].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c5_info[27].name = "mtimes";
  c5_info[27].dominantType = "double";
  c5_info[27].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[27].fileTimeLo = 1289519692U;
  c5_info[27].fileTimeHi = 0U;
  c5_info[27].mFileTimeLo = 0U;
  c5_info[27].mFileTimeHi = 0U;
  c5_info[28].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c5_info[28].name = "eml_scalar_eg";
  c5_info[28].dominantType = "double";
  c5_info[28].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[28].fileTimeLo = 1286818796U;
  c5_info[28].fileTimeHi = 0U;
  c5_info[28].mFileTimeLo = 0U;
  c5_info[28].mFileTimeHi = 0U;
  c5_info[29].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c5_info[29].name = "eml_refblas_xgemm";
  c5_info[29].dominantType = "int32";
  c5_info[29].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c5_info[29].fileTimeLo = 1299076774U;
  c5_info[29].fileTimeHi = 0U;
  c5_info[29].mFileTimeLo = 0U;
  c5_info[29].mFileTimeHi = 0U;
}

static void c5_inv(SFc5_QmoddefInstanceStruct *chartInstance, real_T c5_x[9],
                   real_T c5_y[9])
{
  int32_T c5_i36;
  real_T c5_b_x[9];
  int32_T c5_i37;
  real_T c5_c_x[9];
  real_T c5_n1x;
  int32_T c5_i38;
  real_T c5_b_y[9];
  real_T c5_n1xinv;
  real_T c5_a;
  real_T c5_b;
  real_T c5_c_y;
  real_T c5_rc;
  real_T c5_d_x;
  boolean_T c5_b_b;
  real_T c5_e_x;
  int32_T c5_i39;
  static char_T c5_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c5_u[8];
  const mxArray *c5_d_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_e_y = NULL;
  real_T c5_c_u;
  const mxArray *c5_f_y = NULL;
  real_T c5_d_u;
  const mxArray *c5_g_y = NULL;
  char_T c5_str[14];
  int32_T c5_i40;
  char_T c5_b_str[14];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  for (c5_i36 = 0; c5_i36 < 9; c5_i36++) {
    c5_b_x[c5_i36] = c5_x[c5_i36];
  }

  c5_inv3x3(chartInstance, c5_b_x, c5_y);
  for (c5_i37 = 0; c5_i37 < 9; c5_i37++) {
    c5_c_x[c5_i37] = c5_x[c5_i37];
  }

  c5_n1x = c5_norm(chartInstance, c5_c_x);
  for (c5_i38 = 0; c5_i38 < 9; c5_i38++) {
    c5_b_y[c5_i38] = c5_y[c5_i38];
  }

  c5_n1xinv = c5_norm(chartInstance, c5_b_y);
  c5_a = c5_n1x;
  c5_b = c5_n1xinv;
  c5_c_y = c5_a * c5_b;
  c5_rc = 1.0 / c5_c_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c5_n1x == 0.0) {
    guard2 = TRUE;
  } else if (c5_n1xinv == 0.0) {
    guard2 = TRUE;
  } else if (c5_rc == 0.0) {
    guard1 = TRUE;
  } else {
    c5_d_x = c5_rc;
    c5_b_b = muDoubleScalarIsNaN(c5_d_x);
    guard3 = FALSE;
    if (c5_b_b) {
      guard3 = TRUE;
    } else {
      if (c5_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c5_e_x = c5_rc;
      for (c5_i39 = 0; c5_i39 < 8; c5_i39++) {
        c5_u[c5_i39] = c5_cv0[c5_i39];
      }

      c5_d_y = NULL;
      sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c5_b_u = 14.0;
      c5_e_y = NULL;
      sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c5_c_u = 6.0;
      c5_f_y = NULL;
      sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c5_d_u = c5_e_x;
      c5_g_y = NULL;
      sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c5_d_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c5_d_y, 14, c5_e_y, 14,
        c5_f_y), 14, c5_g_y), "sprintf", c5_str);
      for (c5_i40 = 0; c5_i40 < 14; c5_i40++) {
        c5_b_str[c5_i40] = c5_str[c5_i40];
      }

      c5_b_eml_warning(chartInstance, c5_b_str);
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c5_eml_warning(chartInstance);
  }
}

static void c5_inv3x3(SFc5_QmoddefInstanceStruct *chartInstance, real_T c5_x[9],
                      real_T c5_y[9])
{
  int32_T c5_p1;
  int32_T c5_p2;
  int32_T c5_p3;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_absx11;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_absx21;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_absx31;
  real_T c5_t1;
  real_T c5_h_x;
  real_T c5_b_y;
  real_T c5_z;
  real_T c5_i_x;
  real_T c5_c_y;
  real_T c5_b_z;
  real_T c5_a;
  real_T c5_b;
  real_T c5_d_y;
  real_T c5_b_a;
  real_T c5_b_b;
  real_T c5_e_y;
  real_T c5_c_a;
  real_T c5_c_b;
  real_T c5_f_y;
  real_T c5_d_a;
  real_T c5_d_b;
  real_T c5_g_y;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_h_y;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_i_y;
  int32_T c5_itmp;
  real_T c5_n_x;
  real_T c5_j_y;
  real_T c5_c_z;
  real_T c5_e_a;
  real_T c5_e_b;
  real_T c5_k_y;
  real_T c5_f_a;
  real_T c5_f_b;
  real_T c5_l_y;
  real_T c5_o_x;
  real_T c5_m_y;
  real_T c5_t3;
  real_T c5_g_a;
  real_T c5_g_b;
  real_T c5_n_y;
  real_T c5_p_x;
  real_T c5_o_y;
  real_T c5_t2;
  int32_T c5_h_a;
  int32_T c5_c;
  real_T c5_i_a;
  real_T c5_h_b;
  real_T c5_p_y;
  real_T c5_j_a;
  real_T c5_i_b;
  real_T c5_q_y;
  real_T c5_q_x;
  real_T c5_r_y;
  real_T c5_d_z;
  int32_T c5_k_a;
  int32_T c5_b_c;
  int32_T c5_l_a;
  int32_T c5_c_c;
  real_T c5_r_x;
  real_T c5_s_y;
  real_T c5_m_a;
  real_T c5_j_b;
  real_T c5_t_y;
  real_T c5_s_x;
  real_T c5_u_y;
  int32_T c5_n_a;
  int32_T c5_d_c;
  real_T c5_o_a;
  real_T c5_k_b;
  real_T c5_v_y;
  real_T c5_p_a;
  real_T c5_l_b;
  real_T c5_w_y;
  real_T c5_t_x;
  real_T c5_x_y;
  real_T c5_e_z;
  int32_T c5_q_a;
  int32_T c5_e_c;
  int32_T c5_r_a;
  int32_T c5_f_c;
  real_T c5_y_y;
  real_T c5_s_a;
  real_T c5_m_b;
  real_T c5_ab_y;
  real_T c5_u_x;
  real_T c5_bb_y;
  int32_T c5_t_a;
  int32_T c5_g_c;
  real_T c5_u_a;
  real_T c5_n_b;
  real_T c5_cb_y;
  real_T c5_v_a;
  real_T c5_o_b;
  real_T c5_db_y;
  real_T c5_v_x;
  real_T c5_eb_y;
  real_T c5_f_z;
  int32_T c5_w_a;
  int32_T c5_h_c;
  int32_T c5_x_a;
  int32_T c5_i_c;
  boolean_T guard1 = FALSE;
  c5_p1 = 0;
  c5_p2 = 3;
  c5_p3 = 6;
  c5_b_x = c5_x[0];
  c5_c_x = c5_b_x;
  c5_absx11 = muDoubleScalarAbs(c5_c_x);
  c5_d_x = c5_x[1];
  c5_e_x = c5_d_x;
  c5_absx21 = muDoubleScalarAbs(c5_e_x);
  c5_f_x = c5_x[2];
  c5_g_x = c5_f_x;
  c5_absx31 = muDoubleScalarAbs(c5_g_x);
  guard1 = FALSE;
  if (c5_absx21 > c5_absx11) {
    if (c5_absx21 > c5_absx31) {
      c5_p1 = 3;
      c5_p2 = 0;
      c5_t1 = c5_x[0];
      c5_x[0] = c5_x[1];
      c5_x[1] = c5_t1;
      c5_t1 = c5_x[3];
      c5_x[3] = c5_x[4];
      c5_x[4] = c5_t1;
      c5_t1 = c5_x[6];
      c5_x[6] = c5_x[7];
      c5_x[7] = c5_t1;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    if (c5_absx31 > c5_absx11) {
      c5_p1 = 6;
      c5_p3 = 0;
      c5_t1 = c5_x[0];
      c5_x[0] = c5_x[2];
      c5_x[2] = c5_t1;
      c5_t1 = c5_x[3];
      c5_x[3] = c5_x[5];
      c5_x[5] = c5_t1;
      c5_t1 = c5_x[6];
      c5_x[6] = c5_x[8];
      c5_x[8] = c5_t1;
    }
  }

  c5_h_x = c5_x[1];
  c5_b_y = c5_x[0];
  c5_z = c5_h_x / c5_b_y;
  c5_x[1] = c5_z;
  c5_i_x = c5_x[2];
  c5_c_y = c5_x[0];
  c5_b_z = c5_i_x / c5_c_y;
  c5_x[2] = c5_b_z;
  c5_a = c5_x[1];
  c5_b = c5_x[3];
  c5_d_y = c5_a * c5_b;
  c5_x[4] -= c5_d_y;
  c5_b_a = c5_x[2];
  c5_b_b = c5_x[3];
  c5_e_y = c5_b_a * c5_b_b;
  c5_x[5] -= c5_e_y;
  c5_c_a = c5_x[1];
  c5_c_b = c5_x[6];
  c5_f_y = c5_c_a * c5_c_b;
  c5_x[7] -= c5_f_y;
  c5_d_a = c5_x[2];
  c5_d_b = c5_x[6];
  c5_g_y = c5_d_a * c5_d_b;
  c5_x[8] -= c5_g_y;
  c5_j_x = c5_x[5];
  c5_k_x = c5_j_x;
  c5_h_y = muDoubleScalarAbs(c5_k_x);
  c5_l_x = c5_x[4];
  c5_m_x = c5_l_x;
  c5_i_y = muDoubleScalarAbs(c5_m_x);
  if (c5_h_y > c5_i_y) {
    c5_itmp = c5_p2;
    c5_p2 = c5_p3;
    c5_p3 = c5_itmp;
    c5_t1 = c5_x[1];
    c5_x[1] = c5_x[2];
    c5_x[2] = c5_t1;
    c5_t1 = c5_x[4];
    c5_x[4] = c5_x[5];
    c5_x[5] = c5_t1;
    c5_t1 = c5_x[7];
    c5_x[7] = c5_x[8];
    c5_x[8] = c5_t1;
  }

  c5_n_x = c5_x[5];
  c5_j_y = c5_x[4];
  c5_c_z = c5_n_x / c5_j_y;
  c5_x[5] = c5_c_z;
  c5_e_a = c5_x[5];
  c5_e_b = c5_x[7];
  c5_k_y = c5_e_a * c5_e_b;
  c5_x[8] -= c5_k_y;
  c5_f_a = c5_x[5];
  c5_f_b = c5_x[1];
  c5_l_y = c5_f_a * c5_f_b;
  c5_o_x = c5_l_y - c5_x[2];
  c5_m_y = c5_x[8];
  c5_t3 = c5_o_x / c5_m_y;
  c5_g_a = c5_x[7];
  c5_g_b = c5_t3;
  c5_n_y = c5_g_a * c5_g_b;
  c5_p_x = -(c5_x[1] + c5_n_y);
  c5_o_y = c5_x[4];
  c5_t2 = c5_p_x / c5_o_y;
  c5_h_a = c5_p1 + 1;
  c5_c = c5_h_a;
  c5_i_a = c5_x[3];
  c5_h_b = c5_t2;
  c5_p_y = c5_i_a * c5_h_b;
  c5_j_a = c5_x[6];
  c5_i_b = c5_t3;
  c5_q_y = c5_j_a * c5_i_b;
  c5_q_x = (1.0 - c5_p_y) - c5_q_y;
  c5_r_y = c5_x[0];
  c5_d_z = c5_q_x / c5_r_y;
  c5_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c5_c), 1, 9, 1, 0) - 1] = c5_d_z;
  c5_k_a = c5_p1 + 2;
  c5_b_c = c5_k_a;
  c5_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c5_b_c), 1, 9, 1, 0) - 1] = c5_t2;
  c5_l_a = c5_p1 + 3;
  c5_c_c = c5_l_a;
  c5_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c5_c_c), 1, 9, 1, 0) - 1] = c5_t3;
  c5_r_x = -c5_x[5];
  c5_s_y = c5_x[8];
  c5_t3 = c5_r_x / c5_s_y;
  c5_m_a = c5_x[7];
  c5_j_b = c5_t3;
  c5_t_y = c5_m_a * c5_j_b;
  c5_s_x = 1.0 - c5_t_y;
  c5_u_y = c5_x[4];
  c5_t2 = c5_s_x / c5_u_y;
  c5_n_a = c5_p2 + 1;
  c5_d_c = c5_n_a;
  c5_o_a = c5_x[3];
  c5_k_b = c5_t2;
  c5_v_y = c5_o_a * c5_k_b;
  c5_p_a = c5_x[6];
  c5_l_b = c5_t3;
  c5_w_y = c5_p_a * c5_l_b;
  c5_t_x = -(c5_v_y + c5_w_y);
  c5_x_y = c5_x[0];
  c5_e_z = c5_t_x / c5_x_y;
  c5_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c5_d_c), 1, 9, 1, 0) - 1] = c5_e_z;
  c5_q_a = c5_p2 + 2;
  c5_e_c = c5_q_a;
  c5_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c5_e_c), 1, 9, 1, 0) - 1] = c5_t2;
  c5_r_a = c5_p2 + 3;
  c5_f_c = c5_r_a;
  c5_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c5_f_c), 1, 9, 1, 0) - 1] = c5_t3;
  c5_y_y = c5_x[8];
  c5_t3 = 1.0 / c5_y_y;
  c5_s_a = -c5_x[7];
  c5_m_b = c5_t3;
  c5_ab_y = c5_s_a * c5_m_b;
  c5_u_x = c5_ab_y;
  c5_bb_y = c5_x[4];
  c5_t2 = c5_u_x / c5_bb_y;
  c5_t_a = c5_p3 + 1;
  c5_g_c = c5_t_a;
  c5_u_a = c5_x[3];
  c5_n_b = c5_t2;
  c5_cb_y = c5_u_a * c5_n_b;
  c5_v_a = c5_x[6];
  c5_o_b = c5_t3;
  c5_db_y = c5_v_a * c5_o_b;
  c5_v_x = -(c5_cb_y + c5_db_y);
  c5_eb_y = c5_x[0];
  c5_f_z = c5_v_x / c5_eb_y;
  c5_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c5_g_c), 1, 9, 1, 0) - 1] = c5_f_z;
  c5_w_a = c5_p3 + 2;
  c5_h_c = c5_w_a;
  c5_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c5_h_c), 1, 9, 1, 0) - 1] = c5_t2;
  c5_x_a = c5_p3 + 3;
  c5_i_c = c5_x_a;
  c5_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c5_i_c), 1, 9, 1, 0) - 1] = c5_t3;
}

static real_T c5_norm(SFc5_QmoddefInstanceStruct *chartInstance, real_T c5_x[9])
{
  real_T c5_y;
  int32_T c5_j;
  real_T c5_b_j;
  real_T c5_s;
  int32_T c5_i;
  real_T c5_b_i;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_b_y;
  real_T c5_d_x;
  boolean_T c5_b;
  boolean_T exitg1;
  c5_y = 0.0;
  c5_j = 0;
  exitg1 = FALSE;
  while ((exitg1 == 0U) && (c5_j < 3)) {
    c5_b_j = 1.0 + (real_T)c5_j;
    c5_s = 0.0;
    for (c5_i = 0; c5_i < 3; c5_i++) {
      c5_b_i = 1.0 + (real_T)c5_i;
      c5_b_x = c5_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c5_b_i), 1, 3, 1, 0) + 3 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c5_b_j), 1, 3, 2, 0) - 1)) - 1];
      c5_c_x = c5_b_x;
      c5_b_y = muDoubleScalarAbs(c5_c_x);
      c5_s += c5_b_y;
    }

    c5_d_x = c5_s;
    c5_b = muDoubleScalarIsNaN(c5_d_x);
    if (c5_b) {
      c5_y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (c5_s > c5_y) {
        c5_y = c5_s;
      }

      c5_j++;
    }
  }

  return c5_y;
}

static void c5_eml_warning(SFc5_QmoddefInstanceStruct *chartInstance)
{
  int32_T c5_i41;
  static char_T c5_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c5_u[27];
  const mxArray *c5_y = NULL;
  for (c5_i41 = 0; c5_i41 < 27; c5_i41++) {
    c5_u[c5_i41] = c5_varargin_1[c5_i41];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c5_y));
}

static void c5_b_eml_warning(SFc5_QmoddefInstanceStruct *chartInstance, char_T
  c5_varargin_2[14])
{
  int32_T c5_i42;
  static char_T c5_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c5_u[33];
  const mxArray *c5_y = NULL;
  int32_T c5_i43;
  char_T c5_b_u[14];
  const mxArray *c5_b_y = NULL;
  for (c5_i42 = 0; c5_i42 < 33; c5_i42++) {
    c5_u[c5_i42] = c5_varargin_1[c5_i42];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  for (c5_i43 = 0; c5_i43 < 14; c5_i43++) {
    c5_b_u[c5_i43] = c5_varargin_2[c5_i43];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c5_y, 14, c5_b_y));
}

static void c5_eml_scalar_eg(SFc5_QmoddefInstanceStruct *chartInstance)
{
}

static void c5_d_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_sprintf, const char_T *c5_identifier, char_T c5_y[14])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_sprintf), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_sprintf);
}

static void c5_e_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, char_T c5_y[14])
{
  char_T c5_cv1[14];
  int32_T c5_i44;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c5_i44 = 0; c5_i44 < 14; c5_i44++) {
    c5_y[c5_i44] = c5_cv1[c5_i44];
  }

  sf_mex_destroy(&c5_u);
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc5_QmoddefInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_f_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i45;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i45, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i45;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc5_QmoddefInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_g_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_Qmoddef, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_Qmoddef), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_Qmoddef);
  return c5_y;
}

static uint8_T c5_h_emlrt_marshallIn(SFc5_QmoddefInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_QmoddefInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_Qmoddef_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3807035143U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3903545700U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2849728229U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2377853757U);
}

mxArray *sf_c5_Qmoddef_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("OdV7GO3nAVWJ8yxmu60LRC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
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

static const mxArray *sf_get_sim_state_info_c5_Qmoddef(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"ddEta\",},{M[8],M[0],T\"is_active_c5_Qmoddef\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_Qmoddef_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_QmoddefInstanceStruct *chartInstance;
    chartInstance = (SFc5_QmoddefInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_QmoddefMachineNumber_,
          5,
          1,
          1,
          7,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"dPhi");
          _SFD_SET_DATA_PROPS(1,1,1,0,"dTheta");
          _SFD_SET_DATA_PROPS(2,1,1,0,"dPsi");
          _SFD_SET_DATA_PROPS(3,2,0,1,"ddEta");
          _SFD_SET_DATA_PROPS(4,1,1,0,"C");
          _SFD_SET_DATA_PROPS(5,1,1,0,"J");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Tau");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,102);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c5_dPhi;
          real_T *c5_dTheta;
          real_T *c5_dPsi;
          real_T (*c5_ddEta)[3];
          real_T (*c5_C)[9];
          real_T (*c5_J)[9];
          real_T (*c5_Tau)[3];
          c5_Tau = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
          c5_J = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
          c5_C = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 3);
          c5_ddEta = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_dPsi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_dTheta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_dPhi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_dPhi);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_dTheta);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_dPsi);
          _SFD_SET_DATA_VALUE_PTR(3U, *c5_ddEta);
          _SFD_SET_DATA_VALUE_PTR(4U, *c5_C);
          _SFD_SET_DATA_VALUE_PTR(5U, *c5_J);
          _SFD_SET_DATA_VALUE_PTR(6U, *c5_Tau);
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
  return "5kITUoMf8jdHAwsvqwE1RB";
}

static void sf_opaque_initialize_c5_Qmoddef(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_QmoddefInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c5_Qmoddef((SFc5_QmoddefInstanceStruct*) chartInstanceVar);
  initialize_c5_Qmoddef((SFc5_QmoddefInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_Qmoddef(void *chartInstanceVar)
{
  enable_c5_Qmoddef((SFc5_QmoddefInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_Qmoddef(void *chartInstanceVar)
{
  disable_c5_Qmoddef((SFc5_QmoddefInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_Qmoddef(void *chartInstanceVar)
{
  sf_c5_Qmoddef((SFc5_QmoddefInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_Qmoddef(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_Qmoddef((SFc5_QmoddefInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_Qmoddef();/* state var info */
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

extern void sf_internal_set_sim_state_c5_Qmoddef(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_Qmoddef();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_Qmoddef((SFc5_QmoddefInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_Qmoddef(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_Qmoddef(S);
}

static void sf_opaque_set_sim_state_c5_Qmoddef(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c5_Qmoddef(S, st);
}

static void sf_opaque_terminate_c5_Qmoddef(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_QmoddefInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_Qmoddef((SFc5_QmoddefInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Qmoddef_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_Qmoddef((SFc5_QmoddefInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_Qmoddef(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_Qmoddef((SFc5_QmoddefInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_Qmoddef(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Qmoddef_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1151625006U));
  ssSetChecksum1(S,(2402323563U));
  ssSetChecksum2(S,(2912232041U));
  ssSetChecksum3(S,(3486190703U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_Qmoddef(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_Qmoddef(SimStruct *S)
{
  SFc5_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc5_QmoddefInstanceStruct *)malloc(sizeof
    (SFc5_QmoddefInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_QmoddefInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_Qmoddef;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_Qmoddef;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_Qmoddef;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_Qmoddef;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_Qmoddef;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_Qmoddef;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_Qmoddef;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_Qmoddef;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_Qmoddef;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_Qmoddef;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_Qmoddef;
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

void c5_Qmoddef_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_Qmoddef(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_Qmoddef(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_Qmoddef(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_Qmoddef_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

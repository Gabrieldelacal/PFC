/* Include files */

#include "blascompat32.h"
#include "Qmod3_sfun.h"
#include "c1_Qmod3.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Qmod3_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[9] = { "Thrust", "nargin", "nargout",
  "w", "k", "m", "g", "R", "y" };

/* Function Declarations */
static void initialize_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance);
static void initialize_params_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance);
static void enable_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance);
static void disable_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_Qmod3(SFc1_Qmod3InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_Qmod3(SFc1_Qmod3InstanceStruct
  *chartInstance);
static void set_sim_state_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance,
  const mxArray *c1_st);
static void finalize_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance);
static void sf_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance);
static void c1_chartstep_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance);
static void initSimStructsc1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_Qmod3InstanceStruct *chartInstance, const
  mxArray *c1_y, const char_T *c1_identifier, real_T c1_b_y[3]);
static void c1_b_emlrt_marshallIn(SFc1_Qmod3InstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_Qmod3InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_eml_scalar_eg(SFc1_Qmod3InstanceStruct *chartInstance);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_Qmod3InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_Qmod3InstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_Qmod3, const char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_Qmod3InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_Qmod3InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_Qmod3 = 0U;
}

static void initialize_params_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance)
{
}

static void enable_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_Qmod3(SFc1_Qmod3InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_Qmod3(SFc1_Qmod3InstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[3];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_d_y)[3];
  c1_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  for (c1_i0 = 0; c1_i0 < 3; c1_i0++) {
    c1_u[c1_i0] = (*c1_d_y)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_Qmod3;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance,
  const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[3];
  int32_T c1_i1;
  real_T (*c1_y)[3];
  c1_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "y",
                      c1_dv0);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    (*c1_y)[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_Qmod3 = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 1)), "is_active_c1_Qmod3");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_Qmod3(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance)
{
}

static void sf_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  real_T *c1_k;
  real_T *c1_m;
  real_T *c1_g;
  real_T (*c1_R)[9];
  real_T (*c1_y)[3];
  real_T (*c1_w)[4];
  c1_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c1_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_g = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_w = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i2 = 0; c1_i2 < 4; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_w)[c1_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_k, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_m, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_g, 3U);
  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_y)[c1_i3], 4U);
  }

  for (c1_i4 = 0; c1_i4 < 9; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_R)[c1_i4], 5U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_Qmod3(chartInstance);
  sf_debug_check_for_state_inconsistency(_Qmod3MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  int32_T c1_i5;
  real_T c1_w[4];
  real_T c1_k;
  real_T c1_m;
  real_T c1_g;
  int32_T c1_i6;
  real_T c1_R[9];
  uint32_T c1_debug_family_var_map[9];
  real_T c1_Thrust[3];
  real_T c1_nargin = 5.0;
  real_T c1_nargout = 1.0;
  real_T c1_y[3];
  real_T c1_a;
  real_T c1_b;
  real_T c1_b_y;
  real_T c1_A;
  real_T c1_B;
  real_T c1_x;
  real_T c1_c_y;
  real_T c1_b_x;
  real_T c1_d_y;
  real_T c1_e_y;
  int32_T c1_i7;
  real_T c1_b_a[9];
  int32_T c1_i8;
  real_T c1_b_b[3];
  int32_T c1_i9;
  real_T c1_f_y[3];
  int32_T c1_i10;
  int32_T c1_i11;
  real_T c1_dv1[3];
  int32_T c1_i12;
  int32_T c1_i13;
  real_T *c1_b_k;
  real_T *c1_b_m;
  real_T *c1_b_g;
  real_T (*c1_g_y)[3];
  real_T (*c1_b_R)[9];
  real_T (*c1_b_w)[4];
  c1_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c1_g_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_g = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_w = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_k;
  c1_b_hoistedGlobal = *c1_b_m;
  c1_c_hoistedGlobal = *c1_b_g;
  for (c1_i5 = 0; c1_i5 < 4; c1_i5++) {
    c1_w[c1_i5] = (*c1_b_w)[c1_i5];
  }

  c1_k = c1_hoistedGlobal;
  c1_m = c1_b_hoistedGlobal;
  c1_g = c1_c_hoistedGlobal;
  for (c1_i6 = 0; c1_i6 < 9; c1_i6++) {
    c1_R[c1_i6] = (*c1_b_R)[c1_i6];
  }

  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_Thrust, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 2U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_w, 3U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_k, 4U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_m, 5U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_g, 6U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_R, 7U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_y, 8U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_a = c1_k;
  c1_b = ((c1_w[0] + c1_w[1]) + c1_w[2]) + c1_w[3];
  c1_b_y = c1_a * c1_b;
  c1_A = c1_b_y;
  c1_B = c1_m;
  c1_x = c1_A;
  c1_c_y = c1_B;
  c1_b_x = c1_x;
  c1_d_y = c1_c_y;
  c1_e_y = c1_b_x / c1_d_y;
  c1_Thrust[0] = 0.0;
  c1_Thrust[1] = 0.0;
  c1_Thrust[2] = c1_e_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  for (c1_i7 = 0; c1_i7 < 9; c1_i7++) {
    c1_b_a[c1_i7] = c1_R[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
    c1_b_b[c1_i8] = c1_Thrust[c1_i8];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    c1_f_y[c1_i9] = 0.0;
    c1_i10 = 0;
    for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
      c1_f_y[c1_i9] += c1_b_a[c1_i10 + c1_i9] * c1_b_b[c1_i11];
      c1_i10 += 3;
    }
  }

  c1_dv1[0] = 0.0;
  c1_dv1[1] = 0.0;
  c1_dv1[2] = -c1_g;
  for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
    c1_y[c1_i12] = c1_f_y[c1_i12] - c1_dv1[c1_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -7);
  sf_debug_symbol_scope_pop();
  for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
    (*c1_g_y)[c1_i13] = c1_y[c1_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_Qmod3(SFc1_Qmod3InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i14;
  real_T c1_b_inData[3];
  int32_T c1_i15;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc1_Qmod3InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    c1_b_inData[c1_i14] = (*(real_T (*)[3])c1_inData)[c1_i14];
  }

  for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
    c1_u[c1_i15] = c1_b_inData[c1_i15];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_Qmod3InstanceStruct *chartInstance, const
  mxArray *c1_y, const char_T *c1_identifier, real_T c1_b_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
}

static void c1_b_emlrt_marshallIn(SFc1_Qmod3InstanceStruct *chartInstance, const
  mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv2[3];
  int32_T c1_i16;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
    c1_y[c1_i16] = c1_dv2[c1_i16];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y[3];
  int32_T c1_i17;
  SFc1_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc1_Qmod3InstanceStruct *)chartInstanceVoid;
  c1_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
  for (c1_i17 = 0; c1_i17 < 3; c1_i17++) {
    (*(real_T (*)[3])c1_outData)[c1_i17] = c1_b_y[c1_i17];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  real_T c1_b_inData[9];
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  real_T c1_u[9];
  const mxArray *c1_y = NULL;
  SFc1_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc1_Qmod3InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i18 = 0;
  for (c1_i19 = 0; c1_i19 < 3; c1_i19++) {
    for (c1_i20 = 0; c1_i20 < 3; c1_i20++) {
      c1_b_inData[c1_i20 + c1_i18] = (*(real_T (*)[9])c1_inData)[c1_i20 + c1_i18];
    }

    c1_i18 += 3;
  }

  c1_i21 = 0;
  for (c1_i22 = 0; c1_i22 < 3; c1_i22++) {
    for (c1_i23 = 0; c1_i23 < 3; c1_i23++) {
      c1_u[c1_i23 + c1_i21] = c1_b_inData[c1_i23 + c1_i21];
    }

    c1_i21 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc1_Qmod3InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i24;
  real_T c1_b_inData[4];
  int32_T c1_i25;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc1_Qmod3InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i24 = 0; c1_i24 < 4; c1_i24++) {
    c1_b_inData[c1_i24] = (*(real_T (*)[4])c1_inData)[c1_i24];
  }

  for (c1_i25 = 0; c1_i25 < 4; c1_i25++) {
    c1_u[c1_i25] = c1_b_inData[c1_i25];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_Qmod3InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc1_Qmod3InstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_Qmod3_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[11];
  c1_ResolvedFunctionInfo (*c1_b_info)[11];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i26;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[11])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mtimes";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[0].fileTimeLo = 1289519692U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context = "";
  (*c1_b_info)[1].name = "mrdivide";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[1].fileTimeLo = 1325124138U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 1319729966U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[2].name = "rdivide";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[2].fileTimeLo = 1286818844U;
  (*c1_b_info)[2].fileTimeHi = 0U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[3].name = "eml_div";
  (*c1_b_info)[3].dominantType = "double";
  (*c1_b_info)[3].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c1_b_info)[3].fileTimeLo = 1313347810U;
  (*c1_b_info)[3].fileTimeHi = 0U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  (*c1_b_info)[4].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[4].name = "eml_index_class";
  (*c1_b_info)[4].dominantType = "";
  (*c1_b_info)[4].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c1_b_info)[4].fileTimeLo = 1286818778U;
  (*c1_b_info)[4].fileTimeHi = 0U;
  (*c1_b_info)[4].mFileTimeLo = 0U;
  (*c1_b_info)[4].mFileTimeHi = 0U;
  (*c1_b_info)[5].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[5].name = "eml_scalar_eg";
  (*c1_b_info)[5].dominantType = "double";
  (*c1_b_info)[5].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c1_b_info)[5].fileTimeLo = 1286818796U;
  (*c1_b_info)[5].fileTimeHi = 0U;
  (*c1_b_info)[5].mFileTimeLo = 0U;
  (*c1_b_info)[5].mFileTimeHi = 0U;
  (*c1_b_info)[6].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[6].name = "eml_xgemm";
  (*c1_b_info)[6].dominantType = "int32";
  (*c1_b_info)[6].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c1_b_info)[6].fileTimeLo = 1299076772U;
  (*c1_b_info)[6].fileTimeHi = 0U;
  (*c1_b_info)[6].mFileTimeLo = 0U;
  (*c1_b_info)[6].mFileTimeHi = 0U;
  (*c1_b_info)[7].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c1_b_info)[7].name = "eml_blas_inline";
  (*c1_b_info)[7].dominantType = "";
  (*c1_b_info)[7].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c1_b_info)[7].fileTimeLo = 1299076768U;
  (*c1_b_info)[7].fileTimeHi = 0U;
  (*c1_b_info)[7].mFileTimeLo = 0U;
  (*c1_b_info)[7].mFileTimeHi = 0U;
  (*c1_b_info)[8].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  (*c1_b_info)[8].name = "mtimes";
  (*c1_b_info)[8].dominantType = "double";
  (*c1_b_info)[8].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[8].fileTimeLo = 1289519692U;
  (*c1_b_info)[8].fileTimeHi = 0U;
  (*c1_b_info)[8].mFileTimeLo = 0U;
  (*c1_b_info)[8].mFileTimeHi = 0U;
  (*c1_b_info)[9].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c1_b_info)[9].name = "eml_scalar_eg";
  (*c1_b_info)[9].dominantType = "double";
  (*c1_b_info)[9].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c1_b_info)[9].fileTimeLo = 1286818796U;
  (*c1_b_info)[9].fileTimeHi = 0U;
  (*c1_b_info)[9].mFileTimeLo = 0U;
  (*c1_b_info)[9].mFileTimeHi = 0U;
  (*c1_b_info)[10].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c1_b_info)[10].name = "eml_refblas_xgemm";
  (*c1_b_info)[10].dominantType = "int32";
  (*c1_b_info)[10].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c1_b_info)[10].fileTimeLo = 1299076774U;
  (*c1_b_info)[10].fileTimeHi = 0U;
  (*c1_b_info)[10].mFileTimeLo = 0U;
  (*c1_b_info)[10].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 11), FALSE);
  for (c1_i26 = 0; c1_i26 < 11; c1_i26++) {
    c1_r0 = &c1_info[c1_i26];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i26);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i26);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i26);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i26);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i26);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i26);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i26);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i26);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_eml_scalar_eg(SFc1_Qmod3InstanceStruct *chartInstance)
{
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc1_Qmod3InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_Qmod3InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i27;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i27, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i27;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc1_Qmod3InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_Qmod3InstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_Qmod3, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_is_active_c1_Qmod3),
    &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_Qmod3);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_Qmod3InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_Qmod3InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_Qmod3_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(535155125U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1422114278U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2771174324U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1516438552U);
}

mxArray *sf_c1_Qmod3_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("kuiPGMrkMBKrvGsj2ih49B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

static const mxArray *sf_get_sim_state_info_c1_Qmod3(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c1_Qmod3\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Qmod3_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Qmod3InstanceStruct *chartInstance;
    chartInstance = (SFc1_Qmod3InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_Qmod3MachineNumber_,
          1,
          1,
          1,
          6,
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
          init_script_number_translation(_Qmod3MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_Qmod3MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_Qmod3MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"w");
          _SFD_SET_DATA_PROPS(1,1,1,0,"k");
          _SFD_SET_DATA_PROPS(2,1,1,0,"m");
          _SFD_SET_DATA_PROPS(3,1,1,0,"g");
          _SFD_SET_DATA_PROPS(4,2,0,1,"y");
          _SFD_SET_DATA_PROPS(5,1,1,0,"R");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,144);
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
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c1_k;
          real_T *c1_m;
          real_T *c1_g;
          real_T (*c1_w)[4];
          real_T (*c1_y)[3];
          real_T (*c1_R)[9];
          c1_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
          c1_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_g = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_w = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_w);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_k);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_m);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_g);
          _SFD_SET_DATA_VALUE_PTR(4U, *c1_y);
          _SFD_SET_DATA_VALUE_PTR(5U, *c1_R);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_Qmod3MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "syZdJ3Ld1V1p9OrkdswK1D";
}

static void sf_opaque_initialize_c1_Qmod3(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_Qmod3InstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c1_Qmod3((SFc1_Qmod3InstanceStruct*) chartInstanceVar);
  initialize_c1_Qmod3((SFc1_Qmod3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_Qmod3(void *chartInstanceVar)
{
  enable_c1_Qmod3((SFc1_Qmod3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_Qmod3(void *chartInstanceVar)
{
  disable_c1_Qmod3((SFc1_Qmod3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_Qmod3(void *chartInstanceVar)
{
  sf_c1_Qmod3((SFc1_Qmod3InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_Qmod3(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_Qmod3((SFc1_Qmod3InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Qmod3();/* state var info */
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

extern void sf_internal_set_sim_state_c1_Qmod3(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Qmod3();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_Qmod3((SFc1_Qmod3InstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_Qmod3(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_Qmod3(S);
}

static void sf_opaque_set_sim_state_c1_Qmod3(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_Qmod3(S, st);
}

static void sf_opaque_terminate_c1_Qmod3(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Qmod3InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_Qmod3((SFc1_Qmod3InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Qmod3_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_Qmod3((SFc1_Qmod3InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Qmod3(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Qmod3((SFc1_Qmod3InstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_Qmod3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Qmod3_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(39176923U));
  ssSetChecksum1(S,(3935398190U));
  ssSetChecksum2(S,(2429259235U));
  ssSetChecksum3(S,(3916569858U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_Qmod3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Qmod3(SimStruct *S)
{
  SFc1_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc1_Qmod3InstanceStruct *)malloc(sizeof
    (SFc1_Qmod3InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_Qmod3InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_Qmod3;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_Qmod3;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_Qmod3;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_Qmod3;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_Qmod3;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_Qmod3;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_Qmod3;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_Qmod3;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Qmod3;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Qmod3;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_Qmod3;
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

void c1_Qmod3_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Qmod3(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Qmod3(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Qmod3(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Qmod3_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

/* Include files */

#include "blascompat32.h"
#include "Qmod3_sfun.h"
#include "c5_Qmod3.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Qmod3_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[13] = { "Ixx", "Iyy", "Izz", "Weta",
  "WetaT", "II", "nargin", "nargout", "Phi", "Theta", "Psi", "I", "y" };

/* Function Declarations */
static void initialize_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance);
static void initialize_params_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance);
static void enable_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance);
static void disable_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_Qmod3(SFc5_Qmod3InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_Qmod3(SFc5_Qmod3InstanceStruct
  *chartInstance);
static void set_sim_state_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance,
  const mxArray *c5_st);
static void finalize_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance);
static void sf_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance);
static void c5_chartstep_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance);
static void initSimStructsc5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_Qmod3InstanceStruct *chartInstance, const
  mxArray *c5_y, const char_T *c5_identifier, real_T c5_b_y[9]);
static void c5_b_emlrt_marshallIn(SFc5_Qmod3InstanceStruct *chartInstance, const
  mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[9]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn(SFc5_Qmod3InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_eml_scalar_eg(SFc5_Qmod3InstanceStruct *chartInstance);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_d_emlrt_marshallIn(SFc5_Qmod3InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_e_emlrt_marshallIn(SFc5_Qmod3InstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_Qmod3, const char_T *c5_identifier);
static uint8_T c5_f_emlrt_marshallIn(SFc5_Qmod3InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_Qmod3InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_Qmod3 = 0U;
}

static void initialize_params_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance)
{
}

static void enable_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_Qmod3(SFc5_Qmod3InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c5_Qmod3(SFc5_Qmod3InstanceStruct
  *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_u[9];
  const mxArray *c5_b_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T (*c5_d_y)[9];
  c5_d_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2), FALSE);
  for (c5_i0 = 0; c5_i0 < 9; c5_i0++) {
    c5_u[c5_i0] = (*c5_d_y)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_Qmod3;
  c5_b_u = c5_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance,
  const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[9];
  int32_T c5_i1;
  real_T (*c5_y)[9];
  c5_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)), "y",
                      c5_dv0);
  for (c5_i1 = 0; c5_i1 < 9; c5_i1++) {
    (*c5_y)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_Qmod3 = c5_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 1)), "is_active_c5_Qmod3");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_Qmod3(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance)
{
}

static void sf_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance)
{
  int32_T c5_i2;
  int32_T c5_i3;
  real_T *c5_Phi;
  real_T *c5_Theta;
  real_T *c5_Psi;
  real_T (*c5_I)[3];
  real_T (*c5_y)[9];
  c5_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c5_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_Phi, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_Theta, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_Psi, 2U);
  for (c5_i2 = 0; c5_i2 < 9; c5_i2++) {
    _SFD_DATA_RANGE_CHECK((*c5_y)[c5_i2], 3U);
  }

  for (c5_i3 = 0; c5_i3 < 3; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((*c5_I)[c5_i3], 4U);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_Qmod3(chartInstance);
  sf_debug_check_for_state_inconsistency(_Qmod3MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_chartstep_c5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_Phi;
  real_T c5_Theta;
  real_T c5_Psi;
  int32_T c5_i4;
  real_T c5_I[3];
  uint32_T c5_debug_family_var_map[13];
  real_T c5_Ixx;
  real_T c5_Iyy;
  real_T c5_Izz;
  real_T c5_Weta[9];
  real_T c5_WetaT[9];
  real_T c5_II[9];
  real_T c5_nargin = 4.0;
  real_T c5_nargout = 1.0;
  real_T c5_y[9];
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_a;
  real_T c5_b;
  real_T c5_b_y;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_n_x;
  real_T c5_b_a;
  real_T c5_b_b;
  real_T c5_c_y;
  int32_T c5_i5;
  real_T c5_u[9];
  const mxArray *c5_d_y = NULL;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  real_T c5_c_a[9];
  int32_T c5_i11;
  real_T c5_c_b[9];
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  real_T c5_e_y[9];
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
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  real_T *c5_b_Phi;
  real_T *c5_b_Theta;
  real_T *c5_b_Psi;
  real_T (*c5_f_y)[9];
  real_T (*c5_b_I)[3];
  c5_b_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c5_f_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_Phi;
  c5_b_hoistedGlobal = *c5_b_Theta;
  c5_c_hoistedGlobal = *c5_b_Psi;
  c5_Phi = c5_hoistedGlobal;
  c5_Theta = c5_b_hoistedGlobal;
  c5_Psi = c5_c_hoistedGlobal;
  for (c5_i4 = 0; c5_i4 < 3; c5_i4++) {
    c5_I[c5_i4] = (*c5_b_I)[c5_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c5_Ixx, 0U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Iyy, 1U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Izz, 2U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_Weta, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_WetaT, 4U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_II, 5U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_Phi, 8U, c5_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Theta, 9U, c5_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Psi, 10U, c5_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_I, 11U, c5_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c5_y, 12U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_Ixx = c5_I[0];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_Iyy = c5_I[1];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_Izz = c5_I[2];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 10);
  c5_x = c5_Theta;
  c5_b_x = c5_x;
  c5_b_x = muDoubleScalarSin(c5_b_x);
  c5_c_x = c5_Phi;
  c5_d_x = c5_c_x;
  c5_d_x = muDoubleScalarCos(c5_d_x);
  c5_e_x = c5_Theta;
  c5_f_x = c5_e_x;
  c5_f_x = muDoubleScalarCos(c5_f_x);
  c5_g_x = c5_Phi;
  c5_h_x = c5_g_x;
  c5_h_x = muDoubleScalarSin(c5_h_x);
  c5_a = c5_f_x;
  c5_b = c5_h_x;
  c5_b_y = c5_a * c5_b;
  c5_i_x = c5_Phi;
  c5_j_x = c5_i_x;
  c5_j_x = muDoubleScalarSin(c5_j_x);
  c5_k_x = c5_Theta;
  c5_l_x = c5_k_x;
  c5_l_x = muDoubleScalarCos(c5_l_x);
  c5_m_x = c5_Phi;
  c5_n_x = c5_m_x;
  c5_n_x = muDoubleScalarCos(c5_n_x);
  c5_b_a = c5_l_x;
  c5_b_b = c5_n_x;
  c5_c_y = c5_b_a * c5_b_b;
  c5_Weta[0] = 1.0;
  c5_Weta[3] = 0.0;
  c5_Weta[6] = -c5_b_x;
  c5_Weta[1] = 0.0;
  c5_Weta[4] = c5_d_x;
  c5_Weta[7] = c5_b_y;
  c5_Weta[2] = 0.0;
  c5_Weta[5] = -c5_j_x;
  c5_Weta[8] = c5_c_y;
  sf_mex_printf("%s =\\n", "Weta");
  for (c5_i5 = 0; c5_i5 < 9; c5_i5++) {
    c5_u[c5_i5] = c5_Weta[c5_i5];
  }

  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_call_debug("disp", 0U, 1U, 14, c5_d_y);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 14);
  c5_i6 = 0;
  for (c5_i7 = 0; c5_i7 < 3; c5_i7++) {
    c5_i8 = 0;
    for (c5_i9 = 0; c5_i9 < 3; c5_i9++) {
      c5_WetaT[c5_i9 + c5_i6] = c5_Weta[c5_i8 + c5_i7];
      c5_i8 += 3;
    }

    c5_i6 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 16);
  c5_II[0] = c5_Ixx;
  c5_II[3] = 0.0;
  c5_II[6] = 0.0;
  c5_II[1] = 0.0;
  c5_II[4] = c5_Iyy;
  c5_II[7] = 0.0;
  c5_II[2] = 0.0;
  c5_II[5] = 0.0;
  c5_II[8] = c5_Izz;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
  for (c5_i10 = 0; c5_i10 < 9; c5_i10++) {
    c5_c_a[c5_i10] = c5_WetaT[c5_i10];
  }

  for (c5_i11 = 0; c5_i11 < 9; c5_i11++) {
    c5_c_b[c5_i11] = c5_II[c5_i11];
  }

  c5_eml_scalar_eg(chartInstance);
  c5_eml_scalar_eg(chartInstance);
  for (c5_i12 = 0; c5_i12 < 3; c5_i12++) {
    c5_i13 = 0;
    for (c5_i14 = 0; c5_i14 < 3; c5_i14++) {
      c5_e_y[c5_i13 + c5_i12] = 0.0;
      c5_i15 = 0;
      for (c5_i16 = 0; c5_i16 < 3; c5_i16++) {
        c5_e_y[c5_i13 + c5_i12] += c5_c_a[c5_i15 + c5_i12] * c5_c_b[c5_i16 +
          c5_i13];
        c5_i15 += 3;
      }

      c5_i13 += 3;
    }
  }

  for (c5_i17 = 0; c5_i17 < 9; c5_i17++) {
    c5_c_b[c5_i17] = c5_Weta[c5_i17];
  }

  c5_eml_scalar_eg(chartInstance);
  c5_eml_scalar_eg(chartInstance);
  for (c5_i18 = 0; c5_i18 < 9; c5_i18++) {
    c5_y[c5_i18] = 0.0;
  }

  for (c5_i19 = 0; c5_i19 < 9; c5_i19++) {
    c5_y[c5_i19] = 0.0;
  }

  for (c5_i20 = 0; c5_i20 < 9; c5_i20++) {
    c5_c_a[c5_i20] = c5_y[c5_i20];
  }

  for (c5_i21 = 0; c5_i21 < 9; c5_i21++) {
    c5_y[c5_i21] = c5_c_a[c5_i21];
  }

  for (c5_i22 = 0; c5_i22 < 9; c5_i22++) {
    c5_c_a[c5_i22] = c5_y[c5_i22];
  }

  for (c5_i23 = 0; c5_i23 < 9; c5_i23++) {
    c5_y[c5_i23] = c5_c_a[c5_i23];
  }

  for (c5_i24 = 0; c5_i24 < 3; c5_i24++) {
    c5_i25 = 0;
    for (c5_i26 = 0; c5_i26 < 3; c5_i26++) {
      c5_y[c5_i25 + c5_i24] = 0.0;
      c5_i27 = 0;
      for (c5_i28 = 0; c5_i28 < 3; c5_i28++) {
        c5_y[c5_i25 + c5_i24] += c5_e_y[c5_i27 + c5_i24] * c5_c_b[c5_i28 +
          c5_i25];
        c5_i27 += 3;
      }

      c5_i25 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -18);
  sf_debug_symbol_scope_pop();
  for (c5_i29 = 0; c5_i29 < 9; c5_i29++) {
    (*c5_f_y)[c5_i29] = c5_y[c5_i29];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_Qmod3(SFc5_Qmod3InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  real_T c5_b_inData[9];
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  real_T c5_u[9];
  const mxArray *c5_y = NULL;
  SFc5_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc5_Qmod3InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i30 = 0;
  for (c5_i31 = 0; c5_i31 < 3; c5_i31++) {
    for (c5_i32 = 0; c5_i32 < 3; c5_i32++) {
      c5_b_inData[c5_i32 + c5_i30] = (*(real_T (*)[9])c5_inData)[c5_i32 + c5_i30];
    }

    c5_i30 += 3;
  }

  c5_i33 = 0;
  for (c5_i34 = 0; c5_i34 < 3; c5_i34++) {
    for (c5_i35 = 0; c5_i35 < 3; c5_i35++) {
      c5_u[c5_i35 + c5_i33] = c5_b_inData[c5_i35 + c5_i33];
    }

    c5_i33 += 3;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_Qmod3InstanceStruct *chartInstance, const
  mxArray *c5_y, const char_T *c5_identifier, real_T c5_b_y[9])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_y), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_y);
}

static void c5_b_emlrt_marshallIn(SFc5_Qmod3InstanceStruct *chartInstance, const
  mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[9])
{
  real_T c5_dv1[9];
  int32_T c5_i36;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c5_i36 = 0; c5_i36 < 9; c5_i36++) {
    c5_y[c5_i36] = c5_dv1[c5_i36];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_y;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[9];
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  SFc5_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc5_Qmod3InstanceStruct *)chartInstanceVoid;
  c5_y = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_y), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_y);
  c5_i37 = 0;
  for (c5_i38 = 0; c5_i38 < 3; c5_i38++) {
    for (c5_i39 = 0; c5_i39 < 3; c5_i39++) {
      (*(real_T (*)[9])c5_outData)[c5_i39 + c5_i37] = c5_b_y[c5_i39 + c5_i37];
    }

    c5_i37 += 3;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i40;
  real_T c5_b_inData[3];
  int32_T c5_i41;
  real_T c5_u[3];
  const mxArray *c5_y = NULL;
  SFc5_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc5_Qmod3InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i40 = 0; c5_i40 < 3; c5_i40++) {
    c5_b_inData[c5_i40] = (*(real_T (*)[3])c5_inData)[c5_i40];
  }

  for (c5_i41 = 0; c5_i41 < 3; c5_i41++) {
    c5_u[c5_i41] = c5_b_inData[c5_i41];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc5_Qmod3InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_Qmod3InstanceStruct *chartInstance,
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
  SFc5_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc5_Qmod3InstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_Qmod3_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[12];
  c5_ResolvedFunctionInfo (*c5_b_info)[12];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i42;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_b_info = (c5_ResolvedFunctionInfo (*)[12])c5_info;
  (*c5_b_info)[0].context = "";
  (*c5_b_info)[0].name = "sin";
  (*c5_b_info)[0].dominantType = "double";
  (*c5_b_info)[0].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c5_b_info)[0].fileTimeLo = 1286818750U;
  (*c5_b_info)[0].fileTimeHi = 0U;
  (*c5_b_info)[0].mFileTimeLo = 0U;
  (*c5_b_info)[0].mFileTimeHi = 0U;
  (*c5_b_info)[1].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c5_b_info)[1].name = "eml_scalar_sin";
  (*c5_b_info)[1].dominantType = "double";
  (*c5_b_info)[1].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c5_b_info)[1].fileTimeLo = 1286818736U;
  (*c5_b_info)[1].fileTimeHi = 0U;
  (*c5_b_info)[1].mFileTimeLo = 0U;
  (*c5_b_info)[1].mFileTimeHi = 0U;
  (*c5_b_info)[2].context = "";
  (*c5_b_info)[2].name = "cos";
  (*c5_b_info)[2].dominantType = "double";
  (*c5_b_info)[2].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c5_b_info)[2].fileTimeLo = 1286818706U;
  (*c5_b_info)[2].fileTimeHi = 0U;
  (*c5_b_info)[2].mFileTimeLo = 0U;
  (*c5_b_info)[2].mFileTimeHi = 0U;
  (*c5_b_info)[3].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c5_b_info)[3].name = "eml_scalar_cos";
  (*c5_b_info)[3].dominantType = "double";
  (*c5_b_info)[3].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c5_b_info)[3].fileTimeLo = 1286818722U;
  (*c5_b_info)[3].fileTimeHi = 0U;
  (*c5_b_info)[3].mFileTimeLo = 0U;
  (*c5_b_info)[3].mFileTimeHi = 0U;
  (*c5_b_info)[4].context = "";
  (*c5_b_info)[4].name = "mtimes";
  (*c5_b_info)[4].dominantType = "double";
  (*c5_b_info)[4].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[4].fileTimeLo = 1289519692U;
  (*c5_b_info)[4].fileTimeHi = 0U;
  (*c5_b_info)[4].mFileTimeLo = 0U;
  (*c5_b_info)[4].mFileTimeHi = 0U;
  (*c5_b_info)[5].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[5].name = "eml_index_class";
  (*c5_b_info)[5].dominantType = "";
  (*c5_b_info)[5].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c5_b_info)[5].fileTimeLo = 1286818778U;
  (*c5_b_info)[5].fileTimeHi = 0U;
  (*c5_b_info)[5].mFileTimeLo = 0U;
  (*c5_b_info)[5].mFileTimeHi = 0U;
  (*c5_b_info)[6].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[6].name = "eml_scalar_eg";
  (*c5_b_info)[6].dominantType = "double";
  (*c5_b_info)[6].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c5_b_info)[6].fileTimeLo = 1286818796U;
  (*c5_b_info)[6].fileTimeHi = 0U;
  (*c5_b_info)[6].mFileTimeLo = 0U;
  (*c5_b_info)[6].mFileTimeHi = 0U;
  (*c5_b_info)[7].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[7].name = "eml_xgemm";
  (*c5_b_info)[7].dominantType = "int32";
  (*c5_b_info)[7].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c5_b_info)[7].fileTimeLo = 1299076772U;
  (*c5_b_info)[7].fileTimeHi = 0U;
  (*c5_b_info)[7].mFileTimeLo = 0U;
  (*c5_b_info)[7].mFileTimeHi = 0U;
  (*c5_b_info)[8].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c5_b_info)[8].name = "eml_blas_inline";
  (*c5_b_info)[8].dominantType = "";
  (*c5_b_info)[8].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c5_b_info)[8].fileTimeLo = 1299076768U;
  (*c5_b_info)[8].fileTimeHi = 0U;
  (*c5_b_info)[8].mFileTimeLo = 0U;
  (*c5_b_info)[8].mFileTimeHi = 0U;
  (*c5_b_info)[9].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  (*c5_b_info)[9].name = "mtimes";
  (*c5_b_info)[9].dominantType = "double";
  (*c5_b_info)[9].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[9].fileTimeLo = 1289519692U;
  (*c5_b_info)[9].fileTimeHi = 0U;
  (*c5_b_info)[9].mFileTimeLo = 0U;
  (*c5_b_info)[9].mFileTimeHi = 0U;
  (*c5_b_info)[10].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c5_b_info)[10].name = "eml_scalar_eg";
  (*c5_b_info)[10].dominantType = "double";
  (*c5_b_info)[10].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c5_b_info)[10].fileTimeLo = 1286818796U;
  (*c5_b_info)[10].fileTimeHi = 0U;
  (*c5_b_info)[10].mFileTimeLo = 0U;
  (*c5_b_info)[10].mFileTimeHi = 0U;
  (*c5_b_info)[11].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c5_b_info)[11].name = "eml_refblas_xgemm";
  (*c5_b_info)[11].dominantType = "int32";
  (*c5_b_info)[11].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c5_b_info)[11].fileTimeLo = 1299076774U;
  (*c5_b_info)[11].fileTimeHi = 0U;
  (*c5_b_info)[11].mFileTimeLo = 0U;
  (*c5_b_info)[11].mFileTimeHi = 0U;
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 12), FALSE);
  for (c5_i42 = 0; c5_i42 < 12; c5_i42++) {
    c5_r0 = &c5_info[c5_i42];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i42);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i42);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i42);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i42);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i42);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i42);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i42);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i42);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_eml_scalar_eg(SFc5_Qmod3InstanceStruct *chartInstance)
{
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc5_Qmod3InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_d_emlrt_marshallIn(SFc5_Qmod3InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i43;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i43, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i43;
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
  SFc5_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc5_Qmod3InstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_Qmod3InstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_Qmod3, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_is_active_c5_Qmod3),
    &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_Qmod3);
  return c5_y;
}

static uint8_T c5_f_emlrt_marshallIn(SFc5_Qmod3InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_Qmod3InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_Qmod3_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4081690737U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4145145227U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3979680369U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1224487349U);
}

mxArray *sf_c5_Qmod3_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("3Sy1vgASNBb8B09UmFtRvD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      pr[1] = (double)(3);
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

static const mxArray *sf_get_sim_state_info_c5_Qmod3(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c5_Qmod3\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_Qmod3_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_Qmod3InstanceStruct *chartInstance;
    chartInstance = (SFc5_Qmod3InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_Qmod3MachineNumber_,
          5,
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
          init_script_number_translation(_Qmod3MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_Qmod3MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_Qmod3MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Phi");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Theta");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Psi");
          _SFD_SET_DATA_PROPS(3,2,0,1,"y");
          _SFD_SET_DATA_PROPS(4,1,1,0,"I");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,266);
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
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c5_Phi;
          real_T *c5_Theta;
          real_T *c5_Psi;
          real_T (*c5_y)[9];
          real_T (*c5_I)[3];
          c5_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c5_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_Phi);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_Theta);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_Psi);
          _SFD_SET_DATA_VALUE_PTR(3U, *c5_y);
          _SFD_SET_DATA_VALUE_PTR(4U, *c5_I);
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
  return "9BbAXrqBA7vAEV6OM6M3UD";
}

static void sf_opaque_initialize_c5_Qmod3(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_Qmod3InstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c5_Qmod3((SFc5_Qmod3InstanceStruct*) chartInstanceVar);
  initialize_c5_Qmod3((SFc5_Qmod3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_Qmod3(void *chartInstanceVar)
{
  enable_c5_Qmod3((SFc5_Qmod3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_Qmod3(void *chartInstanceVar)
{
  disable_c5_Qmod3((SFc5_Qmod3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_Qmod3(void *chartInstanceVar)
{
  sf_c5_Qmod3((SFc5_Qmod3InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_Qmod3(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_Qmod3((SFc5_Qmod3InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_Qmod3();/* state var info */
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

extern void sf_internal_set_sim_state_c5_Qmod3(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_Qmod3();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_Qmod3((SFc5_Qmod3InstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_Qmod3(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_Qmod3(S);
}

static void sf_opaque_set_sim_state_c5_Qmod3(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c5_Qmod3(S, st);
}

static void sf_opaque_terminate_c5_Qmod3(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_Qmod3InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_Qmod3((SFc5_Qmod3InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Qmod3_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_Qmod3((SFc5_Qmod3InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_Qmod3(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_Qmod3((SFc5_Qmod3InstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_Qmod3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Qmod3_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1691162629U));
  ssSetChecksum1(S,(3782524655U));
  ssSetChecksum2(S,(1856647195U));
  ssSetChecksum3(S,(3096222914U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_Qmod3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_Qmod3(SimStruct *S)
{
  SFc5_Qmod3InstanceStruct *chartInstance;
  chartInstance = (SFc5_Qmod3InstanceStruct *)malloc(sizeof
    (SFc5_Qmod3InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_Qmod3InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_Qmod3;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_Qmod3;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_Qmod3;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_Qmod3;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_Qmod3;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_Qmod3;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_Qmod3;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_Qmod3;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_Qmod3;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_Qmod3;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_Qmod3;
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

void c5_Qmod3_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_Qmod3(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_Qmod3(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_Qmod3(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_Qmod3_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

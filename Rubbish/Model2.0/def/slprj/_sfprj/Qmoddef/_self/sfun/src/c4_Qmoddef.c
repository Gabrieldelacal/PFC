/* Include files */

#include "blascompat32.h"
#include "Qmoddef_sfun.h"
#include "c4_Qmoddef.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Qmoddef_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[13] = { "Ixx", "Iyy", "Izz", "Weta",
  "WetaT", "II", "nargin", "nargout", "Phi", "Theta", "Psi", "I", "J" };

/* Function Declarations */
static void initialize_c4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance);
static void initialize_params_c4_Qmoddef(SFc4_QmoddefInstanceStruct
  *chartInstance);
static void enable_c4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance);
static void disable_c4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_Qmoddef(SFc4_QmoddefInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_Qmoddef(SFc4_QmoddefInstanceStruct
  *chartInstance);
static void set_sim_state_c4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance,
  const mxArray *c4_st);
static void finalize_c4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance);
static void sf_c4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance);
static void c4_chartstep_c4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance);
static void initSimStructsc4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_QmoddefInstanceStruct *chartInstance, const
  mxArray *c4_J, const char_T *c4_identifier, real_T c4_y[9]);
static void c4_b_emlrt_marshallIn(SFc4_QmoddefInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[9]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_QmoddefInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_eml_scalar_eg(SFc4_QmoddefInstanceStruct *chartInstance);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_d_emlrt_marshallIn(SFc4_QmoddefInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_e_emlrt_marshallIn(SFc4_QmoddefInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_Qmoddef, const char_T *c4_identifier);
static uint8_T c4_f_emlrt_marshallIn(SFc4_QmoddefInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_QmoddefInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_Qmoddef = 0U;
}

static void initialize_params_c4_Qmoddef(SFc4_QmoddefInstanceStruct
  *chartInstance)
{
}

static void enable_c4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_Qmoddef(SFc4_QmoddefInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c4_Qmoddef(SFc4_QmoddefInstanceStruct
  *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[9];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T (*c4_J)[9];
  c4_J = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2), FALSE);
  for (c4_i0 = 0; c4_i0 < 9; c4_i0++) {
    c4_u[c4_i0] = (*c4_J)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_Qmoddef;
  c4_b_u = c4_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance,
  const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[9];
  int32_T c4_i1;
  real_T (*c4_J)[9];
  c4_J = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "J",
                      c4_dv0);
  for (c4_i1 = 0; c4_i1 < 9; c4_i1++) {
    (*c4_J)[c4_i1] = c4_dv0[c4_i1];
  }

  chartInstance->c4_is_active_c4_Qmoddef = c4_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 1)), "is_active_c4_Qmoddef");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_Qmoddef(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance)
{
}

static void sf_c4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance)
{
  int32_T c4_i2;
  int32_T c4_i3;
  real_T *c4_Phi;
  real_T *c4_Theta;
  real_T *c4_Psi;
  real_T (*c4_I)[3];
  real_T (*c4_J)[9];
  c4_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c4_J = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_Phi, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_Theta, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_Psi, 2U);
  for (c4_i2 = 0; c4_i2 < 9; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((*c4_J)[c4_i2], 3U);
  }

  for (c4_i3 = 0; c4_i3 < 3; c4_i3++) {
    _SFD_DATA_RANGE_CHECK((*c4_I)[c4_i3], 4U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_Qmoddef(chartInstance);
  sf_debug_check_for_state_inconsistency(_QmoddefMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_chartstep_c4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_Phi;
  real_T c4_Theta;
  real_T c4_Psi;
  int32_T c4_i4;
  real_T c4_I[3];
  uint32_T c4_debug_family_var_map[13];
  real_T c4_Ixx;
  real_T c4_Iyy;
  real_T c4_Izz;
  real_T c4_Weta[9];
  real_T c4_WetaT[9];
  real_T c4_II[9];
  real_T c4_nargin = 4.0;
  real_T c4_nargout = 1.0;
  real_T c4_J[9];
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_a;
  real_T c4_b;
  real_T c4_y;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_k_x;
  real_T c4_l_x;
  real_T c4_m_x;
  real_T c4_n_x;
  real_T c4_b_a;
  real_T c4_b_b;
  real_T c4_b_y;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  real_T c4_c_a[9];
  int32_T c4_i10;
  real_T c4_c_b[9];
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  real_T c4_c_y[9];
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  real_T *c4_b_Phi;
  real_T *c4_b_Theta;
  real_T *c4_b_Psi;
  real_T (*c4_b_J)[9];
  real_T (*c4_b_I)[3];
  c4_b_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c4_b_J = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_Phi;
  c4_b_hoistedGlobal = *c4_b_Theta;
  c4_c_hoistedGlobal = *c4_b_Psi;
  c4_Phi = c4_hoistedGlobal;
  c4_Theta = c4_b_hoistedGlobal;
  c4_Psi = c4_c_hoistedGlobal;
  for (c4_i4 = 0; c4_i4 < 3; c4_i4++) {
    c4_I[c4_i4] = (*c4_b_I)[c4_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c4_Ixx, 0U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_Iyy, 1U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_Izz, 2U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c4_Weta, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c4_WetaT, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c4_II, 5U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 6U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 7U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_Phi, 8U, c4_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_Theta, 9U, c4_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_Psi, 10U, c4_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c4_I, 11U, c4_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c4_J, 12U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_Ixx = c4_I[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  c4_Iyy = c4_I[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  c4_Izz = c4_I[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_x = c4_Theta;
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarSin(c4_b_x);
  c4_c_x = c4_Phi;
  c4_d_x = c4_c_x;
  c4_d_x = muDoubleScalarCos(c4_d_x);
  c4_e_x = c4_Theta;
  c4_f_x = c4_e_x;
  c4_f_x = muDoubleScalarCos(c4_f_x);
  c4_g_x = c4_Phi;
  c4_h_x = c4_g_x;
  c4_h_x = muDoubleScalarSin(c4_h_x);
  c4_a = c4_f_x;
  c4_b = c4_h_x;
  c4_y = c4_a * c4_b;
  c4_i_x = c4_Phi;
  c4_j_x = c4_i_x;
  c4_j_x = muDoubleScalarSin(c4_j_x);
  c4_k_x = c4_Theta;
  c4_l_x = c4_k_x;
  c4_l_x = muDoubleScalarCos(c4_l_x);
  c4_m_x = c4_Phi;
  c4_n_x = c4_m_x;
  c4_n_x = muDoubleScalarCos(c4_n_x);
  c4_b_a = c4_l_x;
  c4_b_b = c4_n_x;
  c4_b_y = c4_b_a * c4_b_b;
  c4_Weta[0] = 1.0;
  c4_Weta[3] = 0.0;
  c4_Weta[6] = -c4_b_x;
  c4_Weta[1] = 0.0;
  c4_Weta[4] = c4_d_x;
  c4_Weta[7] = c4_y;
  c4_Weta[2] = 0.0;
  c4_Weta[5] = -c4_j_x;
  c4_Weta[8] = c4_b_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  c4_i5 = 0;
  for (c4_i6 = 0; c4_i6 < 3; c4_i6++) {
    c4_i7 = 0;
    for (c4_i8 = 0; c4_i8 < 3; c4_i8++) {
      c4_WetaT[c4_i8 + c4_i5] = c4_Weta[c4_i7 + c4_i6];
      c4_i7 += 3;
    }

    c4_i5 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  c4_II[0] = c4_Ixx;
  c4_II[3] = 0.0;
  c4_II[6] = 0.0;
  c4_II[1] = 0.0;
  c4_II[4] = c4_Iyy;
  c4_II[7] = 0.0;
  c4_II[2] = 0.0;
  c4_II[5] = 0.0;
  c4_II[8] = c4_Izz;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
  for (c4_i9 = 0; c4_i9 < 9; c4_i9++) {
    c4_c_a[c4_i9] = c4_WetaT[c4_i9];
  }

  for (c4_i10 = 0; c4_i10 < 9; c4_i10++) {
    c4_c_b[c4_i10] = c4_II[c4_i10];
  }

  c4_eml_scalar_eg(chartInstance);
  c4_eml_scalar_eg(chartInstance);
  for (c4_i11 = 0; c4_i11 < 3; c4_i11++) {
    c4_i12 = 0;
    for (c4_i13 = 0; c4_i13 < 3; c4_i13++) {
      c4_c_y[c4_i12 + c4_i11] = 0.0;
      c4_i14 = 0;
      for (c4_i15 = 0; c4_i15 < 3; c4_i15++) {
        c4_c_y[c4_i12 + c4_i11] += c4_c_a[c4_i14 + c4_i11] * c4_c_b[c4_i15 +
          c4_i12];
        c4_i14 += 3;
      }

      c4_i12 += 3;
    }
  }

  for (c4_i16 = 0; c4_i16 < 9; c4_i16++) {
    c4_c_b[c4_i16] = c4_Weta[c4_i16];
  }

  c4_eml_scalar_eg(chartInstance);
  c4_eml_scalar_eg(chartInstance);
  for (c4_i17 = 0; c4_i17 < 9; c4_i17++) {
    c4_J[c4_i17] = 0.0;
  }

  for (c4_i18 = 0; c4_i18 < 9; c4_i18++) {
    c4_J[c4_i18] = 0.0;
  }

  for (c4_i19 = 0; c4_i19 < 9; c4_i19++) {
    c4_c_a[c4_i19] = c4_J[c4_i19];
  }

  for (c4_i20 = 0; c4_i20 < 9; c4_i20++) {
    c4_J[c4_i20] = c4_c_a[c4_i20];
  }

  for (c4_i21 = 0; c4_i21 < 9; c4_i21++) {
    c4_c_a[c4_i21] = c4_J[c4_i21];
  }

  for (c4_i22 = 0; c4_i22 < 9; c4_i22++) {
    c4_J[c4_i22] = c4_c_a[c4_i22];
  }

  for (c4_i23 = 0; c4_i23 < 3; c4_i23++) {
    c4_i24 = 0;
    for (c4_i25 = 0; c4_i25 < 3; c4_i25++) {
      c4_J[c4_i24 + c4_i23] = 0.0;
      c4_i26 = 0;
      for (c4_i27 = 0; c4_i27 < 3; c4_i27++) {
        c4_J[c4_i24 + c4_i23] += c4_c_y[c4_i26 + c4_i23] * c4_c_b[c4_i27 +
          c4_i24];
        c4_i26 += 3;
      }

      c4_i24 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -16);
  sf_debug_symbol_scope_pop();
  for (c4_i28 = 0; c4_i28 < 9; c4_i28++) {
    (*c4_b_J)[c4_i28] = c4_J[c4_i28];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_Qmoddef(SFc4_QmoddefInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i29;
  int32_T c4_i30;
  int32_T c4_i31;
  real_T c4_b_inData[9];
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  real_T c4_u[9];
  const mxArray *c4_y = NULL;
  SFc4_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc4_QmoddefInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i29 = 0;
  for (c4_i30 = 0; c4_i30 < 3; c4_i30++) {
    for (c4_i31 = 0; c4_i31 < 3; c4_i31++) {
      c4_b_inData[c4_i31 + c4_i29] = (*(real_T (*)[9])c4_inData)[c4_i31 + c4_i29];
    }

    c4_i29 += 3;
  }

  c4_i32 = 0;
  for (c4_i33 = 0; c4_i33 < 3; c4_i33++) {
    for (c4_i34 = 0; c4_i34 < 3; c4_i34++) {
      c4_u[c4_i34 + c4_i32] = c4_b_inData[c4_i34 + c4_i32];
    }

    c4_i32 += 3;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_QmoddefInstanceStruct *chartInstance, const
  mxArray *c4_J, const char_T *c4_identifier, real_T c4_y[9])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_J), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_J);
}

static void c4_b_emlrt_marshallIn(SFc4_QmoddefInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[9])
{
  real_T c4_dv1[9];
  int32_T c4_i35;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c4_i35 = 0; c4_i35 < 9; c4_i35++) {
    c4_y[c4_i35] = c4_dv1[c4_i35];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_J;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[9];
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  SFc4_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc4_QmoddefInstanceStruct *)chartInstanceVoid;
  c4_J = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_J), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_J);
  c4_i36 = 0;
  for (c4_i37 = 0; c4_i37 < 3; c4_i37++) {
    for (c4_i38 = 0; c4_i38 < 3; c4_i38++) {
      (*(real_T (*)[9])c4_outData)[c4_i38 + c4_i36] = c4_y[c4_i38 + c4_i36];
    }

    c4_i36 += 3;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i39;
  real_T c4_b_inData[3];
  int32_T c4_i40;
  real_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc4_QmoddefInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i39 = 0; c4_i39 < 3; c4_i39++) {
    c4_b_inData[c4_i39] = (*(real_T (*)[3])c4_inData)[c4_i39];
  }

  for (c4_i40 = 0; c4_i40 < 3; c4_i40++) {
    c4_u[c4_i40] = c4_b_inData[c4_i40];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc4_QmoddefInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_QmoddefInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc4_QmoddefInstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_Qmoddef_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[12];
  c4_ResolvedFunctionInfo (*c4_b_info)[12];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i41;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[12])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "sin";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c4_b_info)[0].fileTimeLo = 1286818750U;
  (*c4_b_info)[0].fileTimeHi = 0U;
  (*c4_b_info)[0].mFileTimeLo = 0U;
  (*c4_b_info)[0].mFileTimeHi = 0U;
  (*c4_b_info)[1].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c4_b_info)[1].name = "eml_scalar_sin";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c4_b_info)[1].fileTimeLo = 1286818736U;
  (*c4_b_info)[1].fileTimeHi = 0U;
  (*c4_b_info)[1].mFileTimeLo = 0U;
  (*c4_b_info)[1].mFileTimeHi = 0U;
  (*c4_b_info)[2].context = "";
  (*c4_b_info)[2].name = "cos";
  (*c4_b_info)[2].dominantType = "double";
  (*c4_b_info)[2].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c4_b_info)[2].fileTimeLo = 1286818706U;
  (*c4_b_info)[2].fileTimeHi = 0U;
  (*c4_b_info)[2].mFileTimeLo = 0U;
  (*c4_b_info)[2].mFileTimeHi = 0U;
  (*c4_b_info)[3].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c4_b_info)[3].name = "eml_scalar_cos";
  (*c4_b_info)[3].dominantType = "double";
  (*c4_b_info)[3].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c4_b_info)[3].fileTimeLo = 1286818722U;
  (*c4_b_info)[3].fileTimeHi = 0U;
  (*c4_b_info)[3].mFileTimeLo = 0U;
  (*c4_b_info)[3].mFileTimeHi = 0U;
  (*c4_b_info)[4].context = "";
  (*c4_b_info)[4].name = "mtimes";
  (*c4_b_info)[4].dominantType = "double";
  (*c4_b_info)[4].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[4].fileTimeLo = 1289519692U;
  (*c4_b_info)[4].fileTimeHi = 0U;
  (*c4_b_info)[4].mFileTimeLo = 0U;
  (*c4_b_info)[4].mFileTimeHi = 0U;
  (*c4_b_info)[5].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[5].name = "eml_index_class";
  (*c4_b_info)[5].dominantType = "";
  (*c4_b_info)[5].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c4_b_info)[5].fileTimeLo = 1286818778U;
  (*c4_b_info)[5].fileTimeHi = 0U;
  (*c4_b_info)[5].mFileTimeLo = 0U;
  (*c4_b_info)[5].mFileTimeHi = 0U;
  (*c4_b_info)[6].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[6].name = "eml_scalar_eg";
  (*c4_b_info)[6].dominantType = "double";
  (*c4_b_info)[6].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c4_b_info)[6].fileTimeLo = 1286818796U;
  (*c4_b_info)[6].fileTimeHi = 0U;
  (*c4_b_info)[6].mFileTimeLo = 0U;
  (*c4_b_info)[6].mFileTimeHi = 0U;
  (*c4_b_info)[7].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[7].name = "eml_xgemm";
  (*c4_b_info)[7].dominantType = "int32";
  (*c4_b_info)[7].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c4_b_info)[7].fileTimeLo = 1299076772U;
  (*c4_b_info)[7].fileTimeHi = 0U;
  (*c4_b_info)[7].mFileTimeLo = 0U;
  (*c4_b_info)[7].mFileTimeHi = 0U;
  (*c4_b_info)[8].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c4_b_info)[8].name = "eml_blas_inline";
  (*c4_b_info)[8].dominantType = "";
  (*c4_b_info)[8].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c4_b_info)[8].fileTimeLo = 1299076768U;
  (*c4_b_info)[8].fileTimeHi = 0U;
  (*c4_b_info)[8].mFileTimeLo = 0U;
  (*c4_b_info)[8].mFileTimeHi = 0U;
  (*c4_b_info)[9].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  (*c4_b_info)[9].name = "mtimes";
  (*c4_b_info)[9].dominantType = "double";
  (*c4_b_info)[9].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[9].fileTimeLo = 1289519692U;
  (*c4_b_info)[9].fileTimeHi = 0U;
  (*c4_b_info)[9].mFileTimeLo = 0U;
  (*c4_b_info)[9].mFileTimeHi = 0U;
  (*c4_b_info)[10].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c4_b_info)[10].name = "eml_scalar_eg";
  (*c4_b_info)[10].dominantType = "double";
  (*c4_b_info)[10].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c4_b_info)[10].fileTimeLo = 1286818796U;
  (*c4_b_info)[10].fileTimeHi = 0U;
  (*c4_b_info)[10].mFileTimeLo = 0U;
  (*c4_b_info)[10].mFileTimeHi = 0U;
  (*c4_b_info)[11].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c4_b_info)[11].name = "eml_refblas_xgemm";
  (*c4_b_info)[11].dominantType = "int32";
  (*c4_b_info)[11].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c4_b_info)[11].fileTimeLo = 1299076774U;
  (*c4_b_info)[11].fileTimeHi = 0U;
  (*c4_b_info)[11].mFileTimeLo = 0U;
  (*c4_b_info)[11].mFileTimeHi = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 12), FALSE);
  for (c4_i41 = 0; c4_i41 < 12; c4_i41++) {
    c4_r0 = &c4_info[c4_i41];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i41);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i41);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i41);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i41);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i41);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i41);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i41);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i41);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_eml_scalar_eg(SFc4_QmoddefInstanceStruct *chartInstance)
{
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc4_QmoddefInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_d_emlrt_marshallIn(SFc4_QmoddefInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i42;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i42, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i42;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc4_QmoddefInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_QmoddefInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_Qmoddef, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_Qmoddef), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_Qmoddef);
  return c4_y;
}

static uint8_T c4_f_emlrt_marshallIn(SFc4_QmoddefInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_QmoddefInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_Qmoddef_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(271382995U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(23644944U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3563002163U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2700855055U);
}

mxArray *sf_c4_Qmoddef_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("RF4dl8MxuTG0AVE78lBQi");
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

static const mxArray *sf_get_sim_state_info_c4_Qmoddef(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"J\",},{M[8],M[0],T\"is_active_c4_Qmoddef\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_Qmoddef_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_QmoddefInstanceStruct *chartInstance;
    chartInstance = (SFc4_QmoddefInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_QmoddefMachineNumber_,
          4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Phi");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Theta");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Psi");
          _SFD_SET_DATA_PROPS(3,2,0,1,"J");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,265);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c4_Phi;
          real_T *c4_Theta;
          real_T *c4_Psi;
          real_T (*c4_J)[9];
          real_T (*c4_I)[3];
          c4_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c4_J = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c4_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_Phi);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_Theta);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_Psi);
          _SFD_SET_DATA_VALUE_PTR(3U, *c4_J);
          _SFD_SET_DATA_VALUE_PTR(4U, *c4_I);
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
  return "3dJjesDGO8gvUTE78bUG5E";
}

static void sf_opaque_initialize_c4_Qmoddef(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_QmoddefInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c4_Qmoddef((SFc4_QmoddefInstanceStruct*) chartInstanceVar);
  initialize_c4_Qmoddef((SFc4_QmoddefInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_Qmoddef(void *chartInstanceVar)
{
  enable_c4_Qmoddef((SFc4_QmoddefInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_Qmoddef(void *chartInstanceVar)
{
  disable_c4_Qmoddef((SFc4_QmoddefInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_Qmoddef(void *chartInstanceVar)
{
  sf_c4_Qmoddef((SFc4_QmoddefInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_Qmoddef(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_Qmoddef((SFc4_QmoddefInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_Qmoddef();/* state var info */
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

extern void sf_internal_set_sim_state_c4_Qmoddef(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_Qmoddef();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_Qmoddef((SFc4_QmoddefInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_Qmoddef(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_Qmoddef(S);
}

static void sf_opaque_set_sim_state_c4_Qmoddef(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c4_Qmoddef(S, st);
}

static void sf_opaque_terminate_c4_Qmoddef(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_QmoddefInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_Qmoddef((SFc4_QmoddefInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Qmoddef_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_Qmoddef((SFc4_QmoddefInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_Qmoddef(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_Qmoddef((SFc4_QmoddefInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_Qmoddef(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Qmoddef_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1520322540U));
  ssSetChecksum1(S,(3705380148U));
  ssSetChecksum2(S,(2173864294U));
  ssSetChecksum3(S,(3514632532U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_Qmoddef(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_Qmoddef(SimStruct *S)
{
  SFc4_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc4_QmoddefInstanceStruct *)malloc(sizeof
    (SFc4_QmoddefInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_QmoddefInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_Qmoddef;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_Qmoddef;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_Qmoddef;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_Qmoddef;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_Qmoddef;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_Qmoddef;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_Qmoddef;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_Qmoddef;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_Qmoddef;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_Qmoddef;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_Qmoddef;
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

void c4_Qmoddef_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_Qmoddef(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_Qmoddef(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_Qmoddef(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_Qmoddef_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

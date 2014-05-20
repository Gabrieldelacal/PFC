/* Include files */

#include "blascompat32.h"
#include "simlag2_sfun.h"
#include "c2_simlag2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "simlag2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[15] = { "R", "T", "nargin", "nargout",
  "w1", "w2", "w3", "w4", "m", "g", "k", "Phi", "Theta", "Psi", "ddXi" };

/* Function Declarations */
static void initialize_c2_simlag2(SFc2_simlag2InstanceStruct *chartInstance);
static void initialize_params_c2_simlag2(SFc2_simlag2InstanceStruct
  *chartInstance);
static void enable_c2_simlag2(SFc2_simlag2InstanceStruct *chartInstance);
static void disable_c2_simlag2(SFc2_simlag2InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_simlag2(SFc2_simlag2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_simlag2(SFc2_simlag2InstanceStruct
  *chartInstance);
static void set_sim_state_c2_simlag2(SFc2_simlag2InstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_simlag2(SFc2_simlag2InstanceStruct *chartInstance);
static void sf_c2_simlag2(SFc2_simlag2InstanceStruct *chartInstance);
static void c2_chartstep_c2_simlag2(SFc2_simlag2InstanceStruct *chartInstance);
static void initSimStructsc2_simlag2(SFc2_simlag2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_simlag2InstanceStruct *chartInstance, const
  mxArray *c2_ddXi, const char_T *c2_identifier, real_T c2_y[3]);
static void c2_b_emlrt_marshallIn(SFc2_simlag2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_simlag2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_simlag2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[15]);
static void c2_eml_scalar_eg(SFc2_simlag2InstanceStruct *chartInstance);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_simlag2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn(SFc2_simlag2InstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_simlag2, const char_T *c2_identifier);
static uint8_T c2_g_emlrt_marshallIn(SFc2_simlag2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_simlag2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_simlag2(SFc2_simlag2InstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_simlag2 = 0U;
}

static void initialize_params_c2_simlag2(SFc2_simlag2InstanceStruct
  *chartInstance)
{
}

static void enable_c2_simlag2(SFc2_simlag2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_simlag2(SFc2_simlag2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_simlag2(SFc2_simlag2InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_simlag2(SFc2_simlag2InstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[3];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_ddXi)[3];
  c2_ddXi = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    c2_u[c2_i0] = (*c2_ddXi)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_simlag2;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_simlag2(SFc2_simlag2InstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[3];
  int32_T c2_i1;
  real_T (*c2_ddXi)[3];
  c2_ddXi = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "ddXi",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    (*c2_ddXi)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_simlag2 = c2_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)), "is_active_c2_simlag2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_simlag2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_simlag2(SFc2_simlag2InstanceStruct *chartInstance)
{
}

static void sf_c2_simlag2(SFc2_simlag2InstanceStruct *chartInstance)
{
  int32_T c2_i2;
  real_T *c2_w1;
  real_T *c2_w2;
  real_T *c2_w3;
  real_T *c2_w4;
  real_T *c2_m;
  real_T *c2_g;
  real_T *c2_k;
  real_T *c2_Phi;
  real_T *c2_Theta;
  real_T *c2_Psi;
  real_T (*c2_ddXi)[3];
  c2_ddXi = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c2_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c2_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c2_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_g = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_w4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_w3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_w2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_w1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_w1, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_w2, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_w3, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_w4, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_m, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_g, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_k, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_Phi, 7U);
  _SFD_DATA_RANGE_CHECK(*c2_Theta, 8U);
  _SFD_DATA_RANGE_CHECK(*c2_Psi, 9U);
  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_ddXi)[c2_i2], 10U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_simlag2(chartInstance);
  sf_debug_check_for_state_inconsistency(_simlag2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_simlag2(SFc2_simlag2InstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_g_hoistedGlobal;
  real_T c2_h_hoistedGlobal;
  real_T c2_i_hoistedGlobal;
  real_T c2_j_hoistedGlobal;
  real_T c2_w1;
  real_T c2_w2;
  real_T c2_w3;
  real_T c2_w4;
  real_T c2_m;
  real_T c2_g;
  real_T c2_k;
  real_T c2_Phi;
  real_T c2_Theta;
  real_T c2_Psi;
  uint32_T c2_debug_family_var_map[15];
  real_T c2_R[9];
  real_T c2_T[3];
  real_T c2_nargin = 10.0;
  real_T c2_nargout = 1.0;
  real_T c2_ddXi[3];
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_a;
  real_T c2_b;
  real_T c2_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_b_y;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_c_y;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_d_y;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_e_y;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_f_a;
  real_T c2_f_b;
  real_T c2_f_y;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_g_a;
  real_T c2_g_b;
  real_T c2_g_y;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_h_a;
  real_T c2_h_b;
  real_T c2_h_y;
  real_T c2_db_x;
  real_T c2_eb_x;
  real_T c2_fb_x;
  real_T c2_gb_x;
  real_T c2_i_a;
  real_T c2_i_b;
  real_T c2_i_y;
  real_T c2_hb_x;
  real_T c2_ib_x;
  real_T c2_j_a;
  real_T c2_j_b;
  real_T c2_j_y;
  real_T c2_jb_x;
  real_T c2_kb_x;
  real_T c2_lb_x;
  real_T c2_mb_x;
  real_T c2_k_a;
  real_T c2_k_b;
  real_T c2_k_y;
  real_T c2_nb_x;
  real_T c2_ob_x;
  real_T c2_pb_x;
  real_T c2_qb_x;
  real_T c2_l_a;
  real_T c2_l_b;
  real_T c2_l_y;
  real_T c2_rb_x;
  real_T c2_sb_x;
  real_T c2_m_a;
  real_T c2_m_b;
  real_T c2_m_y;
  real_T c2_tb_x;
  real_T c2_ub_x;
  real_T c2_vb_x;
  real_T c2_wb_x;
  real_T c2_n_a;
  real_T c2_n_b;
  real_T c2_n_y;
  real_T c2_xb_x;
  real_T c2_yb_x;
  real_T c2_ac_x;
  real_T c2_bc_x;
  real_T c2_cc_x;
  real_T c2_dc_x;
  real_T c2_o_a;
  real_T c2_o_b;
  real_T c2_o_y;
  real_T c2_ec_x;
  real_T c2_fc_x;
  real_T c2_gc_x;
  real_T c2_hc_x;
  real_T c2_p_a;
  real_T c2_p_b;
  real_T c2_p_y;
  real_T c2_q_a;
  real_T c2_q_b;
  real_T c2_q_y;
  real_T c2_A;
  real_T c2_B;
  real_T c2_ic_x;
  real_T c2_r_y;
  real_T c2_jc_x;
  real_T c2_s_y;
  real_T c2_t_y;
  int32_T c2_i3;
  real_T c2_r_a[9];
  int32_T c2_i4;
  real_T c2_r_b[3];
  int32_T c2_i5;
  real_T c2_u_y[3];
  int32_T c2_i6;
  int32_T c2_i7;
  real_T c2_b_B;
  real_T c2_v_y;
  real_T c2_w_y;
  int32_T c2_i8;
  real_T c2_dv1[3];
  int32_T c2_i9;
  int32_T c2_i10;
  real_T *c2_b_w1;
  real_T *c2_b_w2;
  real_T *c2_b_w3;
  real_T *c2_b_w4;
  real_T *c2_b_m;
  real_T *c2_b_g;
  real_T *c2_b_k;
  real_T *c2_b_Phi;
  real_T *c2_b_Theta;
  real_T *c2_b_Psi;
  real_T (*c2_b_ddXi)[3];
  c2_b_ddXi = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c2_b_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c2_b_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c2_b_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_b_g = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_w4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_w3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_w2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_w1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_w1;
  c2_b_hoistedGlobal = *c2_b_w2;
  c2_c_hoistedGlobal = *c2_b_w3;
  c2_d_hoistedGlobal = *c2_b_w4;
  c2_e_hoistedGlobal = *c2_b_m;
  c2_f_hoistedGlobal = *c2_b_g;
  c2_g_hoistedGlobal = *c2_b_k;
  c2_h_hoistedGlobal = *c2_b_Phi;
  c2_i_hoistedGlobal = *c2_b_Theta;
  c2_j_hoistedGlobal = *c2_b_Psi;
  c2_w1 = c2_hoistedGlobal;
  c2_w2 = c2_b_hoistedGlobal;
  c2_w3 = c2_c_hoistedGlobal;
  c2_w4 = c2_d_hoistedGlobal;
  c2_m = c2_e_hoistedGlobal;
  c2_g = c2_f_hoistedGlobal;
  c2_k = c2_g_hoistedGlobal;
  c2_Phi = c2_h_hoistedGlobal;
  c2_Theta = c2_i_hoistedGlobal;
  c2_Psi = c2_j_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 15U, 15U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c2_R, 0U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_T, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_w1, 4U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_w2, 5U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_w3, 6U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_w4, 7U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_m, 8U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_g, 9U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_k, 10U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Phi, 11U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Theta, 12U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Psi, 13U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_ddXi, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_x = c2_Psi;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_c_x = c2_Theta;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarCos(c2_d_x);
  c2_a = c2_b_x;
  c2_b = c2_d_x;
  c2_y = c2_a * c2_b;
  c2_e_x = c2_Psi;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarCos(c2_f_x);
  c2_g_x = c2_Theta;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarSin(c2_h_x);
  c2_b_a = c2_f_x;
  c2_b_b = c2_h_x;
  c2_b_y = c2_b_a * c2_b_b;
  c2_i_x = c2_Phi;
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarSin(c2_j_x);
  c2_c_a = c2_b_y;
  c2_c_b = c2_j_x;
  c2_c_y = c2_c_a * c2_c_b;
  c2_k_x = c2_Psi;
  c2_l_x = c2_k_x;
  c2_l_x = muDoubleScalarSin(c2_l_x);
  c2_m_x = c2_Phi;
  c2_n_x = c2_m_x;
  c2_n_x = muDoubleScalarCos(c2_n_x);
  c2_d_a = c2_l_x;
  c2_d_b = c2_n_x;
  c2_d_y = c2_d_a * c2_d_b;
  c2_o_x = c2_Psi;
  c2_p_x = c2_o_x;
  c2_p_x = muDoubleScalarCos(c2_p_x);
  c2_q_x = c2_Theta;
  c2_r_x = c2_q_x;
  c2_r_x = muDoubleScalarSin(c2_r_x);
  c2_e_a = c2_p_x;
  c2_e_b = c2_r_x;
  c2_e_y = c2_e_a * c2_e_b;
  c2_s_x = c2_Phi;
  c2_t_x = c2_s_x;
  c2_t_x = muDoubleScalarCos(c2_t_x);
  c2_f_a = c2_e_y;
  c2_f_b = c2_t_x;
  c2_f_y = c2_f_a * c2_f_b;
  c2_u_x = c2_Psi;
  c2_v_x = c2_u_x;
  c2_v_x = muDoubleScalarSin(c2_v_x);
  c2_w_x = c2_Phi;
  c2_x_x = c2_w_x;
  c2_x_x = muDoubleScalarSin(c2_x_x);
  c2_g_a = c2_v_x;
  c2_g_b = c2_x_x;
  c2_g_y = c2_g_a * c2_g_b;
  c2_y_x = c2_Psi;
  c2_ab_x = c2_y_x;
  c2_ab_x = muDoubleScalarSin(c2_ab_x);
  c2_bb_x = c2_Theta;
  c2_cb_x = c2_bb_x;
  c2_cb_x = muDoubleScalarCos(c2_cb_x);
  c2_h_a = c2_ab_x;
  c2_h_b = c2_cb_x;
  c2_h_y = c2_h_a * c2_h_b;
  c2_db_x = c2_Psi;
  c2_eb_x = c2_db_x;
  c2_eb_x = muDoubleScalarSin(c2_eb_x);
  c2_fb_x = c2_Theta;
  c2_gb_x = c2_fb_x;
  c2_gb_x = muDoubleScalarSin(c2_gb_x);
  c2_i_a = c2_eb_x;
  c2_i_b = c2_gb_x;
  c2_i_y = c2_i_a * c2_i_b;
  c2_hb_x = c2_Phi;
  c2_ib_x = c2_hb_x;
  c2_ib_x = muDoubleScalarSin(c2_ib_x);
  c2_j_a = c2_i_y;
  c2_j_b = c2_ib_x;
  c2_j_y = c2_j_a * c2_j_b;
  c2_jb_x = c2_Psi;
  c2_kb_x = c2_jb_x;
  c2_kb_x = muDoubleScalarCos(c2_kb_x);
  c2_lb_x = c2_Phi;
  c2_mb_x = c2_lb_x;
  c2_mb_x = muDoubleScalarCos(c2_mb_x);
  c2_k_a = c2_kb_x;
  c2_k_b = c2_mb_x;
  c2_k_y = c2_k_a * c2_k_b;
  c2_nb_x = c2_Psi;
  c2_ob_x = c2_nb_x;
  c2_ob_x = muDoubleScalarSin(c2_ob_x);
  c2_pb_x = c2_Theta;
  c2_qb_x = c2_pb_x;
  c2_qb_x = muDoubleScalarSin(c2_qb_x);
  c2_l_a = c2_ob_x;
  c2_l_b = c2_qb_x;
  c2_l_y = c2_l_a * c2_l_b;
  c2_rb_x = c2_Phi;
  c2_sb_x = c2_rb_x;
  c2_sb_x = muDoubleScalarCos(c2_sb_x);
  c2_m_a = c2_l_y;
  c2_m_b = c2_sb_x;
  c2_m_y = c2_m_a * c2_m_b;
  c2_tb_x = c2_Psi;
  c2_ub_x = c2_tb_x;
  c2_ub_x = muDoubleScalarCos(c2_ub_x);
  c2_vb_x = c2_Phi;
  c2_wb_x = c2_vb_x;
  c2_wb_x = muDoubleScalarSin(c2_wb_x);
  c2_n_a = c2_ub_x;
  c2_n_b = c2_wb_x;
  c2_n_y = c2_n_a * c2_n_b;
  c2_xb_x = c2_Theta;
  c2_yb_x = c2_xb_x;
  c2_yb_x = muDoubleScalarSin(c2_yb_x);
  c2_ac_x = c2_Theta;
  c2_bc_x = c2_ac_x;
  c2_bc_x = muDoubleScalarCos(c2_bc_x);
  c2_cc_x = c2_Phi;
  c2_dc_x = c2_cc_x;
  c2_dc_x = muDoubleScalarSin(c2_dc_x);
  c2_o_a = c2_bc_x;
  c2_o_b = c2_dc_x;
  c2_o_y = c2_o_a * c2_o_b;
  c2_ec_x = c2_Theta;
  c2_fc_x = c2_ec_x;
  c2_fc_x = muDoubleScalarCos(c2_fc_x);
  c2_gc_x = c2_Phi;
  c2_hc_x = c2_gc_x;
  c2_hc_x = muDoubleScalarCos(c2_hc_x);
  c2_p_a = c2_fc_x;
  c2_p_b = c2_hc_x;
  c2_p_y = c2_p_a * c2_p_b;
  c2_R[0] = c2_y;
  c2_R[3] = c2_c_y - c2_d_y;
  c2_R[6] = c2_f_y + c2_g_y;
  c2_R[1] = c2_h_y;
  c2_R[4] = c2_j_y + c2_k_y;
  c2_R[7] = c2_m_y - c2_n_y;
  c2_R[2] = -c2_yb_x;
  c2_R[5] = c2_o_y;
  c2_R[8] = c2_p_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_q_a = c2_k;
  c2_q_b = ((c2_w1 + c2_w2) + c2_w3) + c2_w4;
  c2_q_y = c2_q_a * c2_q_b;
  c2_A = c2_q_y;
  c2_B = c2_m;
  c2_ic_x = c2_A;
  c2_r_y = c2_B;
  c2_jc_x = c2_ic_x;
  c2_s_y = c2_r_y;
  c2_t_y = c2_jc_x / c2_s_y;
  c2_T[0] = 0.0;
  c2_T[1] = 0.0;
  c2_T[2] = c2_t_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  for (c2_i3 = 0; c2_i3 < 9; c2_i3++) {
    c2_r_a[c2_i3] = c2_R[c2_i3];
  }

  for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
    c2_r_b[c2_i4] = c2_T[c2_i4];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    c2_u_y[c2_i5] = 0.0;
    c2_i6 = 0;
    for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
      c2_u_y[c2_i5] += c2_r_a[c2_i6 + c2_i5] * c2_r_b[c2_i7];
      c2_i6 += 3;
    }
  }

  c2_b_B = c2_m;
  c2_v_y = c2_b_B;
  c2_w_y = c2_v_y;
  for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
    c2_u_y[c2_i8] /= c2_w_y;
  }

  c2_dv1[0] = 0.0;
  c2_dv1[1] = 0.0;
  c2_dv1[2] = -c2_g;
  for (c2_i9 = 0; c2_i9 < 3; c2_i9++) {
    c2_ddXi[c2_i9] = c2_u_y[c2_i9] + c2_dv1[c2_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -12);
  sf_debug_symbol_scope_pop();
  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    (*c2_b_ddXi)[c2_i10] = c2_ddXi[c2_i10];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_simlag2(SFc2_simlag2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i11;
  real_T c2_b_inData[3];
  int32_T c2_i12;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc2_simlag2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    c2_b_inData[c2_i11] = (*(real_T (*)[3])c2_inData)[c2_i11];
  }

  for (c2_i12 = 0; c2_i12 < 3; c2_i12++) {
    c2_u[c2_i12] = c2_b_inData[c2_i12];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_simlag2InstanceStruct *chartInstance, const
  mxArray *c2_ddXi, const char_T *c2_identifier, real_T c2_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_ddXi), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_ddXi);
}

static void c2_b_emlrt_marshallIn(SFc2_simlag2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3])
{
  real_T c2_dv2[3];
  int32_T c2_i13;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i13 = 0; c2_i13 < 3; c2_i13++) {
    c2_y[c2_i13] = c2_dv2[c2_i13];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_ddXi;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i14;
  SFc2_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc2_simlag2InstanceStruct *)chartInstanceVoid;
  c2_ddXi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_ddXi), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_ddXi);
  for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
    (*(real_T (*)[3])c2_outData)[c2_i14] = c2_y[c2_i14];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc2_simlag2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_simlag2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc2_simlag2InstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  real_T c2_b_inData[9];
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i20;
  real_T c2_u[9];
  const mxArray *c2_y = NULL;
  SFc2_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc2_simlag2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i15 = 0;
  for (c2_i16 = 0; c2_i16 < 3; c2_i16++) {
    for (c2_i17 = 0; c2_i17 < 3; c2_i17++) {
      c2_b_inData[c2_i17 + c2_i15] = (*(real_T (*)[9])c2_inData)[c2_i17 + c2_i15];
    }

    c2_i15 += 3;
  }

  c2_i18 = 0;
  for (c2_i19 = 0; c2_i19 < 3; c2_i19++) {
    for (c2_i20 = 0; c2_i20 < 3; c2_i20++) {
      c2_u[c2_i20 + c2_i18] = c2_b_inData[c2_i20 + c2_i18];
    }

    c2_i18 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_simlag2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9])
{
  real_T c2_dv3[9];
  int32_T c2_i21;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c2_i21 = 0; c2_i21 < 9; c2_i21++) {
    c2_y[c2_i21] = c2_dv3[c2_i21];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_R;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[9];
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  SFc2_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc2_simlag2InstanceStruct *)chartInstanceVoid;
  c2_R = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_R), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_R);
  c2_i22 = 0;
  for (c2_i23 = 0; c2_i23 < 3; c2_i23++) {
    for (c2_i24 = 0; c2_i24 < 3; c2_i24++) {
      (*(real_T (*)[9])c2_outData)[c2_i24 + c2_i22] = c2_y[c2_i24 + c2_i22];
    }

    c2_i22 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_simlag2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[15];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i25;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 15), FALSE);
  for (c2_i25 = 0; c2_i25 < 15; c2_i25++) {
    c2_r0 = &c2_info[c2_i25];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i25);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[15])
{
  c2_info[0].context = "";
  c2_info[0].name = "cos";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[0].fileTimeLo = 1286818706U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[1].name = "eml_scalar_cos";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[1].fileTimeLo = 1286818722U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "mtimes";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[2].fileTimeLo = 1289519692U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "";
  c2_info[3].name = "sin";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[3].fileTimeLo = 1286818750U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[4].name = "eml_scalar_sin";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[4].fileTimeLo = 1286818736U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "";
  c2_info[5].name = "mrdivide";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[5].fileTimeLo = 1325124138U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 1319729966U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[6].name = "rdivide";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[6].fileTimeLo = 1286818844U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[7].name = "eml_div";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[7].fileTimeLo = 1313347810U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[8].name = "eml_index_class";
  c2_info[8].dominantType = "";
  c2_info[8].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[8].fileTimeLo = 1286818778U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[9].name = "eml_scalar_eg";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[9].fileTimeLo = 1286818796U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[10].name = "eml_xgemm";
  c2_info[10].dominantType = "int32";
  c2_info[10].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[10].fileTimeLo = 1299076772U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[11].name = "eml_blas_inline";
  c2_info[11].dominantType = "";
  c2_info[11].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[11].fileTimeLo = 1299076768U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c2_info[12].name = "mtimes";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[12].fileTimeLo = 1289519692U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[13].name = "eml_scalar_eg";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[13].fileTimeLo = 1286818796U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[14].name = "eml_refblas_xgemm";
  c2_info[14].dominantType = "int32";
  c2_info[14].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[14].fileTimeLo = 1299076774U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
}

static void c2_eml_scalar_eg(SFc2_simlag2InstanceStruct *chartInstance)
{
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc2_simlag2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_simlag2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i26;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i26, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i26;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc2_simlag2InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_simlag2InstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_simlag2, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_simlag2), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_simlag2);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_simlag2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_simlag2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_simlag2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1301471941U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(933850683U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(198112073U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3236686235U);
}

mxArray *sf_c2_simlag2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Ief48QBz1xPGhMmgqiSu6E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));
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

static const mxArray *sf_get_sim_state_info_c2_simlag2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"ddXi\",},{M[8],M[0],T\"is_active_c2_simlag2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_simlag2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_simlag2InstanceStruct *chartInstance;
    chartInstance = (SFc2_simlag2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_simlag2MachineNumber_,
          2,
          1,
          1,
          11,
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
          init_script_number_translation(_simlag2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_simlag2MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_simlag2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"w1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"w2");
          _SFD_SET_DATA_PROPS(2,1,1,0,"w3");
          _SFD_SET_DATA_PROPS(3,1,1,0,"w4");
          _SFD_SET_DATA_PROPS(4,1,1,0,"m");
          _SFD_SET_DATA_PROPS(5,1,1,0,"g");
          _SFD_SET_DATA_PROPS(6,1,1,0,"k");
          _SFD_SET_DATA_PROPS(7,1,1,0,"Phi");
          _SFD_SET_DATA_PROPS(8,1,1,0,"Theta");
          _SFD_SET_DATA_PROPS(9,1,1,0,"Psi");
          _SFD_SET_DATA_PROPS(10,2,0,1,"ddXi");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,466);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T *c2_w1;
          real_T *c2_w2;
          real_T *c2_w3;
          real_T *c2_w4;
          real_T *c2_m;
          real_T *c2_g;
          real_T *c2_k;
          real_T *c2_Phi;
          real_T *c2_Theta;
          real_T *c2_Psi;
          real_T (*c2_ddXi)[3];
          c2_ddXi = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c2_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c2_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c2_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c2_g = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_w4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_w3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_w2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_w1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_w1);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_w2);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_w3);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_w4);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_m);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_g);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_k);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_Phi);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_Theta);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_Psi);
          _SFD_SET_DATA_VALUE_PTR(10U, *c2_ddXi);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_simlag2MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "H8ORSBmffWY7Qa9PpqWW6C";
}

static void sf_opaque_initialize_c2_simlag2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_simlag2InstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c2_simlag2((SFc2_simlag2InstanceStruct*) chartInstanceVar);
  initialize_c2_simlag2((SFc2_simlag2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_simlag2(void *chartInstanceVar)
{
  enable_c2_simlag2((SFc2_simlag2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_simlag2(void *chartInstanceVar)
{
  disable_c2_simlag2((SFc2_simlag2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_simlag2(void *chartInstanceVar)
{
  sf_c2_simlag2((SFc2_simlag2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_simlag2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_simlag2((SFc2_simlag2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_simlag2();/* state var info */
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

extern void sf_internal_set_sim_state_c2_simlag2(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_simlag2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_simlag2((SFc2_simlag2InstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_simlag2(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_simlag2(S);
}

static void sf_opaque_set_sim_state_c2_simlag2(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_simlag2(S, st);
}

static void sf_opaque_terminate_c2_simlag2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_simlag2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_simlag2((SFc2_simlag2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_simlag2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_simlag2((SFc2_simlag2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_simlag2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_simlag2((SFc2_simlag2InstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_simlag2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_simlag2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,10);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3052292697U));
  ssSetChecksum1(S,(724649781U));
  ssSetChecksum2(S,(3429803229U));
  ssSetChecksum3(S,(762419996U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_simlag2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_simlag2(SimStruct *S)
{
  SFc2_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc2_simlag2InstanceStruct *)malloc(sizeof
    (SFc2_simlag2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_simlag2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_simlag2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_simlag2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_simlag2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_simlag2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_simlag2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_simlag2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_simlag2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_simlag2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_simlag2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_simlag2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_simlag2;
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

void c2_simlag2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_simlag2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_simlag2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_simlag2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_simlag2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

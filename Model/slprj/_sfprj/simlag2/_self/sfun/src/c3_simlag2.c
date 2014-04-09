/* Include files */

#include "blascompat32.h"
#include "simlag2_sfun.h"
#include "c3_simlag2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "simlag2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[41] = { "m", "k", "l", "b", "g", "Ixx",
  "Iyy", "Izz", "zD", "dzD", "PhiD", "ThetaD", "PsiD", "dPhiD", "dThetaD",
  "dPsiD", "KphiP", "KthetaP", "KpsiP", "KzP", "KphiD", "KthetaD", "KpsiD",
  "KzD", "T", "TauPhi", "TauTheta", "TauPsi", "nargin", "nargout", "Phi",
  "Theta", "Psi", "dPhi", "dTheta", "dPsi", "z", "dz", "Constants", "II", "y" };

/* Function Declarations */
static void initialize_c3_simlag2(SFc3_simlag2InstanceStruct *chartInstance);
static void initialize_params_c3_simlag2(SFc3_simlag2InstanceStruct
  *chartInstance);
static void enable_c3_simlag2(SFc3_simlag2InstanceStruct *chartInstance);
static void disable_c3_simlag2(SFc3_simlag2InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_simlag2(SFc3_simlag2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_simlag2(SFc3_simlag2InstanceStruct
  *chartInstance);
static void set_sim_state_c3_simlag2(SFc3_simlag2InstanceStruct *chartInstance,
  const mxArray *c3_st);
static void finalize_c3_simlag2(SFc3_simlag2InstanceStruct *chartInstance);
static void sf_c3_simlag2(SFc3_simlag2InstanceStruct *chartInstance);
static void c3_chartstep_c3_simlag2(SFc3_simlag2InstanceStruct *chartInstance);
static void initSimStructsc3_simlag2(SFc3_simlag2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_simlag2InstanceStruct *chartInstance, const
  mxArray *c3_y, const char_T *c3_identifier, real_T c3_b_y[4]);
static void c3_b_emlrt_marshallIn(SFc3_simlag2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[4]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn(SFc3_simlag2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn(SFc3_simlag2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_e_emlrt_marshallIn(SFc3_simlag2InstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_simlag2, const char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn(SFc3_simlag2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_simlag2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_simlag2(SFc3_simlag2InstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_simlag2 = 0U;
}

static void initialize_params_c3_simlag2(SFc3_simlag2InstanceStruct
  *chartInstance)
{
}

static void enable_c3_simlag2(SFc3_simlag2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_simlag2(SFc3_simlag2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_simlag2(SFc3_simlag2InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_simlag2(SFc3_simlag2InstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[4];
  const mxArray *c3_b_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T (*c3_d_y)[4];
  c3_d_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  for (c3_i0 = 0; c3_i0 < 4; c3_i0++) {
    c3_u[c3_i0] = (*c3_d_y)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_simlag2;
  c3_b_u = c3_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_simlag2(SFc3_simlag2InstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[4];
  int32_T c3_i1;
  real_T (*c3_y)[4];
  c3_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)), "y",
                      c3_dv0);
  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    (*c3_y)[c3_i1] = c3_dv0[c3_i1];
  }

  chartInstance->c3_is_active_c3_simlag2 = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 1)), "is_active_c3_simlag2");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_simlag2(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_simlag2(SFc3_simlag2InstanceStruct *chartInstance)
{
}

static void sf_c3_simlag2(SFc3_simlag2InstanceStruct *chartInstance)
{
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  real_T *c3_Phi;
  real_T *c3_Theta;
  real_T *c3_Psi;
  real_T *c3_dPhi;
  real_T *c3_dTheta;
  real_T *c3_dPsi;
  real_T *c3_z;
  real_T *c3_dz;
  real_T (*c3_II)[3];
  real_T (*c3_Constants)[5];
  real_T (*c3_y)[4];
  c3_II = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c3_Constants = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 8);
  c3_dz = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_dPsi = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_dTheta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_dPhi = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_Phi, 0U);
  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    _SFD_DATA_RANGE_CHECK((*c3_y)[c3_i2], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_Theta, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_Psi, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_dPhi, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_dTheta, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_dPsi, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_z, 7U);
  _SFD_DATA_RANGE_CHECK(*c3_dz, 8U);
  for (c3_i3 = 0; c3_i3 < 5; c3_i3++) {
    _SFD_DATA_RANGE_CHECK((*c3_Constants)[c3_i3], 9U);
  }

  for (c3_i4 = 0; c3_i4 < 3; c3_i4++) {
    _SFD_DATA_RANGE_CHECK((*c3_II)[c3_i4], 10U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_simlag2(chartInstance);
  sf_debug_check_for_state_inconsistency(_simlag2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_simlag2(SFc3_simlag2InstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_f_hoistedGlobal;
  real_T c3_g_hoistedGlobal;
  real_T c3_h_hoistedGlobal;
  real_T c3_Phi;
  real_T c3_Theta;
  real_T c3_Psi;
  real_T c3_dPhi;
  real_T c3_dTheta;
  real_T c3_dPsi;
  real_T c3_z;
  real_T c3_dz;
  int32_T c3_i5;
  real_T c3_Constants[5];
  int32_T c3_i6;
  real_T c3_II[3];
  uint32_T c3_debug_family_var_map[41];
  real_T c3_m;
  real_T c3_k;
  real_T c3_l;
  real_T c3_b;
  real_T c3_g;
  real_T c3_Ixx;
  real_T c3_Iyy;
  real_T c3_Izz;
  real_T c3_zD;
  real_T c3_dzD;
  real_T c3_PhiD;
  real_T c3_ThetaD;
  real_T c3_PsiD;
  real_T c3_dPhiD;
  real_T c3_dThetaD;
  real_T c3_dPsiD;
  real_T c3_KphiP;
  real_T c3_KthetaP;
  real_T c3_KpsiP;
  real_T c3_KzP;
  real_T c3_KphiD;
  real_T c3_KthetaD;
  real_T c3_KpsiD;
  real_T c3_KzD;
  real_T c3_T;
  real_T c3_TauPhi;
  real_T c3_TauTheta;
  real_T c3_TauPsi;
  real_T c3_nargin = 10.0;
  real_T c3_nargout = 1.0;
  real_T c3_y[4];
  real_T c3_b_b;
  real_T c3_b_y;
  real_T c3_c_b;
  real_T c3_c_y;
  real_T c3_a;
  real_T c3_d_b;
  real_T c3_d_y;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_b_a;
  real_T c3_e_b;
  real_T c3_e_y;
  real_T c3_A;
  real_T c3_B;
  real_T c3_e_x;
  real_T c3_f_y;
  real_T c3_f_x;
  real_T c3_g_y;
  real_T c3_f_b;
  real_T c3_h_y;
  real_T c3_g_b;
  real_T c3_i_y;
  real_T c3_c_a;
  real_T c3_h_b;
  real_T c3_i_b;
  real_T c3_j_y;
  real_T c3_j_b;
  real_T c3_k_y;
  real_T c3_d_a;
  real_T c3_k_b;
  real_T c3_l_b;
  real_T c3_l_y;
  real_T c3_m_b;
  real_T c3_m_y;
  real_T c3_e_a;
  real_T c3_n_b;
  real_T c3_o_b;
  real_T c3_n_y;
  real_T c3_b_A;
  real_T c3_b_B;
  real_T c3_g_x;
  real_T c3_o_y;
  real_T c3_h_x;
  real_T c3_p_y;
  real_T c3_q_y;
  real_T c3_p_b;
  real_T c3_r_y;
  real_T c3_f_a;
  real_T c3_q_b;
  real_T c3_s_y;
  real_T c3_c_A;
  real_T c3_c_B;
  real_T c3_i_x;
  real_T c3_t_y;
  real_T c3_j_x;
  real_T c3_u_y;
  real_T c3_v_y;
  real_T c3_r_b;
  real_T c3_w_y;
  real_T c3_d_A;
  real_T c3_d_B;
  real_T c3_k_x;
  real_T c3_x_y;
  real_T c3_l_x;
  real_T c3_y_y;
  real_T c3_ab_y;
  real_T c3_s_b;
  real_T c3_bb_y;
  real_T c3_e_A;
  real_T c3_e_B;
  real_T c3_m_x;
  real_T c3_cb_y;
  real_T c3_n_x;
  real_T c3_db_y;
  real_T c3_eb_y;
  real_T c3_t_b;
  real_T c3_fb_y;
  real_T c3_g_a;
  real_T c3_u_b;
  real_T c3_gb_y;
  real_T c3_f_A;
  real_T c3_f_B;
  real_T c3_o_x;
  real_T c3_hb_y;
  real_T c3_p_x;
  real_T c3_ib_y;
  real_T c3_jb_y;
  real_T c3_v_b;
  real_T c3_kb_y;
  real_T c3_g_A;
  real_T c3_g_B;
  real_T c3_q_x;
  real_T c3_lb_y;
  real_T c3_r_x;
  real_T c3_mb_y;
  real_T c3_nb_y;
  real_T c3_w_b;
  real_T c3_ob_y;
  real_T c3_h_A;
  real_T c3_h_B;
  real_T c3_s_x;
  real_T c3_pb_y;
  real_T c3_t_x;
  real_T c3_qb_y;
  real_T c3_rb_y;
  real_T c3_x_b;
  real_T c3_sb_y;
  real_T c3_h_a;
  real_T c3_y_b;
  real_T c3_tb_y;
  real_T c3_i_A;
  real_T c3_i_B;
  real_T c3_u_x;
  real_T c3_ub_y;
  real_T c3_v_x;
  real_T c3_vb_y;
  real_T c3_wb_y;
  real_T c3_ab_b;
  real_T c3_xb_y;
  real_T c3_j_A;
  real_T c3_j_B;
  real_T c3_w_x;
  real_T c3_yb_y;
  real_T c3_x_x;
  real_T c3_ac_y;
  real_T c3_bc_y;
  real_T c3_bb_b;
  real_T c3_cc_y;
  real_T c3_k_A;
  real_T c3_k_B;
  real_T c3_y_x;
  real_T c3_dc_y;
  real_T c3_ab_x;
  real_T c3_ec_y;
  real_T c3_fc_y;
  real_T c3_cb_b;
  real_T c3_gc_y;
  real_T c3_i_a;
  real_T c3_db_b;
  real_T c3_hc_y;
  real_T c3_l_A;
  real_T c3_l_B;
  real_T c3_bb_x;
  real_T c3_ic_y;
  real_T c3_cb_x;
  real_T c3_jc_y;
  real_T c3_kc_y;
  real_T c3_eb_b;
  real_T c3_lc_y;
  real_T c3_m_A;
  real_T c3_m_B;
  real_T c3_db_x;
  real_T c3_mc_y;
  real_T c3_eb_x;
  real_T c3_nc_y;
  real_T c3_oc_y;
  int32_T c3_i7;
  real_T *c3_b_dz;
  real_T *c3_b_z;
  real_T *c3_b_dPsi;
  real_T *c3_b_dTheta;
  real_T *c3_b_dPhi;
  real_T *c3_b_Psi;
  real_T *c3_b_Theta;
  real_T *c3_b_Phi;
  real_T (*c3_pc_y)[4];
  real_T (*c3_b_II)[3];
  real_T (*c3_b_Constants)[5];
  c3_b_II = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c3_b_Constants = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 8);
  c3_b_dz = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_b_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_b_dPsi = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_dTheta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_dPhi = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_pc_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_Phi;
  c3_b_hoistedGlobal = *c3_b_Theta;
  c3_c_hoistedGlobal = *c3_b_Psi;
  c3_d_hoistedGlobal = *c3_b_dPhi;
  c3_e_hoistedGlobal = *c3_b_dTheta;
  c3_f_hoistedGlobal = *c3_b_dPsi;
  c3_g_hoistedGlobal = *c3_b_z;
  c3_h_hoistedGlobal = *c3_b_dz;
  c3_Phi = c3_hoistedGlobal;
  c3_Theta = c3_b_hoistedGlobal;
  c3_Psi = c3_c_hoistedGlobal;
  c3_dPhi = c3_d_hoistedGlobal;
  c3_dTheta = c3_e_hoistedGlobal;
  c3_dPsi = c3_f_hoistedGlobal;
  c3_z = c3_g_hoistedGlobal;
  c3_dz = c3_h_hoistedGlobal;
  for (c3_i5 = 0; c3_i5 < 5; c3_i5++) {
    c3_Constants[c3_i5] = (*c3_b_Constants)[c3_i5];
  }

  for (c3_i6 = 0; c3_i6 < 3; c3_i6++) {
    c3_II[c3_i6] = (*c3_b_II)[c3_i6];
  }

  sf_debug_symbol_scope_push_eml(0U, 41U, 41U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_m, 0U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_k, 1U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_l, 2U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_b, 3U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_g, 4U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Ixx, 5U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Iyy, 6U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Izz, 7U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_zD, 8U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_dzD, 9U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_PhiD, 10U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_ThetaD, 11U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_PsiD, 12U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_dPhiD, 13U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_dThetaD, 14U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_dPsiD, 15U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_KphiP, 16U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_KthetaP, 17U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_KpsiP, 18U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_KzP, 19U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_KphiD, 20U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_KthetaD, 21U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_KpsiD, 22U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_KzD, 23U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_T, 24U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_TauPhi, 25U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_TauTheta, 26U,
    c3_d_sf_marshallOut, c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_TauPsi, 27U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 28U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 29U, c3_d_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_Phi, 30U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Theta, 31U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Psi, 32U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_dPhi, 33U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_dTheta, 34U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_dPsi, 35U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_z, 36U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_dz, 37U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_Constants, 38U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_II, 39U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c3_y, 40U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_m = c3_Constants[0];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  c3_k = c3_Constants[1];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_l = c3_Constants[2];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_b = c3_Constants[3];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_g = c3_Constants[4];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_Ixx = c3_II[0];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  c3_Iyy = c3_II[1];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
  c3_Izz = c3_II[2];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
  c3_zD = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  c3_dzD = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
  c3_PhiD = 0.5;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
  c3_ThetaD = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
  c3_PsiD = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
  c3_dPhiD = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
  c3_dThetaD = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
  c3_dPsiD = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
  c3_KphiP = 1.5;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 26);
  c3_KthetaP = 6.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 27);
  c3_KpsiP = 6.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
  c3_KzP = 6.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
  c3_KphiD = 2.5;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 31);
  c3_KthetaD = 1.75;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
  c3_KpsiD = 1.75;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 33);
  c3_KzD = 1.75;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 35);
  c3_b_b = c3_dzD - c3_dz;
  c3_b_y = 1.75 * c3_b_b;
  c3_c_b = c3_zD - c3_z;
  c3_c_y = 6.0 * c3_c_b;
  c3_a = (c3_g + c3_b_y) + c3_c_y;
  c3_d_b = c3_m;
  c3_d_y = c3_a * c3_d_b;
  c3_x = c3_Phi;
  c3_b_x = c3_x;
  c3_b_x = muDoubleScalarCos(c3_b_x);
  c3_c_x = c3_Theta;
  c3_d_x = c3_c_x;
  c3_d_x = muDoubleScalarCos(c3_d_x);
  c3_b_a = c3_b_x;
  c3_e_b = c3_d_x;
  c3_e_y = c3_b_a * c3_e_b;
  c3_A = c3_d_y;
  c3_B = c3_e_y;
  c3_e_x = c3_A;
  c3_f_y = c3_B;
  c3_f_x = c3_e_x;
  c3_g_y = c3_f_y;
  c3_T = c3_f_x / c3_g_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
  c3_f_b = c3_dPhiD - c3_dPhi;
  c3_h_y = 2.5 * c3_f_b;
  c3_g_b = c3_PhiD - c3_Phi;
  c3_i_y = 1.5 * c3_g_b;
  c3_c_a = c3_Ixx;
  c3_h_b = c3_h_y + c3_i_y;
  c3_TauPhi = c3_c_a * c3_h_b;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 39);
  c3_i_b = c3_dThetaD - c3_dTheta;
  c3_j_y = 1.75 * c3_i_b;
  c3_j_b = c3_ThetaD - c3_Theta;
  c3_k_y = 6.0 * c3_j_b;
  c3_d_a = c3_Iyy;
  c3_k_b = c3_j_y + c3_k_y;
  c3_TauTheta = c3_d_a * c3_k_b;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
  c3_l_b = c3_dPsiD - c3_dPsi;
  c3_l_y = 1.75 * c3_l_b;
  c3_m_b = c3_PsiD - c3_Psi;
  c3_m_y = 6.0 * c3_m_b;
  c3_e_a = c3_Izz;
  c3_n_b = c3_l_y + c3_m_y;
  c3_TauPsi = c3_e_a * c3_n_b;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 43);
  c3_o_b = c3_k;
  c3_n_y = 4.0 * c3_o_b;
  c3_b_A = c3_T;
  c3_b_B = c3_n_y;
  c3_g_x = c3_b_A;
  c3_o_y = c3_b_B;
  c3_h_x = c3_g_x;
  c3_p_y = c3_o_y;
  c3_q_y = c3_h_x / c3_p_y;
  c3_p_b = c3_k;
  c3_r_y = 2.0 * c3_p_b;
  c3_f_a = c3_r_y;
  c3_q_b = c3_l;
  c3_s_y = c3_f_a * c3_q_b;
  c3_c_A = c3_TauTheta;
  c3_c_B = c3_s_y;
  c3_i_x = c3_c_A;
  c3_t_y = c3_c_B;
  c3_j_x = c3_i_x;
  c3_u_y = c3_t_y;
  c3_v_y = c3_j_x / c3_u_y;
  c3_r_b = c3_b;
  c3_w_y = 4.0 * c3_r_b;
  c3_d_A = c3_TauPsi;
  c3_d_B = c3_w_y;
  c3_k_x = c3_d_A;
  c3_x_y = c3_d_B;
  c3_l_x = c3_k_x;
  c3_y_y = c3_x_y;
  c3_ab_y = c3_l_x / c3_y_y;
  c3_s_b = c3_k;
  c3_bb_y = 4.0 * c3_s_b;
  c3_e_A = c3_T;
  c3_e_B = c3_bb_y;
  c3_m_x = c3_e_A;
  c3_cb_y = c3_e_B;
  c3_n_x = c3_m_x;
  c3_db_y = c3_cb_y;
  c3_eb_y = c3_n_x / c3_db_y;
  c3_t_b = c3_k;
  c3_fb_y = 2.0 * c3_t_b;
  c3_g_a = c3_fb_y;
  c3_u_b = c3_l;
  c3_gb_y = c3_g_a * c3_u_b;
  c3_f_A = c3_TauPhi;
  c3_f_B = c3_gb_y;
  c3_o_x = c3_f_A;
  c3_hb_y = c3_f_B;
  c3_p_x = c3_o_x;
  c3_ib_y = c3_hb_y;
  c3_jb_y = c3_p_x / c3_ib_y;
  c3_v_b = c3_b;
  c3_kb_y = 4.0 * c3_v_b;
  c3_g_A = c3_TauPsi;
  c3_g_B = c3_kb_y;
  c3_q_x = c3_g_A;
  c3_lb_y = c3_g_B;
  c3_r_x = c3_q_x;
  c3_mb_y = c3_lb_y;
  c3_nb_y = c3_r_x / c3_mb_y;
  c3_w_b = c3_k;
  c3_ob_y = 4.0 * c3_w_b;
  c3_h_A = c3_T;
  c3_h_B = c3_ob_y;
  c3_s_x = c3_h_A;
  c3_pb_y = c3_h_B;
  c3_t_x = c3_s_x;
  c3_qb_y = c3_pb_y;
  c3_rb_y = c3_t_x / c3_qb_y;
  c3_x_b = c3_k;
  c3_sb_y = 2.0 * c3_x_b;
  c3_h_a = c3_sb_y;
  c3_y_b = c3_l;
  c3_tb_y = c3_h_a * c3_y_b;
  c3_i_A = c3_TauTheta;
  c3_i_B = c3_tb_y;
  c3_u_x = c3_i_A;
  c3_ub_y = c3_i_B;
  c3_v_x = c3_u_x;
  c3_vb_y = c3_ub_y;
  c3_wb_y = c3_v_x / c3_vb_y;
  c3_ab_b = c3_b;
  c3_xb_y = 4.0 * c3_ab_b;
  c3_j_A = c3_TauPsi;
  c3_j_B = c3_xb_y;
  c3_w_x = c3_j_A;
  c3_yb_y = c3_j_B;
  c3_x_x = c3_w_x;
  c3_ac_y = c3_yb_y;
  c3_bc_y = c3_x_x / c3_ac_y;
  c3_bb_b = c3_k;
  c3_cc_y = 4.0 * c3_bb_b;
  c3_k_A = c3_T;
  c3_k_B = c3_cc_y;
  c3_y_x = c3_k_A;
  c3_dc_y = c3_k_B;
  c3_ab_x = c3_y_x;
  c3_ec_y = c3_dc_y;
  c3_fc_y = c3_ab_x / c3_ec_y;
  c3_cb_b = c3_k;
  c3_gc_y = 2.0 * c3_cb_b;
  c3_i_a = c3_gc_y;
  c3_db_b = c3_l;
  c3_hc_y = c3_i_a * c3_db_b;
  c3_l_A = c3_TauPhi;
  c3_l_B = c3_hc_y;
  c3_bb_x = c3_l_A;
  c3_ic_y = c3_l_B;
  c3_cb_x = c3_bb_x;
  c3_jc_y = c3_ic_y;
  c3_kc_y = c3_cb_x / c3_jc_y;
  c3_eb_b = c3_b;
  c3_lc_y = 4.0 * c3_eb_b;
  c3_m_A = c3_TauPsi;
  c3_m_B = c3_lc_y;
  c3_db_x = c3_m_A;
  c3_mc_y = c3_m_B;
  c3_eb_x = c3_db_x;
  c3_nc_y = c3_mc_y;
  c3_oc_y = c3_eb_x / c3_nc_y;
  c3_y[0] = (c3_q_y - c3_v_y) - c3_ab_y;
  c3_y[1] = (c3_eb_y - c3_jb_y) + c3_nb_y;
  c3_y[2] = (c3_rb_y + c3_wb_y) - c3_bc_y;
  c3_y[3] = (c3_fc_y + c3_kc_y) + c3_oc_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -43);
  sf_debug_symbol_scope_pop();
  for (c3_i7 = 0; c3_i7 < 4; c3_i7++) {
    (*c3_pc_y)[c3_i7] = c3_y[c3_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_simlag2(SFc3_simlag2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i8;
  real_T c3_b_inData[4];
  int32_T c3_i9;
  real_T c3_u[4];
  const mxArray *c3_y = NULL;
  SFc3_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc3_simlag2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i8 = 0; c3_i8 < 4; c3_i8++) {
    c3_b_inData[c3_i8] = (*(real_T (*)[4])c3_inData)[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 4; c3_i9++) {
    c3_u[c3_i9] = c3_b_inData[c3_i9];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_simlag2InstanceStruct *chartInstance, const
  mxArray *c3_y, const char_T *c3_identifier, real_T c3_b_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_y), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_y);
}

static void c3_b_emlrt_marshallIn(SFc3_simlag2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[4])
{
  real_T c3_dv1[4];
  int32_T c3_i10;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c3_i10 = 0; c3_i10 < 4; c3_i10++) {
    c3_y[c3_i10] = c3_dv1[c3_i10];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_y;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y[4];
  int32_T c3_i11;
  SFc3_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc3_simlag2InstanceStruct *)chartInstanceVoid;
  c3_y = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_y), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_y);
  for (c3_i11 = 0; c3_i11 < 4; c3_i11++) {
    (*(real_T (*)[4])c3_outData)[c3_i11] = c3_b_y[c3_i11];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i12;
  real_T c3_b_inData[3];
  int32_T c3_i13;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc3_simlag2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i12 = 0; c3_i12 < 3; c3_i12++) {
    c3_b_inData[c3_i12] = (*(real_T (*)[3])c3_inData)[c3_i12];
  }

  for (c3_i13 = 0; c3_i13 < 3; c3_i13++) {
    c3_u[c3_i13] = c3_b_inData[c3_i13];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i14;
  real_T c3_b_inData[5];
  int32_T c3_i15;
  real_T c3_u[5];
  const mxArray *c3_y = NULL;
  SFc3_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc3_simlag2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i14 = 0; c3_i14 < 5; c3_i14++) {
    c3_b_inData[c3_i14] = (*(real_T (*)[5])c3_inData)[c3_i14];
  }

  for (c3_i15 = 0; c3_i15 < 5; c3_i15++) {
    c3_u[c3_i15] = c3_b_inData[c3_i15];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc3_simlag2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn(SFc3_simlag2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc3_simlag2InstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_simlag2_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[6];
  c3_ResolvedFunctionInfo (*c3_b_info)[6];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i16;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_b_info = (c3_ResolvedFunctionInfo (*)[6])c3_info;
  (*c3_b_info)[0].context = "";
  (*c3_b_info)[0].name = "mtimes";
  (*c3_b_info)[0].dominantType = "double";
  (*c3_b_info)[0].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[0].fileTimeLo = 1289519692U;
  (*c3_b_info)[0].fileTimeHi = 0U;
  (*c3_b_info)[0].mFileTimeLo = 0U;
  (*c3_b_info)[0].mFileTimeHi = 0U;
  (*c3_b_info)[1].context = "";
  (*c3_b_info)[1].name = "cos";
  (*c3_b_info)[1].dominantType = "double";
  (*c3_b_info)[1].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c3_b_info)[1].fileTimeLo = 1286818706U;
  (*c3_b_info)[1].fileTimeHi = 0U;
  (*c3_b_info)[1].mFileTimeLo = 0U;
  (*c3_b_info)[1].mFileTimeHi = 0U;
  (*c3_b_info)[2].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c3_b_info)[2].name = "eml_scalar_cos";
  (*c3_b_info)[2].dominantType = "double";
  (*c3_b_info)[2].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c3_b_info)[2].fileTimeLo = 1286818722U;
  (*c3_b_info)[2].fileTimeHi = 0U;
  (*c3_b_info)[2].mFileTimeLo = 0U;
  (*c3_b_info)[2].mFileTimeHi = 0U;
  (*c3_b_info)[3].context = "";
  (*c3_b_info)[3].name = "mrdivide";
  (*c3_b_info)[3].dominantType = "double";
  (*c3_b_info)[3].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c3_b_info)[3].fileTimeLo = 1325124138U;
  (*c3_b_info)[3].fileTimeHi = 0U;
  (*c3_b_info)[3].mFileTimeLo = 1319729966U;
  (*c3_b_info)[3].mFileTimeHi = 0U;
  (*c3_b_info)[4].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c3_b_info)[4].name = "rdivide";
  (*c3_b_info)[4].dominantType = "double";
  (*c3_b_info)[4].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c3_b_info)[4].fileTimeLo = 1286818844U;
  (*c3_b_info)[4].fileTimeHi = 0U;
  (*c3_b_info)[4].mFileTimeLo = 0U;
  (*c3_b_info)[4].mFileTimeHi = 0U;
  (*c3_b_info)[5].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c3_b_info)[5].name = "eml_div";
  (*c3_b_info)[5].dominantType = "double";
  (*c3_b_info)[5].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c3_b_info)[5].fileTimeLo = 1313347810U;
  (*c3_b_info)[5].fileTimeHi = 0U;
  (*c3_b_info)[5].mFileTimeLo = 0U;
  (*c3_b_info)[5].mFileTimeHi = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 6), FALSE);
  for (c3_i16 = 0; c3_i16 < 6; c3_i16++) {
    c3_r0 = &c3_info[c3_i16];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i16);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i16);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i16);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i16);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i16);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i16);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i16);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i16);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc3_simlag2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn(SFc3_simlag2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i17;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i17, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i17;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc3_simlag2InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_simlag2InstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_simlag2, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_simlag2), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_simlag2);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_simlag2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_simlag2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_simlag2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3912349214U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1315465321U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(193968139U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1125773276U);
}

mxArray *sf_c3_simlag2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("1qlvWVV36rLQghmNE1Uq9E");
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
      pr[0] = (double)(5);
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
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c3_simlag2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c3_simlag2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_simlag2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_simlag2InstanceStruct *chartInstance;
    chartInstance = (SFc3_simlag2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_simlag2MachineNumber_,
          3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Phi");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Theta");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Psi");
          _SFD_SET_DATA_PROPS(4,1,1,0,"dPhi");
          _SFD_SET_DATA_PROPS(5,1,1,0,"dTheta");
          _SFD_SET_DATA_PROPS(6,1,1,0,"dPsi");
          _SFD_SET_DATA_PROPS(7,1,1,0,"z");
          _SFD_SET_DATA_PROPS(8,1,1,0,"dz");
          _SFD_SET_DATA_PROPS(9,1,1,0,"Constants");
          _SFD_SET_DATA_PROPS(10,1,1,0,"II");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,757);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c3_Phi;
          real_T *c3_Theta;
          real_T *c3_Psi;
          real_T *c3_dPhi;
          real_T *c3_dTheta;
          real_T *c3_dPsi;
          real_T *c3_z;
          real_T *c3_dz;
          real_T (*c3_y)[4];
          real_T (*c3_Constants)[5];
          real_T (*c3_II)[3];
          c3_II = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
          c3_Constants = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 8);
          c3_dz = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c3_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c3_dPsi = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_dTheta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_dPhi = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c3_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_Phi);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_Theta);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_Psi);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_dPhi);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_dTheta);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_dPsi);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_z);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_dz);
          _SFD_SET_DATA_VALUE_PTR(9U, *c3_Constants);
          _SFD_SET_DATA_VALUE_PTR(10U, *c3_II);
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
  return "71d7uv3o5OcWX7EPypCmfF";
}

static void sf_opaque_initialize_c3_simlag2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_simlag2InstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c3_simlag2((SFc3_simlag2InstanceStruct*) chartInstanceVar);
  initialize_c3_simlag2((SFc3_simlag2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_simlag2(void *chartInstanceVar)
{
  enable_c3_simlag2((SFc3_simlag2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_simlag2(void *chartInstanceVar)
{
  disable_c3_simlag2((SFc3_simlag2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_simlag2(void *chartInstanceVar)
{
  sf_c3_simlag2((SFc3_simlag2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_simlag2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_simlag2((SFc3_simlag2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_simlag2();/* state var info */
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

extern void sf_internal_set_sim_state_c3_simlag2(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_simlag2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_simlag2((SFc3_simlag2InstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_simlag2(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_simlag2(S);
}

static void sf_opaque_set_sim_state_c3_simlag2(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_simlag2(S, st);
}

static void sf_opaque_terminate_c3_simlag2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_simlag2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_simlag2((SFc3_simlag2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_simlag2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_simlag2((SFc3_simlag2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_simlag2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_simlag2((SFc3_simlag2InstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_simlag2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_simlag2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
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
        infoStruct,3,10);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3619021957U));
  ssSetChecksum1(S,(2434541725U));
  ssSetChecksum2(S,(1243336229U));
  ssSetChecksum3(S,(2839941708U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_simlag2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_simlag2(SimStruct *S)
{
  SFc3_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc3_simlag2InstanceStruct *)malloc(sizeof
    (SFc3_simlag2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_simlag2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_simlag2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_simlag2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_simlag2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_simlag2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_simlag2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_simlag2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_simlag2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_simlag2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_simlag2;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_simlag2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_simlag2;
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

void c3_simlag2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_simlag2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_simlag2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_simlag2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_simlag2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

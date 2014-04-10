/* Include files */

#include "blascompat32.h"
#include "simlag2_sfun.h"
#include "c1_simlag2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "simlag2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[25] = { "Ixx", "Iyy", "Izz", "TauB",
  "Weta", "J", "CdEta", "nargin", "nargout", "w1", "w2", "w3", "w4", "II", "Phi",
  "Theta", "Psi", "dPhi", "dTheta", "dPsi", "A", "l", "b", "k", "y" };

/* Function Declarations */
static void initialize_c1_simlag2(SFc1_simlag2InstanceStruct *chartInstance);
static void initialize_params_c1_simlag2(SFc1_simlag2InstanceStruct
  *chartInstance);
static void enable_c1_simlag2(SFc1_simlag2InstanceStruct *chartInstance);
static void disable_c1_simlag2(SFc1_simlag2InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_simlag2(SFc1_simlag2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_simlag2(SFc1_simlag2InstanceStruct
  *chartInstance);
static void set_sim_state_c1_simlag2(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_st);
static void finalize_c1_simlag2(SFc1_simlag2InstanceStruct *chartInstance);
static void sf_c1_simlag2(SFc1_simlag2InstanceStruct *chartInstance);
static void c1_chartstep_c1_simlag2(SFc1_simlag2InstanceStruct *chartInstance);
static void initSimStructsc1_simlag2(SFc1_simlag2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance, const
  mxArray *c1_y, const char_T *c1_identifier, real_T c1_b_y[3]);
static void c1_b_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[42]);
static void c1_eml_scalar_eg(SFc1_simlag2InstanceStruct *chartInstance);
static real_T c1_mpower(SFc1_simlag2InstanceStruct *chartInstance, real_T c1_a);
static void c1_inv3x3(SFc1_simlag2InstanceStruct *chartInstance, real_T c1_x[9],
                      real_T c1_y[9]);
static real_T c1_norm(SFc1_simlag2InstanceStruct *chartInstance, real_T c1_x[9]);
static void c1_eml_warning(SFc1_simlag2InstanceStruct *chartInstance);
static void c1_b_eml_warning(SFc1_simlag2InstanceStruct *chartInstance, char_T
  c1_varargin_2[14]);
static void c1_b_eml_scalar_eg(SFc1_simlag2InstanceStruct *chartInstance);
static void c1_e_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_sprintf, const char_T *c1_identifier, char_T c1_y[14]);
static void c1_f_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, char_T c1_y[14]);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_g_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_h_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_simlag2, const char_T *c1_identifier);
static uint8_T c1_i_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_simlag2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_simlag2(SFc1_simlag2InstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_simlag2 = 0U;
}

static void initialize_params_c1_simlag2(SFc1_simlag2InstanceStruct
  *chartInstance)
{
}

static void enable_c1_simlag2(SFc1_simlag2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_simlag2(SFc1_simlag2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_simlag2(SFc1_simlag2InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_simlag2(SFc1_simlag2InstanceStruct
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
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_simlag2;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_simlag2(SFc1_simlag2InstanceStruct *chartInstance,
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

  chartInstance->c1_is_active_c1_simlag2 = c1_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 1)), "is_active_c1_simlag2");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_simlag2(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_simlag2(SFc1_simlag2InstanceStruct *chartInstance)
{
}

static void sf_c1_simlag2(SFc1_simlag2InstanceStruct *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  real_T *c1_w1;
  real_T *c1_w2;
  real_T *c1_w3;
  real_T *c1_w4;
  real_T *c1_Phi;
  real_T *c1_Theta;
  real_T *c1_Psi;
  real_T *c1_dPhi;
  real_T *c1_dTheta;
  real_T *c1_dPsi;
  real_T *c1_l;
  real_T *c1_b;
  real_T *c1_k;
  real_T (*c1_A)[3];
  real_T (*c1_II)[3];
  real_T (*c1_y)[3];
  c1_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c1_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c1_l = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c1_A = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 11);
  c1_dPsi = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_dTheta = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_dPhi = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_II = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c1_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_w4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_w3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_w2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_w1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_w1, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_w2, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_w3, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_w4, 3U);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_y)[c1_i2], 4U);
  }

  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_II)[c1_i3], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_Phi, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_Theta, 7U);
  _SFD_DATA_RANGE_CHECK(*c1_Psi, 8U);
  _SFD_DATA_RANGE_CHECK(*c1_dPhi, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_dTheta, 10U);
  _SFD_DATA_RANGE_CHECK(*c1_dPsi, 11U);
  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_A)[c1_i4], 12U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_l, 13U);
  _SFD_DATA_RANGE_CHECK(*c1_b, 14U);
  _SFD_DATA_RANGE_CHECK(*c1_k, 15U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_simlag2(chartInstance);
  sf_debug_check_for_state_inconsistency(_simlag2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_simlag2(SFc1_simlag2InstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_g_hoistedGlobal;
  real_T c1_h_hoistedGlobal;
  real_T c1_i_hoistedGlobal;
  real_T c1_j_hoistedGlobal;
  real_T c1_k_hoistedGlobal;
  real_T c1_l_hoistedGlobal;
  real_T c1_m_hoistedGlobal;
  real_T c1_w1;
  real_T c1_w2;
  real_T c1_w3;
  real_T c1_w4;
  int32_T c1_i5;
  real_T c1_II[3];
  real_T c1_Phi;
  real_T c1_Theta;
  real_T c1_Psi;
  real_T c1_dPhi;
  real_T c1_dTheta;
  real_T c1_dPsi;
  int32_T c1_i6;
  real_T c1_A[3];
  real_T c1_l;
  real_T c1_b;
  real_T c1_k;
  uint32_T c1_debug_family_var_map[25];
  real_T c1_Ixx;
  real_T c1_Iyy;
  real_T c1_Izz;
  real_T c1_TauB[3];
  real_T c1_Weta[9];
  real_T c1_J[9];
  real_T c1_CdEta[3];
  real_T c1_nargin = 15.0;
  real_T c1_nargout = 1.0;
  real_T c1_y[3];
  real_T c1_a;
  real_T c1_b_b;
  real_T c1_b_y;
  real_T c1_b_a;
  real_T c1_c_b;
  real_T c1_c_y;
  real_T c1_c_a;
  real_T c1_d_b;
  real_T c1_d_y;
  real_T c1_d_a;
  real_T c1_e_b;
  real_T c1_e_y;
  real_T c1_e_a;
  real_T c1_f_b;
  real_T c1_f_y;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_f_a;
  real_T c1_g_b;
  real_T c1_g_y;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_g_a;
  real_T c1_h_b;
  real_T c1_h_y;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  real_T c1_h_a[9];
  real_T c1_i_b[9];
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  real_T c1_i_y[9];
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  real_T c1_i_a;
  real_T c1_j_b;
  real_T c1_j_y;
  real_T c1_k_b;
  real_T c1_k_y;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_j_a;
  real_T c1_l_b;
  real_T c1_l_y;
  real_T c1_b_A;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_m_y;
  real_T c1_k_a;
  real_T c1_m_b;
  real_T c1_n_y;
  real_T c1_n_b;
  real_T c1_o_y;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_l_a;
  real_T c1_o_b;
  real_T c1_p_y;
  real_T c1_c_A;
  real_T c1_u_x;
  real_T c1_v_x;
  real_T c1_q_y;
  real_T c1_m_a;
  real_T c1_p_b;
  real_T c1_r_y;
  real_T c1_n_a;
  real_T c1_q_b;
  real_T c1_s_y;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_o_a;
  real_T c1_r_b;
  real_T c1_t_y;
  real_T c1_p_a;
  real_T c1_s_b;
  real_T c1_u_y;
  real_T c1_t_b;
  real_T c1_v_y;
  real_T c1_y_x;
  real_T c1_ab_x;
  real_T c1_q_a;
  real_T c1_u_b;
  real_T c1_w_y;
  real_T c1_bb_x;
  real_T c1_cb_x;
  real_T c1_r_a;
  real_T c1_v_b;
  real_T c1_x_y;
  real_T c1_d_A;
  real_T c1_db_x;
  real_T c1_eb_x;
  real_T c1_y_y;
  real_T c1_s_a;
  real_T c1_w_b;
  real_T c1_ab_y;
  real_T c1_x_b;
  real_T c1_bb_y;
  real_T c1_fb_x;
  real_T c1_gb_x;
  real_T c1_t_a;
  real_T c1_y_b;
  real_T c1_cb_y;
  real_T c1_hb_x;
  real_T c1_ib_x;
  real_T c1_u_a;
  real_T c1_ab_b;
  real_T c1_db_y;
  real_T c1_e_A;
  real_T c1_jb_x;
  real_T c1_kb_x;
  real_T c1_eb_y;
  real_T c1_v_a;
  real_T c1_bb_b;
  real_T c1_fb_y;
  real_T c1_w_a;
  real_T c1_cb_b;
  real_T c1_gb_y;
  real_T c1_db_b;
  real_T c1_hb_y;
  real_T c1_lb_x;
  real_T c1_mb_x;
  real_T c1_x_a;
  real_T c1_eb_b;
  real_T c1_ib_y;
  real_T c1_nb_x;
  real_T c1_ob_x;
  real_T c1_y_a;
  real_T c1_fb_b;
  real_T c1_jb_y;
  real_T c1_ab_a;
  real_T c1_gb_b;
  real_T c1_kb_y;
  real_T c1_bb_a;
  real_T c1_hb_b;
  real_T c1_lb_y;
  real_T c1_ib_b;
  real_T c1_mb_y;
  real_T c1_pb_x;
  real_T c1_qb_x;
  real_T c1_cb_a;
  real_T c1_jb_b;
  real_T c1_nb_y;
  real_T c1_rb_x;
  real_T c1_sb_x;
  real_T c1_db_a;
  real_T c1_kb_b;
  real_T c1_ob_y;
  real_T c1_eb_a;
  real_T c1_lb_b;
  real_T c1_pb_y;
  real_T c1_tb_x;
  real_T c1_ub_x;
  real_T c1_fb_a;
  real_T c1_mb_b;
  real_T c1_qb_y;
  real_T c1_nb_b;
  real_T c1_rb_y;
  real_T c1_gb_a;
  real_T c1_ob_b;
  real_T c1_sb_y;
  real_T c1_vb_x;
  real_T c1_wb_x;
  real_T c1_hb_a;
  real_T c1_pb_b;
  real_T c1_tb_y;
  real_T c1_xb_x;
  real_T c1_yb_x;
  real_T c1_ib_a;
  real_T c1_qb_b;
  real_T c1_ub_y;
  real_T c1_rb_b;
  real_T c1_vb_y;
  real_T c1_jb_a;
  real_T c1_sb_b;
  real_T c1_wb_y;
  real_T c1_ac_x;
  real_T c1_bc_x;
  real_T c1_kb_a;
  real_T c1_tb_b;
  real_T c1_xb_y;
  real_T c1_cc_x;
  real_T c1_dc_x;
  real_T c1_lb_a;
  real_T c1_ub_b;
  real_T c1_yb_y;
  real_T c1_mb_a;
  real_T c1_vb_b;
  real_T c1_ac_y;
  real_T c1_ec_x;
  real_T c1_fc_x;
  real_T c1_nb_a;
  real_T c1_wb_b;
  real_T c1_bc_y;
  real_T c1_gc_x;
  real_T c1_hc_x;
  real_T c1_ob_a;
  real_T c1_xb_b;
  real_T c1_cc_y;
  real_T c1_pb_a;
  real_T c1_yb_b;
  real_T c1_dc_y;
  real_T c1_ic_x;
  real_T c1_jc_x;
  real_T c1_qb_a;
  real_T c1_ac_b;
  real_T c1_ec_y;
  real_T c1_kc_x;
  real_T c1_lc_x;
  real_T c1_rb_a;
  real_T c1_bc_b;
  real_T c1_fc_y;
  real_T c1_sb_a;
  real_T c1_cc_b;
  real_T c1_gc_y;
  real_T c1_mc_x;
  real_T c1_nc_x;
  real_T c1_tb_a;
  real_T c1_dc_b;
  real_T c1_hc_y;
  real_T c1_oc_x;
  real_T c1_pc_x;
  real_T c1_ub_a;
  real_T c1_ec_b;
  real_T c1_ic_y;
  real_T c1_vb_a;
  real_T c1_fc_b;
  real_T c1_jc_y;
  real_T c1_qc_x;
  real_T c1_rc_x;
  real_T c1_wb_a;
  real_T c1_gc_b;
  real_T c1_kc_y;
  real_T c1_sc_x;
  real_T c1_tc_x;
  real_T c1_xb_a;
  real_T c1_hc_b;
  real_T c1_lc_y;
  real_T c1_yb_a;
  real_T c1_ic_b;
  real_T c1_mc_y;
  real_T c1_ac_a;
  real_T c1_jc_b;
  real_T c1_nc_y;
  real_T c1_uc_x;
  real_T c1_vc_x;
  real_T c1_bc_a;
  real_T c1_kc_b;
  real_T c1_oc_y;
  real_T c1_wc_x;
  real_T c1_xc_x;
  real_T c1_cc_a;
  real_T c1_lc_b;
  real_T c1_pc_y;
  real_T c1_dc_a;
  real_T c1_mc_b;
  real_T c1_qc_y;
  real_T c1_yc_x;
  real_T c1_ad_x;
  real_T c1_ec_a;
  real_T c1_nc_b;
  real_T c1_rc_y;
  real_T c1_bd_x;
  real_T c1_cd_x;
  real_T c1_fc_a;
  real_T c1_oc_b;
  real_T c1_sc_y;
  real_T c1_dd_x;
  real_T c1_ed_x;
  real_T c1_gc_a;
  real_T c1_pc_b;
  real_T c1_tc_y;
  real_T c1_hc_a;
  real_T c1_qc_b;
  real_T c1_uc_y;
  real_T c1_fd_x;
  real_T c1_gd_x;
  real_T c1_ic_a;
  real_T c1_rc_b;
  real_T c1_vc_y;
  real_T c1_hd_x;
  real_T c1_id_x;
  real_T c1_jc_a;
  real_T c1_sc_b;
  real_T c1_wc_y;
  real_T c1_jd_x;
  real_T c1_kd_x;
  real_T c1_kc_a;
  real_T c1_tc_b;
  real_T c1_xc_y;
  real_T c1_lc_a;
  real_T c1_uc_b;
  real_T c1_yc_y;
  real_T c1_ld_x;
  real_T c1_md_x;
  real_T c1_mc_a;
  real_T c1_vc_b;
  real_T c1_ad_y;
  real_T c1_nc_a;
  real_T c1_wc_b;
  real_T c1_bd_y;
  real_T c1_nd_x;
  real_T c1_od_x;
  real_T c1_oc_a;
  real_T c1_xc_b;
  real_T c1_cd_y;
  real_T c1_pd_x;
  real_T c1_qd_x;
  real_T c1_pc_a;
  real_T c1_yc_b;
  real_T c1_dd_y;
  real_T c1_qc_a;
  real_T c1_ad_b;
  real_T c1_ed_y;
  real_T c1_rd_x;
  real_T c1_sd_x;
  real_T c1_rc_a;
  real_T c1_bd_b;
  real_T c1_fd_y;
  real_T c1_td_x;
  real_T c1_ud_x;
  real_T c1_sc_a;
  real_T c1_cd_b;
  real_T c1_gd_y;
  real_T c1_tc_a;
  real_T c1_dd_b;
  real_T c1_hd_y;
  real_T c1_vd_x;
  real_T c1_wd_x;
  real_T c1_uc_a;
  real_T c1_ed_b;
  real_T c1_id_y;
  real_T c1_xd_x;
  real_T c1_yd_x;
  real_T c1_vc_a;
  real_T c1_fd_b;
  real_T c1_jd_y;
  real_T c1_wc_a;
  real_T c1_gd_b;
  real_T c1_kd_y;
  real_T c1_ae_x;
  real_T c1_be_x;
  real_T c1_xc_a;
  real_T c1_hd_b;
  real_T c1_ld_y;
  real_T c1_ce_x;
  real_T c1_de_x;
  real_T c1_yc_a;
  real_T c1_id_b;
  real_T c1_md_y;
  real_T c1_jd_b;
  real_T c1_nd_y;
  real_T c1_ad_a;
  real_T c1_kd_b;
  real_T c1_od_y;
  real_T c1_ee_x;
  real_T c1_fe_x;
  real_T c1_bd_a;
  real_T c1_ld_b;
  real_T c1_pd_y;
  real_T c1_ge_x;
  real_T c1_he_x;
  real_T c1_cd_a;
  real_T c1_md_b;
  real_T c1_qd_y;
  real_T c1_ie_x;
  real_T c1_je_x;
  real_T c1_dd_a;
  real_T c1_nd_b;
  real_T c1_rd_y;
  real_T c1_od_b;
  real_T c1_sd_y;
  real_T c1_ed_a;
  real_T c1_pd_b;
  real_T c1_td_y;
  real_T c1_ke_x;
  real_T c1_le_x;
  real_T c1_fd_a;
  real_T c1_qd_b;
  real_T c1_ud_y;
  real_T c1_me_x;
  real_T c1_ne_x;
  real_T c1_gd_a;
  real_T c1_rd_b;
  real_T c1_vd_y;
  real_T c1_oe_x;
  real_T c1_pe_x;
  real_T c1_hd_a;
  real_T c1_sd_b;
  real_T c1_wd_y;
  real_T c1_id_a;
  real_T c1_td_b;
  real_T c1_xd_y;
  real_T c1_jd_a;
  real_T c1_ud_b;
  real_T c1_yd_y;
  real_T c1_qe_x;
  real_T c1_re_x;
  real_T c1_kd_a;
  real_T c1_vd_b;
  real_T c1_ae_y;
  real_T c1_se_x;
  real_T c1_te_x;
  real_T c1_ld_a;
  real_T c1_wd_b;
  real_T c1_be_y;
  real_T c1_ue_x;
  real_T c1_ve_x;
  real_T c1_md_a;
  real_T c1_xd_b;
  real_T c1_ce_y;
  real_T c1_nd_a;
  real_T c1_yd_b;
  real_T c1_de_y;
  real_T c1_we_x;
  real_T c1_xe_x;
  real_T c1_od_a;
  real_T c1_ae_b;
  real_T c1_ee_y;
  real_T c1_ye_x;
  real_T c1_af_x;
  real_T c1_pd_a;
  real_T c1_be_b;
  real_T c1_fe_y;
  real_T c1_bf_x;
  real_T c1_cf_x;
  real_T c1_qd_a;
  real_T c1_ce_b;
  real_T c1_ge_y;
  real_T c1_de_b;
  real_T c1_he_y;
  real_T c1_rd_a;
  real_T c1_ee_b;
  real_T c1_ie_y;
  real_T c1_sd_a;
  real_T c1_fe_b;
  real_T c1_je_y;
  real_T c1_df_x;
  real_T c1_ef_x;
  real_T c1_td_a;
  real_T c1_ge_b;
  real_T c1_ke_y;
  real_T c1_ff_x;
  real_T c1_gf_x;
  real_T c1_ud_a;
  real_T c1_he_b;
  real_T c1_le_y;
  real_T c1_ie_b;
  real_T c1_me_y;
  real_T c1_vd_a;
  real_T c1_je_b;
  real_T c1_ne_y;
  real_T c1_wd_a;
  real_T c1_ke_b;
  real_T c1_oe_y;
  real_T c1_hf_x;
  real_T c1_if_x;
  real_T c1_xd_a;
  real_T c1_le_b;
  real_T c1_pe_y;
  real_T c1_jf_x;
  real_T c1_kf_x;
  real_T c1_yd_a;
  real_T c1_me_b;
  real_T c1_qe_y;
  real_T c1_lf_x;
  real_T c1_mf_x;
  real_T c1_ae_a;
  real_T c1_ne_b;
  real_T c1_re_y;
  real_T c1_oe_b;
  real_T c1_se_y;
  real_T c1_be_a;
  real_T c1_pe_b;
  real_T c1_te_y;
  real_T c1_ce_a;
  real_T c1_qe_b;
  real_T c1_ue_y;
  real_T c1_nf_x;
  real_T c1_of_x;
  real_T c1_de_a;
  real_T c1_re_b;
  real_T c1_ve_y;
  real_T c1_pf_x;
  real_T c1_qf_x;
  real_T c1_ee_a;
  real_T c1_se_b;
  real_T c1_we_y;
  real_T c1_rf_x;
  real_T c1_sf_x;
  real_T c1_fe_a;
  real_T c1_te_b;
  real_T c1_xe_y;
  int32_T c1_i28;
  int32_T c1_i29;
  real_T c1_ge_a[9];
  int32_T c1_i30;
  real_T c1_he_a[9];
  real_T c1_n1x;
  int32_T c1_i31;
  real_T c1_ye_y[9];
  real_T c1_n1xinv;
  real_T c1_ie_a;
  real_T c1_ue_b;
  real_T c1_af_y;
  real_T c1_rc;
  real_T c1_tf_x;
  boolean_T c1_ve_b;
  real_T c1_uf_x;
  int32_T c1_i32;
  static char_T c1_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c1_u[8];
  const mxArray *c1_bf_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_cf_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_df_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_ef_y = NULL;
  char_T c1_str[14];
  int32_T c1_i33;
  char_T c1_b_str[14];
  int32_T c1_i34;
  real_T c1_we_b[3];
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  real_T c1_C[3];
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  real_T (*c1_ff_y)[3];
  real_T *c1_b_k;
  real_T *c1_xe_b;
  real_T *c1_b_l;
  real_T *c1_b_dPsi;
  real_T *c1_b_dTheta;
  real_T *c1_b_dPhi;
  real_T *c1_b_Psi;
  real_T *c1_b_Theta;
  real_T *c1_b_Phi;
  real_T *c1_b_w4;
  real_T *c1_b_w3;
  real_T *c1_b_w2;
  real_T *c1_b_w1;
  real_T (*c1_f_A)[3];
  real_T (*c1_b_II)[3];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c1_b_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c1_xe_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c1_b_l = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c1_f_A = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 11);
  c1_b_dPsi = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_b_dTheta = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_b_dPhi = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_b_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_b_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_b_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_II = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c1_ff_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_w4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_w3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_w2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_w1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_w1;
  c1_b_hoistedGlobal = *c1_b_w2;
  c1_c_hoistedGlobal = *c1_b_w3;
  c1_d_hoistedGlobal = *c1_b_w4;
  c1_e_hoistedGlobal = *c1_b_Phi;
  c1_f_hoistedGlobal = *c1_b_Theta;
  c1_g_hoistedGlobal = *c1_b_Psi;
  c1_h_hoistedGlobal = *c1_b_dPhi;
  c1_i_hoistedGlobal = *c1_b_dTheta;
  c1_j_hoistedGlobal = *c1_b_dPsi;
  c1_k_hoistedGlobal = *c1_b_l;
  c1_l_hoistedGlobal = *c1_xe_b;
  c1_m_hoistedGlobal = *c1_b_k;
  c1_w1 = c1_hoistedGlobal;
  c1_w2 = c1_b_hoistedGlobal;
  c1_w3 = c1_c_hoistedGlobal;
  c1_w4 = c1_d_hoistedGlobal;
  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    c1_II[c1_i5] = (*c1_b_II)[c1_i5];
  }

  c1_Phi = c1_e_hoistedGlobal;
  c1_Theta = c1_f_hoistedGlobal;
  c1_Psi = c1_g_hoistedGlobal;
  c1_dPhi = c1_h_hoistedGlobal;
  c1_dTheta = c1_i_hoistedGlobal;
  c1_dPsi = c1_j_hoistedGlobal;
  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    c1_A[c1_i6] = (*c1_f_A)[c1_i6];
  }

  c1_l = c1_k_hoistedGlobal;
  c1_b = c1_l_hoistedGlobal;
  c1_k = c1_m_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 25U, 25U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_Ixx, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Iyy, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Izz, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_TauB, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Weta, 4U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_J, 5U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_CdEta, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 8U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_w1, 9U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_w2, 10U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_w3, 11U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_w4, 12U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_II, 13U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Phi, 14U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Theta, 15U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Psi, 16U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_dPhi, 17U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_dTheta, 18U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_dPsi, 19U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_A, 20U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_l, 21U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_b, 22U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_k, 23U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_y, 24U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_Ixx = c1_II[0];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_Iyy = c1_II[1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_Izz = c1_II[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  c1_a = c1_l;
  c1_b_b = c1_k;
  c1_b_y = c1_a * c1_b_b;
  c1_b_a = c1_b_y;
  c1_c_b = c1_w4 - c1_w2;
  c1_c_y = c1_b_a * c1_c_b;
  c1_c_a = c1_l;
  c1_d_b = c1_k;
  c1_d_y = c1_c_a * c1_d_b;
  c1_d_a = c1_d_y;
  c1_e_b = c1_w3 - c1_w1;
  c1_e_y = c1_d_a * c1_e_b;
  c1_e_a = c1_b;
  c1_f_b = ((c1_w1 + c1_w3) - c1_w2) - c1_w4;
  c1_f_y = c1_e_a * c1_f_b;
  c1_TauB[0] = c1_c_y;
  c1_TauB[1] = c1_e_y;
  c1_TauB[2] = c1_f_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_x = c1_Theta;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarSin(c1_b_x);
  c1_c_x = c1_Phi;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarCos(c1_d_x);
  c1_e_x = c1_Theta;
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarCos(c1_f_x);
  c1_g_x = c1_Phi;
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarSin(c1_h_x);
  c1_f_a = c1_f_x;
  c1_g_b = c1_h_x;
  c1_g_y = c1_f_a * c1_g_b;
  c1_i_x = c1_Phi;
  c1_j_x = c1_i_x;
  c1_j_x = muDoubleScalarSin(c1_j_x);
  c1_k_x = c1_Theta;
  c1_l_x = c1_k_x;
  c1_l_x = muDoubleScalarCos(c1_l_x);
  c1_m_x = c1_Phi;
  c1_n_x = c1_m_x;
  c1_n_x = muDoubleScalarCos(c1_n_x);
  c1_g_a = c1_l_x;
  c1_h_b = c1_n_x;
  c1_h_y = c1_g_a * c1_h_b;
  c1_Weta[0] = 1.0;
  c1_Weta[3] = 0.0;
  c1_Weta[6] = -c1_b_x;
  c1_Weta[1] = 0.0;
  c1_Weta[4] = c1_d_x;
  c1_Weta[7] = c1_g_y;
  c1_Weta[2] = 0.0;
  c1_Weta[5] = -c1_j_x;
  c1_Weta[8] = c1_h_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  c1_i7 = 0;
  for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
    c1_i9 = 0;
    for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
      c1_h_a[c1_i10 + c1_i7] = c1_Weta[c1_i9 + c1_i8];
      c1_i9 += 3;
    }

    c1_i7 += 3;
  }

  c1_i_b[0] = c1_Ixx;
  c1_i_b[3] = 0.0;
  c1_i_b[6] = 0.0;
  c1_i_b[1] = 0.0;
  c1_i_b[4] = c1_Iyy;
  c1_i_b[7] = 0.0;
  c1_i_b[2] = 0.0;
  c1_i_b[5] = 0.0;
  c1_i_b[8] = c1_Izz;
  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
    c1_i12 = 0;
    for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
      c1_i_y[c1_i12 + c1_i11] = 0.0;
      c1_i14 = 0;
      for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
        c1_i_y[c1_i12 + c1_i11] += c1_h_a[c1_i14 + c1_i11] * c1_i_b[c1_i15 +
          c1_i12];
        c1_i14 += 3;
      }

      c1_i12 += 3;
    }
  }

  for (c1_i16 = 0; c1_i16 < 9; c1_i16++) {
    c1_i_b[c1_i16] = c1_Weta[c1_i16];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i17 = 0; c1_i17 < 9; c1_i17++) {
    c1_J[c1_i17] = 0.0;
  }

  for (c1_i18 = 0; c1_i18 < 9; c1_i18++) {
    c1_J[c1_i18] = 0.0;
  }

  for (c1_i19 = 0; c1_i19 < 9; c1_i19++) {
    c1_h_a[c1_i19] = c1_J[c1_i19];
  }

  for (c1_i20 = 0; c1_i20 < 9; c1_i20++) {
    c1_J[c1_i20] = c1_h_a[c1_i20];
  }

  for (c1_i21 = 0; c1_i21 < 9; c1_i21++) {
    c1_h_a[c1_i21] = c1_J[c1_i21];
  }

  for (c1_i22 = 0; c1_i22 < 9; c1_i22++) {
    c1_J[c1_i22] = c1_h_a[c1_i22];
  }

  for (c1_i23 = 0; c1_i23 < 3; c1_i23++) {
    c1_i24 = 0;
    for (c1_i25 = 0; c1_i25 < 3; c1_i25++) {
      c1_J[c1_i24 + c1_i23] = 0.0;
      c1_i26 = 0;
      for (c1_i27 = 0; c1_i27 < 3; c1_i27++) {
        c1_J[c1_i24 + c1_i23] += c1_i_y[c1_i26 + c1_i23] * c1_i_b[c1_i27 +
          c1_i24];
        c1_i26 += 3;
      }

      c1_i24 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
  c1_i_a = c1_Iyy;
  c1_j_b = c1_mpower(chartInstance, c1_dTheta);
  c1_j_y = c1_i_a * c1_j_b;
  c1_k_b = c1_Phi;
  c1_k_y = 2.0 * c1_k_b;
  c1_o_x = c1_k_y;
  c1_p_x = c1_o_x;
  c1_p_x = muDoubleScalarSin(c1_p_x);
  c1_j_a = c1_j_y;
  c1_l_b = c1_p_x;
  c1_l_y = c1_j_a * c1_l_b;
  c1_b_A = c1_l_y;
  c1_q_x = c1_b_A;
  c1_r_x = c1_q_x;
  c1_m_y = c1_r_x / 2.0;
  c1_k_a = c1_Izz;
  c1_m_b = c1_mpower(chartInstance, c1_dTheta);
  c1_n_y = c1_k_a * c1_m_b;
  c1_n_b = c1_Phi;
  c1_o_y = 2.0 * c1_n_b;
  c1_s_x = c1_o_y;
  c1_t_x = c1_s_x;
  c1_t_x = muDoubleScalarSin(c1_t_x);
  c1_l_a = c1_n_y;
  c1_o_b = c1_t_x;
  c1_p_y = c1_l_a * c1_o_b;
  c1_c_A = c1_p_y;
  c1_u_x = c1_c_A;
  c1_v_x = c1_u_x;
  c1_q_y = c1_v_x / 2.0;
  c1_m_a = c1_Ixx;
  c1_p_b = c1_dPsi;
  c1_r_y = c1_m_a * c1_p_b;
  c1_n_a = c1_r_y;
  c1_q_b = c1_dTheta;
  c1_s_y = c1_n_a * c1_q_b;
  c1_w_x = c1_Theta;
  c1_x_x = c1_w_x;
  c1_x_x = muDoubleScalarCos(c1_x_x);
  c1_o_a = c1_s_y;
  c1_r_b = c1_x_x;
  c1_t_y = c1_o_a * c1_r_b;
  c1_p_a = c1_Iyy;
  c1_s_b = c1_mpower(chartInstance, c1_dPsi);
  c1_u_y = c1_p_a * c1_s_b;
  c1_t_b = c1_Phi;
  c1_v_y = 2.0 * c1_t_b;
  c1_y_x = c1_v_y;
  c1_ab_x = c1_y_x;
  c1_ab_x = muDoubleScalarSin(c1_ab_x);
  c1_q_a = c1_u_y;
  c1_u_b = c1_ab_x;
  c1_w_y = c1_q_a * c1_u_b;
  c1_bb_x = c1_Theta;
  c1_cb_x = c1_bb_x;
  c1_cb_x = muDoubleScalarCos(c1_cb_x);
  c1_r_a = c1_w_y;
  c1_v_b = c1_mpower(chartInstance, c1_cb_x);
  c1_x_y = c1_r_a * c1_v_b;
  c1_d_A = c1_x_y;
  c1_db_x = c1_d_A;
  c1_eb_x = c1_db_x;
  c1_y_y = c1_eb_x / 2.0;
  c1_s_a = c1_Izz;
  c1_w_b = c1_mpower(chartInstance, c1_dPsi);
  c1_ab_y = c1_s_a * c1_w_b;
  c1_x_b = c1_Phi;
  c1_bb_y = 2.0 * c1_x_b;
  c1_fb_x = c1_bb_y;
  c1_gb_x = c1_fb_x;
  c1_gb_x = muDoubleScalarSin(c1_gb_x);
  c1_t_a = c1_ab_y;
  c1_y_b = c1_gb_x;
  c1_cb_y = c1_t_a * c1_y_b;
  c1_hb_x = c1_Theta;
  c1_ib_x = c1_hb_x;
  c1_ib_x = muDoubleScalarCos(c1_ib_x);
  c1_u_a = c1_cb_y;
  c1_ab_b = c1_mpower(chartInstance, c1_ib_x);
  c1_db_y = c1_u_a * c1_ab_b;
  c1_e_A = c1_db_y;
  c1_jb_x = c1_e_A;
  c1_kb_x = c1_jb_x;
  c1_eb_y = c1_kb_x / 2.0;
  c1_v_a = c1_Iyy;
  c1_bb_b = c1_dPsi;
  c1_fb_y = c1_v_a * c1_bb_b;
  c1_w_a = c1_fb_y;
  c1_cb_b = c1_dTheta;
  c1_gb_y = c1_w_a * c1_cb_b;
  c1_db_b = c1_Phi;
  c1_hb_y = 2.0 * c1_db_b;
  c1_lb_x = c1_hb_y;
  c1_mb_x = c1_lb_x;
  c1_mb_x = muDoubleScalarCos(c1_mb_x);
  c1_x_a = c1_gb_y;
  c1_eb_b = c1_mb_x;
  c1_ib_y = c1_x_a * c1_eb_b;
  c1_nb_x = c1_Theta;
  c1_ob_x = c1_nb_x;
  c1_ob_x = muDoubleScalarCos(c1_ob_x);
  c1_y_a = c1_ib_y;
  c1_fb_b = c1_ob_x;
  c1_jb_y = c1_y_a * c1_fb_b;
  c1_ab_a = c1_Izz;
  c1_gb_b = c1_dPsi;
  c1_kb_y = c1_ab_a * c1_gb_b;
  c1_bb_a = c1_kb_y;
  c1_hb_b = c1_dTheta;
  c1_lb_y = c1_bb_a * c1_hb_b;
  c1_ib_b = c1_Phi;
  c1_mb_y = 2.0 * c1_ib_b;
  c1_pb_x = c1_mb_y;
  c1_qb_x = c1_pb_x;
  c1_qb_x = muDoubleScalarCos(c1_qb_x);
  c1_cb_a = c1_lb_y;
  c1_jb_b = c1_qb_x;
  c1_nb_y = c1_cb_a * c1_jb_b;
  c1_rb_x = c1_Theta;
  c1_sb_x = c1_rb_x;
  c1_sb_x = muDoubleScalarCos(c1_sb_x);
  c1_db_a = c1_nb_y;
  c1_kb_b = c1_sb_x;
  c1_ob_y = c1_db_a * c1_kb_b;
  c1_eb_a = c1_Ixx;
  c1_lb_b = c1_dPsi;
  c1_pb_y = c1_eb_a * c1_lb_b;
  c1_tb_x = c1_Theta;
  c1_ub_x = c1_tb_x;
  c1_ub_x = muDoubleScalarCos(c1_ub_x);
  c1_fb_a = c1_pb_y;
  c1_mb_b = c1_ub_x;
  c1_qb_y = c1_fb_a * c1_mb_b;
  c1_nb_b = c1_Iyy;
  c1_rb_y = 2.0 * c1_nb_b;
  c1_gb_a = c1_rb_y;
  c1_ob_b = c1_dTheta;
  c1_sb_y = c1_gb_a * c1_ob_b;
  c1_vb_x = c1_Phi;
  c1_wb_x = c1_vb_x;
  c1_wb_x = muDoubleScalarCos(c1_wb_x);
  c1_hb_a = c1_sb_y;
  c1_pb_b = c1_wb_x;
  c1_tb_y = c1_hb_a * c1_pb_b;
  c1_xb_x = c1_Phi;
  c1_yb_x = c1_xb_x;
  c1_yb_x = muDoubleScalarSin(c1_yb_x);
  c1_ib_a = c1_tb_y;
  c1_qb_b = c1_yb_x;
  c1_ub_y = c1_ib_a * c1_qb_b;
  c1_rb_b = c1_Izz;
  c1_vb_y = 2.0 * c1_rb_b;
  c1_jb_a = c1_vb_y;
  c1_sb_b = c1_dTheta;
  c1_wb_y = c1_jb_a * c1_sb_b;
  c1_ac_x = c1_Phi;
  c1_bc_x = c1_ac_x;
  c1_bc_x = muDoubleScalarCos(c1_bc_x);
  c1_kb_a = c1_wb_y;
  c1_tb_b = c1_bc_x;
  c1_xb_y = c1_kb_a * c1_tb_b;
  c1_cc_x = c1_Phi;
  c1_dc_x = c1_cc_x;
  c1_dc_x = muDoubleScalarSin(c1_dc_x);
  c1_lb_a = c1_xb_y;
  c1_ub_b = c1_dc_x;
  c1_yb_y = c1_lb_a * c1_ub_b;
  c1_mb_a = c1_Iyy;
  c1_vb_b = c1_dPsi;
  c1_ac_y = c1_mb_a * c1_vb_b;
  c1_ec_x = c1_Phi;
  c1_fc_x = c1_ec_x;
  c1_fc_x = muDoubleScalarCos(c1_fc_x);
  c1_nb_a = c1_ac_y;
  c1_wb_b = c1_mpower(chartInstance, c1_fc_x);
  c1_bc_y = c1_nb_a * c1_wb_b;
  c1_gc_x = c1_Theta;
  c1_hc_x = c1_gc_x;
  c1_hc_x = muDoubleScalarCos(c1_hc_x);
  c1_ob_a = c1_bc_y;
  c1_xb_b = c1_hc_x;
  c1_cc_y = c1_ob_a * c1_xb_b;
  c1_pb_a = c1_Izz;
  c1_yb_b = c1_dPsi;
  c1_dc_y = c1_pb_a * c1_yb_b;
  c1_ic_x = c1_Phi;
  c1_jc_x = c1_ic_x;
  c1_jc_x = muDoubleScalarCos(c1_jc_x);
  c1_qb_a = c1_dc_y;
  c1_ac_b = c1_mpower(chartInstance, c1_jc_x);
  c1_ec_y = c1_qb_a * c1_ac_b;
  c1_kc_x = c1_Theta;
  c1_lc_x = c1_kc_x;
  c1_lc_x = muDoubleScalarCos(c1_lc_x);
  c1_rb_a = c1_ec_y;
  c1_bc_b = c1_lc_x;
  c1_fc_y = c1_rb_a * c1_bc_b;
  c1_sb_a = c1_Iyy;
  c1_cc_b = c1_dPsi;
  c1_gc_y = c1_sb_a * c1_cc_b;
  c1_mc_x = c1_Theta;
  c1_nc_x = c1_mc_x;
  c1_nc_x = muDoubleScalarCos(c1_nc_x);
  c1_tb_a = c1_gc_y;
  c1_dc_b = c1_nc_x;
  c1_hc_y = c1_tb_a * c1_dc_b;
  c1_oc_x = c1_Phi;
  c1_pc_x = c1_oc_x;
  c1_pc_x = muDoubleScalarSin(c1_pc_x);
  c1_ub_a = c1_hc_y;
  c1_ec_b = c1_mpower(chartInstance, c1_pc_x);
  c1_ic_y = c1_ub_a * c1_ec_b;
  c1_vb_a = c1_Izz;
  c1_fc_b = c1_dPsi;
  c1_jc_y = c1_vb_a * c1_fc_b;
  c1_qc_x = c1_Theta;
  c1_rc_x = c1_qc_x;
  c1_rc_x = muDoubleScalarCos(c1_rc_x);
  c1_wb_a = c1_jc_y;
  c1_gc_b = c1_rc_x;
  c1_kc_y = c1_wb_a * c1_gc_b;
  c1_sc_x = c1_Phi;
  c1_tc_x = c1_sc_x;
  c1_tc_x = muDoubleScalarSin(c1_tc_x);
  c1_xb_a = c1_kc_y;
  c1_hc_b = c1_mpower(chartInstance, c1_tc_x);
  c1_lc_y = c1_xb_a * c1_hc_b;
  c1_yb_a = c1_dPhi;
  c1_ic_b = (((((c1_qb_y - c1_ub_y) + c1_yb_y) + c1_cc_y) - c1_fc_y) - c1_ic_y)
    + c1_lc_y;
  c1_mc_y = c1_yb_a * c1_ic_b;
  c1_ac_a = c1_Ixx;
  c1_jc_b = c1_mpower(chartInstance, c1_dPsi);
  c1_nc_y = c1_ac_a * c1_jc_b;
  c1_uc_x = c1_Theta;
  c1_vc_x = c1_uc_x;
  c1_vc_x = muDoubleScalarCos(c1_vc_x);
  c1_bc_a = c1_nc_y;
  c1_kc_b = c1_vc_x;
  c1_oc_y = c1_bc_a * c1_kc_b;
  c1_wc_x = c1_Theta;
  c1_xc_x = c1_wc_x;
  c1_xc_x = muDoubleScalarSin(c1_xc_x);
  c1_cc_a = c1_oc_y;
  c1_lc_b = c1_xc_x;
  c1_pc_y = c1_cc_a * c1_lc_b;
  c1_dc_a = c1_Iyy;
  c1_mc_b = c1_mpower(chartInstance, c1_dPsi);
  c1_qc_y = c1_dc_a * c1_mc_b;
  c1_yc_x = c1_Theta;
  c1_ad_x = c1_yc_x;
  c1_ad_x = muDoubleScalarCos(c1_ad_x);
  c1_ec_a = c1_qc_y;
  c1_nc_b = c1_ad_x;
  c1_rc_y = c1_ec_a * c1_nc_b;
  c1_bd_x = c1_Phi;
  c1_cd_x = c1_bd_x;
  c1_cd_x = muDoubleScalarSin(c1_cd_x);
  c1_fc_a = c1_rc_y;
  c1_oc_b = c1_mpower(chartInstance, c1_cd_x);
  c1_sc_y = c1_fc_a * c1_oc_b;
  c1_dd_x = c1_Theta;
  c1_ed_x = c1_dd_x;
  c1_ed_x = muDoubleScalarSin(c1_ed_x);
  c1_gc_a = c1_sc_y;
  c1_pc_b = c1_ed_x;
  c1_tc_y = c1_gc_a * c1_pc_b;
  c1_hc_a = c1_Izz;
  c1_qc_b = c1_mpower(chartInstance, c1_dPsi);
  c1_uc_y = c1_hc_a * c1_qc_b;
  c1_fd_x = c1_Phi;
  c1_gd_x = c1_fd_x;
  c1_gd_x = muDoubleScalarCos(c1_gd_x);
  c1_ic_a = c1_uc_y;
  c1_rc_b = c1_mpower(chartInstance, c1_gd_x);
  c1_vc_y = c1_ic_a * c1_rc_b;
  c1_hd_x = c1_Theta;
  c1_id_x = c1_hd_x;
  c1_id_x = muDoubleScalarCos(c1_id_x);
  c1_jc_a = c1_vc_y;
  c1_sc_b = c1_id_x;
  c1_wc_y = c1_jc_a * c1_sc_b;
  c1_jd_x = c1_Theta;
  c1_kd_x = c1_jd_x;
  c1_kd_x = muDoubleScalarSin(c1_kd_x);
  c1_kc_a = c1_wc_y;
  c1_tc_b = c1_kd_x;
  c1_xc_y = c1_kc_a * c1_tc_b;
  c1_lc_a = c1_Ixx;
  c1_uc_b = c1_dTheta;
  c1_yc_y = c1_lc_a * c1_uc_b;
  c1_ld_x = c1_Theta;
  c1_md_x = c1_ld_x;
  c1_md_x = muDoubleScalarCos(c1_md_x);
  c1_mc_a = c1_yc_y;
  c1_vc_b = c1_md_x;
  c1_ad_y = c1_mc_a * c1_vc_b;
  c1_nc_a = c1_Iyy;
  c1_wc_b = c1_dTheta;
  c1_bd_y = c1_nc_a * c1_wc_b;
  c1_nd_x = c1_Phi;
  c1_od_x = c1_nd_x;
  c1_od_x = muDoubleScalarCos(c1_od_x);
  c1_oc_a = c1_bd_y;
  c1_xc_b = c1_mpower(chartInstance, c1_od_x);
  c1_cd_y = c1_oc_a * c1_xc_b;
  c1_pd_x = c1_Theta;
  c1_qd_x = c1_pd_x;
  c1_qd_x = muDoubleScalarCos(c1_qd_x);
  c1_pc_a = c1_cd_y;
  c1_yc_b = c1_qd_x;
  c1_dd_y = c1_pc_a * c1_yc_b;
  c1_qc_a = c1_Izz;
  c1_ad_b = c1_dTheta;
  c1_ed_y = c1_qc_a * c1_ad_b;
  c1_rd_x = c1_Phi;
  c1_sd_x = c1_rd_x;
  c1_sd_x = muDoubleScalarCos(c1_sd_x);
  c1_rc_a = c1_ed_y;
  c1_bd_b = c1_mpower(chartInstance, c1_sd_x);
  c1_fd_y = c1_rc_a * c1_bd_b;
  c1_td_x = c1_Theta;
  c1_ud_x = c1_td_x;
  c1_ud_x = muDoubleScalarCos(c1_ud_x);
  c1_sc_a = c1_fd_y;
  c1_cd_b = c1_ud_x;
  c1_gd_y = c1_sc_a * c1_cd_b;
  c1_tc_a = c1_Iyy;
  c1_dd_b = c1_dTheta;
  c1_hd_y = c1_tc_a * c1_dd_b;
  c1_vd_x = c1_Theta;
  c1_wd_x = c1_vd_x;
  c1_wd_x = muDoubleScalarCos(c1_wd_x);
  c1_uc_a = c1_hd_y;
  c1_ed_b = c1_wd_x;
  c1_id_y = c1_uc_a * c1_ed_b;
  c1_xd_x = c1_Phi;
  c1_yd_x = c1_xd_x;
  c1_yd_x = muDoubleScalarSin(c1_yd_x);
  c1_vc_a = c1_id_y;
  c1_fd_b = c1_mpower(chartInstance, c1_yd_x);
  c1_jd_y = c1_vc_a * c1_fd_b;
  c1_wc_a = c1_Izz;
  c1_gd_b = c1_dTheta;
  c1_kd_y = c1_wc_a * c1_gd_b;
  c1_ae_x = c1_Theta;
  c1_be_x = c1_ae_x;
  c1_be_x = muDoubleScalarCos(c1_be_x);
  c1_xc_a = c1_kd_y;
  c1_hd_b = c1_be_x;
  c1_ld_y = c1_xc_a * c1_hd_b;
  c1_ce_x = c1_Phi;
  c1_de_x = c1_ce_x;
  c1_de_x = muDoubleScalarSin(c1_de_x);
  c1_yc_a = c1_ld_y;
  c1_id_b = c1_mpower(chartInstance, c1_de_x);
  c1_md_y = c1_yc_a * c1_id_b;
  c1_jd_b = c1_Iyy;
  c1_nd_y = 2.0 * c1_jd_b;
  c1_ad_a = c1_nd_y;
  c1_kd_b = c1_dPsi;
  c1_od_y = c1_ad_a * c1_kd_b;
  c1_ee_x = c1_Phi;
  c1_fe_x = c1_ee_x;
  c1_fe_x = muDoubleScalarCos(c1_fe_x);
  c1_bd_a = c1_od_y;
  c1_ld_b = c1_fe_x;
  c1_pd_y = c1_bd_a * c1_ld_b;
  c1_ge_x = c1_Theta;
  c1_he_x = c1_ge_x;
  c1_he_x = muDoubleScalarCos(c1_he_x);
  c1_cd_a = c1_pd_y;
  c1_md_b = c1_mpower(chartInstance, c1_he_x);
  c1_qd_y = c1_cd_a * c1_md_b;
  c1_ie_x = c1_Phi;
  c1_je_x = c1_ie_x;
  c1_je_x = muDoubleScalarSin(c1_je_x);
  c1_dd_a = c1_qd_y;
  c1_nd_b = c1_je_x;
  c1_rd_y = c1_dd_a * c1_nd_b;
  c1_od_b = c1_Izz;
  c1_sd_y = 2.0 * c1_od_b;
  c1_ed_a = c1_sd_y;
  c1_pd_b = c1_dPsi;
  c1_td_y = c1_ed_a * c1_pd_b;
  c1_ke_x = c1_Phi;
  c1_le_x = c1_ke_x;
  c1_le_x = muDoubleScalarCos(c1_le_x);
  c1_fd_a = c1_td_y;
  c1_qd_b = c1_le_x;
  c1_ud_y = c1_fd_a * c1_qd_b;
  c1_me_x = c1_Theta;
  c1_ne_x = c1_me_x;
  c1_ne_x = muDoubleScalarCos(c1_ne_x);
  c1_gd_a = c1_ud_y;
  c1_rd_b = c1_mpower(chartInstance, c1_ne_x);
  c1_vd_y = c1_gd_a * c1_rd_b;
  c1_oe_x = c1_Phi;
  c1_pe_x = c1_oe_x;
  c1_pe_x = muDoubleScalarSin(c1_pe_x);
  c1_hd_a = c1_vd_y;
  c1_sd_b = c1_pe_x;
  c1_wd_y = c1_hd_a * c1_sd_b;
  c1_id_a = -c1_dPhi;
  c1_td_b = (((((c1_ad_y - c1_dd_y) + c1_gd_y) + c1_jd_y) - c1_md_y) - c1_rd_y)
    + c1_wd_y;
  c1_xd_y = c1_id_a * c1_td_b;
  c1_jd_a = c1_Iyy;
  c1_ud_b = c1_mpower(chartInstance, c1_dTheta);
  c1_yd_y = c1_jd_a * c1_ud_b;
  c1_qe_x = c1_Phi;
  c1_re_x = c1_qe_x;
  c1_re_x = muDoubleScalarCos(c1_re_x);
  c1_kd_a = c1_yd_y;
  c1_vd_b = c1_re_x;
  c1_ae_y = c1_kd_a * c1_vd_b;
  c1_se_x = c1_Phi;
  c1_te_x = c1_se_x;
  c1_te_x = muDoubleScalarSin(c1_te_x);
  c1_ld_a = c1_ae_y;
  c1_wd_b = c1_te_x;
  c1_be_y = c1_ld_a * c1_wd_b;
  c1_ue_x = c1_Theta;
  c1_ve_x = c1_ue_x;
  c1_ve_x = muDoubleScalarSin(c1_ve_x);
  c1_md_a = c1_be_y;
  c1_xd_b = c1_ve_x;
  c1_ce_y = c1_md_a * c1_xd_b;
  c1_nd_a = c1_Izz;
  c1_yd_b = c1_mpower(chartInstance, c1_dTheta);
  c1_de_y = c1_nd_a * c1_yd_b;
  c1_we_x = c1_Phi;
  c1_xe_x = c1_we_x;
  c1_xe_x = muDoubleScalarCos(c1_xe_x);
  c1_od_a = c1_de_y;
  c1_ae_b = c1_xe_x;
  c1_ee_y = c1_od_a * c1_ae_b;
  c1_ye_x = c1_Phi;
  c1_af_x = c1_ye_x;
  c1_af_x = muDoubleScalarSin(c1_af_x);
  c1_pd_a = c1_ee_y;
  c1_be_b = c1_af_x;
  c1_fe_y = c1_pd_a * c1_be_b;
  c1_bf_x = c1_Theta;
  c1_cf_x = c1_bf_x;
  c1_cf_x = muDoubleScalarSin(c1_cf_x);
  c1_qd_a = c1_fe_y;
  c1_ce_b = c1_cf_x;
  c1_ge_y = c1_qd_a * c1_ce_b;
  c1_de_b = c1_Ixx;
  c1_he_y = 2.0 * c1_de_b;
  c1_rd_a = c1_he_y;
  c1_ee_b = c1_dPsi;
  c1_ie_y = c1_rd_a * c1_ee_b;
  c1_sd_a = c1_ie_y;
  c1_fe_b = c1_dTheta;
  c1_je_y = c1_sd_a * c1_fe_b;
  c1_df_x = c1_Theta;
  c1_ef_x = c1_df_x;
  c1_ef_x = muDoubleScalarCos(c1_ef_x);
  c1_td_a = c1_je_y;
  c1_ge_b = c1_ef_x;
  c1_ke_y = c1_td_a * c1_ge_b;
  c1_ff_x = c1_Theta;
  c1_gf_x = c1_ff_x;
  c1_gf_x = muDoubleScalarSin(c1_gf_x);
  c1_ud_a = c1_ke_y;
  c1_he_b = c1_gf_x;
  c1_le_y = c1_ud_a * c1_he_b;
  c1_ie_b = c1_Izz;
  c1_me_y = 2.0 * c1_ie_b;
  c1_vd_a = c1_me_y;
  c1_je_b = c1_dPsi;
  c1_ne_y = c1_vd_a * c1_je_b;
  c1_wd_a = c1_ne_y;
  c1_ke_b = c1_dTheta;
  c1_oe_y = c1_wd_a * c1_ke_b;
  c1_hf_x = c1_Phi;
  c1_if_x = c1_hf_x;
  c1_if_x = muDoubleScalarCos(c1_if_x);
  c1_xd_a = c1_oe_y;
  c1_le_b = c1_mpower(chartInstance, c1_if_x);
  c1_pe_y = c1_xd_a * c1_le_b;
  c1_jf_x = c1_Theta;
  c1_kf_x = c1_jf_x;
  c1_kf_x = muDoubleScalarCos(c1_kf_x);
  c1_yd_a = c1_pe_y;
  c1_me_b = c1_kf_x;
  c1_qe_y = c1_yd_a * c1_me_b;
  c1_lf_x = c1_Theta;
  c1_mf_x = c1_lf_x;
  c1_mf_x = muDoubleScalarSin(c1_mf_x);
  c1_ae_a = c1_qe_y;
  c1_ne_b = c1_mf_x;
  c1_re_y = c1_ae_a * c1_ne_b;
  c1_oe_b = c1_Iyy;
  c1_se_y = 2.0 * c1_oe_b;
  c1_be_a = c1_se_y;
  c1_pe_b = c1_dPsi;
  c1_te_y = c1_be_a * c1_pe_b;
  c1_ce_a = c1_te_y;
  c1_qe_b = c1_dTheta;
  c1_ue_y = c1_ce_a * c1_qe_b;
  c1_nf_x = c1_Theta;
  c1_of_x = c1_nf_x;
  c1_of_x = muDoubleScalarCos(c1_of_x);
  c1_de_a = c1_ue_y;
  c1_re_b = c1_of_x;
  c1_ve_y = c1_de_a * c1_re_b;
  c1_pf_x = c1_Phi;
  c1_qf_x = c1_pf_x;
  c1_qf_x = muDoubleScalarSin(c1_qf_x);
  c1_ee_a = c1_ve_y;
  c1_se_b = c1_mpower(chartInstance, c1_qf_x);
  c1_we_y = c1_ee_a * c1_se_b;
  c1_rf_x = c1_Theta;
  c1_sf_x = c1_rf_x;
  c1_sf_x = muDoubleScalarSin(c1_sf_x);
  c1_fe_a = c1_we_y;
  c1_te_b = c1_sf_x;
  c1_xe_y = c1_fe_a * c1_te_b;
  c1_CdEta[0] = (((((c1_m_y - c1_q_y) - c1_t_y) - c1_y_y) + c1_eb_y) - c1_jb_y)
    + c1_ob_y;
  c1_CdEta[1] = ((c1_mc_y - c1_pc_y) + c1_tc_y) + c1_xc_y;
  c1_CdEta[2] = ((((c1_xd_y - c1_ce_y) + c1_ge_y) + c1_le_y) - c1_re_y) -
    c1_xe_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
  for (c1_i28 = 0; c1_i28 < 9; c1_i28++) {
    c1_h_a[c1_i28] = c1_J[c1_i28];
  }

  for (c1_i29 = 0; c1_i29 < 9; c1_i29++) {
    c1_ge_a[c1_i29] = c1_h_a[c1_i29];
  }

  c1_inv3x3(chartInstance, c1_ge_a, c1_i_y);
  for (c1_i30 = 0; c1_i30 < 9; c1_i30++) {
    c1_he_a[c1_i30] = c1_h_a[c1_i30];
  }

  c1_n1x = c1_norm(chartInstance, c1_he_a);
  for (c1_i31 = 0; c1_i31 < 9; c1_i31++) {
    c1_ye_y[c1_i31] = c1_i_y[c1_i31];
  }

  c1_n1xinv = c1_norm(chartInstance, c1_ye_y);
  c1_ie_a = c1_n1x;
  c1_ue_b = c1_n1xinv;
  c1_af_y = c1_ie_a * c1_ue_b;
  c1_rc = 1.0 / c1_af_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c1_n1x == 0.0) {
    guard2 = TRUE;
  } else if (c1_n1xinv == 0.0) {
    guard2 = TRUE;
  } else if (c1_rc == 0.0) {
    guard1 = TRUE;
  } else {
    c1_tf_x = c1_rc;
    c1_ve_b = muDoubleScalarIsNaN(c1_tf_x);
    guard3 = FALSE;
    if (c1_ve_b) {
      guard3 = TRUE;
    } else {
      if (c1_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c1_uf_x = c1_rc;
      for (c1_i32 = 0; c1_i32 < 8; c1_i32++) {
        c1_u[c1_i32] = c1_cv0[c1_i32];
      }

      c1_bf_y = NULL;
      sf_mex_assign(&c1_bf_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c1_b_u = 14.0;
      c1_cf_y = NULL;
      sf_mex_assign(&c1_cf_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_c_u = 6.0;
      c1_df_y = NULL;
      sf_mex_assign(&c1_df_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_d_u = c1_uf_x;
      c1_ef_y = NULL;
      sf_mex_assign(&c1_ef_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_e_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c1_bf_y, 14, c1_cf_y, 14,
        c1_df_y), 14, c1_ef_y), "sprintf", c1_str);
      for (c1_i33 = 0; c1_i33 < 14; c1_i33++) {
        c1_b_str[c1_i33] = c1_str[c1_i33];
      }

      c1_b_eml_warning(chartInstance, c1_b_str);
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c1_eml_warning(chartInstance);
  }

  for (c1_i34 = 0; c1_i34 < 3; c1_i34++) {
    c1_we_b[c1_i34] = c1_TauB[c1_i34] - c1_CdEta[c1_i34];
  }

  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  for (c1_i35 = 0; c1_i35 < 3; c1_i35++) {
    c1_y[c1_i35] = 0.0;
  }

  for (c1_i36 = 0; c1_i36 < 3; c1_i36++) {
    c1_y[c1_i36] = 0.0;
  }

  for (c1_i37 = 0; c1_i37 < 3; c1_i37++) {
    c1_C[c1_i37] = c1_y[c1_i37];
  }

  for (c1_i38 = 0; c1_i38 < 3; c1_i38++) {
    c1_y[c1_i38] = c1_C[c1_i38];
  }

  for (c1_i39 = 0; c1_i39 < 3; c1_i39++) {
    c1_C[c1_i39] = c1_y[c1_i39];
  }

  for (c1_i40 = 0; c1_i40 < 3; c1_i40++) {
    c1_y[c1_i40] = c1_C[c1_i40];
  }

  for (c1_i41 = 0; c1_i41 < 3; c1_i41++) {
    c1_y[c1_i41] = 0.0;
    c1_i42 = 0;
    for (c1_i43 = 0; c1_i43 < 3; c1_i43++) {
      c1_y[c1_i41] += c1_i_y[c1_i42 + c1_i41] * c1_we_b[c1_i43];
      c1_i42 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -34);
  sf_debug_symbol_scope_pop();
  for (c1_i44 = 0; c1_i44 < 3; c1_i44++) {
    (*c1_ff_y)[c1_i44] = c1_y[c1_i44];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_simlag2(SFc1_simlag2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i45;
  real_T c1_b_inData[3];
  int32_T c1_i46;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc1_simlag2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i45 = 0; c1_i45 < 3; c1_i45++) {
    c1_b_inData[c1_i45] = (*(real_T (*)[3])c1_inData)[c1_i45];
  }

  for (c1_i46 = 0; c1_i46 < 3; c1_i46++) {
    c1_u[c1_i46] = c1_b_inData[c1_i46];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance, const
  mxArray *c1_y, const char_T *c1_identifier, real_T c1_b_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
}

static void c1_b_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv1[3];
  int32_T c1_i47;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i47 = 0; c1_i47 < 3; c1_i47++) {
    c1_y[c1_i47] = c1_dv1[c1_i47];
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
  int32_T c1_i48;
  SFc1_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc1_simlag2InstanceStruct *)chartInstanceVoid;
  c1_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
  for (c1_i48 = 0; c1_i48 < 3; c1_i48++) {
    (*(real_T (*)[3])c1_outData)[c1_i48] = c1_b_y[c1_i48];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc1_simlag2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
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
  SFc1_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc1_simlag2InstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  real_T c1_b_inData[9];
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  real_T c1_u[9];
  const mxArray *c1_y = NULL;
  SFc1_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc1_simlag2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i49 = 0;
  for (c1_i50 = 0; c1_i50 < 3; c1_i50++) {
    for (c1_i51 = 0; c1_i51 < 3; c1_i51++) {
      c1_b_inData[c1_i51 + c1_i49] = (*(real_T (*)[9])c1_inData)[c1_i51 + c1_i49];
    }

    c1_i49 += 3;
  }

  c1_i52 = 0;
  for (c1_i53 = 0; c1_i53 < 3; c1_i53++) {
    for (c1_i54 = 0; c1_i54 < 3; c1_i54++) {
      c1_u[c1_i54 + c1_i52] = c1_b_inData[c1_i54 + c1_i52];
    }

    c1_i52 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9])
{
  real_T c1_dv2[9];
  int32_T c1_i55;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i55 = 0; c1_i55 < 9; c1_i55++) {
    c1_y[c1_i55] = c1_dv2[c1_i55];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_J;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[9];
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  SFc1_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc1_simlag2InstanceStruct *)chartInstanceVoid;
  c1_J = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_J), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_J);
  c1_i56 = 0;
  for (c1_i57 = 0; c1_i57 < 3; c1_i57++) {
    for (c1_i58 = 0; c1_i58 < 3; c1_i58++) {
      (*(real_T (*)[9])c1_outData)[c1_i58 + c1_i56] = c1_y[c1_i58 + c1_i56];
    }

    c1_i56 += 3;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_simlag2_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[42];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i59;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 42), FALSE);
  for (c1_i59 = 0; c1_i59 < 42; c1_i59++) {
    c1_r0 = &c1_info[c1_i59];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i59);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i59);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i59);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i59);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i59);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i59);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i59);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i59);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[42])
{
  c1_info[0].context = "";
  c1_info[0].name = "mtimes";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[0].fileTimeLo = 1289519692U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context = "";
  c1_info[1].name = "sin";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[1].fileTimeLo = 1286818750U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[2].name = "eml_scalar_sin";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[2].fileTimeLo = 1286818736U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "";
  c1_info[3].name = "cos";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[3].fileTimeLo = 1286818706U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[4].name = "eml_scalar_cos";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[4].fileTimeLo = 1286818722U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[5].name = "eml_index_class";
  c1_info[5].dominantType = "";
  c1_info[5].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[5].fileTimeLo = 1286818778U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[6].name = "eml_scalar_eg";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[6].fileTimeLo = 1286818796U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[7].name = "eml_xgemm";
  c1_info[7].dominantType = "int32";
  c1_info[7].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[7].fileTimeLo = 1299076772U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[8].name = "eml_blas_inline";
  c1_info[8].dominantType = "";
  c1_info[8].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[8].fileTimeLo = 1299076768U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c1_info[9].name = "mtimes";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[9].fileTimeLo = 1289519692U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[10].name = "eml_scalar_eg";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[10].fileTimeLo = 1286818796U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[11].name = "eml_refblas_xgemm";
  c1_info[11].dominantType = "int32";
  c1_info[11].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[11].fileTimeLo = 1299076774U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context = "";
  c1_info[12].name = "mpower";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[12].fileTimeLo = 1286818842U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[13].name = "power";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[13].fileTimeLo = 1307651240U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[14].name = "eml_scalar_eg";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[14].fileTimeLo = 1286818796U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[15].name = "eml_scalexp_alloc";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[15].fileTimeLo = 1286818796U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[16].name = "eml_scalar_floor";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[16].fileTimeLo = 1286818726U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context = "";
  c1_info[17].name = "mrdivide";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[17].fileTimeLo = 1325124138U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 1319729966U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[18].name = "rdivide";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[18].fileTimeLo = 1286818844U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[19].name = "eml_div";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[19].fileTimeLo = 1313347810U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context = "";
  c1_info[20].name = "inv";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m";
  c1_info[20].fileTimeLo = 1305318000U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c1_info[21].name = "eml_index_class";
  c1_info[21].dominantType = "";
  c1_info[21].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[21].fileTimeLo = 1286818778U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c1_info[22].name = "abs";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[22].fileTimeLo = 1286818694U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[23].name = "eml_scalar_abs";
  c1_info[23].dominantType = "double";
  c1_info[23].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[23].fileTimeLo = 1286818712U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c1_info[24].name = "eml_div";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[24].fileTimeLo = 1313347810U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c1_info[25].name = "mtimes";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[25].fileTimeLo = 1289519692U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c1_info[26].name = "eml_index_plus";
  c1_info[26].dominantType = "int32";
  c1_info[26].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[26].fileTimeLo = 1286818778U;
  c1_info[26].fileTimeHi = 0U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[27].name = "eml_index_class";
  c1_info[27].dominantType = "";
  c1_info[27].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[27].fileTimeLo = 1286818778U;
  c1_info[27].fileTimeHi = 0U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[28].name = "norm";
  c1_info[28].dominantType = "double";
  c1_info[28].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[28].fileTimeLo = 1286818826U;
  c1_info[28].fileTimeHi = 0U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
  c1_info[29].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c1_info[29].name = "abs";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[29].fileTimeLo = 1286818694U;
  c1_info[29].fileTimeHi = 0U;
  c1_info[29].mFileTimeLo = 0U;
  c1_info[29].mFileTimeHi = 0U;
  c1_info[30].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c1_info[30].name = "isnan";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[30].fileTimeLo = 1286818760U;
  c1_info[30].fileTimeHi = 0U;
  c1_info[30].mFileTimeLo = 0U;
  c1_info[30].mFileTimeHi = 0U;
  c1_info[31].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c1_info[31].name = "eml_guarded_nan";
  c1_info[31].dominantType = "char";
  c1_info[31].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c1_info[31].fileTimeLo = 1286818776U;
  c1_info[31].fileTimeHi = 0U;
  c1_info[31].mFileTimeLo = 0U;
  c1_info[31].mFileTimeHi = 0U;
  c1_info[32].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c1_info[32].name = "eml_is_float_class";
  c1_info[32].dominantType = "char";
  c1_info[32].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[32].fileTimeLo = 1286818782U;
  c1_info[32].fileTimeHi = 0U;
  c1_info[32].mFileTimeLo = 0U;
  c1_info[32].mFileTimeHi = 0U;
  c1_info[33].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[33].name = "mtimes";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[33].fileTimeLo = 1289519692U;
  c1_info[33].fileTimeHi = 0U;
  c1_info[33].mFileTimeLo = 0U;
  c1_info[33].mFileTimeHi = 0U;
  c1_info[34].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[34].name = "eml_warning";
  c1_info[34].dominantType = "char";
  c1_info[34].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c1_info[34].fileTimeLo = 1286818802U;
  c1_info[34].fileTimeHi = 0U;
  c1_info[34].mFileTimeLo = 0U;
  c1_info[34].mFileTimeHi = 0U;
  c1_info[35].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[35].name = "isnan";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[35].fileTimeLo = 1286818760U;
  c1_info[35].fileTimeHi = 0U;
  c1_info[35].mFileTimeLo = 0U;
  c1_info[35].mFileTimeHi = 0U;
  c1_info[36].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[36].name = "eps";
  c1_info[36].dominantType = "char";
  c1_info[36].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[36].fileTimeLo = 1307651240U;
  c1_info[36].fileTimeHi = 0U;
  c1_info[36].mFileTimeLo = 0U;
  c1_info[36].mFileTimeHi = 0U;
  c1_info[37].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[37].name = "eml_is_float_class";
  c1_info[37].dominantType = "char";
  c1_info[37].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[37].fileTimeLo = 1286818782U;
  c1_info[37].fileTimeHi = 0U;
  c1_info[37].mFileTimeLo = 0U;
  c1_info[37].mFileTimeHi = 0U;
  c1_info[38].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[38].name = "eml_eps";
  c1_info[38].dominantType = "char";
  c1_info[38].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[38].fileTimeLo = 1307651240U;
  c1_info[38].fileTimeHi = 0U;
  c1_info[38].mFileTimeLo = 0U;
  c1_info[38].mFileTimeHi = 0U;
  c1_info[39].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[39].name = "eml_float_model";
  c1_info[39].dominantType = "char";
  c1_info[39].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[39].fileTimeLo = 1307651242U;
  c1_info[39].fileTimeHi = 0U;
  c1_info[39].mFileTimeLo = 0U;
  c1_info[39].mFileTimeHi = 0U;
  c1_info[40].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c1_info[40].name = "eml_flt2str";
  c1_info[40].dominantType = "double";
  c1_info[40].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c1_info[40].fileTimeLo = 1309451196U;
  c1_info[40].fileTimeHi = 0U;
  c1_info[40].mFileTimeLo = 0U;
  c1_info[40].mFileTimeHi = 0U;
  c1_info[41].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c1_info[41].name = "char";
  c1_info[41].dominantType = "double";
  c1_info[41].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/strfun/char.m";
  c1_info[41].fileTimeLo = 1319729968U;
  c1_info[41].fileTimeHi = 0U;
  c1_info[41].mFileTimeLo = 0U;
  c1_info[41].mFileTimeHi = 0U;
}

static void c1_eml_scalar_eg(SFc1_simlag2InstanceStruct *chartInstance)
{
}

static real_T c1_mpower(SFc1_simlag2InstanceStruct *chartInstance, real_T c1_a)
{
  real_T c1_b_a;
  real_T c1_ak;
  c1_b_a = c1_a;
  c1_ak = c1_b_a;
  return muDoubleScalarPower(c1_ak, 2.0);
}

static void c1_inv3x3(SFc1_simlag2InstanceStruct *chartInstance, real_T c1_x[9],
                      real_T c1_y[9])
{
  int32_T c1_p1;
  int32_T c1_p2;
  int32_T c1_p3;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_absx11;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_absx21;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_absx31;
  real_T c1_t1;
  real_T c1_h_x;
  real_T c1_b_y;
  real_T c1_z;
  real_T c1_i_x;
  real_T c1_c_y;
  real_T c1_b_z;
  real_T c1_a;
  real_T c1_b;
  real_T c1_d_y;
  real_T c1_b_a;
  real_T c1_b_b;
  real_T c1_e_y;
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_f_y;
  real_T c1_d_a;
  real_T c1_d_b;
  real_T c1_g_y;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_h_y;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_i_y;
  int32_T c1_itmp;
  real_T c1_n_x;
  real_T c1_j_y;
  real_T c1_c_z;
  real_T c1_e_a;
  real_T c1_e_b;
  real_T c1_k_y;
  real_T c1_f_a;
  real_T c1_f_b;
  real_T c1_l_y;
  real_T c1_o_x;
  real_T c1_m_y;
  real_T c1_t3;
  real_T c1_g_a;
  real_T c1_g_b;
  real_T c1_n_y;
  real_T c1_p_x;
  real_T c1_o_y;
  real_T c1_t2;
  int32_T c1_h_a;
  int32_T c1_c;
  real_T c1_i_a;
  real_T c1_h_b;
  real_T c1_p_y;
  real_T c1_j_a;
  real_T c1_i_b;
  real_T c1_q_y;
  real_T c1_q_x;
  real_T c1_r_y;
  real_T c1_d_z;
  int32_T c1_k_a;
  int32_T c1_b_c;
  int32_T c1_l_a;
  int32_T c1_c_c;
  real_T c1_r_x;
  real_T c1_s_y;
  real_T c1_m_a;
  real_T c1_j_b;
  real_T c1_t_y;
  real_T c1_s_x;
  real_T c1_u_y;
  int32_T c1_n_a;
  int32_T c1_d_c;
  real_T c1_o_a;
  real_T c1_k_b;
  real_T c1_v_y;
  real_T c1_p_a;
  real_T c1_l_b;
  real_T c1_w_y;
  real_T c1_t_x;
  real_T c1_x_y;
  real_T c1_e_z;
  int32_T c1_q_a;
  int32_T c1_e_c;
  int32_T c1_r_a;
  int32_T c1_f_c;
  real_T c1_y_y;
  real_T c1_s_a;
  real_T c1_m_b;
  real_T c1_ab_y;
  real_T c1_u_x;
  real_T c1_bb_y;
  int32_T c1_t_a;
  int32_T c1_g_c;
  real_T c1_u_a;
  real_T c1_n_b;
  real_T c1_cb_y;
  real_T c1_v_a;
  real_T c1_o_b;
  real_T c1_db_y;
  real_T c1_v_x;
  real_T c1_eb_y;
  real_T c1_f_z;
  int32_T c1_w_a;
  int32_T c1_h_c;
  int32_T c1_x_a;
  int32_T c1_i_c;
  boolean_T guard1 = FALSE;
  c1_p1 = 0;
  c1_p2 = 3;
  c1_p3 = 6;
  c1_b_x = c1_x[0];
  c1_c_x = c1_b_x;
  c1_absx11 = muDoubleScalarAbs(c1_c_x);
  c1_d_x = c1_x[1];
  c1_e_x = c1_d_x;
  c1_absx21 = muDoubleScalarAbs(c1_e_x);
  c1_f_x = c1_x[2];
  c1_g_x = c1_f_x;
  c1_absx31 = muDoubleScalarAbs(c1_g_x);
  guard1 = FALSE;
  if (c1_absx21 > c1_absx11) {
    if (c1_absx21 > c1_absx31) {
      c1_p1 = 3;
      c1_p2 = 0;
      c1_t1 = c1_x[0];
      c1_x[0] = c1_x[1];
      c1_x[1] = c1_t1;
      c1_t1 = c1_x[3];
      c1_x[3] = c1_x[4];
      c1_x[4] = c1_t1;
      c1_t1 = c1_x[6];
      c1_x[6] = c1_x[7];
      c1_x[7] = c1_t1;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    if (c1_absx31 > c1_absx11) {
      c1_p1 = 6;
      c1_p3 = 0;
      c1_t1 = c1_x[0];
      c1_x[0] = c1_x[2];
      c1_x[2] = c1_t1;
      c1_t1 = c1_x[3];
      c1_x[3] = c1_x[5];
      c1_x[5] = c1_t1;
      c1_t1 = c1_x[6];
      c1_x[6] = c1_x[8];
      c1_x[8] = c1_t1;
    }
  }

  c1_h_x = c1_x[1];
  c1_b_y = c1_x[0];
  c1_z = c1_h_x / c1_b_y;
  c1_x[1] = c1_z;
  c1_i_x = c1_x[2];
  c1_c_y = c1_x[0];
  c1_b_z = c1_i_x / c1_c_y;
  c1_x[2] = c1_b_z;
  c1_a = c1_x[1];
  c1_b = c1_x[3];
  c1_d_y = c1_a * c1_b;
  c1_x[4] -= c1_d_y;
  c1_b_a = c1_x[2];
  c1_b_b = c1_x[3];
  c1_e_y = c1_b_a * c1_b_b;
  c1_x[5] -= c1_e_y;
  c1_c_a = c1_x[1];
  c1_c_b = c1_x[6];
  c1_f_y = c1_c_a * c1_c_b;
  c1_x[7] -= c1_f_y;
  c1_d_a = c1_x[2];
  c1_d_b = c1_x[6];
  c1_g_y = c1_d_a * c1_d_b;
  c1_x[8] -= c1_g_y;
  c1_j_x = c1_x[5];
  c1_k_x = c1_j_x;
  c1_h_y = muDoubleScalarAbs(c1_k_x);
  c1_l_x = c1_x[4];
  c1_m_x = c1_l_x;
  c1_i_y = muDoubleScalarAbs(c1_m_x);
  if (c1_h_y > c1_i_y) {
    c1_itmp = c1_p2;
    c1_p2 = c1_p3;
    c1_p3 = c1_itmp;
    c1_t1 = c1_x[1];
    c1_x[1] = c1_x[2];
    c1_x[2] = c1_t1;
    c1_t1 = c1_x[4];
    c1_x[4] = c1_x[5];
    c1_x[5] = c1_t1;
    c1_t1 = c1_x[7];
    c1_x[7] = c1_x[8];
    c1_x[8] = c1_t1;
  }

  c1_n_x = c1_x[5];
  c1_j_y = c1_x[4];
  c1_c_z = c1_n_x / c1_j_y;
  c1_x[5] = c1_c_z;
  c1_e_a = c1_x[5];
  c1_e_b = c1_x[7];
  c1_k_y = c1_e_a * c1_e_b;
  c1_x[8] -= c1_k_y;
  c1_f_a = c1_x[5];
  c1_f_b = c1_x[1];
  c1_l_y = c1_f_a * c1_f_b;
  c1_o_x = c1_l_y - c1_x[2];
  c1_m_y = c1_x[8];
  c1_t3 = c1_o_x / c1_m_y;
  c1_g_a = c1_x[7];
  c1_g_b = c1_t3;
  c1_n_y = c1_g_a * c1_g_b;
  c1_p_x = -(c1_x[1] + c1_n_y);
  c1_o_y = c1_x[4];
  c1_t2 = c1_p_x / c1_o_y;
  c1_h_a = c1_p1 + 1;
  c1_c = c1_h_a;
  c1_i_a = c1_x[3];
  c1_h_b = c1_t2;
  c1_p_y = c1_i_a * c1_h_b;
  c1_j_a = c1_x[6];
  c1_i_b = c1_t3;
  c1_q_y = c1_j_a * c1_i_b;
  c1_q_x = (1.0 - c1_p_y) - c1_q_y;
  c1_r_y = c1_x[0];
  c1_d_z = c1_q_x / c1_r_y;
  c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_c), 1, 9, 1, 0) - 1] = c1_d_z;
  c1_k_a = c1_p1 + 2;
  c1_b_c = c1_k_a;
  c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_b_c), 1, 9, 1, 0) - 1] = c1_t2;
  c1_l_a = c1_p1 + 3;
  c1_c_c = c1_l_a;
  c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_c_c), 1, 9, 1, 0) - 1] = c1_t3;
  c1_r_x = -c1_x[5];
  c1_s_y = c1_x[8];
  c1_t3 = c1_r_x / c1_s_y;
  c1_m_a = c1_x[7];
  c1_j_b = c1_t3;
  c1_t_y = c1_m_a * c1_j_b;
  c1_s_x = 1.0 - c1_t_y;
  c1_u_y = c1_x[4];
  c1_t2 = c1_s_x / c1_u_y;
  c1_n_a = c1_p2 + 1;
  c1_d_c = c1_n_a;
  c1_o_a = c1_x[3];
  c1_k_b = c1_t2;
  c1_v_y = c1_o_a * c1_k_b;
  c1_p_a = c1_x[6];
  c1_l_b = c1_t3;
  c1_w_y = c1_p_a * c1_l_b;
  c1_t_x = -(c1_v_y + c1_w_y);
  c1_x_y = c1_x[0];
  c1_e_z = c1_t_x / c1_x_y;
  c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_d_c), 1, 9, 1, 0) - 1] = c1_e_z;
  c1_q_a = c1_p2 + 2;
  c1_e_c = c1_q_a;
  c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_e_c), 1, 9, 1, 0) - 1] = c1_t2;
  c1_r_a = c1_p2 + 3;
  c1_f_c = c1_r_a;
  c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_f_c), 1, 9, 1, 0) - 1] = c1_t3;
  c1_y_y = c1_x[8];
  c1_t3 = 1.0 / c1_y_y;
  c1_s_a = -c1_x[7];
  c1_m_b = c1_t3;
  c1_ab_y = c1_s_a * c1_m_b;
  c1_u_x = c1_ab_y;
  c1_bb_y = c1_x[4];
  c1_t2 = c1_u_x / c1_bb_y;
  c1_t_a = c1_p3 + 1;
  c1_g_c = c1_t_a;
  c1_u_a = c1_x[3];
  c1_n_b = c1_t2;
  c1_cb_y = c1_u_a * c1_n_b;
  c1_v_a = c1_x[6];
  c1_o_b = c1_t3;
  c1_db_y = c1_v_a * c1_o_b;
  c1_v_x = -(c1_cb_y + c1_db_y);
  c1_eb_y = c1_x[0];
  c1_f_z = c1_v_x / c1_eb_y;
  c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_g_c), 1, 9, 1, 0) - 1] = c1_f_z;
  c1_w_a = c1_p3 + 2;
  c1_h_c = c1_w_a;
  c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_h_c), 1, 9, 1, 0) - 1] = c1_t2;
  c1_x_a = c1_p3 + 3;
  c1_i_c = c1_x_a;
  c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c1_i_c), 1, 9, 1, 0) - 1] = c1_t3;
}

static real_T c1_norm(SFc1_simlag2InstanceStruct *chartInstance, real_T c1_x[9])
{
  real_T c1_y;
  int32_T c1_j;
  real_T c1_b_j;
  real_T c1_s;
  int32_T c1_i;
  real_T c1_b_i;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_b_y;
  real_T c1_d_x;
  boolean_T c1_b;
  boolean_T exitg1;
  c1_y = 0.0;
  c1_j = 0;
  exitg1 = FALSE;
  while ((exitg1 == 0U) && (c1_j < 3)) {
    c1_b_j = 1.0 + (real_T)c1_j;
    c1_s = 0.0;
    for (c1_i = 0; c1_i < 3; c1_i++) {
      c1_b_i = 1.0 + (real_T)c1_i;
      c1_b_x = c1_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c1_b_i), 1, 3, 1, 0) + 3 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c1_b_j), 1, 3, 2, 0) - 1)) - 1];
      c1_c_x = c1_b_x;
      c1_b_y = muDoubleScalarAbs(c1_c_x);
      c1_s += c1_b_y;
    }

    c1_d_x = c1_s;
    c1_b = muDoubleScalarIsNaN(c1_d_x);
    if (c1_b) {
      c1_y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (c1_s > c1_y) {
        c1_y = c1_s;
      }

      c1_j++;
    }
  }

  return c1_y;
}

static void c1_eml_warning(SFc1_simlag2InstanceStruct *chartInstance)
{
  int32_T c1_i60;
  static char_T c1_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c1_u[27];
  const mxArray *c1_y = NULL;
  for (c1_i60 = 0; c1_i60 < 27; c1_i60++) {
    c1_u[c1_i60] = c1_varargin_1[c1_i60];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c1_y));
}

static void c1_b_eml_warning(SFc1_simlag2InstanceStruct *chartInstance, char_T
  c1_varargin_2[14])
{
  int32_T c1_i61;
  static char_T c1_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c1_u[33];
  const mxArray *c1_y = NULL;
  int32_T c1_i62;
  char_T c1_b_u[14];
  const mxArray *c1_b_y = NULL;
  for (c1_i61 = 0; c1_i61 < 33; c1_i61++) {
    c1_u[c1_i61] = c1_varargin_1[c1_i61];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  for (c1_i62 = 0; c1_i62 < 14; c1_i62++) {
    c1_b_u[c1_i62] = c1_varargin_2[c1_i62];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c1_y, 14, c1_b_y));
}

static void c1_b_eml_scalar_eg(SFc1_simlag2InstanceStruct *chartInstance)
{
}

static void c1_e_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_sprintf, const char_T *c1_identifier, char_T c1_y[14])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sprintf), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_sprintf);
}

static void c1_f_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, char_T c1_y[14])
{
  char_T c1_cv1[14];
  int32_T c1_i63;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c1_i63 = 0; c1_i63 < 14; c1_i63++) {
    c1_y[c1_i63] = c1_cv1[c1_i63];
  }

  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc1_simlag2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_g_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i64;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i64, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i64;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc1_simlag2InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_h_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_simlag2, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_simlag2), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_simlag2);
  return c1_y;
}

static uint8_T c1_i_emlrt_marshallIn(SFc1_simlag2InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_simlag2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_simlag2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3264155092U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3947890101U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2141579390U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2921783014U);
}

mxArray *sf_c1_simlag2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("LsDZKXt20a0Mru0FTpRQKC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,15,3,dataFields);

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
      pr[0] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));
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

static const mxArray *sf_get_sim_state_info_c1_simlag2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c1_simlag2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_simlag2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_simlag2InstanceStruct *chartInstance;
    chartInstance = (SFc1_simlag2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_simlag2MachineNumber_,
          1,
          1,
          1,
          16,
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
          _SFD_SET_DATA_PROPS(4,2,0,1,"y");
          _SFD_SET_DATA_PROPS(5,1,1,0,"II");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Phi");
          _SFD_SET_DATA_PROPS(7,1,1,0,"Theta");
          _SFD_SET_DATA_PROPS(8,1,1,0,"Psi");
          _SFD_SET_DATA_PROPS(9,1,1,0,"dPhi");
          _SFD_SET_DATA_PROPS(10,1,1,0,"dTheta");
          _SFD_SET_DATA_PROPS(11,1,1,0,"dPsi");
          _SFD_SET_DATA_PROPS(12,1,1,0,"A");
          _SFD_SET_DATA_PROPS(13,1,1,0,"l");
          _SFD_SET_DATA_PROPS(14,1,1,0,"b");
          _SFD_SET_DATA_PROPS(15,1,1,0,"k");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4361);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_w1;
          real_T *c1_w2;
          real_T *c1_w3;
          real_T *c1_w4;
          real_T *c1_Phi;
          real_T *c1_Theta;
          real_T *c1_Psi;
          real_T *c1_dPhi;
          real_T *c1_dTheta;
          real_T *c1_dPsi;
          real_T *c1_l;
          real_T *c1_b;
          real_T *c1_k;
          real_T (*c1_y)[3];
          real_T (*c1_II)[3];
          real_T (*c1_A)[3];
          c1_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
          c1_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c1_l = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c1_A = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 11);
          c1_dPsi = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c1_dTheta = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c1_dPhi = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c1_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c1_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_II = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c1_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_w4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_w3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_w2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_w1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_w1);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_w2);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_w3);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_w4);
          _SFD_SET_DATA_VALUE_PTR(4U, *c1_y);
          _SFD_SET_DATA_VALUE_PTR(5U, *c1_II);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_Phi);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_Theta);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_Psi);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_dPhi);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_dTheta);
          _SFD_SET_DATA_VALUE_PTR(11U, c1_dPsi);
          _SFD_SET_DATA_VALUE_PTR(12U, *c1_A);
          _SFD_SET_DATA_VALUE_PTR(13U, c1_l);
          _SFD_SET_DATA_VALUE_PTR(14U, c1_b);
          _SFD_SET_DATA_VALUE_PTR(15U, c1_k);
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
  return "ovZhZfZtF93ihPO4f68zLH";
}

static void sf_opaque_initialize_c1_simlag2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_simlag2InstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c1_simlag2((SFc1_simlag2InstanceStruct*) chartInstanceVar);
  initialize_c1_simlag2((SFc1_simlag2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_simlag2(void *chartInstanceVar)
{
  enable_c1_simlag2((SFc1_simlag2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_simlag2(void *chartInstanceVar)
{
  disable_c1_simlag2((SFc1_simlag2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_simlag2(void *chartInstanceVar)
{
  sf_c1_simlag2((SFc1_simlag2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_simlag2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_simlag2((SFc1_simlag2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_simlag2();/* state var info */
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

extern void sf_internal_set_sim_state_c1_simlag2(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_simlag2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_simlag2((SFc1_simlag2InstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_simlag2(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_simlag2(S);
}

static void sf_opaque_set_sim_state_c1_simlag2(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_simlag2(S, st);
}

static void sf_opaque_terminate_c1_simlag2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_simlag2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_simlag2((SFc1_simlag2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_simlag2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_simlag2((SFc1_simlag2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_simlag2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_simlag2((SFc1_simlag2InstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_simlag2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_simlag2_optimization_info();
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
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,15);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4065265217U));
  ssSetChecksum1(S,(135062498U));
  ssSetChecksum2(S,(2434737183U));
  ssSetChecksum3(S,(577290017U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_simlag2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_simlag2(SimStruct *S)
{
  SFc1_simlag2InstanceStruct *chartInstance;
  chartInstance = (SFc1_simlag2InstanceStruct *)malloc(sizeof
    (SFc1_simlag2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_simlag2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_simlag2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_simlag2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_simlag2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_simlag2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_simlag2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_simlag2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_simlag2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_simlag2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_simlag2;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_simlag2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_simlag2;
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

void c1_simlag2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_simlag2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_simlag2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_simlag2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_simlag2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

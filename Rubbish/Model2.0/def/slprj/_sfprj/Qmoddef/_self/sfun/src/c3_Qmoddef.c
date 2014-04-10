/* Include files */

#include "blascompat32.h"
#include "Qmoddef_sfun.h"
#include "c3_Qmoddef.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Qmoddef_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[23] = { "Ixx", "Iyy", "Izz", "C11",
  "C12", "C13", "C21", "C22", "C23", "C31", "C32", "C33", "Cmat", "nargin",
  "nargout", "Phi", "Theta", "Psi", "dPhi", "dTheta", "dPsi", "I", "C" };

/* Function Declarations */
static void initialize_c3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance);
static void initialize_params_c3_Qmoddef(SFc3_QmoddefInstanceStruct
  *chartInstance);
static void enable_c3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance);
static void disable_c3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Qmoddef(SFc3_QmoddefInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_Qmoddef(SFc3_QmoddefInstanceStruct
  *chartInstance);
static void set_sim_state_c3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance,
  const mxArray *c3_st);
static void finalize_c3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance);
static void sf_c3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance);
static void c3_chartstep_c3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance);
static void initSimStructsc3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_QmoddefInstanceStruct *chartInstance, const
  mxArray *c3_C, const char_T *c3_identifier, real_T c3_y[9]);
static void c3_b_emlrt_marshallIn(SFc3_QmoddefInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[9]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn(SFc3_QmoddefInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static real_T c3_mpower(SFc3_QmoddefInstanceStruct *chartInstance, real_T c3_a);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn(SFc3_QmoddefInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_e_emlrt_marshallIn(SFc3_QmoddefInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_Qmoddef, const char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn(SFc3_QmoddefInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_QmoddefInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_Qmoddef = 0U;
}

static void initialize_params_c3_Qmoddef(SFc3_QmoddefInstanceStruct
  *chartInstance)
{
}

static void enable_c3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_Qmoddef(SFc3_QmoddefInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_Qmoddef(SFc3_QmoddefInstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[9];
  const mxArray *c3_b_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T (*c3_C)[9];
  c3_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  for (c3_i0 = 0; c3_i0 < 9; c3_i0++) {
    c3_u[c3_i0] = (*c3_C)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_Qmoddef;
  c3_b_u = c3_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[9];
  int32_T c3_i1;
  real_T (*c3_C)[9];
  c3_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)), "C",
                      c3_dv0);
  for (c3_i1 = 0; c3_i1 < 9; c3_i1++) {
    (*c3_C)[c3_i1] = c3_dv0[c3_i1];
  }

  chartInstance->c3_is_active_c3_Qmoddef = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 1)), "is_active_c3_Qmoddef");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_Qmoddef(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance)
{
}

static void sf_c3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance)
{
  int32_T c3_i2;
  int32_T c3_i3;
  real_T *c3_Phi;
  real_T *c3_Theta;
  real_T *c3_Psi;
  real_T *c3_dPhi;
  real_T *c3_dTheta;
  real_T *c3_dPsi;
  real_T (*c3_I)[3];
  real_T (*c3_C)[9];
  c3_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
  c3_dPsi = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_dTheta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_dPhi = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_Phi, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_Theta, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_Psi, 2U);
  for (c3_i2 = 0; c3_i2 < 9; c3_i2++) {
    _SFD_DATA_RANGE_CHECK((*c3_C)[c3_i2], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_dPhi, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_dTheta, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_dPsi, 6U);
  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    _SFD_DATA_RANGE_CHECK((*c3_I)[c3_i3], 7U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_Qmoddef(chartInstance);
  sf_debug_check_for_state_inconsistency(_QmoddefMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_f_hoistedGlobal;
  real_T c3_Phi;
  real_T c3_Theta;
  real_T c3_Psi;
  real_T c3_dPhi;
  real_T c3_dTheta;
  real_T c3_dPsi;
  int32_T c3_i4;
  real_T c3_I[3];
  uint32_T c3_debug_family_var_map[23];
  real_T c3_Ixx;
  real_T c3_Iyy;
  real_T c3_Izz;
  real_T c3_C11;
  real_T c3_C12;
  real_T c3_C13;
  real_T c3_C21;
  real_T c3_C22;
  real_T c3_C23;
  real_T c3_C31;
  real_T c3_C32;
  real_T c3_C33;
  real_T c3_Cmat[9];
  real_T c3_nargin = 7.0;
  real_T c3_nargout = 1.0;
  real_T c3_C[9];
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_a;
  real_T c3_b;
  real_T c3_y;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_b_y;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_c_y;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_d_y;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_e_y;
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_f_y;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_g_y;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_h_a;
  real_T c3_h_b;
  real_T c3_h_y;
  real_T c3_m_x;
  real_T c3_n_x;
  real_T c3_i_a;
  real_T c3_i_b;
  real_T c3_i_y;
  real_T c3_o_x;
  real_T c3_p_x;
  real_T c3_j_a;
  real_T c3_j_b;
  real_T c3_j_y;
  real_T c3_k_a;
  real_T c3_k_b;
  real_T c3_k_y;
  real_T c3_q_x;
  real_T c3_r_x;
  real_T c3_l_a;
  real_T c3_l_b;
  real_T c3_l_y;
  real_T c3_m_a;
  real_T c3_m_b;
  real_T c3_m_y;
  real_T c3_s_x;
  real_T c3_t_x;
  real_T c3_n_a;
  real_T c3_n_b;
  real_T c3_n_y;
  real_T c3_u_x;
  real_T c3_v_x;
  real_T c3_o_a;
  real_T c3_o_b;
  real_T c3_o_y;
  real_T c3_w_x;
  real_T c3_x_x;
  real_T c3_p_a;
  real_T c3_p_b;
  real_T c3_y_x;
  real_T c3_ab_x;
  real_T c3_q_a;
  real_T c3_q_b;
  real_T c3_p_y;
  real_T c3_bb_x;
  real_T c3_cb_x;
  real_T c3_r_a;
  real_T c3_r_b;
  real_T c3_q_y;
  real_T c3_db_x;
  real_T c3_eb_x;
  real_T c3_s_a;
  real_T c3_s_b;
  real_T c3_r_y;
  real_T c3_fb_x;
  real_T c3_gb_x;
  real_T c3_t_a;
  real_T c3_t_b;
  real_T c3_s_y;
  real_T c3_u_a;
  real_T c3_u_b;
  real_T c3_t_y;
  real_T c3_v_a;
  real_T c3_v_b;
  real_T c3_u_y;
  real_T c3_hb_x;
  real_T c3_ib_x;
  real_T c3_w_a;
  real_T c3_w_b;
  real_T c3_v_y;
  real_T c3_jb_x;
  real_T c3_kb_x;
  real_T c3_x_a;
  real_T c3_x_b;
  real_T c3_w_y;
  real_T c3_lb_x;
  real_T c3_mb_x;
  real_T c3_y_a;
  real_T c3_y_b;
  real_T c3_x_y;
  real_T c3_ab_a;
  real_T c3_ab_b;
  real_T c3_y_y;
  real_T c3_nb_x;
  real_T c3_ob_x;
  real_T c3_bb_a;
  real_T c3_bb_b;
  real_T c3_ab_y;
  real_T c3_cb_a;
  real_T c3_cb_b;
  real_T c3_bb_y;
  real_T c3_pb_x;
  real_T c3_qb_x;
  real_T c3_db_a;
  real_T c3_db_b;
  real_T c3_cb_y;
  real_T c3_rb_x;
  real_T c3_sb_x;
  real_T c3_eb_a;
  real_T c3_eb_b;
  real_T c3_fb_a;
  real_T c3_fb_b;
  real_T c3_db_y;
  real_T c3_tb_x;
  real_T c3_ub_x;
  real_T c3_gb_a;
  real_T c3_gb_b;
  real_T c3_eb_y;
  real_T c3_vb_x;
  real_T c3_wb_x;
  real_T c3_hb_a;
  real_T c3_hb_b;
  real_T c3_fb_y;
  real_T c3_ib_a;
  real_T c3_ib_b;
  real_T c3_gb_y;
  real_T c3_xb_x;
  real_T c3_yb_x;
  real_T c3_jb_a;
  real_T c3_jb_b;
  real_T c3_hb_y;
  real_T c3_ac_x;
  real_T c3_bc_x;
  real_T c3_kb_a;
  real_T c3_kb_b;
  real_T c3_ib_y;
  real_T c3_cc_x;
  real_T c3_dc_x;
  real_T c3_lb_a;
  real_T c3_lb_b;
  real_T c3_jb_y;
  real_T c3_ec_x;
  real_T c3_fc_x;
  real_T c3_mb_a;
  real_T c3_mb_b;
  real_T c3_kb_y;
  real_T c3_nb_a;
  real_T c3_nb_b;
  real_T c3_lb_y;
  real_T c3_gc_x;
  real_T c3_hc_x;
  real_T c3_ob_a;
  real_T c3_ob_b;
  real_T c3_mb_y;
  real_T c3_ic_x;
  real_T c3_jc_x;
  real_T c3_pb_a;
  real_T c3_pb_b;
  real_T c3_nb_y;
  real_T c3_kc_x;
  real_T c3_lc_x;
  real_T c3_qb_a;
  real_T c3_qb_b;
  real_T c3_ob_y;
  real_T c3_mc_x;
  real_T c3_nc_x;
  real_T c3_rb_a;
  real_T c3_rb_b;
  real_T c3_pb_y;
  real_T c3_sb_a;
  real_T c3_sb_b;
  real_T c3_qb_y;
  real_T c3_oc_x;
  real_T c3_pc_x;
  real_T c3_tb_a;
  real_T c3_tb_b;
  real_T c3_rb_y;
  real_T c3_qc_x;
  real_T c3_rc_x;
  real_T c3_ub_a;
  real_T c3_ub_b;
  real_T c3_sb_y;
  real_T c3_sc_x;
  real_T c3_tc_x;
  real_T c3_vb_a;
  real_T c3_vb_b;
  real_T c3_tb_y;
  real_T c3_uc_x;
  real_T c3_vc_x;
  real_T c3_wb_a;
  real_T c3_wb_b;
  real_T c3_ub_y;
  real_T c3_xb_a;
  real_T c3_xb_b;
  real_T c3_vb_y;
  real_T c3_wc_x;
  real_T c3_xc_x;
  real_T c3_yb_a;
  real_T c3_yb_b;
  real_T c3_wb_y;
  real_T c3_yc_x;
  real_T c3_ad_x;
  real_T c3_ac_a;
  real_T c3_ac_b;
  real_T c3_xb_y;
  real_T c3_bd_x;
  real_T c3_cd_x;
  real_T c3_bc_a;
  real_T c3_bc_b;
  real_T c3_yb_y;
  real_T c3_dd_x;
  real_T c3_ed_x;
  real_T c3_cc_a;
  real_T c3_cc_b;
  real_T c3_ac_y;
  real_T c3_fd_x;
  real_T c3_gd_x;
  real_T c3_dc_a;
  real_T c3_dc_b;
  real_T c3_bc_y;
  real_T c3_hd_x;
  real_T c3_id_x;
  real_T c3_ec_a;
  real_T c3_ec_b;
  real_T c3_cc_y;
  real_T c3_jd_x;
  real_T c3_kd_x;
  real_T c3_fc_a;
  real_T c3_fc_b;
  real_T c3_dc_y;
  real_T c3_gc_a;
  real_T c3_gc_b;
  real_T c3_ec_y;
  real_T c3_hc_a;
  real_T c3_hc_b;
  real_T c3_fc_y;
  real_T c3_ld_x;
  real_T c3_md_x;
  real_T c3_ic_a;
  real_T c3_ic_b;
  real_T c3_gc_y;
  real_T c3_nd_x;
  real_T c3_od_x;
  real_T c3_jc_a;
  real_T c3_jc_b;
  real_T c3_hc_y;
  real_T c3_pd_x;
  real_T c3_qd_x;
  real_T c3_kc_a;
  real_T c3_kc_b;
  real_T c3_ic_y;
  real_T c3_lc_a;
  real_T c3_lc_b;
  real_T c3_jc_y;
  real_T c3_rd_x;
  real_T c3_sd_x;
  real_T c3_mc_a;
  real_T c3_mc_b;
  real_T c3_kc_y;
  real_T c3_td_x;
  real_T c3_ud_x;
  real_T c3_nc_a;
  real_T c3_nc_b;
  real_T c3_lc_y;
  real_T c3_oc_a;
  real_T c3_oc_b;
  real_T c3_mc_y;
  real_T c3_vd_x;
  real_T c3_wd_x;
  real_T c3_pc_a;
  real_T c3_pc_b;
  real_T c3_nc_y;
  real_T c3_xd_x;
  real_T c3_yd_x;
  real_T c3_qc_a;
  real_T c3_qc_b;
  real_T c3_oc_y;
  real_T c3_ae_x;
  real_T c3_be_x;
  real_T c3_rc_a;
  real_T c3_rc_b;
  real_T c3_pc_y;
  real_T c3_ce_x;
  real_T c3_de_x;
  real_T c3_sc_a;
  real_T c3_sc_b;
  real_T c3_qc_y;
  real_T c3_tc_a;
  real_T c3_tc_b;
  real_T c3_rc_y;
  real_T c3_ee_x;
  real_T c3_fe_x;
  real_T c3_uc_a;
  real_T c3_uc_b;
  real_T c3_sc_y;
  real_T c3_ge_x;
  real_T c3_he_x;
  real_T c3_vc_a;
  real_T c3_vc_b;
  real_T c3_tc_y;
  real_T c3_ie_x;
  real_T c3_je_x;
  real_T c3_wc_a;
  real_T c3_wc_b;
  real_T c3_uc_y;
  real_T c3_ke_x;
  real_T c3_le_x;
  real_T c3_xc_a;
  real_T c3_xc_b;
  real_T c3_vc_y;
  real_T c3_yc_a;
  real_T c3_yc_b;
  real_T c3_wc_y;
  real_T c3_me_x;
  real_T c3_ne_x;
  real_T c3_ad_a;
  real_T c3_ad_b;
  real_T c3_xc_y;
  real_T c3_oe_x;
  real_T c3_pe_x;
  real_T c3_bd_a;
  real_T c3_bd_b;
  real_T c3_yc_y;
  real_T c3_qe_x;
  real_T c3_re_x;
  real_T c3_cd_a;
  real_T c3_cd_b;
  real_T c3_ad_y;
  real_T c3_se_x;
  real_T c3_te_x;
  real_T c3_dd_a;
  real_T c3_dd_b;
  real_T c3_bd_y;
  real_T c3_ed_a;
  real_T c3_ed_b;
  real_T c3_cd_y;
  real_T c3_ue_x;
  real_T c3_ve_x;
  real_T c3_fd_a;
  real_T c3_fd_b;
  real_T c3_dd_y;
  real_T c3_we_x;
  real_T c3_xe_x;
  real_T c3_gd_a;
  real_T c3_gd_b;
  real_T c3_ed_y;
  real_T c3_ye_x;
  real_T c3_af_x;
  real_T c3_hd_a;
  real_T c3_hd_b;
  real_T c3_fd_y;
  real_T c3_bf_x;
  real_T c3_cf_x;
  real_T c3_id_a;
  real_T c3_id_b;
  real_T c3_gd_y;
  real_T c3_jd_a;
  real_T c3_jd_b;
  real_T c3_hd_y;
  real_T c3_df_x;
  real_T c3_ef_x;
  real_T c3_kd_a;
  real_T c3_kd_b;
  real_T c3_id_y;
  real_T c3_ff_x;
  real_T c3_gf_x;
  real_T c3_ld_a;
  real_T c3_ld_b;
  real_T c3_jd_y;
  real_T c3_hf_x;
  real_T c3_if_x;
  real_T c3_md_a;
  real_T c3_md_b;
  real_T c3_kd_y;
  real_T c3_jf_x;
  real_T c3_kf_x;
  real_T c3_nd_a;
  real_T c3_nd_b;
  real_T c3_ld_y;
  real_T c3_od_a;
  real_T c3_od_b;
  real_T c3_md_y;
  real_T c3_lf_x;
  real_T c3_mf_x;
  real_T c3_pd_a;
  real_T c3_pd_b;
  real_T c3_nd_y;
  real_T c3_nf_x;
  real_T c3_of_x;
  real_T c3_qd_a;
  real_T c3_qd_b;
  real_T c3_od_y;
  int32_T c3_i5;
  int32_T c3_i6;
  real_T *c3_b_Phi;
  real_T *c3_b_Theta;
  real_T *c3_b_Psi;
  real_T *c3_b_dPhi;
  real_T *c3_b_dTheta;
  real_T *c3_b_dPsi;
  real_T (*c3_b_C)[9];
  real_T (*c3_b_I)[3];
  c3_b_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
  c3_b_dPsi = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_dTheta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_dPhi = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_Phi;
  c3_b_hoistedGlobal = *c3_b_Theta;
  c3_c_hoistedGlobal = *c3_b_Psi;
  c3_d_hoistedGlobal = *c3_b_dPhi;
  c3_e_hoistedGlobal = *c3_b_dTheta;
  c3_f_hoistedGlobal = *c3_b_dPsi;
  c3_Phi = c3_hoistedGlobal;
  c3_Theta = c3_b_hoistedGlobal;
  c3_Psi = c3_c_hoistedGlobal;
  c3_dPhi = c3_d_hoistedGlobal;
  c3_dTheta = c3_e_hoistedGlobal;
  c3_dPsi = c3_f_hoistedGlobal;
  for (c3_i4 = 0; c3_i4 < 3; c3_i4++) {
    c3_I[c3_i4] = (*c3_b_I)[c3_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 23U, 23U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_Ixx, 0U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Iyy, 1U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Izz, 2U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_C11, 3U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_C12, 4U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_C13, 5U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_C21, 6U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_C22, 7U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_C23, 8U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_C31, 9U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_C32, 10U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_C33, 11U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_Cmat, 12U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 13U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 14U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_Phi, 15U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Theta, 16U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Psi, 17U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_dPhi, 18U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_dTheta, 19U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_dPsi, 20U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_I, 21U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c3_C, 22U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_Ixx = c3_I[0];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  c3_Iyy = c3_I[1];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_Izz = c3_I[2];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_C11 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_x = c3_Phi;
  c3_b_x = c3_x;
  c3_b_x = muDoubleScalarCos(c3_b_x);
  c3_a = c3_dTheta;
  c3_b = c3_b_x;
  c3_y = c3_a * c3_b;
  c3_c_x = c3_Phi;
  c3_d_x = c3_c_x;
  c3_d_x = muDoubleScalarSin(c3_d_x);
  c3_b_a = c3_y;
  c3_b_b = c3_d_x;
  c3_b_y = c3_b_a * c3_b_b;
  c3_e_x = c3_Phi;
  c3_f_x = c3_e_x;
  c3_f_x = muDoubleScalarSin(c3_f_x);
  c3_c_a = c3_dPsi;
  c3_c_b = c3_f_x;
  c3_c_y = c3_c_a * c3_c_b;
  c3_g_x = c3_Phi;
  c3_h_x = c3_g_x;
  c3_h_x = muDoubleScalarSin(c3_h_x);
  c3_d_a = c3_c_y;
  c3_d_b = c3_h_x;
  c3_d_y = c3_d_a * c3_d_b;
  c3_i_x = c3_Theta;
  c3_j_x = c3_i_x;
  c3_j_x = muDoubleScalarCos(c3_j_x);
  c3_e_a = c3_d_y;
  c3_e_b = c3_j_x;
  c3_e_y = c3_e_a * c3_e_b;
  c3_f_a = c3_Iyy - c3_Izz;
  c3_f_b = c3_b_y + c3_e_y;
  c3_f_y = c3_f_a * c3_f_b;
  c3_g_a = c3_Izz - c3_Iyy;
  c3_g_b = c3_dPsi;
  c3_g_y = c3_g_a * c3_g_b;
  c3_k_x = c3_Phi;
  c3_l_x = c3_k_x;
  c3_l_x = muDoubleScalarCos(c3_l_x);
  c3_h_a = c3_g_y;
  c3_h_b = c3_l_x;
  c3_h_y = c3_h_a * c3_h_b;
  c3_m_x = c3_Phi;
  c3_n_x = c3_m_x;
  c3_n_x = muDoubleScalarCos(c3_n_x);
  c3_i_a = c3_h_y;
  c3_i_b = c3_n_x;
  c3_i_y = c3_i_a * c3_i_b;
  c3_o_x = c3_Theta;
  c3_p_x = c3_o_x;
  c3_p_x = muDoubleScalarCos(c3_p_x);
  c3_j_a = c3_i_y;
  c3_j_b = c3_p_x;
  c3_j_y = c3_j_a * c3_j_b;
  c3_k_a = c3_Ixx;
  c3_k_b = c3_dPsi;
  c3_k_y = c3_k_a * c3_k_b;
  c3_q_x = c3_Theta;
  c3_r_x = c3_q_x;
  c3_r_x = muDoubleScalarCos(c3_r_x);
  c3_l_a = c3_k_y;
  c3_l_b = c3_r_x;
  c3_l_y = c3_l_a * c3_l_b;
  c3_C12 = (c3_f_y + c3_j_y) - c3_l_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_m_a = c3_Izz - c3_Iyy;
  c3_m_b = c3_dPsi;
  c3_m_y = c3_m_a * c3_m_b;
  c3_s_x = c3_Phi;
  c3_t_x = c3_s_x;
  c3_t_x = muDoubleScalarCos(c3_t_x);
  c3_n_a = c3_m_y;
  c3_n_b = c3_t_x;
  c3_n_y = c3_n_a * c3_n_b;
  c3_u_x = c3_Phi;
  c3_v_x = c3_u_x;
  c3_v_x = muDoubleScalarSin(c3_v_x);
  c3_o_a = c3_n_y;
  c3_o_b = c3_v_x;
  c3_o_y = c3_o_a * c3_o_b;
  c3_w_x = c3_Theta;
  c3_x_x = c3_w_x;
  c3_x_x = muDoubleScalarCos(c3_x_x);
  c3_p_a = c3_o_y;
  c3_p_b = c3_mpower(chartInstance, c3_x_x);
  c3_C13 = c3_p_a * c3_p_b;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  c3_y_x = c3_Phi;
  c3_ab_x = c3_y_x;
  c3_ab_x = muDoubleScalarCos(c3_ab_x);
  c3_q_a = c3_dTheta;
  c3_q_b = c3_ab_x;
  c3_p_y = c3_q_a * c3_q_b;
  c3_bb_x = c3_Phi;
  c3_cb_x = c3_bb_x;
  c3_cb_x = muDoubleScalarSin(c3_cb_x);
  c3_r_a = c3_p_y;
  c3_r_b = c3_cb_x;
  c3_q_y = c3_r_a * c3_r_b;
  c3_db_x = c3_Phi;
  c3_eb_x = c3_db_x;
  c3_eb_x = muDoubleScalarSin(c3_eb_x);
  c3_s_a = c3_dPsi;
  c3_s_b = c3_eb_x;
  c3_r_y = c3_s_a * c3_s_b;
  c3_fb_x = c3_Theta;
  c3_gb_x = c3_fb_x;
  c3_gb_x = muDoubleScalarCos(c3_gb_x);
  c3_t_a = c3_r_y;
  c3_t_b = c3_gb_x;
  c3_s_y = c3_t_a * c3_t_b;
  c3_u_a = c3_Izz - c3_Iyy;
  c3_u_b = c3_q_y + c3_s_y;
  c3_t_y = c3_u_a * c3_u_b;
  c3_v_a = c3_Iyy - c3_Izz;
  c3_v_b = c3_dPsi;
  c3_u_y = c3_v_a * c3_v_b;
  c3_hb_x = c3_Phi;
  c3_ib_x = c3_hb_x;
  c3_ib_x = muDoubleScalarCos(c3_ib_x);
  c3_w_a = c3_u_y;
  c3_w_b = c3_ib_x;
  c3_v_y = c3_w_a * c3_w_b;
  c3_jb_x = c3_Phi;
  c3_kb_x = c3_jb_x;
  c3_kb_x = muDoubleScalarCos(c3_kb_x);
  c3_x_a = c3_v_y;
  c3_x_b = c3_kb_x;
  c3_w_y = c3_x_a * c3_x_b;
  c3_lb_x = c3_Theta;
  c3_mb_x = c3_lb_x;
  c3_mb_x = muDoubleScalarCos(c3_mb_x);
  c3_y_a = c3_w_y;
  c3_y_b = c3_mb_x;
  c3_x_y = c3_y_a * c3_y_b;
  c3_ab_a = c3_Ixx;
  c3_ab_b = c3_dPsi;
  c3_y_y = c3_ab_a * c3_ab_b;
  c3_nb_x = c3_Theta;
  c3_ob_x = c3_nb_x;
  c3_ob_x = muDoubleScalarCos(c3_ob_x);
  c3_bb_a = c3_y_y;
  c3_bb_b = c3_ob_x;
  c3_ab_y = c3_bb_a * c3_bb_b;
  c3_C21 = (c3_t_y + c3_x_y) + c3_ab_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
  c3_cb_a = c3_Izz - c3_Iyy;
  c3_cb_b = c3_dPhi;
  c3_bb_y = c3_cb_a * c3_cb_b;
  c3_pb_x = c3_Phi;
  c3_qb_x = c3_pb_x;
  c3_qb_x = muDoubleScalarCos(c3_qb_x);
  c3_db_a = c3_bb_y;
  c3_db_b = c3_qb_x;
  c3_cb_y = c3_db_a * c3_db_b;
  c3_rb_x = c3_Phi;
  c3_sb_x = c3_rb_x;
  c3_sb_x = muDoubleScalarSin(c3_sb_x);
  c3_eb_a = c3_cb_y;
  c3_eb_b = c3_sb_x;
  c3_C22 = c3_eb_a * c3_eb_b;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  c3_fb_a = -c3_Ixx;
  c3_fb_b = c3_dPsi;
  c3_db_y = c3_fb_a * c3_fb_b;
  c3_tb_x = c3_Theta;
  c3_ub_x = c3_tb_x;
  c3_ub_x = muDoubleScalarSin(c3_ub_x);
  c3_gb_a = c3_db_y;
  c3_gb_b = c3_ub_x;
  c3_eb_y = c3_gb_a * c3_gb_b;
  c3_vb_x = c3_Theta;
  c3_wb_x = c3_vb_x;
  c3_wb_x = muDoubleScalarCos(c3_wb_x);
  c3_hb_a = c3_eb_y;
  c3_hb_b = c3_wb_x;
  c3_fb_y = c3_hb_a * c3_hb_b;
  c3_ib_a = c3_Iyy;
  c3_ib_b = c3_dPsi;
  c3_gb_y = c3_ib_a * c3_ib_b;
  c3_xb_x = c3_Phi;
  c3_yb_x = c3_xb_x;
  c3_yb_x = muDoubleScalarSin(c3_yb_x);
  c3_jb_a = c3_gb_y;
  c3_jb_b = c3_yb_x;
  c3_hb_y = c3_jb_a * c3_jb_b;
  c3_ac_x = c3_Phi;
  c3_bc_x = c3_ac_x;
  c3_bc_x = muDoubleScalarSin(c3_bc_x);
  c3_kb_a = c3_hb_y;
  c3_kb_b = c3_bc_x;
  c3_ib_y = c3_kb_a * c3_kb_b;
  c3_cc_x = c3_Theta;
  c3_dc_x = c3_cc_x;
  c3_dc_x = muDoubleScalarSin(c3_dc_x);
  c3_lb_a = c3_ib_y;
  c3_lb_b = c3_dc_x;
  c3_jb_y = c3_lb_a * c3_lb_b;
  c3_ec_x = c3_Theta;
  c3_fc_x = c3_ec_x;
  c3_fc_x = muDoubleScalarCos(c3_fc_x);
  c3_mb_a = c3_jb_y;
  c3_mb_b = c3_fc_x;
  c3_kb_y = c3_mb_a * c3_mb_b;
  c3_nb_a = c3_Izz;
  c3_nb_b = c3_dPsi;
  c3_lb_y = c3_nb_a * c3_nb_b;
  c3_gc_x = c3_Phi;
  c3_hc_x = c3_gc_x;
  c3_hc_x = muDoubleScalarCos(c3_hc_x);
  c3_ob_a = c3_lb_y;
  c3_ob_b = c3_hc_x;
  c3_mb_y = c3_ob_a * c3_ob_b;
  c3_ic_x = c3_Phi;
  c3_jc_x = c3_ic_x;
  c3_jc_x = muDoubleScalarCos(c3_jc_x);
  c3_pb_a = c3_mb_y;
  c3_pb_b = c3_jc_x;
  c3_nb_y = c3_pb_a * c3_pb_b;
  c3_kc_x = c3_Theta;
  c3_lc_x = c3_kc_x;
  c3_lc_x = muDoubleScalarSin(c3_lc_x);
  c3_qb_a = c3_nb_y;
  c3_qb_b = c3_lc_x;
  c3_ob_y = c3_qb_a * c3_qb_b;
  c3_mc_x = c3_Theta;
  c3_nc_x = c3_mc_x;
  c3_nc_x = muDoubleScalarCos(c3_nc_x);
  c3_rb_a = c3_ob_y;
  c3_rb_b = c3_nc_x;
  c3_pb_y = c3_rb_a * c3_rb_b;
  c3_C23 = (c3_fb_y + c3_kb_y) + c3_pb_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
  c3_sb_a = c3_Iyy - c3_Izz;
  c3_sb_b = c3_dPsi;
  c3_qb_y = c3_sb_a * c3_sb_b;
  c3_oc_x = c3_Theta;
  c3_pc_x = c3_oc_x;
  c3_pc_x = muDoubleScalarCos(c3_pc_x);
  c3_tb_a = c3_qb_y;
  c3_tb_b = c3_pc_x;
  c3_rb_y = c3_tb_a * c3_tb_b;
  c3_qc_x = c3_Theta;
  c3_rc_x = c3_qc_x;
  c3_rc_x = muDoubleScalarCos(c3_rc_x);
  c3_ub_a = c3_rb_y;
  c3_ub_b = c3_rc_x;
  c3_sb_y = c3_ub_a * c3_ub_b;
  c3_sc_x = c3_Phi;
  c3_tc_x = c3_sc_x;
  c3_tc_x = muDoubleScalarSin(c3_tc_x);
  c3_vb_a = c3_sb_y;
  c3_vb_b = c3_tc_x;
  c3_tb_y = c3_vb_a * c3_vb_b;
  c3_uc_x = c3_Phi;
  c3_vc_x = c3_uc_x;
  c3_vc_x = muDoubleScalarCos(c3_vc_x);
  c3_wb_a = c3_tb_y;
  c3_wb_b = c3_vc_x;
  c3_ub_y = c3_wb_a * c3_wb_b;
  c3_xb_a = c3_Ixx;
  c3_xb_b = c3_dTheta;
  c3_vb_y = c3_xb_a * c3_xb_b;
  c3_wc_x = c3_Theta;
  c3_xc_x = c3_wc_x;
  c3_xc_x = muDoubleScalarCos(c3_xc_x);
  c3_yb_a = c3_vb_y;
  c3_yb_b = c3_xc_x;
  c3_wb_y = c3_yb_a * c3_yb_b;
  c3_C31 = c3_ub_y - c3_wb_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
  c3_yc_x = c3_Phi;
  c3_ad_x = c3_yc_x;
  c3_ad_x = muDoubleScalarCos(c3_ad_x);
  c3_ac_a = c3_dTheta;
  c3_ac_b = c3_ad_x;
  c3_xb_y = c3_ac_a * c3_ac_b;
  c3_bd_x = c3_Phi;
  c3_cd_x = c3_bd_x;
  c3_cd_x = muDoubleScalarSin(c3_cd_x);
  c3_bc_a = c3_xb_y;
  c3_bc_b = c3_cd_x;
  c3_yb_y = c3_bc_a * c3_bc_b;
  c3_dd_x = c3_Theta;
  c3_ed_x = c3_dd_x;
  c3_ed_x = muDoubleScalarSin(c3_ed_x);
  c3_cc_a = c3_yb_y;
  c3_cc_b = c3_ed_x;
  c3_ac_y = c3_cc_a * c3_cc_b;
  c3_fd_x = c3_Phi;
  c3_gd_x = c3_fd_x;
  c3_gd_x = muDoubleScalarSin(c3_gd_x);
  c3_dc_a = c3_dPhi;
  c3_dc_b = c3_gd_x;
  c3_bc_y = c3_dc_a * c3_dc_b;
  c3_hd_x = c3_Phi;
  c3_id_x = c3_hd_x;
  c3_id_x = muDoubleScalarSin(c3_id_x);
  c3_ec_a = c3_bc_y;
  c3_ec_b = c3_id_x;
  c3_cc_y = c3_ec_a * c3_ec_b;
  c3_jd_x = c3_Theta;
  c3_kd_x = c3_jd_x;
  c3_kd_x = muDoubleScalarCos(c3_kd_x);
  c3_fc_a = c3_cc_y;
  c3_fc_b = c3_kd_x;
  c3_dc_y = c3_fc_a * c3_fc_b;
  c3_gc_a = c3_Izz - c3_Iyy;
  c3_gc_b = c3_ac_y + c3_dc_y;
  c3_ec_y = c3_gc_a * c3_gc_b;
  c3_hc_a = c3_Iyy - c3_Izz;
  c3_hc_b = c3_dPhi;
  c3_fc_y = c3_hc_a * c3_hc_b;
  c3_ld_x = c3_Phi;
  c3_md_x = c3_ld_x;
  c3_md_x = muDoubleScalarCos(c3_md_x);
  c3_ic_a = c3_fc_y;
  c3_ic_b = c3_md_x;
  c3_gc_y = c3_ic_a * c3_ic_b;
  c3_nd_x = c3_Phi;
  c3_od_x = c3_nd_x;
  c3_od_x = muDoubleScalarCos(c3_od_x);
  c3_jc_a = c3_gc_y;
  c3_jc_b = c3_od_x;
  c3_hc_y = c3_jc_a * c3_jc_b;
  c3_pd_x = c3_Theta;
  c3_qd_x = c3_pd_x;
  c3_qd_x = muDoubleScalarCos(c3_qd_x);
  c3_kc_a = c3_hc_y;
  c3_kc_b = c3_qd_x;
  c3_ic_y = c3_kc_a * c3_kc_b;
  c3_lc_a = c3_Ixx;
  c3_lc_b = c3_dPsi;
  c3_jc_y = c3_lc_a * c3_lc_b;
  c3_rd_x = c3_Theta;
  c3_sd_x = c3_rd_x;
  c3_sd_x = muDoubleScalarSin(c3_sd_x);
  c3_mc_a = c3_jc_y;
  c3_mc_b = c3_sd_x;
  c3_kc_y = c3_mc_a * c3_mc_b;
  c3_td_x = c3_Theta;
  c3_ud_x = c3_td_x;
  c3_ud_x = muDoubleScalarCos(c3_ud_x);
  c3_nc_a = c3_kc_y;
  c3_nc_b = c3_ud_x;
  c3_lc_y = c3_nc_a * c3_nc_b;
  c3_oc_a = c3_Iyy;
  c3_oc_b = c3_dPsi;
  c3_mc_y = c3_oc_a * c3_oc_b;
  c3_vd_x = c3_Phi;
  c3_wd_x = c3_vd_x;
  c3_wd_x = muDoubleScalarSin(c3_wd_x);
  c3_pc_a = c3_mc_y;
  c3_pc_b = c3_wd_x;
  c3_nc_y = c3_pc_a * c3_pc_b;
  c3_xd_x = c3_Phi;
  c3_yd_x = c3_xd_x;
  c3_yd_x = muDoubleScalarSin(c3_yd_x);
  c3_qc_a = c3_nc_y;
  c3_qc_b = c3_yd_x;
  c3_oc_y = c3_qc_a * c3_qc_b;
  c3_ae_x = c3_Theta;
  c3_be_x = c3_ae_x;
  c3_be_x = muDoubleScalarSin(c3_be_x);
  c3_rc_a = c3_oc_y;
  c3_rc_b = c3_be_x;
  c3_pc_y = c3_rc_a * c3_rc_b;
  c3_ce_x = c3_Theta;
  c3_de_x = c3_ce_x;
  c3_de_x = muDoubleScalarCos(c3_de_x);
  c3_sc_a = c3_pc_y;
  c3_sc_b = c3_de_x;
  c3_qc_y = c3_sc_a * c3_sc_b;
  c3_tc_a = c3_Izz;
  c3_tc_b = c3_dPsi;
  c3_rc_y = c3_tc_a * c3_tc_b;
  c3_ee_x = c3_Phi;
  c3_fe_x = c3_ee_x;
  c3_fe_x = muDoubleScalarCos(c3_fe_x);
  c3_uc_a = c3_rc_y;
  c3_uc_b = c3_fe_x;
  c3_sc_y = c3_uc_a * c3_uc_b;
  c3_ge_x = c3_Phi;
  c3_he_x = c3_ge_x;
  c3_he_x = muDoubleScalarCos(c3_he_x);
  c3_vc_a = c3_sc_y;
  c3_vc_b = c3_he_x;
  c3_tc_y = c3_vc_a * c3_vc_b;
  c3_ie_x = c3_Theta;
  c3_je_x = c3_ie_x;
  c3_je_x = muDoubleScalarSin(c3_je_x);
  c3_wc_a = c3_tc_y;
  c3_wc_b = c3_je_x;
  c3_uc_y = c3_wc_a * c3_wc_b;
  c3_ke_x = c3_Theta;
  c3_le_x = c3_ke_x;
  c3_le_x = muDoubleScalarCos(c3_le_x);
  c3_xc_a = c3_uc_y;
  c3_xc_b = c3_le_x;
  c3_vc_y = c3_xc_a * c3_xc_b;
  c3_C32 = (((c3_ec_y + c3_ic_y) + c3_lc_y) - c3_qc_y) - c3_vc_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
  c3_yc_a = c3_Iyy - c3_Izz;
  c3_yc_b = c3_dPhi;
  c3_wc_y = c3_yc_a * c3_yc_b;
  c3_me_x = c3_Phi;
  c3_ne_x = c3_me_x;
  c3_ne_x = muDoubleScalarCos(c3_ne_x);
  c3_ad_a = c3_wc_y;
  c3_ad_b = c3_ne_x;
  c3_xc_y = c3_ad_a * c3_ad_b;
  c3_oe_x = c3_Phi;
  c3_pe_x = c3_oe_x;
  c3_pe_x = muDoubleScalarSin(c3_pe_x);
  c3_bd_a = c3_xc_y;
  c3_bd_b = c3_pe_x;
  c3_yc_y = c3_bd_a * c3_bd_b;
  c3_qe_x = c3_Theta;
  c3_re_x = c3_qe_x;
  c3_re_x = muDoubleScalarCos(c3_re_x);
  c3_cd_a = c3_yc_y;
  c3_cd_b = c3_re_x;
  c3_ad_y = c3_cd_a * c3_cd_b;
  c3_se_x = c3_Theta;
  c3_te_x = c3_se_x;
  c3_te_x = muDoubleScalarCos(c3_te_x);
  c3_dd_a = c3_ad_y;
  c3_dd_b = c3_te_x;
  c3_bd_y = c3_dd_a * c3_dd_b;
  c3_ed_a = c3_Iyy;
  c3_ed_b = c3_dTheta;
  c3_cd_y = c3_ed_a * c3_ed_b;
  c3_ue_x = c3_Phi;
  c3_ve_x = c3_ue_x;
  c3_ve_x = muDoubleScalarSin(c3_ve_x);
  c3_fd_a = c3_cd_y;
  c3_fd_b = c3_ve_x;
  c3_dd_y = c3_fd_a * c3_fd_b;
  c3_we_x = c3_Phi;
  c3_xe_x = c3_we_x;
  c3_xe_x = muDoubleScalarSin(c3_xe_x);
  c3_gd_a = c3_dd_y;
  c3_gd_b = c3_xe_x;
  c3_ed_y = c3_gd_a * c3_gd_b;
  c3_ye_x = c3_Theta;
  c3_af_x = c3_ye_x;
  c3_af_x = muDoubleScalarCos(c3_af_x);
  c3_hd_a = c3_ed_y;
  c3_hd_b = c3_af_x;
  c3_fd_y = c3_hd_a * c3_hd_b;
  c3_bf_x = c3_Theta;
  c3_cf_x = c3_bf_x;
  c3_cf_x = muDoubleScalarSin(c3_cf_x);
  c3_id_a = c3_fd_y;
  c3_id_b = c3_cf_x;
  c3_gd_y = c3_id_a * c3_id_b;
  c3_jd_a = c3_Izz;
  c3_jd_b = c3_dTheta;
  c3_hd_y = c3_jd_a * c3_jd_b;
  c3_df_x = c3_Phi;
  c3_ef_x = c3_df_x;
  c3_ef_x = muDoubleScalarCos(c3_ef_x);
  c3_kd_a = c3_hd_y;
  c3_kd_b = c3_ef_x;
  c3_id_y = c3_kd_a * c3_kd_b;
  c3_ff_x = c3_Phi;
  c3_gf_x = c3_ff_x;
  c3_gf_x = muDoubleScalarCos(c3_gf_x);
  c3_ld_a = c3_id_y;
  c3_ld_b = c3_gf_x;
  c3_jd_y = c3_ld_a * c3_ld_b;
  c3_hf_x = c3_Theta;
  c3_if_x = c3_hf_x;
  c3_if_x = muDoubleScalarCos(c3_if_x);
  c3_md_a = c3_jd_y;
  c3_md_b = c3_if_x;
  c3_kd_y = c3_md_a * c3_md_b;
  c3_jf_x = c3_Theta;
  c3_kf_x = c3_jf_x;
  c3_kf_x = muDoubleScalarSin(c3_kf_x);
  c3_nd_a = c3_kd_y;
  c3_nd_b = c3_kf_x;
  c3_ld_y = c3_nd_a * c3_nd_b;
  c3_od_a = c3_Ixx;
  c3_od_b = c3_dTheta;
  c3_md_y = c3_od_a * c3_od_b;
  c3_lf_x = c3_Theta;
  c3_mf_x = c3_lf_x;
  c3_mf_x = muDoubleScalarCos(c3_mf_x);
  c3_pd_a = c3_md_y;
  c3_pd_b = c3_mf_x;
  c3_nd_y = c3_pd_a * c3_pd_b;
  c3_nf_x = c3_Theta;
  c3_of_x = c3_nf_x;
  c3_of_x = muDoubleScalarSin(c3_of_x);
  c3_qd_a = c3_nd_y;
  c3_qd_b = c3_of_x;
  c3_od_y = c3_qd_a * c3_qd_b;
  c3_C33 = ((c3_bd_y - c3_gd_y) - c3_ld_y) + c3_od_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
  c3_Cmat[0] = c3_C11;
  c3_Cmat[3] = c3_C12;
  c3_Cmat[6] = c3_C13;
  c3_Cmat[1] = c3_C21;
  c3_Cmat[4] = c3_C22;
  c3_Cmat[7] = c3_C23;
  c3_Cmat[2] = c3_C31;
  c3_Cmat[5] = c3_C32;
  c3_Cmat[8] = c3_C33;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
  for (c3_i5 = 0; c3_i5 < 9; c3_i5++) {
    c3_C[c3_i5] = c3_Cmat[c3_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -25);
  sf_debug_symbol_scope_pop();
  for (c3_i6 = 0; c3_i6 < 9; c3_i6++) {
    (*c3_b_C)[c3_i6] = c3_C[c3_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_Qmoddef(SFc3_QmoddefInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  real_T c3_b_inData[9];
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  real_T c3_u[9];
  const mxArray *c3_y = NULL;
  SFc3_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc3_QmoddefInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i7 = 0;
  for (c3_i8 = 0; c3_i8 < 3; c3_i8++) {
    for (c3_i9 = 0; c3_i9 < 3; c3_i9++) {
      c3_b_inData[c3_i9 + c3_i7] = (*(real_T (*)[9])c3_inData)[c3_i9 + c3_i7];
    }

    c3_i7 += 3;
  }

  c3_i10 = 0;
  for (c3_i11 = 0; c3_i11 < 3; c3_i11++) {
    for (c3_i12 = 0; c3_i12 < 3; c3_i12++) {
      c3_u[c3_i12 + c3_i10] = c3_b_inData[c3_i12 + c3_i10];
    }

    c3_i10 += 3;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_QmoddefInstanceStruct *chartInstance, const
  mxArray *c3_C, const char_T *c3_identifier, real_T c3_y[9])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_C), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_C);
}

static void c3_b_emlrt_marshallIn(SFc3_QmoddefInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[9])
{
  real_T c3_dv1[9];
  int32_T c3_i13;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c3_i13 = 0; c3_i13 < 9; c3_i13++) {
    c3_y[c3_i13] = c3_dv1[c3_i13];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_C;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[9];
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  SFc3_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc3_QmoddefInstanceStruct *)chartInstanceVoid;
  c3_C = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_C), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_C);
  c3_i14 = 0;
  for (c3_i15 = 0; c3_i15 < 3; c3_i15++) {
    for (c3_i16 = 0; c3_i16 < 3; c3_i16++) {
      (*(real_T (*)[9])c3_outData)[c3_i16 + c3_i14] = c3_y[c3_i16 + c3_i14];
    }

    c3_i14 += 3;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i17;
  real_T c3_b_inData[3];
  int32_T c3_i18;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc3_QmoddefInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i17 = 0; c3_i17 < 3; c3_i17++) {
    c3_b_inData[c3_i17] = (*(real_T (*)[3])c3_inData)[c3_i17];
  }

  for (c3_i18 = 0; c3_i18 < 3; c3_i18++) {
    c3_u[c3_i18] = c3_b_inData[c3_i18];
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
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc3_QmoddefInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn(SFc3_QmoddefInstanceStruct *chartInstance,
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
  SFc3_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc3_QmoddefInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_Qmoddef_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[10];
  c3_ResolvedFunctionInfo (*c3_b_info)[10];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i19;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_b_info = (c3_ResolvedFunctionInfo (*)[10])c3_info;
  (*c3_b_info)[0].context = "";
  (*c3_b_info)[0].name = "cos";
  (*c3_b_info)[0].dominantType = "double";
  (*c3_b_info)[0].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c3_b_info)[0].fileTimeLo = 1286818706U;
  (*c3_b_info)[0].fileTimeHi = 0U;
  (*c3_b_info)[0].mFileTimeLo = 0U;
  (*c3_b_info)[0].mFileTimeHi = 0U;
  (*c3_b_info)[1].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c3_b_info)[1].name = "eml_scalar_cos";
  (*c3_b_info)[1].dominantType = "double";
  (*c3_b_info)[1].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c3_b_info)[1].fileTimeLo = 1286818722U;
  (*c3_b_info)[1].fileTimeHi = 0U;
  (*c3_b_info)[1].mFileTimeLo = 0U;
  (*c3_b_info)[1].mFileTimeHi = 0U;
  (*c3_b_info)[2].context = "";
  (*c3_b_info)[2].name = "mtimes";
  (*c3_b_info)[2].dominantType = "double";
  (*c3_b_info)[2].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[2].fileTimeLo = 1289519692U;
  (*c3_b_info)[2].fileTimeHi = 0U;
  (*c3_b_info)[2].mFileTimeLo = 0U;
  (*c3_b_info)[2].mFileTimeHi = 0U;
  (*c3_b_info)[3].context = "";
  (*c3_b_info)[3].name = "sin";
  (*c3_b_info)[3].dominantType = "double";
  (*c3_b_info)[3].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c3_b_info)[3].fileTimeLo = 1286818750U;
  (*c3_b_info)[3].fileTimeHi = 0U;
  (*c3_b_info)[3].mFileTimeLo = 0U;
  (*c3_b_info)[3].mFileTimeHi = 0U;
  (*c3_b_info)[4].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c3_b_info)[4].name = "eml_scalar_sin";
  (*c3_b_info)[4].dominantType = "double";
  (*c3_b_info)[4].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c3_b_info)[4].fileTimeLo = 1286818736U;
  (*c3_b_info)[4].fileTimeHi = 0U;
  (*c3_b_info)[4].mFileTimeLo = 0U;
  (*c3_b_info)[4].mFileTimeHi = 0U;
  (*c3_b_info)[5].context = "";
  (*c3_b_info)[5].name = "mpower";
  (*c3_b_info)[5].dominantType = "double";
  (*c3_b_info)[5].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c3_b_info)[5].fileTimeLo = 1286818842U;
  (*c3_b_info)[5].fileTimeHi = 0U;
  (*c3_b_info)[5].mFileTimeLo = 0U;
  (*c3_b_info)[5].mFileTimeHi = 0U;
  (*c3_b_info)[6].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c3_b_info)[6].name = "power";
  (*c3_b_info)[6].dominantType = "double";
  (*c3_b_info)[6].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/power.m";
  (*c3_b_info)[6].fileTimeLo = 1307651240U;
  (*c3_b_info)[6].fileTimeHi = 0U;
  (*c3_b_info)[6].mFileTimeLo = 0U;
  (*c3_b_info)[6].mFileTimeHi = 0U;
  (*c3_b_info)[7].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/power.m";
  (*c3_b_info)[7].name = "eml_scalar_eg";
  (*c3_b_info)[7].dominantType = "double";
  (*c3_b_info)[7].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c3_b_info)[7].fileTimeLo = 1286818796U;
  (*c3_b_info)[7].fileTimeHi = 0U;
  (*c3_b_info)[7].mFileTimeLo = 0U;
  (*c3_b_info)[7].mFileTimeHi = 0U;
  (*c3_b_info)[8].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/power.m";
  (*c3_b_info)[8].name = "eml_scalexp_alloc";
  (*c3_b_info)[8].dominantType = "double";
  (*c3_b_info)[8].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c3_b_info)[8].fileTimeLo = 1286818796U;
  (*c3_b_info)[8].fileTimeHi = 0U;
  (*c3_b_info)[8].mFileTimeLo = 0U;
  (*c3_b_info)[8].mFileTimeHi = 0U;
  (*c3_b_info)[9].context =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/ops/power.m";
  (*c3_b_info)[9].name = "eml_scalar_floor";
  (*c3_b_info)[9].dominantType = "double";
  (*c3_b_info)[9].resolved =
    "[ILXE]/usr/local/matlab/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c3_b_info)[9].fileTimeLo = 1286818726U;
  (*c3_b_info)[9].fileTimeHi = 0U;
  (*c3_b_info)[9].mFileTimeLo = 0U;
  (*c3_b_info)[9].mFileTimeHi = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 10), FALSE);
  for (c3_i19 = 0; c3_i19 < 10; c3_i19++) {
    c3_r0 = &c3_info[c3_i19];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i19);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i19);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i19);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i19);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i19);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i19);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i19);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i19);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static real_T c3_mpower(SFc3_QmoddefInstanceStruct *chartInstance, real_T c3_a)
{
  real_T c3_b_a;
  real_T c3_ak;
  c3_b_a = c3_a;
  c3_ak = c3_b_a;
  return muDoubleScalarPower(c3_ak, 2.0);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc3_QmoddefInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn(SFc3_QmoddefInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i20;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i20, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i20;
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
  SFc3_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc3_QmoddefInstanceStruct *)chartInstanceVoid;
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

static uint8_T c3_e_emlrt_marshallIn(SFc3_QmoddefInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_Qmoddef, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_Qmoddef), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_Qmoddef);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_QmoddefInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_QmoddefInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_Qmoddef_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2388608189U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3842249681U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3641616359U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3208078127U);
}

mxArray *sf_c3_Qmoddef_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ZrD7nG5KFaGz8Hab4NX6sH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
      pr[0] = (double)(3);
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

static const mxArray *sf_get_sim_state_info_c3_Qmoddef(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"C\",},{M[8],M[0],T\"is_active_c3_Qmoddef\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Qmoddef_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_QmoddefInstanceStruct *chartInstance;
    chartInstance = (SFc3_QmoddefInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_QmoddefMachineNumber_,
          3,
          1,
          1,
          8,
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
          _SFD_SET_DATA_PROPS(3,2,0,1,"C");
          _SFD_SET_DATA_PROPS(4,1,1,0,"dPhi");
          _SFD_SET_DATA_PROPS(5,1,1,0,"dTheta");
          _SFD_SET_DATA_PROPS(6,1,1,0,"dPsi");
          _SFD_SET_DATA_PROPS(7,1,1,0,"I");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1337);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c3_Phi;
          real_T *c3_Theta;
          real_T *c3_Psi;
          real_T *c3_dPhi;
          real_T *c3_dTheta;
          real_T *c3_dPsi;
          real_T (*c3_C)[9];
          real_T (*c3_I)[3];
          c3_I = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
          c3_dPsi = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_dTheta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_dPhi = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c3_Psi = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_Phi = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_Phi);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_Theta);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_Psi);
          _SFD_SET_DATA_VALUE_PTR(3U, *c3_C);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_dPhi);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_dTheta);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_dPsi);
          _SFD_SET_DATA_VALUE_PTR(7U, *c3_I);
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
  return "E5Omb54991w7lHY6sCUIUH";
}

static void sf_opaque_initialize_c3_Qmoddef(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_QmoddefInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c3_Qmoddef((SFc3_QmoddefInstanceStruct*) chartInstanceVar);
  initialize_c3_Qmoddef((SFc3_QmoddefInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_Qmoddef(void *chartInstanceVar)
{
  enable_c3_Qmoddef((SFc3_QmoddefInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_Qmoddef(void *chartInstanceVar)
{
  disable_c3_Qmoddef((SFc3_QmoddefInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_Qmoddef(void *chartInstanceVar)
{
  sf_c3_Qmoddef((SFc3_QmoddefInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_Qmoddef(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_Qmoddef((SFc3_QmoddefInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_Qmoddef();/* state var info */
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

extern void sf_internal_set_sim_state_c3_Qmoddef(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_Qmoddef();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_Qmoddef((SFc3_QmoddefInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_Qmoddef(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_Qmoddef(S);
}

static void sf_opaque_set_sim_state_c3_Qmoddef(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_Qmoddef(S, st);
}

static void sf_opaque_terminate_c3_Qmoddef(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_QmoddefInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_Qmoddef((SFc3_QmoddefInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Qmoddef_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Qmoddef((SFc3_QmoddefInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Qmoddef(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_Qmoddef((SFc3_QmoddefInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_Qmoddef(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Qmoddef_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(266042750U));
  ssSetChecksum1(S,(962345496U));
  ssSetChecksum2(S,(1383834944U));
  ssSetChecksum3(S,(3505580536U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_Qmoddef(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_Qmoddef(SimStruct *S)
{
  SFc3_QmoddefInstanceStruct *chartInstance;
  chartInstance = (SFc3_QmoddefInstanceStruct *)malloc(sizeof
    (SFc3_QmoddefInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_QmoddefInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_Qmoddef;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_Qmoddef;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_Qmoddef;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_Qmoddef;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_Qmoddef;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_Qmoddef;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_Qmoddef;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_Qmoddef;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Qmoddef;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Qmoddef;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_Qmoddef;
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

void c3_Qmoddef_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Qmoddef(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Qmoddef(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Qmoddef(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Qmoddef_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

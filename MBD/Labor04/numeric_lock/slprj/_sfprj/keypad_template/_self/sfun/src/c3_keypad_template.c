/* Include files */

#include "simstruc.h"
#include "fixedpoint.h"
#include "simtarget/slSimTgtLogLoadBlocksSfcnBridge.h"
#include "keypad_template_sfun.h"
#include "c3_keypad_template.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "keypad_template_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_CHECK                    ((uint8_T)1U)
#define c3_IN_IDLE                     ((uint8_T)2U)
#define c3_IN_INIT                     ((uint8_T)3U)
#define c3_IN_LOCKED                   ((uint8_T)4U)
#define c3_IN_READING                  ((uint8_T)5U)
#define c3_IN_SYSTEM_LOCKDOWN          ((uint8_T)6U)
#define c3_IN_UNLOCK                   ((uint8_T)7U)
#define c3_IN_WRONG_CODE               ((uint8_T)8U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_sv0[9] = { "INIT", "IDLE", "KEY_PRESSED", "READING",
  "CHECK", "UNLOCK", "WRONG_CODE", "SYSTEM_LOCKDOWN", "LOCKED" };

static const int32_T c3_iv0[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

/* Function Declarations */
static void c3_sdiInitialize(SFc3_keypad_templateInstanceStruct *chartInstance);
static void c3_sdiTerminate(SFc3_keypad_templateInstanceStruct *chartInstance);
static void initialize_c3_keypad_template(SFc3_keypad_templateInstanceStruct
  *chartInstance);
static void initialize_params_c3_keypad_template
  (SFc3_keypad_templateInstanceStruct *chartInstance);
static void enable_c3_keypad_template(SFc3_keypad_templateInstanceStruct
  *chartInstance);
static void disable_c3_keypad_template(SFc3_keypad_templateInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_keypad_template
  (SFc3_keypad_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c3_keypad_template(SFc3_keypad_templateInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c3_keypad_template
  (SFc3_keypad_templateInstanceStruct *chartInstance);
static void set_sim_state_c3_keypad_template(SFc3_keypad_templateInstanceStruct *
  chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_keypad_template
  (SFc3_keypad_templateInstanceStruct *chartInstance);
static void finalize_c3_keypad_template(SFc3_keypad_templateInstanceStruct
  *chartInstance);
static void sf_gateway_c3_keypad_template(SFc3_keypad_templateInstanceStruct
  *chartInstance);
static void mdl_start_c3_keypad_template(SFc3_keypad_templateInstanceStruct
  *chartInstance);
static void c3_c3_keypad_template(SFc3_keypad_templateInstanceStruct
  *chartInstance);
static void initSimStructsc3_keypad_template(SFc3_keypad_templateInstanceStruct *
  chartInstance);
static void c3_enter_atomic_INIT(SFc3_keypad_templateInstanceStruct
  *chartInstance);
static void c3_enter_atomic_LOCKED(SFc3_keypad_templateInstanceStruct
  *chartInstance);
static void c3_CHECK(SFc3_keypad_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_nargin, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static c3_States c3_e_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_b_state, const char_T *c3_identifier);
static c3_States c3_f_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_g_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_b_seq_key, const char_T *c3_identifier,
  real_T c3_y[4]);
static void c3_h_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4]);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_i_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_keypad_template, const char_T
  *c3_identifier);
static uint8_T c3_j_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static uint16_T c3_k_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_b_temporalCounter_i1, const char_T
  *c3_identifier);
static uint16_T c3_l_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_m_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[7]);
static void c3_n_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[7]);
static const mxArray *c3_o_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_p_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc3_keypad_templateInstanceStruct *chartInstance, int32_T c3_ssid);
static void c3_init_sf_message_store_memory(SFc3_keypad_templateInstanceStruct
  *chartInstance);
static void c3_sdiStreamingWrapperFcn(SFc3_keypad_templateInstanceStruct
  *chartInstance, int32_T c3_modeFlag, int32_T c3_ssidIdx, uint32_T c3_ssid,
  void *c3_streamedData);
static void c3_b_sdiStreamingWrapperFcn(SFc3_keypad_templateInstanceStruct
  *chartInstance, int32_T c3_modeFlag, int32_T c3_ssidIdx, uint32_T c3_ssid,
  int32_T c3_streamedData);
static void c3_c_sdiStreamingWrapperFcn(SFc3_keypad_templateInstanceStruct
  *chartInstance, int32_T c3_modeFlag, int32_T c3_ssidIdx, uint32_T c3_ssid,
  int32_T c3_streamedData);
static void c3_d_sdiStreamingWrapperFcn(SFc3_keypad_templateInstanceStruct
  *chartInstance, int32_T c3_modeFlag, int32_T c3_ssidIdx, uint32_T c3_ssid,
  void *c3_streamedData);
static void init_test_point_addr_map(SFc3_keypad_templateInstanceStruct
  *chartInstance);
static void **get_test_point_address_map(SFc3_keypad_templateInstanceStruct
  *chartInstance);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc3_keypad_templateInstanceStruct *chartInstance);
static void **get_dataset_logging_obj_vector(SFc3_keypad_templateInstanceStruct *
  chartInstance);
static void init_dsm_address_info(SFc3_keypad_templateInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_keypad_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void c3_sdiInitialize(SFc3_keypad_templateInstanceStruct *chartInstance)
{
  uint32_T c3_b[9] = { 0U, 8U, 5U, 1U, 55U, 7U, 11U, 9U, 10U };

  uint32_T c3_c[10] = { 22U, 25U, 28U, 36U, 38U, 44U, 27U, 58U, 60U, 37U };

  const char * c3_d[9] = { "None", "CHECK", "IDLE", "INIT", "LOCKED", "READING",
    "SYSTEM_LOCKDOWN", "UNLOCK", "WRONG_CODE" };

  int32_T c3_e[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

  const char * c3_f[9] = { "None", "INIT", "LOCKED", "IDLE", "READING", "CHECK",
    "UNLOCK", "WRONG_CODE", "SYSTEM_LOCKDOWN" };

  int32_T c3_g[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

  const char * c3_h[9] = { "INIT", "IDLE", "KEY_PRESSED", "READING", "CHECK",
    "UNLOCK", "WRONG_CODE", "SYSTEM_LOCKDOWN", "LOCKED" };

  int32_T c3_j[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

  int32_T c3_k[1] = { 1 };

  int32_T c3_l[1] = { 1 };

  int32_T c3_m[1] = { 1 };

  int32_T c3_n[1] = { 4 };

  int32_T c3_o[1] = { 1 };

  int32_T c3_p[1] = { 4 };

  int32_T c3_q[1] = { 1 };

  chartInstance->c3_sdiBlockInfo.mdlRefFullPath = "";
  chartInstance->c3_sdiBlockInfo.SimStruct = (void *)chartInstance->S;
  chartInstance->c3_sdiBlockInfo.blkPath = "";
  chartInstance->c3_sdiBlockInfo.blkSID = "keypad_template:105";
  chartInstance->c3_sdiBlockInfo.sharedSCMPath = "";
  chartInstance->c3_sdiBlockInfo.sdiRuntime = NULL;
  sdi_database_initialize(&chartInstance->c3_sdiBlockInfo, c3_b, (uint8_T *)
    &chartInstance->c3_sdiLoggedStatesBuffer[0U], 9, c3_c, (uint8_T *)
    &chartInstance->c3_sdiLoggedDataBuffer[0U], 10);
  if (chartInstance->c3_sdiLoggedStatesBuffer[0U] & 1) {
    sdi_register_child_activity_signal(&chartInstance->c3_sdiBlockInfo,
      "numeric sequence lock/Chart", "", 9, c3_d, c3_e, sizeof(uint8_T), 1, 0U);
  }

  if (chartInstance->c3_sdiLoggedStatesBuffer[0U] & 2) {
    sdi_register_leaf_activity_signal(&chartInstance->c3_sdiBlockInfo,
      "numeric sequence lock/Chart", "", 9, c3_f, c3_g, 1, 0U);
  }

  chartInstance->c3_SignalExportProp.logName = "";
  chartInstance->c3_SignalExportProp.signalName = "CHECK";
  chartInstance->c3_SignalExportProp.useCustomName = 0;
  chartInstance->c3_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_SignalExportProp.decimate = 0;
  chartInstance->c3_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_SignalExportProp.decimation = 2U;
  if (chartInstance->c3_sdiLoggedStatesBuffer[1U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c3_sdiBlockInfo, "CHECK",
      "CHECK", 1, &chartInstance->c3_SignalExportProp, 8U);
  }

  chartInstance->c3_b_SignalExportProp.logName = "";
  chartInstance->c3_b_SignalExportProp.signalName = "IDLE";
  chartInstance->c3_b_SignalExportProp.useCustomName = 0;
  chartInstance->c3_b_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_b_SignalExportProp.decimate = 0;
  chartInstance->c3_b_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_b_SignalExportProp.decimation = 2U;
  if (chartInstance->c3_sdiLoggedStatesBuffer[2U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c3_sdiBlockInfo, "IDLE",
      "IDLE", 1, &chartInstance->c3_b_SignalExportProp, 5U);
  }

  chartInstance->c3_c_SignalExportProp.logName = "";
  chartInstance->c3_c_SignalExportProp.signalName = "INIT";
  chartInstance->c3_c_SignalExportProp.useCustomName = 0;
  chartInstance->c3_c_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_c_SignalExportProp.decimate = 0;
  chartInstance->c3_c_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_c_SignalExportProp.decimation = 2U;
  if (chartInstance->c3_sdiLoggedStatesBuffer[3U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c3_sdiBlockInfo, "INIT",
      "INIT", 1, &chartInstance->c3_c_SignalExportProp, 1U);
  }

  chartInstance->c3_d_SignalExportProp.logName = "";
  chartInstance->c3_d_SignalExportProp.signalName = "LOCKED";
  chartInstance->c3_d_SignalExportProp.useCustomName = 0;
  chartInstance->c3_d_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_d_SignalExportProp.decimate = 0;
  chartInstance->c3_d_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_d_SignalExportProp.decimation = 2U;
  if (chartInstance->c3_sdiLoggedStatesBuffer[4U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c3_sdiBlockInfo, "LOCKED",
      "LOCKED", 1, &chartInstance->c3_d_SignalExportProp, 55U);
  }

  chartInstance->c3_e_SignalExportProp.logName = "";
  chartInstance->c3_e_SignalExportProp.signalName = "READING";
  chartInstance->c3_e_SignalExportProp.useCustomName = 0;
  chartInstance->c3_e_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_e_SignalExportProp.decimate = 0;
  chartInstance->c3_e_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_e_SignalExportProp.decimation = 2U;
  if (chartInstance->c3_sdiLoggedStatesBuffer[5U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c3_sdiBlockInfo, "READING",
      "READING", 1, &chartInstance->c3_e_SignalExportProp, 7U);
  }

  chartInstance->c3_f_SignalExportProp.logName = "";
  chartInstance->c3_f_SignalExportProp.signalName = "SYSTEM_LOCKDOWN";
  chartInstance->c3_f_SignalExportProp.useCustomName = 0;
  chartInstance->c3_f_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_f_SignalExportProp.decimate = 0;
  chartInstance->c3_f_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_f_SignalExportProp.decimation = 2U;
  if (chartInstance->c3_sdiLoggedStatesBuffer[6U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c3_sdiBlockInfo,
      "SYSTEM_LOCKDOWN", "SYSTEM_LOCKDOWN", 1,
      &chartInstance->c3_f_SignalExportProp, 11U);
  }

  chartInstance->c3_g_SignalExportProp.logName = "";
  chartInstance->c3_g_SignalExportProp.signalName = "UNLOCK";
  chartInstance->c3_g_SignalExportProp.useCustomName = 0;
  chartInstance->c3_g_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_g_SignalExportProp.decimate = 0;
  chartInstance->c3_g_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_g_SignalExportProp.decimation = 2U;
  if (chartInstance->c3_sdiLoggedStatesBuffer[7U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c3_sdiBlockInfo, "UNLOCK",
      "UNLOCK", 1, &chartInstance->c3_g_SignalExportProp, 9U);
  }

  chartInstance->c3_h_SignalExportProp.logName = "";
  chartInstance->c3_h_SignalExportProp.signalName = "WRONG_CODE";
  chartInstance->c3_h_SignalExportProp.useCustomName = 0;
  chartInstance->c3_h_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_h_SignalExportProp.decimate = 0;
  chartInstance->c3_h_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_h_SignalExportProp.decimation = 2U;
  if (chartInstance->c3_sdiLoggedStatesBuffer[8U] & 4) {
    sdi_register_self_activity_signal(&chartInstance->c3_sdiBlockInfo,
      "WRONG_CODE", "WRONG_CODE", 1, &chartInstance->c3_h_SignalExportProp, 10U);
  }

  chartInstance->c3_i_SignalExportProp.logName = "";
  chartInstance->c3_i_SignalExportProp.signalName = "state";
  chartInstance->c3_i_SignalExportProp.useCustomName = 0;
  chartInstance->c3_i_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_i_SignalExportProp.decimate = 0;
  chartInstance->c3_i_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_i_SignalExportProp.decimation = 1U;
  if (chartInstance->c3_sdiLoggedDataBuffer[1U]) {
    sdi_register_enum_data_type_signal(&chartInstance->c3_sdiBlockInfo, "state",
      "", "States", 9, c3_h, c3_j, 4, 0, 1, c3_k, 1, 0, 0,
      &chartInstance->c3_i_SignalExportProp, 25U);
  }

  chartInstance->c3_j_SignalExportProp.logName = "";
  chartInstance->c3_j_SignalExportProp.signalName = "i";
  chartInstance->c3_j_SignalExportProp.useCustomName = 0;
  chartInstance->c3_j_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_j_SignalExportProp.decimate = 0;
  chartInstance->c3_j_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_j_SignalExportProp.decimation = 1U;
  if (chartInstance->c3_sdiLoggedDataBuffer[2U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c3_sdiBlockInfo, "i",
      "", 1, c3_l, 1, 0, 0, 0, &chartInstance->c3_j_SignalExportProp, "", 28U);
  }

  chartInstance->c3_k_SignalExportProp.logName = "";
  chartInstance->c3_k_SignalExportProp.signalName = "sequence_length";
  chartInstance->c3_k_SignalExportProp.useCustomName = 0;
  chartInstance->c3_k_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_k_SignalExportProp.decimate = 0;
  chartInstance->c3_k_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_k_SignalExportProp.decimation = 1U;
  if (chartInstance->c3_sdiLoggedDataBuffer[3U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c3_sdiBlockInfo,
      "sequence_length", "", 1, c3_m, 1, 0, 0, 0,
      &chartInstance->c3_k_SignalExportProp, "", 36U);
  }

  chartInstance->c3_l_SignalExportProp.logName = "";
  chartInstance->c3_l_SignalExportProp.signalName = "seq_key";
  chartInstance->c3_l_SignalExportProp.useCustomName = 0;
  chartInstance->c3_l_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_l_SignalExportProp.decimate = 0;
  chartInstance->c3_l_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_l_SignalExportProp.decimation = 1U;
  if (chartInstance->c3_sdiLoggedDataBuffer[4U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c3_sdiBlockInfo,
      "seq_key", "", 1, c3_n, 1, 0, 0, 0, &chartInstance->c3_l_SignalExportProp,
      "", 38U);
  }

  chartInstance->c3_m_SignalExportProp.logName = "";
  chartInstance->c3_m_SignalExportProp.signalName = "sequece_length";
  chartInstance->c3_m_SignalExportProp.useCustomName = 0;
  chartInstance->c3_m_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_m_SignalExportProp.decimate = 0;
  chartInstance->c3_m_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_m_SignalExportProp.decimation = 1U;
  if (chartInstance->c3_sdiLoggedDataBuffer[5U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c3_sdiBlockInfo,
      "sequece_length", "", 1, c3_o, 1, 0, 0, 0,
      &chartInstance->c3_m_SignalExportProp, "", 44U);
  }

  chartInstance->c3_n_SignalExportProp.logName = "";
  chartInstance->c3_n_SignalExportProp.signalName = "user_seq";
  chartInstance->c3_n_SignalExportProp.useCustomName = 0;
  chartInstance->c3_n_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_n_SignalExportProp.decimate = 0;
  chartInstance->c3_n_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_n_SignalExportProp.decimation = 1U;
  if (chartInstance->c3_sdiLoggedDataBuffer[6U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c3_sdiBlockInfo,
      "user_seq", "", 1, c3_p, 1, 0, 0, 0, &chartInstance->c3_n_SignalExportProp,
      "", 27U);
  }

  chartInstance->c3_o_SignalExportProp.logName = "";
  chartInstance->c3_o_SignalExportProp.signalName = "fail_cntr";
  chartInstance->c3_o_SignalExportProp.useCustomName = 0;
  chartInstance->c3_o_SignalExportProp.limitDataPoints = 0;
  chartInstance->c3_o_SignalExportProp.decimate = 0;
  chartInstance->c3_o_SignalExportProp.maxPoints = 5000U;
  chartInstance->c3_o_SignalExportProp.decimation = 1U;
  if (chartInstance->c3_sdiLoggedDataBuffer[9U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c3_sdiBlockInfo,
      "fail_cntr", "", 1, c3_q, 1, 0, 0, 0,
      &chartInstance->c3_o_SignalExportProp, "", 37U);
  }
}

static void c3_sdiTerminate(SFc3_keypad_templateInstanceStruct *chartInstance)
{
  sdi_database_terminate(&chartInstance->c3_sdiBlockInfo);
}

static void initialize_c3_keypad_template(SFc3_keypad_templateInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_keypad_template(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  sim_mode_is_external(chartInstance->S);
  *chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c3_temporalCounter_i1 = 0U;
  *chartInstance->c3_is_active_c3_keypad_template = 0U;
  *chartInstance->c3_is_c3_keypad_template = c3_IN_NO_ACTIVE_CHILD;
  c3_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U,
    chartInstance->c3_is_c3_keypad_template);
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 1));
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 2));
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 3));
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 4));
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 5));
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 6));
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 7));
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 8));
  c3_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 0);
  setLegacyDebuggerFlagForRuntime(chartInstance->S, true);
}

static void initialize_params_c3_keypad_template
  (SFc3_keypad_templateInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_keypad_template(SFc3_keypad_templateInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_keypad_template(SFc3_keypad_templateInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_keypad_template
  (SFc3_keypad_templateInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*chartInstance->c3_is_active_c3_keypad_template == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_c3_keypad_template == c3_IN_INIT) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_c3_keypad_template == c3_IN_LOCKED) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_c3_keypad_template == c3_IN_IDLE) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_c3_keypad_template == c3_IN_READING) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_c3_keypad_template == c3_IN_CHECK) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_c3_keypad_template == c3_IN_UNLOCK) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_c3_keypad_template == c3_IN_WRONG_CODE) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_c3_keypad_template == c3_IN_SYSTEM_LOCKDOWN) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c3_keypad_template(SFc3_keypad_templateInstanceStruct *
  chartInstance)
{
  c3_update_debugger_state_c3_keypad_template(chartInstance);
}

static const mxArray *get_sim_state_c3_keypad_template
  (SFc3_keypad_templateInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  const mxArray *c3_b_y = NULL;
  c3_States c3_b_hoistedGlobal;
  const mxArray *c3_c_y = NULL;
  int32_T c3_u;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_m0 = NULL;
  const mxArray *c3_e_y = NULL;
  real_T c3_c_hoistedGlobal;
  const mxArray *c3_f_y = NULL;
  const mxArray *c3_g_y = NULL;
  real_T c3_d_hoistedGlobal;
  const mxArray *c3_h_y = NULL;
  real_T c3_e_hoistedGlobal;
  const mxArray *c3_i_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  const mxArray *c3_j_y = NULL;
  uint8_T c3_g_hoistedGlobal;
  const mxArray *c3_k_y = NULL;
  uint16_T c3_h_hoistedGlobal;
  const mxArray *c3_l_y = NULL;
  real_T c3_i_hoistedGlobal;
  const mxArray *c3_m_y = NULL;
  const mxArray *c3_n_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(12, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_fail_cntr;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *chartInstance->c3_state;
  c3_c_y = NULL;
  sf_mex_check_enum("States", 9, c3_sv0, c3_iv0);
  c3_u = (int16_T)c3_b_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_m0, c3_d_y, false);
  sf_mex_assign(&c3_c_y, sf_mex_create_enum("States", c3_m0), false);
  sf_mex_destroy(&c3_m0);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", *chartInstance->c3_user_seq, 0, 0U,
    1U, 0U, 1, 4), false);
  sf_mex_setcell(c3_y, 2, c3_e_y);
  c3_c_hoistedGlobal = *chartInstance->c3_i;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_c_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 3, c3_f_y);
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", *chartInstance->c3_seq_key, 0, 0U,
    1U, 0U, 1, 4), false);
  sf_mex_setcell(c3_y, 4, c3_g_y);
  c3_d_hoistedGlobal = *chartInstance->c3_sequece_length;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_d_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 5, c3_h_y);
  c3_e_hoistedGlobal = *chartInstance->c3_sequence_length;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_e_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 6, c3_i_y);
  c3_f_hoistedGlobal = *chartInstance->c3_is_active_c3_keypad_template;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_f_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 7, c3_j_y);
  c3_g_hoistedGlobal = *chartInstance->c3_is_c3_keypad_template;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_g_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 8, c3_k_y);
  c3_h_hoistedGlobal = *chartInstance->c3_temporalCounter_i1;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_h_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 9, c3_l_y);
  c3_i_hoistedGlobal = *chartInstance->c3_user_input_start;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_i_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 10, c3_m_y);
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y",
    chartInstance->c3_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 7), false);
  sf_mex_setcell(c3_y, 11, c3_n_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_keypad_template(SFc3_keypad_templateInstanceStruct *
  chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[4];
  int32_T c3_i0;
  real_T c3_dv1[4];
  int32_T c3_i1;
  boolean_T c3_bv0[7];
  int32_T c3_i2;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_fail_cntr = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "fail_cntr");
  c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 9, 37U,
    chartInstance->c3_fail_cntr);
  *chartInstance->c3_state = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "state");
  c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 25U, chartInstance->c3_state);
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
                        "user_seq", c3_dv0);
  for (c3_i0 = 0; c3_i0 < 4; c3_i0++) {
    (*chartInstance->c3_user_seq)[c3_i0] = c3_dv0[c3_i0];
  }

  c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 6, 27U,
    chartInstance->c3_user_seq);
  *chartInstance->c3_i = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 3)), "i");
  c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 28U, chartInstance->c3_i);
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
                        "seq_key", c3_dv1);
  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    (*chartInstance->c3_seq_key)[c3_i1] = c3_dv1[c3_i1];
  }

  c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 4, 38U,
    chartInstance->c3_seq_key);
  *chartInstance->c3_sequece_length = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 5)), "sequece_length");
  c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 5, 44U,
    chartInstance->c3_sequece_length);
  *chartInstance->c3_sequence_length = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 6)), "sequence_length");
  c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 3, 36U,
    chartInstance->c3_sequence_length);
  *chartInstance->c3_is_active_c3_keypad_template = c3_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 7)),
     "is_active_c3_keypad_template");
  *chartInstance->c3_is_c3_keypad_template = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 8)), "is_c3_keypad_template");
  c3_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U,
    chartInstance->c3_is_c3_keypad_template);
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 1));
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 2));
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 3));
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 4));
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 5));
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 6));
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 7));
  c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
    (*chartInstance->c3_is_c3_keypad_template == 8));
  *chartInstance->c3_temporalCounter_i1 = c3_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 9)), "temporalCounter_i1");
  *chartInstance->c3_user_input_start = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 10)), "user_input_start");
  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 11)),
                        "dataWrittenToVector", c3_bv0);
  for (c3_i2 = 0; c3_i2 < 7; c3_i2++) {
    chartInstance->c3_dataWrittenToVector[c3_i2] = c3_bv0[c3_i2];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 12)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_keypad_template(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_keypad_template
  (SFc3_keypad_templateInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if ((*chartInstance->c3_is_c3_keypad_template == c3_IN_SYSTEM_LOCKDOWN) &&
        (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                    "setSimStateSideEffectsInfo", 1, 7) == 0.0)) {
      *chartInstance->c3_temporalCounter_i1 = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_keypad_template(SFc3_keypad_templateInstanceStruct
  *chartInstance)
{
  c3_sdiTerminate(chartInstance);
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_keypad_template(SFc3_keypad_templateInstanceStruct
  *chartInstance)
{
  c3_set_sim_state_side_effects_c3_keypad_template(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (*chartInstance->c3_temporalCounter_i1 < 2047U) {
    *chartInstance->c3_temporalCounter_i1 = (uint16_T)((uint32_T)
      *chartInstance->c3_temporalCounter_i1 + 1U);
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0, *chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_enter, 6U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_lock, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_user_input, 4U);
  *chartInstance->c3_sfEvent = CALL_EVENT;
  *chartInstance->c3_user_input_prev = *chartInstance->c3_user_input_start;
  *chartInstance->c3_user_input_start = *chartInstance->c3_user_input;
  c3_c3_keypad_template(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c3_keypad_template(SFc3_keypad_templateInstanceStruct
  *chartInstance)
{
  c3_init_sf_message_store_memory(chartInstance);
  c3_sdiInitialize(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void c3_c3_keypad_template(SFc3_keypad_templateInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  uint32_T c3_c_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  uint32_T c3_d_debug_family_var_map[3];
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  uint32_T c3_e_debug_family_var_map[3];
  real_T c3_nargout = 1.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_c_nargout = 1.0;
  real_T c3_e_nargin = 0.0;
  boolean_T c3_out;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_d_out;
  boolean_T c3_e_out;
  uint32_T c3_f_debug_family_var_map[3];
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 1.0;
  boolean_T c3_f_out;
  uint32_T c3_g_debug_family_var_map[2];
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  c3_States c3_hoistedGlobal;
  uint32_T c3_h_debug_family_var_map[2];
  const mxArray *c3_y = NULL;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  int32_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint32_T c3_i_debug_family_var_map[2];
  const mxArray *c3_m1 = NULL;
  uint32_T c3_j_debug_family_var_map[2];
  real_T c3_i_nargin = 0.0;
  real_T c3_j_nargin = 0.0;
  real_T c3_i_nargout = 0.0;
  real_T c3_j_nargout = 0.0;
  c3_States c3_b_hoistedGlobal;
  const mxArray *c3_c_y = NULL;
  int32_T c3_b_u;
  const mxArray *c3_d_y = NULL;
  c3_States c3_c_hoistedGlobal;
  c3_States c3_d_hoistedGlobal;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_m2 = NULL;
  uint32_T c3_k_debug_family_var_map[2];
  const mxArray *c3_f_y = NULL;
  real_T c3_k_nargin = 0.0;
  int32_T c3_c_u;
  real_T c3_k_nargout = 0.0;
  int32_T c3_d_u;
  const mxArray *c3_g_y = NULL;
  const mxArray *c3_h_y = NULL;
  const mxArray *c3_m3 = NULL;
  const mxArray *c3_m4 = NULL;
  c3_States c3_e_hoistedGlobal;
  const mxArray *c3_i_y = NULL;
  int32_T c3_e_u;
  real_T c3_f_hoistedGlobal;
  const mxArray *c3_j_y = NULL;
  const mxArray *c3_k_y = NULL;
  const mxArray *c3_m5 = NULL;
  int32_T c3_i3;
  const mxArray *c3_l_y = NULL;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
  if (*chartInstance->c3_is_active_c3_keypad_template == 0U) {
    *chartInstance->c3_user_input_prev = *chartInstance->c3_user_input;
    *chartInstance->c3_user_input_start = *chartInstance->c3_user_input;
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_active_c3_keypad_template = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_c3_keypad_template = c3_IN_INIT;
    c3_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U,
      chartInstance->c3_is_c3_keypad_template);
    c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
      (*chartInstance->c3_is_c3_keypad_template == 1));
    c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
      (*chartInstance->c3_is_c3_keypad_template == 2));
    c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
      (*chartInstance->c3_is_c3_keypad_template == 3));
    c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
      (*chartInstance->c3_is_c3_keypad_template == 4));
    c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
      (*chartInstance->c3_is_c3_keypad_template == 5));
    c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
      (*chartInstance->c3_is_c3_keypad_template == 6));
    c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
      (*chartInstance->c3_is_c3_keypad_template == 7));
    c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
      (*chartInstance->c3_is_c3_keypad_template == 8));
    c3_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 1);
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
    c3_enter_atomic_INIT(chartInstance);
  } else {
    switch (*chartInstance->c3_is_c3_keypad_template) {
     case c3_IN_CHECK:
      CV_CHART_EVAL(0, 0, c3_IN_CHECK);
      c3_CHECK(chartInstance);
      break;

     case c3_IN_IDLE:
      CV_CHART_EVAL(0, 0, c3_IN_IDLE);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      if (CV_EML_IF(1, 0, 0, *chartInstance->c3_user_input_prev !=
                    *chartInstance->c3_user_input_start)) {
        c3_out = true;
      } else {
        c3_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_c3_keypad_template = c3_IN_NO_ACTIVE_CHILD;
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 1));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 2));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 3));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 4));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 5));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 6));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 7));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 8));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_c3_keypad_template = c3_IN_READING;
        c3_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U,
          chartInstance->c3_is_c3_keypad_template);
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 1));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 2));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 3));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 4));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 5));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 6));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 7));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 8));
        c3_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 4);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
          c3_h_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_state = States_READING;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 25U,
          chartInstance->c3_state);
        if (!chartInstance->c3_dataWrittenToVector[0U]) {
          sf_read_before_write_error(chartInstance->S, 7U, 7U, 15, 5);
        }

        sf_mex_printf("%s =\\n", "state");
        c3_b_hoistedGlobal = *chartInstance->c3_state;
        c3_c_y = NULL;
        sf_mex_check_enum("States", 9, c3_sv0, c3_iv0);
        c3_b_u = (int16_T)c3_b_hoistedGlobal;
        c3_d_y = NULL;
        sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_b_u, 6, 0U, 0U, 0U, 0),
                      false);
        sf_mex_assign(&c3_m2, c3_d_y, false);
        sf_mex_assign(&c3_c_y, sf_mex_create_enum("States", c3_m2), false);
        sf_mex_destroy(&c3_m2);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c3_c_y);
        if (!chartInstance->c3_dataWrittenToVector[1U]) {
          sf_read_before_write_error(chartInstance->S, 0U, 7U, 42, 1);
        }

        (*chartInstance->c3_i)++;
        chartInstance->c3_dataWrittenToVector[1U] = true;
        c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 28U,
          chartInstance->c3_i);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_i, 0U);
        if (!chartInstance->c3_dataWrittenToVector[1U]) {
          sf_read_before_write_error(chartInstance->S, 0U, 7U, 38, 1);
        }

        sf_mex_printf("%s =\\n", "i");
        c3_f_hoistedGlobal = *chartInstance->c3_i;
        c3_k_y = NULL;
        sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_f_hoistedGlobal, 0, 0U, 0U,
          0U, 0), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c3_k_y);
        if (!chartInstance->c3_dataWrittenToVector[1U]) {
          sf_read_before_write_error(chartInstance->S, 0U, 7U, 75, 1);
        }

        (*chartInstance->c3_user_seq)[sf_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 13U, 0, 0, 8U,
           sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 7U, 75, 1, 8U, (int32_T)sf_integer_check
            (chartInstance->S, 7U, 75U, 1U, *chartInstance->c3_i), 1, 4) - 1, 0,
           3)] = *chartInstance->c3_user_input;
        chartInstance->c3_dataWrittenToVector[5U] = true;
        c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 6, 27U,
          chartInstance->c3_user_seq);
        for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c3_user_seq)[c3_i3], 8U);
        }

        if (!chartInstance->c3_dataWrittenToVector[5U]) {
          sf_read_before_write_error(chartInstance->S, 8U, 7U, 66, 8);
        }

        sf_mex_printf("%s =\\n", "user_seq");
        c3_l_y = NULL;
        sf_mex_assign(&c3_l_y, sf_mex_create("y", *chartInstance->c3_user_seq, 0,
          0U, 1U, 0U, 1, 4), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c3_l_y);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     *chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c3_sfEvent);
      break;

     case c3_IN_INIT:
      CV_CHART_EVAL(0, 0, c3_IN_INIT);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_c3_keypad_template = c3_IN_NO_ACTIVE_CHILD;
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 1));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 2));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 3));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 4));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 5));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 6));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 7));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 8));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_c3_keypad_template = c3_IN_LOCKED;
      c3_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U,
        chartInstance->c3_is_c3_keypad_template);
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 1));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 2));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 3));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 4));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 5));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 6));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 7));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 8));
      c3_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 2);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
      c3_enter_atomic_LOCKED(chartInstance);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *chartInstance->c3_sfEvent);
      break;

     case c3_IN_LOCKED:
      CV_CHART_EVAL(0, 0, c3_IN_LOCKED);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_c3_keypad_template = c3_IN_NO_ACTIVE_CHILD;
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 1));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 2));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 3));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 4));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 5));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 6));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 7));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 8));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_c3_keypad_template = c3_IN_IDLE;
      c3_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U,
        chartInstance->c3_is_c3_keypad_template);
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 1));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 2));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 3));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 4));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 5));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 6));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 7));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 8));
      c3_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 3);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
        c3_g_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_state = States_IDLE;
      chartInstance->c3_dataWrittenToVector[0U] = true;
      c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 25U,
        chartInstance->c3_state);
      if (!chartInstance->c3_dataWrittenToVector[0U]) {
        sf_read_before_write_error(chartInstance->S, 7U, 5U, 12, 5);
      }

      sf_mex_printf("%s =\\n", "state");
      c3_hoistedGlobal = *chartInstance->c3_state;
      c3_y = NULL;
      sf_mex_check_enum("States", 9, c3_sv0, c3_iv0);
      c3_u = (int16_T)c3_hoistedGlobal;
      c3_b_y = NULL;
      sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
      sf_mex_assign(&c3_m1, c3_b_y, false);
      sf_mex_assign(&c3_y, sf_mex_create_enum("States", c3_m1), false);
      sf_mex_destroy(&c3_m1);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_y);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c3_sfEvent);
      break;

     case c3_IN_READING:
      CV_CHART_EVAL(0, 0, c3_IN_READING);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, *chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_n_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      if (!chartInstance->c3_dataWrittenToVector[1U]) {
        sf_read_before_write_error(chartInstance->S, 0U, 14U, 1, 1);
      }

      if (!chartInstance->c3_dataWrittenToVector[2U]) {
        sf_read_before_write_error(chartInstance->S, 3U, 14U, 6, 15);
      }

      if (CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0, *chartInstance->c3_i,
            *chartInstance->c3_sequence_length, -1, 5U, *chartInstance->c3_i >= *
            chartInstance->c3_sequence_length))) {
        c3_d_out = true;
      } else {
        c3_d_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_c3_keypad_template = c3_IN_NO_ACTIVE_CHILD;
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 1));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 2));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 3));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 4));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 5));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 6));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 7));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 8));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_c3_keypad_template = c3_IN_CHECK;
        c3_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U,
          chartInstance->c3_is_c3_keypad_template);
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 1));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 2));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 3));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 4));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 5));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 6));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 7));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 8));
        c3_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 5);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
          c3_j_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_state = States_CHECK;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 25U,
          chartInstance->c3_state);
        if (!chartInstance->c3_dataWrittenToVector[0U]) {
          sf_read_before_write_error(chartInstance->S, 7U, 8U, 13, 5);
        }

        sf_mex_printf("%s =\\n", "state");
        c3_d_hoistedGlobal = *chartInstance->c3_state;
        c3_f_y = NULL;
        sf_mex_check_enum("States", 9, c3_sv0, c3_iv0);
        c3_d_u = (int16_T)c3_d_hoistedGlobal;
        c3_h_y = NULL;
        sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_d_u, 6, 0U, 0U, 0U, 0),
                      false);
        sf_mex_assign(&c3_m4, c3_h_y, false);
        sf_mex_assign(&c3_f_y, sf_mex_create_enum("States", c3_m4), false);
        sf_mex_destroy(&c3_m4);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c3_f_y);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     *chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_l_debug_family_names,
          c3_f_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        if (CV_EML_IF(6, 0, 0, *chartInstance->c3_user_input_prev !=
                      *chartInstance->c3_user_input_start)) {
          c3_f_out = true;
        } else {
          c3_f_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c3_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
          *chartInstance->c3_is_c3_keypad_template = c3_IN_NO_ACTIVE_CHILD;
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 1));
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 2));
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 3));
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 4));
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 5));
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 6));
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 7));
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 8));
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
          *chartInstance->c3_is_c3_keypad_template = c3_IN_IDLE;
          c3_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U,
            chartInstance->c3_is_c3_keypad_template);
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 1));
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 2));
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 3));
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 4));
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 5));
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 6));
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 7));
          c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
            (*chartInstance->c3_is_c3_keypad_template == 8));
          c3_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 3);
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
            c3_k_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          *chartInstance->c3_state = States_IDLE;
          chartInstance->c3_dataWrittenToVector[0U] = true;
          c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 25U,
            chartInstance->c3_state);
          if (!chartInstance->c3_dataWrittenToVector[0U]) {
            sf_read_before_write_error(chartInstance->S, 7U, 5U, 12, 5);
          }

          sf_mex_printf("%s =\\n", "state");
          c3_e_hoistedGlobal = *chartInstance->c3_state;
          c3_i_y = NULL;
          sf_mex_check_enum("States", 9, c3_sv0, c3_iv0);
          c3_e_u = (int16_T)c3_e_hoistedGlobal;
          c3_j_y = NULL;
          sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_e_u, 6, 0U, 0U, 0U, 0),
                        false);
          sf_mex_assign(&c3_m5, c3_j_y, false);
          sf_mex_assign(&c3_i_y, sf_mex_create_enum("States", c3_m5), false);
          sf_mex_destroy(&c3_m5);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c3_i_y);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                       *chartInstance->c3_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *chartInstance->c3_sfEvent);
      break;

     case c3_IN_SYSTEM_LOCKDOWN:
      CV_CHART_EVAL(0, 0, c3_IN_SYSTEM_LOCKDOWN);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_k_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      if (CV_EML_IF(4, 0, 0, *chartInstance->c3_temporalCounter_i1 >= 1500)) {
        c3_b_out = true;
      } else {
        c3_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_c3_keypad_template = c3_IN_NO_ACTIVE_CHILD;
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 1));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 2));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 3));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 4));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 5));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 6));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 7));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 8));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_c3_keypad_template = c3_IN_LOCKED;
        c3_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U,
          chartInstance->c3_is_c3_keypad_template);
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 1));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 2));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 3));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 4));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 5));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 6));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 7));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 8));
        c3_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 2);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
        c3_enter_atomic_LOCKED(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                     *chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *chartInstance->c3_sfEvent);
      break;

     case c3_IN_UNLOCK:
      CV_CHART_EVAL(0, 0, c3_IN_UNLOCK);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_j_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      if (CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0, (real_T)
            *chartInstance->c3_lock, 1.0, -1, 0U, (int32_T)
            *chartInstance->c3_lock))) {
        c3_c_out = true;
      } else {
        c3_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_c3_keypad_template = c3_IN_NO_ACTIVE_CHILD;
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 1));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 2));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 3));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 4));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 5));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 6));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 7));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 8));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_c3_keypad_template = c3_IN_INIT;
        c3_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U,
          chartInstance->c3_is_c3_keypad_template);
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 1));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 2));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 3));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 4));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 5));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 6));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 7));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 8));
        c3_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 1);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
        c3_enter_atomic_INIT(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     *chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *chartInstance->c3_sfEvent);
      break;

     case c3_IN_WRONG_CODE:
      CV_CHART_EVAL(0, 0, c3_IN_WRONG_CODE);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_q_debug_family_names,
        c3_e_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      if (!chartInstance->c3_dataWrittenToVector[6U]) {
        sf_read_before_write_error(chartInstance->S, 9U, 34U, 1, 9);
      }

      if (CV_EML_IF(8, 0, 0, CV_RELATIONAL_EVAL(5U, 8U, 0,
            *chartInstance->c3_fail_cntr, 5.0, -1, 5U,
            *chartInstance->c3_fail_cntr >= 5.0))) {
        c3_e_out = true;
      } else {
        c3_e_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_c3_keypad_template = c3_IN_NO_ACTIVE_CHILD;
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 1));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 2));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 3));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 4));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 5));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 6));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 7));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 8));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_c3_keypad_template = c3_IN_SYSTEM_LOCKDOWN;
        c3_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U,
          chartInstance->c3_is_c3_keypad_template);
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 1));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 2));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 3));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 4));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 5));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 6));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 7));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 8));
        c3_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 8);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_temporalCounter_i1 = 0U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_i_debug_family_names,
          c3_i_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_state = States_SYSTEM_LOCKDOWN;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 25U,
          chartInstance->c3_state);
        if (!chartInstance->c3_dataWrittenToVector[0U]) {
          sf_read_before_write_error(chartInstance->S, 7U, 11U, 23, 5);
        }

        sf_mex_printf("%s =\\n", "state");
        c3_c_hoistedGlobal = *chartInstance->c3_state;
        c3_e_y = NULL;
        sf_mex_check_enum("States", 9, c3_sv0, c3_iv0);
        c3_c_u = (int16_T)c3_c_hoistedGlobal;
        c3_g_y = NULL;
        sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_c_u, 6, 0U, 0U, 0U, 0),
                      false);
        sf_mex_assign(&c3_m3, c3_g_y, false);
        sf_mex_assign(&c3_e_y, sf_mex_create_enum("States", c3_m3), false);
        sf_mex_destroy(&c3_m3);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c3_e_y);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_c3_keypad_template = c3_IN_NO_ACTIVE_CHILD;
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 1));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 2));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 3));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 4));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 5));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 6));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 7));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 8));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_c3_keypad_template = c3_IN_LOCKED;
        c3_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U,
          chartInstance->c3_is_c3_keypad_template);
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 1));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 2));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 3));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 4));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 5));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 6));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 7));
        c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
          (*chartInstance->c3_is_c3_keypad_template == 8));
        c3_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 2);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
        c3_enter_atomic_LOCKED(chartInstance);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, *chartInstance->c3_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);

      /* Unreachable state, for coverage only */
      *chartInstance->c3_is_c3_keypad_template = c3_IN_NO_ACTIVE_CHILD;
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 1));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 2));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 3));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 4));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 5));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 6));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 7));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 8));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
}

static void initSimStructsc3_keypad_template(SFc3_keypad_templateInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c3_enter_atomic_INIT(SFc3_keypad_templateInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  c3_States c3_hoistedGlobal;
  const mxArray *c3_y = NULL;
  int32_T c3_u;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_m6 = NULL;
  real_T c3_b_hoistedGlobal;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  const mxArray *c3_d_y = NULL;
  int32_T c3_i4;
  int32_T c3_i5;
  const mxArray *c3_e_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_state = States_INIT;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 25U, chartInstance->c3_state);
  if (!chartInstance->c3_dataWrittenToVector[0U]) {
    sf_read_before_write_error(chartInstance->S, 7U, 1U, 5, 5);
  }

  sf_mex_printf("%s =\\n", "state");
  c3_hoistedGlobal = *chartInstance->c3_state;
  c3_y = NULL;
  sf_mex_check_enum("States", 9, c3_sv0, c3_iv0);
  c3_u = (int16_T)c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_m6, c3_b_y, false);
  sf_mex_assign(&c3_y, sf_mex_create_enum("States", c3_m6), false);
  sf_mex_destroy(&c3_m6);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_y);
  *chartInstance->c3_sequence_length = 4.0;
  chartInstance->c3_dataWrittenToVector[2U] = true;
  c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 3, 36U,
    chartInstance->c3_sequence_length);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_sequence_length, 3U);
  if (!chartInstance->c3_dataWrittenToVector[2U]) {
    sf_read_before_write_error(chartInstance->S, 3U, 1U, 25, 15);
  }

  sf_mex_printf("%s =\\n", "sequence_length");
  c3_b_hoistedGlobal = *chartInstance->c3_sequence_length;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_c_y);
  *chartInstance->c3_fail_cntr = 0.0;
  chartInstance->c3_dataWrittenToVector[6U] = true;
  c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 9, 37U,
    chartInstance->c3_fail_cntr);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_fail_cntr, 9U);
  if (!chartInstance->c3_dataWrittenToVector[6U]) {
    sf_read_before_write_error(chartInstance->S, 9U, 1U, 45, 9);
  }

  sf_mex_printf("%s =\\n", "fail_cntr");
  c3_c_hoistedGlobal = *chartInstance->c3_fail_cntr;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_d_y);
  for (c3_i4 = 0; c3_i4 < 4; c3_i4++) {
    (*chartInstance->c3_seq_key)[c3_i4] = 1.0;
  }

  chartInstance->c3_dataWrittenToVector[3U] = true;
  c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 4, 38U,
    chartInstance->c3_seq_key);
  for (c3_i5 = 0; c3_i5 < 4; c3_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_seq_key)[c3_i5], 1U);
  }

  if (!chartInstance->c3_dataWrittenToVector[3U]) {
    sf_read_before_write_error(chartInstance->S, 1U, 1U, 82, 7);
  }

  sf_mex_printf("%s =\\n", "seq_key");
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", *chartInstance->c3_seq_key, 0, 0U,
    1U, 0U, 1, 4), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_e_y);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_atomic_LOCKED(SFc3_keypad_templateInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  c3_States c3_hoistedGlobal;
  const mxArray *c3_y = NULL;
  int32_T c3_u;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_m7 = NULL;
  int32_T c3_i6;
  int32_T c3_i7;
  const mxArray *c3_c_y = NULL;
  real_T c3_b_hoistedGlobal;
  const mxArray *c3_d_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_state = States_LOCKED;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 25U, chartInstance->c3_state);
  if (!chartInstance->c3_dataWrittenToVector[0U]) {
    sf_read_before_write_error(chartInstance->S, 7U, 55U, 14, 5);
  }

  sf_mex_printf("%s =\\n", "state");
  c3_hoistedGlobal = *chartInstance->c3_state;
  c3_y = NULL;
  sf_mex_check_enum("States", 9, c3_sv0, c3_iv0);
  c3_u = (int16_T)c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_m7, c3_b_y, false);
  sf_mex_assign(&c3_y, sf_mex_create_enum("States", c3_m7), false);
  sf_mex_destroy(&c3_m7);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_y);
  for (c3_i6 = 0; c3_i6 < 4; c3_i6++) {
    (*chartInstance->c3_user_seq)[c3_i6] = 0.0;
  }

  chartInstance->c3_dataWrittenToVector[5U] = true;
  c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 6, 27U,
    chartInstance->c3_user_seq);
  for (c3_i7 = 0; c3_i7 < 4; c3_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_user_seq)[c3_i7], 8U);
  }

  if (!chartInstance->c3_dataWrittenToVector[5U]) {
    sf_read_before_write_error(chartInstance->S, 8U, 55U, 36, 8);
  }

  sf_mex_printf("%s =\\n", "user_seq");
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", *chartInstance->c3_user_seq, 0, 0U,
    1U, 0U, 1, 4), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_c_y);
  *chartInstance->c3_i = 0.0;
  chartInstance->c3_dataWrittenToVector[1U] = true;
  c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 28U, chartInstance->c3_i);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_i, 0U);
  if (!chartInstance->c3_dataWrittenToVector[1U]) {
    sf_read_before_write_error(chartInstance->S, 0U, 55U, 74, 1);
  }

  sf_mex_printf("%s =\\n", "i");
  c3_b_hoistedGlobal = *chartInstance->c3_i;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_d_y);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_CHECK(SFc3_keypad_templateInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  boolean_T c3_p;
  boolean_T c3_b_p;
  int32_T c3_k;
  real_T c3_b_k;
  real_T c3_x1;
  real_T c3_x2;
  boolean_T c3_c_p;
  uint32_T c3_c_debug_family_var_map[2];
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  c3_States c3_hoistedGlobal;
  c3_States c3_b_hoistedGlobal;
  const mxArray *c3_y = NULL;
  const mxArray *c3_b_y = NULL;
  int32_T c3_u;
  int32_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  const mxArray *c3_d_y = NULL;
  const mxArray *c3_m8 = NULL;
  const mxArray *c3_m9 = NULL;
  real_T c3_c_hoistedGlobal;
  const mxArray *c3_e_y = NULL;
  boolean_T exitg1;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U, *chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  if (CV_EML_IF(11, 0, 0, CV_RELATIONAL_EVAL(5U, 11U, 0, (real_T)
        *chartInstance->c3_enter, 1.0, -1, 0U, (int32_T)*chartInstance->c3_enter)))
  {
    c3_out = true;
  } else {
    c3_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, *chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_p_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[5U]) {
      sf_read_before_write_error(chartInstance->S, 8U, 15U, 9, 8);
    }

    if (!chartInstance->c3_dataWrittenToVector[3U]) {
      sf_read_before_write_error(chartInstance->S, 1U, 15U, 19, 7);
    }

    c3_p = false;
    c3_b_p = true;
    c3_k = 0;
    exitg1 = false;
    while ((!exitg1) && (c3_k < 4)) {
      c3_b_k = 1.0 + (real_T)c3_k;
      c3_x1 = (*chartInstance->c3_user_seq)[(int32_T)c3_b_k - 1];
      c3_x2 = (*chartInstance->c3_seq_key)[(int32_T)c3_b_k - 1];
      c3_c_p = (c3_x1 == c3_x2);
      if (!c3_c_p) {
        c3_b_p = false;
        exitg1 = true;
      } else {
        c3_k++;
      }
    }

    if (!c3_b_p) {
    } else {
      c3_p = true;
    }

    if (CV_EML_IF(3, 0, 0, c3_p)) {
      c3_b_out = true;
    } else {
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_c3_keypad_template = c3_IN_NO_ACTIVE_CHILD;
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 1));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 2));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 3));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 4));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 5));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 6));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 7));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 8));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_c3_keypad_template = c3_IN_UNLOCK;
      c3_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U,
        chartInstance->c3_is_c3_keypad_template);
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 1));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 2));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 3));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 4));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 5));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 6));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 7));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 8));
      c3_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 6);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_g_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_state = States_UNLOCK;
      chartInstance->c3_dataWrittenToVector[0U] = true;
      c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 25U,
        chartInstance->c3_state);
      if (!chartInstance->c3_dataWrittenToVector[0U]) {
        sf_read_before_write_error(chartInstance->S, 7U, 9U, 14, 5);
      }

      sf_mex_printf("%s =\\n", "state");
      c3_b_hoistedGlobal = *chartInstance->c3_state;
      c3_b_y = NULL;
      sf_mex_check_enum("States", 9, c3_sv0, c3_iv0);
      c3_b_u = (int16_T)c3_b_hoistedGlobal;
      c3_d_y = NULL;
      sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_b_u, 6, 0U, 0U, 0U, 0),
                    false);
      sf_mex_assign(&c3_m9, c3_d_y, false);
      sf_mex_assign(&c3_b_y, sf_mex_create_enum("States", c3_m9), false);
      sf_mex_destroy(&c3_m9);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_b_y);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_c3_keypad_template = c3_IN_NO_ACTIVE_CHILD;
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 1));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 2));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 3));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 4));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 5));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 6));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 7));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 8));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_c3_keypad_template = c3_IN_WRONG_CODE;
      c3_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U,
        chartInstance->c3_is_c3_keypad_template);
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 8U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 1));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 5U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 2));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 3, 1U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 3));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 4, 55U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 4));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 5, 7U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 5));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 6, 11U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 6));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 7, 9U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 7));
      c3_b_sdiStreamingWrapperFcn(chartInstance, 4, 8, 10U, (int32_T)
        (*chartInstance->c3_is_c3_keypad_template == 8));
      c3_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 7);
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_state = States_WRONG_CODE;
      chartInstance->c3_dataWrittenToVector[0U] = true;
      c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 25U,
        chartInstance->c3_state);
      if (!chartInstance->c3_dataWrittenToVector[0U]) {
        sf_read_before_write_error(chartInstance->S, 7U, 10U, 18, 5);
      }

      sf_mex_printf("%s =\\n", "state");
      c3_hoistedGlobal = *chartInstance->c3_state;
      c3_y = NULL;
      sf_mex_check_enum("States", 9, c3_sv0, c3_iv0);
      c3_u = (int16_T)c3_hoistedGlobal;
      c3_c_y = NULL;
      sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
      sf_mex_assign(&c3_m8, c3_c_y, false);
      sf_mex_assign(&c3_y, sf_mex_create_enum("States", c3_m8), false);
      sf_mex_destroy(&c3_m8);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_y);
      if (!chartInstance->c3_dataWrittenToVector[6U]) {
        sf_read_before_write_error(chartInstance->S, 9U, 10U, 56, 9);
      }

      (*chartInstance->c3_fail_cntr)++;
      chartInstance->c3_dataWrittenToVector[6U] = true;
      c3_d_sdiStreamingWrapperFcn(chartInstance, 0, 9, 37U,
        chartInstance->c3_fail_cntr);
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_fail_cntr, 9U);
      if (!chartInstance->c3_dataWrittenToVector[6U]) {
        sf_read_before_write_error(chartInstance->S, 9U, 10U, 44, 9);
      }

      sf_mex_printf("%s =\\n", "fail_cntr");
      c3_c_hoistedGlobal = *chartInstance->c3_fail_cntr;
      c3_e_y = NULL;
      sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_c_hoistedGlobal, 0, 0U, 0U,
        0U, 0), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_e_y);
      _SFD_SYMBOL_SCOPE_POP();
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)(c3_machineNumber);
  (void)(c3_chartNumber);
  (void)(c3_instanceNumber);
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_keypad_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_keypad_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_nargin, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargin), &c3_thisId);
  sf_mex_destroy(&c3_nargin);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargin;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_keypad_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_keypad_templateInstanceStruct *)chartInstanceVoid;
  c3_nargin = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargin), &c3_thisId);
  sf_mex_destroy(&c3_nargin);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_keypad_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_keypad_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_keypad_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_keypad_templateInstanceStruct *)chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_keypad_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  const char * c3_data[4] = {
    "789c6360f4f465646060e003622620ae606300035e08c52000a599185001ba3c230e1a06581958c066f0a2c9cf81d2c9f97925a91525104e4e665eaa5f696e52"
    "6a11909397989b0a3726253f37332f31af24a4b22095a128b5383fa72c35052c939699931a92999bea938fc4f1c8047272dd90a4e01c901488ed9c919a9c1d5c",
    "9acb5094518c706e0e328701297c1270f89f8540f8a003f4f0415747c83e3602f6118a0f4e060e24de077b4afd07339f0d8dcf00570791092e492c492d1eb8f0"
    "9c40a67d30f30d08d807938ff68b75b6d20f2d4e2d2ad6f7cc4e2c2a2dd677492dce2ec92fd0cf2bcd4d2dca4c8ecfc94fced68784875e2efde2dbe178c8ff6b",
    "8ef44d5ff44ecf03675f050ef3884d5f6238ec1340932f0dab888a2836360c0b334fae2c74f72e0af24ff57346b82380803d84dcc180834f6bf301afc254b1",
    "" };

  c3_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(c3_data, 1680U, &c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_keypad_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_keypad_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i8;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i8, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i8;
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
  SFc3_keypad_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_keypad_templateInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  c3_States c3_u;
  const mxArray *c3_y = NULL;
  int32_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_m10 = NULL;
  SFc3_keypad_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_keypad_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(c3_States *)c3_inData;
  c3_y = NULL;
  sf_mex_check_enum("States", 9, c3_sv0, c3_iv0);
  c3_b_u = (int16_T)c3_u;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_m10, c3_b_y, false);
  sf_mex_assign(&c3_y, sf_mex_create_enum("States", c3_m10), false);
  sf_mex_destroy(&c3_m10);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static c3_States c3_e_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_b_state, const char_T *c3_identifier)
{
  c3_States c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_state), &c3_thisId);
  sf_mex_destroy(&c3_b_state);
  return c3_y;
}

static c3_States c3_f_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  c3_States c3_y;
  (void)chartInstance;
  sf_mex_check_enum("States", 9, c3_sv0, c3_iv0);
  sf_mex_check_builtin(c3_parentId, c3_u, "States", 0, 0U, NULL);
  c3_y = (c3_States)sf_mex_get_enum_element(c3_u, 0);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_state;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  c3_States c3_y;
  SFc3_keypad_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_keypad_templateInstanceStruct *)chartInstanceVoid;
  c3_b_state = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_state), &c3_thisId);
  sf_mex_destroy(&c3_b_state);
  *(c3_States *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i9;
  const mxArray *c3_y = NULL;
  real_T c3_u[4];
  SFc3_keypad_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_keypad_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i9 = 0; c3_i9 < 4; c3_i9++) {
    c3_u[c3_i9] = (*(real_T (*)[4])c3_inData)[c3_i9];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_g_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_b_seq_key, const char_T *c3_identifier,
  real_T c3_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_seq_key), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_b_seq_key);
}

static void c3_h_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4])
{
  real_T c3_dv2[4];
  int32_T c3_i10;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv2, 1, 0, 0U, 1, 0U, 1, 4);
  for (c3_i10 = 0; c3_i10 < 4; c3_i10++) {
    c3_y[c3_i10] = c3_dv2[c3_i10];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_seq_key;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[4];
  int32_T c3_i11;
  SFc3_keypad_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_keypad_templateInstanceStruct *)chartInstanceVoid;
  c3_b_seq_key = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_seq_key), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_b_seq_key);
  for (c3_i11 = 0; c3_i11 < 4; c3_i11++) {
    (*(real_T (*)[4])c3_outData)[c3_i11] = c3_y[c3_i11];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_i_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_keypad_template, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_keypad_template), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_keypad_template);
  return c3_y;
}

static uint8_T c3_j_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static uint16_T c3_k_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_b_temporalCounter_i1, const char_T
  *c3_identifier)
{
  uint16_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_temporalCounter_i1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_temporalCounter_i1);
  return c3_y;
}

static uint16_T c3_l_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint16_T c3_y;
  uint16_T c3_u1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u1, 1, 5, 0U, 0, 0U, 0);
  c3_y = c3_u1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_m_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[7])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_n_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[7])
{
  boolean_T c3_bv1[7];
  int32_T c3_i12;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv1, 1, 11, 0U, 1, 0U, 1, 7);
  for (c3_i12 = 0; c3_i12 < 7; c3_i12++) {
    c3_y[c3_i12] = c3_bv1[c3_i12];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_o_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  sf_mex_assign(&c3_y, c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_p_emlrt_marshallIn(SFc3_keypad_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc3_keypad_templateInstanceStruct *chartInstance, int32_T c3_ssid)
{
  (void)chartInstance;
  (void)c3_ssid;
  return NULL;
}

static void c3_init_sf_message_store_memory(SFc3_keypad_templateInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_sdiStreamingWrapperFcn(SFc3_keypad_templateInstanceStruct
  *chartInstance, int32_T c3_modeFlag, int32_T c3_ssidIdx, uint32_T c3_ssid,
  void *c3_streamedData)
{
  if (chartInstance->c3_sdiLoggedStatesBuffer[c3_ssidIdx] & (uint8_T)c3_modeFlag)
  {
    sdi_stream_child_activity_signal(&chartInstance->c3_sdiBlockInfo, c3_ssid,
      c3_streamedData);
  }
}

static void c3_b_sdiStreamingWrapperFcn(SFc3_keypad_templateInstanceStruct
  *chartInstance, int32_T c3_modeFlag, int32_T c3_ssidIdx, uint32_T c3_ssid,
  int32_T c3_streamedData)
{
  if (chartInstance->c3_sdiLoggedStatesBuffer[c3_ssidIdx] & (uint8_T)c3_modeFlag)
  {
    sdi_update_self_activity_signal(&chartInstance->c3_sdiBlockInfo, c3_ssid,
      c3_streamedData);
  }
}

static void c3_c_sdiStreamingWrapperFcn(SFc3_keypad_templateInstanceStruct
  *chartInstance, int32_T c3_modeFlag, int32_T c3_ssidIdx, uint32_T c3_ssid,
  int32_T c3_streamedData)
{
  if (chartInstance->c3_sdiLoggedStatesBuffer[c3_ssidIdx] & (uint8_T)c3_modeFlag)
  {
    sdi_update_leaf_activity_signal(&chartInstance->c3_sdiBlockInfo, c3_ssid,
      c3_streamedData);
  }
}

static void c3_d_sdiStreamingWrapperFcn(SFc3_keypad_templateInstanceStruct
  *chartInstance, int32_T c3_modeFlag, int32_T c3_ssidIdx, uint32_T c3_ssid,
  void *c3_streamedData)
{
  (void)c3_modeFlag;
  if (chartInstance->c3_sdiLoggedDataBuffer[c3_ssidIdx]) {
    sdi_stream_data_signal(&chartInstance->c3_sdiBlockInfo, c3_ssid,
      c3_streamedData);
  }
}

static void init_test_point_addr_map(SFc3_keypad_templateInstanceStruct
  *chartInstance)
{
  chartInstance->c3_testPointAddrMap[0] = chartInstance->c3_state;
}

static void **get_test_point_address_map(SFc3_keypad_templateInstanceStruct
  *chartInstance)
{
  return &chartInstance->c3_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc3_keypad_templateInstanceStruct *chartInstance)
{
  return &chartInstance->c3_testPointMappingInfo;
}

static void **get_dataset_logging_obj_vector(SFc3_keypad_templateInstanceStruct *
  chartInstance)
{
  return &chartInstance->c3_dataSetLogObjVector[0];
}

static void init_dsm_address_info(SFc3_keypad_templateInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_keypad_templateInstanceStruct
  *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c3_is_active_c3_keypad_template = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_is_c3_keypad_template = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_user_input = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_state = (c3_States *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_i = (real_T *)ssGetDWork_wrapper(chartInstance->S, 3);
  chartInstance->c3_sequence_length = (real_T *)ssGetDWork_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_seq_key = (real_T (*)[4])ssGetDWork_wrapper(chartInstance->S,
    5);
  chartInstance->c3_sequece_length = (real_T *)ssGetDWork_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_user_seq = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_lock = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_enter = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_fail_cntr = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_temporalCounter_i1 = (uint16_T *)ssGetDWork_wrapper
    (chartInstance->S, 7);
  chartInstance->c3_user_input_prev = (real_T *)ssGetDWork_wrapper
    (chartInstance->S, 8);
  chartInstance->c3_user_input_start = (real_T *)ssGetDWork_wrapper
    (chartInstance->S, 9);
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
static uint32_T* sf_get_sfun_dwork_checksum(void);
void sf_c3_keypad_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2596896559U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1059141522U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2072620365U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3057094892U);
}

mxArray* sf_c3_keypad_template_get_post_codegen_info(void);
mxArray *sf_c3_keypad_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("frIFkD9Y5gC7Y97uTIafkH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(14));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_keypad_template_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_keypad_template_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_keypad_template_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("ext_mode");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_keypad_template_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_keypad_template_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c3_keypad_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[37],T\"fail_cntr\",},{M[1],M[25],T\"state\",},{M[1],M[27],T\"user_seq\",},{M[3],M[28],T\"i\",},{M[3],M[38],T\"seq_key\",},{M[3],M[44],T\"sequece_length\",},{M[3],M[36],T\"sequence_length\",},{M[8],M[0],T\"is_active_c3_keypad_template\",},{M[9],M[0],T\"is_c3_keypad_template\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[11],M[1]}}}}",
    "100 S1x2'type','srcId','name','auxInfo'{{M[12],M[22],T\"user_input_start\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 12, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_keypad_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc3_keypad_templateInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_keypad_templateInstanceStruct *chartInstance =
      (SFc3_keypad_templateInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _keypad_templateMachineNumber_,
           3,
           8,
           15,
           0,
           10,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_keypad_templateMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_keypad_templateMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _keypad_templateMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"i");
          _SFD_SET_DATA_PROPS(1,0,0,0,"seq_key");
          _SFD_SET_DATA_PROPS(2,0,0,0,"sequece_length");
          _SFD_SET_DATA_PROPS(3,0,0,0,"sequence_length");
          _SFD_SET_DATA_PROPS(4,1,1,0,"user_input");
          _SFD_SET_DATA_PROPS(5,1,1,0,"lock");
          _SFD_SET_DATA_PROPS(6,1,1,0,"enter");
          _SFD_SET_DATA_PROPS(7,2,0,1,"state");
          _SFD_SET_DATA_PROPS(8,2,0,1,"user_seq");
          _SFD_SET_DATA_PROPS(9,2,0,1,"fail_cntr");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_CH_SUBSTATE_COUNT(8);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_CH_SUBSTATE_INDEX(4,4);
          _SFD_CH_SUBSTATE_INDEX(5,5);
          _SFD_CH_SUBSTATE_INDEX(6,6);
          _SFD_CH_SUBSTATE_INDEX(7,7);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
        }

        _SFD_CV_INIT_CHART(8,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,10,1,10);
        _SFD_CV_INIT_EML_RELATIONAL(5,0,0,1,10,-1,0);
        _SFD_CV_INIT_EML(4,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(6,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(2,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,21,1,21);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,1,21,-1,5);
        _SFD_CV_INIT_EML(11,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,11,1,11);
        _SFD_CV_INIT_EML_RELATIONAL(11,0,0,1,11,-1,0);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,27,1,27);
        _SFD_CV_INIT_EML(8,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,13,1,13);
        _SFD_CV_INIT_EML_RELATIONAL(8,0,0,1,13,-1,5);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4U;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _keypad_templateMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_keypad_templateInstanceStruct *chartInstance =
      (SFc3_keypad_templateInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c3_user_input);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c3_state);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_i);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c3_sequence_length);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c3_seq_key);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c3_sequece_length);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c3_user_seq);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c3_lock);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c3_enter);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c3_fail_cntr);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sBjjaFjNGEDCiJIpHWopAKH";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_keypad_template_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 3, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c3_keypad_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc3_keypad_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc3_keypad_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_keypad_template((SFc3_keypad_templateInstanceStruct*)
    chartInstanceVar);
  initialize_c3_keypad_template((SFc3_keypad_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_keypad_template(void *chartInstanceVar)
{
  enable_c3_keypad_template((SFc3_keypad_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_keypad_template(void *chartInstanceVar)
{
  disable_c3_keypad_template((SFc3_keypad_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_keypad_template(void *chartInstanceVar)
{
  sf_gateway_c3_keypad_template((SFc3_keypad_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c3_keypad_template(void *chartInstanceVar)
{
  ext_mode_exec_c3_keypad_template((SFc3_keypad_templateInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_keypad_template(SimStruct* S)
{
  return get_sim_state_c3_keypad_template((SFc3_keypad_templateInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_keypad_template(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c3_keypad_template((SFc3_keypad_templateInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_keypad_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_keypad_templateInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_keypad_template_optimization_info();
    }

    finalize_c3_keypad_template((SFc3_keypad_templateInstanceStruct*)
      chartInstanceVar);
    if (!sim_mode_is_rtw_gen(S)) {
      ssSetModelMappingInfoPtr(S, NULL);
    }

    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_keypad_template((SFc3_keypad_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_keypad_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_keypad_template((SFc3_keypad_templateInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

mxArray *sf_c3_keypad_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S1x2'varName','path'{{T\"is_active_c3_keypad_template\",T\"is_active_c3_keypad_template\"},{T\"is_c3_keypad_template\",T\"is_c3_keypad_template\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"int32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[4],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint16\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 10, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 3307503662U, 2445205213U, 1904303599U,
    3374954133U };

  return checksum;
}

static void mdlSetWorkWidths_c3_keypad_template(SimStruct *S)
{
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_keypad_template_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 3);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3594439030U));
  ssSetChecksum1(S,(4238007102U));
  ssSetChecksum2(S,(2828552711U));
  ssSetChecksum3(S,(3916866651U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_keypad_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_keypad_template(SimStruct *S)
{
  SFc3_keypad_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_keypad_templateInstanceStruct *)utMalloc(sizeof
    (SFc3_keypad_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_keypad_templateInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_keypad_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_keypad_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_keypad_template;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_keypad_template;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_keypad_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_keypad_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_keypad_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_keypad_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_keypad_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_keypad_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_keypad_template;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c3_keypad_template;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0, NULL, NULL);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
    init_test_point_mapping_info(S);
  }

  chart_debug_initialization(S,1);
  mdl_start_c3_keypad_template(chartInstance);
}

void c3_keypad_template_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_keypad_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_keypad_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_keypad_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_keypad_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  { "enum States", "States", 0, 0, sizeof(enum States), SS_ENUM_TYPE, 0, 0 } };

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  { &sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0 }
};

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_SCALAR, 0, 2 } };

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  { 0, 0, "StateflowChart/state", "state", 0, 0, 0, 0, 0 } };

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0 } };

static const uint_T dimensionArray[] = {
  1, 1 };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    1,                                 /* Num Block IO signals */
    NULL,                              /* Root Inputs Array    */
    0,                                 /* Num root inputs      */
    NULL,                              /* Root Outputs Array */
    0                                  /* Num root outputs   */
  },

  /* parameter tuning */
  {
    NULL,                              /* Block parameters Array    */
    0,                                 /* Num block parameters      */
    NULL,                              /* Variable parameters Array */
    0                                  /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                              /* Block States array        */
    0                                  /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                       /* Data Type Map            */
    dimensionMap,                      /* Data Dimension Map       */
    fixedPointMap,                     /* Fixed Point Map          */
    NULL,                              /* Structure Element map    */
    sampleTimeMap,                     /* Sample Times Map         */
    dimensionArray                     /* Dimension Array          */
  },

  /* Target type */
  "float",

  {
    3594439030U,
    4238007102U,
    2828552711U,
    3916866651U
  }
};

static void init_test_point_mapping_info(SimStruct *S)
{
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;
  SFc3_keypad_templateInstanceStruct *chartInstance =
    (SFc3_keypad_templateInstanceStruct *)sf_get_chart_instance_ptr(S);
  init_test_point_addr_map(chartInstance);
  testPointMappingInfo = get_test_point_mapping_info(chartInstance);
  testPointAddrMap = get_test_point_address_map(chartInstance);
  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetLoggingStaticMap(*testPointMappingInfo, NULL);
  rtwCAPI_SetInstanceLoggingInfo(*testPointMappingInfo, NULL);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);
  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
}

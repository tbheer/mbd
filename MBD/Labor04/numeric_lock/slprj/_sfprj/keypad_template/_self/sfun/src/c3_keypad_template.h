#ifndef __c3_keypad_template_h__
#define __c3_keypad_template_h__
#include "sf_runtime/sfc_sdi.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
#ifndef enum_States
#define enum_States

enum States
{
  States_INIT = 0,                     /* Default value */
  States_IDLE,
  States_KEY_PRESSED,
  States_READING,
  States_CHECK,
  States_UNLOCK,
  States_WRONG_CODE,
  States_SYSTEM_LOCKDOWN,
  States_LOCKED
};

#endif                                 /*enum_States*/

#ifndef typedef_c3_States
#define typedef_c3_States

typedef enum States c3_States;

#endif                                 /*typedef_c3_States*/

#ifndef typedef_SFc3_keypad_templateInstanceStruct
#define typedef_SFc3_keypad_templateInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c3_dataWrittenToVector[7];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_dataSetLogObjVector[1];
  uint8_T c3_sdiLoggedStatesBuffer[9];
  uint8_T c3_sdiLoggedDataBuffer[10];
  sdiBlockID_t c3_sdiBlockInfo;
  SignalExportStruct c3_SignalExportProp;
  SignalExportStruct c3_b_SignalExportProp;
  SignalExportStruct c3_c_SignalExportProp;
  SignalExportStruct c3_d_SignalExportProp;
  SignalExportStruct c3_e_SignalExportProp;
  SignalExportStruct c3_f_SignalExportProp;
  SignalExportStruct c3_g_SignalExportProp;
  SignalExportStruct c3_h_SignalExportProp;
  SignalExportStruct c3_i_SignalExportProp;
  SignalExportStruct c3_j_SignalExportProp;
  SignalExportStruct c3_k_SignalExportProp;
  SignalExportStruct c3_l_SignalExportProp;
  SignalExportStruct c3_m_SignalExportProp;
  SignalExportStruct c3_n_SignalExportProp;
  SignalExportStruct c3_o_SignalExportProp;
  rtwCAPI_ModelMappingInfo c3_testPointMappingInfo;
  void *c3_testPointAddrMap[1];
  void *c3_fEmlrtCtx;
  int32_T *c3_sfEvent;
  uint8_T *c3_is_active_c3_keypad_template;
  uint8_T *c3_is_c3_keypad_template;
  real_T *c3_user_input;
  c3_States *c3_state;
  real_T *c3_i;
  real_T *c3_sequence_length;
  real_T (*c3_seq_key)[4];
  real_T *c3_sequece_length;
  real_T (*c3_user_seq)[4];
  boolean_T *c3_lock;
  boolean_T *c3_enter;
  real_T *c3_fail_cntr;
  uint16_T *c3_temporalCounter_i1;
  real_T *c3_user_input_prev;
  real_T *c3_user_input_start;
} SFc3_keypad_templateInstanceStruct;

#endif                                 /*typedef_SFc3_keypad_templateInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_keypad_template_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_keypad_template_get_check_sum(mxArray *plhs[]);
extern void c3_keypad_template_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: numeric_sequence_lock.h
 *
 * Code generated for Simulink model 'numeric_sequence_lock'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Nov 27 15:33:50 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_numeric_sequence_lock_h_
#define RTW_HEADER_numeric_sequence_lock_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef numeric_sequence_lock_COMMON_INCLUDES_
# define numeric_sequence_lock_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* numeric_sequence_lock_COMMON_INCLUDES_ */

#include "numeric_sequence_lock_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Subtract;                     /* '<S3>/Subtract' */
  real_T user_seq[4];                  /* '<S1>/Chart' */
  States state;                        /* '<S1>/Chart' */
  boolean_T Equal;                     /* '<S3>/Equal' */
  boolean_T Equal1;                    /* '<S3>/Equal1' */
} B_numeric_sequence_lock_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T i;                            /* '<S1>/Chart' */
  real_T sequence_length;              /* '<S1>/Chart' */
  real_T fail_cntr;                    /* '<S1>/Chart' */
  real_T seq_key[4];                   /* '<S1>/Chart' */
  real_T sequece_length;               /* '<S1>/Chart' */
  real_T user_input_start;             /* '<S1>/Chart' */
  uint8_T is_active_c3_numeric_sequence_l;/* '<S1>/Chart' */
  uint8_T is_c3_numeric_sequence_lock; /* '<S1>/Chart' */
} DW_numeric_sequence_lock_T;

/* Parameters (default storage) */
struct P_numeric_sequence_lock_T_ {
  boolean_T IntervalTest_lowlimit;     /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S4>/Lower Limit'
                                        */
  boolean_T IntervalTest_uplimit;      /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S4>/Upper Limit'
                                        */
  real_T Constant_Value;               /* Expression: 48
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T _Value;                       /* Expression: 42
                                        * Referenced by: '<S3>/+'
                                        */
  real_T _Value_e;                     /* Expression: 35
                                        * Referenced by: '<S3>/#'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_numeric_sequence_lock_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_numeric_sequence_lock_T numeric_sequence_lock_P;

/* Block signals (default storage) */
extern B_numeric_sequence_lock_T numeric_sequence_lock_B;

/* Block states (default storage) */
extern DW_numeric_sequence_lock_T numeric_sequence_lock_DW;

/* Model entry point functions */
extern void numeric_sequence_lock_initialize(void);
extern void numeric_sequence_lock_step(void);
extern void numeric_sequence_lock_terminate(void);

/* Real-time Model object */
extern RT_MODEL_numeric_sequence_loc_T *const numeric_sequence_lock_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<S4>/FixPt Data Type Duplicate' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'numeric_sequence_lock'
 * '<S1>'   : 'numeric_sequence_lock/numeric sequence lock'
 * '<S2>'   : 'numeric_sequence_lock/numeric sequence lock/Chart'
 * '<S3>'   : 'numeric_sequence_lock/numeric sequence lock/check input'
 * '<S4>'   : 'numeric_sequence_lock/numeric sequence lock/check input/Interval Test  '
 */
#endif                                 /* RTW_HEADER_numeric_sequence_lock_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * framework.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "framework".
 *
 * Model version              : 1.7
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Fri Feb  1 19:59:15 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_framework_h_
#define RTW_HEADER_framework_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef framework_COMMON_INCLUDES_
# define framework_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "MW_I2C.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* framework_COMMON_INCLUDES_ */

#include "framework_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
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

/* Block states (default storage) for system '<S1>/I2C Write4' */
typedef struct {
  codertarget_arduinobase_int_e_T obj; /* '<S1>/I2C Write4' */
  boolean_T objisempty;                /* '<S1>/I2C Write4' */
} DW_I2CWrite4_framework_T;

/* Block signals (default storage) */
typedef struct {
  real_T Add;                          /* '<S3>/Add' */
  real_T gyroXrate;                    /* '<S2>/MATLAB Function1' */
  real_T roll;                         /* '<S2>/MATLAB Function' */
} B_framework_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_f_T obj; /* '<S2>/I2C Read' */
  codertarget_arduinobase_in_fe_T obj_h;/* '<S4>/PWM' */
  codertarget_arduinobase_in_fe_T obj_n;/* '<S4>/PWM1' */
  codertarget_arduinobase_block_T obj_j;/* '<S14>/Digital Output' */
  codertarget_arduinobase_block_T obj_d;/* '<S13>/Digital Output' */
  codertarget_arduinobase_block_T obj_na;/* '<S12>/Digital Output' */
  codertarget_arduinobase_block_T obj_l;/* '<S11>/Digital Output' */
  codertarget_arduinobase_block_T obj_g;/* '<S6>/Digital Output' */
  codertarget_arduinobase_block_T obj_lq;/* '<S5>/Digital Output' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T Delay1_DSTATE;                /* '<Root>/Delay1' */
  real_T Delay2_DSTATE;                /* '<Root>/Delay2' */
  real_T Delay3_DSTATE;                /* '<S3>/Delay3' */
  real_T UD_DSTATE;                    /* '<S9>/UD' */
  real_T P[4];                         /* '<S3>/MATLAB Function' */
  real_T x[2];                         /* '<S3>/MATLAB Function' */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  boolean_T objisempty;                /* '<S14>/Digital Output' */
  boolean_T objisempty_i;              /* '<S13>/Digital Output' */
  boolean_T objisempty_o;              /* '<S12>/Digital Output' */
  boolean_T objisempty_d;              /* '<S11>/Digital Output' */
  boolean_T objisempty_m;              /* '<S4>/PWM' */
  boolean_T objisempty_e;              /* '<S4>/PWM1' */
  boolean_T objisempty_dv;             /* '<S2>/I2C Read' */
  boolean_T objisempty_f;              /* '<S6>/Digital Output' */
  boolean_T objisempty_e1;             /* '<S5>/Digital Output' */
  DW_I2CWrite4_framework_T I2CWrite;   /* '<S1>/I2C Write4' */
  DW_I2CWrite4_framework_T I2CWrite1;  /* '<S1>/I2C Write4' */
  DW_I2CWrite4_framework_T I2CWrite2;  /* '<S1>/I2C Write4' */
  DW_I2CWrite4_framework_T I2CWrite3;  /* '<S1>/I2C Write4' */
  DW_I2CWrite4_framework_T I2CWrite4;  /* '<S1>/I2C Write4' */
} DW_framework_T;

/* Parameters (default storage) */
struct P_framework_T_ {
  real_T Difference_ICPrevInput;       /* Mask Parameter: Difference_ICPrevInput
                                        * Referenced by: '<S9>/UD'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 7
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant7'
                                        */
  real_T I2CRead_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S2>/I2C Read'
                                        */
  real_T newAngle_Y0;                  /* Computed Parameter: newAngle_Y0
                                        * Referenced by: '<S2>/newAngle'
                                        */
  real_T Gyro_Car_Y0;                  /* Computed Parameter: Gyro_Car_Y0
                                        * Referenced by: '<S2>/Gyro_Car'
                                        */
  real_T PWM_Y0;                       /* Computed Parameter: PWM_Y0
                                        * Referenced by: '<S3>/PWM'
                                        */
  real_T Constant_Value;               /* Expression: 0.01
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Product_Gain;                 /* Expression: 15
                                        * Referenced by: '<S3>/Product'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay3'
                                        */
  real_T Differentiater_Gain;          /* Expression: 3.5
                                        * Referenced by: '<S3>/Differentiater'
                                        */
  real_T Integrater_Gain;              /* Expression: 0.35
                                        * Referenced by: '<S3>/Integrater'
                                        */
  real_T Constant3_Value_b;            /* Expression: 0
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Constant4_Value_n;            /* Expression: 1
                                        * Referenced by: '<S4>/Constant4'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay2'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  uint32_T Delay3_DelayLength;         /* Computed Parameter: Delay3_DelayLength
                                        * Referenced by: '<S3>/Delay3'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<Root>/Delay1'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<Root>/Delay2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_framework_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_framework_T framework_P;

/* Block signals (default storage) */
extern B_framework_T framework_B;

/* Block states (default storage) */
extern DW_framework_T framework_DW;

/* Model entry point functions */
extern void framework_initialize(void);
extern void framework_step(void);
extern void framework_terminate(void);

/* Real-time Model object */
extern RT_MODEL_framework_T *const framework_M;

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
 * '<Root>' : 'framework'
 * '<S1>'   : 'framework/One_time_initialization'
 * '<S2>'   : 'framework/acc_gyro_read'
 * '<S3>'   : 'framework/controller'
 * '<S4>'   : 'framework/motor_controller'
 * '<S5>'   : 'framework/One_time_initialization/SPD_PUL_L'
 * '<S6>'   : 'framework/One_time_initialization/SPD_PUL_R'
 * '<S7>'   : 'framework/acc_gyro_read/MATLAB Function'
 * '<S8>'   : 'framework/acc_gyro_read/MATLAB Function1'
 * '<S9>'   : 'framework/controller/Difference'
 * '<S10>'  : 'framework/controller/MATLAB Function'
 * '<S11>'  : 'framework/motor_controller/Digital Output'
 * '<S12>'  : 'framework/motor_controller/Digital Output1'
 * '<S13>'  : 'framework/motor_controller/Digital Output2'
 * '<S14>'  : 'framework/motor_controller/Digital Output3'
 */
#endif                                 /* RTW_HEADER_framework_h_ */

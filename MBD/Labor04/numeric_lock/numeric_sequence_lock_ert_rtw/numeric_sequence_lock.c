/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: numeric_sequence_lock.c
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

#include "numeric_sequence_lock.h"
#include "numeric_sequence_lock_private.h"
#include "numeric_sequence_lock_dt.h"

/* Named constants for Chart: '<S1>/Chart' */
#define numeric_sequ_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define numeric_sequ_IN_SYSTEM_LOCKDOWN ((uint8_T)6U)
#define numeric_sequence__IN_WRONG_CODE ((uint8_T)8U)
#define numeric_sequence_loc_IN_READING ((uint8_T)5U)
#define numeric_sequence_lock_IN_CHECK ((uint8_T)1U)
#define numeric_sequence_lock_IN_IDLE  ((uint8_T)2U)
#define numeric_sequence_lock_IN_INIT  ((uint8_T)3U)
#define numeric_sequence_lock_IN_LOCKED ((uint8_T)4U)
#define numeric_sequence_lock_IN_UNLOCK ((uint8_T)7U)

/* Block signals (default storage) */
B_numeric_sequence_lock_T numeric_sequence_lock_B;

/* Block states (default storage) */
DW_numeric_sequence_lock_T numeric_sequence_lock_DW;

/* Real-time model */
RT_MODEL_numeric_sequence_loc_T numeric_sequence_lock_M_;
RT_MODEL_numeric_sequence_loc_T *const numeric_sequence_lock_M =
  &numeric_sequence_lock_M_;

/* Model step function */
void numeric_sequence_lock_step(void)
{
  boolean_T p;
  boolean_T b_p;
  int16_T k;
  real_T user_input_prev;
  boolean_T exitg1;

  /* Sum: '<S3>/Subtract' incorporates:
   *  Constant: '<S3>/Constant'
   *  Product: '<S3>/Product'
   */
  numeric_sequence_lock_B.Subtract = 0.0 -
    numeric_sequence_lock_P.Constant_Value;

  /* RelationalOperator: '<S3>/Equal' incorporates:
   *  Constant: '<S3>/+'
   */
  numeric_sequence_lock_B.Equal = (numeric_sequence_lock_P._Value == 0.0);

  /* RelationalOperator: '<S3>/Equal1' incorporates:
   *  Constant: '<S3>/#'
   */
  numeric_sequence_lock_B.Equal1 = (0.0 == numeric_sequence_lock_P._Value_e);

  /* Chart: '<S1>/Chart' */
  user_input_prev = numeric_sequence_lock_DW.user_input_start;
  numeric_sequence_lock_DW.user_input_start = numeric_sequence_lock_B.Subtract;
  if (numeric_sequence_lock_DW.is_active_c3_numeric_sequence_l == 0U) {
    numeric_sequence_lock_DW.is_active_c3_numeric_sequence_l = 1U;
    numeric_sequence_lock_DW.is_c3_numeric_sequence_lock =
      numeric_sequence_lock_IN_INIT;
    numeric_sequence_lock_B.state = INIT;
    numeric_sequence_lock_DW.sequence_length = 4.0;
    numeric_sequence_lock_DW.fail_cntr = 0.0;
    numeric_sequence_lock_DW.seq_key[0] = 1.0;
    numeric_sequence_lock_DW.seq_key[1] = 1.0;
    numeric_sequence_lock_DW.seq_key[2] = 1.0;
    numeric_sequence_lock_DW.seq_key[3] = 1.0;
  } else {
    switch (numeric_sequence_lock_DW.is_c3_numeric_sequence_lock) {
     case numeric_sequence_lock_IN_CHECK:
      if (numeric_sequence_lock_B.Equal1) {
        p = false;
        b_p = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 4)) {
          if (!(numeric_sequence_lock_B.user_seq[k] ==
                numeric_sequence_lock_DW.seq_key[k])) {
            b_p = false;
            exitg1 = true;
          } else {
            k++;
          }
        }

        if (b_p) {
          p = true;
        }

        if (p) {
          numeric_sequence_lock_DW.is_c3_numeric_sequence_lock =
            numeric_sequence_lock_IN_UNLOCK;
          numeric_sequence_lock_B.state = UNLOCK;
        } else {
          numeric_sequence_lock_DW.is_c3_numeric_sequence_lock =
            numeric_sequence__IN_WRONG_CODE;
          numeric_sequence_lock_B.state = WRONG_CODE;
          numeric_sequence_lock_DW.fail_cntr++;
        }
      }
      break;

     case numeric_sequence_lock_IN_IDLE:
      if (user_input_prev != numeric_sequence_lock_DW.user_input_start) {
        numeric_sequence_lock_DW.is_c3_numeric_sequence_lock =
          numeric_sequence_loc_IN_READING;
        numeric_sequence_lock_B.state = READING;
        numeric_sequence_lock_DW.i++;
        numeric_sequence_lock_B.user_seq[(int16_T)numeric_sequence_lock_DW.i - 1]
          = numeric_sequence_lock_B.Subtract;
      }
      break;

     case numeric_sequence_lock_IN_INIT:
      numeric_sequence_lock_DW.is_c3_numeric_sequence_lock =
        numeric_sequence_lock_IN_LOCKED;
      numeric_sequence_lock_B.state = LOCKED;
      numeric_sequence_lock_B.user_seq[0] = 0.0;
      numeric_sequence_lock_B.user_seq[1] = 0.0;
      numeric_sequence_lock_B.user_seq[2] = 0.0;
      numeric_sequence_lock_B.user_seq[3] = 0.0;
      numeric_sequence_lock_DW.i = 0.0;
      break;

     case numeric_sequence_lock_IN_LOCKED:
      numeric_sequence_lock_DW.is_c3_numeric_sequence_lock =
        numeric_sequence_lock_IN_IDLE;
      numeric_sequence_lock_B.state = IDLE;
      numeric_sequence_lock_DW.fail_cntr = 0.0;
      break;

     case numeric_sequence_loc_IN_READING:
      if (numeric_sequence_lock_DW.i >= numeric_sequence_lock_DW.sequence_length)
      {
        numeric_sequence_lock_DW.is_c3_numeric_sequence_lock =
          numeric_sequence_lock_IN_CHECK;
        numeric_sequence_lock_B.state = CHECK;
      } else {
        if (user_input_prev != numeric_sequence_lock_DW.user_input_start) {
          numeric_sequence_lock_DW.is_c3_numeric_sequence_lock =
            numeric_sequence_lock_IN_IDLE;
          numeric_sequence_lock_B.state = IDLE;
          numeric_sequence_lock_DW.fail_cntr = 0.0;
        }
      }
      break;

     case numeric_sequ_IN_SYSTEM_LOCKDOWN:
      numeric_sequence_lock_DW.is_c3_numeric_sequence_lock =
        numeric_sequence_lock_IN_LOCKED;
      numeric_sequence_lock_B.state = LOCKED;
      numeric_sequence_lock_B.user_seq[0] = 0.0;
      numeric_sequence_lock_B.user_seq[1] = 0.0;
      numeric_sequence_lock_B.user_seq[2] = 0.0;
      numeric_sequence_lock_B.user_seq[3] = 0.0;
      numeric_sequence_lock_DW.i = 0.0;
      break;

     case numeric_sequence_lock_IN_UNLOCK:
      if (numeric_sequence_lock_B.Equal) {
        numeric_sequence_lock_DW.is_c3_numeric_sequence_lock =
          numeric_sequence_lock_IN_INIT;
        numeric_sequence_lock_B.state = INIT;
        numeric_sequence_lock_DW.sequence_length = 4.0;
        numeric_sequence_lock_DW.fail_cntr = 0.0;
        numeric_sequence_lock_DW.seq_key[0] = 1.0;
        numeric_sequence_lock_DW.seq_key[1] = 1.0;
        numeric_sequence_lock_DW.seq_key[2] = 1.0;
        numeric_sequence_lock_DW.seq_key[3] = 1.0;
      }
      break;

     default:
      if (numeric_sequence_lock_DW.fail_cntr >= 5.0) {
        numeric_sequence_lock_DW.is_c3_numeric_sequence_lock =
          numeric_sequ_IN_SYSTEM_LOCKDOWN;
        numeric_sequence_lock_B.state = SYSTEM_LOCKDOWN;
      } else {
        numeric_sequence_lock_DW.is_c3_numeric_sequence_lock =
          numeric_sequence_lock_IN_LOCKED;
        numeric_sequence_lock_B.state = LOCKED;
        numeric_sequence_lock_B.user_seq[0] = 0.0;
        numeric_sequence_lock_B.user_seq[1] = 0.0;
        numeric_sequence_lock_B.user_seq[2] = 0.0;
        numeric_sequence_lock_B.user_seq[3] = 0.0;
        numeric_sequence_lock_DW.i = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.2s, 0.0s] */
    rtExtModeUpload(0, (real_T)numeric_sequence_lock_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(numeric_sequence_lock_M)!=-1) &&
        !((rtmGetTFinal(numeric_sequence_lock_M)-
           numeric_sequence_lock_M->Timing.taskTime0) >
          numeric_sequence_lock_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(numeric_sequence_lock_M, "Simulation finished");
    }

    if (rtmGetStopRequested(numeric_sequence_lock_M)) {
      rtmSetErrorStatus(numeric_sequence_lock_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  numeric_sequence_lock_M->Timing.taskTime0 =
    (++numeric_sequence_lock_M->Timing.clockTick0) *
    numeric_sequence_lock_M->Timing.stepSize0;
}

/* Model initialize function */
void numeric_sequence_lock_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)numeric_sequence_lock_M, 0,
                sizeof(RT_MODEL_numeric_sequence_loc_T));
  rtmSetTFinal(numeric_sequence_lock_M, -1);
  numeric_sequence_lock_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  numeric_sequence_lock_M->Sizes.checksums[0] = (2875814248U);
  numeric_sequence_lock_M->Sizes.checksums[1] = (882041842U);
  numeric_sequence_lock_M->Sizes.checksums[2] = (1349520914U);
  numeric_sequence_lock_M->Sizes.checksums[3] = (1288374976U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    numeric_sequence_lock_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(numeric_sequence_lock_M->extModeInfo,
      &numeric_sequence_lock_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(numeric_sequence_lock_M->extModeInfo,
                        numeric_sequence_lock_M->Sizes.checksums);
    rteiSetTPtr(numeric_sequence_lock_M->extModeInfo, rtmGetTPtr
                (numeric_sequence_lock_M));
  }

  /* block I/O */
  (void) memset(((void *) &numeric_sequence_lock_B), 0,
                sizeof(B_numeric_sequence_lock_T));

  {
    numeric_sequence_lock_B.state = INIT;
  }

  /* states (dwork) */
  (void) memset((void *)&numeric_sequence_lock_DW, 0,
                sizeof(DW_numeric_sequence_lock_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    numeric_sequence_lock_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* SystemInitialize for Chart: '<S1>/Chart' */
  numeric_sequence_lock_DW.is_active_c3_numeric_sequence_l = 0U;
  numeric_sequence_lock_DW.is_c3_numeric_sequence_lock =
    numeric_sequ_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void numeric_sequence_lock_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

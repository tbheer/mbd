/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: keypad_template.c
 *
 * Code generated for Simulink model 'keypad_template'.
 *
 * Model version                  : 1.67
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Nov 27 15:49:00 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "keypad_template.h"
#include "keypad_template_private.h"
#include "keypad_template_dt.h"

/* Named constants for Chart: '<S1>/Chart' */
#define keypad_templ_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define keypad_templ_IN_SYSTEM_LOCKDOWN ((uint8_T)6U)
#define keypad_template_IN_CHECK       ((uint8_T)1U)
#define keypad_template_IN_IDLE        ((uint8_T)2U)
#define keypad_template_IN_INIT        ((uint8_T)3U)
#define keypad_template_IN_LOCKED      ((uint8_T)4U)
#define keypad_template_IN_READING     ((uint8_T)5U)
#define keypad_template_IN_UNLOCK      ((uint8_T)7U)
#define keypad_template_IN_WRONG_CODE  ((uint8_T)8U)

/* Block signals (default storage) */
B_keypad_template_T keypad_template_B;

/* Block states (default storage) */
DW_keypad_template_T keypad_template_DW;

/* Real-time model */
RT_MODEL_keypad_template_T keypad_template_M_;
RT_MODEL_keypad_template_T *const keypad_template_M = &keypad_template_M_;

/* Model step function */
void keypad_template_step(void)
{
  boolean_T p;
  boolean_T b_p;
  int16_T k;
  real_T rtb_ManualSwitch;
  boolean_T exitg1;

  /* S-Function (keypad_sfcn): '<Root>/S-Function Builder' */
  keypad_sfcn_Outputs_wrapper( &keypad_template_B.SFunctionBuilder );

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (keypad_template_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch = keypad_template_B.SFunctionBuilder;
  } else {
    rtb_ManualSwitch = keypad_template_P.Constant_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Sum: '<S3>/Subtract' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S4>/Lower Limit'
   *  Constant: '<S4>/Upper Limit'
   *  Logic: '<S4>/AND'
   *  Product: '<S3>/Product'
   *  RelationalOperator: '<S4>/Lower Test'
   *  RelationalOperator: '<S4>/Upper Test'
   */
  keypad_template_B.Subtract = (real_T)((keypad_template_P.IntervalTest_lowlimit
    <= rtb_ManualSwitch) && (rtb_ManualSwitch <=
    keypad_template_P.IntervalTest_uplimit)) * rtb_ManualSwitch -
    keypad_template_P.Constant_Value_f;

  /* RelationalOperator: '<S3>/Equal' incorporates:
   *  Constant: '<S3>/+'
   */
  keypad_template_B.Equal = (keypad_template_P._Value == rtb_ManualSwitch);

  /* RelationalOperator: '<S3>/Equal1' incorporates:
   *  Constant: '<S3>/#'
   */
  keypad_template_B.Equal1 = (rtb_ManualSwitch == keypad_template_P._Value_o);

  /* Chart: '<S1>/Chart' */
  if (keypad_template_DW.temporalCounter_i1 < 2047U) {
    keypad_template_DW.temporalCounter_i1++;
  }

  /* Gateway: numeric sequence lock/Chart */
  rtb_ManualSwitch = keypad_template_DW.user_input_start;
  keypad_template_DW.user_input_start = keypad_template_B.Subtract;

  /* During: numeric sequence lock/Chart */
  if (keypad_template_DW.is_active_c3_keypad_template == 0U) {
    /* Entry: numeric sequence lock/Chart */
    keypad_template_DW.is_active_c3_keypad_template = 1U;

    /* Entry Internal: numeric sequence lock/Chart */
    /* Transition: '<S2>:2' */
    keypad_template_DW.is_c3_keypad_template = keypad_template_IN_INIT;

    /* Entry 'INIT': '<S2>:1' */
    /* '<S2>:1:1' state = States.INIT */
    keypad_template_B.state = INIT;

    /* '<S2>:1:1' sequence_length = 4 */
    keypad_template_DW.sequence_length = 4.0;

    /* counts failed attemps */
    /* '<S2>:1:2' fail_cntr = 0 %counts failed attemps */
    keypad_template_B.fail_cntr = 0.0;

    /* change this to change lock combination */
    /* '<S2>:1:3' seq_key = [1;1;1;1] %change this to change lock combination */
    keypad_template_DW.seq_key[0] = 1.0;
    keypad_template_DW.seq_key[1] = 1.0;
    keypad_template_DW.seq_key[2] = 1.0;
    keypad_template_DW.seq_key[3] = 1.0;
  } else {
    switch (keypad_template_DW.is_c3_keypad_template) {
     case keypad_template_IN_CHECK:
      /* During 'CHECK': '<S2>:8' */
      /* '<S2>:41:1' sf_internal_predicateOutput = enter == 1; */
      if (keypad_template_B.Equal1) {
        /* Transition: '<S2>:41' */
        /* '<S2>:15:1' sf_internal_predicateOutput = isequal(user_seq ,seq_key); */
        p = false;
        b_p = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 4)) {
          if (!(keypad_template_B.user_seq[k] == keypad_template_DW.seq_key[k]))
          {
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
          /* Transition: '<S2>:15' */
          keypad_template_DW.is_c3_keypad_template = keypad_template_IN_UNLOCK;

          /* Entry 'UNLOCK': '<S2>:9' */
          /* '<S2>:9:1' state = States.UNLOCK */
          keypad_template_B.state = UNLOCK;

          /* do something */
        } else {
          /* Transition: '<S2>:40' */
          keypad_template_DW.is_c3_keypad_template =
            keypad_template_IN_WRONG_CODE;

          /* Entry 'WRONG_CODE': '<S2>:10' */
          /* '<S2>:10:1' state = States.WRONG_CODE */
          keypad_template_B.state = WRONG_CODE;

          /* '<S2>:10:1' fail_cntr = fail_cntr + 1 */
          keypad_template_B.fail_cntr++;
        }
      }
      break;

     case keypad_template_IN_IDLE:
      /* During 'IDLE': '<S2>:5' */
      /* '<S2>:13:1' sf_internal_predicateOutput = hasChanged(user_input); */
      if (rtb_ManualSwitch != keypad_template_DW.user_input_start) {
        /* Transition: '<S2>:13' */
        keypad_template_DW.is_c3_keypad_template = keypad_template_IN_READING;

        /* Entry 'READING': '<S2>:7' */
        /* '<S2>:7:1' state = States.READING */
        keypad_template_B.state = READING;

        /* increasing index */
        /* '<S2>:7:1' i = i + 1 %increasing index */
        keypad_template_DW.i++;

        /* '<S2>:7:3' user_seq(i) = user_input */
        keypad_template_B.user_seq[(int16_T)keypad_template_DW.i - 1] =
          keypad_template_B.Subtract;
      }
      break;

     case keypad_template_IN_INIT:
      /* During 'INIT': '<S2>:1' */
      /* Transition: '<S2>:57' */
      keypad_template_DW.is_c3_keypad_template = keypad_template_IN_LOCKED;

      /* Entry 'LOCKED': '<S2>:55' */
      /* '<S2>:55:1' state = States.LOCKED */
      keypad_template_B.state = LOCKED;

      /* resetting input */
      /* '<S2>:55:1' user_seq = [0;0;0;0] %resetting input */
      keypad_template_B.user_seq[0] = 0.0;
      keypad_template_B.user_seq[1] = 0.0;
      keypad_template_B.user_seq[2] = 0.0;
      keypad_template_B.user_seq[3] = 0.0;

      /* reseting index */
      /* '<S2>:55:4' i = 0 %reseting index */
      keypad_template_DW.i = 0.0;

      /* lock system */
      break;

     case keypad_template_IN_LOCKED:
      /* During 'LOCKED': '<S2>:55' */
      /* Transition: '<S2>:56' */
      keypad_template_DW.is_c3_keypad_template = keypad_template_IN_IDLE;

      /* Entry 'IDLE': '<S2>:5' */
      /* '<S2>:5:1' state = States.IDLE */
      keypad_template_B.state = IDLE;

      /* lock system */
      break;

     case keypad_template_IN_READING:
      /* During 'READING': '<S2>:7' */
      /* Transition: '<S2>:43' */
      /* '<S2>:14:1' sf_internal_predicateOutput = i >= sequence_length; */
      if (keypad_template_DW.i >= keypad_template_DW.sequence_length) {
        /* Transition: '<S2>:14' */
        keypad_template_DW.is_c3_keypad_template = keypad_template_IN_CHECK;

        /* Entry 'CHECK': '<S2>:8' */
        /* '<S2>:8:1' state = States.CHECK */
        keypad_template_B.state = CHECK;
      } else {
        /* '<S2>:29:1' sf_internal_predicateOutput = hasChanged(user_input); */
        if (rtb_ManualSwitch != keypad_template_DW.user_input_start) {
          /* Transition: '<S2>:29' */
          keypad_template_DW.is_c3_keypad_template = keypad_template_IN_IDLE;

          /* Entry 'IDLE': '<S2>:5' */
          /* '<S2>:5:1' state = States.IDLE */
          keypad_template_B.state = IDLE;

          /* lock system */
        }
      }
      break;

     case keypad_templ_IN_SYSTEM_LOCKDOWN:
      /* During 'SYSTEM_LOCKDOWN': '<S2>:11' */
      /* '<S2>:19:1' sf_internal_predicateOutput = after(15,sec); */
      if (keypad_template_DW.temporalCounter_i1 >= 1500U) {
        /* Transition: '<S2>:19' */
        keypad_template_DW.is_c3_keypad_template = keypad_template_IN_LOCKED;

        /* Entry 'LOCKED': '<S2>:55' */
        /* '<S2>:55:1' state = States.LOCKED */
        keypad_template_B.state = LOCKED;

        /* resetting input */
        /* '<S2>:55:1' user_seq = [0;0;0;0] %resetting input */
        keypad_template_B.user_seq[0] = 0.0;
        keypad_template_B.user_seq[1] = 0.0;
        keypad_template_B.user_seq[2] = 0.0;
        keypad_template_B.user_seq[3] = 0.0;

        /* reseting index */
        /* '<S2>:55:4' i = 0 %reseting index */
        keypad_template_DW.i = 0.0;

        /* lock system */
      }
      break;

     case keypad_template_IN_UNLOCK:
      /* During 'UNLOCK': '<S2>:9' */
      /* '<S2>:20:1' sf_internal_predicateOutput = lock == 1; */
      if (keypad_template_B.Equal) {
        /* Transition: '<S2>:20' */
        keypad_template_DW.is_c3_keypad_template = keypad_template_IN_INIT;

        /* Entry 'INIT': '<S2>:1' */
        /* '<S2>:1:1' state = States.INIT */
        keypad_template_B.state = INIT;

        /* '<S2>:1:1' sequence_length = 4 */
        keypad_template_DW.sequence_length = 4.0;

        /* counts failed attemps */
        /* '<S2>:1:2' fail_cntr = 0 %counts failed attemps */
        keypad_template_B.fail_cntr = 0.0;

        /* change this to change lock combination */
        /* '<S2>:1:3' seq_key = [1;1;1;1] %change this to change lock combination */
        keypad_template_DW.seq_key[0] = 1.0;
        keypad_template_DW.seq_key[1] = 1.0;
        keypad_template_DW.seq_key[2] = 1.0;
        keypad_template_DW.seq_key[3] = 1.0;
      }
      break;

     default:
      /* During 'WRONG_CODE': '<S2>:10' */
      /* Transition: '<S2>:33' */
      /* '<S2>:34:1' sf_internal_predicateOutput = fail_cntr>=5; */
      if (keypad_template_B.fail_cntr >= 5.0) {
        /* Transition: '<S2>:34' */
        keypad_template_DW.is_c3_keypad_template =
          keypad_templ_IN_SYSTEM_LOCKDOWN;
        keypad_template_DW.temporalCounter_i1 = 0U;

        /* Entry 'SYSTEM_LOCKDOWN': '<S2>:11' */
        /* '<S2>:11:1' state = States.SYSTEM_LOCKDOWN */
        keypad_template_B.state = SYSTEM_LOCKDOWN;

        /* todo: implement delay */
      } else {
        /* Transition: '<S2>:35' */
        keypad_template_DW.is_c3_keypad_template = keypad_template_IN_LOCKED;

        /* Entry 'LOCKED': '<S2>:55' */
        /* '<S2>:55:1' state = States.LOCKED */
        keypad_template_B.state = LOCKED;

        /* resetting input */
        /* '<S2>:55:1' user_seq = [0;0;0;0] %resetting input */
        keypad_template_B.user_seq[0] = 0.0;
        keypad_template_B.user_seq[1] = 0.0;
        keypad_template_B.user_seq[2] = 0.0;
        keypad_template_B.user_seq[3] = 0.0;

        /* reseting index */
        /* '<S2>:55:4' i = 0 %reseting index */
        keypad_template_DW.i = 0.0;

        /* lock system */
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, (real_T)keypad_template_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(keypad_template_M)!=-1) &&
        !((rtmGetTFinal(keypad_template_M)-keypad_template_M->Timing.taskTime0) >
          keypad_template_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(keypad_template_M, "Simulation finished");
    }

    if (rtmGetStopRequested(keypad_template_M)) {
      rtmSetErrorStatus(keypad_template_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  keypad_template_M->Timing.taskTime0 =
    (++keypad_template_M->Timing.clockTick0) *
    keypad_template_M->Timing.stepSize0;
}

/* Model initialize function */
void keypad_template_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)keypad_template_M, 0,
                sizeof(RT_MODEL_keypad_template_T));
  rtmSetTFinal(keypad_template_M, -1);
  keypad_template_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  keypad_template_M->Sizes.checksums[0] = (3248944882U);
  keypad_template_M->Sizes.checksums[1] = (3376812286U);
  keypad_template_M->Sizes.checksums[2] = (2978903727U);
  keypad_template_M->Sizes.checksums[3] = (2358121645U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    keypad_template_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(keypad_template_M->extModeInfo,
      &keypad_template_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(keypad_template_M->extModeInfo,
                        keypad_template_M->Sizes.checksums);
    rteiSetTPtr(keypad_template_M->extModeInfo, rtmGetTPtr(keypad_template_M));
  }

  /* block I/O */
  (void) memset(((void *) &keypad_template_B), 0,
                sizeof(B_keypad_template_T));

  {
    keypad_template_B.state = INIT;
  }

  /* states (dwork) */
  (void) memset((void *)&keypad_template_DW, 0,
                sizeof(DW_keypad_template_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    keypad_template_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* SystemInitialize for Chart: '<S1>/Chart' */
  keypad_template_DW.temporalCounter_i1 = 0U;
  keypad_template_DW.is_active_c3_keypad_template = 0U;
  keypad_template_DW.is_c3_keypad_template = keypad_templ_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void keypad_template_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

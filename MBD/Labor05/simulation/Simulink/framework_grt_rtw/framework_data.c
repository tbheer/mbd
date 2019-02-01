/*
 * framework_data.c
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

#include "framework.h"
#include "framework_private.h"

/* Block parameters (default storage) */
P_framework_T framework_P = {
  /* Mask Parameter: Difference_ICPrevInput
   * Referenced by: '<S9>/UD'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant1'
   */
  1.0,

  /* Expression: 7
   * Referenced by: '<S1>/Constant2'
   */
  7.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant5'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant6'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant7'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S2>/I2C Read'
   */
  -1.0,

  /* Computed Parameter: newAngle_Y0
   * Referenced by: '<S2>/newAngle'
   */
  0.0,

  /* Computed Parameter: Gyro_Car_Y0
   * Referenced by: '<S2>/Gyro_Car'
   */
  0.0,

  /* Computed Parameter: PWM_Y0
   * Referenced by: '<S3>/PWM'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S3>/Constant'
   */
  0.01,

  /* Expression: 15
   * Referenced by: '<S3>/Product'
   */
  15.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay3'
   */
  0.0,

  /* Expression: 3.5
   * Referenced by: '<S3>/Differentiater'
   */
  3.5,

  /* Expression: 0.35
   * Referenced by: '<S3>/Integrater'
   */
  0.35,

  /* Expression: 0
   * Referenced by: '<S4>/Constant3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Constant4'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay1'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Computed Parameter: Delay3_DelayLength
   * Referenced by: '<S3>/Delay3'
   */
  1U,

  /* Computed Parameter: Delay_DelayLength
   * Referenced by: '<Root>/Delay'
   */
  1U,

  /* Computed Parameter: Delay1_DelayLength
   * Referenced by: '<Root>/Delay1'
   */
  1U,

  /* Computed Parameter: Delay2_DelayLength
   * Referenced by: '<Root>/Delay2'
   */
  1U
};

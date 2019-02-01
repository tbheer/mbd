/*
 * framework_private.h
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

#ifndef RTW_HEADER_framework_private_h_
#define RTW_HEADER_framework_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "framework.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

extern void framework_I2CWrite4_Start(DW_I2CWrite4_framework_T *localDW);
extern void framework_I2CWrite4(real_T rtu_0, DW_I2CWrite4_framework_T *localDW);
extern void framework_I2CWrite4_Term(DW_I2CWrite4_framework_T *localDW);

#endif                                 /* RTW_HEADER_framework_private_h_ */

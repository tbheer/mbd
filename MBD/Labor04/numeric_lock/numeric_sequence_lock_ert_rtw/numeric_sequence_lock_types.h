/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: numeric_sequence_lock_types.h
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

#ifndef RTW_HEADER_numeric_sequence_lock_types_h_
#define RTW_HEADER_numeric_sequence_lock_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_States_
#define DEFINED_TYPEDEF_FOR_States_

typedef enum {
  INIT = 0,                            /* Default value */
  IDLE,
  KEY_PRESSED,
  READING,
  CHECK,
  UNLOCK,
  WRONG_CODE,
  SYSTEM_LOCKDOWN,
  LOCKED
} States;

#endif

/* Parameters (default storage) */
typedef struct P_numeric_sequence_lock_T_ P_numeric_sequence_lock_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_numeric_sequence_lock_T RT_MODEL_numeric_sequence_loc_T;

#endif                                 /* RTW_HEADER_numeric_sequence_lock_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * keypad_template_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "keypad_template".
 *
 * Model version              : 1.67
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Tue Nov 27 15:49:00 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(States)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "States"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&keypad_template_B.Subtract), 0, 0, 6 },

  { (char_T *)(&keypad_template_B.state), 14, 0, 1 },

  { (char_T *)(&keypad_template_B.SFunctionBuilder), 3, 0, 1 },

  { (char_T *)(&keypad_template_B.Equal), 8, 0, 2 }
  ,

  { (char_T *)(&keypad_template_DW.i), 0, 0, 8 },

  { (char_T *)(&keypad_template_DW.Scope_PWORK.LoggedData), 11, 0, 1 },

  { (char_T *)(&keypad_template_DW.temporalCounter_i1), 5, 0, 1 },

  { (char_T *)(&keypad_template_DW.is_active_c3_keypad_template), 3, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&keypad_template_P.IntervalTest_lowlimit), 0, 0, 6 },

  { (char_T *)(&keypad_template_P.ManualSwitch_CurrentSetting), 3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] keypad_template_dt.h */

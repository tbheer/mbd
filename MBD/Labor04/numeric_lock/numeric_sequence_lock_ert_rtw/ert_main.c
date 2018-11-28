/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  numeric_sequence_lock_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  OverrunFlag--;
  rtExtModeCheckEndTrigger();
}

volatile boolean_T stopRequested = false;
int main(void)
{
  volatile boolean_T runModel = true;
  float modelBaseRate = 0.2;
  float systemClock = 0;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(numeric_sequence_lock_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  numeric_sequence_lock_initialize();
  sei ();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(numeric_sequence_lock_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(numeric_sequence_lock_M->extModeInfo, 1,
      &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(numeric_sequence_lock_M, true);
    }
  }

  rtERTExtModeStartMsg();
  cli();
  configureArduinoAVRTimer();
  runModel =
    (rtmGetErrorStatus(numeric_sequence_lock_M) == (NULL)) &&
    !rtmGetStopRequested(numeric_sequence_lock_M);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei ();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(numeric_sequence_lock_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(numeric_sequence_lock_M, true);
      }
    }

    stopRequested = !(
                      (rtmGetErrorStatus(numeric_sequence_lock_M) == (NULL)) &&
                      !rtmGetStopRequested(numeric_sequence_lock_M));
    runModel = !(stopRequested);
    runModel = runModel && MW_Arduino_Loop();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  numeric_sequence_lock_terminate();
  rtExtModeShutdown(1);
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * framework.c
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

/* Block signals (default storage) */
B_framework_T framework_B;

/* Block states (default storage) */
DW_framework_T framework_DW;

/* Real-time model */
RT_MODEL_framework_T framework_M_;
RT_MODEL_framework_T *const framework_M = &framework_M_;

/* Forward declaration for local functions */
static codertarget_arduinobase_int_e_T *arduinoI2CWrite_arduinoI2CWrite
  (codertarget_arduinobase_int_e_T *obj);
static void framework_SystemCore_release(const codertarget_arduinobase_int_e_T
  *obj);
static void framework_SystemCore_delete(const codertarget_arduinobase_int_e_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_e_T *obj);

/* Forward declaration for local functions */
static codertarget_arduinobase_int_f_T *f_arduinoI2CRead_arduinoI2CRead
  (codertarget_arduinobase_int_f_T *obj);
static codertarget_arduinobase_in_fe_T *arduino_PWMOutput_arduino_PWMOu
  (codertarget_arduinobase_in_fe_T *obj);
static void matlabCodegenHandle_matlabCod_f(codertarget_arduinobase_block_T *obj);
static void framework_SystemCore_release_f(const codertarget_arduinobase_int_f_T
  *obj);
static void framework_SystemCore_delete_fex(const
  codertarget_arduinobase_int_f_T *obj);
static void matlabCodegenHandle_matlabC_fex(codertarget_arduinobase_int_f_T *obj);
static void matlabCodegenHandle_matlab_fex2(codertarget_arduinobase_in_fe_T *obj);
static codertarget_arduinobase_int_e_T *arduinoI2CWrite_arduinoI2CWrite
  (codertarget_arduinobase_int_e_T *obj)
{
  codertarget_arduinobase_int_e_T *b_obj;
  obj->isInitialized = 0;
  b_obj = obj;
  obj->Hw.AvailablePwmPinNames.f1 = '2';
  obj->Hw.AvailablePwmPinNames.f2 = '3';
  obj->Hw.AvailablePwmPinNames.f3 = '4';
  obj->Hw.AvailablePwmPinNames.f4 = '5';
  obj->Hw.AvailablePwmPinNames.f5 = '6';
  obj->Hw.AvailablePwmPinNames.f6 = '7';
  obj->Hw.AvailablePwmPinNames.f7 = '8';
  obj->Hw.AvailablePwmPinNames.f8 = '9';
  obj->Hw.AvailablePwmPinNames.f9[0] = '1';
  obj->Hw.AvailablePwmPinNames.f9[1] = '0';
  obj->Hw.AvailablePwmPinNames.f10[0] = '1';
  obj->Hw.AvailablePwmPinNames.f10[1] = '1';
  obj->Hw.AvailablePwmPinNames.f11[0] = '1';
  obj->Hw.AvailablePwmPinNames.f11[1] = '2';
  obj->Hw.AvailablePwmPinNames.f12[0] = '1';
  obj->Hw.AvailablePwmPinNames.f12[1] = '3';
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void framework_SystemCore_release(const codertarget_arduinobase_int_e_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->MW_I2C_HANDLE);
  }
}

static void framework_SystemCore_delete(const codertarget_arduinobase_int_e_T
  *obj)
{
  framework_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_e_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    framework_SystemCore_delete(obj);
  }
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void framework_I2CWrite4_Start(DW_I2CWrite4_framework_T *localDW)
{
  codertarget_arduinobase_int_e_T *obj;
  uint32_T i2cname;

  /* Start for MATLABSystem: '<S1>/I2C Write4' */
  localDW->obj.matlabCodegenIsDeleted = true;
  arduinoI2CWrite_arduinoI2CWrite(&localDW->obj);
  localDW->objisempty = true;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  i2cname = 0;
  obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  localDW->obj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(localDW->obj.MW_I2C_HANDLE, localDW->obj.BusSpeed);
  localDW->obj.isSetupComplete = true;
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void framework_I2CWrite4(real_T rtu_0, DW_I2CWrite4_framework_T *localDW)
{
  uint8_T SwappedDataBytes[8];
  uint8_T b_SwappedDataBytes[9];
  real_T b_x;
  uint8_T xtmp;
  int32_T i;

  /* MATLABSystem: '<S1>/I2C Write4' */
  memcpy((void *)&SwappedDataBytes[0], (void *)&rtu_0, (uint32_T)((size_t)8 *
          sizeof(uint8_T)));
  xtmp = SwappedDataBytes[0];
  SwappedDataBytes[0] = SwappedDataBytes[7];
  SwappedDataBytes[7] = xtmp;
  xtmp = SwappedDataBytes[1];
  SwappedDataBytes[1] = SwappedDataBytes[6];
  SwappedDataBytes[6] = xtmp;
  xtmp = SwappedDataBytes[2];
  SwappedDataBytes[2] = SwappedDataBytes[5];
  SwappedDataBytes[5] = xtmp;
  xtmp = SwappedDataBytes[3];
  SwappedDataBytes[3] = SwappedDataBytes[4];
  SwappedDataBytes[4] = xtmp;
  memcpy((void *)&b_x, (void *)&SwappedDataBytes[0], (uint32_T)((size_t)1 *
          sizeof(real_T)));
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_x, (uint32_T)((size_t)8 *
          sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 107U;
  for (i = 0; i < 8; i++) {
    b_SwappedDataBytes[i + 1] = SwappedDataBytes[i];
  }

  MW_I2C_MasterWrite(localDW->obj.MW_I2C_HANDLE, 104U, b_SwappedDataBytes, 9U,
                     false, false);

  /* End of MATLABSystem: '<S1>/I2C Write4' */
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void framework_I2CWrite4_Term(DW_I2CWrite4_framework_T *localDW)
{
  /* Terminate for MATLABSystem: '<S1>/I2C Write4' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj);
}

static codertarget_arduinobase_int_f_T *f_arduinoI2CRead_arduinoI2CRead
  (codertarget_arduinobase_int_f_T *obj)
{
  codertarget_arduinobase_int_f_T *b_obj;
  obj->isInitialized = 0;
  b_obj = obj;
  obj->Hw.AvailablePwmPinNames.f1 = '2';
  obj->Hw.AvailablePwmPinNames.f2 = '3';
  obj->Hw.AvailablePwmPinNames.f3 = '4';
  obj->Hw.AvailablePwmPinNames.f4 = '5';
  obj->Hw.AvailablePwmPinNames.f5 = '6';
  obj->Hw.AvailablePwmPinNames.f6 = '7';
  obj->Hw.AvailablePwmPinNames.f7 = '8';
  obj->Hw.AvailablePwmPinNames.f8 = '9';
  obj->Hw.AvailablePwmPinNames.f9[0] = '1';
  obj->Hw.AvailablePwmPinNames.f9[1] = '0';
  obj->Hw.AvailablePwmPinNames.f10[0] = '1';
  obj->Hw.AvailablePwmPinNames.f10[1] = '1';
  obj->Hw.AvailablePwmPinNames.f11[0] = '1';
  obj->Hw.AvailablePwmPinNames.f11[1] = '2';
  obj->Hw.AvailablePwmPinNames.f12[0] = '1';
  obj->Hw.AvailablePwmPinNames.f12[1] = '3';
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static codertarget_arduinobase_in_fe_T *arduino_PWMOutput_arduino_PWMOu
  (codertarget_arduinobase_in_fe_T *obj)
{
  codertarget_arduinobase_in_fe_T *b_obj;
  obj->isInitialized = 0;
  b_obj = obj;
  obj->Hw.AvailablePwmPinNames.f1 = '2';
  obj->Hw.AvailablePwmPinNames.f2 = '3';
  obj->Hw.AvailablePwmPinNames.f3 = '4';
  obj->Hw.AvailablePwmPinNames.f4 = '5';
  obj->Hw.AvailablePwmPinNames.f5 = '6';
  obj->Hw.AvailablePwmPinNames.f6 = '7';
  obj->Hw.AvailablePwmPinNames.f7 = '8';
  obj->Hw.AvailablePwmPinNames.f8 = '9';
  obj->Hw.AvailablePwmPinNames.f9[0] = '1';
  obj->Hw.AvailablePwmPinNames.f9[1] = '0';
  obj->Hw.AvailablePwmPinNames.f10[0] = '1';
  obj->Hw.AvailablePwmPinNames.f10[1] = '1';
  obj->Hw.AvailablePwmPinNames.f11[0] = '1';
  obj->Hw.AvailablePwmPinNames.f11[1] = '2';
  obj->Hw.AvailablePwmPinNames.f12[0] = '1';
  obj->Hw.AvailablePwmPinNames.f12[1] = '3';
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void matlabCodegenHandle_matlabCod_f(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void framework_SystemCore_release_f(const codertarget_arduinobase_int_f_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->MW_I2C_HANDLE);
  }
}

static void framework_SystemCore_delete_fex(const
  codertarget_arduinobase_int_f_T *obj)
{
  framework_SystemCore_release_f(obj);
}

static void matlabCodegenHandle_matlabC_fex(codertarget_arduinobase_int_f_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    framework_SystemCore_delete_fex(obj);
  }
}

static void matlabCodegenHandle_matlab_fex2(codertarget_arduinobase_in_fe_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function */
void framework_step(void)
{
  real_T F[4];
  real_T y;
  real_T K[2];
  static const real_T a[4] = { 0.001, 0.0, 0.0, 0.003 };

  int16_T b_output[7];
  uint8_T status;
  uint8_T output_raw[14];
  uint8_T y_0[2];
  int16_T x;
  uint8_T b_x[2];
  real_T rtb_Delay1;
  real_T rtb_Delay;
  int32_T i;
  real_T F_0[2];
  real_T tmp[2];
  real_T F_1[4];
  real_T F_2[4];
  real_T K_0;
  real_T P_tmp;

  /* Delay: '<Root>/Delay' */
  rtb_Delay = framework_DW.Delay_DSTATE;

  /* Outputs for Enabled SubSystem: '<Root>/One_time_initialization' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant4'
   *  Delay: '<Root>/Delay'
   */
  if (!(framework_DW.Delay_DSTATE != 0.0)) {
    framework_I2CWrite4(framework_P.Constant1_Value, &framework_DW.I2CWrite);
    framework_I2CWrite4(framework_P.Constant2_Value, &framework_DW.I2CWrite1);
    framework_I2CWrite4(framework_P.Constant3_Value, &framework_DW.I2CWrite2);
    framework_I2CWrite4(framework_P.Constant4_Value, &framework_DW.I2CWrite3);

    /* MATLABSystem: '<S1>/I2C Write4' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant2'
     *  Constant: '<S1>/Constant3'
     *  Constant: '<S1>/Constant4'
     *  Constant: '<S1>/Constant5'
     */
    framework_I2CWrite4(framework_P.Constant5_Value, &framework_DW.I2CWrite4);

    /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
     *  Constant: '<S1>/Constant6'
     */
    if (framework_P.Constant6_Value < 256.0) {
      if (framework_P.Constant6_Value >= 0.0) {
        status = (uint8_T)framework_P.Constant6_Value;
      } else {
        status = 0U;
      }
    } else {
      status = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

    /* MATLABSystem: '<S6>/Digital Output' */
    writeDigitalPin(12, status);

    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  Constant: '<S1>/Constant7'
     */
    if (framework_P.Constant7_Value < 256.0) {
      if (framework_P.Constant7_Value >= 0.0) {
        status = (uint8_T)framework_P.Constant7_Value;
      } else {
        status = 0U;
      }
    } else {
      status = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

    /* MATLABSystem: '<S5>/Digital Output' */
    writeDigitalPin(9, status);
  }

  /* End of Logic: '<Root>/Logical Operator' */
  /* End of Outputs for SubSystem: '<Root>/One_time_initialization' */

  /* Outputs for Enabled SubSystem: '<Root>/acc_gyro_read' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* Delay: '<Root>/Delay' */
  if (framework_DW.Delay_DSTATE > 0.0) {
    /* MATLABSystem: '<S2>/I2C Read' */
    if (framework_DW.obj.SampleTime != framework_P.I2CRead_SampleTime) {
      framework_DW.obj.SampleTime = framework_P.I2CRead_SampleTime;
    }

    status = 59U;
    status = MW_I2C_MasterWrite(framework_DW.obj.MW_I2C_HANDLE, 104U, &status,
      1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(framework_DW.obj.MW_I2C_HANDLE, 104U, output_raw, 14U,
                        false, true);
      memcpy((void *)&b_output[0], (void *)&output_raw[0], (uint32_T)((size_t)7 *
              sizeof(int16_T)));
      for (i = 0; i < 7; i++) {
        x = b_output[i];
        memcpy((void *)&y_0[0], (void *)&x, (uint32_T)((size_t)2 * sizeof
                (uint8_T)));
        b_x[0] = y_0[1];
        b_x[1] = y_0[0];
        memcpy((void *)&b_output[i], (void *)&b_x[0], (uint32_T)((size_t)1 *
                sizeof(int16_T)));
      }
    } else {
      for (i = 0; i < 7; i++) {
        b_output[i] = 0;
      }
    }

    /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
     *  MATLABSystem: '<S2>/I2C Read'
     */
    framework_B.roll = atan((real_T)b_output[1] / sqrt((real_T)(b_output[0] *
      b_output[0]) + (real_T)(b_output[2] * b_output[2]))) * 180.0 /
      3.1415926535897931;

    /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
     *  MATLABSystem: '<S2>/I2C Read'
     */
    framework_B.gyroXrate = (real_T)b_output[4] / 131.0;
  }

  /* End of Outputs for SubSystem: '<Root>/acc_gyro_read' */

  /* Delay: '<Root>/Delay1' incorporates:
   *  Constant: '<S3>/Constant'
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  rtb_Delay1 = framework_DW.Delay1_DSTATE;

  /* Outputs for Enabled SubSystem: '<Root>/controller' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (framework_DW.Delay1_DSTATE > 0.0) {
    /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
     *  Constant: '<S3>/Constant'
     */
    F[0] = 1.0;
    F[2] = -framework_P.Constant_Value;
    F[1] = 0.0;
    F[3] = 1.0;
    F_0[0] = -framework_P.Constant_Value * framework_DW.x[1] + framework_DW.x[0];
    F_0[1] = 0.0 * framework_DW.x[0];
    F_0[1] += framework_DW.x[1];

    /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
     *  Constant: '<S3>/Constant'
     */
    tmp[0] = framework_P.Constant_Value * framework_B.gyroXrate;
    tmp[1] = 0.0 * framework_B.gyroXrate;
    for (i = 0; i < 2; i++) {
      framework_DW.x[i] = F_0[i] + tmp[i];
      F_1[i] = 0.0;
      F_1[i] += F[i] * framework_DW.P[0];
      y = F[i + 2];
      F_1[i] += y * framework_DW.P[1];
      F_1[i + 2] = 0.0;
      F_1[i + 2] += F[i] * framework_DW.P[2];
      F_1[i + 2] += y * framework_DW.P[3];
    }

    y = 0.0;
    for (i = 0; i < 2; i++) {
      P_tmp = F_1[i + 2];
      framework_DW.P[i] = (P_tmp * -framework_P.Constant_Value + F_1[i]) + a[i] *
        framework_P.Constant_Value;
      framework_DW.P[i + 2] = (F_1[i] * 0.0 + P_tmp) + a[i + 2] *
        framework_P.Constant_Value;
      y += (1.0 - (real_T)i) * framework_DW.x[i];
    }

    y = framework_B.roll - y;
    P_tmp = (0.0 * framework_DW.P[3] + framework_DW.P[2]) * 0.0 + (0.0 *
      framework_DW.P[1] + framework_DW.P[0]);
    K_0 = (framework_DW.P[2] * 0.0 + framework_DW.P[0]) / (P_tmp + 0.03);
    framework_DW.x[0] += K_0 * y;
    K[0] = K_0;

    /* MATLAB Function: '<S3>/MATLAB Function' */
    K_0 = (framework_DW.P[3] * 0.0 + framework_DW.P[1]) / (P_tmp + 0.03);
    framework_DW.x[1] += K_0 * y;
    K[1] = K_0;

    /* MATLAB Function: '<S3>/MATLAB Function' */
    F[1] = 0.0;
    F[2] = 0.0;
    F[0] = 1.0;
    F[3] = 1.0;
    for (i = 0; i < 2; i++) {
      F_1[i] = F[i] - K[i];
      F_1[i + 2] = F[i + 2] - K[i] * 0.0;
      F_2[i] = 0.0;
      F_2[i] += F_1[i] * framework_DW.P[0];
      y = F_1[i + 2];
      F_2[i] += y * framework_DW.P[1];
      F_2[i + 2] = 0.0;
      F_2[i + 2] += F_1[i] * framework_DW.P[2];
      F_2[i + 2] += y * framework_DW.P[3];
    }

    framework_DW.P[0] = F_2[0];
    framework_DW.P[1] = F_2[1];
    framework_DW.P[2] = F_2[2];
    framework_DW.P[3] = F_2[3];

    /* Gain: '<S3>/Differentiater' incorporates:
     *  MATLAB Function: '<S3>/MATLAB Function'
     */
    y = framework_P.Differentiater_Gain * framework_DW.x[0];

    /* Sum: '<S3>/Add' incorporates:
     *  Delay: '<S3>/Delay3'
     *  Gain: '<S3>/Product'
     *  MATLAB Function: '<S3>/MATLAB Function'
     *  Sum: '<S9>/Diff'
     *  UnitDelay: '<S9>/UD'
     */
    framework_B.Add = (framework_P.Product_Gain * framework_DW.x[0] +
                       framework_DW.Delay3_DSTATE) + (y - framework_DW.UD_DSTATE);

    /* Update for Delay: '<S3>/Delay3' incorporates:
     *  Gain: '<S3>/Integrater'
     *  MATLAB Function: '<S3>/MATLAB Function'
     */
    framework_DW.Delay3_DSTATE = framework_P.Integrater_Gain * framework_DW.x[0];

    /* Update for UnitDelay: '<S9>/UD' */
    framework_DW.UD_DSTATE = y;
  }

  /* End of Delay: '<Root>/Delay1' */
  /* End of Outputs for SubSystem: '<Root>/controller' */
  /* Outputs for Enabled SubSystem: '<Root>/motor_controller' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Delay: '<Root>/Delay2' */
  if (framework_DW.Delay2_DSTATE > 0.0) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant3'
     *  Constant: '<S4>/Constant4'
     *  Logic: '<S4>/Logical Operator1'
     */
    if (framework_B.Add > framework_P.Switch_Threshold) {
      K[0] = framework_P.Constant3_Value_b;
      K[1] = framework_P.Constant4_Value_n;
    } else {
      K[0] = !(framework_P.Constant3_Value_b != 0.0);
      K[1] = !(framework_P.Constant4_Value_n != 0.0);
    }

    /* End of Switch: '<S4>/Switch' */

    /* DataTypeConversion: '<S11>/Data Type Conversion' */
    if (K[0] < 256.0) {
      if (K[0] >= 0.0) {
        status = (uint8_T)K[0];
      } else {
        status = 0U;
      }
    } else {
      status = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

    /* MATLABSystem: '<S11>/Digital Output' */
    writeDigitalPin(8, status);

    /* DataTypeConversion: '<S12>/Data Type Conversion' */
    if (K[1] < 256.0) {
      if (K[1] >= 0.0) {
        status = (uint8_T)K[1];
      } else {
        status = 0U;
      }
    } else {
      status = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S12>/Data Type Conversion' */

    /* MATLABSystem: '<S12>/Digital Output' */
    writeDigitalPin(7, status);

    /* DataTypeConversion: '<S13>/Data Type Conversion' */
    if (K[1] < 256.0) {
      if (K[1] >= 0.0) {
        status = (uint8_T)K[1];
      } else {
        status = 0U;
      }
    } else {
      status = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S13>/Data Type Conversion' */

    /* MATLABSystem: '<S13>/Digital Output' */
    writeDigitalPin(3, status);

    /* DataTypeConversion: '<S14>/Data Type Conversion' */
    if (K[0] < 256.0) {
      if (K[0] >= 0.0) {
        status = (uint8_T)K[0];
      } else {
        status = 0U;
      }
    } else {
      status = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S14>/Data Type Conversion' */

    /* MATLABSystem: '<S14>/Digital Output' */
    writeDigitalPin(4, status);

    /* Abs: '<S4>/Abs' */
    y = fabs(framework_B.Add);

    /* MATLABSystem: '<S4>/PWM' */
    MW_PWM_SetDutyCycle(framework_DW.obj_h.MW_PWM_HANDLE, y);

    /* MATLABSystem: '<S4>/PWM1' */
    MW_PWM_SetDutyCycle(framework_DW.obj_n.MW_PWM_HANDLE, y);
  }

  /* End of Delay: '<Root>/Delay2' */
  /* End of Outputs for SubSystem: '<Root>/motor_controller' */

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  Constant: '<Root>/Constant'
   */
  framework_DW.Delay_DSTATE = framework_P.Constant_Value_c;

  /* Update for Delay: '<Root>/Delay1' */
  framework_DW.Delay1_DSTATE = rtb_Delay;

  /* Update for Delay: '<Root>/Delay2' */
  framework_DW.Delay2_DSTATE = rtb_Delay1;

  /* Matfile logging */
  rt_UpdateTXYLogVars(framework_M->rtwLogInfo, (&framework_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(framework_M)!=-1) &&
        !((rtmGetTFinal(framework_M)-framework_M->Timing.taskTime0) >
          framework_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(framework_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++framework_M->Timing.clockTick0)) {
    ++framework_M->Timing.clockTickH0;
  }

  framework_M->Timing.taskTime0 = framework_M->Timing.clockTick0 *
    framework_M->Timing.stepSize0 + framework_M->Timing.clockTickH0 *
    framework_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void framework_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)framework_M, 0,
                sizeof(RT_MODEL_framework_T));
  rtmSetTFinal(framework_M, 10.0);
  framework_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    framework_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(framework_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(framework_M->rtwLogInfo, (NULL));
    rtliSetLogT(framework_M->rtwLogInfo, "tout");
    rtliSetLogX(framework_M->rtwLogInfo, "");
    rtliSetLogXFinal(framework_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(framework_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(framework_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(framework_M->rtwLogInfo, 0);
    rtliSetLogDecimation(framework_M->rtwLogInfo, 1);
    rtliSetLogY(framework_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(framework_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(framework_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &framework_B), 0,
                sizeof(B_framework_T));

  /* states (dwork) */
  (void) memset((void *)&framework_DW, 0,
                sizeof(DW_framework_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(framework_M->rtwLogInfo, 0.0, rtmGetTFinal
    (framework_M), framework_M->Timing.stepSize0, (&rtmGetErrorStatus
    (framework_M)));

  {
    codertarget_arduinobase_int_f_T *obj;
    uint32_T i2cname;
    codertarget_arduinobase_in_fe_T *obj_0;

    /* Start for Enabled SubSystem: '<Root>/One_time_initialization' */
    /* Constant: '<S1>/Constant1' */
    framework_I2CWrite4_Start(&framework_DW.I2CWrite);

    /* Constant: '<S1>/Constant2' */
    framework_I2CWrite4_Start(&framework_DW.I2CWrite1);

    /* Constant: '<S1>/Constant3' */
    framework_I2CWrite4_Start(&framework_DW.I2CWrite2);

    /* Constant: '<S1>/Constant4' */
    framework_I2CWrite4_Start(&framework_DW.I2CWrite3);

    /* Start for MATLABSystem: '<S1>/I2C Write4' incorporates:
     *  Constant: '<S1>/Constant5'
     */
    framework_I2CWrite4_Start(&framework_DW.I2CWrite4);

    /* Start for MATLABSystem: '<S6>/Digital Output' */
    framework_DW.obj_g.matlabCodegenIsDeleted = true;
    framework_DW.obj_g.isInitialized = 0;
    framework_DW.obj_g.matlabCodegenIsDeleted = false;
    framework_DW.objisempty_f = true;
    framework_DW.obj_g.isSetupComplete = false;
    framework_DW.obj_g.isInitialized = 1;
    digitalIOSetup(12, true);
    framework_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output' */
    framework_DW.obj_lq.matlabCodegenIsDeleted = true;
    framework_DW.obj_lq.isInitialized = 0;
    framework_DW.obj_lq.matlabCodegenIsDeleted = false;
    framework_DW.objisempty_e1 = true;
    framework_DW.obj_lq.isSetupComplete = false;
    framework_DW.obj_lq.isInitialized = 1;
    digitalIOSetup(9, true);
    framework_DW.obj_lq.isSetupComplete = true;

    /* End of Start for SubSystem: '<Root>/One_time_initialization' */

    /* Start for Enabled SubSystem: '<Root>/acc_gyro_read' */
    /* Start for MATLABSystem: '<S2>/I2C Read' */
    framework_DW.obj.matlabCodegenIsDeleted = true;
    f_arduinoI2CRead_arduinoI2CRead(&framework_DW.obj);
    framework_DW.objisempty_dv = true;
    framework_DW.obj.SampleTime = framework_P.I2CRead_SampleTime;
    obj = &framework_DW.obj;
    framework_DW.obj.isSetupComplete = false;
    framework_DW.obj.isInitialized = 1;
    i2cname = 0;
    obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
    framework_DW.obj.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(framework_DW.obj.MW_I2C_HANDLE, framework_DW.obj.BusSpeed);
    framework_DW.obj.isSetupComplete = true;

    /* End of Start for SubSystem: '<Root>/acc_gyro_read' */
    /* Start for Enabled SubSystem: '<Root>/motor_controller' */
    /* Start for MATLABSystem: '<S11>/Digital Output' */
    framework_DW.obj_l.matlabCodegenIsDeleted = true;
    framework_DW.obj_l.isInitialized = 0;
    framework_DW.obj_l.matlabCodegenIsDeleted = false;
    framework_DW.objisempty_d = true;
    framework_DW.obj_l.isSetupComplete = false;
    framework_DW.obj_l.isInitialized = 1;
    digitalIOSetup(8, true);
    framework_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S12>/Digital Output' */
    framework_DW.obj_na.matlabCodegenIsDeleted = true;
    framework_DW.obj_na.isInitialized = 0;
    framework_DW.obj_na.matlabCodegenIsDeleted = false;
    framework_DW.objisempty_o = true;
    framework_DW.obj_na.isSetupComplete = false;
    framework_DW.obj_na.isInitialized = 1;
    digitalIOSetup(7, true);
    framework_DW.obj_na.isSetupComplete = true;

    /* Start for MATLABSystem: '<S13>/Digital Output' */
    framework_DW.obj_d.matlabCodegenIsDeleted = true;
    framework_DW.obj_d.isInitialized = 0;
    framework_DW.obj_d.matlabCodegenIsDeleted = false;
    framework_DW.objisempty_i = true;
    framework_DW.obj_d.isSetupComplete = false;
    framework_DW.obj_d.isInitialized = 1;
    digitalIOSetup(3, true);
    framework_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S14>/Digital Output' */
    framework_DW.obj_j.matlabCodegenIsDeleted = true;
    framework_DW.obj_j.isInitialized = 0;
    framework_DW.obj_j.matlabCodegenIsDeleted = false;
    framework_DW.objisempty = true;
    framework_DW.obj_j.isSetupComplete = false;
    framework_DW.obj_j.isInitialized = 1;
    digitalIOSetup(4, true);
    framework_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM' */
    framework_DW.obj_h.matlabCodegenIsDeleted = true;
    arduino_PWMOutput_arduino_PWMOu(&framework_DW.obj_h);
    framework_DW.objisempty_m = true;
    obj_0 = &framework_DW.obj_h;
    framework_DW.obj_h.isSetupComplete = false;
    framework_DW.obj_h.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(6U, 0.0, 0.0);
    MW_PWM_Start(framework_DW.obj_h.MW_PWM_HANDLE);
    framework_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM1' */
    framework_DW.obj_n.matlabCodegenIsDeleted = true;
    arduino_PWMOutput_arduino_PWMOu(&framework_DW.obj_n);
    framework_DW.objisempty_e = true;
    obj_0 = &framework_DW.obj_n;
    framework_DW.obj_n.isSetupComplete = false;
    framework_DW.obj_n.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(5U, 0.0, 0.0);
    MW_PWM_Start(framework_DW.obj_n.MW_PWM_HANDLE);
    framework_DW.obj_n.isSetupComplete = true;

    /* End of Start for SubSystem: '<Root>/motor_controller' */
  }

  /* InitializeConditions for Delay: '<Root>/Delay' */
  framework_DW.Delay_DSTATE = framework_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay1' */
  framework_DW.Delay1_DSTATE = framework_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay2' */
  framework_DW.Delay2_DSTATE = framework_P.Delay2_InitialCondition;

  /* SystemInitialize for Enabled SubSystem: '<Root>/acc_gyro_read' */
  /* SystemInitialize for Outport: '<S2>/newAngle' */
  framework_B.roll = framework_P.newAngle_Y0;

  /* SystemInitialize for Outport: '<S2>/Gyro_Car' */
  framework_B.gyroXrate = framework_P.Gyro_Car_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/acc_gyro_read' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/controller' */
  /* InitializeConditions for Delay: '<S3>/Delay3' */
  framework_DW.Delay3_DSTATE = framework_P.Delay3_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S9>/UD' */
  framework_DW.UD_DSTATE = framework_P.Difference_ICPrevInput;

  /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function' */
  framework_DW.P[0] = 0.0;
  framework_DW.P[1] = 0.0;
  framework_DW.P[2] = 0.0;
  framework_DW.P[3] = 0.0;
  framework_DW.x[0] = 0.0;
  framework_DW.x[1] = 0.0;

  /* SystemInitialize for Outport: '<S3>/PWM' */
  framework_B.Add = framework_P.PWM_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/controller' */
}

/* Model terminate function */
void framework_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<Root>/One_time_initialization' */
  framework_I2CWrite4_Term(&framework_DW.I2CWrite);
  framework_I2CWrite4_Term(&framework_DW.I2CWrite1);
  framework_I2CWrite4_Term(&framework_DW.I2CWrite2);
  framework_I2CWrite4_Term(&framework_DW.I2CWrite3);

  /* Terminate for MATLABSystem: '<S1>/I2C Write4' */
  framework_I2CWrite4_Term(&framework_DW.I2CWrite4);

  /* Terminate for MATLABSystem: '<S6>/Digital Output' */
  matlabCodegenHandle_matlabCod_f(&framework_DW.obj_g);

  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  matlabCodegenHandle_matlabCod_f(&framework_DW.obj_lq);

  /* End of Terminate for SubSystem: '<Root>/One_time_initialization' */

  /* Terminate for Enabled SubSystem: '<Root>/acc_gyro_read' */
  /* Terminate for MATLABSystem: '<S2>/I2C Read' */
  matlabCodegenHandle_matlabC_fex(&framework_DW.obj);

  /* End of Terminate for SubSystem: '<Root>/acc_gyro_read' */

  /* Terminate for Enabled SubSystem: '<Root>/motor_controller' */
  /* Terminate for MATLABSystem: '<S11>/Digital Output' */
  matlabCodegenHandle_matlabCod_f(&framework_DW.obj_l);

  /* Terminate for MATLABSystem: '<S12>/Digital Output' */
  matlabCodegenHandle_matlabCod_f(&framework_DW.obj_na);

  /* Terminate for MATLABSystem: '<S13>/Digital Output' */
  matlabCodegenHandle_matlabCod_f(&framework_DW.obj_d);

  /* Terminate for MATLABSystem: '<S14>/Digital Output' */
  matlabCodegenHandle_matlabCod_f(&framework_DW.obj_j);

  /* Terminate for MATLABSystem: '<S4>/PWM' */
  matlabCodegenHandle_matlab_fex2(&framework_DW.obj_h);

  /* Terminate for MATLABSystem: '<S4>/PWM1' */
  matlabCodegenHandle_matlab_fex2(&framework_DW.obj_n);

  /* End of Terminate for SubSystem: '<Root>/motor_controller' */
}

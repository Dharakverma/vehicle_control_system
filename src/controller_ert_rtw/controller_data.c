/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_data.c
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jan 31 00:31:24 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller.h"

/* Invariant block signals (default storage) */
const ConstB_controller_T controller_ConstB = {
  0.0F,                                /* '<S12>/Data Type Conversion1' */
  0.0F,                                /* '<S12>/Data Type Conversion2' */
  0.0F,                                /* '<S18>/Subtract1' */
  4095.0F,                             /* '<S12>/Data Type Conversion' */
  4095.0F,                             /* '<S18>/Subtract' */
  0.0F,                                /* '<S18>/Divide' */
  0.0F,                                /* '<S18>/Gain' */
  4095.0F,                             /* '<S11>/Data Type Conversion' */
  0.0F,                                /* '<S11>/Data Type Conversion2' */
  4095.0F,                             /* '<S16>/Subtract' */
  0.0F,                                /* '<S13>/Data Type Conversion1' */
  0.0F,                                /* '<S13>/Data Type Conversion2' */
  0.0F,                                /* '<S20>/Subtract1' */
  4095.0F,                             /* '<S13>/Data Type Conversion' */
  4095.0F,                             /* '<S20>/Subtract' */
  0.0F,                                /* '<S20>/Divide' */
  0.0F,                                /* '<S20>/Gain' */
  0.0F,                                /* '<S2>/Switch2' */
  0.0F,                                /* '<S4>/Gain3' */
  0.5F,                                /* '<S5>/Gain1' */
  0,                                   /* '<S4>/Data Type Conversion1' */
  1,                                   /* '<S4>/Data Type Conversion2' */
  1,                                   /* '<S19>/Lower Test' */
  1,                                   /* '<S19>/Upper Test' */
  1,                                   /* '<S19>/FixPt Logical Operator' */
  0                                    /* '<S13>/NOT' */
};

/* Constant parameters (default storage) */
const ConstP_controller_T controller_ConstP = {
  /* Pooled Parameter (Expression: [0 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95 100])
   * Referenced by: '<S2>/AccelPedalPos1 LUT'
   */
  { 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F, 50.0F,
    55.0F, 60.0F, 65.0F, 70.0F, 75.0F, 80.0F, 85.0F, 90.0F, 95.0F, 100.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

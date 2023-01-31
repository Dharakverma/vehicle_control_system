/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller.c
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
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "controller_types.h"
#include "controller_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define IN_ErrorInitializePrechargeStat ((uint8_T)3U)
#define co_IN_ErrorPrechargeClosedState ((uint8_T)4U)
#define con_IN_InitializePrechargeState ((uint8_T)9U)
#define controll_IN_ErrorAllClosedState ((uint8_T)1U)
#define controll_IN_ErrorPrechargeState ((uint8_T)5U)
#define controller_IN_ErrorHVPositive  ((uint8_T)2U)
#define controller_IN_ErrorRunningState ((uint8_T)6U)
#define controller_IN_ErrorStartupState ((uint8_T)7U)
#define controller_IN_InitialState     ((uint8_T)8U)
#define controller_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define controller_IN_PrechargeState   ((uint8_T)10U)
#define controller_IN_RunningState     ((uint8_T)11U)
#define controller_IN_StartupState     ((uint8_T)12U)
#define controller_IN_StartupState1    ((uint8_T)13U)

/* Named constants for Chart: '<S2>/Chart' */
#define contr_IN_Driver_requested_start ((uint8_T)1U)
#define controlle_IN_Waiting_for_driver ((uint8_T)3U)
#define controller_IN_DI_error         ((uint8_T)1U)
#define controller_IN_DI_running       ((uint8_T)2U)
#define controller_IN_INIT             ((uint8_T)3U)
#define controller_IN_Ready_to_drive   ((uint8_T)2U)
#define controller_IN_SpeakerOff       ((uint8_T)1U)
#define controller_IN_SpeakerOn_       ((uint8_T)2U)
#define controller_IN_Vehicle_coasting ((uint8_T)4U)

/* Named constants for Chart: '<S3>/Chart' */
#define contro_IN_Command_motor_startup ((uint8_T)1U)
#define contro_IN_DriverInterface_Error ((uint8_T)1U)
#define controlle_IN_Initialize_outputs ((uint8_T)1U)
#define controller_IN_Err_reset        ((uint8_T)2U)
#define controller_IN_HV_run_error     ((uint8_T)1U)
#define controller_IN_HV_startup       ((uint8_T)2U)
#define controller_IN_HV_startup_error ((uint8_T)3U)
#define controller_IN_Motor_faulted    ((uint8_T)4U)
#define controller_IN_Motor_run_error  ((uint8_T)2U)
#define controller_IN_RUNNING          ((uint8_T)2U)
#define controller_IN_RUNNING_ERROR    ((uint8_T)3U)
#define controller_IN_STARTUP          ((uint8_T)4U)
#define controller_IN_STARTUP_ERROR    ((uint8_T)5U)
#define controller_IN_Send_ReadyToDrive ((uint8_T)3U)

/* Named constants for Chart: '<S4>/RIGHT_MOTOR' */
#define contr_IN_enforceSetpointsZero_p ((uint8_T)1U)
#define contr_IN_motorOff_waitingForGov ((uint8_T)6U)
#define control_IN_enforceSetpointsZero ((uint8_T)2U)
#define controller_IN_AMK_errorDetected ((uint8_T)1U)
#define controller_IN_AMK_errorReset   ((uint8_T)2U)
#define controller_IN_AMK_running      ((uint8_T)3U)
#define controller_IN_AMK_shutdown     ((uint8_T)4U)
#define controller_IN_AMK_startup      ((uint8_T)5U)
#define controller_IN_commandOff       ((uint8_T)1U)
#define controller_IN_commandOn        ((uint8_T)1U)
#define controller_IN_sendReset        ((uint8_T)2U)
#define controller_IN_toggleDCon       ((uint8_T)3U)
#define controller_IN_toggleEnable     ((uint8_T)3U)
#define controller_IN_toggleReset      ((uint8_T)4U)
#define controller_IN_waiting_sysReady ((uint8_T)4U)

/* Block signals (default storage) */
B_controller_T controller_B;

/* Block states (default storage) */
DW_controller_T controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_controller_T controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_controller_T controller_Y;

/* Real-time model */
static RT_MODEL_controller_T controller_M_;
RT_MODEL_controller_T *const controller_M = &controller_M_;
real32_T look1_iflf_binlcpw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  real32_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0F;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/* Model step function */
void controller_step(void)
{
  real32_T a;
  real32_T rtb_TorqueLimit;

  /* Chart: '<S3>/Chart' incorporates:
   *  Delay: '<S3>/Delay'
   *  Delay: '<S3>/Delay1'
   *  Delay: '<S3>/Delay2'
   */
  if (controller_DW.is_active_c3_governor_lib == 0U) {
    controller_DW.is_active_c3_governor_lib = 1U;
    controller_DW.is_c3_governor_lib = controlle_IN_Initialize_outputs;
    controller_B.GOV_e_miCmd = CMD_INIT;
    controller_B.GOV_e_diCmd = DI_CMD_INIT;
    controller_DW.motorStartCount = 0U;
  } else {
    switch (controller_DW.is_c3_governor_lib) {
     case controlle_IN_Initialize_outputs:
      controller_B.GOV_e_diCmd = DI_CMD_INIT;
      controller_DW.is_c3_governor_lib = controller_IN_STARTUP;
      controller_DW.is_STARTUP = controller_IN_HV_startup;
      break;

     case controller_IN_RUNNING:
      if (controller_DW.Delay_DSTATE_f == ERR_STARTUP) {
        controller_DW.is_c3_governor_lib = controller_IN_RUNNING_ERROR;
        controller_DW.is_RUNNING_ERROR = controller_IN_HV_run_error;
        controller_B.GOV_e_diCmd = SYSTEM_ERROR;
      } else if (controller_DW.Delay1_DSTATE == MI_STS_ERROR) {
        controller_DW.is_c3_governor_lib = controller_IN_RUNNING_ERROR;
        controller_DW.is_RUNNING_ERROR = controller_IN_Motor_run_error;
        controller_B.GOV_e_diCmd = SYSTEM_ERROR;
      }
      break;

     case controller_IN_RUNNING_ERROR:
      if (controller_DW.is_RUNNING_ERROR == controller_IN_HV_run_error) {
        controller_B.GOV_e_diCmd = SYSTEM_ERROR;
      } else {
        /* case IN_Motor_run_error: */
        controller_B.GOV_e_diCmd = SYSTEM_ERROR;
      }
      break;

     case controller_IN_STARTUP:
      {
        if (controller_DW.Delay_DSTATE_f == ERR_STARTUP) {
          controller_DW.is_STARTUP = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_c3_governor_lib = controller_IN_STARTUP_ERROR;
          controller_DW.is_STARTUP_ERROR = controller_IN_HV_startup_error;
        } else if (controller_DW.Delay2_DSTATE == DI_ERROR) {
          controller_DW.is_STARTUP = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_c3_governor_lib = controller_IN_STARTUP_ERROR;
          controller_DW.is_STARTUP_ERROR = contro_IN_DriverInterface_Error;
        } else if (controller_DW.Delay1_DSTATE == MI_STS_ERROR) {
          if (controller_DW.motorStartCount >= 5) {
            controller_DW.is_STARTUP = controller_IN_NO_ACTIVE_CHILD;
            controller_DW.is_c3_governor_lib = controller_IN_STARTUP_ERROR;
            controller_DW.is_STARTUP_ERROR = controller_IN_Motor_faulted;
            controller_B.GOV_e_miCmd = CMD_SHUTDOWN;
          } else {
            controller_DW.is_STARTUP = controller_IN_NO_ACTIVE_CHILD;
            controller_DW.is_c3_governor_lib = controller_IN_STARTUP_ERROR;
            controller_DW.is_STARTUP_ERROR = controller_IN_Err_reset;
          }
        } else {
          switch (controller_DW.is_STARTUP) {
           case contro_IN_Command_motor_startup:
            if ((controller_DW.Delay1_DSTATE == RUNNING) &&
                (controller_DW.Delay2_DSTATE == DRV_START_REQ)) {
              controller_DW.is_STARTUP = controller_IN_Send_ReadyToDrive;
              controller_B.GOV_e_diCmd = READY_TO_DRIVE;
            }
            break;

           case controller_IN_HV_startup:
            {
              if (controller_DW.Delay_DSTATE_f == BM_RUNNING) {
                uint32_T tmp;
                controller_DW.is_STARTUP = contro_IN_Command_motor_startup;
                controller_B.GOV_e_miCmd = CMD_STARTUP;
                tmp = controller_DW.motorStartCount + 1U;
                if (controller_DW.motorStartCount + 1U > 65535U) {
                  tmp = 65535U;
                }

                controller_DW.motorStartCount = (uint16_T)tmp;
              }
            }
            break;

           default:
            /* case IN_Send_ReadyToDrive: */
            controller_B.GOV_e_diCmd = READY_TO_DRIVE;
            if (controller_DW.Delay2_DSTATE == DI_RUNNING) {
              controller_DW.is_STARTUP = controller_IN_NO_ACTIVE_CHILD;
              controller_DW.is_c3_governor_lib = controller_IN_RUNNING;
            }
            break;
          }
        }
      }
      break;

     default:
      /* case IN_STARTUP_ERROR: */
      switch (controller_DW.is_STARTUP_ERROR) {
       case contro_IN_DriverInterface_Error:
       case controller_IN_HV_startup_error:
        break;

       case controller_IN_Err_reset:
        if (controller_DW.Delay1_DSTATE == OFF) {
          controller_DW.is_STARTUP_ERROR = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_c3_governor_lib = controller_IN_STARTUP;
          controller_DW.is_STARTUP = controller_IN_HV_startup;
        } else {
          controller_B.GOV_e_miCmd = ERR_RESET;
        }
        break;

       default:
        /* case IN_Motor_faulted: */
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */

  /* Chart: '<S2>/Chart' incorporates:
   *  Delay: '<S3>/Delay2'
   */
  if (controller_DW.temporalCounter_i1_a < 255U) {
    controller_DW.temporalCounter_i1_a++;
  }

  if (controller_DW.is_active_c3_driver_interface_l == 0U) {
    controller_DW.is_active_c3_driver_interface_l = 1U;
    controller_DW.is_c3_driver_interface_lib = controller_IN_INIT;
    controller_DW.Delay2_DSTATE = DI_STS_INIT;
    controller_B.b_ReadyToDrive = false;

    /* Outport: '<Root>/DI_b_driverSpeaker' incorporates:
     *  Delay: '<S3>/Delay2'
     */
    controller_Y.DI_b_driverSpeaker = false;
  } else {
    switch (controller_DW.is_c3_driver_interface_lib) {
     case controller_IN_DI_error:
      controller_DW.Delay2_DSTATE = DI_ERROR;
      break;

     case controller_IN_DI_running:
      switch (controller_DW.is_DI_running) {
       case contr_IN_Driver_requested_start:
        controller_DW.Delay2_DSTATE = DRV_START_REQ;
        if (controller_B.GOV_e_diCmd == READY_TO_DRIVE) {
          controller_DW.is_DI_running = controller_IN_Ready_to_drive;
          controller_B.b_ReadyToDrive = true;
          controller_DW.Delay2_DSTATE = DI_RUNNING;
          controller_DW.is_Ready_to_drive = controller_IN_SpeakerOn_;
          controller_DW.temporalCounter_i1_a = 0U;

          /* Outport: '<Root>/DI_b_driverSpeaker' */
          controller_Y.DI_b_driverSpeaker = true;
        }
        break;

       case controller_IN_Ready_to_drive:
        controller_B.b_ReadyToDrive = true;
        controller_DW.Delay2_DSTATE = DI_RUNNING;
        if (controller_B.GOV_e_diCmd == SYSTEM_ERROR) {
          controller_DW.is_Ready_to_drive = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_DI_running = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_c3_driver_interface_lib =
            controller_IN_Vehicle_coasting;
          controller_B.b_ReadyToDrive = false;
          controller_DW.Delay2_DSTATE = DI_IDLE;
        } else if (controller_DW.is_Ready_to_drive == controller_IN_SpeakerOff)
        {
          /* Outport: '<Root>/DI_b_driverSpeaker' */
          controller_Y.DI_b_driverSpeaker = false;
        } else {
          /* Outport: '<Root>/DI_b_driverSpeaker' */
          /* case IN_SpeakerOn_: */
          controller_Y.DI_b_driverSpeaker = true;
          if (controller_DW.temporalCounter_i1_a >= 200U) {
            controller_DW.is_Ready_to_drive = controller_IN_SpeakerOff;

            /* Outport: '<Root>/DI_b_driverSpeaker' */
            controller_Y.DI_b_driverSpeaker = false;
          }
        }
        break;

       default:
        /* case IN_Waiting_for_driver: */
        controller_DW.is_DI_running = contr_IN_Driver_requested_start;
        controller_DW.Delay2_DSTATE = DRV_START_REQ;
        break;
      }
      break;

     case controller_IN_INIT:
      controller_B.b_ReadyToDrive = false;

      /* Outport: '<Root>/DI_b_driverSpeaker' */
      controller_Y.DI_b_driverSpeaker = false;
      controller_DW.is_c3_driver_interface_lib = controller_IN_DI_running;
      controller_DW.is_DI_running = controlle_IN_Waiting_for_driver;
      controller_DW.Delay2_DSTATE = WAITING_FOR_DRVR;
      break;

     default:
      /* case IN_Vehicle_coasting: */
      controller_B.b_ReadyToDrive = false;
      controller_DW.Delay2_DSTATE = DI_IDLE;
      break;
    }
  }

  /* End of Chart: '<S2>/Chart' */

  /* MATLAB Function: '<S5>/RIGHT_LIMIT' incorporates:
   *  Constant: '<S5>/MaxMotorCurrent'
   *  Constant: '<S5>/MaxMotorTorque'
   *  Constant: '<S5>/Vbat'
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/convertToAmps3'
   *  Inport: '<Root>/AMK_ActualVelocity'
   *  Inport: '<Root>/AMK_MagnetizingCurrent'
   */
  rtb_TorqueLimit = fmaxf(0.0999984741F * (real32_T)
    controller_U.AMK_MagnetizingCurrent, 0.0F);
  a = fminf(controller_ConstB.Gain1, 52.0F);
  rtb_TorqueLimit = fminf(fmaxf(sqrtf(a * a - rtb_TorqueLimit * rtb_TorqueLimit),
    0.0F) * 24.0F / (fmaxf(controller_U.AMK_ActualVelocity, 1.0F) * 3.14159274F /
                     30.0F), 0.25F);

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S11>/LowerPotentiometerLimit1'
   *  Constant: '<S11>/UpperPotentiometerLimit1'
   *  Constant: '<S5>/Constant6'
   *  Gain: '<S5>/Gain2'
   *  If: '<S2>/If'
   *  Inport: '<Root>/DI_V_AccelPedalPos1'
   *  Logic: '<S11>/NOT'
   *  Logic: '<S15>/FixPt Logical Operator'
   *  Logic: '<S2>/NOT'
   *  Lookup_n-D: '<S2>/AccelPedalPos1 LUT'
   *  MinMax: '<S5>/Min'
   *  Product: '<S5>/Divide'
   *  RelationalOperator: '<S15>/Lower Test'
   *  RelationalOperator: '<S15>/Upper Test'
   */
  if (controller_ConstB.Switch2 > 0.0F) {
    rtb_TorqueLimit = 0.0F;
  } else {
    if (!controller_B.b_ReadyToDrive) {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      /* If: '<S2>/If' incorporates:
       *  Constant: '<S2>/Constant'
       *  SignalConversion generated from: '<S8>/In1'
       */
      a = 0.0F;

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
    } else if ((controller_U.DI_V_AccelPedalPos1 < 0) ||
               (controller_U.DI_V_AccelPedalPos1 > 4095)) {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* If: '<S2>/If' incorporates:
       *  SignalConversion generated from: '<S10>/In1'
       */
      a = controller_ConstB.Gain;

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
    } else {
      /* If: '<S2>/If' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion1'
       *  Gain: '<S16>/Gain'
       *  Inport: '<Root>/DI_V_AccelPedalPos1'
       *  Product: '<S16>/Divide'
       *  Sum: '<S16>/Subtract1'
       */
      a = ((real32_T)controller_U.DI_V_AccelPedalPos1 -
           controller_ConstB.DataTypeConversion2_p) / controller_ConstB.range_p *
        100.0F;
    }

    rtb_TorqueLimit = 0.01F * look1_iflf_binlcpw(a, controller_ConstP.pooled2,
      controller_ConstP.pooled2, 20U) * fminf(rtb_TorqueLimit, rtb_TorqueLimit);
  }

  /* End of Switch: '<S5>/Switch' */

  /* Chart: '<S4>/RIGHT_MOTOR' incorporates:
   *  Inport: '<Root>/AMK_bDcOn'
   *  Inport: '<Root>/AMK_bError'
   *  Inport: '<Root>/AMK_bInverterOn'
   *  Inport: '<Root>/AMK_bQuitDcOn'
   *  Inport: '<Root>/AMK_bQuitInverterOn'
   *  Inport: '<Root>/AMK_bSystemReady'
   */
  if (controller_DW.temporalCounter_i1 < 127U) {
    controller_DW.temporalCounter_i1++;
  }

  if (controller_DW.is_active_c3_motor_interface_li == 0U) {
    controller_DW.is_active_c3_motor_interface_li = 1U;
    controller_DW.is_c3_motor_interface_lib = contr_IN_motorOff_waitingForGov;
    controller_B.MI_motorStatus = OFF;

    /* Outport: '<Root>/AMK_bInverterOn_tx' */
    controller_Y.AMK_bInverterOn_tx = 0U;

    /* Outport: '<Root>/AMK_bDcOn_tx' */
    controller_Y.AMK_bDcOn_tx = 0U;

    /* Outport: '<Root>/AMK_bEnable' */
    controller_Y.AMK_bEnable = 0U;

    /* Outport: '<Root>/AMK_bErrorReset' */
    controller_Y.AMK_bErrorReset = 0U;

    /* Outport: '<Root>/AMK_TargetVelocity' */
    controller_Y.AMK_TargetVelocity = 0;

    /* Outport: '<Root>/AMK_TorqueLimitPositiv' */
    controller_Y.AMK_TorqueLimitPositiv = 0;

    /* Outport: '<Root>/AMK_TorqueLimitNegativ' */
    controller_Y.AMK_TorqueLimitNegativ = 0;
  } else {
    switch (controller_DW.is_c3_motor_interface_lib) {
     case controller_IN_AMK_errorDetected:
      if (controller_B.GOV_e_miCmd == ERR_RESET) {
        controller_DW.is_c3_motor_interface_lib = controller_IN_AMK_errorReset;
        controller_DW.is_AMK_errorReset = contr_IN_enforceSetpointsZero_p;

        /* Outport: '<Root>/AMK_TargetVelocity' */
        controller_Y.AMK_TargetVelocity = 0;

        /* Outport: '<Root>/AMK_TorqueLimitPositiv' */
        controller_Y.AMK_TorqueLimitPositiv = 0;

        /* Outport: '<Root>/AMK_TorqueLimitNegativ' */
        controller_Y.AMK_TorqueLimitNegativ = 0;

        /* Outport: '<Root>/AMK_bInverterOn_tx' */
        controller_Y.AMK_bInverterOn_tx = 0U;
      }
      break;

     case controller_IN_AMK_errorReset:
      switch (controller_DW.is_AMK_errorReset) {
       case contr_IN_enforceSetpointsZero_p:
        /* Outport: '<Root>/AMK_bInverterOn_tx' */
        controller_Y.AMK_bInverterOn_tx = 0U;
        if (!controller_U.AMK_bInverterOn) {
          controller_DW.is_AMK_errorReset = controller_IN_toggleEnable;
          controller_DW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/AMK_bEnable' */
          controller_Y.AMK_bEnable = 0U;
        }
        break;

       case controller_IN_sendReset:
        /* Outport: '<Root>/AMK_bErrorReset' */
        controller_Y.AMK_bErrorReset = 1U;
        if (controller_DW.temporalCounter_i1 >= 50U) {
          controller_DW.is_AMK_errorReset = controller_IN_toggleReset;

          /* Outport: '<Root>/AMK_bErrorReset' */
          controller_Y.AMK_bErrorReset = 0U;
        }
        break;

       case controller_IN_toggleEnable:
        /* Outport: '<Root>/AMK_bEnable' */
        controller_Y.AMK_bEnable = 0U;
        if (controller_DW.temporalCounter_i1 >= 50U) {
          controller_DW.is_AMK_errorReset = controller_IN_sendReset;
          controller_DW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/AMK_bErrorReset' */
          controller_Y.AMK_bErrorReset = 1U;
        }
        break;

       default:
        /* Outport: '<Root>/AMK_bErrorReset' */
        /* case IN_toggleReset: */
        controller_Y.AMK_bErrorReset = 0U;
        if (controller_U.AMK_bSystemReady) {
          controller_DW.is_AMK_errorReset = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_c3_motor_interface_lib =
            contr_IN_motorOff_waitingForGov;
          controller_B.MI_motorStatus = OFF;

          /* Outport: '<Root>/AMK_bInverterOn_tx' */
          controller_Y.AMK_bInverterOn_tx = 0U;

          /* Outport: '<Root>/AMK_bDcOn_tx' */
          controller_Y.AMK_bDcOn_tx = 0U;

          /* Outport: '<Root>/AMK_bEnable' */
          controller_Y.AMK_bEnable = 0U;

          /* Outport: '<Root>/AMK_TargetVelocity' */
          controller_Y.AMK_TargetVelocity = 0;

          /* Outport: '<Root>/AMK_TorqueLimitPositiv' */
          controller_Y.AMK_TorqueLimitPositiv = 0;

          /* Outport: '<Root>/AMK_TorqueLimitNegativ' */
          controller_Y.AMK_TorqueLimitNegativ = 0;
        }
        break;
      }
      break;

     case controller_IN_AMK_running:
      if (controller_U.AMK_bError) {
        controller_DW.is_c3_motor_interface_lib =
          controller_IN_AMK_errorDetected;
        controller_B.MI_motorStatus = MI_STS_ERROR;
      } else if (controller_B.GOV_e_miCmd == CMD_SHUTDOWN) {
        controller_DW.is_c3_motor_interface_lib = controller_IN_AMK_shutdown;
        controller_DW.is_AMK_shutdown = control_IN_enforceSetpointsZero;
        controller_B.MI_motorStatus = SHUTDOWN;

        /* Outport: '<Root>/AMK_TargetVelocity' */
        controller_Y.AMK_TargetVelocity = 0;

        /* Outport: '<Root>/AMK_TorqueLimitPositiv' */
        controller_Y.AMK_TorqueLimitPositiv = 0;

        /* Outport: '<Root>/AMK_TorqueLimitNegativ' */
        controller_Y.AMK_TorqueLimitNegativ = 0;

        /* Outport: '<Root>/AMK_bInverterOn_tx' */
        controller_Y.AMK_bInverterOn_tx = 0U;
      } else {
        controller_B.MI_motorStatus = RUNNING;

        /* Outport: '<Root>/AMK_TargetVelocity' */
        controller_Y.AMK_TargetVelocity =
          controller_ConstB.DataTypeConversion2_d;

        /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
         *  Gain: '<S4>/Gain2'
         */
        a = floorf(1000.0F * rtb_TorqueLimit);
        if (rtIsNaNF(a) || rtIsInfF(a)) {
          a = 0.0F;
        } else {
          a = fmodf(a, 65536.0F);
        }

        /* Outport: '<Root>/AMK_TorqueLimitPositiv' incorporates:
         *  DataTypeConversion: '<S4>/Data Type Conversion'
         */
        controller_Y.AMK_TorqueLimitPositiv = (int16_T)(a < 0.0F ? (int32_T)
          (int16_T)-(int16_T)(uint16_T)-a : (int32_T)(int16_T)(uint16_T)a);

        /* Outport: '<Root>/AMK_TorqueLimitNegativ' */
        controller_Y.AMK_TorqueLimitNegativ =
          controller_ConstB.DataTypeConversion1_l;
      }
      break;

     case controller_IN_AMK_shutdown:
      switch (controller_DW.is_AMK_shutdown) {
       case controller_IN_commandOff:
        /* Outport: '<Root>/AMK_bEnable' */
        controller_Y.AMK_bEnable = 0U;
        if (!controller_U.AMK_bQuitDcOn) {
          controller_DW.is_AMK_shutdown = controller_IN_toggleDCon;

          /* Outport: '<Root>/AMK_bDcOn_tx' */
          controller_Y.AMK_bDcOn_tx = 0U;
        } else if (controller_U.AMK_bError) {
          controller_DW.is_AMK_shutdown = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_c3_motor_interface_lib =
            controller_IN_AMK_errorDetected;
          controller_B.MI_motorStatus = MI_STS_ERROR;
        }
        break;

       case control_IN_enforceSetpointsZero:
        /* Outport: '<Root>/AMK_bInverterOn_tx' */
        controller_Y.AMK_bInverterOn_tx = 0U;
        if (!controller_U.AMK_bInverterOn) {
          controller_DW.is_AMK_shutdown = controller_IN_commandOff;

          /* Outport: '<Root>/AMK_bEnable' */
          controller_Y.AMK_bEnable = 0U;
        } else if (controller_U.AMK_bError) {
          controller_DW.is_AMK_shutdown = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_c3_motor_interface_lib =
            controller_IN_AMK_errorDetected;
          controller_B.MI_motorStatus = MI_STS_ERROR;
        }
        break;

       default:
        /* Outport: '<Root>/AMK_bDcOn_tx' */
        /* case IN_toggleDCon: */
        controller_Y.AMK_bDcOn_tx = 0U;
        if ((!controller_U.AMK_bDcOn) && (!controller_U.AMK_bQuitDcOn)) {
          controller_DW.is_AMK_shutdown = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_c3_motor_interface_lib =
            contr_IN_motorOff_waitingForGov;
          controller_B.MI_motorStatus = OFF;

          /* Outport: '<Root>/AMK_bInverterOn_tx' */
          controller_Y.AMK_bInverterOn_tx = 0U;

          /* Outport: '<Root>/AMK_bEnable' */
          controller_Y.AMK_bEnable = 0U;

          /* Outport: '<Root>/AMK_bErrorReset' */
          controller_Y.AMK_bErrorReset = 0U;

          /* Outport: '<Root>/AMK_TargetVelocity' */
          controller_Y.AMK_TargetVelocity = 0;

          /* Outport: '<Root>/AMK_TorqueLimitPositiv' */
          controller_Y.AMK_TorqueLimitPositiv = 0;

          /* Outport: '<Root>/AMK_TorqueLimitNegativ' */
          controller_Y.AMK_TorqueLimitNegativ = 0;
        } else if (controller_U.AMK_bError) {
          controller_DW.is_AMK_shutdown = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_c3_motor_interface_lib =
            controller_IN_AMK_errorDetected;
          controller_B.MI_motorStatus = MI_STS_ERROR;
        }
        break;
      }
      break;

     case controller_IN_AMK_startup:
      switch (controller_DW.is_AMK_startup) {
       case controller_IN_commandOn:
        /* Outport: '<Root>/AMK_bEnable' */
        controller_Y.AMK_bEnable = 1U;

        /* Outport: '<Root>/AMK_bInverterOn_tx' */
        controller_Y.AMK_bInverterOn_tx = 1U;
        if (controller_U.AMK_bInverterOn && controller_U.AMK_bQuitInverterOn) {
          controller_DW.is_AMK_startup = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_c3_motor_interface_lib = controller_IN_AMK_running;
        } else if (controller_U.AMK_bError) {
          controller_DW.is_AMK_startup = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_c3_motor_interface_lib =
            controller_IN_AMK_errorDetected;
          controller_B.MI_motorStatus = MI_STS_ERROR;
        }
        break;

       case control_IN_enforceSetpointsZero:
        if (controller_DW.temporalCounter_i1 >= 100U) {
          controller_DW.is_AMK_startup = controller_IN_commandOn;

          /* Outport: '<Root>/AMK_bEnable' */
          controller_Y.AMK_bEnable = 1U;

          /* Outport: '<Root>/AMK_bInverterOn_tx' */
          controller_Y.AMK_bInverterOn_tx = 1U;
        } else if (controller_U.AMK_bError) {
          controller_DW.is_AMK_startup = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_c3_motor_interface_lib =
            controller_IN_AMK_errorDetected;
          controller_B.MI_motorStatus = MI_STS_ERROR;
        }
        break;

       case controller_IN_toggleDCon:
        /* Outport: '<Root>/AMK_bDcOn_tx' */
        controller_Y.AMK_bDcOn_tx = 1U;
        if (controller_U.AMK_bDcOn && controller_U.AMK_bQuitDcOn) {
          controller_DW.is_AMK_startup = control_IN_enforceSetpointsZero;
          controller_DW.temporalCounter_i1 = 0U;

          /* Outport: '<Root>/AMK_TargetVelocity' */
          controller_Y.AMK_TargetVelocity = 0;

          /* Outport: '<Root>/AMK_TorqueLimitPositiv' */
          controller_Y.AMK_TorqueLimitPositiv = 0;

          /* Outport: '<Root>/AMK_TorqueLimitNegativ' */
          controller_Y.AMK_TorqueLimitNegativ = 0;
        } else if (controller_U.AMK_bError) {
          controller_DW.is_AMK_startup = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_c3_motor_interface_lib =
            controller_IN_AMK_errorDetected;
          controller_B.MI_motorStatus = MI_STS_ERROR;
        }
        break;

       default:
        /* case IN_waiting_sysReady: */
        if (controller_U.AMK_bSystemReady) {
          controller_DW.is_AMK_startup = controller_IN_toggleDCon;

          /* Outport: '<Root>/AMK_bDcOn_tx' */
          controller_Y.AMK_bDcOn_tx = 1U;
        } else if (controller_U.AMK_bError) {
          controller_DW.is_AMK_startup = controller_IN_NO_ACTIVE_CHILD;
          controller_DW.is_c3_motor_interface_lib =
            controller_IN_AMK_errorDetected;
          controller_B.MI_motorStatus = MI_STS_ERROR;
        }
        break;
      }
      break;

     default:
      /* Outport: '<Root>/AMK_bInverterOn_tx' */
      /* case IN_motorOff_waitingForGov: */
      controller_Y.AMK_bInverterOn_tx = 0U;

      /* Outport: '<Root>/AMK_bDcOn_tx' */
      controller_Y.AMK_bDcOn_tx = 0U;

      /* Outport: '<Root>/AMK_bEnable' */
      controller_Y.AMK_bEnable = 0U;

      /* Outport: '<Root>/AMK_bErrorReset' */
      controller_Y.AMK_bErrorReset = 0U;
      if (controller_B.GOV_e_miCmd == CMD_STARTUP) {
        controller_DW.is_c3_motor_interface_lib = controller_IN_AMK_startup;
        controller_DW.is_AMK_startup = controller_IN_waiting_sysReady;
        controller_B.MI_motorStatus = STARTUP;
      }
      break;
    }
  }

  /* End of Chart: '<S4>/RIGHT_MOTOR' */

  /* Chart: '<S1>/Chart' incorporates:
   *  Delay: '<S3>/Delay'
   *  Inport: '<Root>/BM_b_HVnegContactorSts'
   *  Inport: '<Root>/BM_b_HVposContactorSts'
   *  Inport: '<Root>/BM_b_prechrgContactorSts'
   */
  if (controller_DW.temporalCounter_i1_p < 127U) {
    controller_DW.temporalCounter_i1_p++;
  }

  if (controller_DW.is_active_c3_battery_monitor_li == 0U) {
    controller_DW.is_active_c3_battery_monitor_li = 1U;
    controller_DW.is_c3_battery_monitor_lib = controller_IN_InitialState;
    controller_DW.Delay_DSTATE_f = BM_INIT;
  } else {
    switch (controller_DW.is_c3_battery_monitor_lib) {
     case controll_IN_ErrorAllClosedState:
      controller_DW.Delay_DSTATE_f = ERR_ALL_CLOSED;
      break;

     case controller_IN_ErrorHVPositive:
      controller_DW.Delay_DSTATE_f = ERR_HV_POSITIVE;
      break;

     case IN_ErrorInitializePrechargeStat:
      controller_DW.Delay_DSTATE_f = ERR_INIT_PRECHARGE;
      break;

     case co_IN_ErrorPrechargeClosedState:
      controller_DW.Delay_DSTATE_f = ERR_PRECHARGE_CLOSED;
      break;

     case controll_IN_ErrorPrechargeState:
      controller_DW.Delay_DSTATE_f = ERR_PRECHARGE;
      break;

     case controller_IN_ErrorRunningState:
      controller_DW.Delay_DSTATE_f = ERR_RUNNING;
      break;

     case controller_IN_ErrorStartupState:
      controller_DW.Delay_DSTATE_f = ERR_STARTUP;
      break;

     case controller_IN_InitialState:
      {
        boolean_T tmp_0;
        boolean_T tmp_1;
        boolean_T tmp_2;
        controller_DW.Delay_DSTATE_f = BM_INIT;
        tmp_0 = !controller_U.BM_b_HVnegContactorSts;
        tmp_1 = !controller_U.BM_b_HVposContactorSts;
        tmp_2 = ((!controller_U.BM_b_prechrgContactorSts) && tmp_0);
        if (tmp_2 && tmp_1) {
          controller_DW.is_c3_battery_monitor_lib = controller_IN_StartupState1;
          controller_DW.Delay_DSTATE_f = BM_IDLE;
        } else if (controller_U.BM_b_prechrgContactorSts && tmp_0 && tmp_1) {
          controller_DW.is_c3_battery_monitor_lib =
            co_IN_ErrorPrechargeClosedState;
          controller_DW.Delay_DSTATE_f = ERR_PRECHARGE_CLOSED;
        } else {
          tmp_0 = (controller_U.BM_b_prechrgContactorSts &&
                   controller_U.BM_b_HVnegContactorSts);
          if (tmp_0 && controller_U.BM_b_HVposContactorSts) {
            controller_DW.is_c3_battery_monitor_lib =
              controll_IN_ErrorAllClosedState;
            controller_DW.Delay_DSTATE_f = ERR_ALL_CLOSED;
          } else if (tmp_2 && controller_U.BM_b_HVposContactorSts) {
            controller_DW.is_c3_battery_monitor_lib =
              controller_IN_ErrorHVPositive;
            controller_DW.Delay_DSTATE_f = ERR_HV_POSITIVE;
          } else if (tmp_0 && tmp_1) {
            controller_DW.is_c3_battery_monitor_lib =
              controller_IN_PrechargeState;
            controller_DW.temporalCounter_i1_p = 0U;
            controller_DW.Delay_DSTATE_f = PRECHARGE;
          } else if ((!controller_U.BM_b_prechrgContactorSts) &&
                     controller_U.BM_b_HVnegContactorSts &&
                     controller_U.BM_b_HVposContactorSts) {
            controller_DW.is_c3_battery_monitor_lib = controller_IN_RunningState;
            controller_DW.temporalCounter_i1_p = 0U;
            controller_DW.Delay_DSTATE_f = BM_RUNNING;
          }
        }
      }
      break;

     case con_IN_InitializePrechargeState:
      controller_DW.Delay_DSTATE_f = INIT_PRECHARGE;
      if (controller_U.BM_b_prechrgContactorSts &&
          controller_U.BM_b_HVnegContactorSts &&
          controller_U.BM_b_HVposContactorSts) {
        controller_DW.is_c3_battery_monitor_lib = controller_IN_PrechargeState;
        controller_DW.temporalCounter_i1_p = 0U;
        controller_DW.Delay_DSTATE_f = PRECHARGE;
      } else if (controller_DW.temporalCounter_i1_p >= 100U) {
        controller_DW.is_c3_battery_monitor_lib =
          IN_ErrorInitializePrechargeStat;
        controller_DW.Delay_DSTATE_f = ERR_INIT_PRECHARGE;
      }
      break;

     case controller_IN_PrechargeState:
      controller_DW.Delay_DSTATE_f = PRECHARGE;
      if ((!controller_U.BM_b_prechrgContactorSts) &&
          controller_U.BM_b_HVnegContactorSts &&
          controller_U.BM_b_HVposContactorSts) {
        controller_DW.is_c3_battery_monitor_lib = controller_IN_RunningState;
        controller_DW.temporalCounter_i1_p = 0U;
        controller_DW.Delay_DSTATE_f = BM_RUNNING;
      } else if (controller_DW.temporalCounter_i1_p >= 100U) {
        controller_DW.is_c3_battery_monitor_lib =
          controll_IN_ErrorPrechargeState;
        controller_DW.Delay_DSTATE_f = ERR_PRECHARGE;
      }
      break;

     case controller_IN_RunningState:
      controller_DW.Delay_DSTATE_f = BM_RUNNING;
      if ((!controller_U.BM_b_prechrgContactorSts) &&
          controller_U.BM_b_HVnegContactorSts &&
          controller_U.BM_b_HVposContactorSts) {
        controller_DW.is_c3_battery_monitor_lib = controller_IN_RunningState;
        controller_DW.temporalCounter_i1_p = 0U;
        controller_DW.Delay_DSTATE_f = BM_RUNNING;
      } else if (controller_DW.temporalCounter_i1_p >= 100U) {
        controller_DW.is_c3_battery_monitor_lib =
          controller_IN_ErrorRunningState;
        controller_DW.Delay_DSTATE_f = ERR_RUNNING;
      }
      break;

     case controller_IN_StartupState:
      controller_DW.Delay_DSTATE_f = BM_STARTUP;
      if (controller_U.BM_b_prechrgContactorSts &&
          controller_U.BM_b_HVnegContactorSts &&
          (!controller_U.BM_b_HVposContactorSts)) {
        controller_DW.is_c3_battery_monitor_lib =
          con_IN_InitializePrechargeState;
        controller_DW.temporalCounter_i1_p = 0U;
        controller_DW.Delay_DSTATE_f = INIT_PRECHARGE;
      } else if (controller_DW.temporalCounter_i1_p >= 100U) {
        controller_DW.is_c3_battery_monitor_lib =
          controller_IN_ErrorStartupState;
        controller_DW.Delay_DSTATE_f = ERR_STARTUP;
      }
      break;

     default:
      /* case IN_StartupState1: */
      controller_DW.Delay_DSTATE_f = BM_IDLE;
      if ((!controller_U.BM_b_prechrgContactorSts) &&
          controller_U.BM_b_HVnegContactorSts &&
          (!controller_U.BM_b_HVposContactorSts)) {
        controller_DW.is_c3_battery_monitor_lib = controller_IN_StartupState;
        controller_DW.temporalCounter_i1_p = 0U;
        controller_DW.Delay_DSTATE_f = BM_STARTUP;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Delay: '<S3>/Delay1'
   *  RelationalOperator: '<S4>/motorErrorActive'
   *  Switch: '<S4>/Switch1'
   */
  if (controller_B.MI_motorStatus == MI_STS_ERROR) {
    controller_DW.Delay1_DSTATE = MI_STS_ERROR;
  } else {
    controller_DW.Delay1_DSTATE = controller_B.MI_motorStatus;
  }

  /* End of Switch: '<S4>/Switch' */
}

/* Model initialize function */
void controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

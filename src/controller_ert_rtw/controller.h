/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller.h
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jan 31 17:09:28 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_h_
#define RTW_HEADER_controller_h_
#ifndef controller_COMMON_INCLUDES_
#define controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* controller_COMMON_INCLUDES_ */

#include "controller_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  MI_STATUSES MI_motorStatus;          /* '<S4>/RIGHT_MOTOR' */
  MI_CMD GOV_e_miCmd;                  /* '<S3>/Chart' */
  DI_CMD GOV_e_diCmd;                  /* '<S3>/Chart' */
  boolean_T b_ReadyToDrive;            /* '<S2>/Chart' */
} B_controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  MI_STATUSES Delay1_DSTATE;           /* '<S3>/Delay1' */
  BM_STATUSES Delay_DSTATE_f;          /* '<S3>/Delay' */
  DI_STATUSES Delay2_DSTATE;           /* '<S3>/Delay2' */
  uint16_T motorStartCount;            /* '<S3>/Chart' */
  uint8_T is_c3_motor_interface_lib;   /* '<S4>/RIGHT_MOTOR' */
  uint8_T is_AMK_startup;              /* '<S4>/RIGHT_MOTOR' */
  uint8_T is_AMK_errorReset;           /* '<S4>/RIGHT_MOTOR' */
  uint8_T is_AMK_shutdown;             /* '<S4>/RIGHT_MOTOR' */
  uint8_T is_active_c3_motor_interface_li;/* '<S4>/RIGHT_MOTOR' */
  uint8_T temporalCounter_i1;          /* '<S4>/RIGHT_MOTOR' */
  uint8_T is_c3_governor_lib;          /* '<S3>/Chart' */
  uint8_T is_STARTUP;                  /* '<S3>/Chart' */
  uint8_T is_STARTUP_ERROR;            /* '<S3>/Chart' */
  uint8_T is_RUNNING_ERROR;            /* '<S3>/Chart' */
  uint8_T is_active_c3_governor_lib;   /* '<S3>/Chart' */
  uint8_T is_c3_driver_interface_lib;  /* '<S2>/Chart' */
  uint8_T is_DI_running;               /* '<S2>/Chart' */
  uint8_T is_Ready_to_drive;           /* '<S2>/Chart' */
  uint8_T is_active_c3_driver_interface_l;/* '<S2>/Chart' */
  uint8_T temporalCounter_i1_a;        /* '<S2>/Chart' */
  uint8_T is_c3_battery_monitor_lib;   /* '<S1>/Chart' */
  uint8_T is_active_c3_battery_monitor_li;/* '<S1>/Chart' */
  uint8_T temporalCounter_i1_p;        /* '<S1>/Chart' */
} DW_controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T DataTypeConversion1;  /* '<S12>/Data Type Conversion1' */
  const real32_T DataTypeConversion2;  /* '<S12>/Data Type Conversion2' */
  const real32_T Subtract1;            /* '<S18>/Subtract1' */
  const real32_T DataTypeConversion;   /* '<S12>/Data Type Conversion' */
  const real32_T range;                /* '<S18>/Subtract' */
  const real32_T Divide;               /* '<S18>/Divide' */
  const real32_T Gain;                 /* '<S18>/Gain' */
  const real32_T DataTypeConversion_f; /* '<S11>/Data Type Conversion' */
  const real32_T DataTypeConversion2_p;/* '<S11>/Data Type Conversion2' */
  const real32_T range_p;              /* '<S16>/Subtract' */
  const real32_T DataTypeConversion1_p;/* '<S13>/Data Type Conversion1' */
  const real32_T DataTypeConversion2_l;/* '<S13>/Data Type Conversion2' */
  const real32_T Subtract1_e;          /* '<S20>/Subtract1' */
  const real32_T DataTypeConversion_b; /* '<S13>/Data Type Conversion' */
  const real32_T range_o;              /* '<S20>/Subtract' */
  const real32_T Divide_h;             /* '<S20>/Divide' */
  const real32_T Gain_c;               /* '<S20>/Gain' */
  const real32_T Switch2;              /* '<S2>/Switch2' */
  const real32_T Gain3;                /* '<S4>/Gain3' */
  const real32_T Gain1;                /* '<S5>/Gain1' */
  const int16_T DataTypeConversion1_l; /* '<S4>/Data Type Conversion1' */
  const int16_T DataTypeConversion2_d; /* '<S4>/Data Type Conversion2' */
  const boolean_T LowerTest;           /* '<S19>/Lower Test' */
  const boolean_T UpperTest;           /* '<S19>/Upper Test' */
  const boolean_T FixPtLogicalOperator;/* '<S19>/FixPt Logical Operator' */
  const boolean_T NOT;                 /* '<S13>/NOT' */
} ConstB_controller_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [0 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95 100])
   * Referenced by: '<S2>/AccelPedalPos1 LUT'
   */
  real32_T pooled2[21];
} ConstP_controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T AMK_bReserve;              /* '<Root>/AMK_bReserve' */
  int16_T DI_V_SteeringAngle;          /* '<Root>/DI_V_SteeringAngle' */
  int16_T DI_V_BrakePedalPos;          /* '<Root>/DI_V_BrakePedalPos' */
  boolean_T DI_b_DriverButton;         /* '<Root>/DI_b_DriverButton' */
  int16_T DI_V_AccelPedalPos1;         /* '<Root>/DI_V_AccelPedalPos1' */
  int16_T DI_V_AccelPedalPos2;         /* '<Root>/DI_V_AccelPedalPos2' */
  boolean_T BM_b_prechrgContactorSts;  /* '<Root>/BM_b_prechrgContactorSts' */
  boolean_T BM_b_HVposContactorSts;    /* '<Root>/BM_b_HVposContactorSts' */
  boolean_T BM_b_HVnegContactorSts;    /* '<Root>/BM_b_HVnegContactorSts' */
  boolean_T AMK_bSystemReady;          /* '<Root>/AMK_bSystemReady' */
  boolean_T AMK_bError;                /* '<Root>/AMK_bError' */
  boolean_T AMK_bWarn;                 /* '<Root>/AMK_bWarn' */
  boolean_T AMK_bQuitDcOn;             /* '<Root>/AMK_bQuitDcOn' */
  boolean_T AMK_bDcOn;                 /* '<Root>/AMK_bDcOn' */
  boolean_T AMK_bQuitInverterOn;       /* '<Root>/AMK_bQuitInverterOn' */
  boolean_T AMK_bInverterOn;           /* '<Root>/AMK_bInverterOn' */
  boolean_T AMK_bDerating;             /* '<Root>/AMK_bDerating' */
  int16_T AMK_TempMotor;               /* '<Root>/AMK_TempMotor' */
  int16_T AMK_TempInverter;            /* '<Root>/AMK_TempInverter' */
  uint16_T AMK_ErrorInfo;              /* '<Root>/AMK_ErrorInfo' */
  int16_T AMK_TempIGBT;                /* '<Root>/AMK_TempIGBT' */
  int16_T AMK_ActualVelocity;          /* '<Root>/AMK_ActualVelocity' */
  int16_T AMK_TorqueCurrent;           /* '<Root>/AMK_TorqueCurrent' */
  int16_T AMK_MagnetizingCurrent;      /* '<Root>/AMK_MagnetizingCurrent' */
} ExtU_controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T ptCAN_AMK_Setpoints1_Left;  /* '<Root>/ptCAN_AMK_Setpoints1_Left' */
  boolean_T DI_b_driverSpeaker;        /* '<Root>/DI_b_driverSpeaker' */
  uint8_T AMK_bInverterOn_tx;          /* '<Root>/AMK_bInverterOn_tx' */
  uint8_T AMK_bDcOn_tx;                /* '<Root>/AMK_bDcOn_tx' */
  uint8_T AMK_bEnable;                 /* '<Root>/AMK_bEnable' */
  uint8_T AMK_bErrorReset;             /* '<Root>/AMK_bErrorReset' */
  int16_T AMK_TargetVelocity;          /* '<Root>/AMK_TargetVelocity' */
  int16_T AMK_TorqueLimitPositiv;      /* '<Root>/AMK_TorqueLimitPositiv' */
  int16_T AMK_TorqueLimitNegativ;      /* '<Root>/AMK_TorqueLimitNegativ' */
} ExtY_controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_controller_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_controller_T controller_B;

/* Block states (default storage) */
extern DW_controller_T controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_controller_T controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_controller_T controller_Y;
extern const ConstB_controller_T controller_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_controller_T controller_ConstP;

/* Model entry point functions */
extern void controller_initialize(void);
extern void controller_step(void);
extern void controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_controller_T *const controller_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/Constant2' : Unused code path elimination
 * Block '<S2>/AND' : Unused code path elimination
 * Block '<S2>/Constant2' : Unused code path elimination
 * Block '<S2>/Constant6' : Unused code path elimination
 * Block '<S2>/OR' : Unused code path elimination
 * Block '<S2>/Switch1' : Unused code path elimination
 * Block '<S15>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/FixPt Logical Operator' : Unused code path elimination
 * Block '<S17>/Lower Test' : Unused code path elimination
 * Block '<S17>/Upper Test' : Unused code path elimination
 * Block '<S12>/NOT' : Unused code path elimination
 * Block '<S19>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Conversion' : Unused code path elimination
 * Block '<S14>/Data Type Conversion1' : Unused code path elimination
 * Block '<S14>/Data Type Conversion2' : Unused code path elimination
 * Block '<S21>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/FixPt Logical Operator' : Unused code path elimination
 * Block '<S21>/Lower Test' : Unused code path elimination
 * Block '<S21>/Upper Test' : Unused code path elimination
 * Block '<S14>/LowerPotentiometerLimit1' : Unused code path elimination
 * Block '<S14>/NOT' : Unused code path elimination
 * Block '<S14>/UpperPotentiometerLimit1' : Unused code path elimination
 * Block '<S22>/Divide' : Unused code path elimination
 * Block '<S22>/Gain' : Unused code path elimination
 * Block '<S22>/Subtract' : Unused code path elimination
 * Block '<S22>/Subtract1' : Unused code path elimination
 * Block '<S5>/MaxAMKspeed1' : Unused code path elimination
 * Block '<S5>/MaxBatteryCurrent1' : Unused code path elimination
 * Block '<S5>/MaxBatteryCurrent2' : Unused code path elimination
 * Block '<S5>/MaxBatteryCurrent3' : Unused code path elimination
 * Block '<S5>/NegTorqueLimit1' : Unused code path elimination
 * Block '<S28>/Constant1' : Unused code path elimination
 * Block '<S29>/Constant' : Unused code path elimination
 * Block '<S31>/Constant' : Unused code path elimination
 * Block '<S5>/convertToAmps' : Unused code path elimination
 * Block '<S5>/convertToAmps1' : Unused code path elimination
 * Block '<S5>/convertToAmps2' : Unused code path elimination
 * Block '<S5>/latAccel' : Unused code path elimination
 * Block '<S5>/longAccel' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'controller'
 * '<S1>'   : 'controller/battery_monitor'
 * '<S2>'   : 'controller/driver_interface'
 * '<S3>'   : 'controller/governor'
 * '<S4>'   : 'controller/motor_interface'
 * '<S5>'   : 'controller/vehicle_dynamics'
 * '<S6>'   : 'controller/battery_monitor/Chart'
 * '<S7>'   : 'controller/driver_interface/Chart'
 * '<S8>'   : 'controller/driver_interface/If Action Subsystem'
 * '<S9>'   : 'controller/driver_interface/If Action Subsystem1'
 * '<S10>'  : 'controller/driver_interface/If Action Subsystem2'
 * '<S11>'  : 'controller/driver_interface/potentiometerProcessing'
 * '<S12>'  : 'controller/driver_interface/potentiometerProcessing1'
 * '<S13>'  : 'controller/driver_interface/potentiometerProcessing2'
 * '<S14>'  : 'controller/driver_interface/potentiometerProcessing3'
 * '<S15>'  : 'controller/driver_interface/potentiometerProcessing/Interval Test Dynamic'
 * '<S16>'  : 'controller/driver_interface/potentiometerProcessing/convertToPercent'
 * '<S17>'  : 'controller/driver_interface/potentiometerProcessing1/Interval Test Dynamic'
 * '<S18>'  : 'controller/driver_interface/potentiometerProcessing1/convertToPercent'
 * '<S19>'  : 'controller/driver_interface/potentiometerProcessing2/Interval Test Dynamic'
 * '<S20>'  : 'controller/driver_interface/potentiometerProcessing2/convertToPercent'
 * '<S21>'  : 'controller/driver_interface/potentiometerProcessing3/Interval Test Dynamic'
 * '<S22>'  : 'controller/driver_interface/potentiometerProcessing3/convertToPercent'
 * '<S23>'  : 'controller/governor/Chart'
 * '<S24>'  : 'controller/motor_interface/RIGHT_MOTOR'
 * '<S25>'  : 'controller/motor_interface/convertToAmps'
 * '<S26>'  : 'controller/motor_interface/convertToAmps1'
 * '<S27>'  : 'controller/vehicle_dynamics/RIGHT_LIMIT'
 * '<S28>'  : 'controller/vehicle_dynamics/TorqueVectoring'
 * '<S29>'  : 'controller/vehicle_dynamics/TractionControlSystem_LEFT'
 * '<S30>'  : 'controller/vehicle_dynamics/TractionControlSystem_RIGHT'
 * '<S31>'  : 'controller/vehicle_dynamics/VelocityEstimation'
 */
#endif                                 /* RTW_HEADER_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

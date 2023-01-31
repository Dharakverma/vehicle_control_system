/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_types.h
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

#ifndef RTW_HEADER_controller_types_h_
#define RTW_HEADER_controller_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_MI_STATUSES_
#define DEFINED_TYPEDEF_FOR_MI_STATUSES_

typedef enum {
  UNKNOWN = 0,                         /* Default value */
  STS_INIT,
  STARTUP,
  RUNNING,
  SHUTDOWN,
  MI_STS_ERROR,
  OFF
} MI_STATUSES;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BM_STATUSES_
#define DEFINED_TYPEDEF_FOR_BM_STATUSES_

typedef enum {
  BM_UNKNOWN = 0,                      /* Default value */
  BM_INIT,
  BM_IDLE,
  BM_STARTUP,
  INIT_PRECHARGE,
  PRECHARGE,
  BM_RUNNING,
  ERR_PRECHARGE_CLOSED,
  ERR_STARTUP,
  ERR_INIT_PRECHARGE,
  ERR_PRECHARGE,
  ERR_RUNNING,
  ERR_ALL_CLOSED,
  ERR_HV_POSITIVE
} BM_STATUSES;

#endif

#ifndef DEFINED_TYPEDEF_FOR_DI_CMD_
#define DEFINED_TYPEDEF_FOR_DI_CMD_

typedef enum {
  DI_CMD_INIT = 0,                     /* Default value */
  READY_TO_DRIVE,
  SYSTEM_ERROR,
  DI_ERR_RESET
} DI_CMD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_DI_STATUSES_
#define DEFINED_TYPEDEF_FOR_DI_STATUSES_

typedef enum {
  DI_UNKNOWN = 0,                      /* Default value */
  DI_STS_INIT,
  DI_IDLE,
  DI_STARTUP,
  WAITING_FOR_DRVR,
  DRV_START_REQ,
  DI_RUNNING,
  DI_ERROR
} DI_STATUSES;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MI_CMD_
#define DEFINED_TYPEDEF_FOR_MI_CMD_

typedef enum {
  CMD_INIT = 0,                        /* Default value */
  IDLE,
  CMD_STARTUP,
  CMD_SHUTDOWN,
  ERR_RESET
} MI_CMD;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_controller_T RT_MODEL_controller_T;

#endif                                 /* RTW_HEADER_controller_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

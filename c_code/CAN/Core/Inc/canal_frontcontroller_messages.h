/*
 * canal_frontcontroller_messages.h
 *
 *  Created on: Dec 28, 2022
 *      Authors: Samuel Parent, Abhishek Magdum, Lin Fu
 *
 *                    ..::^~~~!!~~~^^:..
 *                .:^!7??JJJJJJJJJJJJ??7!~:.
 *              :~7?JJJ???????????????JJJJ??!^.
 *           .^7?JJJ???JJJJJJ??????????????JJJ?~:
 *          ^7JJ???????777777???JJJJJJJ???????JJ?~.
 *        .!JJ???????????7!~^::::^~!!7??JJ???????J7:
 *       :7JJJ??????????JJJJ??7~:    ..:~7?J??????J?^
 *      .7J???????????????????JJ?!.       :7J??????J?^
 *     .~J??????????????????JJJJ?!.       .7J???????J7.
 *     :?J?????????????JJJJ??7!^.      .:~???????????J~
 *     ^???????????JJJ??7~^:..      .:~7?JJ??????????J!.
 *     ^????????JJ?7~^:.        .:~!?JJJ?????????????J!.
 *     ^????????!^.          .:~7?JJJ????????????????J!.
 *     .7J????!.            :7?JJ?????????????????????^
 *      ~JJ?J7.             ~JJJJ???????????????????J!.
 *      .!J???^.            .^!7?JJJJJJ????????????J7:
 *       .!?J??7^.              .:^~!7???JJJJJ????J7:
 *        .^?JJJJ?7~.                 ..:^~~!7????!.
 *          .!?JJJJ?:                         ..::
 *            :~??!:
 *              ..
 */

#ifndef INC_CANAL_FRONTCONTROLLER_MESSAGES_H_
#define INC_CANAL_FRONTCONTROLLER_MESSAGES_H_

/*********************************************************
*                       INCLUDES
*********************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "canal_types.h"

/*********************************************************
*                        ENUMS
*********************************************************/

typedef enum {
    UNKNOWN_CAN_ID = 0,
    AMK_SETPOINTS_CAN_ID = ((uint32_t) 0x240), //this one is a test
    AMK0_STS_CAN_ID = ((uint32_t) 0x284),
    AMK1_STS_CAN_ID = ((uint32_t) 0x285),
    AMK0_TEMPS_CAN_ID = ((uint32_t) 0x286),
    AMK1_TEMPS_CAN_ID = ((uint32_t) 0x287),
} TeMessageID;

/*********************************************************
*                     MESSAGE STRUCTS
*********************************************************/


typedef struct test{ //this one is a test
    uint16_t AMK_TargetVelocity;
    _Bool bEnable;
}TsAMKSetpoints;

typedef struct AMK_STS{
    _Bool       AMK_bSystemReady;
    _Bool       AMK_bError;
    _Bool       AMK_bWarn;
    _Bool       AMK_bQuitDcOn;
    _Bool       AMK_bDcOn;
    _Bool       AMK_bQuitInvertorOn;
    _Bool       AMK_bInverterOn;
    _Bool       AMK_bDerating;
    uint16_t    AMK_ActualVelocity;
    uint16_t    AMK_TorqueCurrent;
    uint16_t    AMK_magnetizingCurrent;
}TsAMK_STS;

// typedef struct AMK1_STS{
//     _Bool       AMK1_bSystemReady;
//     _Bool       AMK1_bError;
//     _Bool       AMK1_bWarn;
//     _Bool       AMK1_bQuitDcOn;
//     _Bool       AMK1_bDcOn;
//     _Bool       AMK1_bQuitInvertorOn;
//     _Bool       AMK1_bInverterOn;
//     _Bool       AMK1_bDerating;
//     uint16_t    AMK1_ActualVelocity;
//     uint16_t    AMK1_TorqueCurrent;
//     uint16_t    AMK1_magnetizingCurrent;
// }TsAMK1_STS;

typedef struct AMK_TEMPS{
    uint16_t AMK_TempMotor;
    uint16_t AMK_TempInverter;
    uint16_t AMK_ErrorInfo;
    uint16_t AMK_TempIGBT;
}TsAMK_TEMPS;

// typedef struct AMK1_TEMPS{
//     uint16_t AMK1_TempMotor;
//     uint16_t AMK1_TempInverter;
//     uint16_t AMK1_ErrorInfo;
//     uint16_t AMK1_TempIGBT;
// }TsAMK1_TEMPS;

/*********************************************************
*                       MESSAGE MACROS
*********************************************************/
#define NUM_RX_MESSAGES (5U) // 1 test + 4 actual
#define NUM_TX_MESSAGES (1U)

#define AMK_SETPOINTS_ENDIANNESS (CAN_LITTLE_ENDIAN)
#define AMK_STS_ENDIANNESS (CAN_LITTLE_ENDIAN)
#define AMK_TEMPS_ENDIANNESS (CAN_LITTLE_ENDIAN)


/*********************************************************
*                       SIGNAL MACROS
*********************************************************/

// AMK_Setpoints: AMK_TempMotor
#define AMK_SETPOINTS_AMK_TARGETVELOCITY_START   (24U)
#define AMK_SETPOINTS_AMK_TARGETVELOCITY_LENGTH  (16U)
#define AMK_SETPOINTS_AMK_TARGETVELOCITY_FACTOR  (0.125)
#define AMK_SETPOINTS_AMK_TARGETVELOCITY_OFFSET  (0U)

// AMK ACTUAL VALUES 1
#define AMK_STS_bSystemReady_START  (8U)
#define AMK_STS_bSystemReady_LENGTH (1U)
// #define AMK_STS_bSystemReady_FACTOR (0U)
// #define AMK_STS_bSystemReady_OFFSET (0U)

#define AMK_STS_bError_START  (9U)
#define AMK_STS_bError_LENGTH (1U)
// #define AMK_STS_bError_FACTOR (0U)
// #define AMK_STS_bError_OFFSET (0U)

#define AMK_STS_bWarn_START  (10U)
#define AMK_STS_bWarn_LENGTH (1U)
// #define AMK_STS_bWarn_FACTOR (0U)
// #define AMK_STS_bWarn_OFFSET (0U)

#define AMK_STS_bQuitDCOn_START  (11U)
#define AMK_STS_bQuitDCOn_LENGTH (1U)
// #define AMK_STS_bQuitDCOn_FACTOR (0U)
// #define AMK_STS_bQuitDCOn_OFFSET (0U)

#define AMK_STS_bDcOn_START  (12U)
#define AMK_STS_bDcOn_LENGTH (1U)
// #define AMK_STS_bDcOn_FACTOR (0U)
// #define AMK_STS_bDcOn_OFFSET (0U)

#define AMK_STS_bQuitInverterOn_START  (13U)
#define AMK_STS_bQuitInverterOn_LENGTH (1U)
// #define AMK_STS_bQuitInverterOn_FACTOR (0U)
// #define AMK_STS_bQuitInverterOn_OFFSET (0U)

#define AMK_STS_bInverterOn_START   (14U)
#define AMK_STS_bInverterOn_LENGTH  (1U)
// #define AMK_STS_bInverterOn_FACTOR  (0U)
// #define AMK_STS_bInverterOn_OFFSET  (0U)

#define AMK_STS_bDerating_START  (15U)
#define AMK_STS_bDerating_LENGTH (1U)
// #define AMK_STS_bDerating_FACTOR (0U)
// #define AMK_STS_bDerating_OFFSET (0U)

#define AMK_STS_ActualVelocity_START  (16U)
#define AMK_STS_ActualVelocity_LENGTH (16U)
// #define AMK_STS_bActualVelocity_FACTOR (0U)
// #define AMK_STS_bActualVelocity_OFFSET (0U)

#define AMK_STS_TorqueCurrent_START  (32U)
#define AMK_STS_TorqueCurrent_LENGTH (16U)
// #define AMK_STS_bTorqueCurrent_FACTOR (0U)
// #define AMK_STS_bTorqueCurrent_OFFSET (0U)

#define AMK_STS_MagnetizingCurrent_START  (48U)
#define AMK_STS_MagnetizingCurrent_LENGTH (16U)
// #define AMK_STS_bMagnetizingCurrent_FACTOR (0U)
// #define AMK_STS_bMagnetizingCurrent_OFFSET (0U)

// AMK ACTUAL VALUES 2
#define AMK_TEMPS_TempMotor_START  (0U)
#define AMK_TEMPS_TempMotor_LENGTH (16U)
// #define AMK_TEMPS_TempMotor_FACTOR (0U)
// #define AMK_TEMPS_TempMotor_OFFSET (0U)

#define AMK_TEMPS_TempInverter_START  (16U)
#define AMK_TEMPS_TempInverter_LENGTH (16U)
// #define AMK_TEMPS_TempInverter_FACTOR (0U)
// #define AMK_TEMPS_TempInverter_OFFSET (0U)

#define AMK_TEMPS_Error_START  (32U)
#define AMK_TEMPS_Error_LENGTH (16U)
// #define AMK_TEMPS_Error_FACTOR (0U)
// #define AMK_TEMPS_Error_OFFSET (0U)

#define AMK_TEMPS_TempIGBT_START  (48U)
#define AMK_TEMPS_TempIGBT_LENGTH (16U)
// #define AMK_TEMPS_TempIGBT_FACTOR (0U)
// #define AMK_TEMPS_TempIGBT_OFFSET (0U)


/*********************************************************
*                 GLOBAL STRUCT INSTANCES
*********************************************************/

extern TsAMKSetpoints AMK_Setpoints;
extern TsAMK_STS AMK0_STS, AMK1_STS;
extern TsAMK_TEMPS AMK0_TEMPS, AMK1_TEMPS;

/*********************************************************
*               PUBLIC FUNCTION DECLARATIONS
*********************************************************/

TeCanALRet GetBinaryUnmarshaller(uint32_t* ID, BinaryUnmarshaller** pUnmarshal);
TeCanALRet GetBinaryMarshaller(TeMessageID* ID, BinaryMarshaller** pMarshal);

#endif /* INC_CANAL_FRONTCONTROLLER_MESSAGES_H_ */

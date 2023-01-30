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
    AMK0_STS = ((uint32_t) 0x284),
    AMK1_STS = ((uint32_t) 0x285),
    AMK0_TEMPS = ((uint32_t) 0x286),
    AMK1_TEMPS = ((uint32_t) 0x287),
} TeMessageID;

/*********************************************************
*                     MESSAGE STRUCTS
*********************************************************/


typedef struct test{ //this one is a test
    uint16_t AMK_TargetVelocity;
    _Bool bEnable;
}TsAMKSetpoints;

typedef struct AMK0_STS{
    _Bool       AMK0_bSystemReady;
    _Bool       AMK0_bError;
    _Bool       AMK0_bWarn;
    _Bool       AMK0_bQuitDcOn;
    _Bool       AMK0_bDcOn;
    _Bool       AMK0_bQuitInvertorOn;
    _Bool       AMK0_bInverterOn;
    _Bool       AMK0_bDerating;
    uint16_t    AMK0_ActualVelocity;
    uint16_t    AMK0_TorqueCurrent;
    uint16_t    AMK0_magnetizingCurrent;
}TsAMK0_STS;

typedef struct AMK1_STS{
    _Bool       AMK1_bSystemReady;
    _Bool       AMK1_bError;
    _Bool       AMK1_bWarn;
    _Bool       AMK1_bQuitDcOn;
    _Bool       AMK1_bDcOn;
    _Bool       AMK1_bQuitInvertorOn;
    _Bool       AMK1_bInverterOn;
    _Bool       AMK1_bDerating;
    uint16_t    AMK1_ActualVelocity;
    uint16_t    AMK1_TorqueCurrent;
    uint16_t    AMK1_magnetizingCurrent;
}TsAMK1_STS;

typedef struct AMK0_TEMPS{
    uint16_t AMK0_TempMotor;
    uint16_t AMK0_TempInverter;
    uint16_t AMK0_ErrorInfo;
    uint16_t AMK0_TempIGBT;
}TsAMK0_TEMPS;

typedef struct AMK1_TEMPS{
    uint16_t AMK1_TempMotor;
    uint16_t AMK1_TempInverter;
    uint16_t AMK1_ErrorInfo;
    uint16_t AMK1_TempIGBT;
}TsAMK1_TEMPS;

/*********************************************************
*                       MESSAGE MACROS
*********************************************************/
#define NUM_RX_MESSAGES (1U)
#define NUM_TX_MESSAGES (1U)

#define AMK_SETPOINTS_ENDIANNESS (CAN_LITTLE_ENDIAN)

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
#define AMK_STS_bSystemReady_FACTOR (0U)
#define AMK_STS_bSystemReady_OFFSET (0U)

#define AMK_STS_bError_START  (9U)
#define AMK_STS_bError_LENGTH (1U)
#define AMK_STS_bError_FACTOR (0U)
#define AMK_STS_bError_OFFSET (0U)

#define AMK_STS_bWarn_START  (10U)
#define AMK_STS_bWarn_LENGTH (1U)
#define AMK_STS_bWarn_FACTOR (0U)
#define AMK_STS_bWarn_OFFSET (0U)

#define AMK_STS_bQuitDCOn_START  (11U)
#define AMK_STS_bQuitDCOn_LENGTH (1U)
#define AMK_STS_bQuitDCOn_FACTOR (0U)
#define AMK_STS_bQuitDCOn_OFFSET (0U)

#define AMK_STS_bDcOn_START  (12U)
#define AMK_STS_bDcOn_LENGTH (1U)
#define AMK_STS_bDcOn_FACTOR (0U)
#define AMK_STS_bDcOn_OFFSET (0U)

#define AMK_STS_bQuitInverterOn_START  (13U)
#define AMK_STS_bQuitInverterOn_LENGTH (1U)
#define AMK_STS_bQuitInverterOn_FACTOR (0U)
#define AMK_STS_bQuitInverterOn_OFFSET (0U)

#define AMK_STS_bInverterOn_START   (14U)
#define AMK_STS_bInverterOn_LENGTH  (1U)
#define AMK_STS_bInverterOn_FACTOR  (0U)
#define AMK_STS_bInverterOn_OFFSET  (0U)

#define AMK_STS_bDerating_START  (15U)
#define AMK_STS_bDerating_LENGTH (1U)
#define AMK_STS_bDerating_FACTOR (0U)
#define AMK_STS_bDerating_OFFSET (0U)

#define AMK_STS_bActualVelocity_START  (16U)
#define AMK_STS_bActualVelocity_LENGTH (16U)
#define AMK_STS_bActualVelocity_FACTOR (0U)
#define AMK_STS_bActualVelocity_OFFSET (0U)

#define AMK_STS_bTorqueCurrent_START  (32U)
#define AMK_STS_bTorqueCurrent_LENGTH (16U)
#define AMK_STS_bTorqueCurrent_FACTOR (0U)
#define AMK_STS_bTorqueCurrent_OFFSET (0U)

#define AMK_STS_bMagnetizingCurrent_START  (48U)
#define AMK_STS_bMagnetizingCurrent_LENGTH (16U)
#define AMK_STS_bMagnetizingCurrent_FACTOR (0U)
#define AMK_STS_bMagnetizingCurrent_OFFSET (0U)

// AMK ACTUAL VALUES 2
#define AMK_TEMPS_TempMotor_START  (0U)
#define AMK_TEMPS_TempMotor_LENGTH (16U)
#define AMK_TEMPS_TempMotor_FACTOR (0U)
#define AMK_TEMPS_TempMotor_OFFSET (0U)

#define AMK_TEMPS_TempInverter_START  (16U)
#define AMK_TEMPS_TempInverter_LENGTH (16U)
#define AMK_TEMPS_TempInverter_FACTOR (0U)
#define AMK_TEMPS_TempInverter_OFFSET (0U)

#define AMK_TEMPS_Error_START  (32U)
#define AMK_TEMPS_Error_LENGTH (16U)
#define AMK_TEMPS_Error_FACTOR (0U)
#define AMK_TEMPS_Error_OFFSET (0U)

#define AMK_TEMPS_TempIGBT_START  (48U)
#define AMK_TEMPS_TempIGBT_LENGTH (16U)
#define AMK_TEMPS_TempIGBT_FACTOR (0U)
#define AMK_TEMPS_TempIGBT_OFFSET (0U)


// Actual Values
#define AMK_STS_


/*********************************************************
*                 GLOBAL STRUCT INSTANCES
*********************************************************/

extern TsAMKSetpoints AMK_Setpoints;

/*********************************************************
*               PUBLIC FUNCTION DECLARATIONS
*********************************************************/

TeCanALRet GetBinaryUnmarshaller(uint32_t* ID, BinaryUnmarshaller** pUnmarshal);
TeCanALRet GetBinaryMarshaller(TeMessageID* ID, BinaryMarshaller** pMarshal);

#endif /* INC_CANAL_FRONTCONTROLLER_MESSAGES_H_ */

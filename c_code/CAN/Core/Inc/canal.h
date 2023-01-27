/*
 * canal.h
 *
 *  Created on: Jan 9, 2023
 *      Author: Samuel Parent
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

#ifndef INC_CANAL_H_
#define INC_CANAL_H_

/*********************************************************
*                       INCLUDES
*********************************************************/

#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "canal_types.h"

// NOTE: Must add ECU specific autogen code here for each new ECU
#if 	__has_include("canal_frontcontroller_messages.h")
#include "canal_frontcontroller_messages.h"
#elif 	__has_include("canal_tms_messages.h")
#include "canal_tms_messages.h"
#elif 	__has_include("canal_lvcontroller_messages.h")
#include "canal_lvcontroller_messages.h"
#endif

/*********************************************************
*                       MACROS
*********************************************************/

#define FREQ_MHZ					(1000000U)
#define NUM_SUPPORTED_PCKL1_FREQ 	(2U)
#define NUM_SUPPORTED_CAN_BITRATES	(4U)
#define NUM_BITRATE_ENTRIES			(NUM_SUPPORTED_CAN_BITRATES * NUM_SUPPORTED_PCKL1_FREQ)
#define DEFAULT_SYNC_JW 			(CAN_SJW_1TQ)
#define DEFAULT_RX_FIFO				(CAN_RX_FIFO0)

#define IS_CANAL_BAUDRATE(__baud__) ((__baud__ == CAN_BAUD_100K) || \
									 (__baud__ == CAN_BAUD_250K) || \
									 (__baud__ == CAN_BAUD_500K) || \
									 (__baud__ == CAN_BAUD_1M))

#define IS_CANAL_MODE(__mode__)		((__mode__ == CAN_NORMAL) || \
									 (__mode__ == CAN_SILENT))

/*********************************************************
*                       TYPES
*********************************************************/

// TeCanALMode enumerates the modes in which the Can hardware operates
typedef enum {
	// CAN_NORMAL is a mode that supports tx/rx but cannot transmit to itself
	CAN_NORMAL = CAN_MODE_NORMAL,
	// CAN_SILENT is a mode that only supports rx
	CAN_SILENT = CAN_MODE_SILENT,
	// NOTE: CAN_LOOPBACK is not supported as we do not want to classify a message
	// as receivable if it can only be received by the same node that send it.
	// This feature may be good for debugging needs, but not for production.
}TeCanALMode;

// TeCanALBaud enumerates the supported can bus baudrates (aka bitrates)
typedef enum {
	CAN_UNKNOWN_BAUD,
	CAN_BAUD_100K = 	((uint16_t)100),
	CAN_BAUD_250K = 	((uint16_t)250),
	CAN_BAUD_500K = 	((uint16_t)500),
	CAN_BAUD_1M = 		((uint16_t)1000),
}TeCanALBaud;

typedef enum {
	CAN_1 = 1,
	CAN_2,
	CAN_3,
}TeCanALInstance;

typedef struct {
	CAN_HandleTypeDef* hcan;
	TeCanALInstance canNum;
	TeCanALBaud baud;
	TeCanALMode mode;
}TsCanAL;

/*********************************************************
*               PUBLIC FUNCTION DECLARATIONS
*********************************************************/

// CAN Init initializes CAN hardware and must be called with successful return
// before any other CAN functions
TeCanALRet Can_Init(TsCanAL* can);
// Can_Receive_IT is meant to be called in HAL_CAN_RxFifo0MsgPendingCallback
TeCanALRet Can_Receive_IT(TsCanAL* can);
// Can_Receive_Poll will poll for a the message associated with the
// messgeID provided
TeCanALRet Can_Receive_Poll(TsCanAL* can, TeMessageID messageID);
// Can_Transmit will send the global message struct associated with the
// messageID provided
TeCanALRet Can_Transmit(TsCanAL* can, TeMessageID messageID);
// Can_Last_Updated returns the amount of time since the message
// associated with messageID provided was last updated in milliseconds
uint8_t Can_Last_Updated(TeMessageID messageID);

#endif /* INC_CAN_H_ */

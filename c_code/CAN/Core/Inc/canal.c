/*
 * canal.c
 *
 *  Created on: Jan 22, 2023
 *      Author: Samuel Parent
 *
 *                   ..::^~~~!!~~~^^:..
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

/*********************************************************
*                       INCLUDES
*********************************************************/

#include "canal.h"

/*********************************************************
*                       HELPERS
*********************************************************/

// This table exists as the there are multiple solutions for timing to the set of
// parameters: {PCLK1_Freq, Baud}. There are are preferred solutions, which
// can be found here: http://www.bittiming.can-wiki.info/
static const struct {
	uint8_t pclk1Mhz; uint16_t baudKb; uint8_t prescaler; uint8_t seg1; uint8_t	seg2;
}CAN_BITRATE_TABLE[NUM_BITRATE_ENTRIES] = {
	{16,	1000,	1,		13,		2},
	{16,	500,	2,		13,		2},
	{16,	250,	4,		13,		2},
	{16,	100,	10,		13, 	2},
	{8,		1000,	1,		6,		1},
	{8,		500,	1,		13,		2},
	{8,		250,	2,		13,		2},
	{8,		100,	5,		13,		2},
};


static TeCanALRet setInstance(CAN_HandleTypeDef* hcan, TeCanALInstance canNum){
	CAN_TypeDef* instance;

	switch (canNum) {
	case CAN_1:
		instance = CAN1;
		break;
	case CAN_2:
		instance = CAN2;
		break;
	case CAN_3:
		instance = CAN3;
		break;
	default:
		return CAN_UNSUPPORTED_INSTANCE;
	}

	hcan->Instance = instance;

	return CAN_OK;
}

static void setDefaults(CAN_HandleTypeDef* hcan) {
	hcan->Init.TimeTriggeredMode = DISABLE;
	hcan->Init.AutoBusOff = DISABLE;
	hcan->Init.AutoWakeUp = DISABLE;
	hcan->Init.AutoRetransmission = DISABLE;
	hcan->Init.ReceiveFifoLocked = DISABLE;
	hcan->Init.TransmitFifoPriority = DISABLE;
}


static TeCanALRet setTimingParams(CAN_HandleTypeDef* hcan, TeCanALBaud baud) {
    uint8_t freq = (HAL_RCC_GetPCLK1Freq() / FREQ_MHZ);

    if (!IS_CANAL_BAUDRATE(baud)) return CAN_UNSUPPORTED_BAUD;


    for (uint8_t i = 0; i < NUM_BITRATE_ENTRIES; i++) {
        if (freq == CAN_BITRATE_TABLE[i].pclk1Mhz) {
            if (baud == CAN_BITRATE_TABLE[i].baudKb){
                hcan->Init.Prescaler  = CAN_BITRATE_TABLE[i].prescaler;
                hcan->Init.TimeSeg1   = CAN_BITRATE_TABLE[i].seg1;
                hcan->Init.TimeSeg2   = CAN_BITRATE_TABLE[i].seg2;
                hcan->Init.SyncJumpWidth = DEFAULT_SYNC_JW;

                return CAN_OK;
            }
        }
    }

    return CAN_UNSUPPORTED_PCLK1_FREQ;
}

static TeCanALRet setMode(CAN_HandleTypeDef* hcan, TeCanALMode mode) {
	if (!IS_CANAL_MODE(mode)) return CAN_UNSUPPORTED_MODE;

	hcan->Init.Mode = mode;

	return CAN_OK;
}

static TeCanALRet setFilters(CAN_HandleTypeDef* hcan) {
	// TODO: Do we have any use for this?
	CAN_FilterTypeDef filterConfig = {
		.FilterBank = 0,
		.FilterMode = CAN_FILTERMODE_IDMASK,
		.FilterScale = CAN_FILTERSCALE_32BIT,
		.FilterIdHigh = 0x0000,
		.FilterIdLow = 0x0000,
		.FilterMaskIdHigh = 0x0000,
		.FilterMaskIdLow = 0x0000,
		.FilterFIFOAssignment = DEFAULT_RX_FIFO,
		.FilterActivation = ENABLE,
		.SlaveStartFilterBank = 14,
	};


	if (HAL_CAN_ConfigFilter(hcan, &filterConfig) != HAL_OK){
		return CAN_CONFIG_FILTER_FAILED;
	}

	return HAL_OK;
}

/*********************************************************
*              PUBLIC FUNCTION DEFINITIONS
*********************************************************/

// Can_Init initializes CAN hardware and must be called with successful return
// before any other CAN functions
TeCanALRet Can_Init(TsCanAL* can) {
	TeCanALRet ret;

	ret = setInstance(can->hcan, can->canNum);
	if (ret != CAN_OK) return ret;

	ret = setTimingParams(can->hcan, can->baud);
	if (ret != CAN_OK) return ret;

	ret = setMode(can->hcan, can->mode);
	if (ret != CAN_OK) return ret;

	ret = setFilters(can->hcan);
	if (ret != CAN_OK) return ret;

	setDefaults(can->hcan);


	if (HAL_CAN_Init(can->hcan) != HAL_OK) return CAN_INIT_FAILED;

	if (HAL_CAN_Start(can->hcan) != HAL_OK) return CAN_START_FAILED;

	return CAN_OK;
}


TeCanALRet Can_Receive_IT(TsCanAL* can) {
	TeCanALRet ret;
	CAN_RxHeaderTypeDef RxHeader =   {0};
	uint8_t RxData[8] = {0};
	uint32_t ID;
	BinaryUnmarshaller* Unmarshal;


	// Get raw message
	if (HAL_CAN_GetRxMessage(can->hcan, DEFAULT_RX_FIFO, &RxHeader, RxData) != HAL_OK) {
		return CAN_GET_RXMESSAGE_FAILED;
	}

	// Message ID can either be standard or extended
	switch (RxHeader.IDE) {
		case CAN_ID_STD:
			ID = RxHeader.StdId;
		case CAN_ID_EXT:
			ID = RxHeader.ExtId;
		default:
			return CAN_UNKOWN_IDE;
	}

	// Get BinaryUnmarshaller from Message Table
	ret = GetBinaryUnmarshaller(&ID, &Unmarshal);
	if (ret != CAN_OK) return ret;

	// Unmarshal raw binary. Updates the global struct instance
	ret = Unmarshal(RxData);
	if (ret != CAN_OK) return ret;

	return CAN_OK;
}




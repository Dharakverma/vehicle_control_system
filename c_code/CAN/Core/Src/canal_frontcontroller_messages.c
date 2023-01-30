/*
 * canal_frontcontroller_messages.c
 *
 *  Created on: Dec 27, 2022
 *     Authors: Samuel Parent, Abhishek Magdum, Lin Fu
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

#include <stdint.h>
#include "canal.h"
#include "canal_frontcontroller_messages.h"

/*********************************************************
*                       MACROS
*********************************************************/
#define MAX_MESSAGE_TABLE_SIZE (1U)
#define CAN_BITS (64U)

// TODO: Unit test all these Macros

// BIT_MASK will output a mask with (__length__) number of 1's
// e.g.: BIT_MASK(5) = 0b0001'1111
#define BIT_MASK(__length__) \
	(UINT64_MAX >> (CAN_BITS - __length__))

// CLEAR_BITS will output the contents of (__data__) with bits from (__start__)
// to (__start__+__length__) set to 0
#define CLEAR_BITS(__data__, __start__, __length__) \
	((UINT64_MAX & (BIT_MASK(__length__) << __start__)) & (__data__))

// GET_BITS will output the bits from (__data__) at bit positions (__start__)
// to (__start__+__length__)
#define GET_BITS(__data__, __start__, __length__) \
	((__data__ >> (CAN_BITS - __length__ - __start__)) & BIT_MASK(__length__))

// SET_BITS will take the first (__length__) bits from (__input__) and set them
// to (__output__) from bit position (__start__) to (__start__ + __length__)
#define SET_BITS(__input__, __output__, __start__, __length__) \
	(CLEAR_BITS(__output__, __start__, __length__) | ((uint64_t)(__input__) & BIT_MASK(__length__)) << __start__)

/*********************************************************
*                    HELPER FUNCTIONS
*********************************************************/

static uint64_t getDataLittleEndian(uint8_t RawData[8]) {
    uint64_t ret;

    for (uint8_t i = 0; i<8; i++) {
        ret += RawData[i];
        ret <<= 8;
    }

    return ret;
}

static uint64_t getDataBigEndian(uint8_t RawData[8]) {
    uint64_t ret;

    for (uint8_t i = 7; i>=0; i--) {
        ret += RawData[i];
        ret <<= 8;
    }

    return ret;
}

TeCanALRet getDataWordFromByteArray(uint8_t dataArr[8], uint64_t* dataOutput, TeCanALEndianness Endianness) {
    switch (Endianness)
    {
    case CAN_LITTLE_ENDIAN:
        *(dataOutput) = getDataLittleEndian(dataArr);
        break;
    case CAN_BIG_ENDIAN:
        *(dataOutput) = getDataBigEndian(dataArr);
        break;
    default:
        return CAN_ERROR;
        break;
    }

    return CAN_OK;
 }

static void setDataLittleEndian (uint64_t* dataWord, uint8_t* dataOutput) {
    for (uint8_t i = 7; i >= 0; i--) {
        dataOutput[i] = (uint8_t)((*dataWord) & BIT_MASK(8));
        *dataWord <<= 8;
    }
}

static void setDataBigEndian (uint64_t* dataWord, uint8_t* dataOutput) {
    for (uint8_t i = 0; i < 8; i++) {
        dataOutput[i] = (uint8_t)((*dataWord) & BIT_MASK(8));
        *dataWord <<= 8;
    }
}

static TeCanALRet setDataWordIntoByteArray(uint64_t* dataWord, uint8_t* dataOutput, TeCanALEndianness Endianness) {
    switch (Endianness)
    {
    case CAN_LITTLE_ENDIAN:
        setDataLittleEndian(dataWord, dataOutput);
        break;
    case CAN_BIG_ENDIAN:
        setDataBigEndian(dataWord, dataOutput);
        break;
    default:
        return CAN_ERROR;
        break;
    }

    return CAN_OK;
}

/*********************************************************
*                    CAN FUNCTIONS
*********************************************************/

TeCanALRet UnmarshalAMKSetpoints(uint8_t* RxData) {
    uint64_t data;
    TsAMKSetpoints temp;
    //static AMK_Setpoints_st temp;
    
    TeCanALRet ret = getDataWordFromByteArray(RxData, &data, AMK_SETPOINTS_ENDIANNESS);
    if (ret != CAN_OK) return ret;

    //  Read raw bits
    temp.AMK_TargetVelocity = GET_BITS(data, AMK_SETPOINTS_AMK_TARGETVELOCITY_START, AMK_SETPOINTS_AMK_TARGETVELOCITY_LENGTH);

    //  Apply linear conversion
    temp.AMK_TargetVelocity = (temp.AMK_TargetVelocity * AMK_SETPOINTS_AMK_TARGETVELOCITY_FACTOR) + AMK_SETPOINTS_AMK_TARGETVELOCITY_OFFSET;

    //  Writing to global struct instance
    AMK_Setpoints = temp;
    
    return CAN_OK;
}

TeCanALRet MarshalAMKSetpoints(uint8_t* TxData){
    uint64_t dataWord = 0;
    TsAMKSetpoints temp;
    TeCanALRet ret;

    temp = AMK_Setpoints;

    temp.AMK_TargetVelocity =  (temp.AMK_TargetVelocity - AMK_SETPOINTS_AMK_TARGETVELOCITY_OFFSET) / AMK_SETPOINTS_AMK_TARGETVELOCITY_FACTOR;

    dataWord = SET_BITS(temp.AMK_TargetVelocity, dataWord, AMK_SETPOINTS_AMK_TARGETVELOCITY_START, AMK_SETPOINTS_AMK_TARGETVELOCITY_LENGTH);

    ret = setDataWordIntoByteArray(&dataWord, TxData, AMK_SETPOINTS_ENDIANNESS);
    if (ret != CAN_OK) {
        return ret;
    }

    return CAN_OK;
}

TeCanALRet UnmarshalAMK0_STS(uint8_t * RxData){
    uint64_t data;
    TsAMK_STS temp;
    TeCanALRet ret;

    ret = getDataWordFromByteArray(RxData, &data, AMK_STS_ENDIANNESS);
    if (ret != CAN_OK) return ret;

    // Read raw bits
    temp.AMK_bError = GET_BITS(data, AMK_STS_bError_START, AMK_STS_bError_LENGTH);
    temp.AMK_bWarn = GET_BITS(data, AMK_STS_bWarn_START, AMK_STS_bWarn_LENGTH);
    temp.AMK_bQuitDcOn = GET_BITS(data, AMK_STS_bQuitDCOn_START, AMK_STS_bQuitDCOn_LENGTH);
    temp.AMK_bDcOn = GET_BITS(data, AMK_STS_bDcOn_START, AMK_STS_bDcOn_LENGTH);
    temp.AMK_bQuitInvertorOn = GET_BITS(data, AMK_STS_bQuitInverterOn_START, AMK_STS_bQuitInverterOn_LENGTH);
    temp.AMK_bInverterOn = GET_BITS(data, AMK_STS_bInverterOn_START, AMK_STS_bInverterOn_LENGTH);
    temp.AMK_bDerating = GET_BITS(data, AMK_STS_bDerating_START, AMK_STS_bDerating_LENGTH);
    temp.AMK_ActualVelocity = GET_BITS(data, AMK_STS_ActualVelocity_START, AMK_STS_ActualVelocity_LENGTH);
    temp.AMK_TorqueCurrent = GET_BITS(data, AMK_STS_TorqueCurrent_START, AMK_STS_TorqueCurrent_LENGTH);
    temp.AMK_magnetizingCurrent = GET_BITS(data, AMK_STS_MagnetizingCurrent_START, AMK_STS_MagnetizingCurrent_LENGTH);

    // Apply linear conversion (not doing this rn since just testing)

    // Writing to global struct instance
    AMK0_STS = temp;

    return CAN_OK;

}

TeCanALRet UnmarshalAMK1_STS(uint8_t * RxData){
    uint64_t data;
    TsAMK_STS temp;
    TeCanALRet ret;

    ret = getDataWordFromByteArray(RxData, &data, AMK_STS_ENDIANNESS);
    if (ret != CAN_OK) return ret;

    // Read raw bits
    temp.AMK_bError = GET_BITS(data, AMK_STS_bError_START, AMK_STS_bError_LENGTH);
    temp.AMK_bWarn = GET_BITS(data, AMK_STS_bWarn_START, AMK_STS_bWarn_LENGTH);
    temp.AMK_bQuitDcOn = GET_BITS(data, AMK_STS_bQuitDCOn_START, AMK_STS_bQuitDCOn_LENGTH);
    temp.AMK_bDcOn = GET_BITS(data, AMK_STS_bDcOn_START, AMK_STS_bDcOn_LENGTH);
    temp.AMK_bQuitInvertorOn = GET_BITS(data, AMK_STS_bQuitInverterOn_START, AMK_STS_bQuitInverterOn_LENGTH);
    temp.AMK_bInverterOn = GET_BITS(data, AMK_STS_bInverterOn_START, AMK_STS_bInverterOn_LENGTH);
    temp.AMK_bDerating = GET_BITS(data, AMK_STS_bDerating_START, AMK_STS_bDerating_LENGTH);
    temp.AMK_ActualVelocity = GET_BITS(data, AMK_STS_ActualVelocity_START, AMK_STS_ActualVelocity_LENGTH);
    temp.AMK_TorqueCurrent = GET_BITS(data, AMK_STS_TorqueCurrent_START, AMK_STS_TorqueCurrent_LENGTH);
    temp.AMK_magnetizingCurrent = GET_BITS(data, AMK_STS_MagnetizingCurrent_START, AMK_STS_MagnetizingCurrent_LENGTH);

    // Apply linear conversion (not doing this rn since just testing)

    // Writing to global struct instance
    AMK1_STS = temp;

    return CAN_OK;

}

/*********************************************************
*               FUNCTION POINTER TABLE
*********************************************************/

static const struct {
	TeMessageID ID;
	BinaryUnmarshaller* Unmarshal;
}CANAL_RX_MESSAGE_TABLE[NUM_RX_MESSAGES] = {
	// MESSAGE ID 				// POINTER TO UNMARSHAL FUNCTION
	{AMK_SETPOINTS_CAN_ID,		&UnmarshalAMKSetpoints},
    {AMK0_STS_CAN_ID,		    &UnmarshalAMK0_STS},
    {AMK0_STS_CAN_ID,		    &UnmarshalAMK0_STS},
};

static const struct {
	TeMessageID ID;
	BinaryMarshaller* Marshal;
}CANAL_TX_MESSAGE_TABLE[NUM_TX_MESSAGES] = {
	// MESSAGE ID 				// POINTER TO MARSHAL FUNCTION
	{AMK_SETPOINTS_CAN_ID,		&MarshalAMKSetpoints},
};

/*********************************************************
*             PUBLIC FUNCTION DEFINITIONS
*********************************************************/

TeCanALRet GetBinaryUnmarshaller(uint32_t* ID, BinaryUnmarshaller** pUnmarshal) {
	for (int i = 0; i < NUM_RX_MESSAGES; i++) {
		if ((*ID) == CANAL_RX_MESSAGE_TABLE[i].ID) {
			*pUnmarshal = CANAL_RX_MESSAGE_TABLE[i].Unmarshal;

			return CAN_OK;
		}
	}

	return CAN_UNSUPPORTED_RX_MESSAGE;
}

TeCanALRet GetBinaryMarshaller(TeMessageID* ID, BinaryMarshaller** pMarshal) {
	for (int i = 0; i < NUM_TX_MESSAGES; i++) {
			if ((*ID) == CANAL_TX_MESSAGE_TABLE[i].ID) {
				*pMarshal = CANAL_TX_MESSAGE_TABLE[i].Marshal;

				return CAN_OK;
			}
		}

		return CAN_UNSUPPORTED_TX_MESSAGE;
}


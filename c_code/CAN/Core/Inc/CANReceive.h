#include <stdio.h>

#define MAX_RECEIVE_TABLE_SIZE (30u)

extern uint16_t vehicleSpeed;
extern uint16_t motorTorque;

extern uint16_t AMK0_bSystemReady;
extern uint16_t AMK0_bError;
extern uint16_t AMK0_bWarn;
extern uint16_t AMK0_bQuitDcOn;
extern uint16_t AMK0_bDcOn;
extern uint16_t AMK0_bQuitInvertorOn;
extern uint16_t AMK0_bInverterOn;
extern uint16_t AMK0_bDerating;
extern uint16_t AMK0_ActualVelocity;
extern uint16_t AMK0_TorqueCurrent;
extern uint16_t AMK0_magnetizingCurrent;

extern uint16_t AMK1_bSystemReady;
extern uint16_t AMK1_bError;
extern uint16_t AMK1_bWarn;
extern uint16_t AMK1_bQuitDcOn;
extern uint16_t AMK1_bDcOn;
extern uint16_t AMK1_bQuitInvertorOn;
extern uint16_t AMK1_bInverterOn;
extern uint16_t AMK1_bDerating;
extern uint16_t AMK1_ActualVelocity;
extern uint16_t AMK1_TorqueCurrent;
extern uint16_t AMK1_magnetizingCurrent;

extern uint16_t AMK0_TempMotor;
extern uint16_t AMK0_TempInverter;
extern uint16_t AMK0_ErrorInfo;
extern uint16_t AMK0_TempIGBT;

extern uint16_t AMK1_TempMotor;
extern uint16_t AMK1_TempInverter;
extern uint16_t AMK1_ErrorInfo;
extern uint16_t AMK1_TempIGBT;

typedef struct {
    uint32_t ID;
    uint16_t * pointerToUserVariable;
    uint16_t offset;
    uint16_t length;

} sReceiveMessage;

int DLC = 8;

sReceiveMessage RecieveMessageTable[MAX_RECEIVE_TABLE_SIZE] = {

    //ID        //poiterToUserVariable          //offset    //length
    {0x284,     &AMK0_bSystemReady,             8,      	1},
    {0x284,     &AMK0_bError,                   9,      	1},
	{0x284,     &AMK0_bWarn,                   	10,      	1},
	{0x284,     &AMK0_bQuitDcOn,               	11,      	1},
	{0x284,     &AMK0_bDcOn,                   	12,      	1},
	{0x284,     &AMK0_bQuitInvertorOn,         	13,      	1},
	{0x284,     &AMK0_bInverterOn,         		14,      	1},
	{0x284,     &AMK0_bDerating,         		15,      	1},
	{0x284,     &AMK0_ActualVelocity,         	16,      	16},
	{0x284,     &AMK0_TorqueCurrent,         	32,      	16},
	{0x284,     &AMK0_magnetizingCurrent,       48,      	16},

	{0x285,     &AMK1_bSystemReady,             8,      	1},
	{0x285,     &AMK1_bError,                   9,      	1},
	{0x285,     &AMK1_bWarn,                   	10,      	1},
	{0x285,     &AMK1_bQuitDcOn,               	11,      	1},
	{0x285,     &AMK1_bDcOn,                   	12,      	1},
	{0x285,     &AMK1_bQuitInvertorOn,         	13,      	1},
	{0x285,     &AMK1_bInverterOn,         		14,      	1},
	{0x285,     &AMK1_bDerating,         		15,      	1},
	{0x285,     &AMK1_ActualVelocity,         	16,      	16},
	{0x285,     &AMK1_TorqueCurrent,         	32,      	16},
	{0x285,     &AMK1_magnetizingCurrent,       48,      	16},

	{0x286,     &AMK0_TempMotor,             	0,      	16},
	{0x286,     &AMK0_TempInverter,             16,      	16},
	{0x286,     &AMK0_ErrorInfo,                32,      	16},
	{0x286,     &AMK0_TempIGBT,               	48,      	16},

	{0x287,     &AMK1_TempMotor,             	0,      	16},
	{0x287,     &AMK1_TempInverter,             16,      	16},
	{0x287,     &AMK1_ErrorInfo,                32,      	16},
	{0x287,     &AMK1_TempIGBT,               	48,      	16}

};

//right now it checks value, will need to change it to update variables
void IncomingCANMessageHandler(uint32_t* ID, uint8_t* RxData) {
	/*This function add all RxData to a uint64 line,
	 * then get the bits we want by bit shifting 'final'
	 * according to offset and length*/
	uint32_t a = RxData[0];
	uint32_t b = RxData[1];
	uint32_t c = RxData[2];
	uint32_t d = RxData[3];
	uint32_t e = RxData[4];
	uint32_t f = RxData[5];
	uint32_t g = RxData[6];
	uint32_t h = RxData[7];

	uint64_t firstSegment = 0;
	uint32_t secondSegment = 0;
	uint64_t finalRxData = 0;

    //add all the unit8 arrays to a uint64 line
	firstSegment =  a << 24 | b << 16 | c << 8 | d;
	secondSegment = e << 24 | f << 16 | g << 8 | h;
	finalRxData = firstSegment << 32 | secondSegment;

    for(int i = 0; i < MAX_RECEIVE_TABLE_SIZE; i++){

        if (RecieveMessageTable[i].ID == *ID){
            //*RecieveMessageTable[i].pointerToUserVariable = CAN_MESSAGE>>(DLC*8 - RecieveMessageTable[i].offset - RecieveMessageTable[i].length) & 0xFFFFFFFFFFFFFFFF>>(64 - RecieveMessageTable[i].length);
            //bit shifting 'final' according to offset and length
        	*RecieveMessageTable[i].pointerToUserVariable = finalRxData>>(DLC*8 - RecieveMessageTable[i].offset - RecieveMessageTable[i].length) & 0xFFFFFFFFFFFFFFFF>>(64 - RecieveMessageTable[i].length);
        }
    }
}



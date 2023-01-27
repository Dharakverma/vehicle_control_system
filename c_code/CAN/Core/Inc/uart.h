/*
 * uart.h
 *
 *  Created on: Oct 26, 2022
 *      Author: ivanl
 */

#ifndef INC_UART_H_
#define INC_UART_H_


/*---------------------- INCLUDES ----------------------*/

#include "main.h"

/*---------------------- MACROS ----------------------*/

#define MIN_UART_BAUDRATE 123
#define MAX_UART_BAUDRATE 500000
#define TIMEOUT 		  5000

/*---------------------- TYPEDEFS ----------------------*/

// Distinguishes between 3 UART modes
typedef enum {
	UART_RX = 1,	// Receive only
	UART_TX,		// Transmit only
	UART_TX_RX		// Receive and transmit
}UART_Mode_et;

// Distinguishes between the bit position of the data stream
typedef enum {
	LSB_First = 1,	// Send least significant bit first
	MSB_First		// Send most significant bit first
}UART_Bit_Position_et;

// Distinguishes between allowable data bits to send at a time (7-9 bits)
typedef enum {
    UART_Datasize_7 = ((uint8_t)7),
    UART_Datasize_8 = ((uint8_t)8),
    UART_Datasize_9 = ((uint8_t)9),
}UART_Datasize_et;

// Predetermines standard baudrates for UART
typedef enum {
    UART_9600 	=   ((uint32_t) 9600),
    UART_19200 	=  	((uint32_t) 19200),
	UART_57600 	= 	((uint32_t) 57600),
    UART_115200 =   ((uint32_t) 115200),
    UART_256000 =   ((uint32_t) 256000),
    UART_500000 =   ((uint32_t) 500000),
}UART_Std_Baud_et;

// UART_st holds the user input for a particular UART configuration
typedef struct {
	// pointer to the UART handle being used
	UART_HandleTypeDef* huart;
	// UART number, from 1-8
	uint8_t uart_num;
	// UART baud rate, from 123 Bits/s and 500 KBits/s
	uint32_t baudrate;
	// UART data frame size, from 7-9
	UART_Datasize_et datasize;
	// UART mode being selected, choose from Tx only, Rx only, or Tx and Rx
	UART_Mode_et mode;
	// Selection for the first or second bit to be sent first
	UART_Bit_Position_et bit_position;
}UART_st;

// UART_Return_et describes the return types for all UART functions
typedef enum {
	UART_OK = 1,
	BAUDRATE_OUT_OF_BOUNDS,
	INVALID_MODE,
	INVALID_BIT_POSITION,
	INVALID_UART_NUM,
	INVALID_DATASIZE,
	TRANSMIT_FAILED,
	RECEIVE_FAILED,
	DEINIT_FAILED,
}UART_Return_et;

/*------------ PUBLIC FUNCTION DECLARATIONS ------------- */

UART_Return_et UART_Init(UART_st* uart);
UART_Return_et UART_Transmit(UART_st* uart, uint8_t* tx_buf, uint8_t buf_len);
UART_Return_et UART_Receive(UART_st* uart, uint8_t* rx_buf, uint8_t buf_len);
UART_Return_et UART_Deinit(UART_st* uart);

#endif /* INC_UART_H_ */

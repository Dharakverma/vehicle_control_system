/*
 * spi.h
 *
 *  Created on: Nov 11, 2022
 *      Author: hadyi
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

/*---------------------- INCLUDES ----------------------*/
#include "main.h"

/*---------------------- DEFINITIONS ----------------------*/
// Distinguishes between 0 and 1 (sometimes 1 and 2) edge clock phase
typedef enum {
	EDGE_0 = 1,
	EDGE_1
}SPI_Clock_Phase_et;

// Distinguishes between high and low clock polarity
typedef enum {
	LOW = 0,
	HIGH
}SPI_Clock_Polarity_et;

// Distinguishes between the bit position of the data stream
typedef enum {
	LSB_FIRST = 1,	// Send least significant bit first
	MSB_FIRST		// Send most significant bit first
}SPI_Bit_Position_et;

// Distinguishes between allowable data bits to send at a time (4-16 bits)
typedef enum {
	SPI_Datasize_4 = SPI_DATASIZE_4BIT,
	SPI_Datasize_5 = SPI_DATASIZE_5BIT,
	SPI_Datasize_6 = SPI_DATASIZE_6BIT,
	SPI_Datasize_7 = SPI_DATASIZE_7BIT,
	SPI_Datasize_8 = SPI_DATASIZE_8BIT,
	SPI_Datasize_9 = SPI_DATASIZE_9BIT,
	SPI_Datasize_10 = SPI_DATASIZE_10BIT,
	SPI_Datasize_11 = SPI_DATASIZE_11BIT,
	SPI_Datasize_12 = SPI_DATASIZE_12BIT,
	SPI_Datasize_13 = SPI_DATASIZE_13BIT,
	SPI_Datasize_14 = SPI_DATASIZE_14BIT,
	SPI_Datasize_15 = SPI_DATASIZE_15BIT,
	SPI_Datasize_16 = SPI_DATASIZE_16BIT
}SPI_Datasize_et;

// SPI_st holds the user input for a particular SPI configuration
typedef struct {
	// pointer to the SPI handle being used
	SPI_HandleTypeDef* hspi;
	// SPI number, from 1-6
	uint8_t spi_num;
	// SPI baud rate
	uint32_t baudrate;
	// SPI data frame size, from 4-16 (not including 14)
	SPI_Datasize_et datasize;
	// SPI clock phase being selected, choose between 0 and 1 edge
	SPI_Clock_Phase_et clock_phase;
	// SPI clock polarity being selected, choose between high and low
	SPI_Clock_Polarity_et clock_polarity;
	// Selection for the first or second bit to be sent first
	SPI_Bit_Position_et bit_position;
	// SPI Port, this is defined upon definition of struct
	GPIO_TypeDef* port;
	// SPI Pin, this is defined upon definition of struct
	uint16_t pin;
}SPI_st;

// SPI_Return_et describes the return types for all SPI functions
typedef enum {
	SPI_OK = 1,
	SPI_BAUDRATE_OUT_OF_BOUNDS,
	SPI_INVALID_CLOCK_PHASE,
	SPI_INVALID_CLOCK_POLARITY,
	SPI_INVALID_BIT_POSITION,
	INVALID_SPI_NUM,
	SPI_INVALID_DATASIZE,
	SPI_TRANSMIT_FAILED,
	SPI_RECEIVE_FAILED,
	SPI_DEINIT_FAILED,
	SPI_INIT_FAILED
}SPI_Status_et;

/*------------- PUBLIC FUNCTION DEFINITIONS ------------- */

SPI_Status_et SPI_Init(SPI_st* spi);
SPI_Status_et SPI_Transmit(SPI_st* spi, uint8_t *Tx_buf, uint8_t buf_len);
SPI_Status_et SPI_Deinit(SPI_st* spi);
SPI_Status_et SPI_Transmit_Receive(SPI_st* spi, uint8_t *tx_buf, uint8_t *rx_buf, uint8_t buf_len);


#endif /* INC_SPI_H_ */

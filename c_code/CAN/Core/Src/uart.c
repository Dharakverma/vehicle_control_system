/*
 * uart.c
 *
 *  Created on: Oct 26, 2022
 *      Author: ivanl
 */

#ifndef SRC_UART_C_
#define SRC_UART_C_

/*---------------------- INCLUDES ----------------------*/

#include "uart.h"

/*------------- PRIVATE FUNCTION DEFINITIONS ------------ */

// UART_Select configures the corresponding UART number from a UART_st
static UART_Return_et UART_Select(UART_st* uart)
{
	// Switch case for selection of 8 UARTS
	switch(uart->uart_num)
	{
		case 1:
			uart->huart -> Instance = USART1;
			break;
		case 2:
			uart->huart -> Instance = USART2;
			break;
		case 3:
			uart->huart -> Instance = USART3;
			break;
		case 4:
			uart->huart -> Instance = UART4;
			break;
		case 5:
			uart->huart -> Instance = UART5;
			break;
		case 6:
			uart->huart -> Instance = USART6;
			break;
		case 7:
			uart->huart -> Instance = UART7;
			break;
		case 8:
			uart->huart -> Instance = UART8;
			break;
		default:
			return INVALID_UART_NUM;
	}

	return UART_OK;
}

// UART_Baud_Rate_Select configures the baud rate from the one specified in baudrate
static UART_Return_et UART_Baud_Rate_Select(UART_st* uart)
{
	// Baud rate must be between 123 Bits/s and 500 KBits/s, stated in .ioc requirements
	if(uart->baudrate < MIN_UART_BAUDRATE || uart->baudrate > MAX_UART_BAUDRATE){
		return BAUDRATE_OUT_OF_BOUNDS;
	}

	uart->huart->Init.BaudRate = uart->baudrate;

	return UART_OK;
}

// UART_Datasize_Select configures the data size from a UART_Datasize_et
static UART_Return_et UART_Datasize_Select(UART_st* uart)
{
	switch(uart->datasize)
	{
		case UART_Datasize_7:
			uart->huart -> Init.WordLength = UART_WORDLENGTH_7B;
			break;
		case UART_Datasize_8:
			uart->huart -> Init.WordLength = UART_WORDLENGTH_8B;
			break;
		case UART_Datasize_9:
			uart->huart -> Init.WordLength = UART_WORDLENGTH_9B;
			break;
		default:
			return INVALID_DATASIZE;
	}

	return UART_OK;
}

// UART_Mode_Select configures the mode based on a UART_Mode_et
static UART_Return_et UART_Mode_Select(UART_st* uart)
{
	switch(uart->mode)
	{
		case UART_RX:
			uart->huart -> Init.Mode = UART_MODE_RX;
			break;
		case UART_TX:
			uart->huart -> Init.Mode = UART_MODE_TX;
			break;
		case UART_TX_RX:
			uart->huart -> Init.Mode = UART_MODE_TX_RX;
			break;
		default:
			return INVALID_MODE;
	}

	return UART_OK;
}

// UART_MSB_Select configures the bit position based on a UART_Bit_Position_et
static UART_Return_et UART_MSB_Select(UART_st* uart)
{
	switch(uart->bit_position){
		case LSB_First:
			uart->huart -> AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
			break;
		case MSB_First:
			uart->huart -> AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_MSBFIRST_INIT;
			uart->huart -> AdvancedInit.MSBFirst = UART_ADVFEATURE_MSBFIRST_ENABLE;
			break;
		default:
			return INVALID_BIT_POSITION;
	}

	return UART_OK;
}

// Current configurations that are not being modified
static void UART_Default_Configs(UART_st* uart)
{
	uart->huart -> Init.StopBits = UART_STOPBITS_1;
	uart->huart -> Init.Parity = UART_PARITY_NONE;
	uart->huart -> Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart->huart -> Init.OverSampling = UART_OVERSAMPLING_16;
	uart->huart -> Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
}

/*------------- PUBLIC FUNCTION DEFINITIONS ------------- */

UART_Return_et UART_Init(UART_st* uart)
{
	UART_Return_et response;

	response = UART_Select(uart);
	if (response != UART_OK) {
		return response;
	}

	response = UART_Baud_Rate_Select(uart);
	if (response != UART_OK) {
		return response;
	}

	response = UART_Datasize_Select(uart);
	if (response != UART_OK) {
		return response;
	}

	response = UART_Mode_Select(uart);
	if (response != UART_OK) {
		return response;
	}

	response = UART_MSB_Select(uart);
	if (response != UART_OK) {
		return response;
	}

	UART_Default_Configs(uart);

	if (HAL_UART_Init(uart->huart) != HAL_OK) { Error_Handler(); }

	return UART_OK;
}

// Uses the HAL UART Transmit to transmit a buffer's contents over the channel specified in the uart struct
UART_Return_et UART_Transmit(UART_st* uart, uint8_t tx_buf[], uint8_t buf_len)
{
	HAL_StatusTypeDef tx_response;

	tx_response = HAL_UART_Transmit(uart->huart, tx_buf, buf_len, TIMEOUT);
	if (tx_response != HAL_OK) {
		return TRANSMIT_FAILED;
	}

	return UART_OK;
}

// TODO: check the rx_buf dataframe being sent (casting currently)
UART_Return_et UART_Receive(UART_st* uart, uint8_t rx_buf[], uint8_t buf_len)
{
	HAL_StatusTypeDef rx_response;

	rx_response = HAL_UART_Receive(uart->huart, rx_buf, buf_len, TIMEOUT);
	if (rx_response != HAL_OK) {
		return RECEIVE_FAILED;
	}

	return UART_OK;
}

UART_Return_et UART_Deinit(UART_st* uart)
{
	HAL_StatusTypeDef deinit_response;

	deinit_response = HAL_UART_DeInit(uart->huart);
	if (deinit_response != HAL_OK) {
		return DEINIT_FAILED;
	}

	return UART_OK;
}

#endif /* SRC_UART_C_ */

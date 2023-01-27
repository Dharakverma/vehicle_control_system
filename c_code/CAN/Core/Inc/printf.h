// All credit to Carmine Noviello for this code (modified to work with Ivan Lange uart library)
// https://github.com/cnoviello/mastering-stm32/blob/master/nucleo-f030R8/system/include/retarget/retarget.h

#ifndef _PRINTF_H__
#define _PRINTF_H__

#include "stm32f7xx_hal.h"
#include <sys/stat.h>
#include "uart.h"

UART_Return_et Printf_Init(UART_st* uart);
int _isatty(int fd);
int _write(int fd, char* ptr, int len);
int _close(int fd);
int _lseek(int fd, int ptr, int dir);
int _read(int fd, char* ptr, int len);
int _fstat(int fd, struct stat* st);

#endif //#ifndef _PRINTF_H__

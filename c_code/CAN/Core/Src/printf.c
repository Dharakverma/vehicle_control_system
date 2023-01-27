// All credit to Carmine Noviello for this code (modified to work with Ivan Lange's uart lib)
// https://github.com/cnoviello/mastering-stm32/blob/master/nucleo-f030R8/system/src/retarget/retarget.c

#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/times.h>
#include <limits.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include "printf.h"


#if !defined(OS_USE_SEMIHOSTING)
#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2



// Must be global
UART_st* Printer;


UART_Return_et Printf_Init(UART_st* uart) {

  UART_Return_et response;

  // Set global to selected UART
  Printer = uart;
  response = UART_Init(uart);

  if (response != UART_OK) {
      return response;
  }

  /* Disable I/O buffering for STDOUT stream, so that
   * chars are sent out as soon as they are printed. */

  setvbuf(stdout, NULL, _IONBF, 0);

  return UART_OK;
}


int _isatty(int fd) {

  if (fd >= STDIN_FILENO && fd <= STDERR_FILENO)
    return 1;

  errno = EBADF;
  return 0;
}

int _write(int fd, char* ptr, int len) {

  UART_Return_et response;

  if (fd == STDOUT_FILENO || fd == STDERR_FILENO) {
    response = UART_Transmit(Printer, (uint8_t*) ptr, len);

    if (response == UART_OK)
      return len;
    else
      return EIO;
  }

  errno = EBADF;
  return -1;
}


int _close(int fd) {

  if (fd >= STDIN_FILENO && fd <= STDERR_FILENO)
    return 0;

  errno = EBADF;
  return -1;
}

int _lseek(int fd, int ptr, int dir) {

  (void) fd;
  (void) ptr;
  (void) dir;
  errno = EBADF;
  return -1;
}

int _read(int fd, char* ptr, int len) {

  UART_Return_et response;

  if (fd == STDIN_FILENO) {
    response = UART_Receive(Printer, (uint8_t*) ptr, len);
    if (response == UART_OK)
      return 1;
    else
      return EIO;
  }

  errno = EBADF;
  return -1;
}


int _fstat(int fd, struct stat* st) {

  if (fd >= STDIN_FILENO && fd <= STDERR_FILENO) {
    st->st_mode = S_IFCHR;
    return 0;
  }

  errno = EBADF;
  return 0;
}


#endif //#if !defined(OS_USE_SEMIHOSTING)

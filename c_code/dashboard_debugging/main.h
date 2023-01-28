#include <stdio.h>
#include <stdint.h>

// This is the DECLARATION of a variable called 'globalVar' of type uint8_t which is EXTERN'd meaning it is of global scope
// Extern means it can be referenced in multiple source files and contain the same information
extern uint8_t globalVar;

void printing_var(void);
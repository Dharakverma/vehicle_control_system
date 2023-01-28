#include <stdio.h>
#include <stdint.h>
#include "main.h"

int main(void) {
    // I have now DEFINED globalVar which is an extern uint8_t from my header "main.h"
    uint8_t globalVar = 5;
    printf("Global var before changing (%i): ", globalVar);
    printing_var();
}
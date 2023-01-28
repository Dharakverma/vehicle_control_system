#include <stdio.h>
#include <stdint.h>
#include "main.h"

void printing_var(void) {
    globalVar = 15;
    printf("global variable (%i): ", globalVar);
}
#include "structFile.h"
#include <stdio.h>
#include <stdlib.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)

void clearConsole() {
    system("cls"); // Pour Windows
}

#else

void clearConsole() {
    printf("\033[H\033[J"); // Pour Linux et macOS
}

#endif
#include "structFile.h"

void clearConsole() {
    #ifdef _WIN32
    #include <windows.h>
        system("cls"); // Pour Windows
    #else
        #include <stdio.h>
        printf("\033[H\033[J"); // Pour Linux et macOS
    #endif
}
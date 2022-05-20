#include "libs/MenuLogic.h"
#include <stdio.h>

int main()
{
    printf("\033[2J\033[1;1H");
    int mode = 0;
    int dif = 1;
    MenuLogic(mode, dif);
    return 0;
}

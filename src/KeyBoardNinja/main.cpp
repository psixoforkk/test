#include "libs/MenuLogic.h"
#include <stdio.h>

int main()
{
    printf("\033[2J\033[1;1H");
    int mode = 0;
    MenuLogic(mode);
    return 0;
}

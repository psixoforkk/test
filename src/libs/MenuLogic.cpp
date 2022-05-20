#include <stdio.h>
#include <stdlib.h>
#include "MenuLogic.h"
#include "trainer.h"
void MenuLogic(int mode) {
    while (1) {
        //printf("\033[2J\033[1;1H");
        mode = ShowMenu();
        SwitchMode(mode);
        if (mode == 4) {
            break;
        }
    }
}

void SwitchMode(int mode) {
    switch(mode) {
    case 1:
        Start();
        break;
    case 2:
        ChooseDifficulty();
        break;
    case 3:
        Results();
        break;
    case 4:
        return;
    }
}

void Start() {
    printf("\033[2J\033[1;1H");
    FILE *input_file;
    char text_array[100];
    memset(text_array, 0, sizeof(text_array));
    input_file = FileOpen("easyway.txt");
    int i = FileCheck(input_file);
    printf("%d\n", i);
    FileRead(input_file, 2, text_array);
    printf("%s", text_array);
}

void ChooseDifficulty() {
    printf("\033[2J\033[1;1H");
}

void Results() {
    printf("\033[2J\033[1;1H");
}

int ShowMenu() {
    int mode = 0;
    printf("1. Start\n");
    printf("2. Choose difficulty\n");
    printf("3. Results\n");
    printf("4. Exit\n");
    scanf("%d", &mode);
    return mode;
}


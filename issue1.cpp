#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int ShowMenu();
void govno(int);
void Start();
void ChooseDifficulty();
void Results();

int main()
{
    printf("\033[2J\033[1;1H");
    int mode = 0;
    while (1) {
        printf("\033[2J\033[1;1H");
        mode = ShowMenu();
        govno(mode);
        if (mode == 4) {
            break;
        }
    }
    return 0;
}

void govno(int mode) {
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
    printf("\nstart\n");
}

void ChooseDifficulty() {
    printf("\033[2J\033[1;1H");
    printf("\ndif\n");
}

void Results() {
    printf("\033[2J\033[1;1H");
    printf("\nres\n");
}

int ShowMenu() {
    int mode = 0;
    //printf("\E[42m");
    printf("1. Start\n");
    printf("2. Choose difficulty\n");
    printf("3. Results\n");
    printf("4. Exit\n");
    scanf("%d", &mode);
    //printf("\e[0m");
    return mode;
}


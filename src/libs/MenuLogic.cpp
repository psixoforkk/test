#include <stdio.h>
#include <stdlib.h>
#include "MenuLogic.h"
#include "trainer.h"

void MenuLogic(int mode, int dif) {
    while (1) {
        //printf("\033[2J\033[1;1H");
        mode = ShowMenu();
	if (mode == 4) {
            break;
        }
        dif = SwitchMode(mode, dif);
	if (dif == 0) {
	    dif = 1;	
	}
	printf("Level of dif %d\n", dif);
    }
}

int SwitchMode(int mode, int dif) {
    int umom = 0;
    switch(mode) {
    case 1:
        printf("time= %f\n",Start(dif));
        break;
    case 2:
        umom = ChooseDifficulty();
	if ( umom >= 4 || umom < 0) umom = 0;
        break;
    case 3:
        Results();
        break;
    case 4:
        umom = 0;
	break;
    }
    return umom;
}

float Start(int dif) {
    printf("\nPress any key to start\n");
    include();
    const char* Nfile;
    int knopka = 0;
    if (dif == 1) {
       Nfile = "easyway.txt";
       knopka = 1;
    }
    if (dif == 2) {
       Nfile = "Normal.txt";
       knopka = 2;
    }
    if (dif == 3) {
       Nfile = "Hard.txt";
       knopka = 3;
    }
    int ohib;
    float time;
    clock_t naz, konz; 
    FILE *input_file;
    char text_array[512];
    memset(text_array, 0, sizeof(text_array));
    input_file = FileOpen(Nfile);
    int number_row = Rand_Row(input_file, text_array);
    int i = FileCheck(input_file);
    rewind(input_file);
    FileRead(input_file, number_row, text_array, i);
    TextOut(text_array, knopka);
    naz = clock();
    ohib = InputTextOut(text_array);
    konz = clock();
    time = (float)(konz - naz)/CLOCKS_PER_SEC;
    printf("ohib=%d  ",ohib);
    record(ohib, time);
    return time; 
}


int ChooseDifficulty() {
    printf("\033[2J\033[1;1H");
    int mode;
    printf("1. Easy\n");
    printf("2. Normal\n");
    printf("3. Hard\n");
    printf("4. Exit\n");
    scanf("%d", &mode);
    while ( mode > 4 || mode < 0) {
	 scanf("%d", &mode);  
    }
    return mode;
}

void Results() {
    printf("\033[2J\033[1;1H");
    //printf("\nres\n");
    results ();
}

int ShowMenu() {
    int mode;
    //printf("\E[42m");
    printf("1. Start\n");
    printf("2. Choose difficulty\n");
    printf("3. Results\n");
    printf("4. Exit\n");
    scanf("%d", &mode);
    while ( mode > 4 || mode < 0) {
	 scanf("%d", &mode);  
    }
    //printf("\e[0m");
    return mode;
}


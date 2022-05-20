#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <time.h> 
#define array_size 10

using namespace std;

int ShowMenu();
int govno(int, int);
float Start(int);
int ChooseDifficulty();
void Results();
void FileRead(FILE*, int, char*);
FILE* FileOpen(const char*);
int FileCheck(FILE*);
void TextOut(const char*, int);
int Rand_Row(FILE*, char*);
int include();
int InputTextOut(const char*);
void Offai(int, char);
void record(int, float);
void results();


int main()
{
	//FILE *input_file;
	//char text_array[512];
	//memset(text_array, 0, sizeof(text_array));
    //printf("\033[2J\033[1;1H");
    int mode = 0, dif = 1;
    //input_file = FileOpen("easyway.txt");
    //int i = FileCheck(input_file);
    while (1) {
        //printf("\033[2J\033[1;1H");
        mode = ShowMenu();
	if (mode == 4) {
            break;
        }
        dif = govno(mode, dif);
	if (dif == 0) {
	    dif = 1;	
	}
	printf("Level of dif %d\n", dif);
    }
    //printf("%d\n", i);
    //FileRead(input_file, 0, text_array);
    //TextOut(text_array);
    //InputTextOut(text_array);
    //printf("%s", text_array);
    return 0;
}

void results (){
	FILE *f;
	char p[1024];
	f=fopen ("record.txt","rb");
	int i=0;
	while (fread(p+i,sizeof(char),1,f))
	{ 
		printf("%c", p[i]);
		i++;
	}
	fclose(f);
}

void record (int ohib, float time){
	FILE *f;
	f = fopen("record.txt", "a");
	fprintf(f, "ohib = %d time = %f\n", ohib, time);
	fclose(f);
}

void Offai(int color, char symbol) {
       printf("\E[%dm", color);
       printf("%c", symbol);
       printf("\e[0m");
}

int InputTextOut(const char text_array[]) {
        char sym;
	int ohib=0;
        printf("\n ");
        //sym = include();
        for (long unsigned int i = 0; i < strlen(text_array) - 1;) 
        {
                int flag = 0;
                sym = include();
                if (sym == text_array[i]) {
                        flag = 1;
                        Offai(42, sym);
                        i++;
                }
                else {
                    Offai(41, sym);
                    printf("\b");
		    ohib++;
                }
                if (sym == '0') {
		    ohib--;
                    break;
                }
                if ((sym == '.' || sym == '?' || sym == '!') && flag != 0) {
		   printf("\n ");
                   i++;
                }
        }
        printf("\n");
        return ohib;
}

int include()
{
        struct termios oldattr, newattr;
        int ch;
        tcgetattr(0, &oldattr);
        newattr = oldattr;
        newattr.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(0, TCSANOW, &newattr);
        ch = getchar();
        while (ch < 32 || ch > 126) {
             ch = getchar();
        }
        tcsetattr(0, TCSANOW, &oldattr);
        return (ch);
}

void TextOut(const char text_array[], int knopka) {
    printf("\033[2J\033[1;1H ");
    if ( knopka == 3) {
        for (long unsigned int i = 0; i < strlen(text_array); i++) {
            printf("%c", text_array[i]);
            if (text_array[i] == '.' || text_array[i] == '?' || text_array[i] == '!') {
                printf("\n");
            }
        }
    }
    int flag = 0;
    int count = 0;
    if ( knopka != 3) {
         for (long unsigned int i = 0; i < strlen(text_array); i++) {
            printf("%c", text_array[i]);
            count++;
            if (count > 20) {
                count = 0;
                flag = 1;
            }
            if (flag == 1 && text_array[i] == ' ') {
                flag = 0;
                printf("\n ");
            }
	 }
    }
    //printf("%s", text_array);
}
 
void FileRead(FILE* input_file, int output_line, char text_array[]) {
	int i = 0;
	while (fgets(text_array, 512, input_file)) {
		if (i == output_line) {
			break;
		}
		i++;
	}
}
int Rand_Row(FILE* input_file, char text_array[]) {
	int i = 0;
	while (fgets(text_array, 512, input_file)) {
		i++;
	}
	return rand()%i;
}
int FileCheck(FILE* input_file) { 
	if (input_file) {
		return 1;
	}
	else {
		return 0;
	}
}

FILE* FileOpen(const char* file_name) {
	FILE* input_file = fopen(file_name, "rt");
	return input_file;
}

int govno(int mode, int dif) {
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
    rewind(input_file);
    FileRead(input_file, number_row, text_array);
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
    return mode;
}

void Results() {
    printf("\033[2J\033[1;1H");
    //printf("\nres\n");
    results ();
}

int ShowMenu() {
    int mode = 0;
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


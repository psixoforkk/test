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
void govno(int);
float Start();
void ChooseDifficulty();
void Results();
void FileRead(FILE*, int, char*);
FILE* FileOpen(const char*);
int FileCheck(FILE*);
void TextOut(const char*);
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
    int mode = 0;
    //input_file = FileOpen("easyway.txt");
    //int i = FileCheck(input_file);
    while (1) {
        //printf("\033[2J\033[1;1H");
        mode = ShowMenu();
        govno(mode); 
        if (mode == 4) {
            break;
        }
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
                sym = include();
                if (sym == text_array[i]) {
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
                if (sym == '.' || sym == '?' || sym == '!') {
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

void TextOut(const char text_array[]) {
    printf("\033[2J\033[1;1H ");
    for (long unsigned int i = 0; i < strlen(text_array); i++) {
        printf("%c", text_array[i]);
        if (text_array[i] == '.' || text_array[i] == '?' || text_array[i] == '!') {
            printf("\n");
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

void govno(int mode) {
    switch(mode) {
    case 1:
        printf("time= %f\n",Start());
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

float Start() {
    printf("\nstart\n");
    int ohib;
    float time;
    clock_t naz, konz; 
    naz = clock();
    FILE *input_file;
    char text_array[512];
    memset(text_array, 0, sizeof(text_array));
    input_file = FileOpen("easyway.txt");
    FileRead(input_file, 0, text_array);
    TextOut(text_array);
    ohib = InputTextOut(text_array);
    printf("ohib=%d  ",ohib);
    konz = clock();
    time = (float)(konz - naz)/CLOCKS_PER_SEC;
    record(ohib, time);
    return time; 
}

void ChooseDifficulty() {
    //printf("\033[2J\033[1;1H");
    printf("\ndif\n");
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
    //printf("\e[0m");
    return mode;
}


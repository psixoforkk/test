#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define array_size 10

using namespace std;

int ShowMenu();
void govno(int);
void Start();
void ChooseDifficulty();
void Results();
void FileRead(FILE*, int, char*);
FILE* FileOpen(const char*);
int FileCheck(FILE*);


int main()
{
	FILE *input_file;
	char text_array[100];
	memset(text_array, 0, sizeof(text_array));
    //printf("\033[2J\033[1;1H");
    //int mode = 0;
    input_file = FileOpen("easyway.txt");
    int i = FileCheck(input_file);
    /*while (1) {
        //printf("\033[2J\033[1;1H");
        mode = ShowMenu();
        govno(mode);
        if (mode == 4) {
            break;
        }
    }*/
    printf("%d\n", i);
    FileRead(input_file, 2, text_array);
    printf("%s", text_array);
    return 0;
}

void FileRead(FILE* input_file, int output_line, char text_array[]) {
	int i = 0;
	while (fgets(text_array, 100, input_file)) {
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
    //printf("\033[2J\033[1;1H");
    printf("\nstart\n");
}

void ChooseDifficulty() {
    //printf("\033[2J\033[1;1H");
    printf("\ndif\n");
}

void Results() {
    //printf("\033[2J\033[1;1H");
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


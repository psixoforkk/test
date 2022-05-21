#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <time.h> 

#define array_size 10

void FileRead(FILE*, int, char*, int);
FILE* FileOpen(const char*);
int FileCheck(FILE*);
void TextOut(const char*, int);
int RandRow(FILE*, char*);
int include();
int InputTextOut(const char*);
void ColorBackGround(int, char);
void record(int, float);
int Comparison(char, char);
void results();

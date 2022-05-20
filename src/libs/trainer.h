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
int Rand_Row(FILE*, char*);
int include();
int InputTextOut(const char*);
void Offai(int, char);
void record(int, float);
int Sravnenie(char, char);
void results();
int Sravnenie(char,char);

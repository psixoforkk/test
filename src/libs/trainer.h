#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define array_size 10

void FileRead(FILE*, int, char*, int);
FILE* FileOpen(const char*);
int FileCheck(FILE*);
void TextOut(const char*);
int include();
void InputTextOut(const char*);
void Offai(int, char);

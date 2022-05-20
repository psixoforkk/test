#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define array_size 10

void FileRead(FILE*, int, char*);
FILE* FileOpen(const char*);
int FileCheck(FILE*);

#include "trainer.h"

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



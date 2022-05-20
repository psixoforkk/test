#include "trainer.h"

void FileRead(FILE* input_file, int output_line, char text_array[], int checkfile) {
	int i = 0;
        if (checkfile){
	        while (fgets(text_array, 100, input_file)) {
		    if (i == output_line) {
			    break;
		    }
		    i++;
	    }
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

void Offai(int color, char symbol) {
       printf("\E[%dm", color);
       printf("%c", symbol);
       printf("\e[0m");
}

void InputTextOut(const char text_array[]) {
        char sym;
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
                }
                if (sym == '0') {
                    break;
                }
                if (sym == '.' || sym == '?' || sym == '!') {
                    printf("\n ");
                    i++;
                }
        }
        printf("\n");
        return;
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

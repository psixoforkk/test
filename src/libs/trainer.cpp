#include "trainer.h"

void FileRead(FILE* input_file, int output_line, char text_array[], int checkfile) {
	int i = 0;
        if (checkfile){
	        while (fgets(text_array, 512, input_file)) {
		    if (i == output_line) {
			    break;
		    }
		    i++;
	    }
        }
}

int RandRow(FILE* input_file, char text_array[]) {
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

void ColorBackGround(int color, char symbol) {
       printf("\E[%dm", color);
       printf("%c", symbol);
       printf("\e[0m");
}
int Comparison(char sym1, char sym2) {
    int res = 0;
    if (sym1 == sym2) {
        res = 1;
    }
    else {
        res = 0;
    }
    return res;
}
int InputTextOut(const char text_array[]) {
        char sym;
	int count_mistake=0;
        printf("\n ");
        //sym = include();
        for (long unsigned int i = 0; i < strlen(text_array) - 1;) 
        {
                int flag = 0;
                sym = include();
                if (Comparison(sym, text_array[i])) {
                        flag = 1;
                        ColorBackGround(42, sym);
                        i++;
                }
                else {
                    ColorBackGround(41, sym);
                    printf("\b");
		    count_mistake++;
                }
                if (sym == '0') {
		    count_mistake--;
                    break;
                }
                if ((sym == '.' || sym == '?' || sym == '!') && flag != 0) {
		   printf("\n ");
                   i++;
                }
        }
        printf("\n");
        return count_mistake;
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

void record (int count_mistake, float time){
	FILE *f;
	f = fopen("record.txt", "a");
	fprintf(f, "count of mistakes = %d time = %f\n", count_mistake, time);
	fclose(f);
}

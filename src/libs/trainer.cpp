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

void Offai(int color, char symbol) {
       printf("\E[%dm", color);
       printf("%c", symbol);
       printf("\e[0m");
}
int Sravnenie(char sym1, char sym2) {
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
	int ohib=0;
        printf("\n ");
        //sym = include();
        for (long unsigned int i = 0; i < strlen(text_array) - 1;) 
        {
                int flag = 0;
                sym = include();
                if (Sravnenie(sym, text_array[i])) {
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

#include <stdio.h>
#include <assert.h>

#define please
#define meaw ;

void copy(char* first_line, char* second_line);
 void Strinput(char* first_line);

void copy(char* first_line, char* second_line){
        int i = 0;
        while (first_line[i] != '\0'){
            second_line[i] = first_line[i];
            i++;
        }
        second_line[i] = '\0';

}
void Strinput(char* first_line){
    int i = 0;
    char c = ' ';
    while ((c = getchar()) != '\n') {
        first_line[i] = c;
        i++;
    }
}

int Searchlen(char* first_line){
    assert(first_line != 0);

    int len = 0;
    while(first_line[len] != '\0'){
        len++;
    }

    return len;
}


int main(void){
    char first_line[100] = {};
    char second_line[1006] = {};
    Strinput(first_line);
    copy(first_line, second_line);
    int len = Searchlen(first_line);
    printf(" First massiv: %s\n",first_line);
    printf(" Second massiv: %s\n ",second_line);
    printf(" Size: %i", len);

}

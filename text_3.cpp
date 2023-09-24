#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#define MAX_NUM 100
#define FILE_SIZE 5

char** Input_text_3(int* rows);
void Print_h(char** text_3, int rows);


char** Input_text_3 (int* rows) {
    FILE* file = fopen("input_massivs.txt", "r");  //char **str  = (char **)malloc(10);
    assert ( file != nullptr );

    //char* index = (char*) calloc(MAX_NUM * sizeof(char), sizeof(char));
    int i = 0;
    char buffer[100] = {};
    char ** text_3 = (char**) calloc(FILE_SIZE,sizeof(char*));

    while(true)
    {
        char *input = fgets((char*) buffer, MAX_NUM, file);
        if (input == NULL)
        {
            break;
        }

        int len = strlen(input);
        char* index = (char*)calloc ( ( len + 1 )  * sizeof ( char ), sizeof ( char ) );
        char* spot_for_cpy =  strncpy ( index,  buffer, len + 1 );
        text_3[i] = spot_for_cpy;
        i++;

        printf("text[i]: <%s> \n addres: %p \n len: %d \n input: %c \n \n", text_3[i], input, len, *input);
        printf("buffer:  <%s> \n addres: %c \n len: %d \n", buffer, *buffer, len);
        printf("spot_for_cpy: %s\n\n\n", spot_for_cpy);
    }

    *rows = i;

    return text_3;
}

void Print_h(char** text_3, int rows){
    for(int i = 0; i < rows; i++){
        printf("<%s> \n",*( text_3 + i ) );
    }
}

int main(){
    int rows = 0;
    //char ** text_3 = (char**) calloc(FILE_SIZE,sizeof(char*));
    char** New_text_3 = Input_text_3(&rows);
    Print_h( New_text_3 , rows );
}

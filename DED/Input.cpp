#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "struct_for_Onegin.h"
#include "sort_from_start.h"
#include "sort_end.h"
#include "Other_func.h"
#include "Input.h"
#include "Qsort_Onegin.h"

#define MAX_NUM 1000

int Size_of_text(int* Num_rows)
{
    FILE* file = fopen("Evgeniy_Onegin.txt", "r");

    assert ( file != nullptr );
    int size_of_file = 0;
    char input = 0;

    while ((input = fgetc(file)) != EOF)
    {
        size_of_file++;
        //printf("input = %c\n", input);
        //printf("Nomber of rows = %d\n", Num_rows);
        if (input == '\n')
        {
            (*Num_rows)++;
        }
    }
    //printf(" 1) Nomber of rows = %d\n", *(Num_rows));
    return size_of_file;
}


struct About_str* Input_text (int Num_rows, char* buffer, int size_of_text) {
    FILE* file = fopen("Evgeniy_Onegin.txt", "r");

    assert ( file != nullptr );


    int i = 0;
    int now_index_buf = 0;
    struct About_str* ab_str = ( struct About_str* ) calloc ( Num_rows + 1 , sizeof ( struct About_str ));
    //struct About_str ab_str[12] = {};
    while ( true )
    {
        char *input = fgets ( ( char* ) (buffer + now_index_buf), MAX_NUM, file );
        if ( input == NULL )
        {
            break;
        }

        int len = strlen ( input );
        //fprintf(stderr, "str = %s\n len = %d \n", input, len );
        char* index = ( char* ) calloc ( ( len + 1 ), sizeof ( char ) );
        char* spot_for_cpy =  strncpy ( index,  (buffer + now_index_buf), len + 1 );
        ab_str[i].str = spot_for_cpy;
        ab_str[i].len = len;
        now_index_buf = now_index_buf + ab_str[i].len;
        //fprintf(stderr, "str = <%s>\n len = %d \n", ab_str[i].str, ab_str[i].len );
        fprintf(stderr, " i = %2d: %s", i, ab_str[i].str);
        //getchar();
        i++;
        //printf("size_of_text = %d \n", *(size_of_text));
        //printf("text[i]: <%s> \n addres: %p \n len: %d \n input: %c \n \n", text[i-1], input, len, *input);
        //printf("buffer:  <%s> \n addres: %c \n len: %d \n", buffer, *buffer, len);
        //printf("spot_for_cpy: %s\n\n\n", spot_for_cpy);
    }
    //fprintf(stderr, "jvrbvrjvrbvrvkjruvefjrfugrorvhrjrhcrcrhrou \n");
    //*(size_of_text) = now_index_buf;
    return ab_str;
}

/*
int num_rows (int* Num_rows, char* buffer)
{
    FILE* file = fopen("Evgeniy_Onegin.txt", "r");

    assert ( file != nullptr );

    int i = 0;
    int now_index_buf = 0;
    while ( true )
    {
        char *input = fgets ( ( char* ) (buffer), MAX_NUM, file );
        (*Num_rows)++;
        if ( input == NULL )
        {
            break;
        }
        now_index_buf = now_index_buf + strlen(input);
        i++;
    }
    return now_index_buf;
}
*/

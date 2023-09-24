#include <stdio.h>
#include <stdlib.h>
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



void Clean_buf()
{
    while(getchar() != '\n')
        ;
}

//--------------------------------------------------------------------------

int Is_letter(char new_elem)
{
    return isalpha(new_elem); //ok (c) mentor
}

//--------------------------------------------------------------------------

void Print_h(struct About_text* ab_text, struct About_str* ab_str){
    assert(ab_text != NULL);
    assert(ab_str != NULL);

    //printf("rows = %d\n", ab_text->rows);
    for(int i = 0; i < (ab_text->rows); i++){
        printf("%s", ab_str[i].str );
    }
    printf("\n\n\n");
}

//--------------------------------------------------------------------------

int cmp_char(int first_elem , int second_elem)
{
    return (first_elem - second_elem);
}

//--------------------------------------------------------------------------

void fill_struct( struct About_text* ab_text, int* Num_rows, int size_of_text, char* buffer)
{
    assert(ab_text != NULL);

    ab_text -> rows = *Num_rows;
    ab_text -> text_size = size_of_text;
    ab_text -> id_buf = buffer;

    printf(" Num_rows =  %d \n", ab_text -> rows);
}

//--------------------------------------------------------------------------

void Make_file(struct About_text* ab_text, struct About_str* ab_str)
{
    assert(ab_text != NULL);
    assert(ab_str != NULL);

    FILE* output_file = fopen("Onegin_output.txt", "a");
    for (int i = 0; i < (ab_text ->rows); i++)
    {
        fputs((ab_str[i].str), output_file);
    }
    fputs("\n\n\n\n", output_file);
    fclose(output_file);
}

//--------------------------------------------------------------------------

void Print_buf( struct About_text ab_text )
{
    assert(ab_text.id_buf != NULL);
    assert(&ab_text != NULL);

    FILE* output_file = fopen("Onegin_output.txt", "a");
    for (int i = 0; i < ab_text.text_size; i++ )
    {
        if (*(ab_text.id_buf + i) == '\0')
        {
            fputc('\n', output_file);
        }
        else
        {
            fputc(*(ab_text.id_buf + i), output_file);
        }
    }
    fclose(output_file);
}

void Free_buf(struct About_text* ab_text, struct About_str* ab_str)
{
    free(ab_str);
    free(ab_text -> id_buf);
}

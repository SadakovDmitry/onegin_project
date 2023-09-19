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




#define MAX_NUM 10000
#define FILE_SIZE 100000
#define ROWS_TEXT 5318



int main()
{
    FILE* output_file = fopen("Onegin_output.txt", "w");

    struct About_text ab_text = {};
    //struct About_str ab_str[14] = {};
    int Num_rows = 0;

    int size_of_text = Size_of_text (&Num_rows);
    char* buffer = (char*) calloc (size_of_text + 1, sizeof(char));
    Num_rows = Num_rows - 1;
    //fprintf(stderr,"Number of rows = %d", size_of_text);

    struct About_str* ab_str = Input_text (Num_rows, buffer, size_of_text);


    //char* buffer = Do_massive (ab_text);
    //buffer = (char*) realloc(buffer, ab_text.text_size / 8);
    fill_struct( &ab_text, &Num_rows, size_of_text);
    //fprintf(stderr,"Number of rows = %d", Num_rows);

    Clean_buf();
    //Sort and print from start Onegin
    //Qsort(&ab_text, 0, Num_rows, ab_str);
    Sort_from_start(&ab_text, ab_str);

    Print_h(&ab_text, ab_str);

    Make_file(&ab_text, ab_str);
    // Sort and print from end Onegin
    Sort_from_end(&ab_text, ab_str);

    Print_h(&ab_text, ab_str);

    Make_file(&ab_text, ab_str);
    // Print Original_Onegin
    Print_buf(buffer, ab_text);

}

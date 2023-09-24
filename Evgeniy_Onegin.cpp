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


int main()
{
    struct About_text ab_text = {};
    char* buffer = NULL;
    int Num_rows = 0;

    struct About_str* ab_str = Work_with_input_file(&ab_text, buffer, &Num_rows);

    //Sort and print from start Onegin
    Qsort(&ab_text, 0, Num_rows - 1, ab_str);
    //Sort_from_start(&ab_text, ab_str);

    Print_h(&ab_text, ab_str);

    Make_file(&ab_text, ab_str);
    // Sort and print from end Onegin
    Sort_from_end(&ab_text, ab_str);

    Print_h(&ab_text, ab_str);

    Make_file(&ab_text, ab_str);
    // Print Original_Onegin
    Print_buf(ab_text);

    Free_buf(&ab_text, ab_str);
    // print function for free buffer
}

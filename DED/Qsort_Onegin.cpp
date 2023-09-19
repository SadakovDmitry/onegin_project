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

void deviser(struct About_text* ab_text, int* start, int* end, char* mid_elem, int* previous_start, int* previous_end, int* mid_id, struct About_str* ab_str)
{
    //Print_ans(massiv, 0, LEN_MASSIV, *start, *end);
    //printf("\n");

    while( *start < *end )
    {
        //Print_h(*ab_text);
        //printf("\n 1 :: result of cmp = %d\n, start = %d, end = %d \n", cmp_str((ab_text -> id_text)[*start], mid_elem), *start , *end);
        while( (cmp_str(ab_str[*start].str, mid_elem) == 0) && (*start < *end ))
        {
            //printf("\n 1 :: result of cmp = %d\n, start = %d, end = %d \n", cmp_str((ab_text -> id_text)[*start], mid_elem), *start , *end);

            (*start)++;
            /*
            Print_ans(massiv, *previous_start, *previous_end + 1, *start, *end);
            printf("\n 1) mid_id = %d, mid_elem = %d, start = %2d, end = %2d, now_elem = %d", *mid_id, *mid_elem, *start, *end, massiv[*start]);
            getchar();
            */
        }

        while( (cmp_str( mid_elem, ab_str[*end].str) == 0 ) && (*start < *end ))
        {
            //printf("\n 2 :: result of cmp = %d \n", cmp_str( mid_elem,(ab_text -> id_text)[*end]));
            (*end)--;
            /*Print_ans(massiv, *previous_start, *previous_end + 1, *start, *end);
            printf("\n 2) mid_id = %d, mid_elem = %d, end = %2d, start = %2d, now_elem = %d", *mid_id, *mid_elem, *end, *start, massiv[*end]);
            getchar();
            */
        }

        if ( *start != *end )
        {
            struct About_str tmp = ab_str[*end];
            ab_str[*end] = ab_str[*start];
            ab_str[*start] = tmp;

        if ( *mid_id == *start ||  cmp_str(ab_str[*start].str, ab_str[*end].str) == -1 )
        {
            (*start)++;
            //printf("\n\n\n\n mid_id = %d \n\n\n\n\n", *mid_id);
        }

        else if ( *mid_id == *end )
        {
            (*end)--;
            //printf("\n\n\n\n mid_id = %d \n\n\n\n\n", *mid_id);
        }

        //Print_h(*ab_text);

        /*
        Print_ans(massiv, *previous_start, *previous_end + 1, *start, *end);
        printf("\n 2) mid_id = %d, mid_elem = %d, end = %2d, start = %2d, now_elem = %d", *mid_id, *mid_elem, *end, *start, massiv[*end]);
        getchar();
        */
        Print_h(ab_text, ab_str);
        getchar();

        }

    }

}

void Qsort(struct About_text* ab_text, int start, int end, struct About_str* ab_str)
{

    int rows = end - start + 1;
    char* mid_elem = ab_str[ start + rows/2].str;
    //printf("mid elem = %s, id = %d\n",ab_str[ start + rows/2].str , start + rows/2);
    int mid_id = start + (int) rows/2;
    int previous_start = start;
    int previous_end   = end;

    deviser(ab_text, &start, &end, mid_elem, &previous_start, &previous_end, &mid_id, ab_str);

    //Print_ans(massiv, 0, 13, start, end);
    //printf("\n --------------------------start = %d, end = %d \n", start, end);

    mid_id = fmin(start, end);
    start = previous_start;
    end = previous_end;

    //printf("\n first : start = %d, end = %d, mid_id = %d \n\n", previous_start, previous_end, mid_id);
    //getchar();

    if ( start < mid_id )
    {
        Qsort ( ab_text, start, mid_id - 1, ab_str);
    }

    //printf("\n second : start = %d, end = %d, mid_id = %d \n\n", previous_start, previous_end, mid_id);
    //getchar();

    if ( end > mid_id )
    {
        //printf(" OK \n");
        Qsort ( ab_text, mid_id , end, ab_str);

    }
}

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

int cmp_str_from_end ( char* first_str, char* second_str , int num_of_row , struct About_str* ab_str)
{
    //printf ("cmp_str:\nfirst_str  = <%s>, \nsecond_str = <%s>\n", first_str, second_str);

    assert(first_str != NULL);
    assert(second_str != NULL);

    int i = ab_str[num_of_row - 1].len; //krivo
    int j = ab_str[num_of_row].len;
    while (true)
    {
        char first_elem  = (char) tolower ( *( first_str  + i) );
        char second_elem = (char) tolower ( *( second_str + j) );

        //printf("\nstart turn: <%c vs %c> \n \n", first_elem, second_elem);
        //Clean_buf();
        //getchar();
        if (i == 0 || j == 0)
        {
            return 0;

        }

        if (! Is_letter ( first_elem ) && ! Is_letter ( second_elem ))
        {
            //printf ("if1: %c vs %c: i-- (%d -> %d), j-- (%d -> %d)\n", first_elem, second_elem, i, i-1, j, j-1);
            i--;
            j--;
            continue;
        }

        if (! Is_letter ( first_elem ) &&   Is_letter ( second_elem ))
        {
            //printf ("if2: %c vs %c: i++ (%d -> %d)\n", first_elem, second_elem, i, i-1);
            i--;
            continue;
        }

        if (  Is_letter ( first_elem ) && ! Is_letter ( second_elem ))
        {
            //printf ("if3: %c vs %c: j++ (%d -> %d)\n", first_elem, second_elem, j, j-1);
            j--;
            continue;
        }

        if (cmp_char(first_elem, second_elem ) > 0)
        {
            //printf ("if4: %c vs %c: sitching to strcmp (%s, %s) > 0\n", first_elem, second_elem, first_str + i, second_str + j);
            return 1;
        }

        if (cmp_char(first_elem, second_elem ) < 0)
        {
            //printf ("if5: %c vs %c: sitching to strcmp (%s, %s) < 0\n", first_elem, second_elem, first_str + i, second_str + j);
            return 0;
        }

        i--;
        j--;
        //printf ("next turn: %c vs %c: i-- (%d -> %d), j-- (%d -> %d)\n", first_elem, second_elem, i, i-1, j, j-1);
    }
}


void Sort_from_end( struct About_text* ab_text, struct About_str* ab_str)
{
    assert(ab_text != NULL);
    assert(ab_str != NULL);

    for ( int j = 1; j < (ab_text -> rows); j++ )
    {
        //printf("now row: %d", j);
        for ( int i = 1; i < (ab_text -> rows); i++ )
        {
            if (cmp_str_from_end(ab_str[i - 1].str, ab_str[i].str, i, ab_str))
            {
                struct About_str tmp = ab_str[i];
                ab_str[i] = ab_str[i-1];
                ab_str[i-1] = tmp;
            }
        }
    }
}

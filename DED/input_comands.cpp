#include <stdio.h>
#include <string.h>
#include <math.h>
#include "input_comands.h"

//--------------------------------------------------------------------

int* Do_massive (int num_of_commands)
{
    int num_of_matches = (num_of_commands + 1) * num_of_commands/2;
    int* matches = (int*) calloc (num_of_matches, sizeof (int));
    return matches;
}

//--------------------------------------------------------------------

void PrintTryangle (const int* matches, int num_of_commands){
    int previous_simbols = 0;
    for (int i = 0; i < num_of_commands; i++){
        previous_simbols = previous_simbols + i;
        for (int j = 0; j < i + 1 ; j++){
            if (i != j)
            {
                printf ("(%2d, %2d) %2d  ", i + 1, j + 1, * (matches + previous_simbols + j));
            }
            else
            {
                printf ("(%2d, %2d)  x  ", i + 1, j + 1);
            }
        }
        printf ("\n");
    }
    printf ("\n");
}

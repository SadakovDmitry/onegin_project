#include "Cheks.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>


void Clean_buf()
{
    while(getchar() != '\n')
        ;
}


void Strinput(char* input_str){
    int i = 0;
    char c = ' ';
    while ((c = getchar()) != '\n') {
        input_str[i] = c;
        i++;
    }

}


int Cmp_two_str(char* input_str, char* answer)
{
    int len = strlen(input_str);
    int i = 0;
    while (*(input_str + i) == *(answer + i))
    {
        i++;
    }
    if (i == len + 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

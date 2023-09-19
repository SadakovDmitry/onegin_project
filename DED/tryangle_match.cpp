#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include "input_comands.h"
#include "Cheks.h"
#include "chenge_massiv.h"



#define MAX_NUM 100



int main()
{
    int num_of_commands = 0;
    printf("Print number of comands: ");
    scanf("%d", &num_of_commands);
    while(getchar() != '\n')
        ;
    int* matches = Do_massive(num_of_commands);
    PrintTryangle( matches, num_of_commands);

    setElem(matches, num_of_commands);

    PrintTryangle( matches, num_of_commands);
    //Chenge_other_command(matches, num_of_commands);
    Best_vershion_of_change(matches, num_of_commands);

}

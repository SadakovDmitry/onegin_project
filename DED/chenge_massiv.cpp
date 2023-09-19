#include <stdio.h>
#include <string.h>
#include <math.h>
#include "chenge_massiv.h"
#include "input_comands.h"
#include "Cheks.h"

void chenge_massiv(int first_comand, int second_comand, int balls, int matches)
{
    if (first_comand == second_comand)
    {
        printf("This commands can't play together, please print correct commands!!! \n");
        setElem(matches, num_of_commands);
    }
    else if (first_comand > second_comand)
    {
        int num_of_matches_befor = (first_comand) * (first_comand - 1) / 2;
        int* changed_results = matches + num_of_matches_befor + second_comand - 1;

        *(changed_results) = balls + *(changed_results);
        printf("OK\n\n");
    }
    else
    {
        int num_of_matches_befor = (second_comand) * (second_comand - 1) / 2;
        int* changed_results = matches + num_of_matches_befor + first_comand - 1;

        *(changed_results) = - balls + *(changed_results);
        printf("OK\n\n");
    }
}

void setElem(int* matches, int num_of_commands){
    int first_comand = 0;
    int second_comand = 0;
    int balls = 0;
    printf("Please print which comands played and number of balls in their play: ");
    scanf("%d %d %d", &first_comand, &second_comand, &balls);

    Clean_buf();

    int num_wrong_ans = 0;

    while (first_comand > num_of_commands || second_comand > num_of_commands)
    {
        if (num_wrong_ans == 0)
        {
            printf("There are no commands whith these numbers!!! Try again!!! \n ");
        }
        else if (num_wrong_ans == 1)
        {
            printf("Please switch on your brane snd try again !!! \n ");
        }
        else if (num_wrong_ans == 2){
            printf("Oh sheet!!! Why are you so stupid ? Try again !!!!!!!!\n ");
        }
        else if (num_wrong_ans >= 3){
            printf("Please print ctrl_C and go out you are too stupid for this program !!!\n ");
        }

        scanf("%d %d %d", &first_comand, &second_comand, &balls);
        num_wrong_ans++;
        Clean_buf();
    }
    chenge_massiv(first_comand, second_comand, balls, matches);
}


void Chenge_other_command(int* matches, int num_of_commands)
{
    while (true)
    {
        printf("Do you want change anything else? Print 1 if yes or 0 in no. \n");

        int input = 0;
        scanf("%d", &input);

        if (input == 1)
        {
            setElem(matches, num_of_commands);
            PrintTryangle( matches, num_of_commands);
        }
        else if (input == 0)
        {
            printf("Thank you !!! \n");
            break;
        }
        else
        {
            printf("Please print correct equal !!! \n");
        }
    }
}


void Best_vershion_of_change(int* matches, int num_of_commands)
{
    while (true)
    {
        printf("Do you want change anything else? Print YES or NO. \n");
        //char* input = 0;
        char input_str[99] = {};
        char answer_yes[4] = "yes";
        char answer_YES[4] = "YES";

        Strinput(input_str);
        //printf("<%s>\n", input_str);
        //printf("<%s>\n", answer);

        if (Cmp_two_str(input_str, answer_yes) || Cmp_two_str(input_str, answer_YES))
        {
            setElem(matches, num_of_commands);
            PrintTryangle( matches, num_of_commands);
        }
        else
        {
            printf("Thank you goodbye!!! \n");
            break;
        }
    }
}

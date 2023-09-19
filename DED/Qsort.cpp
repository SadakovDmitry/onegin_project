#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define LEN_MASSIV 13


void qsort(int* massiv, int start, int end, int prev_flag /* 1 or -1 */);
void Print_ans(int* massiv, int start, int end, int now_start, int now_end);
void deviser(int* massiv, int* start, int* end, int* mid_elem, int* previous_start, int* previous_end, int* mid_id);
void Qsort(int* massiv, int start, int end);


 //void qsort(int* massiv, int start, int end, int prev_flag /* 1 or -1 */)
/*{
    int rows = end - start + 1;
    int mid_elem = massiv[ (int) rows/2 ];
    int mid_id = rows/2;
    int i = 0;
    int previous_start  = start;
    int previous_end =   end;
    //int mid_elem = (int) rows/2;

    //Print_ans(massiv, rows);
    //printf("\n mid_id = %d , mid_elem = %d, i = %d, now_elem = ", mid_id, mid_elem, i, massiv[i],);

    while( start <= end )
    {
        //Print_ans(massiv, start, end);
        printf("\n mid_id = %d , mid_elem = %d, i = %d, now_elem = %d", mid_id, mid_elem, i, massiv[i]);
        getchar();


        if ((mid_elem >= massiv[i] && prev_flag == -1) || (mid_elem <= massiv[i] && prev_flag == 1))
        {
            prev_flag = prev_flag * -1;

            if (prev_flag == 1)
            {
                if ( start == mid_id )
                {
                    mid_id = end;
                }
                else if ( end == mid_id )
                {
                    mid_id = start;
                }

                int id = massiv[end];
                massiv[end] = massiv[start];
                massiv[start] = id;

                end--;
                start++;
                i = start;
            }
            else
            {
                i = end;
            }
        }
        else if(prev_flag == 1)
        {
            start++;
            i++;
        }
        else
        {
            end--;
            i--;
        }

    }

    printf("\n first : previous_start = %d, raght_end = %d, mid_id = %d \n\n", previous_start, previous_end, mid_id);
    //int left_end_for_sec =  previous_end;
    //int right_end_for_sec = ;
    //int prev = mid_id;
    //mid_id = start;
    start = previous_start;
    end = previous_end;

    if ( start < mid_id )
    {
        qsort ( massiv, start, mid_id - 1, 1 );
    }

    printf("\n second : start = %d, end = %d, mid_id = %d \n\n", previous_start, previous_end, mid_id);

    if ( end > mid_id )
    {
        printf("OK");
        qsort ( massiv, mid_id , end, 1 );

    }
}*/

//-----------------------------------------------------------------------------------

void deviser(int* massiv, int* start, int* end, int* mid_elem, int* previous_start, int* previous_end, int* mid_id)
{
    //Print_ans(massiv, 0, LEN_MASSIV, *start, *end);
    //printf("\n");

    while( *start < *end )
    {

        while( massiv[*start] < *mid_elem && *start < *end )
        {
            (*start)++;
            /*
            Print_ans(massiv, *previous_start, *previous_end + 1, *start, *end);
            printf("\n 1) mid_id = %d, mid_elem = %d, start = %2d, end = %2d, now_elem = %d", *mid_id, *mid_elem, *start, *end, massiv[*start]);
            getchar();
            */

            //(*start)++;
        }

        while( massiv[*end] > *mid_elem && *start < *end )
        {
            (*end)--;
            /*Print_ans(massiv, *previous_start, *previous_end + 1, *start, *end);
            printf("\n 2) mid_id = %d, mid_elem = %d, end = %2d, start = %2d, now_elem = %d", *mid_id, *mid_elem, *end, *start, massiv[*end]);
            getchar();
            */
            //(*end)--;
        }

        if ( *start != *end )
        {
        int id = massiv[*end];
        massiv[*end] = massiv[*start];
        massiv[*start] = id;
        /*if (massiv[*start] == massiv[*end])
        {

            //(*end)--;
            (*start)++;

        }*/

        if ( *mid_id == *start ||  massiv[*start] == massiv[*end])
        {
            (*start)++;
            //printf("\n\n\n\n mid_id = %d \n\n\n\n\n", *mid_id);
        }

        else if ( *mid_id == *end )
        {
            (*end)--;
            //printf("\n\n\n\n mid_id = %d \n\n\n\n\n", *mid_id);
        }

        //(*end)--;
        //(*start)++;

        /*
        Print_ans(massiv, *previous_start, *previous_end + 1, *start, *end);
        printf("\n 2) mid_id = %d, mid_elem = %d, end = %2d, start = %2d, now_elem = %d", *mid_id, *mid_elem, *end, *start, massiv[*end]);
        getchar();
        */

        //(*end)--;
        //(*start)++;
        }
    }

}

void Qsort(int* massiv, int start, int end)
{

    int rows = end - start + 1;
    int mid_elem = massiv[ start + (int) rows/2 ];
    int mid_id = start + (int) rows/2;
    int previous_start = start;
    int previous_end   = end;

    deviser(massiv, &start, &end, &mid_elem, &previous_start, &previous_end, &mid_id);

    //Print_ans(massiv, 0, 13, start, end);
    //printf("\n --------------------------start = %d, end = %d \n", start, end);

    mid_id = fmin(start, end);
    start = previous_start;
    end = previous_end;

    //printf("\n first : start = %d, end = %d, mid_id = %d \n\n", previous_start, previous_end, mid_id);
    //getchar();

    if ( start < mid_id )
    {
        Qsort ( massiv, start, mid_id - 1);
    }

    //printf("\n second : start = %d, end = %d, mid_id = %d \n\n", previous_start, previous_end, mid_id);
    //getchar();

    if ( end > mid_id )
    {
        //printf(" OK \n");
        Qsort ( massiv, mid_id , end);

    }
}

//---------------------------------------------------------------------

void Print_ans ( int* massiv, int start, int end , int now_start, int now_end)
{
    for (int i = start; i < end; i++)
    {
        if (i == now_start)
        {
            printf(" < ");
        }

        printf("%2d ", massiv[i]);

        if (i == now_end)
        {
            printf(" > ");
        }
    }
}

//---------------------------------------------------------------------

int main()
{
    //int massiv[] = {2, 10, 3, 5, 81, 4, 9, 7, 5, 56, 11, 19, 44};
    //int massiv[] = {4, 8, 45, 67, 3, 80, 7, 10, 26, 7, 35, 26, 14, 57, 44};
    //int massiv[] = {6, 7, 2, 9, 1};
    //int massiv[] = {8, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 8};
    int massiv[] = {1, 14, 23, 3, 45, 56, 2, 14, 2, 6, 7, 57, 10, 20};
    //int massiv[] = {9, 1, -9, 2, 0, 3, 9};


    //qsort(massiv, 0, 12, 1);
    Qsort(massiv, 0, LEN_MASSIV - 1);
    Print_ans(massiv, 0, LEN_MASSIV, 0, LEN_MASSIV - 1);
}


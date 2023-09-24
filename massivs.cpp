#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 100

void readind_massive(const char* text_1);
void PrintTryangle(const int* tryangle_massiv, int rows);
void PrintRect(const int* rect_massiv, int rows, int cols);
void Massive_with_indicator(const int* indicated_massiv);
int getElem(int* data, int i, int j, int syze_x, int syze_y);
int setElem(int* data, int i, int j, int syze_x, int syze_y, int new_elem);


void PrintTryangle(const int* tryangle_massiv, int rows){
    int previous_simbols = 0;
    for (int i = 0; i < rows; i++){
        previous_simbols = previous_simbols + i;
        for (int j = 0; j < i + 1 ; j++){
            printf("%2d ", *(tryangle_massiv + previous_simbols + j));
        }
        printf("\n");
    }
    printf("\n");
}

void PrintRect(const char* rect_massiv, int rows, int cols){
    for(int i = 0; i < rows; i++){
        printf("%d: <", i);
        for (int j = 0; j < cols; j++){
              printf("%c",*(rect_massiv + i * cols + j));
//            printf("%c (%d) ",*(rect_massiv + i * cols + j), *(rect_massiv + i * cols + j));
        }
        printf(">\n");
    }
    printf("\n");
}

void Massive_with_indicator(const int* indicated_massiv){
    int size_x = *indicated_massiv;
    int size_y = *(indicated_massiv + 1);
    for(int i = 0; i < size_x; i++){
        for(int j = 0; j < size_y; j++){
            printf("%2d", *(indicated_massiv + i * size_y + j));
        }
        printf("\n");
    }
    printf("\n");
}

void readind_massive(char* text_1){
    FILE * file = fopen("input_massivs.txt", "r");
    assert(file != nullptr);

    int i = 0;
    while(true){
        char* input = fgets(text_1 + i * 10, MAX_NUM, file);

        printf ("readind_massive: i = %d, <%s>, input = <%s>\n",
                i, text_1 + i * 10, input);
        i++;

        if (input == NULL){
            break;
        }
    }
    fclose(file);
}



int getElem(int* data, int i, int j, int syze_x, int syze_y){
    assert(i < size_x);
    assert(j < size_y);

    return *(data + j*(i - 1) + i);
}



int setElem(int* data, int i, int j, int syze_x, int syze_y, int new_elem){
    assert(i < size_x);
    assert(j < size_y);

    int pr_elem = *(data + j*(i - 1) + i);
    data[i][j] = new_elem;
    return pr_elem;
}



int main(void){
    int tryangle_massiv[15] =  {0,
                                2, 3,
                                -2, -1, 7,
                                5, 8, 10, 0,
                                0, 1, 8, 9, -3};

    int rect_massiv[5][5] = {{1, 2, 3, 4, 5},
                             {2, 3, 4, 5, 6},
                             {3, 4, 5, 6, 7},
                             {4, 5, 6, 7, 8},
                             {5, 6, 7, 8, 9}};

    int indicated_massiv[14] = {3, 4,
                                9, 8, 7, 6,
                                8, 7, 6, 5,
                                7, 6, 5, 4};
    char text_1[10][10] = {};
    char text_3_first[100] = {};

    char * text_3[100] = {};

    //char (*text_3) = text_3_first;



    int rows = 5;
    //PrintTryangle(tryangle_massiv, rows);
    //Massive_with_indicator(indicated_massiv);
    //readind_massive(( char*) text_1);
    //PrintRect((const char*)text_1, 10, 10);
    int i = 4;
    int j = 3;
    int size_y = 5;
    int size_x = 5;
    int new_elem = 11;
    setElem((const int*) rect_massiv, i, j, size_x, size_y, new_elem);
    PrintRect((const int*)rect_massiv, ROWS, COLS);
}

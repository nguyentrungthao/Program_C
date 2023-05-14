#include "..\headers\caculation.h"
#include <stdio.h>
#include <math.h>

void rectangular(int a, int b)
{
    int i, j;
    for (i = 1; i <= a; i++){
        for (j = 1; j <= b; j++){
            if(1 == i || a == i || 1 == j || b == j){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}

void triangle(int a)
{
    int i, j;
    for (i = 1; i <= a; i++){
        for (j = 1; j < 2 * a; j++){
            if(abs(a - j) <= i - 1){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}
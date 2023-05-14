#include <stdio.h>
#include <stdlib.h>
#define N 10001

void nhap(int **a, int *n, int *b)
{
    int i = 0;
    while (b[i])
    {
        if (*n == 0)
        {
            *a = (int *)malloc(sizeof(int));
        }
        else
        {
            *a = (int *)realloc(*a, (*n + 1) * sizeof(int));
        }
        *(*a + *n) = b[i];
        (*n)++;
        i++;
    }
}

int main()
{
    int *a;
    int b[N];
    int n = 0;

    for (int i = 0; i < N - 1; i++)
    {
        b[i] = i + 1;
    }
    b[N - 1] = 0;

    nhap(&a, &n, b);

    for (int i = 0; i < n; i++)
    {
        printf("%-5d", a[i]);
    }

    free(a);
    return 0;
}
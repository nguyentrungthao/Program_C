#include "..\headers\array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int nhapN()
{
    int n;
    printf("so luong phan tu : ");
    scanf("%d", &n);
    return n;
}

void swap(int *a, int *b)
{
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

void vector(int **arr, int *size)
{
    int x;
    printf("\t\t DUNG KHI NHAP KY TU\n");
    while (1)
    {
        printf("a[%d] = ", *size);
        if (true == !scanf("%d", &x))
        {
            break;
        }
        if (*size == 0)
        {
            *arr = (int *)malloc(sizeof(int));
        }
        else
        {
            *arr = (int *)realloc(*arr, ((*size) + 1) * sizeof(int));
        }
        *(*arr + *size) = x;
        (*size)++;
    }
}

void input(int *arr, int size)
{
    printf("\n\n\t\t NHAP MANG \n");
    for (int i = 0; i < size; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

void output(int *arr, int size)
{
    printf("\n\n\t\t XUAT MANG \n");
    for (int i = 0; i < size; i++)
    {
        printf("%-10d", arr[i]);
    }
}

void insertion(int *arr, int size, int mode)
{ // CẦN XEM LẠI
    int i, j, x;
    if (12 == mode)
    {
        for (i = 1; i < size; i++)
        {
            x = arr[i];
            for (j = i; j > 0 && x < arr[j - 1]; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[j] = x;
        }
    }
    // cần xem lại
    else if (21 == mode)
    {
        for (i = 1; i < size; i++)
        {
            x = arr[i];
            for (j = i; j > 0 && x > arr[j - 1]; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[j] = x;
        }
    }
    else
    {
        printf("\n\n\t\tSAI CHE DO\n\n");
    }
}

void selection(int *arr, int size, int mode)
{
    int i, j;
    if (12 == mode)
    {
        for (i = 0; i < size; i++)
        {
            for (j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                {
                    swap(arr + i, arr + j);
                }
            }
        }
    }
    else if (21 == mode)
    {
        for (i = 0; i < size; i++)
        {
            for (j = i + 1; j < size; j++)
            {
                if (arr[i] < arr[j])
                {
                    swap(arr + i, arr + j);
                }
            }
        }
    }
    else
    {
        printf("\n\n\t\tSAI CHE DO\n\n");
    }
}

void delete_arr(int **arr, int *size, int position)
{
    int i;
    for (i = position; i < *size - 1; i++)
    {
        *(*arr + i) = *(*arr + i + 1);
    }
    *arr = (int *)realloc(*arr, ((*size) - 1) * sizeof(int));
    (*size)--;
}

void add_arr(int **arr, int *size, int number, int position)
{
    int i;
    *arr = (int *)realloc(*arr, ((*size) + 1) * sizeof(int));

    for (i = *size; i > position; i--)
    {
        *(*arr + i) = *(*arr + i - 1);
    }
    *(*arr + i) = number;

    (*size)++;
}

int find_position(int *arr, int size, int x)
{
    int last = 0, first = size - 1;
    if (arr[first] < x)
    {
        return size;
    }
    int mid = (first - last) / 2;
    while (last <= first)
    {
        if (arr[mid] > x)
        {
            if (arr[mid - 1] < x)
            {
                return mid;
            }
            first = mid - 1;
        }
        else if (arr[mid] < x)
        {
            if (arr[mid + 1] > x)
            {
                return mid + 1;
            }
            last = mid + 1;
        }
        else
        {
            return mid + 1;
        }
        mid = (first - last) / 2;
    }
    return 0;
}

void auto_add(int **arr, int *size, int number)
{
    int position = find_position(*arr, *size, number);
    add_arr(arr, size, number, position);
}

int find_number_binary(int *arr, int size, int number)
{
    int last = 0, first = size - 1;
    int mid = (first + last) / 2;
    while (last <= first)
    {
        if (arr[mid] == number)
        {
            return mid;
        }
        if (arr[mid] < number)
        {
            last = mid;
        }
        else
        {
            first = mid;
        }
        mid = (first + last) / 2;
    }
    return -1;
}
int find_all_number_binary(int *arr, int size, int number, int *all_of_number)
{
    int i = -1;
    int last = 0, first = size - 1;
    int mid = (first + last) / 2;
    while (last <= first)
    {
        if (arr[mid] == number)
        {
            int n = 0;
            i = 0;
            while (arr[mid + n] == number)
            {
                all_of_number[i] = mid + n;
                i++;
                n++;
            }
            n = -1;
            while (arr[mid + n] == number)
            {
                all_of_number[i] = mid + n;
                i++;
                n--;
            }
            break;
        }
        if (arr[mid] < number)
        {
            last = mid + 1;
        }
        else
        {
            first = mid - 1;
        }
        mid = (first + last) / 2;
    }
    return i;
}

int find_number_linear(int *arr, int size, int number)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == number)
            return i;
    }
    return -1;
}
int find_all_number_linear(int *arr, int size, int number, int *all_of_number)
{
    int i, n = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == number)
        {
            all_of_number[n] = i;
            n++;
        }
    }
    return n;
}

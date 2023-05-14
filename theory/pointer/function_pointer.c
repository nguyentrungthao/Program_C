#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

#define enter printf("\n")

void swap(int* a, int* b) {
    int tam = *a;
    *a = *b;
    *b = tam;
}

bool ascending(int left, int right)
{
    return left > right;
}

bool descending(int left, int right)
{
    return left < right;
}

bool evensFirst(int left, int right)
{
    //if left is even and right is odd, not need to swap
    if ((left % 2 == 0) && (right % 2 != 0))
        return false;

    //if left is odd and right is even, swap this couple
    if ((left % 2 != 0) && (right % 2 == 0))
        return true;

    return ascending(left, right);
}


// đối với C++ có thao tác khởi tạo sẵn các giá trị cho tham số truyền vào của hàm 
// void ht(int a = 3)
// trong main()
// ht() => a = 3 
// ht(7) => a = 7
void selectionSort(int* arr, int length, bool (*comparisonFunc)(int, int))
{
    for (int i_start = 0; i_start < length; i_start++)
    {
        int minIndex = i_start;

        for (int i_current = i_start + 1; i_current < length; i_current++)
        {
            if (comparisonFunc(arr[minIndex], arr[i_current])) // use function pointer as ascending or descending function
            {
                minIndex = i_current;
            }
        }

        swap(&arr[i_start], &arr[minIndex]);
    }
}

void printArray(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%-5d", arr[i]);
    }
}

int main()
{
    int arr[] = { 1, 4, 2, 3, 6, 5, 8, 9, 7 };
    int length = sizeof(arr) / sizeof(int);

    printf("Before sorted: \t");
    printArray(arr, length);

    selectionSort(arr, length, ascending);
    enter;
    printf("tang dan: \t");
    printArray(arr, length);

    selectionSort(arr, length, descending);
    enter;
    printf("giam dan: \t");
    printArray(arr, length);

    return 0;
}
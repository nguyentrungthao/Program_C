#include <stdio.h>
#include <math.h>
#include <stdlib.h> // dùng malloc caplloc realloc
// #define N (int)(pow(2, 31) - 1)
#define endl printf("\n")

// đếm số phần tử trong mảng;
// áp dụng cho mảng tĩnh
// ko nên đưa vào hàm riêng vì mảng sẽ suy biến thành con trỏ có kích thước là 4byte
int count_amount_arr(int* a) {
    return sizeof(a) / sizeof(a[0]);
}
// giới hạn phần tử tối đa là 2^31 - 1 ~ 2 tỷ phần tử
// void declere_arrays(int* a) {
//     int a[N];
// }

// siêu mảng động tự động cập nhật số phần tử

// void nhap_mang(int *a, int *n){
//     while(1){
//         int x; 
//         if(scanf("%d", &x)){
//             if((*n) == 0){
//                 a = (int *)malloc(sizeof(int));
//             }
//             else{
//                 realloc(a, (*n) * sizeof(int));
//             }
//             a[*n] = x;
//             ++(*n);
//         }
//         else{
//             break;
//         }
//     }
// }

void xuat_mang(int *a, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

int main() {
    int *a;
    int n = 0;
    int x;
    // nhap_mang(a, &n);
    while (scanf("%d", &x))
    {
        if (n == 0)
        {
            a = (int *)malloc(sizeof(int));
        }
        else
        {
            a = (int *)realloc(a, n * sizeof(int));
        }
        a[n] = x;
        ++n;

    }
    endl;
    xuat_mang(a, n);
    endl;

    free(a);
    return 0;
}
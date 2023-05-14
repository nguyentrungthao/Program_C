/*
                        LIỆT KÊ HOÁN VỊ
- khởi tạo mảng từ 1 -> n
    XUẤT CẤU HÌNH HIỆN TẠI 
-  i : (n - 1; 0) tìm vị trí phần tử nghịch thế đầu tiên (tức là phần tử a[i] < a[i + 1])
    + i < 0 => cấu hình cuối
- tìm số nhỏ nhất trong khoản i:(i+1; n-1) NHƯNG LỚN HƠN a[i] vị trí là x (có thể dùng tìm kiếm nhị phân)
    + hoán đổi a[x] và a[i]
- hoán đổi các phần tử a[i+1 + j ] và a[n-1 - j            

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void initialize(int* a, int n) {
    for (int i = 1; i <= n; ++i) {
        a[i] = 1;
    }
}

void swap(int* a, int* b) {
    int tem = *a;
    *a = *b;
    *b = tem;
}

int find_position(int* a, int n) {
    int i = n - 1;
    while (a[i] < a[i - 1] && i > 0) {
        --i;
    }
    return i; // trả về 0 
}



int main() {
    int n;;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));


    return 0;
}
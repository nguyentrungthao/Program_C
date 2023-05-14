/*
                            LIỆT KÊ NHỊ PHÂN

- khởi tạo cấu hình đầu tiên full 0 (a[n] = {0})
    XUẤT CẤU HÌNH HIỆN TẠI
- cho i : (n - 1 ; 0) tìm vị trí số 0 đầu tiên
    + nếu i < 0 tức là cấu hình cuối 11...1
- a[i] = 1
    + gán toàn bộ các phần tử từ a[i + 1] -> a[n - 1] = 0

VD n = 3
000 001 010 011 100 101 110 111

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>

void initialization(int* a, int n) { // khởi tạo
    int i;
    for (i = 0; i < n; ++i) {
        a[i] = 0;
    }
}

int find_first_zero(int* a, int n) {
    int i = n - 1;
    while (a[i] != 0 && i >= 0) {
        --i;
    }
    return i;
}

void printf_bin_number(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d", a[i]);
    }
    printf("\n");
}

void generation_binnumber(int* a, int n) {
    int i;
    if (0 == n) {
        printf("khong hop le!\n");
    }
    else {
        initialization(a, n);
        while (true) {
            printf_bin_number(a, n);
            i = find_first_zero(a, n);
            if (i >= 0) {
                a[i] = 1;
                for (i += 1; i < n; ++i) {
                    a[i] = 0;
                }
            }
            else {
                printf("complete\n");
                break;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    generation_binnumber(a, n);

    getch();
    free(a);
    return 0;
}
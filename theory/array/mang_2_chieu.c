#include <stdio.h>

int main() {

    // int a[m][n] = {}; tự động gán tất cả phần tử là 0 trường hợp khai báo thiếu biến thiếu cx gán là 0
    int a[3][2] = { {1,2},{2,1},{3} };
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; i < 2; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
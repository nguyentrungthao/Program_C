#include <stdio.h>

// thay đổi tên sử dụng : typrdef old_name new_name;
typedef char word;

// sử dụng thay thế #define new_name old_name
// khá khó truyền biến vào;
#define loop(a, n) for(int i = a; i < n; i++)
void test_define() {
    loop(2, 5) {
        printf("oke \n");
    }
}

int main() {
    loop(2, 5) {
        printf("oke \n");
    }


    return 0;
}
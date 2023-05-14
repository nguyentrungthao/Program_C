#include <stdio.h>

#define uint32_t unsigned int

struct rcc {
    uint32_t bien1;
    uint32_t bien2;
    uint32_t bien3;
};

uint32_t a[14];

// tức là gán địa chỉ của a-(1 cái mảng được tạo ra mô phỏng 1 cụm thanh ghi sẵn của con STM32) 
// thực tế mình ko có biến nào và nếu khai báo 1 biến bình thường thì nó nó thể có được địa chỉ đó nên con trỏ sẽ theo biến đó 
struct rcc* hello = (struct rcc*)a;

struct rcc b;

int main() {
    int z = 0b00000001;
    a[0] = (uint32_t)2;
    printf("%x", hello);
    printf("\n%x", a);

    printf("\n\n%x %x", hello->bien1, *(a));

    return 0;
}
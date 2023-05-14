#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // thư viện giúp macro các kiểu dữ kiệu uint8

#define hello

#if !defined hello
// xuất hiện thông báo khi build chương trình //! chặn build
#error chua hello 
#endif // if !define hello
// tương tự như error nhưng build được chỉ xuất hiện cảnh báo 
#warning day la warning

//* param pragma pack(x) sẽ lựa chọn việc sắp xếp các ô nhớ cho struct 
/*
    với 1 struct như bên dưới
    nếu x = 4 thì khi sắp xếp các ô nhớ theo
    |   1   |   2   |   3   |   4   |

    | AA(1) | pad.................. |
    | BB(1) | BB(2) | BB(3) | BB(4) |
    | CC(1) | pad.................. |

    nếu x = 1 xếp các ô nhớ chỉ nằm cho trên 1 cột tối ưu được số ô nhớ bị bỏ trống (pad .....)
*/
#pragma pack(1)
struct GPIO { // tổng 4 + 4 + 1 + 1 = 10 bit 
    uint32_t a;
    uint8_t b;
    uint8_t d;
    uint32_t c;
};
typedef struct GPIO GPIO;

#pragma pack(2)
struct RCC {
    uint32_t a;
    uint8_t b;
    uint32_t c;
    uint8_t d;
};
typedef struct RCC RCC;

typedef struct {
    int sv1;
} abc;

int main() {
    printf("co warning van build duoc");
    printf("%d\n ", sizeof(RCC));
    printf("%d\n ", sizeof(GPIO));
    abc a;
    a.sv1;


    return EXIT_SUCCESS;
}
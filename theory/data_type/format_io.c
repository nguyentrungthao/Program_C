#include <stdio.h>
// xuất ra phạm vi lưu trữ của các kiểu dữ liệu nguyên
#include <limits.h>
// xuất ra phạm vi lưu trữ của các kiểu dữ liệu thực
#include <float.h>
// thư viện kiểu số nguyên 
#include <stdint.h>
// kiểu 1 bit
/*
    kiểu bool là 1 kiểu 8 bit nhưng chỉ có thể chứa 1 hoặc 0
    không thể dùng flag = ~flag vì kết qả ra xàm vcl
*/
#include <stdbool.h>

//https://laptrinhcanban.com/c/lap-trinh-c-co-ban/nhap-xuat-trong-c/dinh-dang-nhap-xuat-trong-c/
//https://www.programiz.com/c-programming

//ĐỊNH DẠNG NHẬP/XUẤT
/*

    %c      char
    %s      char*

    %d      int, short
    %u      u int, u short
    ! 4 kiểu trên
    %x                      HỆ 16
    %o                      HỆ 8

    %ld     long
    %lu     u long
    %llu    unsigned long long 8byte
    ! 2 kiểu trên
    %lx
    %lo

    !float
    %e                      XUẤT RA DƯỚI DẠNG MŨ
    %g                      XUẤT RA SỐ THỰC DẠNG PHÙ HỢP NHẤT
    %f

    !double
    %lf
    %a                      MỘT SỐ THỰC CHÍNH XÁC KÉP HỆ 16

    %p                      IN ĐỊA CHỈ
*/

/*
    chú ý khi ta đưa phép tính vào trong printf();
    trình biên dịch sẽ đưa phép tính vào kiểu dữ liệu lớn nhất và thực hiện
*/

int main() {
    uint8_t a = 0x01;
    printf("%x\n", a);
    // a = ~a;
    printf("%x\n", ~a);
    printf("bool:\n");
    bool x = 1;
    printf("%x\n", x);
    x = ~x;
    printf("%x\n", x);

    // unsigned long long a = 1;
    //! unsigned long long a = 18446744073709551614;
    // printf("%llu\n", UINT64_MAX);
    // printf("%d", sizeof(unsigned long long));

    return 0;
}
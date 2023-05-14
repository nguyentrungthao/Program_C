#include <stdio.h>
#include <stdlib.h>

/*
    int const *ptr TƯƠNG ĐƯƠNG const int *ptr : // DÙNG ĐỂ TRỎ ĐẾN NHỮNG BIẾN hằng số 
    int *const ptr                              // CHỈ TRỎ ĐẾN 1 BIẾN bth DUY NHẤT
*/

char* p = "data"; //non-const pointer, non-const data
const char* p = "data"; //non-const pointer, const data
char* const p = "data"; //const pointer, non-const data
const char* const p = "data"; //const pointer, const data

int main() {
    {
        const int a = 10; // đây là hằng số vì vậy cần 1 con trỏ mà ko thể thay đổi giá trị;
        int aa = 555;
        int const* p1; // DÙNG ĐỂ TRỎ ĐẾN NHỮNG BIẾN HẰNG SỐ 
        p1 = &a;
        int* p2 = &a; // sẽ bị lỗi vì nếu *p2 = 100 tức a(const) = 100 => sai "invalid conversion"
        printf("gia tri a = %d dia chi a = %d ", *p1, p1);
        p1 = &aa;
        *p1++; // giá trị nó mãi là 10 :3
        printf("\ngia tri aa = %d dia chi aa = %d\ngai tri con tro luu %d dia chi con tro luu %d ", aa, &aa, *p1, p1);
        /*
            giá trị của con trỏ lưu mãi ko thay đổi
            còn nó muốn trỏ đâu cx đc 
        */

    }
    {
        int b = 100, c = 200;
        int* const p3 = &b;// gán địa chỉ ngay khi khai báo và nó ko thể thay đổi
    // p3 = &b;
    // p3 = &c;
    }



    return 0;
}
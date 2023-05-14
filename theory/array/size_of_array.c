#include <stdio.h>
#include <stdlib.h>

// ở mảng tĩnh bộ nhớ tối đa cho phép là 1MB 
// nếu muốn nhiều phần tử hơn hãy dùng mảng động

// chỉ sử dụng mảng tĩnh bên trong main 
// trả về kích thước của mảng 
int count_amount_arr(int *a)
{
    return sizeof(a) / sizeof(a[0]);
}

int main(){

    return 0;
}
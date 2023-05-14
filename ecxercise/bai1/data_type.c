/*
*/

#include <stdio.h>

int overflow(){
    int a = pow(10, 6), b = pow(10, 6);
    int mul = a * b;
    /*khi thực hiện phép máy tính tự lấy kiểu lớn nhất trong 2 biến a và b 
    làm kiểu lưu dữ liệu, kết quả a*b = 10^12 ko chứa nổi trong int nên chỉ còn lại 10^6 dù mul có kiểu 
    long long hay double
    */
}

int main() {


    return 0;
}
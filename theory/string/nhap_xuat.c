#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    //khai báo
    char c;
    char tring0[30] = {}; // tất cả phần tử đều được gán = '\0'
    char string[30]; // chứa tối đa 29 kí tự, chừa chỗ cho '\0';// nên khởi tạo ="" tức là thêm ký tự '\0'
    char string1[30] = "hello";// tự động thêm ký tự '\0'
    char strg[] = "hello world";// tự động thêm ký tự '\0' ở cuối

    //xuất
    putchar(c);

    printf("%s", string1);
    puts(string1);// chỉ xuất được 1 chuỗi// tự động xuống dòng

    //nhập
    c = getchar();

    scanf("%s", string);// không nhận ' ' và '\n'
    /*
    vì:
        khi nhập cpu lưu ký tự vào bộ nhớ đệm stdin (vì có thể đang thực hiện tiến trình của phần mềm khác)
        khi nhập : nguyen trung thao . scanf nhận đến khi gặp ' ' và '\n' thì dừng        
    */
    /*
    CHÚ Ý:
        nếu việc nhập có sử dụng phím '\n' để kết thúc nhập 
        thì sau đó không thể sử dụng gets hoặc fgets vì tụi nó ko nhận phím enter hoặc nhận enter để kết thúc nhập
    */
    // XÓA BỘ ĐỆM TRƯỚC KHI DÙNG gets và fgets
    fflush(stdin);
    gets(string); // không nhận '\n' NHƯNG có thể nhận vượt quá chuỗi khai báo dẫn đến ghi đè lên vùng cấm
    fgets(string, 29, stdin); // nhận phím '\n' lưu và chuỗi và kết thúc việc nhập

    char str[80];
    // ghi dữ liệu vào mảng mà không xuất ra màn hình 
    sprintf(str, "Gia tri cua Pi = %f", M_PI);
    //    printf(str);

    return 0;
}
#include <stdio.h>
#include <string.h>

#pragma pack(1) // điều chỉnh cách tổ chức bộ nhớ xem phần preprocess
struct sinhvien {
    char ten[30];
    int ma;
    float diem;
};
typedef struct sinhvien sinhvien;
/*
    một cách viết khác của cấu trúc phía trên đẩy nhanh code ko cần dòng typedef nữa 
    typedef struct{
        char ten[30];
        int ma;
        float diem;
    } sinhvien;
*/

// cũng là 1 kiểu dữ liệu tự định nghĩa 

/*
    giúp việc macro các biến đầu vào nhanh hơn rõ ràng hơn cho người sử dụng
    VD mình quy định trả về -1 để thông báo lỗi, người dùng ko biết được hoặc lâu quá mình éo nhớ
    thì các này giúp tường minh code hơn 
*/
// các tham số cách nhanh bởi dấu ,
typedef enum {
    PARAMETER_ERROR, // khi không có giá trị khởi tự khởi tạo biến đầu tiên *=0
    PARAMETER_WARNIG , //* =1
    SUCCESS //* =2 
} message;

// dùng cho mục đích thông báo trạng thái của 1 hàm hay j đấy 
// trước mắt thì thay vì để 1 hàm chạy mà ko có thông báo thành công (void)
// ta có thể đưa nó thành kiểu enum để thông báo 
/*
    message xuat_chuoi(char *str, int long){
        //* thông qua đó chắc các giá trị đưa vào
        if(long <= 0)
            return PARAMETER_ERROR;

        * code *

        return SUCCESS;
    }
*/

// khi ở một bộ enum khác các giá trị sẽ khởi tạo y chang 
// bắt đầu từ 0
//! cẩn thận
typedef enum {
    aaaaa,
    bbbbb
} wtf;

sinhvien nhap() {
    sinhvien x;
    printf("nhap ten : ");
    fgets(x.ten, 29, stdin);
    printf("nhap ma : ");
    scanf("%d", &x.ma);
    printf("nhap diem : ");
    scanf("%f", &x.diem);

    return x;
}

void xuat(sinhvien x) {
    printf("\n\n\t\tTHONG TIN SINH VIEN\n");
    printf("ten : %s", x.ten);
    printf("ma : %d\n", x.ma);
    printf("diem : %f\n", x.diem);
}

int main() {
    sinhvien x = nhap();
    xuat(x);
    sinhvien y;

    //có thể gán 2 biến struct cho nhau trừ trường hợp con trỏ 
    x = y;
    // nếu bên trong struct có con trỏ có nguy cơ x thay đổi làm y cũng thay đổi theo gây ra BUG

    return 0;
}
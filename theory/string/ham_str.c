#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int build_strlen(char* s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
    return i;
}

void build_strcpy(char* s2, const char* s1)
{
    int i = 0;
    while (s1[i])
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0'; // chú ý nếu ko có '\0' bị lỗi in 2 lần kèm ký tự sai
}

char* build_strdup(const char* s)
{
    char* s1 = (char*)malloc(strlen(s) + 1);
    int i = 0;
    while (s[i])
    {
        s1[i] = s[i];
        i++;
    }
    return s1;
    free(s1);
}

void build_strlwn(char* s)
{
    int i = 0;
    while (s[i])
    {
        s[i] = tolower(s[i]);
        i++;
    }
}

void build_strrev(char* s)
{
    int i, len = strlen(s) - 1;
    for (i = 0; i <= len / 2; i++)
    {
        if (i != len - i)
        {
            char temp = s[i];
            s[i] = s[len - i];
            s[len - i] = temp;
        }
        i++;
    }
}

int build_strcmp(const char* s1, const char* s2)
{
    int len = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);
    for (int i = 0; i < len; i++)
    {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
    }
    if (strlen(s1) < strlen(s2))
        return -1;
    if (strlen(s1) > strlen(s2))
        return 1;

    return 0;
}

int build_strToNum(const char* s) {
    int mu = 0;
    int num = 0;
    for (int i = strlen(s) - 2; i >= 0; i--) {
        num += (s[i] - 48) * (int)pow(10, mu);
        mu++;
    }
    return num;
}

int main()
{
    char s[30];
    fgets(s, 29, stdin);
    int len = strlen(s); // trả về độ dài của chuỗi không tính ký tự '\0'
    char s1[30];
    strcpy(s1, s); // hàm sao chép từ s sang s1; // tự động thêm ký tự '\0' cuối chuỗi str
    char* s2 = strdup(s);
    /*
        cấp phát 1 mảng động s2 lưu chính sát các phần tử trong s vd có 5 ký tự
        cấp phát 1 chuỗi 5 ký tự r copy qua
    */
    strlwr(s); // chuyển nguyên chuỗi thành chữ thường;

    strrev(s); // hàm đảo chuỗi

    strcmp(s1, s2); //so sanh 2 chuỗi CÓ phân biệt hoa thường
    /*
    chỉ cần có sự khác biệt giữa 2 ký tự lập tức kết luận
    CHÚ Ý : ưu tiên ĐỘ DÀI MÀ SO SÁNH GIỮA 2 KÝ TỰ TRÊN MÃ ASCII rồi SO SÁNH ĐỘ DÀI
    return :
        NHẮC LẠI LÀ ưu tiên 2 KÝ TỰ trước khi SO SÁNH ĐỘ DÀI
            s1 < s2  => <0
            s1 > s2  => >0
            s1 = s2  => =0

            vd s1 :"a" ; s2 = "LAP TRINH" 'a' = 97 > 'L' => s1 > s2 return >0
        SO SÁNH ĐỘ DÀI thằng nào dài hơn thằng đó lớn hơn
    */
    stricmp(s1, s2); // so sánh 2 chuỗi ko phân biệt thường

    char* a;
    long num = strtol(s1, &a, 10);/*luôn trả về hệ cơ số 10 nhận các hệ số khác nhau
    vd 101 phải nhập vào trong hàm là 2 sẽ trả về 5(hệ 10)
    */

    memset(s1, '-', 7);// thay thế 7 kí tự đầu bằng '-' ....

    strncpy(s2, s1, 2);// copy chuỗi 1 vào chuỗi 2 chỉ 2 phần tử 

    strstr(s1, s2);//tìm chuỗi 2 trong chuỗi 1 

    free(s2); // giải phóng mảng động trong bộ nhớ heap
    getch();
    return 0;
}
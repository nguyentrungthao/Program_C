#include <stdio.h>
#include <string.h>

void hocLuc(float diem){
    char s[20];
    if(diem >= 9){
        strcpy(s, "xuat sac");
    }
    else if(diem < 9 && diem >= 8){
        strcpy(s, "gioi");
    }
    else if(diem < 8 && diem >= 6.5){
        strcpy(s, "kha");
    }
    else if(diem < 6.5 && diem >= 4){
        strcpy(s, "trung binh");
    }
    else {
        strcpy(s, "yeu");
    }

    puts(s);

}

int main(){
    char s[10];

    hocLuc(2);

    return 0;
}
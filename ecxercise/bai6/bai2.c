#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct sophuc{
    int thuc;
    int ao;
};

typedef struct sophuc sophuc;

sophuc nhap(){
    sophuc a;
    printf("nhap phan thuc: ");
    scanf("%d",&a.thuc);
    printf("nhap phan ao: ");
    scanf("%d",&a.ao);

    return a;
}

sophuc cong(sophuc a, sophuc b){
    sophuc tong;
    tong.thuc = a.thuc + b.thuc;
    tong.ao = a.ao + b.ao;
    return tong;
}

sophuc tru(sophuc a, sophuc b){
    sophuc hieu;
    hieu.thuc = a.thuc - b.thuc;
    hieu.ao = a.ao - b.ao;
    return hieu;
}

sophuc nhan(sophuc a, sophuc b){
    sophuc tich;
    tich.thuc = a.thuc * b.thuc - a.ao * b.ao;
    tich.ao = a.thuc * b.ao + a.ao * b.thuc;
    return tich; 
}

sophuc chia(sophuc a, sophuc b){
    sophuc thuong;
    thuong.thuc = (a.thuc * b.thuc + a.ao * b.ao) / (b.thuc * b.thuc + b.ao *b.ao);
    thuong.ao = (a.thuc * b.thuc - a.ao * b.ao) / (b.thuc * b.thuc + b.ao *b.ao);
    return thuong;
}

void xuat(sophuc a){
    // char b;
    // if(a.ao > 0){
    //     b = '+';
    // }
    // else{
    //     b = ' ';
    // }
    printf("ket qua = %d %c %di\n\n", a.thuc, (a.ao > 0) ? '+' : '\b', a.ao);//(a.ao > 0) ? '+' : " "
}

int main(){
    sophuc a, b;
    char luachon;
    do{
        printf("==================== MENU ====================");
        printf("\n\t1. tinh tong 2 so phuc\n\t2. tinh hieu 2 so phuc\n\t3. tinh tich 2 so phuc\n\t4. tinh thuong 2 so phuc");
        printf("\n\tESC. thoat");
        printf("\n\tlua chon : ");
        luachon = getch();

        switch(luachon){
            case '1' :
                printf("1\n");
                printf("so phuc 1 :\n");
                a = nhap();
                printf("so phuc 2 :\n");
                b = nhap();
                xuat(cong(a, b));
                break;
            
            case '2':
                printf("2\n");
                printf("so phuc 1 :\n");
                a = nhap();
                printf("so phuc 2 :\n");
                b = nhap();
                xuat(tru(a, b));
                break;
            
            case '3':
                printf("3\n");
                printf("so phuc 1 :\n");
                a = nhap();
                printf("so phuc 2 :\n");
                b = nhap();
                xuat(nhan(a, b));
                break;
                
            case '4':
                printf("4\n");
                printf("so phuc 1 :\n");
                a = nhap();
                printf("so phuc 2 :\n");
                b = nhap();
                xuat(chia(a, b));
                break;
            
            default :
                printf("nhap sai vui long nhap lai!!");
                break;
        }


    }while(luachon != 27);

    return  0;
}
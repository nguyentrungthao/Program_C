#include<stdio.h>
#include<conio.h>

void nhapBang(int *r, int *c){
    do{
        printf("nhap so hang, so cot > 0 : ");
    scanf("%d%d",r,c);
    }while(*r < 1 || *c < 1);
}

void nhapMang(int *a, int r, int c){
    int i, j;
    for(i  = 0; i < r; i++){
        for(j = 0; i < c; i++){
            printf("a[%d][%d]: ", i, j);
            scanf("%d",a[i][j]);
        }
    }
}


void xuat(int *a, int dem){

}

int main(){

    getch();
    return 0;
}
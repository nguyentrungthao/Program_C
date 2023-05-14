#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

int nhapN(){
    int n;
    do{
        printf("nhap so phan tu cua mang n > 0: ");
        scanf("%d",&n);
    }while(n < 1);

    return n;
}
int trung(int *a, int n, int x){ // đếm sô lần xuất hiện của a[i]
    for(int i = 0; i < n; i++){
        if(a[i] == x)
            return 0;
    }
    return 1;
}

void taoSo(int *a, int n){
    srand(time(NULL));
    int i = 0;
    while(i < n){
        int x = rand();
        if(trung(a, n , x)){
            a[i++] = x;
        }       
    }
}
void xuat(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] :  %d\n",i, a[i]);
    }
    
}
int main(){
    int n = nhapN();
    int a[n];
    taoSo(a, n);

    xuat(a, n);
    
    getch();
    return 0;
}
#include<stdio.h>
#include<conio.h>
int nhapN(){
    int n;
    do{
        printf("nhap so phan tu cua mang n > 0: ");
        scanf("%d",&n);
    }
    while(n < 1);

    return n;
}

void nhapMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d]",i);
        scanf("%d",&a[i]);
    }
}
void nhapAB(int *a, int *b){
    do{
        printf("nhap a < b: ");
        scanf("%d%d",a,b);
    }
    while(*a > *b);
}

int tongGiuaAB(int *arr, int a, int b, int n){
    int tong = 0;
    int i;
    for(i = 0; i < n; i++){
        if( a < arr[i] && arr[i] < b){
            tong += arr[i];
        }
    }

    return tong;
}

int main(){

    int n = nhapN();
    int arr[n];
    int a,b;
    nhapMang(arr, n);
    nhapAB(&a, &b);
    printf("tong cac so nam giua %d va %d = %d", a, b,tongGiuaAB(arr, a, b, n));

    getch();
    return 0;
}
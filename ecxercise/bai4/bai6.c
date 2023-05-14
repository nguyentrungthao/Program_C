#include<stdio.h>
#include<conio.h>

int nhapN(){
    int n;
    do{
        printf("nhap so phan tu cua mang n > 0: ");
        scanf("%d",&n);
    }while(n < 1);

    return n;
}
void nhapMang(int *a, int n){
    for(int i = 0;i < n; i++){
        printf("a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}

float tongChan(int *a, int n){
    int tong = 0;
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            tong += a[i];
            dem ++;
        }
    }
    return (float)tong / dem;
}

float tongLe(int *a, int n){
    int tong = 0;
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 != 0){
            tong += a[i];
            dem++;
        }
    }
    return (float)tong / dem;
}

int main(){
    int n = nhapN();
    int a[n];

    nhapMang(a, n);

    printf("trung binh tong cac so le = %o.2f", tongLe(a, n));
    printf("\ntrung binh tong cac so chan = %0.2f",tongChan(a, n));
    
    getch();
    return 0;
}
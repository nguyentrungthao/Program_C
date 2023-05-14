#include<stdio.h>
#include<conio.h>
#include<math.h>

int nhapN(){
    int n;
    do{
        printf("nhap so phan tu cua mang n > 0: ");
        scanf("%d", &n);
    }while(n < 1);

    return n;
}

int nhapX(){
    int n;
        printf("nhap phan tu can xet: ");
        scanf("%d", &n);
    return n;
}

void nhapMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d]",i);
        scanf("%d",&a[i]);
    }
}

int ganNhat(int *a, int n, int x){
    int d = abs(a[0] - x);
    for(int i = 1; i < n; i++){      
        if(abs(a[i] - x) < d && a[i] != x){
            d = abs(a[i] - x);           
        }
    }
    return d;
}

int daIn(int *b, int n, int check){
    for(int i = 0; i < n; i++){
        if(b[i] == check){
            return 0;
        }
    }
    return 1;
}

void xuat(int *a, int n, int d, int x){
    int dem = 0;
    int b[n];
    for(int i = 0; i < n; i++){
        if(abs(a[i] - x) == d && daIn(b, dem, a[i])){
            printf("%5d",a[i]);
            b[dem++] = a[i];
        }     
    }
}

int main(){
    int n = nhapN();
    int a[n];

    nhapMang(a, n);
    int x = nhapX();

    int d = ganNhat(a, n, x);
    xuat(a, n, d, x);

    getch();
    return 0;
}


#include <stdio.h>
#include <conio.h>

int nhapN(){
    int n ;
    do{
        printf("nhap so phan tu cua mang n > 0: ");
        scanf("%d",&n);
    }while(n < 1);

    return n;
}

void nhapMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] : ",i);
        scanf("%d",&a[i]);
    }
}
int nhapK(int n){
    int k;
    do{
        printf("nhap vi tri can xoa 0 <= k < n : ");
        scanf("%d",&k);
    }while( k < 0 || k >= n);
    
    return k;
}

void xoa(int *a, int n, int k){
    for(int i = k; i < n - 1; i++){
        a[i] = a[i + 1];
    }
}

void xuat(int *a, int n){
    for(int i = 0; i < n - 1; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
}

int main(){
    int n = nhapN();

    int a[n];
    nhapMang(a, n);

    int k = nhapK(n);

    xoa(a, n, k);
    xuat(a, n);

    getch();
    return 0;
}
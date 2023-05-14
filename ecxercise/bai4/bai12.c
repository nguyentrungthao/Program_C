#include<stdio.h>
#include<conio.h>

int nhapN(){
    int n;
    do{
        printf("nhap so phan tu cua mang n >0 : ");
        scanf("%d",&n);
    }while(n < 1);

    return n;
}

void nhapMang(int *a, int n){
    for(int i = 0; i < n - 1; i++){
        printf("a[%d] : ",i);
        scanf("%d",&a[i]);
    }
}

int nhapX(){
    int x;
    printf("nhap so can chen x : ");
    scanf("%d",&x);

    return x;
}

int nhapK(int n){
    int k ;
    do {
        printf("nhap vi tri chen 0 <= k < n : ");
        scanf("%d",&k);
    }while(k < 0 || k >= n);

    return k;
}
void chen(int *a, int n, int x, int k){
    int dem = 0;
    for(int i = n - 1; i > k; i--){
        a[i] = a[i - 1];
    }
    a[k] = x;
}

void xuat(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] : %d\n", i, a[i]);
    }
}
int main(){
    int n = nhapN();

    int a[n];
    nhapMang(a, n);

    int x = nhapX();
    int k = nhapK(n);

    chen(a, n, x, k);
    xuat(a, n);

    getch();
    return 0;
}
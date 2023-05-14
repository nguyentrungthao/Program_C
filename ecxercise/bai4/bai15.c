#include<stdio.h>
#include<conio.h>

int nhapN(int mang){
    int n;
    do{
        printf("nhap so phan tu cua mang %d  > 0: ", mang);
        scanf("%d",&n);
    }while(n < 1);
    
    return n;
}

void nhapMang(int *a, int n, int mang){
    for(int i = 0; i < n; i++){
        printf("a%d[%d]: ", mang ,i);
        scanf("%d",&a[i]);
    }
}

int nhapK(int n){
    int k;
    do{
        printf("nhap vi tri chen mang 0 <= k < %d : ",n);
        scanf("%d",&k);
    }while(k < 0 || k >= n);

    return k;
}

int soPhanTu_a1(int n,int k, int m){
    if(n - k <  m -1){
        n = k + m ;
    }
    return n;
}

void chenMang(int *a1, int *a2, int m, int k){
    for(int i = 0; i < m ; i++){
        a1[k++] = a2[i];
    }
}

void xuat(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a1[%d] = %d\n", i, a[i]);
    }
}

int main(){
    int n = nhapN(1);
    int m = nhapN(2);
    int a1[n + m], a2[m];

    printf("\n\nnhap phan tu cua mang a1: \n");
    nhapMang(a1, n, 1);
    printf("\n\nnhap phan tu cua mang a2: \n");
    nhapMang(a2, m, 2);
    int k = nhapK(n);

    n = soPhanTu_a1(n, k, m);
    chenMang(a1, a2, m, k);
    printf("\n\nmang sau khi chen: \n");
    xuat(a1, n);

    getch();
    return 0;
}
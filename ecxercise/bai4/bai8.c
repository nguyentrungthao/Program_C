#include<stdio.h>
#include<conio.h>

int nhapN(){
    int n;
    do{
        printf("nhap so phan tu cua mang n > 0 : ");
        scanf("%d",&n);
    }while(n < 1);

    return n;
}

void nhapMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}

int thuanNghich(int *a, int n){
    int dem = 0, dk = 0 ;
    int i,j;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(a[i] == a[j]){
                dem ++;
            }
        }
        if(dem % 2 != 0){
            dk ++;
        }
        if(dk == 2){
            return 0;
        }
        dem = 0; 
    }
    return 1;
}

int main(){
    int n = nhapN();
    int a[n];

    nhapMang(a, n);
    if(thuanNghich(a, n)){
        printf("mang da nhap la mang thuan nghich ! ");
    }
    else{
        printf(" mang da nhap KHONG thuan nghich !");
    }
    getch();
    return 0;
}
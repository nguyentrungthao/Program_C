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
    for(int i = 0; i < n; i++){
        printf("a[%d] : ", i);
        scanf("%d",&a[i]);
    }
}

int trung(int *b, int n, int x){
    for(int i = 0; i < n; i++){
        if(b[i] == x){
            return 0;
        }
    }
    return 1;
}

void xuat(int *a, int n){
    int b[100] ;
    for(int i = 0; i < 100; i++){
        b[i] = -1;
    }
    int dem = 0, am1 = 1;

    for(int i = 0; i < n; i++){
        if(trung(b, n, a[i])){
            printf("%5d", a[i]);
            b[dem++] = a[i];
        }
        if((a[i] == - 1) && am1){
            printf("%5d",a[i]);
            am1 = 0;
        }
    }
}

int main(){
    int n = nhapN();
    int a[n];
    
    nhapMang(a, n);
    xuat(a, n);

    getch();
    return 0;
}
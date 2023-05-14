#include<stdio.h>
#include<conio.h>
#include<math.h>

int nhapN(){
    int n;
    do{
        printf("nhap so phan tu cua mang: ");
        scanf("%d",&n);
    }while(n < 1);

    return n;
}

void nhapMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d]", i);
        scanf("%d",&a[i]);
    }
}
float nhapX(){
    float x;
    printf("nhap x = ");
    scanf("%f",&x);

    return x;
}

float tinhTong(int *a, int n, int x){
    float s = a[0];
    for(int i = 1; i <= n; i++){
        s += a[i] * pow(x, i);
    }
    return s;
}

int main(){
    int n = nhapN();
    int a[n];
    nhapMang(a, n);
    float x = nhapX();

    printf("tong cua da thuc = %f",tinhTong(a, n, x));

    getch();
    return 0;
}
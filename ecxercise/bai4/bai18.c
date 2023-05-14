#include<stdio.h>
#include<conio.h>
#include<math.h>

int nhapN(){
    int n; 
    do{
        printf("nhap so phan tu cua chuoi > 0 : ");
        scanf("%d",&n);
    }
    while(n < 1);

    return n;
}

int nhapX(){
    int x;
    printf("nhap X: ");
    scanf("%d",&x);
    return x;
}
void nhapMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}

float tinhTong(int *a, int n, int x){
    float s = a[1];
     for(int i = 2; i < n; i++){
         s += i * a[i] * pow(x, i - 1);
     }
     return s;
}
int main(){
    int n = nhapN();
    int a[n];
    
    nhapMang(a, n);
    int x = nhapX();

 
    printf("tong dao ham bac 1 cua ham so la: %f",tinhTong(a, n, x));

    getch();
    return 0;
}
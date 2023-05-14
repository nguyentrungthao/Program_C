#include<stdio.h>
#include<conio.h>

void nhapMang(int *a, int *n){
    do{
        printf("nhap so phan tu cua mang n > 0: ");
        scanf("%d", n);
    }while((*n) < 1);

    for(int i = 0; i < (*n); i++){
        printf("a[%d]", i);
        scanf("%d", &a[i]);
    }
}

void minMax(int *a, int n, int *min, int *max){
    for(int i = 1; i < n; i++){
        if((*min) > a[i]){
            (*min) = a[i];
        }
        if((*max) < a[i]){
            (*max) = a[i];
        }
    }
}

void xuat(int min, int max){
    if(min == max){
        printf("khong co min max ");
    }
    else
        printf("MIN = %d\nMAX = %d", min, max);
}

int main(){

    int n = 10;
    int a[n];

    nhapMang(a, &n);
    int max = a[0], min = a[0];

    minMax(a, n, &min, &max);
    xuat(min, max);

    return 0;
    getch();
}
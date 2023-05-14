#include<stdio.h>
#include<conio.h>

int nhapN(){
    int n;
    do{
        printf("nhap so phan tu cua mang  > 0: ");
        scanf("%d",&n);
    }while(n < 1);

    return n;
}

void nhapMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] : ",i);
        scafn("%d",&a[i]);
    }
}


int main(){

    getch();
    return 0;
}
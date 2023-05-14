#include<stdio.h>
#include<conio.h>

int nhapSo(){
    int n;
    do
    {
        printf("nhap so nguyen n>0: ");
        scanf("%d",&n);
    } while (n<0);
    
    return n;
}

void rasing(int n){
    int a1 = 10;
    int a2 = n%10;
    while(a1>a2){
        n /= 10;
        a1 = a2;
        a2 = n%10;
    }
    if(n == 0)
        printf("la so tang\n");
    else 
        printf("khong la so tang\n");

}

int first(int n){
    int a;
    while(n >0){
        a = n%10;
        n /= 10;
    }
    return a;
}

int countFirst(int n, int a){
    int count =0;
    int dk = n%10;
    while(n>0){
        n /= 10;
        if(dk == a){
            count++;
        }
        dk = n%10;        
    }
    return count;
}

int main(){
    int n;

    n = nhapSo();
    rasing(n);

    printf("so dau tien = %d\n",first(n));
    printf("co %d so giong so dau tien\n",countFirst(n,first(n)));

    return 0;
    getch();
}
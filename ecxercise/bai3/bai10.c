#include<stdio.h>
#include<conio.h>

int nhapSo(){
    int n;
    do{
        printf("nhap so n: ");
        scanf("%d",&n);
    }
    while(n<0);
    return n;
}

int demSO(int n){
    int dem=0;
    while(n>0){
        dem++;
        n /= 10;
    }
    return dem;
}

int demSoLe(int n){
    int dem=0;
    while(n>0){
        int thu = n%10;
        if(thu%2 !=0){
            dem++;
        }
        n /= 10;
    }
    return dem;
}

float tongChuSo(int n){
    int s=0;
    while(n>0){
        s += n%10;
        n /= 10;
    }
    return s;
}


int main(){
    int n;
    n = nhapSo();

    printf("so %d co %d so\n",n,demSO(n));

    printf("so %d co %d so le\n",n,demSoLe(n));

    printf("trung binh cac chu so = %f\n",tongChuSo(n)/demSO(n));

    return 0;
    getch();
}
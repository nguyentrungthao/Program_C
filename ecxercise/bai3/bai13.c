#include<stdio.h>
#include<conio.h>
#include<math.h>
int nhapSo(){
    int n;
    do{
        printf(" nhap so n: ");
        scanf("%d",&n);
    }
    while(n<=0);

    return n;
}

int SNT(int n){
    int dk = 1;
    for(int i=2; i<= sqrt(n); i++){
        if( n%i==0 ){
            dk = 0;
            break;
        }
    }
    return dk;
}

void soSNT(int n){ // hien n so nguyen to
    int dem = 2;
    for(int i=2; i<=n;){
        if(SNT(dem)){
            printf("%d ",dem);
            i++;
        }
        dem++;
    }
}

void chuoiFibo(int n){
    int f0=0, f1=1, fn=0;
    for(int i=2; i<=n; i++){
        fn = f1 + f0;
        printf(" so fibo thu %d = %d\n",i,fn);
        f0 = f1;
        f1 = fn;
    }
}

void chinhPhuong(int n){
    int dem = 1;
    for(int i=1; i<=n; ){
        if(sqrt(dem)*sqrt(dem)==dem){
            printf("%d ",dem);
            i++;
        }
        dem++;
    }
}

int main(){
    int n;

    n = nhapSo();
    soSNT(n);
    printf("\n");
    chuoiFibo(n);
    printf("\n");
    chinhPhuong(n);

    return 0;
    getch();
}
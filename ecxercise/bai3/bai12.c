#include<stdio.h>
#include<conio.h>
#include<math.h>

int nhapSo(){
    int n;
    do{
        printf("nhap so n: ");
        scanf("%d",&n);
    }
    while(n<1);

    return n;
}

void listUoc(int n){
    for (int  i = 2; i < n; i++)
    {
        if(n%i==0){
            printf("%d ",i);
        }
    }  
}

int demUoc(int n){
    int dem=0;
    for (int i = 2; i < n; i++)
    {
        if(n%i==0) dem++;
    }
    return dem;
}

int SNT(int n){
    int dk =1;
    for(int i=2; i<=sqrt(n); i++ ){
        if(n%i==0){
            dk = 0;
            break;
        }           
    }
    return dk;
}

void uocSNT(int n){
    for(int i=2; i<n; i++){
        if(n%i==0 && SNT(i))
            printf("%d ",i);
    }
}

int main(){
    int n = nhapSo();
    listUoc(n);
    printf("\nso %d co %d uoc \n",n,demUoc(n));
    uocSNT(n);
    return 0;
    getch();
}
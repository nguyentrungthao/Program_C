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

int tongChuSo(int n){
    int s=0;
    while(n>0){
        s += n%10;
        n /= 10;
    }
    return s;
}
void phanTichSNT(int n){
    unsigned int i =2;
    unsigned int dem=0;
    while(n>1){
        if(n%i==0)
        {
            dem++;               
            if(n == i){
                if(dem>1)
                    printf("%d^%d",i,dem);
                else 
                    printf("%d",i);              
            }
        n /=i;
        }
        else
        {
            if(dem>1)
                printf("%d^%d",i,dem);
            else
                printf("%d",i);
            if(n>i) 
                printf(" x ");
            
            dem = 0;
            i++;
        }

    }
}


int main(){
    int n,i;

    n = nhapSo();
    printf("tong cac chu so la: %d\n",tongChuSo(n));
    printf("%d = ",n);
    phanTichSNT(n); 

    return 0;
    getch();
}
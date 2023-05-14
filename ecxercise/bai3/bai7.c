#include<stdio.h>

int thuanNghich(int n){
    int dao = 0 ;
    int m=n;
    while(m>0){
        dao = dao * 10 + m%10;
        m /= 10;
    }
    if(dao == n)
        return 1;
    else 
        return 0;
}

int main(){
    int k,i;
    do{
        printf("nhap k : ");
        scanf("%d",&k);
    }while(k<1);

    for(i=10000000 ; i<=99999999; i++){
        if(i%k == 0 ){
            if(thuanNghich(i))
            printf("%10d ",i);
        }   
    }
}
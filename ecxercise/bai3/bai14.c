#include<stdio.h>
#include<math.h>
#include<conio.h>

int SNT(long n){
    int dk = 1; //la so nguyen to
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            dk = 0;// khong la so nguyen to
            break;
        }
    }
    return dk;
}

int chusoSNT(long n){
    int dk = 1;
    while(n>0){
        int a = n%10;
        if(!SNT(a))
        {
            dk = 0;
            break;
        }
        n /= 10;
    }
    return dk; 
} 

int tongchusoSNT(long n){
    int s=0;
    while(n>0){
        s += n%10;
        n /= 10; 
    }
    return SNT(s);
}
int main(){
    for(long i=10000000; i<=99999999; i++){
        if( chusoSNT(i) && SNT(i) && tongchusoSNT(i)){
            printf("%ld   ",i);
        }       
    }
    return 0;
    getch();
}
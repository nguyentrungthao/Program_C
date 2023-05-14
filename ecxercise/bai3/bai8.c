#include<stdio.h>
#include<conio.h>

int soNguyenTo(int n){
    int dem = 0;
    for(int i=2; i<n; i++){
        if(n%i==0){
            dem++ ;
        }
    }
    if(dem>0){ // uoc nhieu hon 1  ko phai la so nguyen to
        return 0;
    }
    else {
        return 1;
    }
}

int main(){
    int a,b;
    do{
        printf("nhap a va b: ");
        scanf("%d%d",&a,&b);
    }
    while(a<0 || a>b );

    for(int i = a+1; i<b; i++){
        if(soNguyenTo(i)){
            printf("%d ",i);
        }
    }

    return 0;
    getch();
}
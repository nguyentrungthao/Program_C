#include<stdio.h>
#include<conio.h>

int main(){
    int h,i ;
    do{
        printf("nhap h: ");
        scanf("%d",&h);
    }
    while(h<1);

    for(i=1; i<=h; i++){
        for(int j=1; j<=i; j++ ){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
    getch();
}
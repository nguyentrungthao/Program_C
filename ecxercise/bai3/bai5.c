#include<stdio.h>
#include<conio.h>
#include<math.h>

int main(){
    int h, i;
    do{
        printf("nhap h: ");
        scanf("%d", &h);
    }
    while(h<0);

    for(i=1; i<=h; i++){
        for(int j=1; j<2*h; j++ ){
            if(abs(h - j) <= (i-1)){
                 printf("%d ",i - abs(h - j));
            }
            else {   
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
    getch();
}
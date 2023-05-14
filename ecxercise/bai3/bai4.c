/*#include<stdio.h>
#include<conio.h>

int main(){
    int h,i,l;
    do{
        printf("nhap chieu cao h: ");
        scanf("%d",&h);
    }
    while(h<1);

    l=h;
    for(i=0; i<h; i++){
        for(int j=1; j<l; j++){
            printf("  ");
        }
        l--;
        for(int j=1; j<=2*i+1; j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
    getch();
}
*/


#include<stdio.h>
#include<conio.h>
#include<math.h>

 int main(){
    int h,i;
    do{
        printf("nhap h: ");
        scanf("%d",&h);
    }
    while(h<1);

    for(i=1; i<=h; i++){
        for(int j=1; j<2*h; j++){
            if(abs(h - j) <= i-1 ){
                printf("* ");
            }
            else
                printf("  ");
        }
        printf("\n");
    }

    return 0;
    getch();
}

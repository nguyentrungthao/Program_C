#include<stdio.h>
#include<conio.h>

int main(){
    int m,n;
    do{
        printf("nhap so m va n : ");
        scanf("%d%d",&m,&n);
    }
    while(m<0 || n<0);

    for(int i=0; i<m; i++){
        for(int i=0; i<n; i++){
            printf("X ");
        }
        printf("\n");
    }

    return 0;
    getch();
}
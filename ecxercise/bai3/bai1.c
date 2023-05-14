#include<stdio.h>
#include<conio.h>

int main(){
    int m,n;
    do{
        printf("nhap so m va n : ");
        scanf("%d%d",&m,&n);
    }
    while(m<0 || n<0);

    for(int i=1; i<=m; i++){
        for(int i=1; i<=n; i++){
            printf("%d ",i);
        }
        printf("\n");
    }
    
    return 0;
    getch();
}
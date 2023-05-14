#include<stdio.h>
#include<conio.h>

int pascalDeQuy(int k, int n){
    if(k == 0 || k == n){
        return 1;
    }
    else{
        return pascalDeQuy(k - 1, n - 1) + pascalDeQuy(k, n - 1);
    }
}
/*
    k = 2 , n = 3
    pascalDeQuy(2 ,3) = pascalDeQuy(1 , 2)                  + pascalDeQuy(2 , 2)
                        pascalDeQuy(0,1) + pascalDeQuy(1,1 ) + pascalDeQuy(1 , 1) + pascalDeQuy(2 , 1)  
    
*/

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= i; i++){
            printf("%d ",pascalDeQuy(k, i));
        }
        printf("\n");
    }

    return 0;
    getch();
}
#include "lib.h"
#include <conio.h>

int main(){
    int n;
    scanf("%d", &n);

    if(prime(n)){
        printf("SNT\n");
    }
    else{
        printf("NO\n");
    }

    if(superprime(n)){
        printf("SUPERPRIME\n");
    }
    else{
        printf("NO\n");
    }

    getch();
    return 0;
}
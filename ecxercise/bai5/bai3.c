#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define n 100

int check(char *a){
    char x[n];
    strcpy(x, a);
    strrev(x);
    return strcmp(a, x) == 0;

}

int main(){
    char s[n];
    long a = 1233221;

    ltoa(a, s, 10);
    printf("%d", check(s));

    getch();
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[100];
    int i = 0;
    fgets(s, 100, stdin);

    while(s[i]){
        putchar(toupper(s[i]));
        ++i;
    }

    i = 0;
    while(s[i]){
        putchar(tolower(s[i]));
        ++i;
    }

    return 0;
}
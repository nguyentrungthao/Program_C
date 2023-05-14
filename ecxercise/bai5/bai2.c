#include <stdio.h>
#include <string.h>
#include <ctype.h>

int khoangTrang(char c){
    return c == ' ' || c == '\t' || c == '\n';
}

int demChu(char *s){
    int i = 0;
    int dem = 0;
    while(s[i]){
        if( isalpha(s[i]) && khoangTrang(s[i + 1])){
            ++dem;
        }
        ++i;
    
    }
    return dem;
}

int main(){
    char s[100];
    fgets(s, 100, stdin);

    printf("%d  ",demChu(s));


    return 0;
}
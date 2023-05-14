#include <stdio.h>
#include <string.h>
#include <ctype.h>

int nhanDang(char c){
    return c == ' ' || c == '-' || c == '_';
}

int nhanChu(char *s){
    int i = 0;
    while(s[i]){
        if(isalpha(s[i])){
            return i;
        }
        ++i;
    }
    return 0;
}

int firstblank(char *s){
    int i = 0;
    while(s[i]){
        if(nhanDang(s[i + 1]) && isalpha(s[i])){
            return ++i ;
        }
        ++i;
    }
    return 0;
}

int endblank(char *s){
    int i = strlen(s) - 1;
    while(s[i]){
        if(nhanDang(s[i - 1]) && isalpha(s[i])){
            return i ;
        }
        --i;
    }
    return 0;
}

void xuat(char *s, int a, int b){
    for(int i = a; i < b; i++){
        printf("%c",s[i]);
    }
    printf(" ");
}

int main(){
    char s[100];
    fgets(s, 99, stdin);
    int a = firstblank(s);
    int b = endblank(s);

    xuat(s, b , strlen(s) - 1);
    xuat(s, a + 1, b - 1);
    xuat(s, nhanChu(s), a);

    return 0;
}
#include <stdio.h>
#include <conio.h>
#include <string.h>

void xoa(int *s, int x);
void them(int *s, int n, char x);

int main(){
    int x;
    char s[30];
    fgets(s, 29, stdin);
    scanf("%d", &x);
    xoa(s, x);

    fflush(stdin);
    fgets(s, 29, stdin);
    scanf("%d", &x);
    char n;
    fflush(stdin);
    scanf("%c", &n);
    them(s, x, n);

    getch();
    return 0;
}

void xoa(int *s, int x){
    int i = x - 1;
    while(s[i]){
        s[i] = s[i + 1];
        i++;
    }
    s[i - 1] = '\0';
}

void them(int *s, int n, char x){
    for (int i = strlen(s) - 1; i >= n; i++){
        s[i + 1] = s[i];
    }
    s[n] = x;
    s[strlen(s) + 1] = '\0';
}
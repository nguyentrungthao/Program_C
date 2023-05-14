#include <stdio.h>
#include <string.h>
#include <ctype.h>

int nhanDang(char c){
    return c == ' ' || c == '\n' || c == '\t';
}
int demChu(char *s){
    int i = 0, dem = 0;
    while(s[i]){
        if(nhanDang(s[i + 1]) && isalnum(s[i])){
            ++dem;
        }
        ++i;
    }
    return dem;
}
void timViTri_DoDai(char *s, int *a, int *len){
    int i = 0, j = 0, k = 0;
    while(s[i]){
        if(isalnum(s[i])){
            a[j++] = i ;
            len[k] = 0;
            while(isalnum(s[i])){
                ++len[k];
                ++i;
            }
            ++k;
        }
        ++i;
    }
}

void xuat(char *s, int *a, int *len, int soChu){
    int i, j;
    for(i = soChu - 1; i >= 0; i--){
        for(j = a[i]; j < a[i] + len[i] ; j++){
            printf("%c",s[j]);
        }
        printf(" ");
    }   
}
int main(){
    char s[1000];
    fgets(s, 999, stdin);
    int a[100], len[100];

    int soChu = demChu(s);
    timViTri_DoDai(s, a, len);
    xuat(s, a, len, soChu);

    return 0;
}
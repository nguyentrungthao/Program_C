#include <stdio.h>
#include <ctype.h>
#include <string.h>

int daIn(char *b, int n, char c){
    for(int i = 0; i <= n; i++){
        if(c == b[i]){
            return 1;
        }
    }
    return 0;
}

int checkNguyenAm(char c){
    return c == 'u' || c == 'e' || c == 'o' || c == 'a' || c =='i';
}
void denNguyenAm(char *s){
    int i = 0;
    int dem = 1, coun = 0;
    char b[50];
    while(s[i]){
       if(checkNguyenAm(s[i]) && !daIn(b, coun, s[i]) && isalpha(s[i])){
            int j = i + 1;
            while(s[j]){
                if(s[i] == s[j]){
                    ++dem;
                }
                ++j;
            }
            printf("ky tu '%c' xuat hien %d lan \n", s[i], dem);
            dem = 1;
            b[coun++] = s[i];
        }
        ++i;
    }
}

void demPhuAm(char *s){
    int i = 0;
    int dem = 1, coun = 0;
    char b[50];
    while(s[i]){
       if(!checkNguyenAm(s[i]) && !daIn(b, coun, s[i]) && isalnum(s[i]) ){
            int j = i + 1;
            while(s[j]){
                if(s[i] == s[j]){
                    ++dem;
                }
                ++j;
            }
            printf("ky tu '%c' xuat hien %d lan \n", s[i], dem);
            dem = 1;
            b[coun++] = s[i];
        }
        ++i;
    }
}

void demKyTuDacBiet(char *s){
    int i = 0;
    int dem = 1, coun = 0;
    char b[50];
    while(s[i]){
        if(! isalnum(s[i]) && !daIn(b, coun, s[i] ) && s[i] != '\n'){
            int j = i + 1;
            while(s[j]){
                if(s[i] == s[j]){
                    ++dem;
                }
                ++j;
            }
            printf("ky tu '%c' xuat hien %d lan \n", s[i], dem);
            dem = 1;
        }
        ++i;
    }
}
int main(){
    char s[100];
    fgets(s, 99, stdin);
    printf("cac ky tu dac biet co trong cau:\n");
    demKyTuDacBiet(s);
    printf("\n\ncac phu am trong cau :\n");
    demPhuAm(s);
    printf("\n\ncac nguyen am trong cau :\n");
    denNguyenAm(s);

    return 0;
}
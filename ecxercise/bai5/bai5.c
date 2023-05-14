#include <stdio.h>
#include <ctype.h>
#include <string.h>

int daDem(char *x, char c, int a, int dk){
    int i = 0;
    x[a + 1] = NULL;
    while(x[i]){
        if(dk){
            if(x[i] == c){
                return 1;
            }
            ++i;
        }
        else{
            if(x[i] == tolower(c) || x[i] == toupper(c)){
                return 1;
            }
            ++i;
        }
        
    }
    return 0;
}

void demPhanBiet(char *s){
    char x[100];
    int dem = 1, i = 0, coun = 0; 
    while(s[i]){// đếm phân biệt hoa thường;
        if(!daDem(x, s[i], i, 1) && s[i] != '\n'){
            char b = s[i];
            int j = i + 1; 
            
            while(s[j]){
                if(b == s[j]){
                    ++dem;
                }
                ++j;
            }
            printf("ki tu %c xuat hien : %d\n", b, dem);
            dem = 1;
            x[coun++] = b;
        }
        ++i;
    }
}

void demKoPB(char *s){
    char x[100];
    int dem = 1, i = 0, coun = 0; 
    while(s[i]){// đếm ko phân biệt hoa thường;
        if(!daDem(x, s[i], i, 0) && s[i] != '\n'){
            char b = s[i];
            int j = i + 1; 
            
            while(s[j]){
                if(b == toupper(s[j]) || b == tolower(s[j])){
                    ++dem;
                }
                ++j;
            }
            printf("ki tu %c hoac %c xuat hien : %d\n", tolower(b), toupper(b), dem);
            dem = 1;
            x[coun++] = b;
        }
        ++i;
    }
}

int main(){
    char s[100], x[100];
    fgets(s, 100, stdin);  

    demKoPB(s);

    return 0;
}
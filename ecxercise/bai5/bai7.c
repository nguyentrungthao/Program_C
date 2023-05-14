// tìm chữ dài nhất và vị trí của nó
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int timViTri(char *s, int *doDai, int *viTri){
    int len = 0;// độ dài chữ đang xét
    int lenMax = 0; // độ dài chữ dài nhất
    int pot, potMax; // biến vị trí chữ đag xét và vị trí chữ dài nhất
    int i = 0; // biến lặp while
    int soChu = 0;// số chữ trong xâu đã được đếm để xđ vị trí của nó trong xâu
    int stt; // biến bị trị chữ dài nhất trong xâu
    while(s[i]){
        if(isalpha(s[i])){
            pot = i;
            ++soChu;
            while(isalpha(s[i])){
                ++len;
                ++i;
            }
            if(len > lenMax){
                lenMax = len;
                potMax = pot;
                stt = soChu;
            }            
        }
        len = 0;
        ++i;       
    }
    *doDai = lenMax;
    *viTri = stt;
    return potMax;
}

void xuat(char *s, int a, int len, int viTri){
    printf("chu dai nhat la :  ");
    for(int i = a ; i < a + len ; i++){
        printf("%c", s[i]);
    }
    printf("\t va la chu thu %d trong xau ",viTri);
}

int main(){
    char s[100];
    fgets(s, 99, stdin);
    int doDai, viTri;
    int pot = timViTri(s, &doDai, &viTri); 
    xuat(s, pot, doDai, viTri);
    
    return 0;
}
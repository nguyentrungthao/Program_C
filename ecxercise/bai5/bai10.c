#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int laMa_soThuong(char *s){
    int i, so = 0;
    int l = strlen(s) - 1;
    int a[l];

    for(i = 0; i < l; i++){
        switch (s[i])
        {
        case 'I':
            a[i] = 1;
            break;
        case 'V':
            a[i] = 5;
            break;
        case 'X':
            a[i] = 10;
            break;
        case 'L':
            a[i] = 50;
            break;
        case 'C':
            a[i] = 100;
            break;
        case 'D':
            a[i] = 500;
            break;
        case 'M':
            a[i] = 1000;
            break;
        }
    }
    
    for(i = 0; i < l - 1; i++){
        (*(a + i) > *(a + i +1)) ? (so += *(a + i)) : (so -= *(a + i));
    }
    so += a[l - 1];
    
    return so;
}

int soThuong_laMa(int n){
    // 399 = 300 + 90 + 9
    int m;
    int x = n;
    while(n > 0){
        m = n % 10;
        n /= 10;
        switch(m){
            case 1:
                printf("I");
                break;
            case 5:
                printf("V");
                break;
            case 10:
                printf("X");
                break;
            case 50 :
                printf("L");
                break;
            case 100:
                printf("C");
                break;
            case 500:
                printf("D");
                break;
            case 1000:
                printf("M");
                break;
        }
    }

}

int main(){
    char s[100];
    fgets(s, 99, stdin);

    printf("%d", docSo(s));

    return 0;
}
#include<stdio.h>
#include<conio.h>
#include<string.h>

const char c[] = {
    '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
    'S','T','R','S','T','U','V','X','Y','Z','W'
};

int main(){
    int n;
    scanf("%d",&n);

    while(n -- ){
        int a, b;
        char str[100];

        scanf("%d%d", &a, &b);        
            if(a == 0){
                printf(" 0 \n");
            }
            else{
            int i = -1;
            while(a){
                
                str[++i] = c[a % b];
                a /= b;
            }
            str[i] = '\0';
            strrev(str);
            puts(str);
        }
    }

    getch();
    return 0;
}
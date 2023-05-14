#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char x[]={ // mang doi chieu
		'A','B','C','D','E','F','G','H',
		'I','J','K','L','M','N','O','P','Q',
        'R','S','T','U','V','X','Y','Z','W','\0'
	};

void tach_in(char *s, const char *x){
    int i = 0;
    int j = 0;
    while(x[j]){
        while(s[i]){
            if(x[j] == toupper(s[i])){
                printf("%c  ",s[i]);
            }
            ++i;
        } 
        i = 0;       
        ++j;
    }
}

int main(){
    char s[100];
    fgets(s, 99, stdin);

    tach_in(s, x);

    return 0;
}
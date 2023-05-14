#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int viTri(char *s, char *s1){
    int i = 0;
    int dem = 0;
    while(s[i]){
        if(strstr(&s[i], s1) == &s[i]){
            ++dem;
        }
        ++i;
    }
    return dem;
}

void thayThe(char *s, char *s1, char *s2){
    int soLan = viTri(s, s1);
    int i = 0, j = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len = strlen(s);
    char *p = (char *)malloc(len + soLan * abs(len2 - len1) + 1);
    while(s[i]){
        if(strstr(&s[i], s1) == &s[i]){
            strcpy(&p[j], s2);
            i += len1;
            j += len2;
        }else{
            p[j++] = s[i++];
        }
    }
    p[j] = '\0';
    puts(p);
}

int main(){
   	char input[1000];
	char token[100];
	fgets(input, 999, stdin);
	fgets(token, 99, stdin);
	
	int len = strlen(token);
	if(len > 0) {
		token[len-1] = '\0';
	}

	int size = strlen(input);
	if(size > 0) {
		input[size-1] = '\0';
	}

	char des[100];
	fgets(des, 99, stdin);
	int newLen = strlen(des);
	if(newLen > 0) {
		des[newLen-1] = '\0';
    }
    
    thayThe(input, token, des);
    
    return 0;
}

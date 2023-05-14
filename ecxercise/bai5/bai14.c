#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dem(char *s1, char *s2){
    int i = 0;
    int dem = 0;
    while(s1[i]){
        if(strstr(&s1[i], s2) == &s1[i]){
            ++dem;
        }
        ++i;
    }
    return dem;
}

void xoa(char *s1, char *s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *p = (char *)malloc(len1 - len2 * dem(s1, s2) + 1);
    int i = 0, j = 0;
    while(s1[i]){
        if(strstr(&s1[i], s2) == &s1[i]){
            i += len2;
        }
        else{
            p[j++] = s1[i++];
        }
    }
    p[j] ='\0';
    puts(p);
}

int main(){
    char s1[100];
    char s2[100];
    fgets(s1, 99, stdin);
    fgets(s2, 99, stdin);
    int len1 = strlen(s1);
    if(len1 > 0){
        s1[len1 - 1] = '\0';
    }
    int len2 = strlen(s2);
    if(len2 > 0){
        s2[len2 - 1] = '\0';
    }

    xoa(s1, s2);

    return 0;
}
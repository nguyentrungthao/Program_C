#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void traiSangPhai(char* str) {
    printf("\n\n\t\tTRAI SANG PHAI\n");
    printf("DB ");
    printf("%s", str);
    char str1[200];
    int i = 0;
    while (i < 32) {
        strcpy(str1 + 5, str);
        str1[0] = '0';
        str1[1] = str1[2] = 'F';
        str1[3] = 'H';
        str1[4] = ',';
        str1[159] = '\n';
        str1[160] = '\0';
        printf("DB ");
        printf("%s", str1);
        strcpy(str, str1);
        i++;
    }
    printf("\n\n\n\n\n\n\n\n\n");
}

void phaiSangTrai(char* str) {
    printf("\t\t\tPHAI SANG TRAI\n");
    printf("DB ");
    printf("%s", str);
    char str1[200];
    int i = 0;
    while (i < 32) {
        strcpy(str1, str + 5);
        str1[155] = '0';
        str1[157] = str1[156] = 'F';
        str1[158] = 'H';
        str1[154] = ',';
        str1[159] = '\n';
        str1[160] = '\0';
        printf("DB ");
        printf("%s", str1);
        strcpy(str, str1);
        i++;
    }
    printf("\n\n\n\n\n\n\n\n\n");
}

int main() {
    char str[165];
    char str1[165];

    while (1) {
        fgets(str, 164, stdin);

        strcpy(str1, str);
        phaiSangTrai(str);
        traiSangPhai(str1);

    }

    getch();
    return 0;
}
//0FFH,0FFH,0FFH,0FFH,0FFH,0FFH,0FFH,0FFH,0FFH,0FFH,0FFH,0FFH,0FFH,0BBH,0BDH,080H,0BFH,0BFH,0FFH,0FFH,09DH,0AEH,0B6H,0BAH,0BDH,0FFH,0FFH,0FFH,0FFH,0FFH,0FFH,0FFH\n
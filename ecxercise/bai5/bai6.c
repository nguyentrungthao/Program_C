#include <stdio.h>
#include <string.h>
#include <ctype.h>

int firstChar(char *s){
    int i = 0;
    while(s[i]){
        if(isalnum(s[i])){
            return i;
        }
        ++i;
    } 
    return i;
}

// void vietHoa(char *s, int i){
//     if(isalpha(s[i])){
//         s[i] = toupper(s[i]);
//     }
// }

// void vietThuong(char *s, int i){
//     while(s[i + 1] || isblank(s[i + 1])){
//         s[i + 1] = towlower(s[i + 1]);
//         ++i;
//     }
// }

void deleteFirstBlank(char *s, int i){
    int a = i;
    i = 0; 
    while(s[i]){
        s[i] = s[i + a];
        ++i;
    }
}
void deleteEndBlank(char *s){
    int i = strlen(s) - 1;
    while(s[i]){
        if(isblank(s[i]) || isspace(s[i])){
            s[i] = '\0';
        }
        if(isalnum(s[i])){
            break;
        }
            
        --i;
    }
}

void dinhDang(char *s){
    int i = 0;
    while(s[i]){
       s[i] = toupper(s[i]);
       ++i;
       while(isalnum(s[i])){
           s[i] = tolower(s[i]);
           ++i;
       } 
       ++i;     
    }
}

int main(){
    char s[100];
    fgets(s, 100, stdin);

    int i = firstChar(s);

    deleteFirstBlank(s, i);
    deleteEndBlank(s);

    dinhDang(s);

    puts(s);

    return 0;
}
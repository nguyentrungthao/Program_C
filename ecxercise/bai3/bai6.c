#include<stdio.h>
#include<conio.h>
#include<math.h>



int main(){
    int y,x;
    for(y=1; y<7; y++){
        for(x=1; x<=7; x++){
            if(y==1){
                if(x==1 || x==4 || x==7 ){
                    printf("  ");
                }
                else
                    printf("* ");
                }
            else if(y==4){
                if(x==1 || x==7){
                    printf("  ");
                }
                else
                    printf("* ");
                }
            else if(y==5){
                if(x>5 || x <3){
                    printf("  ");
                }
                else
                    printf("* ");
                }
            else if(y==6){
                if(x!=4){
                    printf("  ");
                }
                else
                    printf("* ");
                }
            else 
                printf("* ");
        }
        printf("\n");
    }
    
    return 0;
    getch();
}
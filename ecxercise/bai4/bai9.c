#include<stdio.h>
#include<conio.h>

int nhapN(){
    int n; 
    do{
        printf("nhap so phan tu cua mang n > 0 : ");
        scanf("%d",&n);
    }while(n < 1);

    return n;
}

void nhapMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] : ",i);
        scanf("%d",&a[i]);
    }
}
int trung(int *b, int n, int x){
    for(int i = 0; i < n; i++){
        if(b[i] == x){
            return 0;
        }
    }
    return 1;
}
void dem(int *a, int n){
    int j,i, k = 0 ;
    int b[100];              // int b[n];
    int dem = 1;
    for(i = 0; i < n; i++){
        if(trung(b, n, a[i])){
            for(j = i + 1; j < n; j++){
                if(a[i] == a[j]){
                    dem ++;

                }
            }
            b[k++] = a[i];
            printf("so lan xuat hien cua %d la %d\n", a[i], dem);
            dem = 1;
        }  
    }
}
int main(){
    int n = nhapN();
    int a[n];

    nhapMang(a, n);
    dem(a, n);

    getch();
    return 0;
}
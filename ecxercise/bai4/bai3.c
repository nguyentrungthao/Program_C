#include<stdio.h>

#define n 8

int* nhap(){
    static int a[n];
    for(int i = 0; i < n; i++){
        printf("a[%d]",i);
        scanf("%d",&a[i]);
    }
    return a;
}

void xuat(const int a[]){
    for(int i = 0; i < n; i++){
        printf("%d  ",a[i]);
    }
}

// void sapXep(int a[]){
//     for(int i = 0; i < n - 1; i++){
//         for(int j = n - 1; j > i; j--){
//             if(a[j - 1] > a[j]){ // tăng dần
//                 int tmb = a[j];
//                 a[j] = a[j - 1];
//                 a[j - 1] = tmb;
//             }
//         }
//     }
// }

void selectionSort(int a[]){ // 6 3 8 -20 19 2 6
    int j, i;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                int tg = a[i];
                a[i] = a[j];
                a[j] = tg;              
            }
        }           
    }
}

int main(){
    int *a;

    a = nhap();
    selectionSort(a);
    xuat(a);

    return 0;
}
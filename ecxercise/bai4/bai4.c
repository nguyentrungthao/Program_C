#include<stdio.h>
#include<conio.h>

int nhapN(){
    int n;
    do{
        printf("nhap so phan tu mang n > 0: ");
        scanf("%d", &n);
    }
    while(n < 1);

    return n;
    
}
int nhapX(){
    int n;
        printf("nhap so can dem: ");
        scanf("%d", &n);

    return n;
    
}


void nhapMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d]",i);
        scanf("%d",&a[i]);
    }
}

// int xuatHien(int *a, int n, int x){
//     int start =0, end = n;
//     for(int i = start; i < end; i++){
//         int mid = (start + end) / 2;
//         if(a[mid] == x){
//             return 1;
//         }
//         else if(a[mid] < x){
//             start = mid + 1;
//         }
//         else {
//             end = mid - 1;
//         }
//     }
//     return 0;   
// }

int demX(int *a, int n, int x){
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            dem ++;
        }
    }
    return dem;
}


int main(){
    int n = nhapN();
    int a[n];

    nhapMang(a, n);
    int x = nhapX();

    printf("so lan %d xuat hien la : %d \n", x, demX(a, n, x));

    getch();
    return 0;
}
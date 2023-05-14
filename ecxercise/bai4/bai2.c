#include<stdio.h>
#include<conio.h>


int nhapN(){
    int n;
    do{
        printf("nhap so phan tu cua mang n > 0: ");
        scanf("%d", &n);
    }while(n < 1);

    return n;
}

void nhapMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d]", i);
        scanf("%d", &a[i]);
    }
}

void sapxep(int *a, int n){
    int i,j;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                a[i] = a[i] ^ a[j];
                a[j] = a[i] ^ a[j];
                a[i] = a[i] ^ a[j];
            }
        }
    }
}

void minmax2(int *a, int n, int *min2, int *max2){
    for(int i = 1; i < n; i++){
        if(a[0] != a[i]){
            (*min2) = a[i];
            break;
        }
    }
    for(int i = n - 1; i > 0; i--){
        if(a[n - 1] != a[i]){
            (*max2) = a[i];
            break;
        }
    }
}

void xuat( int *a, int n, int min2, int max2){
    if(min2 == max2 || a[0] == a[n]){
        printf(" khong co gia tri lon nhi");
    }
    else{
        printf("MIN2 = %d\nMAX2 = %d", min2, max2);
    }

}

int main(){
    int min2, max2;
    int n = nhapN();
    int a[n];

    nhapMang(a, n);
    sapxep(a, n);
    minmax2(a, n, &min2, &max2);
    xuat(a, n, min2, max2);

    getch();
    return 0;
}


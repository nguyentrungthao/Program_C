#include<stdio.h>
#include<conio.h>

int nhapN(){
    int n;
    do{
        printf("nhap so phan tu cua mang n > 0: ");
        scanf("%d",&n);
    }while(n < 1);

    return n;
}

void nhapMang(int *a, int n){
    for(int i = 0; i < n - 1; i++){
        printf("a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}

int nhapX(){
    int x;
    printf("nhap x : ");
    scanf("%d",&x);

    return x;
}

void sapxep(int *a, int n){
    int i,j;
    for(i = 0; i < n -1; i++){
        for(j = i + 1; j < n - 1; j++){
            if(a[i] > a[j]){
                a[i] = a[i] ^ a[j];
                a[j] = a[i] ^ a[j];
                a[i] = a[i] ^ a[j];
            }
        }
    }
}

int timViTri(int *a, int n, int x){ // sắp xếp các điều kiện dễ xet lên trước
    if(x < a[0]){
        return 0;
    }
    else if(a > a[n - 1]){
        return n - 1;
    }
    for(int i = 0; i < n; i++){ //1 2 3 4      6 7 8 9
        if(a[i] >= x){ 
            return i;
        }
    }
}

void chen(int *a, int n, int x, int k){
        for(int i = n - 1; i > k; i--){
            a[i] = a[i - 1];
        }
        a[k] = x;
}

void xuat(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
}

int main(){
    int n = nhapN();
    
    int a[n];
    nhapMang(a, n);
    int x = nhapX();
    
    sapxep(a, n);
    chen(a, n, x, timViTri(a, n, x));
    xuat(a, n);

    getch();
    return 0;
}
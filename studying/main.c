#include <stdio.h>
#include "lib/datatType.h"
#include <string.h>

hocsinh nhap() {
    hocsinh a;
    printf("nhap ho ten: ");
    fgets(a.hoTen, 29, stdin);
    printf("nhap tuoi: ");
    scanf("%d", &a.tuoi);
    printf("nhap gioi tinh(nam 1 nu 0): ");
    fflush(stdin);
    scanf("%d", &a.gioiTinh);

    return a;
}

void xuat(hocsinh x) {
    printf("ten: %-15s tuoi: %-3d ", x.hoTen, x.tuoi);
    if (x.gioiTinh)
        printf("nam\n");
    else
        printf("nu\n");
}

int main() {
    hocsinh x;
    // x = nhap();
    // xuat(x);

    printf("\n\t\t%d", hello);
    printf("\n%d", a);

    return 0;
}
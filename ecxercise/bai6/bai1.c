#include <stdio.h>

#define led 13

struct phanso {
    int tu;
    int mau;
};

typedef struct phanso phanso;

phanso nhap(){
    phanso a;
    printf("nhap tu so: ");
    scanf("%d", &a.tu);
    do{
        printf("nhap mau so khac 0: ");
        scanf("%d", &a.mau);
    }while(a.mau == 0);

    return a;
}

int UCLN(int a, int b){
    int ucln;
    while(a != b){
        if(a > b){
            ucln = a - b;
            a -= b;
        }
        else{
            ucln = b - a;
            b -= a;
        }
    }
    return ucln;
}
phanso rutGon(phanso a){
    int ucln = UCLN(a.tu, a.mau);
    a.tu /= ucln;
    a.mau /= ucln;
    return a;
}

phanso tong(phanso a, phanso b){
    phanso t;
    t.mau = a.mau * b.mau / UCLN(a.mau, b.mau);
    t.tu = t.mau *a.tu / a.mau + t.mau * b.tu / b.mau ;
    return rutGon(t);
}

phanso hieu(phanso a, phanso b){
    phanso h;
    h.mau = a.mau * b.mau / UCLN(a.mau, b.mau);
    h.tu = h.mau * a.tu / a.mau - h.mau * b.tu / b.mau ;
    return rutGon(h);
}
phanso tich(phanso a, phanso b){
    phanso t;
    t.mau = a.mau * b.mau;
    t.tu = a.tu * b.tu;
    return rutGon(t);
}

phanso thuong(phanso a, phanso b){
    phanso t;
    t.tu = a.tu * b.mau;
    t.mau = a.mau * b.tu;
    return rutGon(t);
}

void xuat(phanso a){
    printf("%d/%d\n\n", a.tu, a.mau);
}

int main(){
    phanso a, b;
    int luaChon;
    do{
        printf("================ MENU ================");
        printf("\n\t1. rut gon phan so");
        printf("\n\t2. cong 2 phan so");
        printf("\n\t3. tru 2 phan so");
        printf("\n\t4. nhan 2 phan so");
        printf("\n\t5. chia 2 phan so");
        printf("\n\t0. thoat\n");
        printf("lua chon : ");
        scanf("%d",&luaChon);

        switch (luaChon)
        {
        case 0:
            printf("thoat");
            break;

        case 1:
            xuat(rutGon(nhap()));
            break;

        case 2:
            a = nhap();
            b = nhap();
            xuat(tong(a, b));
            break;
        
        case 3:
            a = nhap();
            b = nhap();
            xuat(hieu(a, b));
            break;
        
        case 4:
            a = nhap();
            b = nhap();
            xuat(tich(a, b));
            break;

        case 5:
            a = nhap();
            b = nhap();
            xuat(thuong(a, b));

        default:
            printf("nhap sai!");
            break;
        }


    }while(luaChon);


    return 0;
}
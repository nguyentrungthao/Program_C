#include<stdio.h>
#include<conio.h>
#include<math.h>

int luaChon(){
    int n;
    do{
        printf("nhap lua chon\n");
        scanf("%d", &n);
    }
    while(n < 1);

    return n;
}
int nhapSo(){
    int n;
    do{
        printf(" nhap so  > 0: ");
        scanf("%d", &n);
    }
    while( n <= 0);

    return n;
}
void bai1(int m, int n){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ",j);
        }
        printf("\n");
    }
}
void bai2(int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; i++){
            printf("X ");
        }
        printf("\n");
    }
}
void bai3(int h){
    int i;
    for(i = 1; i <= h; i++){
        for(int j = 1; j <= i; j++){
            printf("* ");
        }
        printf("\n");
    }
}
void bai4(int h){
    for(int i = 1; i <= h; i++){
        for(int j = 1; j < 2*h; j++){
            if(abs(h - j ) <= (i -1)){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        pritnf("\n");
    }
}
void bai5(int h){
    for(int i = 1; i <= h; i++){
        for(int j = 1; j < 2*h; j++){
            if(abs(h - j) <= (i -1)){
                printf("%d ",i - abs(h -j));
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}
void bai6(){
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 7; j++){
            if( i == 1 && (j == 1 || j==4 || j == 7)){
                printf("  ");
            }
            else if( i== 4 && (j == 1 || j==7)){
                printf("  ");
            }
            else if( i == 5 && (j < 3 || j >5)){
                printf("  ");
            }
            else if(i==6 && j != 4){
                printf("  ");
            }
            else {
                printf("* ");
            }
        }
    }
}
int thuanNgich(int n){
    int m = n, dao =0;
    while( n > 0){
        dao = dao * 10 + n % 10;
        n /= 10;
    }
    if(dao == n)
        return 1;
    else 
        return 0;
}
int SNT(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return 0;
            break;
        }
    }
    return 1;
}
int tongChuSo(int n){
    int s = 0;
    while(n > 0){
        s += n % 10;
        n /= 10;
    }
    return s;
}
void phanTichSNT(int n){
    int dem = 0, i = 2;
    while(n > 0){
        if(n % i == 0){
            dem ++;
            if(n == i && dem > 1){
                printf("%d^%d", i, dem);
                dem = 0;
            }
            else{
                printf("%d", i);
            }
            
        }
        else {
            if (dem > 1){
                printf("%d^%d", i, dem);
                dem = 0;
            }
            else if(dem == 1){
                printf("%d",i);
            }
            if(n >= i){
                pritnf(" x ");
            }

            i++;
        }
    }
}
int demChuSo(int n){
    int dem = 0;
    while(n > 0){
        dem ++;
        n /= 10;
    }
    return dem;
}
int demChuSoLe(int n){
    int dem = 0;{
        while(n > 0){
            int dk = n % 10;
            if( dk % 2 == 0){
                dem++;
            }
        }
    }
    return dem;
}
float TBCong(int n){
    float tb = (float)tongChuSo(n) / demChuSo(n);
    return tb;
}
int tangDan(int n){
    int a1 = 0;
    int a2 = n % 10;
    while(n > 0){
        n /= 10;
        if (a1 > a2){
            return 0;
            break;
        }
        a1 = a2;
        a2 = n % 10;
    }
    return 1;
}
int chuSoDauTien(int n){
    int a;
    while(n > 0){
        a = n % 10;
        n /= 10;
    }
    return a;
}
int demSoDauTien(int n){
    int dem = 0;
    while(n > 0){
        int a = n % 10;
        if(a == chuSoDauTien(n)){
            dem ++;
        }
    }
    return dem;
}
void lietKeUoc(int n){
    for(int i = 1; i <=n; i++){
        if(n % i == 0){
            printf("%d ",i);
        }
    }
}
int demUoc(int n){
    int dem = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            dem ++;
        }
    }
    return dem;
}
void uocSNT(int n){
    for(int i = 2; i <= n; i++){
        if(SNT(i)){
            printf("%d ",i);
        }
    }
}
void lietKeSNT(int n){
    int i = 2;
    while(n > 0){
        if(SNT(i)){
            printf("%d ",i);
            n--;
        }
        i++;
    }
}
void lietKeFi(int n){
    int f1 = 1, f0 =0, fn;
    while(n > 0){
        fn = f1 + f0;
        printf("%d  ", fn);
        f0 = f1; 
        f1 = fn;
        n--;
    }
}
void lietKeChinhPhuong(int n){
    int i = 1;
    while(n > 0){
        if(sqrt(i) * sqrt(i) == i){
            printf("%d  ",i);
            n--;
        }
        i++;
    }
}
int chuSoSNT(int n){
    int a;
    while(n > 0){
        a = n % 10;
        if(SNT(a)){
            return 0;
            break;
        }
        n /= 10;
    }
    return 1;
}
int tongChuSoSNT(int n){
    int s = 0;
    while(n > 0){
        s += n % 10;
        n /= 10;
    }
    return SNT(s);
}
int so6(int n){
    while(n > 0){
        if(n % 10 == 6){
            return 0;
            break;
        }
        n /= 10;
    }
    return 1;
}
int khongTang(int n){
    int a1 = 0; 
    int a2 = n % 10;
    while(n > 0){
        if(a1 > a2){
            return 0;
            break;
        }
        n /= 10;
        a1 = a2;
        a2 = n % 10;
    }
    return 1;
}
int khongGiam(int n){
    int a1 = 10; 
    int a2 = n % 10;
    while(n > 0){
        if(a1 < a2){
            return 0;
        }
        n /= 10;
        a1 = a2;
        a2 = n % 10;
    }
    return 1;
}
int chanBangLe(int n){
    int chan =0, le =0;
    while(n > 0){
        int a = n % 10;
        if(a % 2 == 0){
            chan += a;
        }
        else{
            le += a;
        }
    }
    return (le == chan) ? 1 : 0;
}
int chiahet(int n, int k){
    if(n % k == 0){
        return 1;
    }
    else return 0;
}
int pascal(int n, int k){
    if(k == 0 || k == n){
        return 1;
    }
    return pascal(n - 1, k - 1) + pascal(n - 1, k);
}

int main(){
    int luachon;
    do{
        printf("MENU\n 1. hinh chu chat so \n 2. hinh chu nhat sao \n 3. tam giac vuong sao \n 4. tam giac can sao\n 5. tam giac can so\n 6. trai tim\n 7. so thuan nghich 8 chu so chia het k\n 8. so nguyen to trong doan a, b\n 9. \n 9.1 tong chu so n  9.2 phan tich so nguyen to\n");
        scanf("%d",&luachon);
    }
    while(luachon > 17);

    switch (luachon){
    case 1:
        bai1(nhapso(), nhapSo());
        break;
    
    case 2:
        bai2(nhapSo(), nhapSo());
        break;
    case 3:
        bai3(nhapSo());
        break;
    case 4:
        bai4(nhapSo());
        break;
    case 5:
        bai5(nhapSo());
        break;
    case 6:
        bai6();
        break;
    case 7:
        int n = nhapSo();
        for(int i = 10000000; i <= 99999999; i++){
            if(thuanNgich(i) && chiahet(i, n)){
                printf("%d",i);
            }
        }
        break;

    case 8:
        int a = 1 + nhapSo();
        int b = nhapSo() - 1;
        for(int i = a; i <= b; i++){
            if(SNT(i)){
                printf("%d ",i);
            }
        }
        break;

    case 9:
        printf("1. tong chu so n      2. phan tich so nguyen to");
        do{
            int n = luaChon();
        }while(n > 2);
        int m = nhapSo();
        switch (n){
            case 1:
                printf("tong cac chu so cua %d = %d", m, tongChuSo(n));
                break;
            
            default:
                printf("%d = ",n);
                phanTichSNT(n);
                break;
        }
        break;

    case 10:
        printf("1. dem chu so cua n      2. dem chu so le cua so n    3. trung trinh cong cac chu so cua n");
        do{
            int n = luaChon;
        }while(n > 3);
        int m = nhapSo();
        switch (n){
            case 1:
                printf("so %d co %d chu so", m, demChuSo(m));
                break;
            case 2:
                printf("so %d co %d chu so le", m, demChuSoLe(m));
                break;
            case 3:
                printf("trung binh cong cac chu so cua %d = %d ", m, TBCong(m));
                break;
        }
        break;

    case 11:
        printf("1. kiem tra so n co tang dan    2. tim chu so dau tien      3. dem so lan xuat hien cua so dau tien");
        do{
            int n = luaChon;
        }while(n > 3);
        int m = nhapSo();
        switch(n){
            case 1:
                (tangDan(m)) ? printf("%d tang dan",m) : printf("%d KHONG tang dan", m);
                break;
            case 2:
                printf("chu so dau tien cua %d la %d ",m ,chuSoDauTien(m));
                break;
            case 3:
                printf("chu so dau tien cua %d xuat hien %d lan", m, demSoDauTien(m));
                break;
        }
        break;

    case 12:
        printf("1. liet ke cac uoc      2. dem uoc      3. liet ke cac uoc so nguyen to");
        do{
            int n = luaChon;
        }while(n > 3);
        int m = nhapSo();
        switch (n)
        {
        case 1:
            lietKeUoc(m);
            break;
        case 2:
            printf("so %d co %d uoc ", m, demUoc(m));
            break;
        case 3:
            uocSNT(m);
            break;
        }
        break;

    case 13:
        printf("1. liet ke n SNT dau tien       2. liet ke n so Fi      3. liet ke n so chinh phuong");
        do{
            int n = luaChon;
        }while(n > 3);
        int m = nhapSo();
        switch(n){
            case 1:
                lietKeUoc(m);
                break;
            case 2:
                lietKeFi(m);
                break;
            case 3:
                lietKeChinhPhuong(m);
                break;
        }
        break;

    case 14:
        for(int i = 20000000; i <= 77777777; i++){
            if(chuSoSNT(i) && tongChuSoSNT(i)){
                printf("%d ",i);
            }
        }
        break;
    case 15:
        for(int i = 10000000; i <= 99999999; i++){
            if(thuanNgich(i) && so6(i) && tongChuSoSNT(i)){
                printf("%d  ",i);
            }
        }
        break;

    case 16:
        int n = nhapSo();
        int k = nhapSo();
        printf("%dC%d = %d", k, n, pascal(n, k));
        break;
    case 17:
        printf("1. la cac so khong tang     2. la cac so khong giam        3. co tong chu so chan = tong chu so le");
        do{
            int n = luaChon;
        }while(n > 3);
        for(int i = 10000; i <= 99999; i++){
            if( n == 1 && khongTang(i)){
                printf("%d ",i);
            }
            else if(n == 2 && khongGiam(i)){
                printf("%d ",i);
            }
            else if(n == 3 && chanBangLe(i)){
                printf("%d ",i);
            }
        }
        break;
    
    }

    return 0;
    getch();
}
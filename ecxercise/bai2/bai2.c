#include<stdio.h>
#include<conio.h>
#include<math.h>

void space(){
    printf("\n");
}

void dayLe(int n){
    for(int i=1;i<n;i++){
        if(i%2!=0)
            printf("%d  ",i);
    }
}

void dayChan(int n){
    for(int i=1;i<n;i++){
        if (i%2==0)
            printf("%d  ",i);       
    }
}

int bai2(int n){
    int s=0;
    if(n<=0) return 0;
    else{
    for(int i=1;i<=n;i++){
         s += i;
    }}
    return s;
}

float bai3(int n){
    float s=0;
    for(float i =1;i<=n;i++){
         s += 1/i;
    }
    return s;
}

int bai4(int n){
    int s=0;
    for(int i=1;i<=n;i++){
        s += i;
    }
    return s;

}

int bai4a(int n){
    int s=0;
    for (int i = 1; i < n; i++)
    {
        if(i%2!=0){
            s += i;
        }
    }
    return s;
}

int bai4b(int n){
    int s=0;
    for (int i = 1; i < n; i++)
    {
        if(i%2==0){
            s+= i;
        }
    }
    return s;
}

int bai5(int n){
    int s=0;
    int giaithua =1;
    for(int i=1;i<=n;i++){
        giaithua *= i;
        s += giaithua;
    }
    return s;
}

int bai6(int n){
    int s=0;
    for(int i=1;i<=n;i++){
        if(i%7==0)
        s += i;
    }
    return s;
}

int bai7(int n){
    int dem=0;
    for(int i=2;i<n;i++){
        if(n%i==0){
            dem++;
        }
    }
    return dem;
}

int UCLN(int n,int m){
    while(m!=n){
    if(m>n)
        m -= n;
    else
        n -= m;
    }
    return m;
}

int BCNN(int n,int m){
    int a =m*n;
    return a/UCLN(n,m);
}

int soNguyenTo(int n){
    int dem=0;
    for(int i=2;i<n;i++){
        if(n%i==0)
            dem++;
    }
    if(dem>0) return 0;//không là số nguyên tố
    else return 1;//là số nguyên tố
}

void phanTich(int n){
    int i=2;
    if(n<0)
        printf("khong the pha tich");
    else{
        while(n>1){
            if(n%i==0){
                printf("%d",i);
                n /= i;
                if(i<=n) printf(" X ");
                }
            else
                i++;   
        }
    }
}

void phanTichLuyThua(int n){
    unsigned int i =2;
    unsigned int dem=0;
    if(n<0)
        printf("nhap lai so n>1");
    else{
        while(n>1){
            if(n%i==0)
            {
                dem++;               
                if(n == i){
                    if(dem>1)
                        printf("%d^%d",i,dem);
                    else 
                        printf("%d",i);              
            }
            n /=i;
        }
            else
            {
                if(dem>1)
                {
                    printf("%d^%d",i,dem);}
                else
                    printf("%d",i);
                if(n>=i) 
                    printf(" x ");
                dem = 0;
                i++;
            }

        }
    }
}

void lietKeSNT(int n){
    if(n<=0) printf("vui long nhap lai");
    else{
    int snt=2;
        while(n>0){
            int dem=0;
            for(int i=2;i<snt;i++){
                if(snt%i==0) dem++;
            }

            if(dem==0) 
            {
                printf("%d  ",snt);
                n--;
            }
            snt++;
        }
    }
}

void bai12(int n){
    int f0 = 0 , f1= 1 , i=2 ,fn;
    if(n==0)
        printf("F0 = %d",f0);
    if(n==1)
        printf("F1 = %d",f1);
    if(n<0) 
        printf("nhap lai n >0");
    else
        for( ; i<=n ; i++){
            fn = f1 + f0;
            f0 = f1;
            f1 = fn;
        }
    printf("so fibo thu %d = %d\n",i-1,fn);
    
}

void thuanNghich(int n){
    int dao=0,m=n;
    while(m>0){
        dao = dao * 10 + m%10;
        m /= 10;
    }
    if(n == dao){
        printf("la so thuan nghich");
    }
    else {
        printf("khong la so thuan nghich");
    }
}

void giaithua(int n){
    unsigned int s=1,a=n;
    for(;n>1;n--){
        s *= n;
    }
    printf("%d! = %d",a,s);
}

void tongChuSo(int n){
    int s=0;
    while(n>0){
        s += n%10;
        n /= 10;
    }
    printf("tong cac chu so = %d",s);
}

void bai16(int n, int m){
    for(;m<n;++m){
        int sqr = sqrt(m);
        if(sqr*sqr == m)
        printf("%d ",m);
    }
}

void pi(float a){
    int doDau = -1, n = 0;
    float pi = 0, N = 1; 
    while(N>=a){
        N = 1.0/(2*n+1);
        pi += (-1) * doDau * N;
        doDau *= (-1);
        n++;
    }
    pi *= 4;
    printf("so pi bang %0.10lf ",pi);
}

void eMuX(double a, double x ){
    double e = 1, xMuk = x;
    unsigned int k = 1;
    unsigned long long kGiaiThua =1;
    double dk = 1;

    while(dk >= a){
        e += xMuk / kGiaiThua;
        
        k++;
        xMuk *= x;
        kGiaiThua *= k;

        dk = xMuk / kGiaiThua;

    }
    printf("e^%lf = %lf ",x, e);
    
}

int main(){
    double a,x;
    printf("nhap so a va x : ");
    scanf("%lf%lf",&a,&x);

    eMuX(a,x);

    return 0;
    getch();
}



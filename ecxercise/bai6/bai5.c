#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct hoTen{
    char ho[10];
    char dem[30];
    char ten[10];
};
typedef struct hoTen hoTen;

struct ngaySinh{
    int ngay;
    int thang;
    int nam;
};
typedef struct ngaySinh ngaySinh;

struct sinhVien{
    char ma[6];
    hoTen ht;
    ngaySinh ns;
    float tbc;
    char hocLuc[11];
};
typedef struct sinhVien sinhVien;

void nhapTen(hoTen *a){
    printf("nhap ho : ");
    scanf("%s", a->ho);

    fflush(stdin);
    printf("nhap dem : ");
    gets(a->dem);

    printf("nhap ten : ");
    scanf("%s", a->ten);
}

// void nhapNgsih(ngaySinh *a){
//     printf("ngay sinh: ");
//     scanf("%d", a->ngay);

//     printf("thang sinh: ");
//     scanf("%d", a->thang);

//     printf("nam sinh");
//     scanf("%d", a->nam);
// }

char *hocLuc(float diem, char *s){
    s = (char *)malloc(20 * sizeof(char));
    if(diem >= 9){
        strcpy(s, "xuat sac");
    }
    else if(diem < 9 && diem >= 8){
        strcpy(s, "gioi");
    }
    else if(diem < 8 && diem >= 6.5){
        strcpy(s, "kha");
    }
    else if(diem < 6.5 && diem >= 4){
        strcpy(s, "trung binh");
    }
    else {
        strcpy(s, "yeu");
    }

    return s;

}

sinhVien nhap(){
    sinhVien a;
    char *s;

    fflush(stdin);
    printf("Nhap ma : ");
    gets(a.ma);

    nhapTen(&a.ht);

    //nhapNgsih(&a.ns);
    printf("ngay sinh: ");
    scanf("%d", &a.ns.ngay);

    printf("thang sinh: ");
    scanf("%d", &a.ns.thang);

    printf("nam sinh : ");
    scanf("%d", &a.ns.nam);


    printf("nhap diem trung binh : ");
    scanf("%f",&a.tbc);

    strcpy(a.hocLuc, hocLuc(a.tbc, s));
    free(s);

    return a;
}

void xuat(sinhVien a){
    printf("%-10s %-10s %-20s %-10s %-10d %-10d %-10d %-10.2f %-10s\n",
    a.ma, a.ht.ho, a.ht.dem, a.ht.ten, a.ns.ngay, a.ns.thang, a.ns.nam, a.tbc, a.hocLuc);
}

void timTheoMa(sinhVien *sv, int solg){
    printf("nhap ma can tim: ");
    char ma[6];
    fflush(stdin);
    gets(ma);
    int a[solg], dem = 0;

    int i;
    for(i = 0; i < solg; i++){
        if(strcmp(sv[i].ma, ma) == 0){
            a[dem++] = i;
        }
    }
    if(dem == 0){
        printf("khong co sinh vien co ma %s trong danh sach!",ma);
    }else{
        printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n",
        "ma", "ho", "dem", "ten", "ngay sinh", "thang sinh", "nam sinh", "diem TB", "hoc luc");

        for(i = 0; i < dem; i++){
            xuat(sv[a[i]]);
        }
    }
}

void timTheoTen(sinhVien *sv, int solg){
    char ten[10];
    printf("nhap ten : ");
    scanf("%s", ten);
    int a[solg], dem = 0;

    int i; 
    for(i = 0; i < solg; i++){
        if(strcmp(sv[i].ht.ten, ten) == 0){
            a[dem++] = i;
        }
    }

    if(dem == 0){
        printf("khong co sinh vien co ten %s trong danh sach!\n",ten);
    }else{
        printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n",
        "ma", "ho", "dem", "ten", "ngay sinh", "thang sinh", "nam sinh", "diem TB", "hoc luc");
        for(i = 0; i < dem; i++){
            xuat(sv[a[i]]);
        }
    }
}

void timTheoDiem(sinhVien *sv, int solg){
    float diem;
    printf("nhap diem: ");
    scanf("%f",&diem);
    int a[solg], dem = 0;

    int i;
    for(i = 0; i < solg; i++){
        if(diem == sv[i].tbc){
            a[dem++] = i;
        }
    }

    if(dem == 0){
        printf("khong co sinh vien co diem %f trong danh sach!\n",diem);
    }else{
        printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n",
        "ma", "ho", "dem", "ten", "ngay sinh", "thang sinh", "nam sinh", "diem TB", "hoc luc");
        for(i = 0; i < dem; i++){
            xuat(sv[a[i]]);
        }
    }
}

void xoaTheoMa(sinhVien *sv, int *solg, char *ma){

    int i, j, dem = 0;
    for(i = 0; i < *solg; i++){
        if(strcmp(sv[i].ma, ma) == 0){
            for(j = i; i < *solg; i++){
                sv[j] = sv[j + 1];
            }
            ++dem;
        }
    }
    *solg -= dem;
}

void sapXepTheoDiemGiamDan(sinhVien *sv, int solg){
    int i, j;

    for(i = 0; i < solg; i++){
        for(j = i + 1; j < solg; j++){
            if(sv[i].tbc > sv[j].tbc);
            sinhVien a = sv[i];
            sv[i] = sv[j];
            sv[j] = a;
        } 
    }
}

void sapXepTheoTen(sinhVien *sv, int solg){
    int i, j;

    for(i = 0; i < solg; i++){
        for(j = i + 1; i < solg; i++){
            if(strcmp(sv[i].ht.ten, sv[j].ht.ten) > 0){
                sinhVien a = sv[i];
                sv[i] = sv[j];
                sv[j] = a;
            }
        }
    }
}

void ghiFILE(sinhVien *a, int solg){
    FILE *f;
    f = fopen("C:\\Users\\nguye\\OneDrive\\Documents\\bai6.txt", "a");

    fprintf(f, "%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
    "ma", "ho", "dem", "ten", "ngay sinh", "thang sinh", "nam sinh", "diem TB", "hoc luc");

    for(int i = 0; i < solg; i++){
        fprintf(f, "%-10s %-10s %-10s %-10s %-10d %-10d %-10d %-10.2f %-10s\n",
        a[i].ma, a[i].ht.ho, a[i].ht.dem, a[i].ht.ten, a[i].ns.ngay, 
        a[i].ns.thang, a[i].ns.nam, a[i].tbc, a[i].hocLuc);
    }

    fclose(f);
}

// printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s",
// "ma", "ho", "dem", "ten", "ngay sinh", "thang sinh", "nam sinh", "diem TB", "hoc luc");


int main(){
    sinhVien sv[99];
    // char *s;
    int solg = 0;

    int luaChon;
    do{
        printf("================ MENU =============\n");
        printf("\t1.nhap sinh vien vao danh sach\n\t2. hien thi danh sach sinh vien\n\t3. tim sinh vien theo ma\n\t");
        printf("4. tim theo ten\n\t");
        printf("5. tim sinh vien theo diem trung binh\n\t6. xoa sing vien theo ma\n\t7. sap xep theo diem TB giam dan");
        printf("\n\t8. sap xep theo ten a -> z\n\t9. in vao file \n\t0. thoat");
        printf("\n\t LUA CHON : ");
        scanf("%d", &luaChon);

        switch(luaChon){
            case 0:
                break;
            
            case 1:
                printf("nhap sinh vien thu : %d\n", solg + 1);
                sv[solg] = nhap();
                ++solg;
                // free(s);
                break;

            case 2:
                printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n",
                "ma", "ho", "dem", "ten", "ngay sinh", "thang sinh", "nam sinh", "diem TB", "hoc luc");
                for(int i = 0; i < solg; i++){
                    xuat(sv[i]);
                }
                break;

            case 3:
                timTheoMa(sv, solg);
                break;

            case 4:
                timTheoTen(sv, solg);
                break;

            case 5:
                timTheoDiem(sv, solg);
                break;
            
            case 6:  
                char ma[6];
                printf("nhap ma: ");
                scanf("%s", ma);             
                printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n",
                "ma", "ho", "dem", "ten", "ngay sinh", "thang sinh", "nam sinh", "diem TB", "hoc luc");
                xoaTheoMa(sv, &solg, ma);
                for(int i = 0; i < solg; i++){
                    xuat(sv[i]);
                }
                break;
            
            case 7:
                printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n",
                "ma", "ho", "dem", "ten", "ngay sinh", "thang sinh", "nam sinh", "diem TB", "hoc luc");
                sapXepTheoDiemGiamDan(sv, solg);
                for(int i = 0; i < solg; i++){
                    xuat(sv[i]);
                }
                break;

            case 8:
                printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n",
                "ma", "ho", "dem", "ten", "ngay sinh", "thang sinh", "nam sinh", "diem TB", "hoc luc");
                sapXepTheoTen(sv, solg);
                for(int i = 0; i < solg; i++){
                    xuat(sv[i]);
                }
                break;

            case 9: 
                ghiFILE(sv, solg);
                break;

            default :
                printf("nhap loi. vui long nhap lai !");
                break;
        }
    }
    while(luaChon);
    

    return 0;
}
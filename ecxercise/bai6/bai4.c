#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct hoten{
    char ho[10];
    char dem[20];
    char ten[10];
};
typedef struct hoten hoTen;

struct diem{
    float toan;
    float van;
    float av;
    float diemtb;
};
typedef struct diem diem;

struct sinhVien{
    char mssv[20];
    hoTen ht;
    char gioitinh[5];
    diem d;
};
typedef struct sinhVien sinhVien;

sinhVien nhap(){
    sinhVien a;

    printf("mssv : ");
    scanf("%s", a.mssv);

    printf("ho: ");
    scanf("%s", a.ht.ho);

    fflush(stdin);
    printf("dem: ");
    gets(a.ht.dem);

    printf("ten: ");
    scanf("%s", a.ht.ten);

    printf("gioi tinh: ");
    scanf("%s", a.gioitinh);

    printf("diem toan: ");
    scanf("%f",&a.d.toan);
    printf("diem van: ");
    scanf("%f",&a.d.van);
    printf("diem av: ");
    scanf("%f",&a.d.av);

    a.d.diemtb = (a.d.av + a.d.toan + a.d.van) / 3;
   
   return a;
}

void hienThi(sinhVien sv){
    printf("%-10s %-10s %-20s %-10s %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",sv.mssv,
    sv.ht.ho, sv.ht.dem, sv.ht.ten, sv.gioitinh, sv.d.toan, sv.d.van, sv.d.av, sv.d.diemtb);
}

void sapXepTen(sinhVien *sv, int solg){
    int i, j;
    for(i = 0; i < solg; i++){
        for(j = i + 1; j < solg; j++){
            if(strcmp(sv[i].ht.ten, sv[j].ht.ten) > 0){
                sinhVien a = sv[i];
                sv[i] = sv[j];
                sv[j] = a;
            }
        }
    }
}


void sapXepDiem(sinhVien *sv, int solg){
    int i, j;
    for(i = 0; i < solg; i++){
        for(j = i + 1; j < solg; j++){
            if(sv[i].d.diemtb < sv[j].d.diemtb){
                sinhVien a = sv[i];
                sv[i] = sv[j];
                sv[j] = a;
            }
        }
    }
}

void timTen(sinhVien *sv, char *s, int solg){
    int i, j = 0, dem = 0;
    int a[solg];
    
    for(i = 0; i < solg; i++){
        if(strcmp(s, sv[i].ht.ten) == 0){
            a[j++] = i;
            ++dem;
        }
    }
    if(dem == 0){
        printf("khong co sinh vien %s trong danh sach\n",s);
    }
    else{
        printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s \n","MSSV",
        "ho", "dem", "ten", "gioi tinh", "diem toan", "diem van", "diem av", "diem TB");
        for(i = 0; i < dem; i++){
            hienThi(sv[a[i]]);
        }
    }
}

void ghiFile(sinhVien *sv, int solg){
    FILE *f;
    f = fopen("C:\\Users\\nguye\\OneDrive\\Documents\\test.txt", "w"); // w mở cho phép ghi .nếu ko có tự tạo. ghi đè
    //f = fopen("C:\\Users\\nguye\\OneDrive\\Documents\\test.txt", "r"); // r mở chỉ đọc ko có trả về null
    //f = fopen("C:\\Users\\nguye\\OneDrive\\Documents\\test.txt", "a"); // a giống w nhưng ghi tiếp theo

    fprintf(f, "%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s \n","MSSV",
            "ho", "dem", "ten", "gioi tinh", "diem toan", "diem van", "diem av", "diem TB");
    for(int i = 0; i < solg; i++){
        fprintf(f, "%-10s %-10s %-20s %-10s %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",sv[i].mssv,
        sv[i].ht.ho, sv[i].ht.dem, sv[i].ht.ten, sv[i].gioitinh, sv[i].d.toan, sv[i].d.van, sv[i].d.av, sv[i].d.diemtb);
    }

    fclose(f);
}

void docfile(char *str){
    FILE *p;
    p = fopen("C:\\Users\\nguye\\OneDrive\\Documents\\test.txt", "r");

    fscanf(p, "%s", str);

    fclose(p);
}

int main(){
    sinhVien sv[100];
    int solg = 0;

    int luaChon;
    do{
        printf("==================== MENU ==================");
        printf("\n\t1. them sinh vien \n\t2. hien thi danh sach sinh vien\n\t3. sap xep theo a -> x");
        printf("\n\t4. sap xep theo diem TB giam\n\t5. tim ten sinh vien\n\t6.lui vao file\n\t7. xuat file\n\t0. thoat\n");
        printf("lua chon : ");
        scanf("%d", &luaChon);

        switch (luaChon)
        {
        case 0:
            break;

        case 1:
            int n;
            printf("so sinh vien can nhap: ");
            scanf("%d", &n);
            for(int i = solg; i < n + solg; i++){
                printf("\nsinh vien %d \n", i + 1);
                sv[i] = nhap();
            }
            solg += n;           
            break;
        
        case 2:
            printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s \n","MSSV",
            "ho", "dem", "ten", "gioi tinh", "diem toan", "diem van", "diem av", "diem TB");
            for(int i = 0; i < solg; i++){
                hienThi(sv[i]);
            }
            break;

        case 3:
            sapXepTen(sv, solg);
             printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s \n","MSSV",
            "ho", "dem", "ten", "gioi tinh", "diem toan", "diem van", "diem av", "diem TB");
            for(int i = 0; i < solg; i++){
                hienThi(sv[i]);
            }
            break;

        case 4:
            sapXepDiem(sv, solg);
              printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s \n","MSSV",
            "ho", "dem", "ten", "gioi tinh", "diem toan", "diem van", "diem av", "diem TB");
            for (int i = 0; i < solg; i++){
                hienThi(sv[i]);
            }
            break;

        case 5:
            printf("nhap ten sinh vien can tim : ");
            char s[10];
            scanf("%s", s);
            timTen(sv, s, solg);  
            break;  

        case 6:
            ghiFile(sv, solg);
            break; 

        case 7: 
            char str[2000];
            docfile(str);
            puts(str);
            break;
        
        default:
            printf("vui long nhap lai!");
            break;
        }

    }while(luaChon);

    return 0;
}
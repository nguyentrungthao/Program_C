#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#define db double


struct thong_so_bjt
{
    db beta, rc, re, r1, r2;
};

struct nguon
{
    db vcc;
};


void xuat(db vcc, db beta, db rc, db re, db r1, db r2) {
    printf("vcc = %lf\n", vcc);
    printf("beta = %lf\n", beta);
    printf("rc = %lf\n", rc);
    printf("r1 = %lf\n", r1);
    if (re > 0) {
        printf("re = %lf\n", re);
    }
    if (r2 > 0) {
        printf("r2 = %lf\n", r2);
    }
}

double yesno() {
    char s[100];
    char* p;
    fflush(stdin);
    fgets(s, 99, stdin);
    if (!isdigit(s[0])) {
        return -1;
    }
    db d = strtod(s, &p);
    return d;
}

void nhapBJT(db* vcc, db* beta, db* rc, db* re, db* r1, db* r2) {
    double ib, ic, vce, rth, uth, check;
    printf("nhap vcc : ");
    scanf("%lf", vcc);
    printf("nhap beta : ");
    scanf("%lf", beta);
    printf("nhap rc : ");
    scanf("%lf", rc);
    printf("nhap r1 : ");
    scanf("%lf", r1);
    // mạch có re  
    printf("nhap re : ");
    check = yesno();
    if (check != -1) {
        *re = check;
    }
    else {
        *re = -1;
    }
    // mạch cầu phân áp
    printf("nhap r2 : ");
    check = yesno();
    if (check != -1) {
        *r2 = check;
    }
    else {
        *r2 = -1;
    }
}

void phan_ap_khong_re(db vcc, db beta, db rc, db rb) {
    double ib, ic, vce, re, hie;
    ib = (vcc - 0.7) / rb;
    ic = beta * ib;
    if (ic > vcc / (rc + re)) {
        ic = vcc / (rc + re);
    }
    vce = vcc - ic * rc;
    re = (26 / ic) / 1000;
    hie = beta * re;
    printf("ib = %-5.10lfmA ic = %-5.10lfmA vce = = %-5.10lfV\n", ib, ic, vce);
    printf("re = %-5.10lfKOhm hie = %-5.10lfKOhm\n", re, hie);
}

void phan_ap_co_re(db vcc, db beta, db rc, db re, db rb) {
    double ib, ic, vce, hie;
    ib = (vcc - 0.7) / (rb + (beta + 1) * re);
    ic = beta * ib;
    if (ic > vcc / (rc + re)) {
        ic = vcc / (rc + re);
    }
    vce = vcc - ic * (rc + re);
    re = (26 / ic) / 1000;
    hie = beta * re;
    printf("ib = %-5.10lfmA ic = %-5.10lfmA vce = = %-5.10lfV\n", ib, ic, vce);
    printf("re = %-5.10lfKOhm hie = %-5.10lfKOhm\n", re, hie);
}

void phan_ap_cau_phan_ap(db vcc, db beta, db rc, db re, db r1, db r2) {
    double ib, ic, vce, rth, uth, hie;
    rth = (r1 * r2) / (r1 + r2);
    uth = (vcc * r2) / (r1 + r2);
    ib = (uth - 0.7) / (rth + (beta + 1) * re);
    ic = beta * ib;
    if (ic > vcc / (rc + re)) {
        ic = vcc / (rc + re);
    }
    vce = vcc - ic * (rc + re);

    re = (26 / ic) / 1000;
    hie = beta * re;
    printf("rth = %-5.10lf uth = %-5.10lf ib = %-5.10lf ic = %-5.10lf vce = = %-5.10lf\n",
        rth, uth, ib, ic, vce);
    printf("re = %-5.10lfKOhm hie = %-5.10lfKOhm\n", re, hie);
}


int main() {
    db vcc, beta, rc, re, r1, r2;
    while (1) {
        printf("  \n\t\t NHAP THONG SO\n");
        nhapBJT(&vcc, &beta, &rc, &re, &r1, &r2);
        xuat(vcc, beta, rc, re, r1, r2);
        printf("\n\t\tTINH TOAN\n");
        if (r2 < 0) {
            if (re < 0) {
                phan_ap_khong_re(vcc, beta, rc, r1);
            }
            else {
                phan_ap_co_re(vcc, beta, rc, re, r1);
            }
        }
        else {
            phan_ap_cau_phan_ap(vcc, beta, rc, re, r1, r2);
        }
        printf("\n\n\n\t\t----------------------------------------------");
    }


    getch();
    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#define db double

void xuat(db vcc, db beta, db rc, db re, db r1, db r2) {
    printf("vcc = %lf\n", vcc);
    printf("beta = %lf\n", beta);
    printf("rc = %lf\n", rc);
    printf("r1 = %lf\n", r1);
    if (re > 0) {
        printf("re = %lf\n", re);
    }
    if (r2 > 0) {
        printf("r2 = %lf\n", r2);
    }
}

double yesno() {
    char s[100];
    char* p;
    fflush(stdin);
    fgets(s, 99, stdin);
    if (!isdigit(s[0])) {
        return -1;
    }
    db d = strtod(s, &p);
    return d;
}

int nhapBJT(db* vcc, db* beta, db* rc, db* re, db* r1, db* r2, db* rl) {
    double ib, ic, vce, rth, uth, check;
    printf("nhap vcc : ");
    check = yesno();
    if (check != -1.0) {
        *vcc = check;
    }
    else {
        return 0;
    }
    printf("nhap beta : ");
    scanf("%lf", beta);
    printf("nhap rc : ");
    scanf("%lf", rc);
    printf("nhap r1 : ");
    scanf("%lf", r1);
    // mạch cóe  
    printf("nhap re : ");
    check = yesno();
    if (check != -1.0) {
        *re = check;
    }
    else {
        *re = -1.0;
    }
    // mạch cầu phân áp
    printf("nhap r2 : ");
    check = yesno();
    if (check != -1.0) {
        *r2 = check;
    }
    else {
        *r2 = -1.0;
    }
    printf("nhap rl: ");
    check = yesno();
    if (check != -1.0) {
        *rl = check;
    }
    else {
        *rl = -1.0;
    }
    return 1;
}

void phan_ap_khong_re(db vcc, db beta, db rc, db rb, db *icq, db *vce, db *hie, db *r) {
    double ib;
    ib = (vcc - 0.7) / rb;
    *icq = beta * ib;
    if (*icq > vcc / rc) {
        *icq = vcc / rc;
    }
    *vce = vcc - (*icq) * rc;
    *r = (26 / ib) / 1000;
    *hie = beta * (*r);
    printf("ib = %-5.10lfmA ic = %-5.10lfmA vce = %-5.10lfV\n", ib, *icq, *vce);
    printf("re = %-5.10lfKOhm hie = %-5.10lfKOhm\n", *r, hie);
}

void phan_ap_co_re(db vcc, db beta, db rc, db re, db rb, db *icq, db *vce, db *hie, db *r) {
    double ib;
    ib = (vcc - 0.7) / (rb + (beta + 1) * re);
    *icq = beta * ib;
    if (*icq > vcc / (rc + re)) {
        *icq = vcc / (rc + re);
    }
    *vce = vcc - (*icq) * (rc + re);
    *r = (26 / ib) / 1000;
    *hie = beta * (*r);
    printf("ib = %-5.10lfmA ic = %-5.10lfmA vce = %-5.10lfV\n", ib, *icq, *vce);
    printf("re = %-5.10lfKOhm hie = %-5.10lfKOhm\n", *r, *hie);
}

void phan_ap_cau_phan_ap(db vcc, db beta, db rc, db re, db r1, db r2, db *icq, db *vce, db *hie, db *r) {
    double ib, rth, uth;
    rth = (r1 * r2) / (r1 + r2);
    uth = (vcc * r2) / (r1 + r2);
    ib = (uth - 0.7) / (rth + (beta + 1) * re);
    *icq = beta * ib;
    if (*icq > vcc / (rc + re)) {
        *icq = vcc / (rc + re);
    }
    *vce = vcc - (*icq) * (rc + re);

    *r = (26 / ib) / 1000;
    *hie = beta * (*r);
    printf("rth = %-5.10lf uth = %-5.10lf ib = %-5.10lf ic = %-5.10lf vce = = %-5.10lf\n",
        rth, uth, ib, *icq, *vce);
    printf("re = %-5.10lfKOhm hie = %-5.10lfKOhm\n", *r, *hie);
}

void DCLL(db vcc, db rc, db re) {
    if (re < 0) {
        printf("Ic = -%lfVCE + %lf\n", 1 / rc, vcc / rc);
    }
    else {
        printf("Ic = -%lfVCE + %lf\n", 1 / (rc + re), vcc / (rc + re));
    }
}

db RAC(db rc, db rl) {
    if (rl < 0) {
        return rc;
    }
    return (rc * rl) / (rc + rl);
}

void ACLL(db icp, db vce, db rc, db rl) {
    db rac = RAC(rc, rl);
    printf("Ict = -%lfVCET + %lf\n", 1 / rac, vce / rac + icp);
}

void Zi(db r1, db r2, db hie) {
    if (r2 < 0) {
        printf("Zi = %lfKohm\n", RAC(r1, hie));
    }
    else {
        printf("ZI = %lfKohm\n", 1 / (1 / r1 + 1 / r2 + 1 / hie));
    }
}

void Av(db rc, db rl, db r, db re, db check) {
    if (check == -1.0) {
        printf("AV = -%lf\n", RAC(rc, rl) / r);
    }
    else {
        printf("AV = -%lf\n", RAC(rc, rl) / (r + re));
    }
}

void menu() {
    int luachon;
    while (1) {
        printf("\t\t1.0 zener\n");
        printf("\t\t2.0 BJT\n");
        printf("lua chon: ");
        scanf("%d", luachon);
        if (luachon == 1) {

        }
        else if (luachon == 2) {
            db vcc, beta, rc, re, r1, r2, rl, ice, vce, hie, r, check;
            while (1) {
                printf("  \n\t\t NHAP THONG SO\n");
                check = nhapBJT(&vcc, &beta, &rc, &re, &r1, &r2, &rl);
                if (check == 0) {
                    break;
                }
                else {
                    printf("CE? Yes = enter");
                    check = yesno();
                    // xuat(vcc, beta, rc, re, r1, r2);
                    printf("\n\t\tTINH TOAN\n");
                    if (r2 < 0) {
                        if (re < 0) {
                            phan_ap_khong_re(vcc, beta, rc, r1, &ice,&vce,&hie,&r);
                        }
                        else {
                            phan_ap_co_re(vcc, beta, rc, re, r1, &ice,&vce,&hie,&r);
                        }
                    }
                    else {
                        phan_ap_cau_phan_ap(vcc, beta, rc, re, r1, r2, &ice,&vce,&hie,&r);
                    }

                    DCLL(vcc, rc, re);
                    ACLL(ice, vce, rc, rl);
                    Zi(r1, r2, hie);
                    Av(rc, rl, r, re, check);
                    printf("\n\n\n\t\t----------------------------------------------");
                }
            }
        }
    }
}

int main() {

    // menu();
    db vcc, beta, rc, re, r1, r2, rl, ice, vce, hie, r, check;
    while (1) {
        printf("  \n\t\t NHAP THONG SO\n");
        check = nhapBJT(&vcc, &beta, &rc, &re, &r1, &r2, &rl);
        if (check == 0) {
            break;
        }
        else {
            printf("CE? Yes = enter: ");
            check = yesno();
            // xuat(vcc, beta, rc, re, r1, r2);
            printf("\n\t\tTINH TOAN\n");
            if (r2 < 0) {
                if (re < 0) {
                    phan_ap_khong_re(vcc, beta, rc, r1, &ice, &vce, &hie, &r);
                }
                else {
                    phan_ap_co_re(vcc, beta, rc, re, r1, &ice, &vce, &hie, &r);
                }
            }
            else {
                phan_ap_cau_phan_ap(vcc, beta, rc, re, r1, r2, &ice, &vce, &hie, &r);
            }

            DCLL(vcc, rc, re);
            ACLL(ice, vce, rc, rl);
            Zi(r1, r2, hie);
            Av(rc, rl, r, re, check);
            printf("\n\n\n\t\t----------------------------------------------");
        }
    }

    getch();
    return 0;
}

*/

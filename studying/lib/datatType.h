#ifndef data_type
#define data_type

#include <stdio.h>
#include <stdbool.h>

#define hello 100

extern int a;

struct hocSinh {
    // char hoTen[30] = "helelo";
    int tuoi = 0;
    bool gioiTinh; // nam 1 nu 0;
};

typedef struct hocSinh hocsinh;


#endif
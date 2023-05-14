#include <stdio.h>
#include <math.h>
#define pi 3.14

float Min(float r, float g, float b) {
    float min;
    if (r > g) {
        min = g;
    }
    else {
        min = r;
    }
    if (min > b) min = b;
    return min;
}

float Max(float r, float g, float b) {
    float max;
    if (r < g) {
        max = g;
    }
    else {
        max = r;
    }
    if (max < b) max = b;
    return max;
}

void gray(float r, float g, float b) {
    printf("\t\t GRAY\n");
    printf("trung binh: %f\n", (r + g + b) / 3);
    printf("lightness: %f\n", (Min(r, g, b) + Max(r, g, b)) / 2);
    printf("lumina: %f\n", 0.2126 * r + 0.7152 * g + 0.0722 * b);
}

void cmyk(float r, float g, float b) {
    printf("\t\t CMYK( r, g, b)\n");
    printf("cyan 0 %0.0f %0.0f\n", g, b);
    printf("magenta %0.0f 0 %0.0f\n", r, b);
    printf("yellow %0.0f %0.0f 0\n", r, g);
    printf("balck %0.0f\n", Min(r, g, b));
}

void hsi(float r, float g, float b) {
    float tu, mau, theta, h, s, i;
    tu = (2 * r - g - b) / 2.0;
    mau = sqrt((r - g) * (r - g) + (r - b) * (g - b));
    theta = acos(tu / mau);
    if (b <= g)
        h = theta * 180 / pi;
    else
        h = 360 - theta * 180 / pi;

    s = 255 * (1 - 3 * Min(r, g, b) / (r + g + b));
    i = (r + g + b) / 3.0;
    printf("\t\t HSI( r, g, b\n");
    printf("hue %0f\n", h);
    printf("sataturation %0f\n", s);
    printf("intensity %0f\n", i);
    printf("HSI %0f %0f %0f\n", h, s / 255, i);
}

void hsv(float r, float g, float b) {
    float tu, mau, theta, h, s, v;
    tu = (2 * r - g - b) / 2.0;
    mau = sqrt((r - g) * (r - g) + (r - b) * (g - b));
    theta = acos(tu / mau);
    if (b <= g)
        h = theta * 180 / 3.14;
    else
        h = 360 - theta * 180 / 3.14;

    s = 255 * (1 - 3 * Min(r, g, b) / (r + g + b));
    v = Max(r, g, b);
    printf("\t\t HSV( r, g, b\n");
    printf("hue %0f\n", h);
    printf("sataturation %0f\n", s);
    printf("V %0f\n", v);
    printf("HSV %0f %0f %0f\n", h, s / 255, v);
}

void XYZ(float r, float g, float b) {
    float x, y, z;
    x = 0.4124564 * r + 0.3575761 * g + 0.1804375 * b;
    y = 0.2126729 * r + 0.7151522 * g + 0.0721750 * b;
    z = 0.0193339 * r + 0.1191920 * g + 0.9503041 * b;
    printf("\t\t XYZ r, g, b\n");
    printf("x,y,z %f %f %f\n", x, y, z);
}

void ycrcb(float r, float g, float b) {
    float Y, Cr, Cb;
    Y = 16 + (65.738 * r + 129.057 * g + 25.064 * b) / 256;
    Cr = 128 + (112.439 * r - 94.154 * g - 18.285 * b) / 256;
    Cb = 128 - (37.945 * r + 74.494 * g - 112.439 * b) / 256;
    printf("\t\t XYZ r, g, b\n");
    printf("y, cr, cb %f %f %f\n", Y, Cr, Cb);
}


int main() {
    float r, g, b;
    while (1) {
        printf("\n\n\n\n");
        scanf("%f%f%f", &r, &g, &b);
        gray(r, g, b);
        cmyk(r, g, b);
        hsi(r, g, b);
        hsv(r, g, b);
        XYZ(r, g, b);
        ycrcb(r, g, b);
    }
    
    return 0;
}
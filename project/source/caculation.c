#include "..\headers\caculation.h"

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

void factorial(unsigned long long int *a){
    a[0] = 1;
    for (int i = 1; i < 21; i++){
        a[i] = a[i - 1] * (i + 1);
    }
}
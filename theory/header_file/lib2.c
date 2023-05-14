#ifndef lib2
#define lib2

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define print(x) printf("%d", (x))

struct kieu {
    bool flag = true;
    int a = 0;
};

extern int c;

int add(int a, int b) {
    return a + b;
}

#endif
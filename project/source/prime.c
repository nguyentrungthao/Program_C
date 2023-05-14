#include "..\headers\prime.h"
#include <stdbool.h>

void Eratosthenes(bool *a, int n)
{
    a[0] = 0;
    a[1] = 0;
    int i;
    for (i = 2; i <= n; i++){
        a[i] = 1;
    }

    for (i = 2; i <= n; i++){
        if(a[i] == true){
            for (int j = 2 * i; j <= n; j += i){
                a[j] = 0;
            }
        }
    }
}

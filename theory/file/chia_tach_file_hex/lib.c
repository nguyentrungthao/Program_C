#include "lib.h"
#include <math.h>

bool prime(int n){
    if(n < 2){
        return 0;
    }
    else{
        for (int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                return 0;
            }
        }
        return 1;
    }
}

bool superprime(int n){
    while(n > 0){
        if(!prime(n % 10)){
            return 0;
        }
        n /= 10;
    }
}
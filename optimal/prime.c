#include <stdio.h>

// Liệt kê các số nguyên tố nhỏ hơn N
void sieve_of_eratosthences(int n) { //2 3 4 5 6 7 8 9 10
    int flap[n + 1];
    int i;
    for (i = 2; i <= n; ++i) {// gán cờ từ 2 đến 10 bằng true ; khi cờ bằng 1 in i ra
        flap[i] = 1;
    }
    for (i = 2; i * i <= n; ++i) {
        if (flap[i]) {
            for (int j = i * i; j < n; j += i) {
                flap[j] = 0;
            }
        }
    }
}

// kiểm tra só nguyên tố
int check_prime(int n) {
    for (int i = 0; i * i <= n; ++i) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {


    return 0;
}
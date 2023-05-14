#include <stdio.h>

long long int exponential(int n) {
    long long int ex = 1;
    while (n != 1) {
        ex *= n--;
    }
    return ex;
}

int main() {
    int n = 5, k = 2;
    // do {
    // scanf("%d%d", &n, &k);
    // } while (k < 0 || k > n || n > 25);

    printf("%lld\n", exponential(n) / (exponential(k) * exponential(n - k)));

    return 0;
}
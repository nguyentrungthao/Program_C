#include <stdio.h>
#include <math.h>

char square(int n) {
    int a = sqrt(n);
    if (a * a == n)
        return 1;
    return 0;
}

int sumOfDivisor(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i + n / i; // tối ưu hơn 
        }
    }
    if (square(n))
        sum += sqrt(n);
    return sum;
}
int main() {
    int t;
    do {
        scanf("%d", &t);
    } while (t < 0 || t  > 1000);

    while (t--) {
        int n;
        do {
            scanf("%d", &n);
        } while (n < 0 || n > 1000000);

        printf("%d\n", sumOfDivisor(n));
    }
    return 0;
}
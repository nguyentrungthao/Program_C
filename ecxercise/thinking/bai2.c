/*
    Cho một số nguyên dương N.
    Ta liệt kê ra các ước số của số N theo thứ tự tăng dần và đưa ra ước số lớn thứ k.
    Đưa ra -1 nếu như số N có ít hơn k ước.

    https://www.facebook.com/groups/laptrinh.IT/posts/4704594639559124/
*/
#include <stdio.h>

int main() {
    int n = 100;
    for (int i = n / 2 + 1; i < n; ++i) {
        if (n % i == 0)
            printf("%-5d", i);
    }

    return 0;
}
/*
    Cho một dãy số a gồm N số, các số chỉ gồm số 0 hoặc số 1.
    Bạn được xóa duy nhất 1 số bất kì.
    Hỏi cần chọn số nào để xóa để sau khi xóa, bạn được một dãy gồm các số 1 liên tục dài nhất.
    Trả về độ dài của dãy số 1 liên tục đó.

    https://www.facebook.com/groups/laptrinh.IT/posts/4706738826011372/
*/

#include <stdio.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

int nhapN() {
    int n;
    scanf("%d", &n);
    return n;
}

void nhapMang(int* a, int const n) {
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
}
int main() {
    int const n = nhapN();
    int a[n];
    nhapMang(a, n);
    int cntZero = 0, l = 0, ans = 0; 
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cntZero++;
        }
        while (cntZero > 1) {
            if (a[l] == 0) {
                cntZero--;
            }
            l++;
        }
        ans = max(ans, i - l);
    }

    return 0;
}

// int main() {
//     int const n = nhapN();
//     int a[n];
//     int i = 0, count, flag, max = 0;
//     nhapMang(a, n);
//     while (i < n) {
//         flag = 0;
//         count = 0;
//         while (a[i] == 0) {
//             ++i;
//         }
//         for (; i < n; ++i) {
//             if (a[i] == 1) {
//                 ++count;
//             }
//             else if (a[i] == 0) {
//                 ++flag;
//             }
//             if (flag > 1) {
//                 break;
//             }
//         }
//         if (max < count) {
//             max = count;
//         }
//         ++i;
//     }
//     printf("%d\n", max);

//     return 0;
// }

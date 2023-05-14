#include <stdio.h>
#include <time.h>

int main() {
    clock_t begin, end;
    begin = clock();


    end = clock();

    double time_run = (double)(begin - end) / CLOCKS_PER_SEC;
    return 0;
}
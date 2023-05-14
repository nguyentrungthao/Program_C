#include <iostream>

struct kieu {
    bool flag = true;
    int a = 1234554312;
};

int main() {

    kieu x;
    std::cout << x.a << " " << x.flag << std::endl;

    return 0;
}
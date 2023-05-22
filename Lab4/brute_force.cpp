#include <iostream>


int multiply(int x, int y) {
    int length = 32 - __builtin_clz(std::max(x, y));
    if (length <= 32) {
        return x * y;
    }
    int half = (length + 1) / 2;
    int a = x >> half;
    int b = x & ((1 << half) - 1);
    int c = y >> half;
    int d = y & ((1 << half) - 1);

    int ac = multiply(a, c);
    int bd = multiply(b, d);
    int abcd = multiply(a + b, c + d);
    return (ac << (half * 2)) + ((abcd - ac - bd) << half) + bd;
}


int main() {
    int x, y;
    std::cout << "Enter two integers to be multiplied: ";
    std::cin >> x >> y;
    std::cout << "The result of the multiplication is: " << multiply(x, y) << std::endl;
    return 0;
}
#include "complex.h"

int main() {
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex c3 = c1 + c2;
    Complex c4 = c1 * c2;
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << c3 << std::endl;
    std::cout << "c1 * c2: " << c4 << std::endl;
    return 0;
}
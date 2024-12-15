#include "Fraction.h"
#include "Vector.h"
#include <iostream>

int main() {
    // Testing Fraction
    Fraction f1(1, 2), f2(3, 4);
    std::cout << "Fraction 1: " << f1 << "\n";
    std::cout << "Fraction 2: " << f2 << "\n";
    std::cout << "Sum: " << f1 + f2 << "\n";

    // Testing Vector
    Vector v1{1.0, 2.0, 3.0}, v2{4.0, 5.0, 6.0};
    std::cout << "Vector 1: " << v1 << "\n";
    std::cout << "Vector 2: " << v2 << "\n";
    std::cout << "Dot Product: " << v1 * v2 << "\n";

    return 0;
}

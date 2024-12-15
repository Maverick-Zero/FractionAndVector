#include "Fraction.h"

std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& frac) {
    char slash;
    is >> frac.numerator >> slash >> frac.denominator;
    if (frac.denominator == 0) throw std::invalid_argument("Denominator cannot be zero.");
    frac.simplify();
    return is;
}

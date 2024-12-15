#include "Fraction.h"
#include <cmath> // For abs

int Fraction::gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::simplify() {
    int gcd_value = gcd(numerator, denominator);
    numerator /= gcd_value;
    denominator /= gcd_value;
    if (denominator < 0) { // Keep denominator positive
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denom == 0) throw std::invalid_argument("Denominator cannot be zero.");
    simplify();
}

int Fraction::getNumerator() const { return numerator; }
int Fraction::getDenominator() const { return denominator; }

void Fraction::setNumerator(int num) { numerator = num; simplify(); }
void Fraction::setDenominator(int denom) {
    if (denom == 0) throw std::invalid_argument("Denominator cannot be zero.");
    denominator = denom;
    simplify();
}

Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(numerator * other.denominator + other.numerator * denominator,
                    denominator * other.denominator);
}

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

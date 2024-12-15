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

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(numerator * other.denominator - other.numerator * denominator,
                    denominator * other.denominator);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) throw std::invalid_argument("Division by zero.");
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

Fraction& Fraction::operator+=(const Fraction& other) {
    *this = *this + other;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other) {
    *this = *this - other;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
    *this = *this * other;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other) {
    *this = *this / other;
    return *this;
}


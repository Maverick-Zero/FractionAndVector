#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b); // Custom GCD function
    void simplify();

public:
    Fraction();
    Fraction(int num, int denom);

    int getNumerator() const;
    int getDenominator() const;

    void setNumerator(int num);
    void setDenominator(int denom);

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
    friend std::istream& operator>>(std::istream& is, Fraction& frac);

    double toDouble() const;
};
#endif

#include <iostream>
#include <vector>
#include <numeric> // For std::gcd in C++17
#include <initializer_list>

// Fraction Class
class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) { // Keep denominator positive
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructors
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denom == 0) throw std::invalid_argument("Denominator cannot be zero.");
        simplify();
    }

    // Getters and Setters
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    void setNumerator(int num) { numerator = num; simplify(); }
    void setDenominator(int denom) {
        if (denom == 0) throw std::invalid_argument("Denominator cannot be zero.");
        denominator = denom; simplify();
    }

    // Overloaded Operators
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) throw std::invalid_argument("Division by zero.");
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    Fraction& operator+=(const Fraction& other) {
        *this = *this + other;
        return *this;
    }

    Fraction& operator-=(const Fraction& other) {
        *this = *this - other;
        return *this;
    }

    Fraction& operator*=(const Fraction& other) {
        *this = *this * other;
        return *this;
    }

    Fraction& operator/=(const Fraction& other) {
        *this = *this / other;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Fraction& frac) {
        char slash;
        is >> frac.numerator >> slash >> frac.denominator;
        if (frac.denominator == 0) throw std::invalid_argument("Denominator cannot be zero.");
        frac.simplify();
        return is;
    }

    double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }
};

// Vector Class
class Vector {
private:
    std::vector<double> components;

public:
    // Constructors
    Vector() = default;
    Vector(std::initializer_list<double> values) : components(values) {}

    // Getters and Setters
    double getComponent(size_t index) const {
        if (index >= components.size()) throw std::out_of_range("Index out of range.");
        return components[index];
    }

    void setComponent(size_t index, double value) {
        if (index >= components.size()) throw std::out_of_range("Index out of range.");
        components[index] = value;
    }

    size_t size() const { return components.size(); }

    // Overloaded Operators
    Vector operator+(const Vector& other) const {
        if (components.size() != other.components.size()) throw std::invalid_argument("Vector sizes must match.");
        Vector result;
        for (size_t i = 0; i < components.size(); ++i) {
            result.components.push_back(components[i] + other.components[i]);
        }
        return result;
    }

    Vector operator-(const Vector& other) const {
        if (components.size() != other.components.size()) throw std::invalid_argument("Vector sizes must match.");
        Vector result;
        for (size_t i = 0; i < components.size(); ++i) {
            result.components.push_back(components[i] - other.components[i]);
        }
        return result;
    }

    Vector& operator+=(const Vector& other) {
        *this = *this + other;
        return *this;
    }

    Vector& operator-=(const Vector& other) {
        *this = *this - other;
        return *this;
    }

    Vector operator*(double scalar) const {
        Vector result;
        for (double component : components) {
            result.components.push_back(component * scalar);
        }
        return result;
    }

    double operator*(const Vector& other) const { // Scalar product
        if (components.size() != other.components.size()) throw std::invalid_argument("Vector sizes must match.");
        double result = 0;
        for (size_t i = 0; i < components.size(); ++i) {
            result += components[i] * other.components[i];
        }
        return result;
    }

    friend Vector operator*(double scalar, const Vector& vec) {
        return vec * scalar;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        os << "(";
        for (size_t i = 0; i < vec.components.size(); ++i) {
            os << vec.components[i];
            if (i < vec.components.size() - 1) os << ", ";
        }
        os << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector& vec) {
        size_t size;
        is >> size;
        vec.components.resize(size);
        for (size_t i = 0; i < size; ++i) {
            is >> vec.components[i];
        }
        return is;
    }
};

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

#include "Vector.h"

Vector::Vector() = default;

Vector::Vector(std::initializer_list<double> values) : components(values) {}

double Vector::getComponent(size_t index) const {
    if (index >= components.size()) throw std::out_of_range("Index out of range.");
    return components[index];
}

void Vector::setComponent(size_t index, double value) {
    if (index >= components.size()) throw std::out_of_range("Index out of range.");
    components[index] = value;
}

size_t Vector::size() const { return components.size(); }

Vector Vector::operator+(const Vector& other) const {
    if (components.size() != other.components.size()) throw std::invalid_argument("Vector sizes must match.");
    Vector result;
    for (size_t i = 0; i < components.size(); ++i) {
        result.components.push_back(components[i] + other.components[i]);
    }
    return result;
}

Vector Vector::operator-(const Vector& other) const {
    if (components.size() != other.components.size()) throw std::invalid_argument("Vector sizes must match.");
    Vector result;
    for (size_t i = 0; i < components.size(); ++i) {
        result.components.push_back(components[i] - other.components[i]);
    }
    return result;
}

Vector& Vector::operator+=(const Vector& other) {
    *this = *this + other;
    return *this;
}

Vector& Vector::operator-=(const Vector& other) {
    *this = *this - other;
    return *this;
}

Vector Vector::operator*(double scalar) const {
    Vector result;
    for (double component : components) {
        result.components.push_back(component * scalar);
    }
    return result;
}

double Vector::operator*(const Vector& other) const {
    if (components.size() != other.components.size()) throw std::invalid_argument("Vector sizes must match.");
    double result = 0;
    for (size_t i = 0; i < components.size(); ++i) {
        result += components[i] * other.components[i];
    }
    return result;
}

Vector operator*(double scalar, const Vector& vec) {
    return vec * scalar;
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "(";
    for (size_t i = 0; i < vec.components.size(); ++i) {
        os << vec.components[i];
        if (i < vec.components.size() - 1) os << ", ";
    }
    os << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector& vec) {
    size_t size;
    is >> size;
    vec.components.resize(size);
    for (size_t i = 0; i < size; ++i) {
        is >> vec.components[i];
    }
    return is;
}

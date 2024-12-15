#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <vector>
#include <stdexcept>

class Vector {
private:
    std::vector<double> components;

public:
    Vector();
    Vector(std::initializer_list<double> values);

    double getComponent(size_t index) const;
    void setComponent(size_t index, double value);

    size_t size() const;

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);

    Vector operator*(double scalar) const;
    double operator*(const Vector& other) const;

    friend Vector operator*(double scalar, const Vector& vec);
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    friend std::istream& operator>>(std::istream& is, Vector& vec);
};
#endif

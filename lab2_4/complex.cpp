#include "complex.h"

Complex::Complex(double r, double i) : real(r), imag(i) {}
Complex::Complex(const Complex& other) : real(other.real), imag(other.imag) {}
Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        real = other.real;
        imag = other.imag;
    }
    return *this;
}
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}
Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}
Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
}
Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    return Complex((real * other.real + imag * other.imag) / denominator, (imag * other.real - real * other.imag) / denominator);
}
Complex Complex::operator-() const {
    return Complex(-real, -imag);
}
Complex& Complex::operator--() {
    real--;
    imag--;
    return *this;
}
Complex Complex::operator--(int) {
    Complex temp(*this);
    real--;
    imag--;
    return temp;
}
Complex& Complex::operator++() {
    real++;
    imag++;
    return *this;
}
Complex Complex::operator++(int) {
    Complex temp(*this);
    real++;
    imag++;
    return temp;
}
bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}
bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}
bool Complex::operator<(const Complex& other) const {
    return real < other.real || (real == other.real && imag < other.imag);
}
bool Complex::operator>(const Complex& other) const {
    return real > other.real || (real == other.real && imag > other.imag);
}
bool Complex::operator<=(const Complex& other) const {
    return !(*this > other);
}
bool Complex::operator>=(const Complex& other) const {
    return !(*this < other);
}
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag) << "i";
    return os;
}
std::istream& operator>>(std::istream& is, Complex& c) {
    char sign, i;
    is >> c.real >> sign >> c.imag >> i;
    if (sign == '-') {
        c.imag = -c.imag;
    }
    return is;
}
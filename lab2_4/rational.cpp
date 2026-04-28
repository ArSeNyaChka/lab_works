#include "rational.h"
#include <stdexcept>
#include <numeric>

Rational::Rational(int num, int den) : numerator(num), denominator(den) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

Rational::Rational(const Rational& other) : numerator(other.numerator), denominator(other.denominator) {}

Rational& Rational::operator=(const Rational& other) {
    if (this != &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}

Rational Rational::operator+(const Rational& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int den = denominator * other.denominator;
    return Rational(num, den);
}

Rational Rational::operator-(const Rational& other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int den = denominator * other.denominator;
    return Rational(num, den);
}

Rational Rational::operator*(const Rational& other) const {
    int num = numerator * other.numerator;
    int den = denominator * other.denominator;
    return Rational(num, den);
}

Rational Rational::operator/(const Rational& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    int num = numerator * other.denominator;
    int den = denominator * other.numerator;
    return Rational(num, den);
}

Rational Rational::operator-() const {
    return Rational(-numerator, denominator);
}

Rational& Rational::operator--() {
    numerator -= denominator;
    return *this;
}

Rational Rational::operator--(int) {
    Rational temp(*this);
    numerator -= denominator;
    return temp;
}

Rational& Rational::operator++() {
    numerator += denominator;
    return *this;
}

Rational Rational::operator++(int) {
    Rational temp(*this);
    numerator += denominator;
    return temp;
}

Rational& Rational::operator+=(const Rational& other) {
    *this = *this + other;
    return *this;
}

Rational& Rational::operator-=(const Rational& other) {
    *this = *this - other;
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    *this = *this * other;
    return *this;
}

Rational& Rational::operator/=(const Rational& other) {
    *this = *this / other;
    return *this;
}

bool Rational::operator==(const Rational& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

bool Rational::operator!=(const Rational& other) const {
    return !(*this == other);
}

bool Rational::operator<(const Rational& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Rational::operator>(const Rational& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}

bool Rational::operator<=(const Rational& other) const {
    return !(*this > other);
}

bool Rational::operator>=(const Rational& other) const {
    return !(*this < other);
}

Rational Rational::operator+(const int& other) const {
    return *this + Rational(other);
}

Rational Rational::operator-(const int& other) const {
    return *this - Rational(other);
}

Rational Rational::operator*(const int& other) const {
    return *this * Rational(other);
}

Rational Rational::operator/(const int& other) const {
    if (other == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    return *this / Rational(other);
}

Rational& Rational::operator+=(const int& other) {
    *this = *this + Rational(other);
    return *this;
}

Rational& Rational::operator-=(const int& other) {
    *this = *this - Rational(other);
    return *this;
}

Rational& Rational::operator*=(const int& other) {
    *this = *this * Rational(other);
    return *this;
}

Rational& Rational::operator/=(const int& other) {
    *this = *this / Rational(other);
    return *this;
}

bool Rational::operator==(const int& other) const {
    return *this == Rational(other);
}

bool Rational::operator!=(const int& other) const {
    return !(*this == Rational(other));
}

bool Rational::operator<(const int& other) const {
    return *this < Rational(other);
}

bool Rational::operator>(const int& other) const {
    return *this > Rational(other);
}

bool Rational::operator<=(const int& other) const {
    return !(*this > Rational(other));
}

bool Rational::operator>=(const int& other) const {
    return !(*this < Rational(other));
}

std::ostream& Rational::operator<<(std::ostream& os) const {
    os << numerator << "/" << denominator;
    return os;
}

std::istream& Rational::operator>>(std::istream& is) {
    char slash;
    is >> numerator >> slash >> denominator;
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    return is;
}

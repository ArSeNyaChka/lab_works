#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational {
private:
    int numerator;
    int denominator;
public:
    Rational(int num = 0, int den = 1);
    Rational(const Rational& other);

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    Rational& operator=(const Rational& other);
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;
    Rational operator-() const; // unary minus
    Rational& operator--(); // prefix decrement
    Rational operator--(int); // postfix decrement
    Rational& operator++(); // prefix increment
    Rational operator++(int); // postfix increment
    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);
    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator<(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>=(const Rational& other) const;

    Rational operator+(const int& other) const;
    Rational operator-(const int& other) const;
    Rational operator*(const int& other) const;
    Rational operator/(const int& other) const;
    Rational& operator+=(const int& other);
    Rational& operator-=(const int& other);
    Rational& operator*=(const int& other);
    Rational& operator/=(const int& other);
    bool operator==(const int& other) const;
    bool operator!=(const int& other) const;
    bool operator<(const int& other) const;
    bool operator>(const int& other) const;
    bool operator<=(const int& other) const;
    bool operator>=(const int& other) const;

    std::ostream& operator<<(std::ostream& os) const;
    std::istream& operator>>(std::istream& is);
};

#endif // RATIONAL_H
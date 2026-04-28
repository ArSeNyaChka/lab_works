#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0, double i = 0);
    Complex(const Complex& other);

    double getReal() const { return real; }
    double getImag() const { return imag; }

    Complex& operator=(const Complex& other);
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    Complex operator-() const; // unary minus
    Complex& operator--(); // prefix decrement
    Complex operator--(int); // postfix decrement
    Complex& operator++(); // prefix increment
    Complex operator++(int); // postfix increment
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator>(const Complex& other) const;
    bool operator<=(const Complex& other) const;
    bool operator>=(const Complex& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

#endif // COMPLEX_H
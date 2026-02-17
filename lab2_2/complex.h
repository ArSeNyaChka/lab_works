#ifndef ComplexLib
#define ComplexLib

#include <cmath>
#include <iostream>


class Complex {
private:
  double m_re{};
  double m_im{};

public:
  Complex() {}
  Complex(double re, double im) : m_re(re), m_im(im) {}
  Complex(const Complex &z) : m_re(z.m_re), m_im(z.m_im) {}
  double re() {return m_re;}
  void re(double x) {m_re = x;}
  double im() {return m_im;}
  void im(double y) {m_im = y;}
  double abs() {return std::sqrt(m_re*m_re + m_im*m_im);}
  double arg() {return ((m_im > 0) - (m_im < 0)) * std::acos(m_re / abs());}
  void print() {std::cout << m_re << " + " << m_im << "i";}
  void trigPrint() {std::cout << abs() << "(cos(" << arg() << ") + i*sin(" << arg() << "))";}
  void expPrint() {std::cout << abs() << "*e^(" << arg() << "i)";}
  Complex add(const Complex &z) {return {m_re + z.m_re, m_im + z.m_im};}
  Complex sub(const Complex &z) {return {m_re - z.m_re, m_im - z.m_im};}
  Complex mult(const Complex &z) {return {m_re * z.m_re - m_im * z.m_im, m_re * z.m_im + m_im * z.m_re};}  // (a + ib)(x + iy) = ax + iay + ibx - by = (ax - by) + i(ay + bx)
  Complex div(const Complex &z) {return {(m_re * z.m_re + m_im * z.m_im)/(z.m_re*z.m_re + z.m_im*z.m_im), (-(m_re * z.m_im) + m_im * z.m_re)/(z.m_re*z.m_re + z.m_im*z.m_im)};}  // (a + ib)/(x + iy) = (a + ib)(x - iy)/(x^2 + y^2) = ((ax + by) + i(-ay + bx))/(x^2 + y^2) = (ax + by)/(x^2 + y^2) + i((-ay + bx)/(x^2 + y^2))
};


#endif
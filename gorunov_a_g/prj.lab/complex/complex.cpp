#include "complex.h"
#include <cmath>
#include <iostream>

Complex::Complex(const double real)
  : Complex(real, 0.0) {
}

Complex::Complex(const double real, const double imaginary)
  : re(real)
  , im(imaginary) {
}

Complex& Complex::operator=(const double rhs) {
  re = rhs;
  im = 0;
  return *this;
}

bool Complex::operator==(const Complex& rhs) const {
  return ((fabs(re - rhs.re) <= std::numeric_limits<double>::epsilon()) &&
    (fabs(im - rhs.im) <= std::numeric_limits<double>::epsilon()));
}

bool Complex::operator!=(const Complex& rhs) const {
  return !operator==(rhs);
}

Complex operator-(const Complex& lhs) {
    return { -lhs.re, -lhs.im };
}

// сложение +=
Complex& Complex::operator+=(const Complex& rhs) {
  re += rhs.re;
  im += rhs.im;
  return *this;
}

// сложение +
Complex operator+(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}
Complex operator+(const Complex& lhs, const double rhs) {
  return Complex(lhs.re + rhs, lhs.im);
}
Complex operator+(const double lhs, const Complex& rhs) {
  return rhs + lhs;
}

// вычитание -=
Complex& Complex::operator-=(const Complex& rhs) {
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}

// вычитание -
Complex operator-(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}
Complex operator-(const Complex& lhs, const double rhs) {
  return Complex(lhs.re - rhs, lhs.im);
}
Complex operator-(const double lhs, const Complex& rhs) {
  return Complex(lhs - rhs.re, -rhs.im);
}

// умножение *=
Complex& Complex::operator*=(const double rhs) {
  re *= rhs;
  im *= rhs;
  return *this;
}
Complex& Complex::operator*=(const Complex& rhs) {
  double n = re * rhs.re - im * rhs.im;
  im = re * rhs.im + im * rhs.re;
  re = n;
  return *this;
}

// умножение *
Complex operator*(const Complex& lhs, const Complex& rhs) {
  Complex mult(lhs);
  mult *= rhs;
  return mult;
}
Complex operator*(const Complex& lhs, const double rhs) {
  return Complex(lhs.re * rhs, lhs.im * rhs);
}
Complex operator*(const double lhs, const Complex& rhs) {
  return rhs * lhs;
}

// деление /=
Complex& Complex::operator/=(const double rhs) {
  if (rhs < std::numeric_limits<double>::epsilon()) {
    throw std::invalid_argument("Divison by zero");
  } else {
    re /= rhs;
    im /= rhs;
  }
  return *this;
}
Complex& Complex::operator/=(const Complex& rhs) {
  double denum = rhs.re * rhs.re + rhs.im * rhs.im;
  double n = (re * rhs.re + im * rhs.im) / denum;
  if (denum < std::numeric_limits<double>::epsilon()) {
    throw std::invalid_argument("Divison by zero");
  } else {
    im = (im * rhs.re - re * rhs.im) / denum;
    re = n;
  }
  return *this;
}

// деление /
Complex operator/(const Complex& lhs, const Complex& rhs) {
  Complex divis(lhs);
  divis /= rhs;
  return divis;
}
Complex operator/(const Complex& lhs, const double rhs) {
  Complex divis(lhs);
  divis /= rhs;
  return divis;
}
Complex operator/(const double lhs, const Complex& rhs) {
  Complex divis(lhs);
  divis /= rhs;
  return divis;
}

/* // комплексно-сопряженные
Complex sopr(const Complex& rhs) {
  Complex sopr(rhs);
  sopr.im *= -1;
  return sopr;
}

//степень (квадрат)
Complex power(const Complex& rhs) {
  Complex power(rhs);
  power.im = pow(power.im, 2); //можно менять степень
  return power;
} */

std::ostream& Complex::writeTo(std::ostream& ostrm) const {
  ostrm << leftBrace << re << separator << im << rightBrace;
  return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) {
  char leftBrace = '0';
  double real = 0.0;
  char comma = '0';
  double imaginary = 0.0;
  char rightBrace = '0';
  istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
  if (istrm.good()) {
    if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) &&
      (Complex::rightBrace == rightBrace)) {
      re = real;
      im = imaginary;
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

struct Complex {
  Complex() {}
  explicit Complex(const double real);
  Complex(const Complex&) = default;
  Complex(const double real, const double imaginary);
  ~Complex() = default;
  Complex& operator=(const Complex&) = default;
  Complex& operator=(const double rhs);

  bool operator==(const Complex& rhs) const;
  bool operator!=(const Complex& rhs) const;
  Complex& operator+=(const Complex& rhs);
  Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
  Complex& operator-=(const Complex& rhs);
  Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
  Complex& operator*=(const double rhs);
  Complex& operator*=(const Complex& rhs);
  Complex& operator/=(const double rhs);
  Complex& operator/=(const Complex& rhs);

  std::ostream& writeTo(std::ostream& ostrm) const;
  std::istream& readFrom(std::istream& istrm);
  double re { 0.0 };
  double im { 0.0 };

  static const char leftBrace { '{' };
  static const char separator { ',' };
  static const char rightBrace { '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator+(const double lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator-(const double lhs, const Complex& rhs);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator*(const double lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double rhs);
Complex operator/(const double lhs, const Complex& rhs);

Complex sopr(const Complex& rhs);
Complex power(const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
  return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
  return rhs.readFrom(istrm);
}


#endif /* COMPLEX_H_ */

#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iosfwd>

int GCD (int a, int b);
int LCM (int a, int b);

class Rational {
public:
  Rational() = default;
  Rational(const Rational&) = default;
  explicit Rational(const int num);
  Rational(const int num, const int denum);
  ~Rational() = default;

  Rational& operator=(const Rational&) = default;
  Rational& operator=(const int rhs);

  //Rational operator-(const Rational& rhs) const; //????
  Rational& operator+=(const Rational& rhs); //+
  Rational& operator+=(const int rhs) { return operator+=(Rational(rhs)); }
  Rational& operator-=(const Rational& rhs); //+
  Rational& operator-=(const int rhs) { return operator-=(Rational(rhs)); }
  Rational& operator*=(const Rational& rhs); //+
  Rational& operator*=(const int rhs) { return operator*=(Rational(rhs)); }
  Rational& operator/=(const Rational& rhs); //+
  Rational& operator/=(const int rhs) { return operator/=(Rational(rhs)); }

  bool operator==(const Rational& rhs) const; // +
  bool operator!=(const Rational& rhs) const; // +
  bool operator<(const Rational& rhs) const; // +
  bool operator<=(const Rational& rhs) const; // +
  bool operator>(const Rational& rhs) const; // +
  bool operator>=(const Rational& rhs) const; // +


  std::istream& read_from(std::istream& istrm);
  std::ostream& write_to(std::ostream& ostrm) const;

private:
  void normalize();
private:
  int num_{0};
  int denum_{1};
  const static char delimiter_{'/'};
};

std::istream& operator>>(std::istream& istrm, Rational& r);
std::ostream& operator<<(std::ostream& ostrm, const Rational& r);

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const int rhs);
Rational operator+(const int lhs, const Rational& rhs);
//Rational operator+(const int lhs, const int rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const int rhs);
Rational operator-(const int lhs, const Rational& rhs);
//Rational operator-(const int lhs, const int rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const int rhs);
Rational operator*(const int lhs, const Rational& rhs);
//Rational operator*(const int lhs, const int rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const int rhs);
Rational operator/(const int lhs, const Rational& rhs);
//Rational operator/(const int lhs, const int rhs);

#endif

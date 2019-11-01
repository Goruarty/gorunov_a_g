#include <iostream>
#include <exception>
#include <cmath>
#include "rational.h"

//нормализация, приведение к нужному типу / виду.
int GCD (int a, int b){
	while(a>0 && b>0){
				  if(a > b){
					  a %= b;
				  } else {
					  b %= a;
				  }
	}
	return a+=b;
}

int LCM (int a, int b){
	return (a*b)/GCD(a,b);
}

Rational::Rational(const int num)
  : Rational(num, 1){
}

Rational::Rational(const int num, const int denum)
  : num_(num)
  , denum_(denum) {
  if (0 == denum_) {
    throw std::invalid_argument("Rational ctor - zero denuminator.");
  }
  normalize();
}

void Rational::normalize() {
  if (denum_ < 0) {
    num_ *= -1;
    denum_ *= -1;
  }
  int a = GCD(abs(num_),abs(denum_));
  num_/=a;
  denum_/=a;
}


// ввод и вывод
std::istream& Rational::read_from(std::istream& istrm) {
  int numerator(0);
  char delimiter('0');
  int denuminator(0);
  istrm >> numerator >> delimiter >> denuminator;
  if (denuminator==0) throw std::invalid_argument("operation is impossible!");
  else {
	  try {
          if (delimiter==Rational::delimiter_){
    	      num_ = numerator;
    	      denum_= denuminator;
    	      normalize();
          }
	  } catch (std::exception& ex){
	  std::cout << ex.what();
	  }
  }
  return istrm;
}

std::ostream& Rational::write_to(std::ostream& ostrm) const {
  ostrm << num_ << delimiter_ << denum_;
  return ostrm;
}


//  операторы сравнения (и присваивания)
Rational& Rational::operator=(const int rhs) {
  num_ = rhs;
  denum_ = 1;
  return *this;
}

bool Rational::operator==(const Rational& rhs) const {
  return num_ == rhs.num_ && denum_ == rhs.denum_;
}

bool Rational::operator!=(const Rational& rhs) const {
  return !operator==(rhs);
}

bool Rational::operator<(const Rational& rhs) const {
  int up1 = num_ * rhs.denum_;
  int up2 = denum_ * rhs.num_;
  return up1<up2;
}

bool Rational::operator<=(const Rational& rhs) const {
  return !operator>(rhs);
}

bool Rational::operator>(const Rational& rhs) const {
	int up1 = num_ * rhs.denum_;
	int up2 = denum_ * rhs.num_;
	return up1>up2;
}

bool Rational::operator>=(const Rational& rhs) const {
  return !operator<(rhs);
}
// << >>
std::istream& operator>>(std::istream& istrm, Rational& r) {
  return r.read_from(istrm);
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& r) {
  return r.write_to(ostrm);
}


// арифметические операторы


//// "+ += " ////
Rational& Rational::operator+=(const Rational& rhs){
	num_ = num_ * rhs.denum_ + denum_ * rhs.num_;
	denum_ *= rhs.denum_;
	normalize();
	return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs){
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational operator+(const Rational& lhs, const int rhs){
	return lhs + Rational(rhs);
}

Rational operator+(const int lhs, const Rational& rhs){
	return Rational(lhs) + rhs;
}

/*Rational operator+(const int lhs, const int rhs){
	return Rational(lhs) + Rational(rhs);
} */


//// "- -= " ////
Rational& Rational::operator-=(const Rational& rhs){
	num_ = num_ * rhs.denum_ - denum_ * rhs.num_;
	denum_ -= rhs.denum_;
	normalize();
	return *this;
}

Rational operator-(const Rational& lhs, const Rational& rhs){
	Rational subtr(lhs);
	subtr -= rhs;
	return subtr;
}

Rational operator-(const Rational& lhs, const int rhs){
	return lhs - Rational(rhs);
}

Rational operator-(const int lhs, const Rational& rhs){
	return Rational(lhs) - rhs;
}

/*Rational operator-(const int lhs, const int rhs){
	return Rational(lhs) - Rational(rhs);
} */


//// "* *= " ////
Rational& Rational::operator*=(const Rational& rhs){
	num_ *= rhs.num_;
	denum_ *= rhs.denum_;
	normalize();
	return *this;
}

Rational operator*(const Rational& lhs, const Rational& rhs){
	Rational mult(lhs);
	mult *= rhs;
	return mult;
}

Rational operator*(const Rational& lhs, const int rhs){
	return lhs * Rational(rhs);
}

Rational operator*(const int lhs, const Rational& rhs){
	return Rational(lhs) * rhs;
}

/*Rational operator*(const int lhs, const int rhs){
	return Rational(lhs) * Rational(rhs);
} */


//// "/ /= " ////
Rational& Rational::operator/=(const Rational& rhs){
	if (rhs.num_==0)
		throw std::invalid_argument("operation is impossible!");
	else {
		num_ *= rhs.denum_;
		denum_ *= rhs.num_;
		normalize();
	}
	return *this;
}

Rational operator/(const Rational& lhs, const Rational& rhs){
	Rational div(lhs);
	div /= rhs;
	return div;
}

Rational operator/(const Rational& lhs, const int rhs){
	return lhs / Rational(rhs);
}

Rational operator/(const int lhs, const Rational& rhs){
	return Rational(lhs) / rhs;
}

/*Rational operator/(const int lhs, const int rhs){
	return Rational(lhs) / Rational(rhs);
} */











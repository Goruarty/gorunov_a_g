#include "rational/rational.h"
#include <iostream>
#include <sstream>
#include <exception>

/*bool testParse(const std::string& str) {
    std::istringstream istrm(str);
    Rational z;
    try {
        istrm >> z;
        if (!istrm.fail()) {
            std::cout << "Read succes: " << str << " -> " << z << std::endl;
        } else {
            std::cout << "Read error: " << str << " -> " << z << std::endl;
        }
    } catch (std::invalid_argument){
        std::cout << "Read error: " << str << " -> " << "Division by zero is catched";
    }
    return istrm.good();
} */

int main() {
  try {
	  Rational n, d;
	  n = 5;
	  std::cout << "n = 5 " << n << std::endl;
	  n = Rational(-5, -2);
	  std::cout << n << std::endl;
	  d = Rational(n);
	  std::cout <<  d << std::endl;

	  std::cout << n << " == " << d  << " " <<
	    (n == d ? "yes" : "no") << std::endl;
	  std::cout << n << " != " << d << " " <<
	    (n != d ? "yes" : "no") << std::endl;
	  d = Rational(5, 8);
	  std::cout << n << " == " << d << " " <<
	    (n == d ? "yes" : "no") << std::endl;
	  std::cout << n << " != " << d << " " <<
	    (n != d ? "yes" : "no") << std::endl;
/*
	  std::cout << n << " <= " << d << " " <<
	    (n <= d ? "yes" : "no") << std::endl;
	  std::cout << n << " >= " << d << " " <<
	    (n >= d ? "yes" : "no") << std::endl;
	  std::cout << n << " < " << d << " " <<
	    (n < d ? "yes" : "no") << std::endl;
	  std::cout << n << " > " << d << " " <<
	    (n > d ? "yes" : "no") << std::endl;
*/
	  n = Rational(3, 5);
	  std::cout << n;
	  n += Rational(8, 3);
	  std::cout << " += 8/3 " << n << std::endl;
	  n += 2;
	  std::cout << n << " += 2 " << n << std::endl;
	  std::cout << n;
	  n -= 2;
	  std::cout << " -= 2" << n << std::endl;
	  std::cout << n;
	  n -= Rational(1, 5);
	  std::cout << " -= 1/5 " << n << std::endl;
	  std::cout << n;
	  n *= -8;
	  std::cout << " *= -8 " << n << std::endl;
	  std::cout << n;
	  n *= Rational(-5, -7);
	  std::cout << " *= (-5)/(-7) " << n << std::endl;
	  std::cout << n;
	  n /= -4;
	  std::cout << " /= -4 " << n << std::endl;
	  std::cout << n;
	  n /= Rational(-2, 3);
	  std::cout << " /= -2/3 " << n << std::endl;

	  std::cout << std::endl;
	  n = Rational(-17, -5);
	  d = Rational(43, 33);
	  std::cout << n << " + " << d << " = " << n + d << std::endl;
	  std::cout << n << " - " << d << " = " << n - d << std::endl;
	  std::cout << n << " * " << d << " = " << n * d << std::endl;
	  std::cout << n << " / " << d << " = " << n / d << std::endl;
	  std::cout << n << " + 2 = " << n + 2 << std::endl;
	  std::cout << "3 + " << n << " = " << 3 + n << std::endl;
	  std::cout << n << " - 7 = " << n - 7 << std::endl;
	  std::cout << "8 - " << n << " = " << 8 - n << std::endl;
	  std::cout << n << " * 7 = " << n * 7 << std::endl;
	  std::cout << "-5 * " << n << " = " << -5 * n << std::endl;
	  std::cout << n << " / 7 = " << n / 7 << std::endl;
	  std::cout << "20 / " << n << " = " << 20 / n << std::endl;
	  std::cout << std::endl;

	  n = Rational(-17, -5);
      try{
	  std::cout << "n / 0/7 = ";
	    std::cout << n / Rational(0, 7) << std::endl;
      } catch (std::exception& ex){
        std::cout << ex.what() << std::endl;
      }
      try {
	  std::cout << "7/0 = ";
	    std::cout << Rational(7,0);
	  std::cout << std::endl;
      } catch (std::exception& ex) {
         std::cout << ex.what() << std::endl;
      }
  } catch (std::exception& ex){
	std::cout << ex.what() << std::endl;
  }
  return 0;
}

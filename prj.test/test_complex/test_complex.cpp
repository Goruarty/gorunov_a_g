#include "complex.h"
#include <iostream>
#include <sstream>
#include <string>

bool testParse(const std::string& str) {
  std::istringstream istrm(str);
  Complex z;
  istrm >> z;
  if (istrm.good()) {
    std::cout << "Read success: " << str << " -> " << z << std::endl;
  } else {
    std::cout << "Read error: " << str << " -> " << z << std::endl;
  }
  return istrm.good();
}

int main() {
  Complex z;
  
  // из условия
  z+= Complex(8.0);
  testParse("{8.9,9}");
  testParse("(8.9,9)");
  testParse("{8.9, 9}");
  testParse("{8.9,9");
  
  // другие
  Complex y;
  z = 8.9;
  std::cout << "z = 8.9 " << z << std::endl;
  z = Complex(2, -3);
  std::cout << "z = (2, -3) " << z << std::endl;

  y = Complex(2, -3);
  std::cout << "2 == -3 " << (z == y ? "yes" : "no") << std::endl;
  y = Complex(2, -2);
  std::cout << "2 != -2 " << (z != y ? "yes" : "no") << std::endl;
  
  z = Complex(8, 8);
  std::cout << z;
  z += Complex(8.9);
  std::cout << "+= 8.9 " << z << std::endl;

  // -=
  z = Complex(-1, 7);
  std::cout << z;
  z -= Complex(9, 8);
  std::cout << "-= (9, 8) " << z << std::endl; 
  z = Complex(4, -4);
  std::cout << z;
  z -= 2.2;
  std::cout << " -= 2.2 " << z << std::endl;
  
  // *=
  z = Complex(5, 5);
  std::cout << z;
  z *= Complex(3, -4);
  std::cout << "*= (3, -4) " << z << std::endl;
  z = Complex(-2, 2);
  std::cout << z;
  z *= 8.9;
  std::cout << " *= 8.9 " << z << std::endl;
  
  // /=
  z = Complex(4, 4);
  std::cout << z;
  z /= Complex(2, 2);
  std::cout << " /= (2, 2) " << z << std::endl;
  z = Complex(3, 1);
  std::cout << z;
  z /= 8.9;
  std::cout << " /= 8.9 " << z << std::endl;
  
  // sopr
  z = Complex(5, 5);
  std::cout << z;
  z = sopr(z);
  std::cout <<"sopr" << z << std::endl;

  // pow
  z = Complex(7, 4);
  std::cout << z;
  z = power(z);
  std::cout << "pow" << z << std::endl;
  
  z = Complex(9, -9); y = Complex(-8, 8);
  std::cout << "(9,-9) + (-8,8) " << z + y << std::endl;
  std::cout << "(9,-9) - (-8,8) " << z - y << std::endl;
  std::cout << "(9,-9) * (-8,8) " << z * y << std::endl;
  std::cout << "(9,-9) / (-8,8) " << z / y << std::endl;
  std::cout << ;
  try {
    std::cout << "z / 0 = " << z / 0 << std::endl;
  }
  catch(std::invalid_argument) {
    std::cout << "z / 0 = " << "Division by zero is cathed" << std::endl;
  }

  try {
    std::cout << z / Complex(0, 0);
  }
  catch(std::invalid_argument) {
    std::cout << "Division by zero is cathed" << std::endl;
  }
  
  return 0;
}
#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
class Complex {
private:
  double realPart;
  double imaginaryPart;
 
public:
  Complex() {
    realPart = imaginaryPart = 0.0;
  }

  Complex(double inputRealPart, double inputImaginaryPart);

  Complex operator+(const Complex& complexRef) const;
  Complex operator-(const Complex& complexRef) const;
  Complex operator*(const Complex& complexRef) const;
  Complex operator*(int inputN) const;
  Complex operator~(void) const;

  friend Complex operator*(int inputN, const Complex& complexRef) {
    return complexRef * inputN;
  }
  friend std::istream& operator>>(std::istream& isRef, Complex& complexRef);
  friend std::ostream& operator<<(std::ostream& osRef, Complex complexRef);
};

#endif // !COMPLEX_H_

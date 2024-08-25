#include "11-7.h"

Complex::Complex(double inputRealPart, double inputImaginaryPart)
{
  realPart = inputRealPart;
  imaginaryPart = inputImaginaryPart;
}

Complex Complex::operator+(const Complex& complexRef) const {
  Complex sum(realPart + complexRef.realPart, imaginaryPart + complexRef.imaginaryPart);
  return sum;
}
Complex Complex::operator-(const Complex& complexRef) const {
  Complex sub(realPart - complexRef.realPart, imaginaryPart - complexRef.imaginaryPart);
  return sub;
}
Complex Complex::operator*(int inputN) const {
  Complex mul(realPart * inputN, imaginaryPart * inputN);
  return mul;
}

Complex Complex::operator*(const Complex& complexRef) const {
  double mulRealPart = realPart * complexRef.realPart - imaginaryPart * complexRef.imaginaryPart;
  double mulImaginaryPart = realPart * complexRef.imaginaryPart + imaginaryPart * complexRef.realPart;
  Complex mul(mulRealPart, mulImaginaryPart);

  return mul;
}

Complex Complex::operator~(void) const {
  Complex conju(realPart, -1 * imaginaryPart);
  return conju;
}

std::istream& operator>>(std::istream& isRef, Complex& complexRef) {
  std::cout << "real : ";
  isRef >> complexRef.realPart;
  
  std::cout << "imaginary : ";
  isRef >> complexRef.imaginaryPart;

  return isRef;
}

std::ostream& operator<<(std::ostream& osRef, Complex complexRef) {
  osRef << "(" << complexRef.realPart << ", " << complexRef.imaginaryPart << "i)" << '\n';

  return osRef;
}
#include <cmath>
#include "11-3.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
using std::cin;

bool isValidInput(double* pointerToTargetDistance, double* pointerToStepLength, int* pointerToInputN) {
  bool isValidInput = true;

  cout << "Enter target distance (q to quit) : ";
  if (!(cin >> *pointerToTargetDistance)) {
    return isValidInput = false;
  }

  cout << "Enter step length : ";
  if (!(cin >> *pointerToStepLength)) {
    return isValidInput = false;
  }

  cout << "Enter the trial count : ";
  if (!(cin >> *pointerToInputN)) {
    return isValidInput = false;
  }
  

  return isValidInput;
}

namespace VECTOR {

  const double RADIAN_TO_DEGREE = 45.0 / atan(1.0);

  void Vector::setMagnitude() {
    magnitude = sqrt(positionOfX * positionOfX + positionOfY * positionOfY);
  }

  void Vector::setAngle() {
    if (positionOfX == 0 && positionOfY == 0) {
      angle = 0.0;
    }
    else {
      angle = atan2(positionOfY, positionOfX);
    }
  }

  void Vector::setPositionOfX(void) {
    positionOfX = magnitude * cos(angle);
  }
  void Vector::setPositionOfY(void)
  {
    positionOfY = magnitude * sin(angle);
  }
  Vector::Vector() ///default constructor
  {
    positionOfX = positionOfY = magnitude = angle = 0.0;
    mode = RECT;
  }
  Vector::Vector(double firstValue, double secondValue, Mode inputForm) ///Mode's default -> RECT
  {
    mode = inputForm;
    if (mode == RECT) {
      positionOfX = firstValue;
      positionOfY = secondValue;
      setMagnitude();
      setAngle();
    }
    else if (mode == POL) {
      magnitude = firstValue;
      angle = secondValue;
      setPositionOfX();
      setPositionOfY();
    }
    else {
      cout << "Incorrect 3rd arguments to Vector() so vector set to 0 \n";
      positionOfX = positionOfY = magnitude = angle = 0.0;
      mode = RECT;
    }
  }
  void Vector::reset(double firstValue, double secondValue, Mode inputForm)
  {
    mode = inputForm;
    if (mode == RECT) {
      positionOfX = firstValue;
      positionOfY = secondValue;
      setMagnitude();
      setAngle();
    }
    else if (mode == POL) {
      magnitude = firstValue;
      angle = secondValue;
      setPositionOfX();
      setPositionOfY();
    }
    else {
      cout << "Incorrect 3rd arguments to Vector() so vector set to 0 \n";
      positionOfX = positionOfY = magnitude = angle = 0.0;
      mode = RECT;
    }
  }
  Vector::~Vector()
  {
  }
  void Vector::toggleToPolar()
  {
    mode = POL;
  }
  void Vector::toggleToRect()
  {
    mode = RECT;
  }
  Vector Vector::operator+(const Vector& vectorRef) const
  {
    return Vector(positionOfX + vectorRef.positionOfX, positionOfY + vectorRef.positionOfY);
  }
  Vector Vector::operator-(const Vector& vectorRef) const
  {
    return Vector(positionOfX - vectorRef.positionOfX, positionOfY - vectorRef.positionOfY);
  }
  Vector Vector::operator-() const
  {
    return Vector(-positionOfX, -positionOfY);
  }
  Vector Vector::operator*(double inputN) const
  {
    return Vector(inputN * positionOfX, inputN * positionOfY);
  }
  ///friend function
  Vector operator*(double n, const Vector& a)
  {
    return a * n;
  }

  std::ostream& operator<<(std::ostream& ostreamRef, const Vector& vectorRef)
  {
    if (vectorRef.mode == Vector::RECT) {
      ostreamRef << "(x, y) = (" << vectorRef.positionOfX << ", " << vectorRef.positionOfY << ")";
    }
    else if (vectorRef.mode == Vector::POL) {
      ostreamRef << "(m, a) = (" << vectorRef.magnitude << ", " << vectorRef.angle * RADIAN_TO_DEGREE << ")";
    }
    else {
      ostreamRef << "Vector object mode is invalid";
    }
    return ostreamRef;
  }
}
#include <cmath>
#include "11-2.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan; ///polar
using std::atan2;///rectangle
using std::cout;

namespace VECTOR {

  const double RADIAN_TO_DEGREE = 45.0 / atan(1.0);

  /*void Vector::setMagnitude() {
    magnitude = sqrt(positionOfX * positionOfX + positionOfY * positionOfY);
  }

  void Vector::setAngle() {
    if (positionOfX == 0 && positionOfY == 0) {
      angle = 0.0;
    }
    else {
      angle = atan2(positionOfY, positionOfX);
    }
  }*/

  double Vector::getMagnitude() const {
    double magnitude = sqrt(positionOfX * positionOfX + positionOfY * positionOfY);
    return magnitude;
  }
  double Vector::getAngle() const {
    double angle{};
    if (positionOfX == 0 && positionOfY == 0) {
      angle = 0.0;
    }
    else {
      angle = atan2(positionOfY, positionOfX);
    }

    return angle;
  }

  void Vector::setPositionOfX(double inputMagnitude, double inputAngle) {
    positionOfX = inputMagnitude * cos(inputAngle);
  }
  void Vector::setPositionOfY(double inputMagnitude, double inputAngle)
  {
    positionOfY = inputMagnitude * sin(inputAngle);
  }

  Vector::Vector() ///default constructor
  {
    positionOfX = positionOfY /*= magnitude = angle */= 0.0;
    mode = RECT;
  }
  Vector::Vector(double firstValue, double secondValue, Mode inputForm) ///Mode's default -> RECT
  {
    mode = inputForm;
    if (mode == RECT) {
      positionOfX = firstValue;
      positionOfY = secondValue;
      /*setMagnitude();
      setAngle();*/
    }
    else if (mode == POL) {
      double magnitude = firstValue;
      double angle = secondValue;
      setPositionOfX(magnitude, angle);
      setPositionOfY(magnitude, angle);
    }
    else {
      cout << "Incorrect 3rd arguments to Vector() so vector set to 0 \n";
      positionOfX = positionOfY /*= magnitude = angle*/ = 0.0;
      mode = RECT;
    }
  }
  void Vector::reset(double firstValue, double secondValue, Mode inputForm)
  {
    mode = inputForm;
    if (mode == RECT) {
      positionOfX = firstValue;
      positionOfY = secondValue;
      /*setMagnitude();
      setAngle();*/
    }
    else if (mode == POL) {
      double magnitude = firstValue;
      double angle = secondValue;
      setPositionOfX(magnitude, angle);
      setPositionOfY(magnitude, angle);
    }
    else {
      cout << "Incorrect 3rd arguments to Vector() so vector set to 0 \n";
      positionOfX = positionOfY /*= magnitude = angle*/ = 0.0;
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
      ostreamRef << "(m, a) = (" << vectorRef.getMagnitude() << ", " << vectorRef.getAngle() * RADIAN_TO_DEGREE << ")";
    }
    else {
      ostreamRef << "Vector object mode is invalid";
    }
    return ostreamRef;
  }
}
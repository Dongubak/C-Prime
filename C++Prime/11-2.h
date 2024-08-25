#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <fstream>
namespace VECTOR {
  class Vector {
  public:
    enum Mode { RECT, POL };
  private:
    double positionOfX;
    double positionOfY;
    /*double magnitude;
    double angle;*/
    Mode mode;
    /*void setMagnitude(void);
    void setAngle(void);*/

    void setPositionOfX(double inputMagnitude, double inputAngle);
    void setPositionOfY(double inputMagnitude, double inputAngle);

  public:
    Vector();
    Vector(double firstValue, double secondValue, Mode inputForm = RECT);
    void reset(double firstValue, double secondValue, Mode inputForm = RECT);
    ~Vector();
    double getX() const { return positionOfX; }
    double getY() const { return positionOfY; }
    double getMagnitude() const;
    double getAngle() const;
    void toggleToPolar();
    void toggleToRect();

    Vector operator+(const Vector& vectorRef) const;
    Vector operator-(const Vector& vectorRef) const;
    Vector operator-() const;
    Vector operator*(double inputN) const;

    friend Vector operator*(double firstOperand, const Vector& vectorRef);
    friend std::ostream& operator<<(std::ostream& ostreamRef, const Vector& vectorRef);
  };
}

#endif // !VECTOR_H_

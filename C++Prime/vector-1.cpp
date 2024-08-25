#include <cmath>
#include "vector.h"
#include "11-1.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
  const double Rad_to_deg = 45.0 / atan(1.0);

  void Vector::set_mag() {
    mag = sqrt(x * x + y * y);
  }

  void Vector::set_ang() {
    if (x == 0.0 && y == 0.0) {
      ang = 0.0;
    }
    else {
      ang = atan2(y, x);
    }
  }

  void Vector::set_x() {
    x = mag * cos(ang);
  }

  void Vector::set_y() {
    y = mag * sin(ang);
  }

  Vector::Vector() {
    std::cout << "calling default constructor" << '\n';
    x = y = mag = ang = 0.0;
    mode = RECT;
  }

  Vector::Vector(double n1, double n2, Mode form) {
    mode = form;
    if (mode == RECT) {
      x = n1;
      y = n2;
      set_mag();
      set_ang();
    }
    else if (mode == POL) {
      mag = n1;
      ang = n2;
      set_x();
      set_y();
    }
    else {
      cout << "invalid arguments\n";
      cout << "all memeber initialized 0.0" << '\n';
      x = y = mag = ang = 0.0;
      mode = RECT;
    }
  }

  void Vector::reset(double n1, double n2, Mode form) {
    mode = form;
    if (mode == RECT) {
      x = n1;
      y = n2;
      set_mag();
      set_ang();
    }
    else if (mode == POL) {
      mag = n1;
      ang = n2;
      set_x();
      set_y();
    }
    else {
      cout << "invalid arguments\n";
      cout << "all memeber initialized 0.0" << '\n';
      x = y = mag = ang = 0.0;
      mode = RECT;
    }
  }
  Vector::~Vector(){
    NULL;
  }

  void Vector::polar_mode() {
    mode = POL;
  }
  void Vector::rect_mode() {
    mode = RECT;
  }

  
  Vector Vector::operator+(const Vector& b) const {
    return Vector(x + b.x, y + b.y);
  }
  Vector Vector::operator-(const Vector& b) const
  {
    return Vector(x - b.x, y - b.y);
  }
  Vector Vector::operator-() const
  {
    return Vector(-x, -y);
  }
  Vector Vector::operator*(double n) const
  {
    return Vector(n * x, n * y);
  }
  Vector operator*(double n, const Vector& a)
  {
    return a * n;
  }

  std::ostream& operator<<(std::ostream& os, const Vector& v)
  {
    std::cout << "friend function call\n";
    if (v.mode == Vector::RECT) {
      os << "(" << v.x << ", " << v.y << ")\n";
    }
    else if (v.mode == Vector::POL) {
      os << "(" << v.mag << ", " << v.ang * Rad_to_deg << ")\n";
    }
    else {
      os << "invalid mode\n";
    }
    return os;
  }

}
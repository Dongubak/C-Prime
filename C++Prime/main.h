#ifndef MYTIME3_H_
#define MYTIME3_H_

#include <iostream>
#include "11-4.h"

class Time {
private:
  int hours;
  int minutes;

public:
  Time();
  Time(int h, int m = 0);
  void AddMin(int m);
  void AddHr(int h);
  void Reset(int h = 0, int m = 0);
  Time operator+(const Time& t) const;
  Time operator-(const Time& t) const;
  Time operator*(double n) const;
  friend Time operator*(double m, const Time& t) {
    return t * m;
  }
  inline std::ostream& operator<<(std::ostream& osRef, const Time& timeRef)
  {
      // TODO: insert return statement here
  }
  friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

#endif // !MYTIME3_H_

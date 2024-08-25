#ifndef MYTIME_H_
#define MYTIME_H_

#include <iostream>

class Time {
private:
  int hours;
  int minutes;

public:
  Time(); ///default constructor
  Time(int inputHour, int inputMinutes = 0);
  void addMin(int inputMinutes);
  void addHour(int inputHours);
  void reset(int inputHour = 0, int inputMinutes = 0);
  
  friend Time operator-(const Time& timeRefIM, const Time& timeRefEX);
  friend Time operator+(const Time& timeRefIM, const Time& timeRefEX);
  friend Time operator*(const Time& timeRef, double inputN); ///friend 왜 쓰는지
  friend Time operator*(double inputN, const Time& timeRef) {
    return timeRef * inputN;
  }
  friend std::ostream& operator<<(std::ostream& osRef, const Time& timeRef);
};

#endif // !MYTIME3_H_

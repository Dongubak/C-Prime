#include "main.h"

Time::Time() {
  hours = minutes = 0;
}

Time::Time(int h, int m) {
  hours = h;
  minutes = m;
}

void Time::AddMin(int m) {
  minutes += m;
  hours += minutes / 60;
  minutes %= 60;
}

void Time::AddHr(int h) {
  hours += h;
}

void Time::Reset(int h, int m) {
  hours = h;
  minutes = m;
}

Time Time::operator+(const Time& t) const {
  Time sum;
  sum.minutes = minutes + t.minutes;
  sum.hours = hours + t.hours + t.minutes / 60;
  sum.minutes %= 60;
  return sum;
}

Time Time::operator-(const Time& t) const {
  Time diff;
  int firstTotal = 0, secondTotal = 0;
  int resultdiff = 0;
  firstTotal = t.minutes + 60 * t.hours;
  secondTotal = minutes + 60 * hours;
  resultdiff = firstTotal - secondTotal;

  diff.Reset(resultdiff / 60, resultdiff % 60);
  return diff;
  
}

Time Time::operator*(double mult) const {
  Time result;
  long totalMinutes = hours * mult * 60 + minutes * mult;
  result.Reset(totalMinutes / 60, totalMinutes % 60);
  return result;
}

std::ostream& operator<<(std::ostream& os, const Time& t) {

  std::cout << t.hours << " : " << t.minutes << '\n';
  
  return os;
}
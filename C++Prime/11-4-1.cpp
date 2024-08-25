#include "11-4.h"

Time::Time() {
  hours = minutes = 0;
}

Time::Time(int inputHour, int inputMinutes)
{
  hours = inputHour;
  minutes = inputMinutes;
}

void Time::addMin(int inputMinutes)
{
  minutes += inputMinutes;
  hours += minutes / 60;
  minutes %= 60;
}

void Time::addHour(int inputHours)
{
  hours += inputHours;
}

void Time::reset(int inputHour, int inputMinutes)
{
  hours = inputHour;
  minutes = inputMinutes;
}

Time operator+(const Time& timeRefIM, const Time& timeRefEX)
{
  Time sum{};
  sum.minutes = timeRefIM.minutes + timeRefEX.minutes;
  sum.hours = timeRefIM.hours + timeRefEX.hours + sum.minutes / 60;
  sum.minutes %= 60;
  return sum;
}

Time operator-(const Time& timeRefIM, const Time& timeRefEX)
{
  Time diff{};
  int thisObjTotalMinutes = timeRefIM.minutes + 60 * timeRefIM.hours;
  int timeRefTotalMinutes = timeRefEX.minutes + 60 * timeRefEX.hours;

  diff.minutes = (timeRefTotalMinutes - thisObjTotalMinutes) % 60;
  diff.hours = (timeRefTotalMinutes - thisObjTotalMinutes) / 60;

  return diff;
}

Time operator*(const Time& timeRef, double inputN)
{
  Time result{};
  long totalMinutes = timeRef.hours * inputN * 60 + timeRef.minutes * inputN;

  result.hours = totalMinutes / 60.0;
  result.minutes = totalMinutes % 60;

  return result;
}

std::ostream& operator<<(std::ostream& osRef, const Time& timeRef) {
  osRef << timeRef.hours << " : " << timeRef.minutes;
  return osRef;
}
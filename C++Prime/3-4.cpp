#include <iostream>

int main() {
  using namespace std;
  const long getDay = 60 * 60 * 24;
  const long getHour = 60 * 60;
  const long getMinute = 60;
  long inputSecond;

  cout << "enter the second : ";
  cin >> inputSecond;
  cout << inputSecond << "초 = ";
  cout << (inputSecond / getDay) << "일, ";
  inputSecond = inputSecond % getDay;
  cout << (inputSecond / getHour) << "시간, ";
  inputSecond %= getHour;
  cout << (inputSecond / getMinute) << "분, ";
  inputSecond %= getMinute;
  cout << (inputSecond) << "초";



  return 0;
} 
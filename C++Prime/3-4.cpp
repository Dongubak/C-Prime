#include <iostream>

int main() {
  using namespace std;
  const long getDay = 60 * 60 * 24;
  const long getHour = 60 * 60;
  const long getMinute = 60;
  long inputSecond;

  cout << "enter the second : ";
  cin >> inputSecond;
  cout << inputSecond << "�� = ";
  cout << (inputSecond / getDay) << "��, ";
  inputSecond = inputSecond % getDay;
  cout << (inputSecond / getHour) << "�ð�, ";
  inputSecond %= getHour;
  cout << (inputSecond / getMinute) << "��, ";
  inputSecond %= getMinute;
  cout << (inputSecond) << "��";



  return 0;
} 
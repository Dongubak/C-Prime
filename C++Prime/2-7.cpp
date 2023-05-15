#include <iostream>

using namespace std;

void displayTime(int inputHour, int inputMinute) {
  cout << "time : " << inputHour << ":" << inputMinute;
}

int main() {

  int inputHour, inputMinute;

  cout << "enter the hour : ";
  cin >> inputHour;

  cout << "enter the minute : ";
  cin >> inputMinute;

  displayTime(inputHour, inputMinute);

  return 0;
}
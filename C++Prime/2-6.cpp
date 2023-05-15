#include <iostream>

double convertLightYearToMile(double inputLightYear) {
  return inputLightYear * 63240;
}

int main() {

  using namespace std;

  cout << "enter the distance(light year) : ";
  double inputYear = 0;
  cin >> inputYear;

  cout << inputYear << " is " << convertLightYearToMile(inputYear);

  return 0;
}
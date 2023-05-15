#include <iostream>

double convertTemperatureCToF(double inputTemperatureC) {
  return 1.8 * inputTemperatureC + 32;
}

int main() {

  using namespace std;

  double inputTemperatureC = 0;
  cout << "enter the temperature(C) : ";
  cin >> inputTemperatureC;
  cout << "convert " << inputTemperatureC <<  "(C) to F : " <<convertTemperatureCToF(inputTemperatureC);

  return 0;
}
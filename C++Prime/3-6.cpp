#include <iostream>

int main() {

  using namespace std;

  int inputDistanceKilo, inputConsumeGasoline;

  cout << "enter the distace and gasoline(kilo, liter)(seperated in space) : ";
  cin >> inputDistanceKilo >> inputConsumeGasoline;

  cout << "Gas mileage : " << (double(inputConsumeGasoline) / inputDistanceKilo) * 100;

  return 0;
}
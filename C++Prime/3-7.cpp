#include <iostream>

int main() {
  using namespace std;
  double inputGasmileageEurope;
  const double ratio = (1 / 3.875) * (1 / 62.14);
  cout << "enter the Gas mileage(Europe) : ";
  cin >> inputGasmileageEurope;
  cout << "Gas mileage(American) : " << 1 / (inputGasmileageEurope * ratio);

}
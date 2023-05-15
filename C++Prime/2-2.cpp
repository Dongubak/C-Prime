#include <iostream>

double convertMileToKilo(double inputMile) {
  return inputMile * 1.60394;
}

int main() {
  
  using namespace std;

  double inputMile = 0;
  cout << "enter the distance(mile) : ";
  cin >> inputMile;
  cout << "convert mile to kilometer : " << convertMileToKilo(inputMile);

  return 0;
}
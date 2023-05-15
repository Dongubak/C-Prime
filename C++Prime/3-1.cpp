#include <iostream>

int main() {

  using namespace std;

  int inputHeightCm = 0;
  const double cmTocm = 1., cmToM = 10e-3;

  cout << "enter your height(cm) : ";
  cin >> inputHeightCm;

  cout << "your height(m) : " << inputHeightCm * cmToM << '\n';
  cout << "your height(cm) : " << inputHeightCm * cmTocm << '\n';
  
  return 0;
}
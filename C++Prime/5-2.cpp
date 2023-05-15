#include <iostream>
#include <array>

const int ArSize = 101;

int main(void) {
  using namespace std;

  array<double, ArSize> factorials;
  factorials[1] = factorials[0] = 1.0;

  for (int i = 2; i < ArSize; i++) {
    factorials[i] = i * factorials[i - 1];
  }

  cout << factorials[100];

  return 0;
}
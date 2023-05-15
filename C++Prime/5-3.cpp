#include <iostream>

int main(void) {

  using namespace std;

  int tmpInputNumber;
  int sum = 0;
  cin >> tmpInputNumber;
  while (tmpInputNumber != 0) {
    sum += tmpInputNumber;
    cin >> tmpInputNumber;
  }

  cout << "sum of input values : " << sum;

  return 0;
}
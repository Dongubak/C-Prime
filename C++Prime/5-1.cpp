#include <iostream>

int main(void) {

  using namespace std;

  int inputStart, inputEnd;

  cout << "enter the two numbers (seperated in space) : ";
  cin >> inputStart >> inputEnd;
  int sum = 0;
  for (int i = inputStart; i < inputEnd + 1; i++) {
    sum += i;
  }

  cout << "sum " << inputStart << " to " << inputEnd << " : " << sum;

  return 0;
}
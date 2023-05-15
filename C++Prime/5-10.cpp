#include <iostream>

int main(void) {

  using namespace std;

  int inputColumn{};

  cout << "enter the column : ";
  cin >> inputColumn;

  for (int i = 0, j = inputColumn; i < inputColumn; i++, j--) {
    for (int k = 0; k < j - 1; k++) {
      cout << "'";
    }
    
    for (int k = 0; k < -j + 1 + inputColumn; k++) {
      cout << "*";
    }

    cout << '\n';
  }

  return 0;
}
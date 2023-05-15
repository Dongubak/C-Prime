#include <iostream>

int main() {
  using namespace std;
  int inputValue = 0;
  cin >> inputValue;

  for (int i = 0; i <= inputValue; i++) {
    for (int j = 0; j < inputValue - i; j++) {
      cout << "#";
    }
    for (int k = 0; k < i; k++) {
      cout << "*";
    }

    cout << "*";

    for (int j = 0; j < i; j++) {
      cout << "*";
    }
    for (int k = 0; k < inputValue - i; k++) {
      cout << "#";
    }

    cout << '\n';
  }

  return 0;
}

//***#***
//**###**
//*#####*
//#######

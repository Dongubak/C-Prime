#include <iostream>

using namespace std;

int factorial(int number);
bool setValue(int* valuePointer);

int main(void) {


  int inputValue{};

  while (setValue(&inputValue)) {
    cout << factorial(inputValue) << '\n';
  }

 
  return 0;
}

int factorial(int number) {
  if (number == 0) {
    return 1;
  }

  return factorial(number - 1) * number;
}

bool setValue(int* valuePointer)
{
  bool isValidInput = true;
  cout << "enter the number (end -1) : ";
  if (!(cin >> *valuePointer) || *valuePointer < 0) {
    isValidInput = false;
  }

  return isValidInput;
}

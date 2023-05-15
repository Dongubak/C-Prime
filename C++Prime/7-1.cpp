#include <iostream>

using namespace std;
bool setNumbers(int* firstNumber, int* secondNumber);
double getHarmonic(int firstNumber, int secondNumber);

int main(void) {
  int firstInput, secondInput;

  while (setNumbers(&firstInput, &secondInput)) {
    cout << "Harmonic of " << firstInput << " and " << secondInput << " : " <<
      getHarmonic(firstInput, secondInput) << '\n';
  }

  return 0;
}

bool setNumbers(int* firstNumber, int* secondNumber)
{

  cout << "enter two numbers seperated in space (end 0): ";
  bool isValidInput = false;

  if (cin >> *firstNumber >> *secondNumber && *firstNumber != 0 && *secondNumber != 0) {
    isValidInput = true;
  }

  return isValidInput;
}

double getHarmonic(int firstNumber, int secondNumber)
{
  return 2.0 * firstNumber * secondNumber / (firstNumber + secondNumber);
}



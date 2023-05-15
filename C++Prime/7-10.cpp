#include <iostream>

using namespace std;

double calculate(double firstValue, double secondValue, double (*functionPointer)(double, double));
bool setValues(int* firstValue, int* secondValue);
double add(double firstValue, double secondValue) {
  return firstValue + secondValue;
}

double sub(double firstValue, double secondValue) {
  return firstValue - secondValue;
}

double mul(double firstValue, double secondValue) {
  return firstValue * secondValue;
}

double div(double firstValue, double secondValue) {
  return firstValue / secondValue;
}

int main(void) {


  int firstValue{}, secondValue{};

  cout << "enter two numbers seperated in space (end : q) :";

  double (*funcPointers[4])(double, double) = {add, sub, mul, div};
  char operators[4] = { '+', '-', '*', '/' };

  while(setValues(&firstValue, &secondValue)) {
    for (int i = 0; i < 4; i++) {
      cout << firstValue << " " << operators[i] << " " << secondValue << " = " 
           << calculate(firstValue, secondValue, funcPointers[i]) << '\n';
    }
  }


  cout << "end program";

  return 0;
}



double calculate(double firstValue, double secondValue, double(*functionPointer)(double, double))
{
  return functionPointer(firstValue, secondValue);
}

bool setValues(int* firstValue, int* secondValue)
{
  bool isValidInput = true;

  if (!(cin >> *firstValue >> *secondValue)) {
    isValidInput = false;
  }

  return isValidInput;
}

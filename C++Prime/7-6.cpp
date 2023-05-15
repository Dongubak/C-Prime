#include <iostream>

const int Length = 10;

using namespace std;
int Fill_array(double* arrPointer, int elementCount);
void Show_array(const double* arrPointer, const int elementCount);
void Reverse_array(double* arrPointer, const int elementCount);

int main(void) {
  int inputCount{};
  double* arr = new double[Length];

  inputCount = Fill_array(arr, Length);
  Show_array(arr, inputCount);
  Reverse_array(arr, inputCount);
  Show_array(arr, inputCount);

  return 0;
}

int Fill_array(double* arrPointer, int elementCount) {
  int validInputCount{};
  for (int i = 0; i < elementCount; i++) {
    cout << "enter the number " << "< " << i + 1 << " > " << ": ";
    if (!(cin >> arrPointer[i])) {
      break;
    }
    validInputCount += 1;
  }
  
  return validInputCount;
}

void Show_array(const double* arrPointer, const int elementCount)
{
  for (int i = 0; i < elementCount; i++) {
    cout << "<" << i + 1 << "> " << ": " << arrPointer[i] << '\n';
  }

  cout << '\n';
}

void Reverse_array(double* arrPointer, const int elementCount)
{
  double* LeftPointer = arrPointer + 1;
  double* RightPointer = arrPointer + elementCount - 2;

  while (LeftPointer < RightPointer) {
    double tmp = *RightPointer;
    *RightPointer = *LeftPointer;
    *LeftPointer = tmp;
    LeftPointer++, RightPointer--;
  }
}

#include <iostream>

using namespace std;

const int Length = 4;

double* setArr(double* startPointer, double* const endPointer);
void getArr(const double* startPointer, double* const endPointer);

int main(void) {


  double* arr = new double[Length];
  double* endPt{};

  endPt = setArr(arr, arr + Length);
  getArr(arr, endPt);

  delete[]arr;

  return 0;
}

double* setArr(double* startPointer, double* const endPointer)
{
  double* returnPointer = startPointer;
  int i = 1;
  while (startPointer < endPointer) {

    cout << "<" << i << ">" << "enter the number : ";
    if (!(cin >> *startPointer)) {
      break;
    }

    returnPointer = ++startPointer;
  }

  return returnPointer;
}

void getArr(const double* startPointer, double* const endPointer)
{
  int i = 1;
  while(startPointer < endPointer) {
    cout << "<" << i << ">" << " : " << *startPointer << '\n';
    i++;
    startPointer++;
  }

}

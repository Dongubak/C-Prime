#include <iostream>
#include <array>

int main(void) {

  using namespace std;

  array<double, 3> runData{};
  int inputCount = 0;

  int outerIter = 0;

  for (outerIter = 0; outerIter < 3; outerIter++) {
    cout << "enter the record (end : q) : ";
    cin >> runData[outerIter];
    if (cin.fail()) 
      break;
    inputCount += 1;
  }

  double sum = 0;

  for (outerIter = 0; outerIter < inputCount; outerIter++) {
    sum += runData[outerIter];
  }

  cout << "input count : " << inputCount << '\n';
  cout << "average of records : " << sum / inputCount;

  return 0;
}
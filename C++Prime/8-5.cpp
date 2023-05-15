#include <iostream>

const int ELEMENT_COUNT = 5;

template <class T>
T findMaxValue(T dataArr[ELEMENT_COUNT]);

int main(void) {

  using namespace std;

  int exArr1[ELEMENT_COUNT] = { 10, 13, 14, 53, 20 };
  double exArr2[ELEMENT_COUNT] = { 10.02, 10.05, 12.04, 22.53, 61.02 };

  cout << "max value in exArr1 : " << findMaxValue(exArr1) << '\n';

  cout << "max value in exArr2 : " << findMaxValue(exArr2) << '\n';

  return 0;
}

template<class T>
T findMaxValue(T dataArr[ELEMENT_COUNT])
{
  T tmpMax = dataArr[0];

  for (int i = 0; i < ELEMENT_COUNT; i++) {
    tmpMax = dataArr[i] > tmpMax ? dataArr[i] : tmpMax;
  }

  return tmpMax;
}

#include <iostream>
#include <cstring>

template <class T>
T findMaxValue(T* dataArr, int elementCount);

template<>
const char* findMaxValue<const char*>(const char** doublePointer, int elementCount);

int main(void) {
  using namespace std;

  const int ELEMENT_COUNT = 5;
  const char* exString[ELEMENT_COUNT] = {
    "And I know there's a line, but I crossed it",
    "And I pray that it won't leave a scar",
    "I said I hate you, but I'm sorry",
    "Sometimes I wish you'd cut me off",
    "Maybe I should think before I talk"
  };

  int stringLength[ELEMENT_COUNT]{};
  for (int i = 0; i < ELEMENT_COUNT; i++) {
    stringLength[i] = strlen(exString[i]);
  }

  for (int i = 0; i < ELEMENT_COUNT; i++) {
    cout << stringLength[i] << " ";
  }
  cout << '\n';

  int exArr1[6] = { 10, 11, 16, 12, 54, 84 };
  int arr1Length = sizeof(exArr1) / sizeof(int);

  double exArr2[4] = { 10.2, 30.42, 63.85, 0.654 };
  int arr2Length = sizeof(exArr2) / sizeof(double);

  cout << "Max value in exArr1 : " << findMaxValue(exArr1, arr1Length) << '\n';
  cout << "Max value in exArr2 : " << findMaxValue(exArr2, arr2Length) << '\n';

  cout << "Long String : " << findMaxValue(exString, ELEMENT_COUNT);

  return 0;
}

template<class T>
T findMaxValue(T *dataArr, int elementCount)
{
  T tmpMaxValue = dataArr[0];
  for (int i = 0; i < elementCount; i++) {
    tmpMaxValue = dataArr[i] > tmpMaxValue ? dataArr[i] : tmpMaxValue;
  }

  return tmpMaxValue;
}

template<>
const char* findMaxValue<const char*>(const char** doublePointer, int elementCount)
{
  std::cout << "explicit specialization" << '\n';
  const char* tmpMaxStringPointer = doublePointer[0];
  for (int i = 0; i < elementCount; i++) {
    tmpMaxStringPointer = strlen(doublePointer[i]) > strlen(tmpMaxStringPointer) ? doublePointer[i] : tmpMaxStringPointer;
  }

  return tmpMaxStringPointer;
}

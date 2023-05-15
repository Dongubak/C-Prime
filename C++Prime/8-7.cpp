#include <iostream>

struct person {
  std::string name;
  int amount;
};

template<class T>
T sumArr(T* dataArr, int elementCount);

template<class T>
T sumArr(T* dataPointerArr[], int elementCount);

int main(void) {

  using namespace std;
  const int COUNT = 4;

  person customers[COUNT] = {
    {"James", 30000},
    {"Hopes", 60400},
    {"Jaspers", 830200},
    {"Albert", 430230}
  };
  int *customerAmountArr[COUNT]{};
  for (int i = 0; i < COUNT; i++) {
    customerAmountArr[i] = &(customers[i].amount);
  }

  int exArr[6] = { 13, 31, 103, 301, 310, 130 };

  cout << "sum of integer arr : " << sumArr(exArr, 6) << '\n';

  cout << "sum of workers amount memeber : " << sumArr(customerAmountArr, COUNT);

  return 0;
}

template<class T>
T sumArr(T* dataArr, int elementCount)
{
  T sum{};
  for (int i = 0; i < elementCount; i++) {
    sum += dataArr[i];
  }
  return sum;
}

template<class T>
T sumArr(T* dataPointerArr[], int elementCount)
{
  T sum{};
  for (int i = 0; i < elementCount; i++) {
    sum += *(dataPointerArr[i]);
  }
  return sum;
}

#include <iostream>

struct Car {
  char companyName[15];
  int manufactureYear;
};

int main(void) {
  using namespace std;
  int inputCount{};

  cout << "enter the car's count : ";
  cin >> inputCount;

  Car* carInfos = new Car[inputCount];
   
  for (int i = 0; i < inputCount; i++) {
    cout << "car " << "#" << i << " : " << '\n';
    cout << "company Name : ";
    cin >> carInfos[i].companyName;
    cout << "Manufacture year : ";
    cin >> carInfos[i].manufactureYear;
  }

  cout << "Your car's list" << '\n';
  for (int i = 0; i < inputCount; i++) {
    cout << carInfos[i].manufactureYear << " " << carInfos[i].companyName << '\n';
  }



  delete[]carInfos;

  return 0;
}
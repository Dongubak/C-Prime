#include <iostream>

const int elementCount = 10;

int main(void) {
  
  using namespace std;

  double inputDonation[10]{};
  int inputCount{};
  for (int i = 0; i < elementCount; i++) {
    cout << "enter the donation " << inputCount  + 1<< " : ";
    if (!(cin >> inputDonation[inputCount])) {
      break;
    }
    inputCount++;
  }

  int sum = 0;
  for (int i = 0; i < inputCount; i++) {
    sum += inputDonation[i];
  }

  int avg = sum / inputCount;
  int overAvgValueCount{};

  for (int i = 0; i < inputCount; i++) {
    if (inputDonation[i] > avg) {
      overAvgValueCount++;
    }
  }

  cout << "Donations's avg : " << avg << '\n';
  cout << "over average count : " << overAvgValueCount << '\n';


  return 0;
}
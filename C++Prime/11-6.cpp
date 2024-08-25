#include <iostream>
using std::cout;
using std::cin;
#include "11-6.h"

void display(const Stonewt& stonewtRef, int count);

int main(void) {

  Stonewt stoneArr[6]{ 120, {10, 2}, 200};
  double tmpInputPound{};
  for (int i = 3; i < 6; i++) {
    cout << "enter the pounds : ";
    cin >> tmpInputPound;

    stoneArr[i] = Stonewt(tmpInputPound);
  }

  Stonewt tmpMaxStone = stoneArr[0];
  Stonewt tmpMinStone = stoneArr[1];
  Stonewt elevenStone = Stonewt(11, 0);
  int overElevenCount{};

  for (int i = 0; i < 6; i++) {
    tmpMaxStone = stoneArr[i] > tmpMaxStone ? stoneArr[i] : tmpMaxStone;
    tmpMinStone = stoneArr[i] < tmpMinStone ? stoneArr[i] : tmpMinStone;
    if (stoneArr[i] > elevenStone)
      overElevenCount++;
  }

  cout << "max stone : " << tmpMaxStone;
  cout << "min stone : " << tmpMinStone;
  cout << "over eleven stone count : " << overElevenCount;

  return 0;
}

void display(const Stonewt& stonewtRef, int count) {
  for (int i = 0; i < count; i++) {
    cout << "Wow! " << stonewtRef;
  }
}
#include <iostream>

using std::cout;

#include "11-5.h"

Stonewt::Stonewt(double inputLbs) { ///lbs인경우 constructor
  stone = int(inputLbs) / STONE_TO_LBS;
  pds_left = int(inputLbs) % STONE_TO_LBS + inputLbs - int(inputLbs); ///pound 나머지 + pound 소수부
  pounds = inputLbs;
  method = POUND_DOUBLE_FORM;
}

Stonewt::Stonewt(int inputStone, double inputLbs) { ///stn, lbs인 경우 constructor
  stone = inputStone;
  pds_left = inputLbs;
  pounds = inputStone * STONE_TO_LBS + inputLbs;
  method = STONE_FORM;
}

Stonewt::Stonewt() {
  stone = pounds = pds_left = 0;
  method = STONE_FORM;
}

Stonewt::~Stonewt() {

}

//void Stonewt::show_stn() const {
//  cout << stone << "stone, " << pds_left << "pound\n";
//}
//
//void Stonewt::show_lbs() const {
//  cout << pounds << "pound" << '\n';
//}

std::ostream& operator<<(std::ostream& osRef, const Stonewt& stonewtRef) {
  if (stonewtRef.method == Stonewt::STONE_FORM) {
    osRef << stonewtRef.stone << "stone, " << stonewtRef.pds_left << "pound\n";
  }
  else if (stonewtRef.method == Stonewt::POUND_INT_FORM) {
    osRef << int(stonewtRef.pounds) << "pound" << '\n';
  }
  else if (stonewtRef.method == Stonewt::POUND_DOUBLE_FORM) {
    osRef << stonewtRef.pounds << "pound" << '\n';    
  }
  else {
    std::cout << "invalid method type!" << '\n';
  }

  return osRef;
}

Stonewt Stonewt::operator+(const Stonewt& stonewtRef) const {
  Stonewt sum(pounds + stonewtRef.pounds);
  return sum;
}
Stonewt Stonewt::operator-(const Stonewt& stonewtRef) const {
  Stonewt sub(pounds - stonewtRef.pounds);
  return sub;
}
Stonewt Stonewt::operator*(int inputN) const {
  Stonewt mul(pounds * inputN);
  return mul;
}



Stonewt operator*(int inputN, const Stonewt& stonewtRef) {
  return stonewtRef * inputN;
}
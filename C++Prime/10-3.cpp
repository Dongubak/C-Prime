#include "10-3.h"

int main(void) {

  using namespace std;

  Golf firstCustomer; ///using default constructor
  Golf secondCustomer{ "Sanchez", 30 }; ///using explicit constructor

  firstCustomer.showGolf();
  secondCustomer.showGolf();

  secondCustomer.setGolf();
  secondCustomer.showGolf();

  firstCustomer.setHandicap(50);
  firstCustomer.showGolf();

  return 0;
}

//const int Len = 40;
//struct golf {
//  char fullname[Len];
//  int handicap;
//};
//
//void setgolf(golf& GolfStructReference, const char* inputName, int inputHandicap);
//int setgolf(golf& GolfStructReference);
//
//void handicap(golf& GolfStructReference, int inputHandicap);
//
//void showgolf(const golf& GolfStructReference);
#include "10-7.h"

int main(void) {

  using namespace std;
  
  Plorg p1 = {"Jaspers"};
  p1.getInfo();

  Plorg p2;
  p2.getInfo();

  p1.setCI(80);
  p1.getInfo();

  return 0;
}
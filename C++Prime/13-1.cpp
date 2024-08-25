#include <iostream>

using namespace std;
#include "13-1.h"
void Bravo(const Cd& disk);

int main(void) {

  Cd c1("Beatles", "Capitol", 14, 35.5); ///Cd constructor
  Classic c2 = Classic("Piano Sonata in B flat, Fantasia in c", "Alfred Brendel", "Philips", 2, 57.17);

  Cd* pcd = &c1;

  cout << "using object directly" << '\n';
  c1.getInfo();
  c2.getInfo();

  cout << "using pointer to Cd object" << '\n';
  pcd->getInfo();
  pcd = &c2;
  pcd->getInfo();

  cout << "using reference to Cd Object" << '\n';
  Bravo(c1);
  Bravo(c2);

  cout << "testing assignment" << '\n';
  Classic copy;
  copy = c2;
  copy.getInfo();


  return 0;
}

void Bravo(const Cd& disk) {
  disk.getInfo();
}
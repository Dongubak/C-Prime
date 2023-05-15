#include <iostream>
#include "10-1.h"

int main(void) {

  using namespace std;

  Account customer { "Jaspers", "10204-2424", 1000 };

  customer.withdraw(10000);
  customer.deposit(300000);
  customer.withdraw(20000);
  customer.getInfo();

  return 0;
}
#include <iostream>
#include "10-2.h"

int main(void) {

  Person one;                //using default constructor
  Person two("Smythecraft"); //using implicit constructor, default parameter
  Person three("Dimwiddy", "Sam");

  one.getFullName();
  one.getFullNameFormally();
  
  std::cout << "---------------" << '\n';

  two.getFullName();
  two.getFullNameFormally();

  std::cout << "---------------" << '\n';
  three.getFullName();
  three.getFullNameFormally();
  

  return 0;
}

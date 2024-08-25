#include <iostream>

using namespace std;

#include "11-7.h"
int main(void) {

  Complex a(3.0, 4.0);
  Complex c{};

  cout << "enter a complex number(q to quit) : \n";
  while (cin >> c) {
    cout << "c is " << c << '\n';
    cout << "complex conjugate is " << ~c << '\n';
    cout << "a is " << a << '\n';
    cout << "a + c is " << a + c;
    cout << "a - c is " << a - c;
    cout << "a * c is " << a * c;
    cout << "2 * c is " << 2 * c;
    cout << "enter a complex number(q to quit): \n";
  }

  cout << "Done!\n";

  return 0;
}
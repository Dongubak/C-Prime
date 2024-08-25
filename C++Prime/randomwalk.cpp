#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"

int main(void) {

  using namespace std;
  using VECTOR::Vector;
  srand(time(0));
  double direction = 0.0;
  Vector step{}; ///total step count
  Vector result{};
  unsigned long steps = 0;
  double target; ///input distance
  double dstep;  ///input distance per step
  cout << "enter the distance : ";
  while (cin >> target) {
    cout << "enter the distance per step : ";
    if (!(cin >> dstep)) {
      break;
    }

    while (result.magval() < target) {
      direction = rand() % 360;
      step.reset(dstep, direction, Vector::POL);
      result = result + step;
      steps++;
    }
    cout << steps << "after stepping -> current position\n";
    cout << result << '\n';

    result.polar_mode();
    cout << "or " << result << '\n';

    steps = 0.0;
    result.reset(0.0, 0.0);
    cout << "enter the distance : ";
  }

  cout << "end program" << '\n';
  cin.clear();
  while (cin.get() != '\n') {
    continue;
  }

  return 0;
}


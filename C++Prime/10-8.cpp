#include "10-8.h"

int main() {

  Stack<int> s1;
  s1.push(1);
  s1.push(2);

  s1.getDatas();
  s1.functionPointerCall(sum);

  Stack<double> s2;
  s2.push(2.4);
  s2.push(1.2);
  s2.push(3.6);
  s2.push(3.4);
  s2.getDatas();


  double popData2{};
  s2.pop(popData2);
  s2.getDatas();
  s2.functionPointerCall(sort);
  s2.getDatas();

  return 0;
}
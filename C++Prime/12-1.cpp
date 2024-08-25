#include "12-1.h"

int main(void) {

  Cow c1{ "Jaspers", "walk", 6 };
  Cow c2{};

  c2 = c1;

  c2.ShowCow();

  return 0;
}
#include "10-6.h"

int main(void) {

  Move fly{ 1, 1 };
  Move bee{ 10, 10 };

  fly.showmove();
  bee.showmove();

  fly = fly.add(bee);
  fly.showmove();

  fly.reset(1, 1);
  fly.showmove();

  return 0;
}
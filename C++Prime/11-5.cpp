#include <iostream>
using std::cout;

#include "11-5.h"

void display(const Stonewt& stonewtRef, int count);

int main(void) {

  Stonewt incognito = 275;
  Stonewt wolfe(285.7);
  Stonewt taft(21, 8);


  incognito.formToggleToStoneForm();
  cout << "The celebrity weighed : " << incognito;
  /*incognito.show_stn();*/

  wolfe.formToggleToStoneForm();
  cout << "The detective weighed : " << wolfe;
  /*wolfe.show_stn();*/

  taft.formToggleToPoundDoubleForm();
  cout << "The President weighed : " << taft;
  /*taft.show_lbs();*/

  incognito = 276.8;
  taft = 325;

  incognito.formToggleToStoneForm();
  cout << "After dinner, the celebrity weighed : " << incognito;
  /*incognito.show_stn();*/
  
  taft.formToggleToPoundDoubleForm();
  cout << "After dinner, the President weighed : " << taft;
  /*taft.show_lbs();*/

  display(taft, 2);

  cout << "The wrestler weighed even more.\n";
  display(422, 2);

  Stonewt sum{};
  Stonewt sub{};
  Stonewt mul{};

  sum = incognito + wolfe;
  sub = incognito - taft;
  mul = wolfe * 3;

  sum.formToggleToStoneForm();
  cout << "sum weighed : " << sum;

  sub.formToggleToStoneForm();
  cout << "sub weighed : " << sub;

  mul.formToggleToPoundDoubleForm();
  cout << "mul weighed : " << mul;

  cout << "No stone left unearned\n";
  
  return 0;
}

void display(const Stonewt& stonewtRef, int count) {
  for (int i = 0; i < count; i++) {
    cout << "Wow! " << stonewtRef;
  }
}
#include <iostream>
#include "13-1.h"

int main(void) {

  using std::cout;
  using std::endl;

  TableTannisPlayer player1("Tara", "Boomdea", false);
  RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
  rplayer1.getName();
  if (rplayer1.IsHasTable()) {
    cout << ": has table" << '\n';
  }
  else {
    cout << ": hasn't table" << '\n';
  }

  cout << "name : ";
  rplayer1.getName();
  cout << "; rate : " << rplayer1.getRate() << '\n';

  RatedPlayer rplayer2(1212, player1);
  cout << "name : ";
  rplayer2.getName();
  cout << "; rate : " << rplayer2.getRate() << '\n';
  
}
#include <iostream>

const int Len = 40;

struct golf {
  char fullname[Len];
  int handicap;
};

void setgolf(golf& GolfStructReference, const char* inputName, int inputHandicap);
int setgolf(golf& GolfStructReference);

void setHandicap(golf& GolfStructReference, int inputHandicap);

void showgolf(const golf& GolfStructReference);


int main(void) {

  using namespace std;
 
  golf ann{};
  setgolf(ann, "Ann Birdfree", 24);
  showgolf(ann);

  setHandicap(ann, 30);
  showgolf(ann);

  golf andy{};
  setgolf(andy);
  showgolf(andy);

  return 0;
}

//const int Len = 40;
//struct golf {
//  char fullname[Len];
//  int handicap;
//};
//
//void setgolf(golf& GolfStructReference, const char* inputName, int inputHandicap);
//int setgolf(golf& GolfStructReference);
//
//void handicap(golf& GolfStructReference, int inputHandicap);
//
//void showgolf(const golf& GolfStructReference);
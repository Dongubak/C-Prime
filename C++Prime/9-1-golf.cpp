#include <iostream>
#include <cstring>
#pragma warning(disable: 4996)

const int Len = 40;
struct golf {
  char fullname[Len];
  int handicap;
};

void setgolf(golf& GolfStructReference, const char* inputName, int inputHandicap);
int setgolf(golf& GolfStructReference);

void setHandicap(golf& GolfStructReference, int inputHandicap);

void showgolf(const golf& GolfStructReference);

void setgolf(golf& GolfStructReference, const char* inputName, int inputHandicap) {
  strcpy(GolfStructReference.fullname, inputName);
  GolfStructReference.handicap = inputHandicap;
}

int setgolf(golf& GolfStructReference) {
  using std::cin;
  using std::cout;
  int isValidInput = true;

  cout << "enter the fullname : ";

  if (!(cin >> GolfStructReference.fullname) || GolfStructReference.fullname[0] == '\0') {
    isValidInput = false;
  }
  else {
    cout << "enter the handicap : ";
    cin >> GolfStructReference.handicap;

    while (cin.get() != '\n') {
      continue;
    }
  }
  
  return isValidInput;
}

void setHandicap(golf& GolfStructReference, int inputHandicap) {
  GolfStructReference.handicap = inputHandicap;
}

void showgolf(const golf& GolfStructReference) {
  using std::cout;
  using std::cin;

  cout << "--show golf--" << '\n';

  cout << "fullname : " << GolfStructReference.fullname << '\n';
  cout << "handicap : " << GolfStructReference.handicap << '\n';
}
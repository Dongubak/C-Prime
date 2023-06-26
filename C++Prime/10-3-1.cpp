#include "10-3.h"
#pragma warning(disable: 4996)

Golf::Golf() {
  std::cout << "default constructor" << '\n';
  while (!(golfUtil::setgolf(m_golf))) {
    continue;
  }
} ///default constructor

Golf::Golf(const char* inputName, int inputHandicap) {
  golfUtil::setgolf(m_golf, inputName, inputHandicap);
} ///explicit constructor

void Golf::showGolf(void) {
  golfUtil::showgolf(m_golf);
}

Golf Golf::setGolf(void) {
  Golf tmpGolfInsatance = Golf("annonymous", 0);
  golfUtil::setgolf(tmpGolfInsatance.m_golf);
  return (*this = tmpGolfInsatance);
}


void Golf::setHandicap(int inputHandicap) {
  golfUtil::setHandicap(m_golf, inputHandicap);
}


///golfUtil namespace function definition
void golfUtil::setgolf(golf& GolfStructReference, const char* inputName, int inputHandicap) {
  strcpy(GolfStructReference.fullname, inputName);
  GolfStructReference.handicap = inputHandicap;
} ///default constructor

int golfUtil::setgolf(golf& GolfStructReference) {
  using std::cin;
  using std::cout;
  int isValidInput = true;

  cout << "enter the fullname : ";

  if (!(cin >> GolfStructReference.fullname) || GolfStructReference.fullname[0] == '\0') {
    isValidInput = false;
  }
  else {
    cout << "enter the handicap : ";
    if (!(cin >> GolfStructReference.handicap)) {
      cin.clear();
      isValidInput = false;
    } ///invalid input case 
    while (cin.get() != '\n') {
      continue;
    } ///valid input case or invalid input case
  }

  return isValidInput;
}

void golfUtil::setHandicap(golf& GolfStructReference, int inputHandicap) {
  GolfStructReference.handicap = inputHandicap;
}

void golfUtil::showgolf(const golf& GolfStructReference) {
  using std::cout;
  using std::cin;

  cout << "--show golf--" << '\n';

  cout << "fullname : " << GolfStructReference.fullname << '\n';
  cout << "handicap : " << GolfStructReference.handicap << '\n';
}
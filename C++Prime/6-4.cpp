#include <iostream>

const int elementCount = 3;

struct bop {
  char fullname[20];
  char title[20];
  char bopname[20];
  int preference;
};

void displayInfo(bop* pt, char mode, int elementCount);

using namespace std;

int main(void) {

  bop memberList[elementCount] = {
    {"Wimp Macho", "a", "A", 0},
    {"Raki Rhodes", "b", "B", 1},
    {"Celia Laiter", "c", "C", 2}
  };

  cout << "Benevolent Order of Programmers\n"
    "a. fullName      b. title\n"
    "c. bopname       d. preference\n";

  char tmpInputChar{};
  cout << "enter the char : ";
  while (cin >> tmpInputChar && tmpInputChar != 'q') {
    displayInfo(memberList, tmpInputChar, elementCount);
    cout << "enter the char : ";
  }

  return 0;
}

void displayInfo(bop* pt, char mode, int elementCount)
{
  switch (mode) {
  case 'a':
    for (int i = 0; i < elementCount; i++) {
      cout << pt[i].fullname << '\n';
    }
    break;
  case 'b':
    for (int i = 0; i < elementCount; i++) {
      cout << pt[i].title << '\n';
    }
    break;
  case 'c':
    for (int i = 0; i < elementCount; i++) {
      cout << pt[i].bopname << '\n';
    }
    break;
  case 'd':
    for (int i = 0; i < elementCount; i++) {
      switch (pt[i].preference) {
      case 0:
        cout << pt[i].fullname << '\n';
        break;
      case 1:
        cout << pt[i].title << '\n';
        break;
      case 2:
        cout << pt[i].bopname << '\n';
        break;
      }
    }
    break;
  }

}

#include <iostream>

bool isValidInput(char inputChar) {
  bool returnBool = false;
  switch (inputChar) {
    case 'c':
    case 'p':
    case 'j':
    case 'g':
    case 'q':
      returnBool = true;
      break;
  }

  return returnBool;
}

int main(void) {

  using namespace std;

  cout << "chooseOne (end : q) : \n"
    "c) C language      p) Python\n"
    "j) JavaScript      g) Golang\n";

  char tmpInputChar{};

  while (!(cin >> tmpInputChar) || !isValidInput(tmpInputChar)) {
    cin.clear();
    cout << "enter only c, p, j, g (end : q) : ";
    while (cin.get() != '\n') {
      continue;
    }
  }

  if (tmpInputChar != 'q') {
    switch (tmpInputChar) {
      case 'c':
        cout << "C is hard!";
        break;
      case 'p':
        cout << "Python is powerful";
        break;
      case 'j':
        cout << "JS is god!";
        break;
      case 'g':
        cout << "Who are you?";
        break;
    }
  }
  else {
    cout << "QUIT";
  }


  return 0;
}
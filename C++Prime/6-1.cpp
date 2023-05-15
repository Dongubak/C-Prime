#include <iostream>
#include <cctype>

int main(void) {

  using namespace std;

  char tmpInputChar{};

  cout << "enter any data :  ";

  while (cin.get(tmpInputChar) && tmpInputChar != '@') {
    if (!isalpha(tmpInputChar)) {
      continue;
    }
    else {
      tmpInputChar = isupper(tmpInputChar) ? tolower(tmpInputChar) : toupper(tmpInputChar);
      cout << tmpInputChar;
    }
  }

  return 0;
}
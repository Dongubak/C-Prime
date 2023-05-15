#include <iostream>
#include <cstring>

int main(void) {
  using namespace std;

  char inputChar[20];
  int wordCount = 0;

  cout << "enter the words (end : done) : ";

  cin >> inputChar;
  while (strcmp(inputChar, "done") != 0) {

    wordCount += 1;
    cin >> inputChar;
  }

  cout << "word count : " << wordCount;

  return 0;
}
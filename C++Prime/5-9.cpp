#include <iostream>
#include <cstring>

int main(void) {
  using namespace std;

  string inputString;
  int wordCount = 0;

  cout << "enter the words (end : done) : ";

  cin >> inputString;
  while (inputString != "done") {

    wordCount += 1;
    cin >> inputString;
  }

  cout << "word count : " << wordCount;

  return 0;
}
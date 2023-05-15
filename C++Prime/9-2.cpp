#include <iostream>
#include <string>

const int ArSize = 10;

void strcount(std::string &sourceString);

int main(void) {

  using namespace std;

  string inputString{};

  cout << "enter the line string(english) : ";
  
  while (getline(cin, inputString) && inputString != "") {
    strcount(inputString);
    cout << "enter the line string(english) : ";
  }
  cout << "end";

  return 0;
}

void strcount(std::string & sourceString) {
  using namespace std;
  static int total = 0;
  int count = 0;

  cout << "\"" << sourceString << "\"에는";
  count = sourceString.size();
  total += count;
  cout << count << "개의 문자가 있습니다.\n";
  cout << "지금까지 총 " << total << "개의 문자를 입력하셨습니다.\n";
}
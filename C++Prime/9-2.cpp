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

  cout << "\"" << sourceString << "\"����";
  count = sourceString.size();
  total += count;
  cout << count << "���� ���ڰ� �ֽ��ϴ�.\n";
  cout << "���ݱ��� �� " << total << "���� ���ڸ� �Է��ϼ̽��ϴ�.\n";
}
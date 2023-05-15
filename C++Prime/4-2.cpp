#include <iostream>
#include <fstream>
#include <string>

int main(void) {
  using namespace std;

  ifstream in;

  in.open("6-8.txt");

  if (!in.is_open()) {
    exit(EXIT_FAILURE);
  }

  char tmpInputChar{};
  int charCount{};

  while (in >> tmpInputChar) {
    charCount += 1;
  }

  cout << "ch count : " << charCount;
  in.close();

  return 0;
}
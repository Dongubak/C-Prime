#include <iostream>

void printString(const char* stringPointer, int trigger = 0);

int main(void) {

  using namespace std;

  const char* exString = "hello, world!";

  printString(exString);
  printString(exString, 0);
  printString(exString, 4);

  return 0;
}

void printString(const char* stringPointer, int trigger)
{
  static int callingCount{};

  int iterCount{};
  iterCount = trigger == 0 ? 1 : callingCount;

  for (int i = 0; i < iterCount; i++) {
    std::cout << stringPointer;
  }
  std::cout << " , calling Count : " << callingCount;
  std::cout << '\n';

  callingCount++;
}

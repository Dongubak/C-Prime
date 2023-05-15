#include <iostream>
#pragma warning(disable: 4996)
using namespace std;
#include <cstring>

struct stringy {
  char* inputString;
  int stringCount;
};

void setData(stringy& referBeany, const char* sourceString);

void displayData(stringy& referBeany, int printCount = 1);
void displayData(const char* stringPointer, int printCount = 1);


int main(void) {

  stringy beany;
  char exString[] = "Reality isn't what it used to be.";

  setData(beany, exString);

  
  displayData(beany);
  displayData(beany, 2);

  exString[0] = 'D';
  exString[1] = 'u';
  
  displayData(exString);
  displayData(exString, 3);
  displayData("Done!");

  return 0;
}

void setData(stringy& referBeany, const char* sourceString)
{
  size_t sourceStringLength = sizeof(sourceString);
  referBeany.inputString = new char[sourceStringLength];

  strcpy(referBeany.inputString, sourceString);
}

void displayData(stringy& referBeany, int printCount)
{
  cout << "------------------" << '\n';
  for (int i = 0; i < printCount; i++) {
    cout << referBeany.inputString << '\n';
  }
  cout << "------------------" << '\n';
}

void displayData(const char* stringPointer, int printCount)
{
  cout << "------------------" << '\n';
  for (int i = 0; i < printCount; i++) {
    cout << stringPointer << '\n';
  }
  cout << "------------------" << '\n';
}

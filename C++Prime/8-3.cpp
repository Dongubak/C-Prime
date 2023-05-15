#include <iostream>
#include <string>
#include <cstring>

bool isValidInput(std::string& inputString);
void convertStringToUpperAndPrint(std::string& inputString);

int main(void) {

  using namespace std;
  string inputString{};

  while (isValidInput(inputString)) {
    convertStringToUpperAndPrint(inputString);
  }

  cout << "end";

  return 0;
}

bool isValidInput(std::string& inputString)
{
  bool isValidInput = true;

  std::cout << "enter the string(end q) : ";
  if (!(getline(std::cin, inputString)) || inputString == "q") {
    isValidInput = false;
  }

  return isValidInput;
}

void convertStringToUpperAndPrint(std::string& inputString)
{
  for (int i = 0; i < inputString.size(); i++) {
    inputString[i] = isalpha(inputString[i]) ? toupper(inputString[i]) : inputString[i];
  }

  std::cout << inputString << '\n';
}
#include <iostream>
#define buf 128

void clearBuf(void) {
  while (std::cin.get() != '\n') {
    continue;
  }
}

bool setData(char* ptToString)
{
  bool isValidInput = true;

  if (!(std::cin >> ptToString, buf)) {
    isValidInput = false;
  }

  std::cin.clear();
  clearBuf();

  return isValidInput;
}

bool setData(int* ptToInt)
{
  bool isValidInput = true;
  if (!(std::cin >> *ptToInt)) {
    isValidInput = false;
  }

  std::cin.clear();
  clearBuf();

  return isValidInput;
}

void setTmpBaseData(char* ptToLabel, int* ptToRating)
{
  std::cout << "enter the label : ";
  while (!setData(ptToLabel)) {
    std::cout << "invalid data!, enter correct data : ";
  }

  std::cout << "enter the rating : ";
  while (!setData(ptToRating)) {
    std::cout << "invalid data!, enter correct data : ";
  }
}


void setType(int* ptToType)
{
  std::cout << "if you want baseDMA, enter 1 or you want lacksDMA, enter 2 : ";
  while (!setData(ptToType)) {
    std::cout << "invalid data!, enter correct data : ";
  }
}

void setColor(char* ptToColor)
{
  std::cout << "enter the color : ";
  while (!setData(ptToColor)) {
    std::cout << "invalid data!, enter correct data : ";
  }
}

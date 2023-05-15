#include <iostream>
#include <cstring>
#pragma warning(disable: 4996)

int main(void) {

  using namespace std;

  char firstName[20], lastName[20];

  cout << "enter your first name : ";
  cin.get(firstName, 20).get();

  cout << "enter your last name : ";
  cin.get(lastName, 20).get();

  char* pt = new char[strlen(firstName) + strlen(lastName) + 1 + 2];

  strcpy(pt, firstName);
  strncat(pt, ", ", 2);
  strcat(pt, lastName);

  cout << pt;

  delete[]pt;
  

  return 0;
}
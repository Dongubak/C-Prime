#include <iostream>
#include <string>
#pragma warning(disable: 4996)

int main(void) {

  using namespace std;

  string firstName, lastName, fullName;

  cout << "enter your first name : ";
  getline(cin, firstName);

  cout << "enter your last name : ";
  getline(cin, lastName);

  fullName = firstName + ", " + lastName;

  cout << "merge : " << fullName;

  return 0;
}
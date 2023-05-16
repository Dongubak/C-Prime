#include <iostream>

class Person {
private:
  static int const LIMIT = 25;
  std::string m_lastName;
  char m_fullName[LIMIT];

public:
  Person() {
    m_lastName = "";
    m_fullName[0] = '\0';
  } //default constructor

  Person(const std::string& lastName, const char* fullName = "Heyyou");
  //explicit constructor
  void getFullName() const;
  void getFullNameFormally() const;
};

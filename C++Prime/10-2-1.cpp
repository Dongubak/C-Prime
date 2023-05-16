#include <iostream>
#include <cstring>
#pragma warning(disable :4996)
#include "10-2.h"

Person::Person(const std::string& lastName, const char* fullName)
{
  m_lastName = lastName; //lastName is string class instance
  strcpy(m_fullName, fullName); //default parameter is "Heyyou"
}

void Person::getFullName() const {
  std::cout << m_fullName << " " << m_lastName << '\n';
    
}
void Person::getFullNameFormally() const {
  std::cout << m_fullName << ", " << m_lastName << '\n';
}

#include "10-7.h"

Plorg::Plorg() { ///default constructor
  strcpy(m_name, "Plorga");
  m_contentmentIndex = 50;
}

Plorg::Plorg(const char* inputName) { ///explicit constructor
  if (strlen(inputName) > 19) {
    std::cout << "input name overflowed, set default" << '\n';
    Plorg tmpInstance;
    *this = tmpInstance;
  }
  else {
    strcpy(m_name, inputName);
    m_contentmentIndex = 50;
  }
}


void Plorg::getInfo() {
  std::cout << "Plorg name : " << m_name << '\n';
  std::cout << "Plorg CI(contentment index) : " << m_contentmentIndex << '\n';
}

void Plorg::setCI(int inputContentmentIndex) {
  m_contentmentIndex = inputContentmentIndex;
}
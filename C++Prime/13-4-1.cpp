#include "13-4.h"
#include <iostream>
#include <cstring>

Port::Port(const char* inputBrandName, const char* inputStyle, int inputBottles) {
  brand = new char[strlen(inputBrandName) + 1];
  strcpy(brand, inputStyle);
  strcpy(style, inputStyle);
  bottles = inputBottles;
}

Port::Port(const Port& portRef) {
  delete[] brand;
  brand = new char[strlen(portRef.brand) + 1];
  strcpy(brand, portRef.brand);
  strcpy(style, portRef.style);
  bottles = portRef.bottles;
}

Port& Port::operator=(const Port& portRef) {
  if (this == &portRef) {
    return *this;
  }

  delete[] brand;
  brand = new char[strlen(portRef.brand) + 1];
  strcpy(brand, portRef.brand);
  strcpy(style, portRef.style);
  bottles = portRef.bottles;

  return *this;
}
Port& Port::operator+=(int b) {
  bottles += b;
}
Port& Port::operator-=(int b) {
  bottles -= b;
}

ostream& operator<<(ostream& osRef, Port& portRef) {
  osRef << portRef.brand << ", " << portRef.style << ", " << portRef.bottles;
}

void Port::getInfo() const {
  std::cout << "brand : " << brand << '\n';
  std::cout << "style : " << style << '\n';
  std::cout << "bottles : " << bottles << '\n';
}

VintagePort::VintagePort() : Port() {
  char defaultString[] = "none";
  nickname = new char[strlen(defaultString) + 1];
  strcpy(nickname, defaultString);

  year = 0;
}

VintagePort::VintagePort(const char* inputBandName, int bottles, const char* inputNickName, int inputYear) : Port(inputBandName, bottles) {
  nickname = new char[strlen(inputNickName) + 1];
  strcpy(nickname, inputNickName);
  year = inputYear;
}

//  VintagePort& operator=(const VintagePort& vintageRef);
//  void getInfo() const;
//  friend ostream& operator<<(ostream& osRef, const VintagePort& vintageRef);

VintagePort& VintagePort::operator=(const VintagePort& vintageRef) {
  if (this == &vintageRef) {
    return *this;
  }

  Port::operator=(vintageRef);
  delete[] nickname;
  nickname = new char[strlen(vintageRef.nickname) + 1];
  strcpy(nickname, vintageRef.nickname);

  year = vintageRef.year;

  return *this;
}

void VintagePort::getInfo() const {
  Port::getInfo();
  std::cout << nickname << ", " << year;
}

ostream& operator<<(ostream& osRef, const VintagePort& vintageRef) {
  osRef << (Port&)vintageRef;
  osRef << "nickname : " << vintageRef.nickname << '\n';
  osRef << "year : " << vintageRef.year << '\n';
}
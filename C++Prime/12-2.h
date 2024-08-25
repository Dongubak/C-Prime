#ifndef STRING_H_
#define STRING_H_
#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>
#include <cctype>

using std::ostream;
using std::istream;

class String {
private:
  char* string;
  int stringLength;
  static int stringsCount;
  static const int CONSOLE_IN_LIMIT = 80;

public:
  String(const char* inputString);
  String();
  String(const String& stringRef);
  ~String();

  int length() const { return stringLength; }
  void stringToUpperCase(void);
  void stringToLowerCase(void);
  int getCount(char inputChar);


  String& operator=(const String& stringRef);
  String& operator=(const char* inputString);
  char& operator[] (int inputIndex);
  const char& operator[](int inputIndex) const;
  String operator+(const String& stringRef);

  friend bool operator<(const String& firstRef, const String& secondRef);
  friend bool operator>(const String& firstRef, const String& secondRef);
  friend bool operator==(const String& firstRef, const String& secondRef);

  friend ostream& operator<<(ostream& osRef, const String& stringRef);
  friend istream& operator>>(istream& isRef, String& stringRef);
  friend String operator+(const char* inputString, const String& stringRef);
  static int getStringsCount();
};

#endif // !STRING_H_

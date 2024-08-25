#include "12-2.h"

int String::stringsCount = 0;

int String::getStringsCount() {
  return stringsCount;
}

///construct String from c string
String::String(const char* inputString) {
  string = new char[strlen(inputString) + 1];
  strcpy(string, inputString);
  stringsCount++;
  stringLength = strlen(inputString);
}

///default constructor
String::String() {
  stringLength = 0;
  string = new char[1];
  string[0] = '\0';
  stringsCount++;
}

///copy constructor
String::String(const String& stringRef) {
  stringsCount++;
  stringLength = stringRef.stringLength;
  string = new char[strlen(stringRef.string) + 1];
  strcpy(string, stringRef.string);
}

///destructor
String::~String() {
  stringsCount--;
  delete[] string;
}
String& String::operator=(const String& stringRef) {
  if (this == &stringRef) {
    return *this;
  }

  stringLength = stringRef.stringLength;
  string = new char[strlen(stringRef.string) + 1];
  strcpy(string, stringRef.string);

  return *this;
}


///assign a C string to a String
String& String::operator=(const char* inputString) {
  delete[] string;
  string = new char[strlen(inputString) + 1];
  strcpy(string, inputString);
  return *this;
}
char& String::operator[] (int inputIndex) {
  return string[inputIndex];
}
const char& String::operator[](int inputIndex) const {
  return string[inputIndex];
}

String String::operator+(const String& stringRef)
{
  char* pointerToMergeString = new char[strlen(string) + strlen(stringRef.string) + 1];
  strcpy(pointerToMergeString, string);
  strcat(pointerToMergeString, stringRef.string);

  String mergedStringRef = pointerToMergeString;

  return mergedStringRef;
}

bool operator<(const String& firstRef, const String& secondRef) {
  return strcmp(firstRef.string, secondRef.string) < 0;
}
bool operator>(const String& firstRef, const String& secondRef) {
  return secondRef < firstRef;
}
bool operator==(const String& firstRef, const String& secondRef) {
  return strcmp(firstRef.string, secondRef.string) == 0;
}

ostream& operator<<(ostream& osRef, const String& stringRef) {
  osRef << stringRef.string;
  return osRef;
}
istream& operator>>(istream& isRef, String& stringRef) {
  char tmpInputString[String::CONSOLE_IN_LIMIT]{};
  isRef.get(tmpInputString, String::CONSOLE_IN_LIMIT);

  if (isRef) {
    stringRef = tmpInputString; ///call assignment operator
  }

  while (isRef && isRef.get() != '\n') {
    continue;
  }

  return isRef;
}

String operator+(const char* inputString, const String& stringRef)
{
  char* pointerToMergeString = new char[strlen(inputString) + strlen(stringRef.string) + 1];
  strcpy(pointerToMergeString, inputString);
  strcat(pointerToMergeString, stringRef.string);

  String mergedStringRef = pointerToMergeString;
  return mergedStringRef;
}

void String::stringToUpperCase() {
  for (int i = 0; i < stringLength; i++) {
    if (isalpha(string[i])) {
      string[i] = toupper(string[i]);
    }
  }
}

void String::stringToLowerCase(void) {
  for (int i = 0; i < stringLength; i++) {
    if (isalpha(string[i])) {
      string[i] = tolower(string[i]);
    }
  }
}

int String::getCount(char inputChar) {

  int charCount{};

  for (int i = 0; i < stringLength; i++) {
    if (string[i] == inputChar) {
      charCount++;
    }
  }

  return charCount;
}
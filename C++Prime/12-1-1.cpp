#include "12-1.h"

//char name[20];
//char* hobby;
//double weight;

Cow::Cow() {
  strcpy(name, "");

  hobby = new char[1];
  hobby[0] = '\0';

  weight = 0;
}///default constructor
Cow::Cow(const char* inputName, const char* inputHobby, double inputWeight) {
  strcpy(name, inputName);
  
  hobby = new char[strlen(inputHobby) + 1];
  strcpy(hobby, inputHobby);

  weight = inputWeight;
}
Cow::Cow(const Cow& c) {
  strcpy(name, c.name);

  hobby = new char[strlen(c.name) + 1];
  strcpy(hobby, c.hobby);

  weight = c.weight;
}
///copy constructor
Cow::~Cow() {
  delete[] hobby;
} ///destructor
Cow& Cow::operator=(const Cow& c) {
  if (this == &c) {
    return *this;
  }
  
  delete[] hobby;
  strcpy(name, c.name);

  hobby = new char[strlen(c.name) + 1];
  strcpy(hobby, c.hobby);

  weight = c.weight;

  return *this;
} ///assignment operator
void Cow::ShowCow() const {
  std::cout << "name : " << name << ", hobby : " << hobby << ", weight : " << weight;
} ///getter
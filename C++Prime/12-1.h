#ifndef COW_H_
#define COW_H_
#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>


class Cow {
private:
  char name[20];
  char* hobby;
  double weight;
public:
  Cow(); ///default constructor
  Cow(const char* inputName, const char* inputHobby, double inputWeight);
  Cow(const Cow& c); ///copy constructor
  ~Cow(); ///destructor
  Cow& operator=(const Cow& c); ///assignment operator
  void ShowCow() const; ///getter
};



#endif // !COW_H_
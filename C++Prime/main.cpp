#include <iostream>

class BaseClass {
protected:
   int sampleIntNum;

public:
  virtual int getSampleNum(void) const;
  BaseClass() {
    sampleIntNum = 0;
  }
};

int BaseClass::getSampleNum(void) const {
  return sampleIntNum;
}

class DerivedClass : BaseClass {
private:
  double sampleDoubleNum;

public:
  DerivedClass(): BaseClass() {
    sampleDoubleNum = 0;
  }
  virtual double getSampleNum(void);

  void getInfo(void) {
    std::cout << "int : " << sampleIntNum << ", double : " << sampleDoubleNum << '\n';
  }
};

double DerivedClass::getSampleNum(void) {
  return sampleDoubleNum;
}

int main(void) {



  return 0;
}
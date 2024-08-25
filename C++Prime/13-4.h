#ifndef PORT_H_
#define PORT_H_
#include <iostream>

using namespace std;

class Port {
private:
  char* brand;
  char style[20];
  int bottles;

public:
  Port(const char* inputBrandName = "none", const char* inputStyle = "none", int inputBottles = 0); ///contructor
  Port(const Port& portRef); ///copy constructor

  int getBottles() const {
    return bottles;
  }

  Port& operator=(const Port& portRef);
  Port& operator+=(int b);
  Port& operator-=(int b);

  virtual ~Port() {
    delete[] brand;
  }
  virtual void getInfo() const;

  friend ostream& operator<<(ostream& osRef, Port& portRef);
};

class VintagePort : public Port {
private:
  char* nickname;
  int year;

public:
  VintagePort();
  VintagePort(const char* inputBandName, int bottles, const char* inputNickName, int inputYear);
  ~VintagePort() {
    delete[] nickname;
  }
  VintagePort& operator=(const VintagePort& vintageRef);
  void getInfo() const;
  friend ostream& operator<<(ostream& osRef, const VintagePort& vintageRef);
};

#endif // !PORT_H_
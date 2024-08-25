#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt {
public:
  enum Method { STONE_FORM, POUND_INT_FORM, POUND_DOUBLE_FORM };

private:
  static const int STONE_TO_LBS = 14;
  int stone;
  double pds_left;
  Method method;
  double pounds;

public:
  Stonewt(double inputLbs);
  Stonewt(int inputStone, double inputLbs);
  Stonewt();
  ~Stonewt();

  void formToggleToStoneForm() {
    method = STONE_FORM;
  }

  void formToggleToPoundIntForm() {
    method = POUND_INT_FORM;
  }

  void formToggleToPoundDoubleForm() {
    method = POUND_DOUBLE_FORM;
  }

  /*void show_lbs() const;
  void show_stn() const;*/

  Stonewt operator+(const Stonewt& stonewtRef) const;
  Stonewt operator-(const Stonewt& stonewtRef) const;
  Stonewt operator*(int inputN) const;

  bool operator<(const Stonewt& stonewtRef) const;
  bool operator>(const Stonewt& stonewtRef) const;
  bool operator<=(const Stonewt& stonewtRef) const;
  bool operator>=(const Stonewt& stonewtRef) const;
  bool operator==(const Stonewt& stonewtRef) const;
  bool operator!=(const Stonewt& stonewtRef) const;

  friend Stonewt operator*(int inputN, const Stonewt& stonewtRef);
  friend std::ostream& operator<<(std::ostream& osRef, const Stonewt& stonewtRef);
};

#endif // !STONEWT_H_
#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt {
private:
  static const int Lbs_per_stn = 14;
  int stone;
  double pds_left;
  double pounds;
public:
  Stonewt(double lbs);
  Stonewt(int stn, double lbs);
  Stonewt(); // defualt constructor
  ~Stonewt(); // destructor
  void show_lbs() const;
  void show_stn() const;
  operator int() const;
  operator double() const;
};

#endif // !STONEWT_H_

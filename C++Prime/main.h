#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock {
private:
  std::string company;
  long shares;
  double share_val;
  double total_val;
  ///definition in class -> default inline method
  void set_tot();

public:
  void acquire(const std::string& co, long n, double pr);
  void buy(long num, double price);
  void sell(long num, double price);
  void update(double price);
  void show();
};

#endif // !STOCK00_H_

#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock {
private:
  std::string company; //회사명
  long shares;         //보유주식수
  double share_val;    //주가
  double total_val;    //주식의 총 가치
  void set_tot() {
    total_val = shares * share_val; //private member function 주식의 총가치를 계산하는 함수
    //이는 public function의 내부 정의에서만 call이 가능하다.
  }

public:
  Stock(); // defualt constructor
  Stock(const const std::string& co, long n = 0, double pr = 0.0); // constructor
  void acquire(const std::string& co, long n, double pr);
  void buy(long num, double price);
  void sell(long num, double price);
  void update(double price);
  void show() const;
  double total() const {
    return total_val;
  } // only read function
  const Stock& top_val(const Stock& s) const;
  ~Stock(); // deconstructor
};

#endif
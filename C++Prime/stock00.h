#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock {
private:
  std::string company; //ȸ���
  long shares;         //�����ֽļ�
  double share_val;    //�ְ�
  double total_val;    //�ֽ��� �� ��ġ
  void set_tot() {
    total_val = shares * share_val; //private member function �ֽ��� �Ѱ�ġ�� ����ϴ� �Լ�
    //�̴� public function�� ���� ���ǿ����� call�� �����ϴ�.
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
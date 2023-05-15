#include <iostream>
#include "stock00.h"

Stock::Stock() { // constructor overriding
  std::cout << "calling default constructor" << '\n';
  company = "no name";
  shares = 0;
  share_val = 0.0;
  total_val = 0.0;
}

Stock::Stock(const std::string& co, long n, double pr) {
  company = co; // public member function �� ���ؼ� private ��� ���� ����

  if (n < 0) {
    std::cout << "cannot minus value, set default 0" << company << "set shares to 0";
    shares = 0;
  }
  else {
    shares = n;
  }
  share_val = pr;
  set_tot();
}

void Stock::acquire(const std::string& co, long n, double pr) {
  company = co; // public member function �� ���ؼ� private ��� ���� ����
  
  if (n < 0) {
    std::cout << "cannot minus value, set default 0" << company << "set shares to 0";
    shares = 0;
  }
  else {
    shares = n;
  }
  share_val = pr;
  set_tot();
}

void Stock::buy(long num, double price) {

  if (num < 0) {
    std::cout << "cannot minus value, " << "cancel trading" << '\n';
  }
  else {
    shares += num;
    share_val = price;
    set_tot();
  }

}

void Stock::sell(long num, double price) {
  using std::cout;

  if (num < 0) {
    cout << "cannt minus value" << "cancel trading" << '\n';
  }
  else if (num > shares) {
    cout << "over your own stock" << "cancel trading" << '\n';
  }
  else {
    shares -= num;  //public function���� private ����� ����
    share_val = price; //public function���� private ����� ����
    set_tot();  //public function���� private function call
  }
}

void Stock::update(double price) {

  share_val = price; //�ְ��� �����ϱ�
                     //public function�� ���� private function�� ȣ��
  set_tot();
}

void Stock::show(void) const {
  using std::cout;
  using std::ios_base;

  ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);

  std::streamsize prec = cout.precision(3);

  std::cout << "company name : " << company << '\n'
    << "stock count : " << shares << '\n'
    << "stock value : " << share_val << '\n';
  cout.precision(2);
  cout << "total stock value : " << total_val << '\n';
  cout.setf(orig, ios_base::floatfield);
  cout.precision(prec);
}

Stock::~Stock() {
  std::cout << "end Stock class" << '\n';
}

const Stock& Stock::top_val(const Stock& s) const {
  if (s.total_val > total_val) {
    return s;
  }
  else {
    return *this; //call object
  }
}

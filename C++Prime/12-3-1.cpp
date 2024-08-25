#include <iostream>
#include "12-3.h"
#pragma warning(disable: 4996)

Stock::Stock() {
  company = new char[1];
  company[0] = '\0';

  shares = 0;
  share_val = 0.0;
  total_val = 0.0;
}
Stock::Stock(const char* co, long n, double pr) {
  company = new char[strlen(co) + 1];
  strcpy(company, co);

  if (n < 0) {
    std::cout << "주식 수는 음수가 될 수 없으므로, " << company << " shares를 0으로 설정합니다.\n";
    shares = 0;
  }
  else {
    shares = n;
  }
  share_val = pr;
  set_tot();
}
Stock::~Stock() {
  delete[] company;
}
void Stock::buy(long num, double price) {
  if (num < 0) {
    std::cout << "매입 주식 수는 음수가 될 수 없으므로, " << "거래가 취소되었습니다.\n";
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
    cout << "매도 주식 수는 음수가 될 수 없으므로, " << "거래가 취소되었습니다.\n";
  }
  else if (num > shares) {
    cout << "보유 주식보다 많은 주식을 매도할 수 없으므로, " << "거래가 취소되었습니다.\n";
  }
  else {
    shares -= num;
    share_val = price;
    set_tot();
  }
}

void Stock::update(double price) {
  share_val = price;
  set_tot();
}
void Stock::show() const {
  using std::cout;
  using std::ios_base;

  ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
  std::streamsize prec = cout.precision(3);

  cout << "회사명 : " << company
    << "주식 수 : " << shares << '\n';

  cout << "주가 : " << share_val;
  cout.precision(2);
  cout << " 주식 총 가치 : $" << total_val << '\n';

  cout.setf(orig, ios_base::floatfield);
  cout.precision(prec);
}
const Stock& Stock::topval(const Stock& s) const {
  if (s.total_val > total_val) {
    return s;
  }
  else {
    return *this;
  }
}

std::ostream& operator<<(std::ostream& osRef, const Stock& stockRef) {
  using std::ios_base;

  ios_base::fmtflags orig = osRef.setf(ios_base::fixed, ios_base::floatfield);
  std::streamsize prec = osRef.precision(3);

  osRef << "회사명 : " << stockRef.company
    << "주식 수 : " << stockRef.shares << '\n';

  osRef << "주가 : " << stockRef.share_val;
  osRef.precision(2);
  osRef << " 주식 총 가치 : $" << stockRef.total_val << '\n';

  osRef.setf(orig, ios_base::floatfield);
  osRef.precision(prec);

  return osRef;
}
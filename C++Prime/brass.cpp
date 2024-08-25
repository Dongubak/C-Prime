#include <iostream>

#include "brass.h"

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const string& inputFullName, long inputAccountNumber, double inputBalance) {
  fullName = inputFullName;
  accountNumber = inputAccountNumber;
  balance = inputBalance;
}

void Brass::deposit(double amount) {
  if (amount < 0) {
    cout << "마이너스 입금은 허용되지 않습니다.\n" << "그래서 입금이 취소되었습니다.\n";
  }
  else {
    balance += amount;
  }
}

void Brass::withdraw(double amount) {
  format initialState = setFormat();
  precis prec = cout.precision(2);

  if (amount < 0) {
    cout << "마이너스 인출은 허용되지 않습니다.\n" << "그래서 인출이 취소되었습니다.\n";
  }
  else if (amount <= balance) {
    balance -= amount;
  }
  else {
    cout << "인출을 요구한 금액 $" << amount
         << "가 현재 잔액을 초과합니다.\n"
         << "그래서 인출이 취소되었습니다.\n";
    restore(initialState, prec);
  }
}

double Brass::getBalance(void) const{
  return balance;
}

void Brass::getInfo(void) const {
  format initialState = setFormat();
  precis prec = cout.precision(2);

  cout << "고객 이름 : " << fullName << '\n';
  cout << "계좌 번호 : " << accountNumber << '\n';
  cout << "현재 잔액 : $" << balance << '\n';

  restore(initialState, prec);
}


BrassPlus::BrassPlus(const string& inputFullName, long inputAccountNumber, double inputBalance,
                     double inputMaxLoan, double inputRate) : Brass(inputFullName, inputAccountNumber, inputBalance) {
  maxLoan = inputMaxLoan;
  owesBank = 0.0;
  rate = inputRate;
}

BrassPlus::BrassPlus(const Brass& inputBrassRef, double inputMaxLoan, double inputRate) : Brass(inputBrassRef) {
  maxLoan = inputMaxLoan;
  owesBank = 0.0;
  rate = inputRate;
}

void BrassPlus::getInfo() const {
  format initialState = setFormat();
  precis prec = cout.precision(2);

  Brass::getInfo();
  cout << "당좌 대월 한도액 : $" << maxLoan << '\n';
  cout << "상환할 원리금 : $" << owesBank << '\n';
  cout.precision(3);
  cout << "당좌 대월 이자율 : " << 100 * rate << "%\n";
  restore(initialState, prec);
}

void BrassPlus::withdraw(double amount) {
  format initialState = setFormat();
  precis prec = cout.precision(2);

  double currentBalance = getBalance();
  if (amount <= currentBalance) {
    Brass::withdraw(amount);
  }
  else if (amount <= (currentBalance + maxLoan - owesBank)) {
    double advance = amount - currentBalance;
    owesBank += advance * (1.0 + rate);
    cout << "당좌 대월 금액 : $" << advance << '\n';
    cout << "당좌 대월 이자 : $" << advance * rate << '\n';
    deposit(advance);
    Brass::withdraw(amount);
  }
  else {
    cout << "당좌 대월 한도가 초과되어 거래가 취소되었습니다.\n";
    restore(initialState, prec);
  }
}

format setFormat() {
  return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p) {
  cout.setf(f, std::ios_base::floatfield);
  cout.precision(p);
}

#include <iostream>
#include "acctabc.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

AccountAbstractBaseClass::AccountAbstractBaseClass(const std::string& inputFullName, long inputAccountNumber,
  double inputBalance) {
  fullName = inputFullName;
  accountNumber = inputAccountNumber;
  balance = inputBalance;
}

void AccountAbstractBaseClass::deposit(double amount) {
  if (amount < 0) {
    cout << "마이너스 입금은 허용되지 않습니다.\n"
      << "그래서 입금이 취소되었습니다.\n";
  }
  else {
    balance += amount;
  }
}

void AccountAbstractBaseClass::withdraw(double amount) {
  balance -= amount;
}

AccountAbstractBaseClass::Formatting AccountAbstractBaseClass::setFormat() const {
  Formatting f;
  f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
  f.pr = cout.precision(2);
  return f;
}

void AccountAbstractBaseClass::restoreFormat(Formatting& f) const {
  cout.setf(f.flag, ios_base::floatfield);
  cout.precision(f.pr);
}

void Brass::withdraw(double amount) {
  if (amount < 0) {
    cout << "마이너스 인출은 허용되지 않습니다.\n"
      << "그래서 인출이 취소되었습니다.\n";
  }
  else if (amount <= getBalance()) {
    AccountAbstractBaseClass::withdraw(amount);
  }
  else {
    cout << "인출을 요구한 금액 $" << amount << "가 현재 잔액을 초과합니다.\n"
      << "그래서 인출이 취소되었습니다.\n";
  }
}

void Brass::getAccountInfo() const {
  Formatting f = setFormat();
  cout << "Bass account userName : " << getFullName() << '\n';
  cout << "Brass account number : " << getAccountNumber() << '\n';
  cout << "Brass account balance : " << getBalance() << '\n';
  restoreFormat(f);
}

BrassPlus::BrassPlus(const string& inputString, long inputAccountNumber, double inputBalance,
  double inputMaxLoan, double inputRate) : AccountAbstractBaseClass(inputString, inputAccountNumber, inputBalance) {
  maxLoan = inputMaxLoan;
  rate = inputRate;
  owesBank = 0.0;
}
void BrassPlus::getAccountInfo() const {
  Formatting f = setFormat();

  cout << "BrassPlus account userName : " << getFullName() << '\n';
  cout << "BrassPlus account number : " << getAccountNumber() << '\n';
  cout << "BrassPlus account balance : " << getBalance() << '\n';

  cout << "BrassPlus account maxLoan : " << maxLoan << '\n';
  cout << "BrassPlus account owes bank : " << owesBank << '\n';
  cout.precision(3);
  cout << "BrassPlus account rate : " << rate << '\n';

  restoreFormat(f);
}

void BrassPlus::withdraw(double amount) {
  Formatting f = setFormat();

  double bal = getBalance();
  if (amount <= bal) {
    AccountAbstractBaseClass::withdraw(amount);
  }
  else if (amount <= bal + maxLoan - owesBank) {
    double advance = amount - bal;
    owesBank += advance * (1.0 + rate);
    cout << "당좌 대월 금액(빚) : " << advance << endl;
    cout << "당좌 대월 이자 : " << advance * rate << endl;
    deposit(advance);
    AccountAbstractBaseClass::withdraw(amount);
  }
  else {
    cout << "당좌 대월 한도가 초과되어 거래가 취소되었습니다.\n";
  }

  restoreFormat(f);
}

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
    cout << "���̳ʽ� �Ա��� ������ �ʽ��ϴ�.\n" << "�׷��� �Ա��� ��ҵǾ����ϴ�.\n";
  }
  else {
    balance += amount;
  }
}

void Brass::withdraw(double amount) {
  format initialState = setFormat();
  precis prec = cout.precision(2);

  if (amount < 0) {
    cout << "���̳ʽ� ������ ������ �ʽ��ϴ�.\n" << "�׷��� ������ ��ҵǾ����ϴ�.\n";
  }
  else if (amount <= balance) {
    balance -= amount;
  }
  else {
    cout << "������ �䱸�� �ݾ� $" << amount
         << "�� ���� �ܾ��� �ʰ��մϴ�.\n"
         << "�׷��� ������ ��ҵǾ����ϴ�.\n";
    restore(initialState, prec);
  }
}

double Brass::getBalance(void) const{
  return balance;
}

void Brass::getInfo(void) const {
  format initialState = setFormat();
  precis prec = cout.precision(2);

  cout << "�� �̸� : " << fullName << '\n';
  cout << "���� ��ȣ : " << accountNumber << '\n';
  cout << "���� �ܾ� : $" << balance << '\n';

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
  cout << "���� ��� �ѵ��� : $" << maxLoan << '\n';
  cout << "��ȯ�� ������ : $" << owesBank << '\n';
  cout.precision(3);
  cout << "���� ��� ������ : " << 100 * rate << "%\n";
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
    cout << "���� ��� �ݾ� : $" << advance << '\n';
    cout << "���� ��� ���� : $" << advance * rate << '\n';
    deposit(advance);
    Brass::withdraw(amount);
  }
  else {
    cout << "���� ��� �ѵ��� �ʰ��Ǿ� �ŷ��� ��ҵǾ����ϴ�.\n";
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

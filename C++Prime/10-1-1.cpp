#include "10-1.h"
#include <cstring>
#include <iostream>
#pragma warning(disable: 4996)

Account::Account(const char* name, const char* accountNumber, long initAccount)
{
  std::cout << "initialization" << '\n';
  strcpy(m_name, name);
  strcpy(m_accountNumber, accountNumber);
  m_account = initAccount;
  getInfo();
}

void Account::getInfo() const
{
  std::cout << "--------------------------" << '\n';
  std::cout << "name : " << m_name << '\n'
    << "account number : " << m_accountNumber << '\n'
    << "account : $" << m_account << '\n';
}

void Account::deposit(long inCash)
{
  std::cout << "--------------------------" << '\n';
  if (inCash < 0) {
    std::cout << "cannot be minus value" << '\n';
  }
  else {
    m_account += inCash;
    std::cout << "in: $" << inCash << '\n';
  }
}

void Account::withdraw(long outCash)
{
  std::cout << "--------------------------" << '\n';
  if (m_account - outCash < 0) {
    std::cout << "over your account" << '\n';
  }
  else {
    m_account -= outCash;
    std::cout << "out: $" << outCash << '\n';
  }
}

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

class Account {
private:
  char m_name[20];
  char m_accountNumber[20];
  long m_account;

public:
  Account(const char* name, const char* accountNumber, long initAccount);
  void getInfo() const;
  void deposit(long inCash);
  void withdraw(long outCash);
};

#endif // ! ACCOUNT_H_

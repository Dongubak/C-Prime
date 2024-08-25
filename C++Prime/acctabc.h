#ifndef  ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>

class AccountAbstractBaseClass {
private:
  std::string fullName;
  long accountNumber;
  double balance;

protected:
  struct Formatting {
    std::ios_base::fmtflags flag;
    std::streamsize pr;
  };

  const std::string& getFullName() const {
    return fullName;
  }

  long getAccountNumber(void) const {
    return accountNumber;
  }

  Formatting setFormat() const;
  void restoreFormat(Formatting& f) const;

public:
  AccountAbstractBaseClass(const std::string& inputFullName = "Nullbody",
    long inputAccountNumber = -1,
    double inputBalance = 0.0);
  void deposit(double amount);
  virtual void withdraw(double amount) = 0; ///pure virtual function
  double getBalance(void) const {
    return balance;
  }
  virtual void getAccountInfo() const = 0; ///pure virtual function
  virtual ~AccountAbstractBaseClass(void) {} ///virtual destructor
};

class Brass : public AccountAbstractBaseClass {
public:
  Brass(const std::string& inputFullName = "Nullbody", long inputAccountNumber = -1, double inputBalance = 0.0)
    : AccountAbstractBaseClass(inputFullName, inputAccountNumber, inputBalance) {};
  virtual void withdraw(double amount);
  virtual void getAccountInfo() const;
  virtual ~Brass() {};
};

class BrassPlus : public AccountAbstractBaseClass {
private:
  double maxLoan;
  double rate;
  double owesBank;
public:
  BrassPlus(const std::string& inputFullName = "Nullbody", long inputAccountNumber = -1, double inputBalance = 0.0,
    double inputMaxLoan = 500, double inputRate = 0.10);
  BrassPlus(const Brass& brassRef, double inputMaxLoan = 500, double inputRate = 0.10);
  virtual void withdraw(double amount);
  virtual void getAccountInfo() const;

  void resetMaxLoan(double inputMaxLoan) {
    maxLoan = inputMaxLoan;
  }

  void resetRate(double inputRate) {
    rate = inputRate;
  }
  
  void resetOwesBank() {
    owesBank = 0;
  } ///reset to 0

  virtual ~BrassPlus() {};
  
};

#endif // ! ACCTABC_H_

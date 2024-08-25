#ifndef BRASS_H_
#define BRASS_H_

#include <string>

class Brass {
private:
  std::string fullName;
  long accountNumber;
  double balance;

public:
  Brass(const std::string& inputFullName = "NullBody", long inputAccountNumber = -1, double inputBalance = 0.0);
  void deposit(double amount); ///balance setter
  virtual void withdraw(double amount); ///balance setter
  double getBalance(void) const; ///balance getter
  virtual void getInfo(void) const;
  virtual ~Brass() {}
};

class BrassPlus : public Brass {
private:
  double maxLoan; ///limits how much money the bank will lend you
  double rate; /// interest on the loan
  double owesBank;///overdraft loans plus interes

public:
  BrassPlus(const std::string& inputFullName = "NullBody", long inputAccountNumber = -1, double inputBalance = 0.0, 
            double inputMaxLoan = 500, double inputRate = 0.11125);
  BrassPlus(const Brass& inputBrassRef,
            double inputMaxLoan = 500, double inputRate = 0.11125);

  virtual void getInfo() const;
  virtual void withdraw(double amount);

  void setMaxLoan(double inputMaxLoan) {
    maxLoan = inputMaxLoan;
  }
  void setRate(double inputRate) {
    rate = inputRate;
  }
  void setOwesBank(double inputOwesBank = 0) {
    owesBank = inputOwesBank;
  }
};

#endif // !BRASS_H_

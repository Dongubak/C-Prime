#include <iostream>
#include <string>
#include "acctabc.h"
#include "useBrass3.h"
const int CLIENTS = 4;

void setInputKind(char& tmpInputKindRef);

#define LOOP(start, end, _var_name) for(int _var_name = start; _var_name < end; _var_name++) {
#define END }

int main(void) {

  using std::cin;
  using std::cout;
  using std::endl;

  AccountAbstractBaseClass* p_clients[CLIENTS];
  std::string tmpInputFullName = "";
  long tmpInputAccountNumber = 0;
  double tmpInputBalance = 0;
  char tmpInputKind = 0;

  for (int i = 0; i < CLIENTS; i++) {
    cout << "enter client's name : ";
    getline(cin, tmpInputFullName);
    cout << "enter client's account number : ";
    cin >> tmpInputAccountNumber;
    cout << "enter opening balance : $";
    cin >> tmpInputBalance;

    cout << "enter 1 for Brass Account or "
      << "2 for BrassPlus Account : ";

    setInputKind(tmpInputKind);

    if (tmpInputKind == '1') {
      p_clients[i] = new Brass(tmpInputFullName, tmpInputAccountNumber, tmpInputBalance);
    }
    else {
      double tmpInputMaxLoan = 0;
      double tmpInputRate = 0.0;

      cout << "enter the overdraft limit : $";
      cin >> tmpInputMaxLoan;
      cout << "enter the interest rate "
        << "as a deciaml fraction : ";
      cin >> tmpInputRate;
      p_clients[i] = new BrassPlus(tmpInputFullName, tmpInputAccountNumber, tmpInputBalance, tmpInputMaxLoan, tmpInputRate);
    }
    while (cin.get() != '\n') {
      continue;
    } ///clear buffer
  }

  cout << "\n";


  LOOP(0, CLIENTS, i)
    p_clients[i]->getAccountInfo();
    cout << '\n';
  END

  LOOP(0, CLIENTS, i)
    delete p_clients[i];
  END
  

  cout << "Done. \n";

  return 0;
}

void setInputKind(char& tmpInputKindRef)
{
  std::cout << "enter 1 for Brass Account or "
    << "2 for BrassPlus Account : ";

  while (!(std::cin >> tmpInputKindRef) || (tmpInputKindRef != '1' && tmpInputKindRef != '2')) {
    std::cout << "Enter either 1 or 2: ";
    while (std::cin.get() != '\n') {
      continue;
    }
  }

}

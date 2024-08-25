#include <iostream>
#include "brass.h"
#include <string>

const int CLIENTS = 4;

int main(void) {

  using std::cout;
  using std::cin;
  using std::endl;

  Brass* p_clients[CLIENTS]{};
  std::string tmpInputFullName{};
  long tmpInputAccountNumber{};
  double tmpInputBalance{};
  char tmpInputKind{};

  for (int i = 0; i < CLIENTS; i++) {
    cout << "enter the customer's name : ";
    getline(cin, tmpInputFullName);

    cout << "enter the customer's account number : ";
    cin >> tmpInputAccountNumber;
    
    cout << "enter the balance : ";
    cin >> tmpInputBalance;
    
    cout << "Brass ���´� 1, " << "BrassPlus ���´� 2�� �Է��Ͻÿ� : ";
    while (cin >> tmpInputKind && (tmpInputKind != '1' && tmpInputKind != '2')) {
      cout << "1 �ƴϸ� 2, �� �� �ϳ��� �Է��Ͻʽÿ� : ";
    }

    if (tmpInputKind == '1') {
      p_clients[i] = new Brass(tmpInputFullName, tmpInputAccountNumber, tmpInputBalance);
    }
    else {
      double tmpInputMaxLoan{}, tmpInputRate{};
      cout << "���� ��� �ѵ��� �Է��Ͻʽÿ� : $";
      cin >> tmpInputMaxLoan;

      cout << "���� ��� �������� �Ҽ��� �������� �Է��Ͻʽÿ� : ";
      cin >> tmpInputRate;
      p_clients[i] = new BrassPlus(tmpInputFullName, tmpInputAccountNumber, tmpInputBalance, tmpInputMaxLoan, tmpInputRate);
    }
    while (cin.get() != '\n') {
      continue;
    }
  }
  cout << endl;
  for (int i = 0; i < CLIENTS; i++) {
    p_clients[i]->getInfo();
    cout << endl;
  }

  for (int i = 0; i < CLIENTS; i++) {
    delete p_clients[i];
  }

  cout << "���α׷��� �����մϴ�. \n";
  
  return 0;
}
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
    
    cout << "Brass 계좌는 1, " << "BrassPlus 계좌는 2를 입력하시오 : ";
    while (cin >> tmpInputKind && (tmpInputKind != '1' && tmpInputKind != '2')) {
      cout << "1 아니면 2, 둘 중 하나를 입력하십시오 : ";
    }

    if (tmpInputKind == '1') {
      p_clients[i] = new Brass(tmpInputFullName, tmpInputAccountNumber, tmpInputBalance);
    }
    else {
      double tmpInputMaxLoan{}, tmpInputRate{};
      cout << "당좌 대월 한도를 입력하십시오 : $";
      cin >> tmpInputMaxLoan;

      cout << "당좌 대월 이자율을 소수점 형식으로 입력하십시오 : ";
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

  cout << "프로그램을 종료합니다. \n";
  
  return 0;
}
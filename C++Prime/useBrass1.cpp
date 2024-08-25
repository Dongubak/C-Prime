#include <iostream>
#include "brass.h"

int main(void) {

  using std::cout;
  using std::endl;

  Brass Piggy("Porcelot Pigg", 381299, 4000.00);
  BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);

  Piggy.getInfo();
  cout << endl;

  Hoggy.getInfo();
  cout << "Hogg ���� ���¿� $1000 �Ա� : \n";
  Hoggy.deposit(1000.00);

  cout << "Hoggy ���� ���� �ܾ� : $" << Hoggy.getBalance() << endl;
  
  cout << "Pigg ���� ���¿��� 4200 ���� : \n";
  Piggy.withdraw(4200.00);

  cout << "Pigg ���� ���� �ܾ� : $" << Piggy.getBalance() << endl;
  cout << "Hogg ���� ���¿��� $4200 ���� : \n";
  Hoggy.withdraw(4200.00);
  Hoggy.getInfo();
  return 0;
}
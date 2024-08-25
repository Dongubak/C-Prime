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
  cout << "Hogg ¾¾ÀÇ °èÁÂ¿¡ $1000 ÀÔ±Ý : \n";
  Hoggy.deposit(1000.00);

  cout << "Hoggy ¾¾ÀÇ ÇöÀç ÀÜ¾× : $" << Hoggy.getBalance() << endl;
  
  cout << "Pigg ¾¾ÀÇ °èÁÂ¿¡¼­ 4200 ÀÎÃâ : \n";
  Piggy.withdraw(4200.00);

  cout << "Pigg ¾¾ÀÇ ÇöÀç ÀÜ¾× : $" << Piggy.getBalance() << endl;
  cout << "Hogg ¾¾ÀÇ °èÁÂ¿¡¼­ $4200 ÀÎÃâ : \n";
  Hoggy.withdraw(4200.00);
  Hoggy.getInfo();
  return 0;
}
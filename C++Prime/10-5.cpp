#include "10-5.h"

int main(void) {

  using namespace std;

  Stack customersStack;
  int fullIncome{};
  char inputChar{};

  std::cout << "|Stack| append (a, A), pop (p, P), end(q, Q) : ";
  while (std::cin >> inputChar && (inputChar != 'q' && inputChar != 'Q')) {
    switch (inputChar) {
    case 'a':
    case 'A':
      if (customersStack.isfull()) {
        std::cout << "stack is full" << '\n';
      }
      else {
        customersStack.push(setAndReturnItem());
      }
      break;
    case 'p':
    case 'P':
      if (customersStack.isempty()) {
        std::cout << "stack is empty" << '\n';
      }
      else {
        std::cout << "remove customer" << '\n';
        customer popCustomer{};
        customersStack.pop(popCustomer);
        std::cout << "name : " << popCustomer.fullName << '\n';
        std::cout << "payment : " << popCustomer.payment << '\n';
        fullIncome += popCustomer.payment;

        cout << '\n';
        cout << "full income : " << fullIncome << '\n';
      }
    }
    std::cout << "|Stack| append (a, A), pop (p, P), end(q, Q) : ";
  }

  return 0;
}


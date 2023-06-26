#include "10-5.h"

Stack::Stack(void) {
  m_count = 0;
} //default constructor

bool Stack::isempty(void) const {
  return m_count == 0;
}

bool Stack::isfull(void) const {
  return m_count == MAX;
}

bool Stack::push(const Item& item) {
  if (m_count < MAX) {
    items[m_count] = item;
    m_count++;
    return true;
  }
  else {
    return false;
  }
}

bool Stack::pop(Item& item) {
  if (m_count > 0) {
    item = items[--m_count];
    return true;
  }
  else {
    return false;
  }
}

Item setAndReturnItem(void) {
  customer tmpInputCustomer{};
  std::cout << "enter the customer's name : ";
  std::cin >> tmpInputCustomer.fullName;

  std::cout << "enter the customer's payment : ";
  std::cin >> tmpInputCustomer.payment;

  return tmpInputCustomer;
}

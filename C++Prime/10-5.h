#ifndef STACK_H_
#define STACK_H_
#include <iostream>
struct customer {
  char fullName[35];
  double payment;
};

typedef customer Item;

class Stack {
private:
  enum { MAX = 10 };
  Item items[MAX]{};
  int m_count;
public:
  Stack();
  bool isempty(void) const;
  bool isfull(void) const;
  bool push(const Item& item);
  bool pop(Item& item);
};

Item setAndReturnItem(void);
#endif
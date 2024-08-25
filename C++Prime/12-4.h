#ifndef STACK_H_
#define STACK_H_
#include <iostream>

typedef unsigned long Item;

class Stack {
private:
  enum { MAX = 10 };
  Item* pitems;
  int size;
  int top;

public:
  Stack(int n = MAX); ///constructor
  Stack(const Stack& st); ///copy constructor
  ~Stack();
  bool isEmpty() const;
  bool isFull() const;
  bool push(const Item& item);
  bool pop(Item& item);
  Stack& operator=(const Stack& st); ///assignment operator
};

#endif // !STACK_H_
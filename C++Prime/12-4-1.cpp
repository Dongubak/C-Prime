#include "12-4.h"

Stack::Stack(int n) {
  top = 0;
  if (n > MAX) {
    std::cout << "cannot over MAX value, setting Item to MAX(10)\n";
    pitems = new Item[MAX];
    size = MAX;
  }
  else {
    pitems = new Item[n];
    size = n;
  }
}///constructor

Stack::Stack(const Stack& st) {
  size = st.size;
  top = st.top;

  pitems = new Item[size];
  for (int i = 0; i < top; i++) {
    pitems[i] = st.pitems[i];
  }
}///copy constructor

Stack::~Stack() {
  delete[] pitems;
}

bool Stack::isEmpty() const {
  return top == 0;
}

bool Stack::isFull() const {
  return top == size;
}

bool Stack::push(const Item& item) {
  if (top < size) {
    pitems[top++] = item;
    return true;
  }
  else {
    return false;
  }
}

bool Stack::pop(Item& item) {
  if (top > 0) {
    item = pitems[--top];
    return true;
  }
  else {
    return false;
  }
}

Stack& Stack::operator=(const Stack& st) {

  if (this == &st) {
    return *this;
  }
  
  size = st.size;
  top = st.top;

  delete[] pitems;

  pitems = new Item[size]; 
  for (int i = 0; i < top; i++) {
    pitems[i] = st.pitems[i];
  }

  return *this;
}
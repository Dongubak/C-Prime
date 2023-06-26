#ifndef STACK_H_
#define STACK_H_
#include <iostream>

template <class T>
void sum(T typeTArray[], int elementCount) {
  T total{};
  for (int i = 0; i < elementCount; i++) {
    total += typeTArray[i];
  }

  std::cout << "sum of Arr : " << total << '\n';
}

template <class T>
void sort(T* typeTArray, int elementCount) {
  for (int i = 0; i < elementCount - 1; i++) {
    for (int j = i + 1; j < elementCount; j++) {
      if (typeTArray[j] < typeTArray[i]) {
        T tmpValue{};
        tmpValue = typeTArray[i];
        typeTArray[i] = typeTArray[j];
        typeTArray[j] = tmpValue;
      }
    }
  }
}

template <typename T>
class Stack {
private:
  enum { MAX = 10 };
  T m_items[MAX];
  int m_top;
public:
  Stack() {
    m_top = 0;
  }
  bool isEmpty() const {
    return m_top == 0;
  }
  bool isFull() const
  {
    return m_top == MAX;
  }
  bool push(const T& item)
  {
    if (m_top < MAX) {
      m_items[m_top++] = item;
      return true;
    }
    else {
      return false;
    }
  }
  bool pop(T& item)
  {
    if (m_top > 0) {
      item = m_items[--m_top];
      return true;
    }
    else {
      return false;
    }
  }
  void getDatas()
  {
    if (!isEmpty()) {
      for (int i = 0; i < m_top; i++) {
        std::cout << m_items[i] << ' ';
      }
      std::cout << '\n';
    }
    else {
      std::cout << "stack is empty!" << '\n';
    }
  }
  void functionPointerCall(void (*functionPointer)(T*, int)) {
    functionPointer(m_items, m_top);
  }
};

#endif // !STACK_H_
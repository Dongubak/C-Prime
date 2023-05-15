#include <iostream>
#include <cctype>
#include "stack.h"

int main(void) {
  using namespace std;

  Stack sampleStack;
  char inputChar{};

  unsigned long inputData{};
  cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P, \n"
    << "종료하려면 Q를 입력하십시오.\n";

  while (cin >> inputChar && toupper(inputChar) != 'Q') {
    while (cin.get() != '\n')
      continue;

    if (!isalpha(inputChar)) {
      cout << '\a';
      continue;
    }

    switch (inputChar) {
    case 'A':
    case 'a':
      cout << "추가할 주문서의 번호를 입력하십시오: ";
      cin >> inputData;
      if (sampleStack.isfull()) {
        cout << "스택이 가득 차 있습니다.";
      }
      else {
        sampleStack.push(inputData);
      }
      break;
    case 'P':
    case 'p':
      if (sampleStack.isempty()) {
        cout << "스택이 비어있습니다.";
      }
      else {
        sampleStack.pop(inputData);
        cout << "#" << inputData << " 주문서를 처리했습니다.";
      }
      break;
    }
    cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P, \n"
      << "종료하려면 Q를 입력하십시오.\n";

  }
  cout << "프로그램을 종료합니다.";
  return 0;
}
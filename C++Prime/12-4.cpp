#include "12-4.h"
#include <cctype>
#include <iostream>

int main(void) {
  using namespace std;

  Stack st1(3);
  Stack st2(8);
  char ch;
  Item po;

  cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P, \n" << "종료하려면 Q를 입력하시오. \n";

  while (cin >> ch && toupper(ch) != 'Q') {
    while (cin.get() != '\n') {
      continue;
    }

    if (!isalpha(ch)) {
      cout << '\a';
      continue;
    }

    switch (ch) {
    case 'A':
    case'a':
      cout << "추가할 주문서의 번호를 입력하십시오 : ";
      cin >> po;
      if (st1.isFull()) {
        st2 = st1;
        cout << "스택이 가득 차 있습니다.\n";
      }
      else {
        st1.push(po);
      }
      break;
    case 'P':
    case 'p':
      if (st1.isEmpty()) {
        cout << "스택이 비어있습니다.\n";
      }
      else {
        st1.pop(po);
        cout << "#" << po << " 주문서를 처리했습니다.\n";
      }
      break;
    }
    cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P, \n" << "종료하려면 Q를 입력하십시오.\n";
  }

  while (!st2.isEmpty()) {
    st2.pop(po);
    cout << "#" << po << " 주문서를 처리했습니다.\n";
  }

  cout << "프로그램을 종료합니다.\n";

  return 0;
}
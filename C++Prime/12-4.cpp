#include "12-4.h"
#include <cctype>
#include <iostream>

int main(void) {
  using namespace std;

  Stack st1(3);
  Stack st2(8);
  char ch;
  Item po;

  cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, \n" << "�����Ϸ��� Q�� �Է��Ͻÿ�. \n";

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
      cout << "�߰��� �ֹ����� ��ȣ�� �Է��Ͻʽÿ� : ";
      cin >> po;
      if (st1.isFull()) {
        st2 = st1;
        cout << "������ ���� �� �ֽ��ϴ�.\n";
      }
      else {
        st1.push(po);
      }
      break;
    case 'P':
    case 'p':
      if (st1.isEmpty()) {
        cout << "������ ����ֽ��ϴ�.\n";
      }
      else {
        st1.pop(po);
        cout << "#" << po << " �ֹ����� ó���߽��ϴ�.\n";
      }
      break;
    }
    cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, \n" << "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
  }

  while (!st2.isEmpty()) {
    st2.pop(po);
    cout << "#" << po << " �ֹ����� ó���߽��ϴ�.\n";
  }

  cout << "���α׷��� �����մϴ�.\n";

  return 0;
}
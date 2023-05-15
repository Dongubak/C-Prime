#include <iostream>
#include <cctype>
#include "stack.h"

int main(void) {
  using namespace std;

  Stack sampleStack;
  char inputChar{};

  unsigned long inputData{};
  cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, \n"
    << "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";

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
      cout << "�߰��� �ֹ����� ��ȣ�� �Է��Ͻʽÿ�: ";
      cin >> inputData;
      if (sampleStack.isfull()) {
        cout << "������ ���� �� �ֽ��ϴ�.";
      }
      else {
        sampleStack.push(inputData);
      }
      break;
    case 'P':
    case 'p':
      if (sampleStack.isempty()) {
        cout << "������ ����ֽ��ϴ�.";
      }
      else {
        sampleStack.pop(inputData);
        cout << "#" << inputData << " �ֹ����� ó���߽��ϴ�.";
      }
      break;
    }
    cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, \n"
      << "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";

  }
  cout << "���α׷��� �����մϴ�.";
  return 0;
}
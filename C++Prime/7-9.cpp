#include <iostream>

using namespace std;

const int SLEN = 30;

struct student {
  char fullname[SLEN];
  char hobby[SLEN];
  int ooplevel;
};

int setData(student* stPointer, int elementCount);
void getData_1(student studentStruct);
void getData_2(const student* stPointer);
void getData_3(student* stPointer, int elementCount);

int main(void) {

  cout << "enter the student number";
  int classSize{};
  cin >> classSize;

  while (cin.get() != '\n') {
    continue;
  }

  student* stPointer = new student[classSize];

  int validCount{};
  validCount = setData(stPointer, classSize);

  for (int i = 0; i < validCount; i++) {
    getData_1(*(stPointer + i));
    getData_2(&stPointer[i]);
  }

  getData_3(stPointer, validCount);
  cout << "end Program";

  return 0;
}
int setData(student* stPointer, int elementCount)
{
  int validCount{};
  for (int i = 0; i < elementCount; i++) {
    cout << "<" << i + 1 << ">" << '\n';
    cout << "Enter the fullname: ";
    cin.getline(stPointer[i].fullname, SLEN);
    if (stPointer[i].fullname == "\n") {
      break;
    }
    cout << "Enter the hobby: ";
    cin.getline(stPointer[i].hobby, SLEN);

    cout << "Enter the ooplevel: ";
    if (!(cin >> stPointer[i].ooplevel)) {
      break;
    }
    cin.get();

    validCount++;
  }

  return validCount;
}

void getData_1(student studentStruct)
{
  cout << "fullName : " << studentStruct.fullname << ", hobby : " 
       << studentStruct.hobby << ", ooplevel" << studentStruct.ooplevel << '\n';
}

void getData_2(const student* stPointer)
{
  cout << "fullName : " << stPointer->fullname << ", hobby : "
    << stPointer->hobby << ", ooplevel" << stPointer->ooplevel << '\n';
}

void getData_3(student* stPointer, int elementCount)
{
  for (int i = 0; i < elementCount; i++) {
    cout << "fullName : " << stPointer[i].fullname << ", hobby : "
      << stPointer[i].hobby << ", ooplevel" << stPointer[i].ooplevel << '\n';
  }
}

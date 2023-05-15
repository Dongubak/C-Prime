#include <iostream>
#include <cstring>
#pragma warning(disable: 4996)

struct person {
  char name[20];
  int age;
};

char buf[512];

void getInfo(person* personStructPointer);

int main(void) {

  using namespace std;

  person* personUsingBuf = new (buf)person[2];
  person* personUsingDynamicAllocated = new person[2];

  const char* EX_NAMES[2] {
    "Jaspers", "Sanchez"
  };

  const int EX_AGES[2]{ 40, 50 };

  for (int i = 0; i < 2; i++) {
    strcpy(personUsingBuf[i].name, EX_NAMES[i]);
    strcpy(personUsingDynamicAllocated[i].name, EX_NAMES[i]);

    personUsingBuf[i].age = EX_AGES[i];
    personUsingDynamicAllocated[i].age = EX_AGES[i];
  }

  getInfo(personUsingBuf);
  getInfo(personUsingDynamicAllocated);

  delete[] personUsingDynamicAllocated;
  

  return 0;
}

void getInfo(person* personStructPointer) {
  for (int i = 0; i < 2; i++) {
    std::cout << i << " struct" << '\n';
    std::cout << "name : " << personStructPointer[i].name << '\n';
    std::cout << "age : " << personStructPointer[i].age << '\n';
  }
}
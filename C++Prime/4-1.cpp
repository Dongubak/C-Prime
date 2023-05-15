#include <iostream>
using namespace std;

struct student {
  char firstName[20];
  char lastName[20];
  char hopeScore;
  int age;
};

void getData(student* pt);
void printData(student* pt);

int main() {

  student exampleStudent;

  getData(&exampleStudent);
  printData(&exampleStudent);

  return 0;
}

void getData(student* pt)
{

  cout << "enter your first name : ";
  cin.get(pt->firstName, 20).get();

  cout << "enter your last name : ";
  cin.get(pt->lastName, 20).get();

  cout << "enter your hoping score : ";
  cin >> pt->hopeScore;

  cout << "enter your age : ";
  cin >> pt->age;
}

void printData(student* pt)
{
  cout << "name : " << pt->lastName << ", " << pt->firstName << '\n';
  cout << "score : " << char(pt->hopeScore + 1) << '\n';
  cout << "age : " << pt->age;
}

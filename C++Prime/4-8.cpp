#include <iostream>
#include <string>

using namespace std;

struct PizzaInfo {
  string companyName;
  double pizzaDiameter;
  double pizzaWeight;
};

int main(void) {

  PizzaInfo* a = new PizzaInfo;

  cout << "enter the pizza diameter : ";
  cin >> a->pizzaDiameter;
  cin.get();

  cout << "enter the company name : ";
  getline(cin, a->companyName);


  cout << "enter the pizza weight : ";
  cin >> a->pizzaWeight;

  cout << "company name : " << a->companyName << '\n';
  cout << "pizza diameter : " << a->pizzaDiameter << '\n';
  cout << "pizza weight : " << a->pizzaWeight << '\n';

  delete a;

  return 0;
}
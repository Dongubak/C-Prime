#include <iostream>
#include <string>

using namespace std;

struct PizzaInfo {
  string companyName;
  double pizzaDiameter;
  double pizzaWeight;
};

int main(void) {
  PizzaInfo a;

  cout << "enter the company name : ";
  getline(cin, a.companyName);

  cout << "enter the pizza diameter : ";
  cin >> a.pizzaDiameter;

  cout << "enter the pizza weight : ";
  cin >> a.pizzaWeight;

  cout << "company name : " << a.companyName << '\n';
  cout << "pizza diameter : " << a.pizzaDiameter << '\n';
  cout << "pizza weight : " << a.pizzaWeight << '\n';

  return 0;
}
#include <iostream>

int main() {

  using namespace std;

  long long inputWorldPopulation, inputAmericanPopulation;

  cout << "enter the world population : ";
  cin >> inputWorldPopulation;

  cout << "enter the American population : ";
  cin >> inputAmericanPopulation;

  cout << "ratio : " << (inputAmericanPopulation / long double(inputWorldPopulation)) * 100;


  return 0;
}
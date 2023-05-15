#include <iostream>

int main(void) {
  
  using namespace std;

  string month[12] = {
    "January", "Febuary", "March", "April", 
    "May", "June", "Junly", "Agust",
    "September", "October", "November", "December"
  };

  int year = 2023;

  cout << "This Year : " << year << '\n';

  int monthlySold[12]{};

  for (int i = 0; i < 12; i++) {
    cout << "enter the Month sold " << "(" << month[i] << ")" << " : ";
    cin >> monthlySold[i];
  }

  int sum = 0;
  for (int i = 0; i < 12; i++) {
    sum += monthlySold[i];
  }

  cout << "This year Sold : " << sum << '\n';
  cout << "sum of array : " << sum;
  

  return 0;
}
#include <iostream>

int main(void) {

  using namespace std;

  const string MONTH[12] = {
    "January", "Febuary", "March", "April",
    "May", "June", "Junly", "Agust",
    "September", "October", "November", "December"
  };

  int initialYear = 2023;
  
  
  int monthlySold[12][3]{};
  for (int year = 0; year < 3; year++) {
    cout << "This Year : " << initialYear + year << '\n';
    for (int month = 0; month < 12; month++) {
      cout << "enter the Month sold " << "(" << MONTH[month] << ")" << " : ";
      cin >> monthlySold[month][year];
    }
  }

  int sum = 0;
  int yearlySold[3]{};
  for (int year = 0; year < 3; year++) {
    for (int month = 0; month < 12; month++) {
      sum += monthlySold[month][year];
      yearlySold[year] += monthlySold[month][year];
    }
  }
  
  for (int year = 0; year < 3; year++) {
    cout << "year : " << initialYear + year << '\n';
    cout << "yearly Sold : " << yearlySold[year] << '\n';
  }




  return 0;
}
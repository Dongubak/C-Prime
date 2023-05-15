#include <iostream>

int main(void) {

  using namespace std;

  double balanceA = 100000, balanceB = 100000;
  int interestA = 10000;
  int yearCount = 0;
  while (balanceB <= balanceA) {
    balanceA += interestA;
    balanceB *= (1 + 0.05);
    ++yearCount;
    cout << "year " << yearCount << "  bal A : " << balanceA << "\t bal B : " << balanceB << '\n';
  }

  cout << "year : " << yearCount;

  return 0;
}
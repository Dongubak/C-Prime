#include <iostream>
#include "6-5.h"

const double firstTaxRate = 0.0;
const double secondTaxRate = 0.1;
const double thirdTaxRate = 0.15;
const double lastTaxRate = 0.2;

const double firstSperator = 5000.;
const double secondSeperator = 10000.;
const double thirdSeperator = 20000.;

double firstFullTax = firstSperator * firstTaxRate;
double secondFullTax = secondSeperator * secondTaxRate;
double thirdFullTax = thirdSeperator * thirdTaxRate;

int main(void) {

  using namespace std;

  int inputIncome{};
  cout << "enter your income : ";

  if (cin >> inputIncome && !(inputIncome < 0)) {
    double tax = 0.0;
    double restIncome = 0.0;
    calTax(inputIncome, tax, restIncome);

    cout << "Tax : " << tax;
  }
  return 0;
}

void calTax(int inputIncome, double& tax, double& restIncome)
{
  if (inputIncome >= 35000) {
    tax = firstFullTax + secondFullTax + thirdFullTax;
    restIncome = inputIncome - (firstSperator + secondSeperator + thirdSeperator);
    tax += restIncome * lastTaxRate;
  }
  else if (inputIncome >= 15000) {
    tax = firstFullTax + secondFullTax;
    restIncome = inputIncome - (firstSperator + secondSeperator);
    tax += restIncome * thirdTaxRate;
  }
  else if (inputIncome >= 5000) {
    tax = firstFullTax;
    restIncome = inputIncome - (firstSperator);
    tax += restIncome * secondTaxRate;
  }
  else {
    tax = firstFullTax;
    restIncome = inputIncome - (firstSperator);
    tax += restIncome * firstTaxRate;
  }
}

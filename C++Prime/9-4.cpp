#include <iostream>
#include "9-4.h"

int main(void) {n 
  using namespace std;
  using namespace SALES;

  const double EX_SALES[4] = {10, 20, 15, 24};

  Sales sampleSales[2]{};
  setSales(sampleSales[0], EX_SALES, QUARTERS);
  showSales(sampleSales[0]);

  setSales(sampleSales[1]);
  showSales(sampleSales[1]);

  return 0;
}
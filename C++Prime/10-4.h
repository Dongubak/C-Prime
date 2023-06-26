#ifndef _SALES_H_
#define _SALES_H_
#include <iostream>

namespace SalesUtil {
  const int QUARTERS = 4;

  struct Sales {
    double sales[QUARTERS];
    double average;
    double max;
    double min;
  };

  void setSales(Sales& inputSales, const double salesArr[], int elementCount);
  void setSales(Sales& inputSales);
  void showSales(const Sales& inputSales);
}

class Sales {
private:
  SalesUtil::Sales m_sales;
public:
  Sales();
  Sales(const double salesArr[], int elementCount);
  Sales setSales();
  void showSales();
};

#endif // !_SALES_H_

#include "10-4.h"

void setDatas(SalesUtil::Sales& inputSales);

namespace SalesUtil {
  void setSales(Sales& inputSales, const double salesArr[], int elementCount) {
    for (int i = 0; i < elementCount; i++) {
      inputSales.sales[i] = salesArr[i];
    }
    setDatas(inputSales);
  }
  void setSales(Sales& inputSales) {
    std::cout << "enter the sales value (seperated in space) : ";
    for (int i = 0; i < QUARTERS; i++) {
      std::cin >> inputSales.sales[i];
    }
    setDatas(inputSales);
  }
  void showSales(const Sales& inputSales) {
    int elementCount = sizeof(inputSales.sales) / sizeof(double);
    for (int i = 0; i < elementCount; i++) {
      std::cout << i << " " << inputSales.sales[i] << '\n';
    }
    std::cout << "Max : " << inputSales.max << ", Min : " << inputSales.min << ", avg : " << inputSales.average << '\n';
  }
}

void setDatas(SalesUtil::Sales& inputSales) {

  double total{};
  for (int i = 0; i < SalesUtil::QUARTERS; i++) {
    total += inputSales.sales[i];
  }

  double tmpMax = inputSales.sales[0];
  double tmpMin = inputSales.sales[0];

  for (int i = 0; i < SalesUtil::QUARTERS; i++) {
    tmpMax = inputSales.sales[i] > tmpMax ? inputSales.sales[i] : tmpMax;
    tmpMin = inputSales.sales[i] < tmpMin ? inputSales.sales[i] : tmpMin;
  }

  inputSales.max = tmpMax;
  inputSales.min = tmpMin;
  inputSales.average = total / SalesUtil::QUARTERS;
}


Sales::Sales()
{
  std::cout << "default constructor" << '\n';
  SalesUtil::setSales(m_sales);
}

Sales::Sales(const double salesArr[], int elementCount)
{
  SalesUtil::setSales(m_sales, salesArr, elementCount);
}
///explicit constructor

Sales Sales::setSales()
{
  Sales tmpSalesInsatance;
  
  return (*this = tmpSalesInsatance);
}

void Sales::showSales()
{
  SalesUtil::showSales(m_sales);
}
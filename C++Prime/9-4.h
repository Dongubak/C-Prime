namespace SALES {
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

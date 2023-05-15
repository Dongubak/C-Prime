#include <iostream>

int main() {
  using namespace std;
  double inputHeightFe, inputHeightIn, inputWeightPo;
  const double feetToInch = 12.0, inchToInch = 1.0, inchToMeter = 0.0254;
  const double poundToKilogram = 2.2; ///divide
  double leftExpression, rightExpression;

  cout << "enter the height(feet), height(inch) and weight(pound) (seperated in space) : ";
  cin >> inputHeightFe >> inputHeightIn >> inputWeightPo;


  rightExpression = (inputHeightFe * feetToInch * inchToMeter);
  leftExpression = (inputWeightPo / poundToKilogram);

  cout << "BMI : " << leftExpression / (rightExpression * rightExpression);

  return 0;
}
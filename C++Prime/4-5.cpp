#include <iostream>
#include <string>
using namespace std;

struct CandyBar {
  string productName;
  double weight;
  int calories;
};

void getData(CandyBar *snack, int elementCount);
void displayData(CandyBar *snack, int elementCount);

int main(void) {
  
  CandyBar snack;

  getData(&snack, 1);
  displayData(&snack, 1);

 
  return 0;
}

void getData(CandyBar *snack, int elementCount)
{
  int outerIter = 0;
  for (outerIter; outerIter < elementCount; outerIter++) {
    cout << "enter the product name : ";
    getline(cin, snack[outerIter].productName);
    cout << "enter the product weight : ";
    cin >> snack[outerIter].weight;
    cout << "enter the product calories : ";
    cin >> snack[outerIter].calories;
  }
}

void displayData(CandyBar* snack, int elementCount)
{
  int outerIter = 0;

  for (outerIter = 0; outerIter < elementCount; outerIter++) {
    cout << "product name : " << snack[outerIter].productName << '\n';
    cout << "product weight : " << snack[outerIter].weight << '\n';
    cout << "product calories : " << snack[outerIter].calories << '\n';
  }
    
 
}

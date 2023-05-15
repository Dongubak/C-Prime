#include <iostream> 

int main() {
  using namespace std;
  const double div = 60.0;

  int inputDegree, inputDegreeMinute, inputDegreeSecond;

  cout << "enter the degree(H) : ";
  cin >> inputDegree;
  cout << "enter the degree(M) : ";
  cin >> inputDegreeMinute;
  cout << "enter the degree(S) : ";
  cin >> inputDegreeSecond;

  cout << inputDegree << "µµ, " 
       << inputDegreeMinute << "ºÐ, " 
       << inputDegreeSecond << "ÃÊ = " 
    << inputDegree + inputDegreeMinute / div + inputDegreeSecond / (div * div);



  return 0;
}
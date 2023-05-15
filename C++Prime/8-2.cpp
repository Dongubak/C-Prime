#include <iostream>
#include <cstring>
#pragma warning(disable: 4996)

struct CandyBar {
  char name[20];
  double weight;
  int calories; 
};

void initMembers(CandyBar& target
  , const char* inputName = "Millennium Munch"
  , double inputWeight = 2.85
  , int inputCalories = 350);

int main(void) {

  using namespace std;

  CandyBar exInstArr[2]{};

  initMembers(exInstArr[0], "sneakers", 3.12, 200);
  initMembers(exInstArr[1]);

  for (int i = 0; i < 2; i++) {
    cout << "---------- " << i << " ----------" << '\n';
    cout << "name : " << exInstArr[i].name << '\n';
    cout << "weight : " << exInstArr[i].weight << '\n';
    cout << "calories : " << exInstArr[i].calories << '\n';
  }

  return 0;
}

void initMembers(CandyBar& target
  , const char* inputName
  , double inputWeight
  , int inputCalories) {
  
  strcpy(target.name, inputName);
  target.weight = inputWeight;
  target.calories = inputCalories;
}
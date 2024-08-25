#include <iostream>
#include <cstdlib>
#include <ctime>
#include "11-3.h"

int main(void) {
  using namespace std;
  using VECTOR::Vector;

  srand(time(0));

  Vector tmpVector{}, resultVector{};

  unsigned long stepCount{};

  double randomDirection{};
  double targetDistance{};
  double stepLength{};

  unsigned long highestStepCount{};
  unsigned long lowestStepCount{};
  unsigned long totalStepCount{};

  int inputN{}; ///execute count
  

  ofstream outFile;
  outFile.open("randomWalkData3.txt");

  int iter = 0;
  if (isValidInput(&targetDistance, &stepLength, &inputN)) {
    while (iter++ < inputN) {///input validation

      while (resultVector.getMagnitude() < targetDistance) {
        stepCount++;
        randomDirection = rand() % 360;
        tmpVector.reset(stepLength, randomDirection, Vector::POL);
        resultVector = resultVector + tmpVector;
      }

      highestStepCount = stepCount > highestStepCount ? stepCount : highestStepCount;
      if (iter == 1) { ///just first time
        cout << "target distance : " << targetDistance << ", step length : " << stepLength << '\n';
        outFile << "target distance : " << targetDistance << ", step length : " << stepLength << '\n';
        lowestStepCount = stepCount;
      }
      lowestStepCount = stepCount < lowestStepCount ? stepCount : lowestStepCount;
      totalStepCount += stepCount;

      stepCount = 0;
      resultVector.reset(0.0, 0.0);
    }
  }

  cout << "-----         report        -----\n";
  cout << "highest steps for " << inputN << " trial : " << highestStepCount << '\n';
  cout << "lowest steps for " << inputN << " trial : " << lowestStepCount << '\n';
  cout << "average steps for " << inputN << " trial : " << totalStepCount / inputN << '\n';


  outFile << "highest steps for " << inputN << " trial : " << highestStepCount << '\n';
  outFile << "lowest steps for " << inputN << " trial : " << lowestStepCount << '\n';
  outFile << "average steps for " << inputN << " trial : " << totalStepCount / inputN << '\n';

  cout << "Bye !\n";
  cin.clear();
  while (cin.get() != '\n') {
    continue;
  }

  return 0;
}
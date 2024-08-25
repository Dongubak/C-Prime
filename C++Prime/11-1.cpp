#include <iostream>
#include <cstdlib>
#include <ctime>
#include "11-1.h"

int main(void) {
  using namespace std;
  using VECTOR::Vector;

  srand(time(0));

  Vector tmpVector{}, resultVector{};

  unsigned long stepCount{};

  double randomDirection{};
  double targetDistance{};
  double stepLength{};

  ofstream outFile;
  outFile.open("randomWalkData.txt");

  cout << "Enter target distance (q to quit) : ";
  while (cin >> targetDistance) {///input validation
    cout << "Enter step length : ";

    if (!(cin >> stepLength)) { ///input validation
      break;
    }

    cout << "target distance : " << targetDistance << ", step length : " << stepLength << '\n';
    outFile << "target distance : " << targetDistance << ", step length : " << stepLength << '\n';

    cout << stepCount << ": (x, y) = (" << resultVector.getX() << ", " << resultVector.getY() << ")\n";
    outFile << stepCount << ": (x, y) = (" << resultVector.getX() << ", " << resultVector.getY() << ")\n";

    while (resultVector.getMagnitude() < targetDistance) {
      stepCount++;
      randomDirection = rand() % 360;
      tmpVector.reset(stepLength, randomDirection, Vector::POL);
      resultVector = resultVector + tmpVector;
      cout << stepCount << ": (x, y) = (" << resultVector.getX() << ", " << resultVector.getY() << ")\n";
      outFile << stepCount << ": (x, y) = (" << resultVector.getX() << ", " << resultVector.getY() << ")\n";
    }


    cout << "After " << stepCount << " steps, the subject has the follwing location: \n";
    outFile << "After " << stepCount << " steps, the subject has the follwing location: \n";

    cout << resultVector << '\n';
    outFile << resultVector << '\n';

    resultVector.toggleToPolar();

    cout << " or\n " << resultVector << '\n';
    outFile << " or\n " << resultVector << '\n';

    cout << "Average outward distance per step = " << resultVector.getMagnitude() / stepCount << '\n';
    outFile << "Average outward distance per step = " << resultVector.getMagnitude() / stepCount << '\n';

    stepCount = 0;
    resultVector.reset(0.0, 0.0);
    cout << "Enter target distance (q to quit) : ";
  }

  cout << "Bye !\n";
  cin.clear();
  while (cin.get() != '\n') {
    continue;
  }

  return 0;
}
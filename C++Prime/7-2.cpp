#include <iostream>

const int MAXINPUT = 10;
using namespace std;

void setScores(int* scoresPointer, int* inputCount);
void getScores(const int* scoresPointer, const int* inputCount);
void getAvg(const int* scoresPointer, const int* inputCount);

int main(void) {
  int* scores = new int[MAXINPUT];
  int inputCount{};

  setScores(scores, &inputCount);
  getScores(scores, &inputCount);
  getAvg(scores, &inputCount);

  delete[] scores;

  return 0;
}

void setScores(int* scoresPointer, int* inputCount)
{
  int inputScore{};
  for (int i = 0; i < MAXINPUT; i++) {
    cout << "enter the " << i + 1 << " score (end -1 or q): ";
    if (!(cin >> inputScore) || inputScore < 0) {
      cin.clear();
      while (cin.get() != '\n') {
        continue;
      }
      break;
    }
    scoresPointer[i] = inputScore;
    (*inputCount)++;
  }
}

void getScores(const int* scoresPointer, const int* inputCount)
{
  for (int i = 0; i < *inputCount; i++) {
    cout << scoresPointer[i] << " ";
  }
  
}

void getAvg(const int* scoresPointer, const int* inputCount)
{
  int total{};
  for (int i = 0; i < *inputCount; i++) {
    total += scoresPointer[i];
  }
  cout << '\n' << "avg: " << double(total) / *inputCount;
}

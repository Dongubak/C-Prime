#include <iostream>
#include <ctype.h>
#include "6-7.h"

using namespace std;

int main(void) {

  cout << "enter the words : \n";

  int vowelCount{}, consonantCount{}, etcCount{};
  string word;

  while ((cin >> word) && word[0] != 'q') {
    evalWord(word, vowelCount, consonantCount, etcCount);
  }

  displayCounts(vowelCount, consonantCount, etcCount);

  return 0;
}

void displayCounts(int vowelCount, int consonantCount, int etcCount)
{
  cout << "start with vowel : " << vowelCount << '\n';
  cout << "start with consonant : " << consonantCount << '\n';
  cout << "etc : " << etcCount << '\n';
}

void evalWord(std::string& word, int& vowelCount, int& consonantCount, int& etcCount)
{
  if (isalpha(word[0])) {
    switch (word[0]) {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      vowelCount += 1;
      break;
    default:
      consonantCount += 1;
    }
  }
  else {
    etcCount += 1;
  }
}

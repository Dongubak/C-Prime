#include <iostream>
#include <fstream>

using namespace std;
const int LEN = 20;

struct donationMembers {
  char name[LEN];
  double donation;
};

bool setData(int membersCount, donationMembers* contributors, ifstream* in);

void displayData(int membersCount, donationMembers* contributors);

int main(void) {

  ifstream in;

  in.open("6-9.txt");

  if (!in.is_open()) {
    exit(EXIT_FAILURE);
  }


  int membersCount{};
  (in >> membersCount).get();

  donationMembers* contributors = new donationMembers[membersCount];

  if (setData(membersCount, contributors, &in)) {
    displayData(membersCount, contributors);
  }
  else {
    cout << "기부자가 없습니다";
  }

  in.close();

  return 0;
}

void displayData(int membersCount, donationMembers* contributors)
{
  cout << "High\n";
  for (int i = 0; i < membersCount; i++) {
    if (contributors[i].donation >= 10000) {
      cout << contributors[i].name << " " << contributors[i].donation << '\n';
    }
  }
  cout << "low\n";
  for (int i = 0; i < membersCount; i++) {
    if (contributors[i].donation < 10000) {
      cout << contributors[i].name << " " << contributors[i].donation << '\n';
    }
  }
}

bool setData(int membersCount, donationMembers* contributors, ifstream* in)
{
  bool returnBool = false;
  if (membersCount == 0) {
    returnBool = false;
  }
  else {
    for (int i = 0; i < membersCount; i++) {
      (*in).getline(contributors[i].name, LEN);
      ((*in) >> contributors[i].donation).get();
    }
    returnBool = true;
  }

  return returnBool;
}

#include <iostream>

using namespace std;

struct donationMembers {
  string name;     
  double donation;
};

bool setData(int membersCount, donationMembers* contributors);

void displayData(int membersCount, donationMembers* contributors);a

int main(void) {
  int membersCount{};
  cout << "enter the donation members count : ";
  cin >> membersCount;

  donationMembers* contributors = new donationMembers[membersCount];

  if (setData(membersCount, contributors)) {
    displayData(membersCount, contributors);
  }
  else {
    cout << "기부자가 없습니다";
  }
  
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

bool setData(int membersCount, donationMembers* contributors)
{
  bool returnBool = false;
  if (membersCount == 0) {
    returnBool = false;
  }
  else {
    for (int i = 0; i < membersCount; i++) {
      cout << i + 1 << " enter the name : ";
      cin >> contributors[i].name;

      cout << i + 1 << " enter donation : ";
      cin >> contributors[i].donation;
    }
    returnBool = true;
  }

  return returnBool;
}

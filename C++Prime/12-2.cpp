#include <iostream>
using namespace std;
#include "12-2.h"

int main(void) {

  String s1{ " and I am a C++ student." };
  String s2 = "Please enter your name : ";
  String s3;

  cout << s2;
  cin >> s3;

  s2 = "My name is " + s3;
  cout << s2 << ".\n";
  s2 = s2 + s1;

  s2.stringToUpperCase();

  cout << "The string\n" << s2 << "\ncontains " << s2.getCount('A') << " 'A' characters in it.\n";
  
  s1 = "red";

  String rgb[3] = {
    String(s1), String("green"), String("blue")
  };

  for (int i = 0; i < 3; i++) {
    cout << rgb[i] << '\n';
  }
  
  cout << "Enter the name of a primary color for mixing light : ";
  String ans;
  bool success = false;
  
  while (cin >> ans) {
    ans.stringToLowerCase();
    for (int i = 0; i < 3; i++) {
      if (ans == rgb[i]) {
        cout << "That's right!\n";
        success = true;
        break;
      }
    }

    if (success) {
      break;
    }
    else {
      cout << "Try again!\n";
    }
  }
  cout << "Bye!";

  return 0;
}
#include <iostream>
#include <exception>

using namespace std;

int main(void) {
   cin.exceptions(ios_base::failbit);

   cout << "enter the number : ";

   int sum = 0;
   int input;

   try {
      while(cin >> input) {
         sum += input;
      }
   } catch(ios_base::failure & bf) {
      cout << bf.what() << endl;

      cout << "O! the horror!\n";
   }

   cout << input;
   cout << sum;

   return 0;
}
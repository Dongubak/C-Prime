//numeric_limits<type>::max(): include <limits>, get type's maximum value
//numeric_limits<type>::min(): include <limits>, get type's minimum value

//typeid(expression).name() : include <typeinfo>, return experssion's type

//modifier with non-parameter(dont need to include <iomanip>)
//static_cast<wanted_type> : dont need <iomanip>, type cast to wanted type
//fixed : dont need <iomanip>, show variance for fixed
//scientific : dont need <iomanip>, show variance for scientific
//showpoint : dont need <iomanip>, show point
//boolalpha : show bool value converting to str
//dec, oct : change base
//showbase : show base

//modifier with parameter (need to include <iomanip>)
//precision : If use percision with insertion operator, you should include <iomanip>.
//            set precision for variance
//setw : set width
//setfill: place dont use for data filled some char

#include <iostream>

int main(void) {

  using namespace std;

  int count = 3;

  while (count--); {
    cout << "hello" << '\n';
    goto foo;
  }

foo: {
  cout << "hello in foo" << '\n';
  }

  return 0;
}
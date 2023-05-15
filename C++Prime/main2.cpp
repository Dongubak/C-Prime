#include <iostream>

class Ik {
private:
  int fuss;

public:
  Ik(int f = 9) { 
    fuss = f;
  };

  void ViewIk() const;
};

void Ik::ViewIk() const{
  std::cout << fuss << std::endl;
}

int main(void) {

  using namespace std;

  Ik* pik = new Ik; // call default constructor
  Ik ee = Ik(8);
  ee.ViewIk();
  pik->ViewIk();


  return 0;
}
#include <iostream>
#include "13-3.h"
#include "13-3-1.h"

#define LOOP(start, end, _var) for(int _var = start; _var < end; _var++) {
#define END }
#define buf 128


int main(void) {

  DMA_AbstractBaseClass* dmaArray[3]{};
  int validDataCount = 0;
  {
    char tmpInputLabel[buf]{}, tmpInputColor[buf]{};
    int tmpInputRating{}, tmpInputType{};
    
    LOOP(0, 3, i)
      setTmpBaseData(tmpInputLabel, &tmpInputRating);
      setType(&tmpInputType);
      
      if (tmpInputType == 1) {
        dmaArray[i] = new baseDMA(tmpInputLabel, tmpInputRating);
      }
      else if (tmpInputType == 2) {
        setColor(tmpInputColor);
        dmaArray[i] = new lacksDMA(tmpInputColor, tmpInputLabel, tmpInputRating);
      }
      else {
        std::cout << "invalid type, end program";
        break;
      }
      
      validDataCount++;
    END
  }

  LOOP(0, validDataCount, i)
    dmaArray[i]->getInfo();
  END

  baseDMA b1("adfsa", 1);
  baseDMA b2("toyi", 2);

  std::cout << "b1 : " << b1 << '\n' << "b2 : " << b2 << '\n';

  b2 = b1;

  std::cout << "b2 : " << b2 << '\n';

  lacksDMA l1("red", "head", 3);
  lacksDMA l2("black", b2);

  std::cout << "l1 : " << l1 << '\n';
  std::cout << "l2 : " << l2 << '\n';

  return 0;
}
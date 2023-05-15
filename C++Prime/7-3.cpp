#include <iostream>

using namespace std;

struct Box {
  char maker[40];
  float height;
  float width;
  float length;
  float volume;
};

void getData(Box box);
void setVolume(Box* boxPointer);

int main(void) {

  Box box = {
    "samsung", 10.0, 20.0, 5.0, 0
  };

  getData(box);
  setVolume(&box);
  getData(box);

  return 0;
}

void getData(Box box)
{
  cout << "maker : "   << box.maker << ", height : " << box.height 
       << ", width : " << box.width << ", length : " << box.length 
       << ", box : "   << box.volume << '\n';

}

void setVolume(Box* boxPointer)
{
  boxPointer->volume = boxPointer->height * boxPointer->width * boxPointer->length;
}

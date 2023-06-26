#ifndef _GOLF_H_
#define _GOLF_H_
#include <iostream>
#include <cstring>

const int Len = 40;
struct golf {
  char fullname[Len];
  int handicap;
};

namespace golfUtil {
  void setgolf(golf& GolfStructReference, const char* inputName, int inputHandicap);
  int setgolf(golf& GolfStructReference);
  void setHandicap(golf& GolfStructReference, int inputHandicap);
  void showgolf(const golf& GolfStructReference);
}


class Golf {
private:
  golf m_golf;
public:
  Golf();
  Golf(const char* inputName, int inputHandicap);///explicit constructor
  Golf setGolf(void);
  void setHandicap(int inputHandicap);
  void showGolf(void);
};


#endif

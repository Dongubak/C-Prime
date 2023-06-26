#ifndef _MOVE_H_
#define _MOVE_H_
#include <iostream>

class Move {
private:
  double m_positionOfX;
  double m_positionOfY;

public:
  Move(double inputPositionX = 0, double inputPositionY = 0);
  void showmove() const;
  Move add(const Move& m) const;
  void reset(double a = 0, double b = 0);
};

#endif // !_MOVE_H_

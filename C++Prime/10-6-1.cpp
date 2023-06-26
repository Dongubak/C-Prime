#include "10-6.h"

Move::Move(double inputPositionX, double inputPositionY)
{
  m_positionOfX = inputPositionX;
  m_positionOfY = inputPositionY;
}

void Move::showmove() const
{
  std::cout << "current position" << '\n';
  std::cout << "position of x : " << m_positionOfX << '\n';
  std::cout << "position of y : " << m_positionOfY << '\n';
}

Move Move::add(const Move& m) const
{
  double sumOfPositionX = this->m_positionOfX + m.m_positionOfX;
  double sumOfPositionY = this->m_positionOfY + m.m_positionOfY;

  return Move(sumOfPositionX, sumOfPositionY);
}

void Move::reset(double a, double b)
{
  *this = Move(a, b);
}

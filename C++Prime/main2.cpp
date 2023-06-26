#include <iostream>
#pragma warning(disable: 4996)

class Player {
private:
  int m_score;

public:
  Player(int inputScore = 0) {
    m_score = inputScore;
  }

  Player compareScore(Player &playerReference) const {
    if (this->m_score > playerReference.m_score) {
      return *this;
    }
    else {
      return playerReference;
    }
  }

  void getInfo(void) const {
    std::cout << "score : " << m_score;
  }
};

int main(void) {

  Player a{ 10 };
  Player b{ 20 };

  Player mvpPlayer = a.compareScore(b);

  mvpPlayer.getInfo();

  return 0;
}
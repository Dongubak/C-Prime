#include "13-1.h"

#include <iostream>

TableTannisPlayer::TableTannisPlayer(const string& inputFirstName,
  const string& inputLastName,
  bool inputHasTable) : firstName(inputFirstName), lastName(inputLastName), hasTable(inputHasTable) { }
///member initializer list

void TableTannisPlayer::getName() const {
  std::cout << lastName << ", " << firstName;
}

//class RatedPlayer : public TableTannisPlayer {
//private:
//  unsigned int rating;
//
//public:
//  RatedPlayer(unsigned int inputRating = 0,
//    const string& inputFirstName = "none",
//    const string& inputLastName = "none",
//    bool inputHasTable = false);
//  RatedPlayer(unsigned int inputRating, const TableTannisPlayer& tp);
//  unsigned int getRate() {
//    return rating;
//  }
//};

RatedPlayer::RatedPlayer(unsigned int inputRating,
  const string& inputFirstName,
  const string& inputLastName,
  bool inputHasTable) : TableTannisPlayer(inputFirstName, inputLastName, inputHasTable) {
  rating = inputRating;
}

RatedPlayer::RatedPlayer(unsigned int inputRating,
  const TableTannisPlayer& tableTannisPlayerRef)
  : TableTannisPlayer(tableTannisPlayerRef), rating(inputRating) {

}
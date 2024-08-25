#ifndef TABLE_H_
#define TABLE_H_

#include <string>

using std::string;

class TableTannisPlayer {
private:
  string firstName;
  string lastName;
  bool hasTable;

public:
  TableTannisPlayer(const string& inputFirstName = "none", 
                    const string& inputLastName = "none", 
                    bool inputHasTable = false);
  void getName() const;
  bool IsHasTable() const {
    return hasTable;
  }
  void setHasTable(bool inputValue) {
    hasTable = inputValue;
  }

};

class RatedPlayer : public TableTannisPlayer {
private:
  unsigned int rating;

public:
  RatedPlayer(unsigned int inputRating = 0, 
              const string& inputFirstName = "none", 
              const string& inputLastName = "none", 
              bool inputHasTable = false);
  RatedPlayer(unsigned int inputRating, const TableTannisPlayer& tp);
  unsigned int getRate() {
    return rating;
  }
};

#endif // !TABLE_H_

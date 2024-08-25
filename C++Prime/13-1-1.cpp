#include "13-1.h"
#include <cstring>
#include <iostream>
#pragma warning(disable: 4996)

Cd::Cd(const char* inputPerformers, const char* inputLabel, int inputSelections, double inputPlaytime) {
  strcpy(performers, inputPerformers);
  strcpy(label, inputLabel);
  selections = inputSelections;
  playtime = inputPlaytime;
}

Cd::Cd(const Cd& inputCdRef) {
  strcpy(performers, inputCdRef.performers);
  strcpy(label, inputCdRef.label);
  selections = inputCdRef.selections;
  playtime = inputCdRef.playtime;
}

Cd::Cd() {
  strcpy(performers, "None");
  strcpy(label, "None");
  selections = 0;
  playtime = 0.0;
}

Cd::~Cd(){

}

void Cd::getInfo() const {
  std::cout << "performers : " << performers << '\n';
  std::cout << "label : " << label << '\n';
  std::cout << "selections : " << selections << '\n';
  std::cout << "playtime : " << playtime << '\n';
}

Cd& Cd::operator=(const Cd& inputCdRef) {
  if (this == &inputCdRef) {
    return *this;
  }

  strcpy(performers, inputCdRef.performers);
  strcpy(label, inputCdRef.label);
  selections = inputCdRef.selections;
  playtime = inputCdRef.playtime;
  
  return *this;
}


Classic::Classic(const char* inputTitleTrack, const char* inputPerformers, const char* inputLabel, int inputSelections, double inputPlaytime) : Cd(inputPerformers, inputLabel, inputSelections, inputPlaytime){
  strcpy(titleTrack, inputTitleTrack);
}

Classic::Classic() : Cd() {
  strcpy(titleTrack, "None");
}
Classic::~Classic() {

}
void Classic::getInfo() const {
  Cd::getInfo();
  std::cout << "title track : " << titleTrack << '\n';
}

Classic::Classic(const Classic& inputClassicRef) : Cd(inputClassicRef) {
  strcpy(titleTrack, inputClassicRef.titleTrack);
}

Classic& Classic::operator=(const Classic& inputClassicRef) {
  if (this == &inputClassicRef) {
    return *this;
  }

  Cd::operator=((Cd&)inputClassicRef);

  strcpy(titleTrack, inputClassicRef.titleTrack);
  return *this;
}
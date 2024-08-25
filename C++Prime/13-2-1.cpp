#include "13-2.h"
#include <cstring>
#include <iostream>
#pragma warning(disable: 4996)

Cd::Cd(const char* inputPerformers, const char* inputLabel, int inputSelections, double inputPlaytime) {
  /*strcpy(performers, inputPerformers);
  strcpy(label, inputLabel);*/

  performers = new char[strlen(inputPerformers) + 1];
  strcpy(performers, inputPerformers);

  label = new char[strlen(inputLabel) + 1];
  strcpy(label, inputLabel);

  selections = inputSelections;
  playtime = inputPlaytime;
}

Cd::Cd(const Cd& inputCdRef) { ///copy constructor
  /*strcpy(performers, inputCdRef.performers);
  strcpy(label, inputCdRef.label);*/

  performers = new char[strlen(inputCdRef.performers) + 1];
  strcpy(performers, inputCdRef.performers);

  label = new char[strlen(inputCdRef.label) + 1];
  strcpy(label, inputCdRef.label);

  selections = inputCdRef.selections;
  playtime = inputCdRef.playtime;
}

Cd::Cd() {
  /*strcpy(performers, "None");
  strcpy(label, "None");*/
  char defaultString[] = "None";

  performers = new char[strlen(defaultString) + 1];
  label = new char[strlen(defaultString) + 1];

  strcpy(performers, defaultString);
  strcpy(label, defaultString);

  selections = 0;
  playtime = 0.0;
}

Cd::~Cd() {
  delete[] performers;
  delete[] label;
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

  delete[] performers;
  delete[] label;

  performers = new char[strlen(inputCdRef.performers) + 1];
  label = new char[strlen(inputCdRef.label) + 1];

  strcpy(performers, inputCdRef.performers);
  strcpy(label, inputCdRef.label);


  selections = inputCdRef.selections;
  playtime = inputCdRef.playtime;

  return *this;
}


Classic::Classic(const char* inputTitleTrack, const char* inputPerformers, const char* inputLabel, int inputSelections, double inputPlaytime) : Cd(inputPerformers, inputLabel, inputSelections, inputPlaytime) {
  titleTrack = new char[strlen(inputTitleTrack) + 1];
  strcpy(titleTrack, inputTitleTrack);
}

Classic::Classic() : Cd() {
  char defaultString[] = "None";
  titleTrack = new char[strlen(defaultString) + 1];
  strcpy(titleTrack, defaultString);
}
Classic::~Classic() {
  delete[] titleTrack;
}
void Classic::getInfo() const {
  Cd::getInfo();
  std::cout << "title track : " << titleTrack << '\n';
}

Classic::Classic(const Classic& inputClassicRef) : Cd(inputClassicRef) {
  titleTrack = new char[strlen(inputClassicRef.titleTrack) + 1];
  strcpy(titleTrack, inputClassicRef.titleTrack);
}

Classic& Classic::operator=(const Classic& inputClassicRef) {
  if (this == &inputClassicRef) {
    return *this;
  }

  Cd::operator=((Cd&)inputClassicRef);

  titleTrack = new char[strlen(inputClassicRef.titleTrack) + 1];
  strcpy(titleTrack, inputClassicRef.titleTrack);

  return *this;
}
#include "13-3.h"
#include <cstring>
#pragma warning(disable: 4996)
//#ifndef DMA_H_
//#define DMA_H_
//
//class DMA_AbstractBaseClass {
//private:
//  char* label;
//  int rating;
//
//public:
//  DMA_AbstractBaseClass(char* inputLabel, int inputRating);
//  virtual ~DMA_AbstractBaseClass();
//  virtual DMA_AbstractBaseClass& operator=(const DMA_AbstractBaseClass& inputDMA_ABCRef) = 0;
//};
//
//#endif // !DMA_H_

DMA_AbstractBaseClass::DMA_AbstractBaseClass(const char* inputLabel, const int inputRating) {
  label = new char[strlen(inputLabel) + 1];
  strcpy(label, inputLabel);

  rating = inputRating;
}

DMA_AbstractBaseClass::~DMA_AbstractBaseClass() {
  delete[] label;
}

DMA_AbstractBaseClass& DMA_AbstractBaseClass::operator=(const DMA_AbstractBaseClass& inputDMA_ABCRef) {
  if (this == &inputDMA_ABCRef) {
    return *this;
  }
  delete[] label;
  label = new char[strlen(inputDMA_ABCRef.label) + 1];
  strcpy(label, inputDMA_ABCRef.label);

  rating = inputDMA_ABCRef.rating;

  return *this;
}

DMA_AbstractBaseClass::DMA_AbstractBaseClass(const DMA_AbstractBaseClass& DMA_ABCRef) {
  delete[] label;
  label = new char[strlen(DMA_ABCRef.label) + 1];
  strcpy(label, DMA_ABCRef.label);
  rating = DMA_ABCRef.rating;
}

const char* DMA_AbstractBaseClass::getLabel(void) const {
  return label;
}
const int DMA_AbstractBaseClass::getRating(void) const {
  return rating;
}

std::ostream& operator<<(std::ostream& osRef, DMA_AbstractBaseClass& inputDMA_ABCRef) {
  osRef << "label : " << inputDMA_ABCRef.label << " , rating : " << inputDMA_ABCRef.rating;

  return osRef;
}

//class baseDMA : public DMA_AbstractBaseClass {
//public:
//  baseDMA(char* inputLabel, int inputRating);
//  virtual ~baseDMA();
//  virtual baseDMA& operator=(const DMA_AbstractBaseClass& inputDMA_ABCRef);
//};

baseDMA::baseDMA(const char* inputLabel, const int inputRating) : DMA_AbstractBaseClass(inputLabel, inputRating) {
  
}

baseDMA::~baseDMA() {

}

baseDMA& baseDMA::operator=(const DMA_AbstractBaseClass& inputDMA_ABCRef) {
  if (this == &inputDMA_ABCRef) {
    return *this;
  }
  DMA_AbstractBaseClass::operator=(inputDMA_ABCRef);
  return *this;
}



std::ostream& operator<<(std::ostream& osRef, const baseDMA& baseDMARef) {
  return osRef << (DMA_AbstractBaseClass&)baseDMARef;
}
void baseDMA::getInfo(void) {
  std::cout << *this << '\n';
}

//class lacksDMA : public DMA_AbstractBaseClass {
//private:
//  char* color;
//
//public:
//  lacksDMA(const char* inputColor, const char* inputLabel, int inputRating);
//  lacksDMA(const char* inputColor, const baseDMA& baseDMARef);
//  virtual ~lacksDMA();
//  virtual lacksDMA& operator=(const DMA_AbstractBaseClass& inputDMA_AbCRef);
//
//  friend std::ostream& operator<<(std::ostream& osRef, const lacksDMA& lacksDMARef);
//};

baseDMA::baseDMA(const baseDMA& baseDMARef) : DMA_AbstractBaseClass(baseDMARef) {

}

lacksDMA::lacksDMA(const char* inputColor, const char* inputLabel, int inputRating) : DMA_AbstractBaseClass(inputLabel, inputRating) {
  color = new char[strlen(inputColor) + 1];
  strcpy(color, inputColor);
}

lacksDMA::lacksDMA(const char* inputColor, const baseDMA& baseDMARef) : DMA_AbstractBaseClass(baseDMARef) {
  color = new char[strlen(inputColor) + 1];
  strcpy(color, inputColor);
}

lacksDMA::~lacksDMA() {
  delete[] color;
}

lacksDMA& lacksDMA::operator=(const DMA_AbstractBaseClass& inputDMA_ABCRef) {
  if (this == &inputDMA_ABCRef) {
    return *this;
  }

  DMA_AbstractBaseClass::operator=(inputDMA_ABCRef);
  delete[] color;
  color = new char[strlen(((lacksDMA&)inputDMA_ABCRef).color) + 1];
  strcpy(color, ((lacksDMA&)inputDMA_ABCRef).color);

  return *this;
}

std::ostream& operator<<(std::ostream& osRef, const lacksDMA& lacksDMARef) {
  std::cout << (DMA_AbstractBaseClass&)lacksDMARef << ", color : " << lacksDMARef.color;
  
  return osRef;
}

void lacksDMA::getInfo(void) {
  std::cout << *this << '\n';
}
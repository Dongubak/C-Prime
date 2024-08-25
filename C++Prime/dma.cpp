#include "dma.h"
#include <cstring>

baseDMA::baseDMA(const char* inputString, int inputRate) {
  label = new char[std::strlen(inputString) + 1]; ///dynamic allocate
  strcpy(label, inputString); ///copy
  rating = inputRate; ///rating initialization
}

baseDMA::baseDMA(const baseDMA& inputBaseDMARef) { ///baseDMA's copy constructor
  label = new char[std::strlen(inputBaseDMARef.label) + 1]; ///dynamic allocate
  std::strcpy(label, inputBaseDMARef.label); ///copy
  rating = inputBaseDMARef.rating; ///copy rating
}

baseDMA::~baseDMA() { ///baseDMA's destructor
  delete[] label;
}

baseDMA& baseDMA::operator=(const baseDMA& inputBaseDMARef) { ///overloaded assignment operator
  if (this == &inputBaseDMARef) { ///self reference
    return *this;
  }

  delete[] label; ///free label memory
  label = new char[std::strlen(inputBaseDMARef.label) + 1]; ///dynamic allocate
  strcpy(label, inputBaseDMARef.label); ///copy
  rating = inputBaseDMARef.rating; ///copy rating

  return *this; ///return this
}

std::ostream& operator<<(std::ostream& osRef, const baseDMA& inputBaseDMARef) {
  osRef << "label : " << inputBaseDMARef.label << '\n';
  osRef << "rating : " << inputBaseDMARef.rating << '\n';
  return osRef;
}


lacksDMA::lacksDMA(const char* inputString, const char* inputLabel, int inputRate) : baseDMA(inputString, inputRate) {
  strncpy(color, inputString, 39);
  color[39] = '\0';
}

lacksDMA::lacksDMA(const char* inputString, const baseDMA& inputBaseDMARef) : baseDMA(inputBaseDMARef) {
  std::strncpy(color, inputString, COL_LEN - 1);
  color[COL_LEN - 1] = '\0';
}

std::ostream& operator<<(std::ostream& osRef, const lacksDMA& inputLackDMARef) {
  ///lacksDMA�� derived class�̸�, baseclass�� overloaded insertion operator����ϱ� ����
  ///reference to baseDMA������ conversion�� insertion operator ���
  osRef << (const baseDMA&)inputLackDMARef;
  osRef << "color : " << inputLackDMARef.color << '\n';
  return osRef;
}

hasDMA::hasDMA(const char* inputString, const char* inputLabel, int inputRate) : baseDMA(inputString, inputRate) { ///member initializer list����ؼ� baseDMA�� consturctorȣ�� ��
  ///derived class�� consturctor ���� ����
  ///hasDMA's constructor
  style = new char[std::strlen(inputString) + 1]; ///dynamic allocate
  strcpy(style, inputString); ///copy string
}

hasDMA::hasDMA(const char* inputString, const baseDMA& inputHasDMARef) : baseDMA(inputHasDMARef) {
  ///reference to baseDMA ���� ��, ����
  style = new char[std::strlen(inputString) + 1];
  strcpy(style, inputString);
}

hasDMA::hasDMA(const hasDMA& inputHasDMARef) :baseDMA(inputHasDMARef) { ///hasDMA's copy constructor
  style = new char[std::strlen(inputHasDMARef.style) + 1];
  strcpy(style, inputHasDMARef.style);
}

hasDMA::~hasDMA() { ///hasDMA's destructor
  delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& inputHasDMARef) { ///hasDMA's overloaded assignment operator
  if (this == &inputHasDMARef) { ///case of self reference
    return *this;
  }

  baseDMA::operator=(inputHasDMARef); ///baseRMA�� overloaded assignment operator ȣ��
  delete[] style; ///������ style memory ����

  style = new char[strlen(inputHasDMARef.style) + 1]; ///dynamic allocate
  strcpy(style, inputHasDMARef.style); ///copy reference's style
  return *this;
}

std::ostream& operator<<(std::ostream& osRef, const hasDMA& inputHasDMARef) {
  osRef << (const baseDMA&)inputHasDMARef; ///reference to baseDMA type���� ����ȯ �� overloaded insertion operator ���
  osRef << "style : " << inputHasDMARef.style << '\n';
  return osRef;
}
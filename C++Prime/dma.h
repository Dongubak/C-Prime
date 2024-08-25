#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class baseDMA {
private:
  char* label;
  int rating;

public:
  baseDMA(const char* inputLabel = "null", int inputRating = 0);
  baseDMA(const baseDMA& inputDMARef);
  virtual ~baseDMA();
  baseDMA& operator=(const baseDMA& inputDMARef);

  friend std::ostream& operator<<(std::ostream& osRef, const baseDMA& inputDMARef);
};

class lacksDMA : public baseDMA {
private:
  enum {COL_LEN = 40};
  char color[COL_LEN];

public:
  lacksDMA(const char* inputString = "blank", const char* inputLabel = "null", int inputRating = 0);
  lacksDMA(const char* inputString, const baseDMA& inputDMARef);
  friend std::ostream& operator<<(std::ostream& osRef, const lacksDMA& inputLackDMARef);
};

class hasDMA : public baseDMA {
private:
  char* style;

public:
  hasDMA(const char* inputString = "none", const char* inputLabel = "null", int inputRating = 0);
  hasDMA(const char* inputString, const baseDMA& inputBaseDMARef);
  hasDMA(const hasDMA& hasDMARef); ///copy constructor
  ~hasDMA();
  hasDMA& operator=(const hasDMA& inputHasDMARef);///overlassignment operator
  friend std::ostream& operator<<(std::ostream& osRef, const hasDMA& inputHasDMARef);
};

#endif // !DMA_H_

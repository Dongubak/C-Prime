#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class DMA_AbstractBaseClass {
private:
  char* label;
  int rating;

protected:
  const char* getLabel(void) const;
  const int getRating(void) const;

public:
  DMA_AbstractBaseClass(const char* inputLabel, int inputRating);
  virtual ~DMA_AbstractBaseClass();
  virtual DMA_AbstractBaseClass& operator=(const DMA_AbstractBaseClass& inputDMA_ABCRef) = 0;
  DMA_AbstractBaseClass(const DMA_AbstractBaseClass& DMA_ABCRef);
  friend std::ostream& operator<<(std::ostream& osRef, DMA_AbstractBaseClass& inputDMA_ABCRef);
  virtual void getInfo(void) = 0;
};

class baseDMA : public DMA_AbstractBaseClass {
public:
  baseDMA(const char* inputLabel, const int inputRating);
  virtual ~baseDMA();
  virtual baseDMA& operator=(const DMA_AbstractBaseClass& inputDMA_ABCRef);

  friend std::ostream& operator<<(std::ostream& osRef, const baseDMA& baseDMARef);

  baseDMA(const baseDMA& baseDMARef);
  virtual void getInfo(void);
};

class lacksDMA : public DMA_AbstractBaseClass {
private:
  char* color;
public:
  lacksDMA(const char* inputColor, const char* inputLabel, int inputRating);
  lacksDMA(const char* inputColor, const baseDMA& baseDMARef);
  virtual ~lacksDMA();
  virtual lacksDMA& operator=(const DMA_AbstractBaseClass& inputDMA_AbCRef);

  friend std::ostream& operator<<(std::ostream& osRef, const lacksDMA& lacksDMARef);

  virtual void getInfo(void);
};

#endif // !DMA_H_
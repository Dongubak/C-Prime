#ifndef _PLOG_H_
#define _PLOG_H_
#include <iostream>
#include <cstring>
#pragma warning(disable: 4996)
class Plorg {
private:
  char m_name[20]; ///include null
  int m_contentmentIndex;

public:
  Plorg();
  Plorg(const char *inputName);
  void getInfo();
  void setCI(int inputContentmentIndex);
};

#endif // !_PLOG_H_

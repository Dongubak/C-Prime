#ifndef CD_H_
#define CD_H_

class Cd {
protected:
  /*char performers[50];
  char label[20];*/
  char* performers;
  char* label;
  int selections;
  double playtime;

public:
  Cd(const char* inputPerformers, const char* inputLabel, int inputSelections, double inputPlaytime);
  Cd(const Cd& inputCdRef);
  Cd();
  virtual ~Cd();
  virtual void getInfo() const;
  Cd& operator=(const Cd& inputCdRef);
};

class Classic : public Cd {
private:
  /*char titleTrack[50];*/
  char* titleTrack;
public:
  Classic(const char* inputTitleTrack, const char* inputPerformers, const char* inputLabel, int inputSelections, double inputPlaytime);
  Classic(const Classic& inputClassicRef);
  Classic();
  virtual ~Classic();
  virtual void getInfo() const;
  Classic& operator=(const Classic& inputClassicRef);
};


#endif // !CD_H_

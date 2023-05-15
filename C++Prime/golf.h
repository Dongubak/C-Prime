const int Len = 40;
struct golf {
  char fullname[Len];
  int handicap;
};

void setgolf(golf& GolfStructReference, const char* inputName, int inputHandicap);
int setgolf(golf& GolfStructReference);

void setHandicap(golf& GolfStructReference, int inputHandicap);

void showgolf(const golf& GolfStructReference);
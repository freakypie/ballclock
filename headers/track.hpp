#pragma once
#include <list>

using namespace std;


class Clock;

class Track {
public:
  int max = 5;
  bool last = false;
  list<int> *balls;
  Clock *clock;

  Track(Clock *clock, int max, bool last);

  virtual ~Track() {
    delete this->balls;
  }

  int add(int ball);
};

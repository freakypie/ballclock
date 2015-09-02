#include "../headers/track.hpp"
#include "../headers/clock.hpp"


Track::Track(Clock *clock, int max, bool last) {
  this->clock = clock;
  this->max = max;
  this->last = last;
  this->balls = new list<int>();
};


int Track::add(int ball) {
  if (this->balls->size() == this->max - 1) {
    this->balls->reverse();
    for (auto b : *(this->balls)) {
      this->clock->balls->push_back(b);
      // this->clock.balls = this->clock.balls.concat this->balls.reverse()
    }
    this->balls->clear();
    return ball;
  } else {
    this->balls->push_back(ball);
    return -1;
  }
};

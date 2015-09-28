#include <iostream>

#include "../headers/clock.hpp"


Clock::Clock(int balls, float expectedDays) {
  this->max = balls;
  this->expectedDays = expectedDays;
  this->expectedMinutes = expectedDays * 24 * 60;
  this->balls = new list<int>();
  this->tracks = new list<Track*>();
  this->tracks->push_back(new Track(this, 5, false)); // 1 minute increments (5)
  this->tracks->push_back(new Track(this, 12, false)); // 5 minute increments (12)
  this->tracks->push_back(new Track(this, 12, true)); // 1 hour (12)

  for (auto x=0; x<this->max; x++) {
    this->balls->push_back(x);
  }
};


void Clock::tick() {

  // take the first ball out of the main pool
  int ball = this->balls->front();
  this->balls->pop_front();

  // add to the track and trickle the ball
  for (auto track : *(this->tracks)) {
    ball = track->add(ball);
    if (ball == -1) {
      break;
    }
  }

  if (ball != -1) {
    this->balls->push_back(ball);
  }

  // this->show()
  // prompt.question "> ready for next?:"

  return;
};

double Clock::calc () {
  auto minutes = 0;

  while (minutes < this->expectedMinutes) {
    minutes += 1;
    this->tick();
  }
  if (this->isReset()) {
    return minutes / (60 * 24);
  }
  return -1;
};

bool Clock::isReset() {
  auto index = 0;

  for (auto ball : *(this->balls)) {
    if (ball != index) {
      printf("ball %d %d", ball, index);
      // this->show();
      return false;
    }
    index += 1;
  }

  return true;
};

#pragma once
#include <list>

#include "./track.hpp"

using namespace std;


class Clock {
public:
  int max = 0;
  double expectedDays = 0.0;
  double expectedMinutes = 0.0;
  list<int> *balls;
  list<Track*> *tracks;

  Clock (int balls, float expectedDays);

  virtual ~Clock() {
    delete this->balls;
    delete this->tracks;
  }

  virtual void tick ();
  virtual double calc ();
  virtual bool isReset();

  // error: (msg) ->
  //   console.error "\n\n  #{msg}  \n\n"
  //
  //   this->show()
  //
  //   console.log "exiting"
  //   exit()
  //
  // show: () ->
  //   console.log "--------------"
  //   console.log "pool:", this->balls.length
  //
  //   for track in this->tracks
  //     console.log "track:", (b for b in track.balls)
};

#pragma once

#include <chrono>
#include <ctime>
#include <iostream>

using clock_type = std::chrono::high_resolution_clock;

class Timer {

public:
  // Construct and start the timer
  Timer(std::string name, bool local_map_idle = false, std::ostream &stream = std::cout);

  // Destruct and stop the timer, reporting the elapseed time
  ~Timer();

  // static void SetStream(std::ostream &str) { _default_str = &str; }

private:
  std::string _name;
  bool _local_map_idle;
  std::chrono::time_point<std::chrono::system_clock> _start;
  std::ostream *_default_str;

  static size_t _depth; //Counter of depth (number of timer objects should be depth of call ASUMING NO PARALLELISM)
  // static std::ostream *_default_str;
};
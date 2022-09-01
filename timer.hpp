#pragma once

#include <chrono>
#include <ctime>
#include <iostream>

using clock_type = std::chrono::system_clock;

class Timer {

public:
  // Construct and start the timer
  Timer(std::string name, std::ostream &stream = std::cout);

  // Destruct and stop the timer, reporting the elapseed time
  ~Timer();

  // static void SetStream(std::ostream &str) { _default_str = &str; }

private:
  std::string _name;
  std::chrono::time_point<std::chrono::system_clock> _start;
  std::ostream *_default_str;

  // static std::ostream *_default_str;
};
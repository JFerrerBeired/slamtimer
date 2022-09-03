#include "timer.hpp"

size_t Timer::_depth = 0; 

Timer::Timer(std::string name, std::ostream &stream)
    : _name(name), 
    _default_str(&stream) {
  _depth++;
  _start = clock_type::now();
}

// Destruct and stop the timer, reporting the elapseed time
Timer::~Timer() {
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(clock_type::now() - _start);
  *_default_str << std::string(_depth, '\t') << _name << " " << elapsed.count() << "\n";
  _depth--;
}
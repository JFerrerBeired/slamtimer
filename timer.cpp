#include "timer.hpp"

size_t Timer::_depth = 0; 

Timer::Timer(std::string name, bool local_map_idle, std::ostream &stream)
    : _name(name),
    _local_map_idle(local_map_idle), 
    _default_str(&stream) {
  _depth++;
  _start = clock_type::now();
}

// Destruct and stop the timer, reporting the elapseed time
Timer::~Timer() {
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(clock_type::now() - _start);
  *_default_str << std::string(_depth, '\t') << _name << " " << elapsed.count()/1e6 << " " << _local_map_idle << "\n";
  _depth--;
}
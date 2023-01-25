#pragma once

#include <iostream>
#include <vector>
//#include "../test_papi/papi/src/papi.h" 
#include <papi.h>

class PapiManager{
public:
    static void init();

    PapiManager(std::string name, std::vector<std::string> metrics, std::ostream &stream = std::cout);

    ~PapiManager();

private:
    std::string _name;
    std::ostream *_default_str;
    int _eventset = PAPI_NULL;
    std::vector<std::string> _event_names;
    std::vector<long long> _counters;
};
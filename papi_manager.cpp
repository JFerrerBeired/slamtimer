#include "papi_manager.hpp"

void PapiManager::init()
{
    int retval;
    retval=PAPI_library_init(PAPI_VER_CURRENT);
    if (retval!=PAPI_VER_CURRENT) {
            fprintf(stderr,"Error initializing PAPI! %s\n",
                    PAPI_strerror(retval));
            //return 0;
    }
}

PapiManager::PapiManager(std::string name, std::vector<std::string> metrics, std::ostream &stream)
    : _name(name), _default_str(&stream)
{
    int retval=PAPI_create_eventset(&_eventset);
    if (retval!=PAPI_OK) {
    fprintf(stderr,"PAPI: Error creating eventset! %s\n",
            PAPI_strerror(retval));
    }

    for(std::string event : metrics){
        retval=PAPI_add_named_event(_eventset, event.c_str()); //TODO: Evaluate overhead. What if they are already char* from the beggining?

        if (retval!=PAPI_OK) {
            fprintf(stderr,"PAPI: Error adding %s: %s\n",
                event.c_str(), PAPI_strerror(retval));
        }
        else {
            _counters.push_back(0);
            _event_names.push_back(event);
        }
    }

    retval=PAPI_start(_eventset);
    if (retval!=PAPI_OK) {
        fprintf(stderr,"PAPI: Error starting: %s\n",
            PAPI_strerror(retval));
    }
}

PapiManager::~PapiManager()
{
    int retval=PAPI_stop(_eventset, &_counters[0]); //The elements of a vector are contiguous.
    if (retval!=PAPI_OK) {
    fprintf(stderr,"PAPI: Error stopping:  %s\n",
        PAPI_strerror(retval));
    }
    else {
        *_default_str << "\tPAPI: " << _name << std::endl;

        while(_counters.size() > 0){
            *_default_str << "\t\t" << _event_names.back() << "\t" << _counters.back() << std::endl;
            _event_names.pop_back();
            _counters.pop_back();
        }
    }
}

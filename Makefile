build: timer.cpp papi_manager.cpp
	g++ -O0 -Wall -I ../test_papi/papi/src -o test_loop_papi loop.cpp timer.cpp papi_manager.cpp ../test_papi/papi/src/libpapi.a
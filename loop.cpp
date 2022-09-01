#include <cstdlib>
#include <iostream>

#include "timer.hpp"

#define LOOP for(int _i=0; _i<1e9; _i++);

void loop_a()
{
    auto t = Timer("loop_a");
    LOOP
}

void loop_b()
{
    auto t = Timer("loop_b");
    LOOP
}


void loop_1(const int its_loop_a, const int its_loop_b)
{
    auto t = Timer("loop_1");
    for(int i=0; i<its_loop_a; i++){
        loop_a();
    }

    for(int i=0; i<its_loop_b; i++){
        loop_b();
    }
        
}

void loop_2(const int its_loop_2)
{
    auto t = Timer("loop_2");
    for(int i=0; i<its_loop_2; i++){
        LOOP
    }
}

int main(int argc, char *argv[])
{
    if(argc!=4){
        return 1;
    }

    loop_1(atoi(argv[1]), atoi(argv[2]));
    loop_2(atoi(argv[3]));

    return 0;
}
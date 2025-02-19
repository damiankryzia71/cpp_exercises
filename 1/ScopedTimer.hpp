#ifndef SCOPEDTIMER_HPP
#define SCOPEDTIMER_HPP

#include <chrono>

class ScopedTimer
{
    private:
        std::chrono::high_resolution_clock::time_point startTime;
    public:
        ScopedTimer();
        ~ScopedTimer();
};

#endif
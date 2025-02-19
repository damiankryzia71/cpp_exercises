#include "ScopedTimer.hpp"
#include <iostream>

ScopedTimer::ScopedTimer()
{
    startTime = std::chrono::high_resolution_clock::now();
}

ScopedTimer::~ScopedTimer()
{
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << "Elapsed time: " << duration.count() << "ms" << std::endl;
}
#include "ScopedTimer.hpp"

void testFunction();

int main()
{
    testFunction();
    return 0;
}

void testFunction()
{
    ScopedTimer timer;
    for (volatile int i = 0; i < 1000000000; i++);
}
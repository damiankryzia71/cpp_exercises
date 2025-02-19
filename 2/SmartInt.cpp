#include "SmartInt.hpp"

SmartInt::SmartInt()
{
    value = std::make_unique<int>(0);
}

SmartInt::SmartInt(int newValue)
{
    value = std::make_unique<int>(newValue);
}

int SmartInt::get() const
{
    return *value;
}

void SmartInt::set(int newValue)
{
    *value = newValue;
}

int SmartInt::operator*() const
{
    return *value;
}

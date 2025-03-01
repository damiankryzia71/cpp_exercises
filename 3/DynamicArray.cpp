#include "DynamicArray.hpp"
#include <stdexcept>

DynamicArray::DynamicArray(int size)
{
    this->size_ = size;
    this->array_ = new int[size];
}

DynamicArray::~DynamicArray()
{
    delete[] this->array_;
}

int DynamicArray::get(int index)
{
    if (index >= 0 && index < this->size_)
    {
        return this->array_[index];
    }
    throw std::out_of_range("Index Error: Index is out of bounds");
}

void DynamicArray::set(int index, int value)
{
    if (index >= 0 && index < this->size_)
    {
        this->array_[index] = value;
    }
    else throw std::out_of_range("Index Error: Index is out of bounds");
}

int DynamicArray::operator[](int index) const
{
    if (index >= 0 && index < this->size_)
    {
        return this->array_[index];
    }
    throw std::out_of_range("Index Error: Index is out of bounds");
}

int& DynamicArray::operator[](int index)
{
    if (index >= 0 && index < this->size_)
    {
        return this->array_[index];
    }
    throw std::out_of_range("Index Error: Index is out of bounds");
}
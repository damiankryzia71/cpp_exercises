#include "MyString.hpp"
#include <iostream>
#include <cstring>
#include <stdexcept>

MyString::MyString(const char* input)
{
    if (input)
    {
        int size = std::strlen(input) + 1;
        this->str_ = new char[size];
        std::strcpy(this->str_, input);
        this->size_ = size;
    }
    else
    {
        this->str_ = new char[1];
        this->str_[0] = '\0';
        this->size_ = 0;
    }
}

MyString::~MyString()
{
    delete[] this->str_;
}

char MyString::operator[](int index) const
{
    if (index >= 0 && index < this->size_)
    {
        return this->str_[index];
    }
    throw std::out_of_range("Index Error: index out of range");
}


MyString& MyString::operator=(const MyString& other)
{
    if (this == &other)
    {
        return *this;
    }

    char* str = new char[std::strlen(other.str_) + 1];
    std::strcpy(str, other.str_);
    delete[] str_;
    this->str_ = str;
    return *this;
}

MyString MyString::operator+(const MyString& other) const
{
    int length = std::strlen(this->str_) + std::strlen(other.str_);
    char* newStr = new char[length + 1];
    std::strcpy(newStr, this->str_);
    std::strcat(newStr, other.str_);
    MyString result(newStr);
    delete[] newStr;
    return result;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    os << str.str_;
    return os;
}
#ifndef MY_STRING_HPP
#define MY_STRING_HPP

#include <iostream>

class MyString
{
    public:
        MyString(const char*);
        MyString(const MyString&);
        ~MyString();
        char operator[](int) const;
        MyString& operator=(const MyString&);
        MyString operator+(const MyString&) const;
        friend std::ostream& operator<<(std::ostream&, const MyString&);

    private:
        char* str_ = nullptr;
        int size_;
};

#endif
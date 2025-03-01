#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

class DynamicArray
{
    public:
        DynamicArray(int);
        ~DynamicArray();
        int operator[](int) const;
        int& operator[](int);
        int get(int);
        void set(int, int);

    private:
        int* array_ = nullptr;
        int size_;
};

#endif
#include "Stack.hpp"
#include <stdexcept>

template <typename T>
Stack<T>::Stack()
{
    capacity = 100;
    topIndex = -1;
    data = new T[capacity];
}

template <typename T>
Stack<T>::Stack(int newCapacity)
{
    capacity = newCapacity;
    topIndex = -1;
    data = new T[capacity];
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] data;
}

template <typename T>
void Stack<T>::push(T element)
{
    if (topIndex + 1 == capacity)
    {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i < topIndex + 1; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

    data[++topIndex] = element;
}

template <typename T>
T Stack<T>::pop()
{
    if (topIndex < 0) throw std::out_of_range("Stack Underflow: Cannot pop from an empty stack.");
    return data[topIndex--];
}

template <typename T>
T Stack<T>::peek() const
{
    if (topIndex < 0) throw std::out_of_range("Stack Underflow: Cannot peek into an empty stack.");
    return data[topIndex];
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return topIndex < 0;
}

template <typename T>
int Stack<T>::getSize() const
{
    return topIndex + 1;
}
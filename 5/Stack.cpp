#include "Stack.hpp"
#include <stdexcept>

template <typename T>
Stack<T>::Stack()
{
    size = 0;
    capacity = 50;
    data = new T[capacity];
}

template <typename T>
Stack<T>::Stack(int newCapacity)
{
    size = 0;
    capacity = newCapacity;
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
    if (size == capacity)
    {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = element;
}

template <typename T>
T Stack<T>::pop()
{
    if (size == 0)
        throw std::out_of_range("Out of range error: stack is empty");
    return data[size--];
}

template <typename T>
T Stack<T>::peek() const
{
    if (size == 0)
        throw std::out_of_range("Out of range error: stack is empty");
    return data[size - 1];
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
int Stack<T>::getSize() const
{
    return size;
}
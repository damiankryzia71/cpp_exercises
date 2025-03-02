#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
class Stack
{
    public:
        Stack();
        Stack(int);
        ~Stack();
        void push(T);
        T pop();
        T peek() const;
        bool isEmpty() const;
        int getSize() const;

    private:
        T* data = nullptr;
        int size;
        int capacity;
};

#endif
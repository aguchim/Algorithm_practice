#pragma once
#include <iostream>
#include <stdio.h>

template<typename T>
class Stack {
public:
    Stack();
    ~Stack();

    void    Push(T Value);
    T       Pop();
    int     GetCount();
    void    StackFull();
private:
    int  top;
    int  capacity;
    T* stack;
};


template<typename T>
 Stack<T>::Stack()
{
    top = 0;
    capacity = 2;
    stack = new T[capacity];
}

template<typename T>
Stack<T>::~Stack()
{
}

template<typename T>
int Stack<T>::GetCount()
{
    return top;
}

template<typename T>
void Stack<T>::Push(T Value)
{
    if (top >= capacity)
    {
        StackFull();
    }
    stack[top++] = Value;
}

template<typename T>
T Stack<T>::Pop()
{
    if (top < 0)
    {
        std::cout << "\n더 빼낼것이 없습니다!";
        return -1;
    }
    return stack[--top];
}

template<typename T>
void Stack<T>::StackFull()
{
    int* temp = new T[capacity];
    for (int i = 0; i < top; i++)
        temp[i] = stack[i];
    delete[] stack;
    capacity *= 2;
    stack = new T[capacity];
    for (int i = 0; i < top; i++)
        stack[i] = temp[i];
    delete[] temp;
    std::cout << capacity;
}


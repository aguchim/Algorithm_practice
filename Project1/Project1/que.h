#pragma once
#include <iostream>
#include <stdio.h>

template<typename T>
class Que {
public:
    Que();
    ~Que();

    void    PushBack(T Value);
    T       PopFront();
    int     GetCount();
    void    StackFull();
private:
    int  Back;
    int  Front;
    int  capacity;
    T* stack;
};


template<typename T>
Que<T>::Que()
{
    Back = 0;
    Front = 0;
    capacity = 2;
    stack = new T[capacity];
}

template<typename T>
Que<T>::~Que()
{
}

template<typename T>
int Que<T>::GetCount()
{
    return (capacity + Back - Front) % capacity;
}

template<typename T>
void Que<T>::PushBack(T Value)
{
    //스텍늘리기
    //Back만 늘리기
    Back++;
    if (Back >= capacity)
    {
        Back = 0;
    }
    if (Back == Front)
    {
        StackFull();
    }
    stack[Back] = Value;
}

template<typename T>
T Que<T>::PopFront()
{
    //Back만 늘리기
    if (Front == Back)
    {
        Front = 0;
        Back = 0;
        std::cout << "\n더 빼낼것이 없습니다!";
        return -1;
    }
    if (Front >= capacity)
    {
        Front = 0;
    }
    return stack[++Front];
}

template<typename T>
void Que<T>::StackFull()
{
    int* temp = new T[capacity];
    for (int i = 0; i < capacity; i++)
        temp[i] = stack[(Front + i) % capacity];
    delete[] stack;

    Front = 0;
    Back = capacity;

    capacity *= 2;
    stack = new T[capacity];
    for (int i = 0; i < capacity; i++)
        stack[i] = temp[i];
    delete[] temp;
}


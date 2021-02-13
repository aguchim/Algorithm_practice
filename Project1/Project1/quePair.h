#pragma once
#include <iostream>
#include <stdio.h>

template<typename T>
class QuePair {
public:
    QuePair();
    ~QuePair();

    void    PushBack(T Value);
    void    PushFront(T Value);
    T       PopFront();
    T       PopBack();
    int     GetCount();
    void    StackFull();
    void    printing();
private:
    int  Back;
    int  Front;
    bool IsAnything;
    int  capacity;
    T* stack;
};

template<typename T>
void QuePair<T>::printing()
{
    std::cout << "\n개수 : ";
    std::cout << GetCount();
    std::cout << "\n시작점! : ";
    std::cout << Front;
    std::cout << "\n";
    std::cout << "끝점!";
    std::cout << Back;
    std::cout << "\n";

    for (size_t i = 0; i < GetCount(); i++)
    {
        std::cout << "[ ";
        std::cout << i;
        std::cout << "번째] [";
        std::cout << (Front + i) % capacity;
        std::cout << "번배열] [";
        std::cout << stack[(Front+i) % capacity];
            std::cout << "내용]\n";
    }
}

template<typename T>
QuePair<T>::QuePair()
{
    Back = -1;
    Front = -1;
    IsAnything = false;
    capacity = 2;
    stack = new T[capacity];
}

template<typename T>
QuePair<T>::~QuePair()
{
}

template<typename T>
int QuePair<T>::GetCount()
{
    return (capacity + Back - Front) % capacity +1;
}

template<typename T>
void QuePair<T>::PushBack(T Value)
{
    Back++;
    if (Back >= capacity)
    {
        Back = 0;
    }
    if (Back == Front)
    {
        StackFull();
        Back++;
    }
    stack[Back] = Value;

    if (!IsAnything)
    {
        IsAnything = true;
        Front = 0;
    }
}

template<typename T>
void QuePair<T>::PushFront(T Value)
{
    Front--;
    if (Front < 0)
    {
        Front = capacity-1;
    }
    if (Back == Front)
    {


        Front= (Front+1)% capacity;
        StackFull();
        Front = capacity - 1;


    }
    stack[Front] = Value;
    if (!IsAnything)
    {
        IsAnything = true;
        Back = Front;
    }
}

template<typename T>
T QuePair<T>::PopFront()
{
    if (!IsAnything)
    {
        std::cout << "\n더 빼낼것이 없습니다!\n";
        return -1;
    }
    if (Front >= capacity)
    {
        Front = 0;
    }
    T RetrunVal = stack[Front];
    if (Front == Back)
    {
        IsAnything = false;
        Front = -1;
        Back = -1;
    }
    Front++;
    return RetrunVal;
}

template<typename T>
T QuePair<T>::PopBack()
{
    if (!IsAnything)
    {
        std::cout << "\n더 빼낼것이 없습니다!\n";
        return -1;
    }
    if (Back < 0)
    {
        Back = capacity-1;
    }
    T RetrunVal = stack[Back];
    if (Front == Back)
    {
        IsAnything = false;
        Front = -1;
        Back = -1;
    }
    Back--;
    return RetrunVal;
}

template<typename T>
void QuePair<T>::StackFull()
{
    int* temp = new T[capacity];
    for (int i = 0; i < capacity; i++)
    {
        temp[i] = stack[(Front + i) % capacity];
    }
    delete[] stack;

    Front = 0;
    Back = capacity-1;

    capacity *= 2;
    stack = new T[capacity];
    for (int i = 0; i < capacity/2; i++)
        stack[i] = temp[i];
    delete[] temp;
}


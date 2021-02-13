#include <iostream>
#include <string>
#include <list>
#include <random>
#include "stack.h"
#include "que.h"
#include "quePair.h"

void Stack_Test();
void Que_Test();
void QuePair_Test();

int main()
{
    QuePair_Test();
    return 0;
}

void QuePair_Test()
{
    QuePair<int> Que;
    int n;
    for (size_t i = 0; i < 35; i++)
    {
        n = rand();
        Que.PushFront(n);
        std::cout << "[";
        std::cout << n;
        std::cout << "]\n";
    }
    n = Que.GetCount();
    Que.printing();

    for (size_t i = 0; i < n; i++)
    {
        std::cout << "[ ";
        std::cout << i;
        std::cout << " : ";
        std::cout << Que.PopBack();
        std::cout << " ]\n";
    }
}

void Que_Test()
{
    Que<int> Que;
    int n;
    for (size_t i = 0; i < 35; i++)
    {
        n = rand();
        Que.PushBack(n);
        std::cout << "[";
        std::cout << i;
        std::cout << "] : ";
        std::cout << n;
        std::cout << "\n";
    }
    std::cout << "\n개수 : ";
    n = Que.GetCount();
    std::cout << Que.GetCount();
    std::cout << "\n";

    for (size_t i = 0; i < n; i++)
    {
        std::cout << "\n";
        std::cout << Que.PopFront();
    }
}

void Stack_Test()
{
    Stack<int> Stack;
    int n;
    for (size_t i = 0; i < 35; i++)
    {
        n = rand();
        Stack.Push(n);
        std::cout << n;
        std::cout << "\n";
    }
    std::cout << "개수 : ";
    n = Stack.GetCount();
    std::cout << Stack.GetCount();
    for (size_t i = 0; i < n; i++)
    {
        std::cout << "\n";
        std::cout<<Stack.Pop();
    }
}
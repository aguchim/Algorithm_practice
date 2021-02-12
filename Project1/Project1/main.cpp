#include <iostream>
#include <string>
#include <list>
#include <random>
#include "stack.h"

int main()
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
    std::cout << "°³¼ö : ";
    n = Stack.GetCount();
    std::cout << Stack.GetCount();
    for (size_t i = 0; i < n; i++)
    {
        std::cout << "\n";
        std::cout<<Stack.Pop();
    }
}
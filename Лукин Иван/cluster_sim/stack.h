﻿#ifndef __STACK_H__
#define __STACK_H__

#include <algorithm>

using namespace std;

const int MaxStackSize = 10000;

template <class T>
class TStack
{
    size_t size;
    T *pMem;
    int top;
public:
    TStack() :size(1), top(-1), pMem(new T[size]) {}
    TStack(size_t _size)
    {
        size = _size;
        top = -1;
        if ((size < 1) || (size > MaxStackSize))
            throw size;
        pMem = new T[size];
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void push(const T& elem)
    {
        if (top == MaxStackSize - 1)
            throw "is Full!";
        if (top == size - 1)
        {
            T* tmp = new T[size*2];
            std::copy(pMem, pMem + top + 1, tmp);
            size *= 2;
            delete[] pMem;
            pMem = tmp;
        }
        pMem[++top] = elem;
    }
    T pop()
    {
        if (isEmpty())
            throw "Stack is Empty!";
        return pMem[top--];
    }
    T get_top()
    {
        if (isEmpty())
            throw "Stack is Empty!";
        return pMem[top];
    }
    size_t stack_size()
    {
        return size;
    }
    int get_top_pos()
    {
        return top;
    }
    ~TStack()
    {
        delete [] pMem;
    }
};

#endif

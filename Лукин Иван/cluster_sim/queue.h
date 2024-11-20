#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "stack.h"

template <class T>
class Queue
{
	TStack<T> LeftStack, RightStack;
	int tail;
public:
	Queue() :LeftStack{}, RightStack{}, tail(-1) {}
	Queue(size_t size) :RightStack(size), LeftStack(size), tail(-1) {}
	void push(const T& elem)
	{
		if (LeftStack.stack_size() + RightStack.stack_size() >= MaxStackSize)
			throw "is Full";
		LeftStack.push(elem);
		tail++;
	}
	T pop()
	{
		if (RightStack.isEmpty())
		{
			if (isEmpty())
				throw "queue is empty!";
			while (!LeftStack.isEmpty())
				RightStack.push(LeftStack.pop());
		}
		tail--;
		return RightStack.pop();
	}
	bool isEmpty() noexcept
	{
		return (LeftStack.isEmpty() && RightStack.isEmpty());
	}
	size_t size() noexcept
	{
		return LeftStack.stack_size();
	}
	~Queue() = default;
};

#endif 




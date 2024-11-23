#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "stack.h"

const int MaxQueuesize = MaxStackSize;

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
		if (LeftStack.get_top_pos() + RightStack.get_top_pos() >= MaxStackSize)
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

	T get_head()
	{
		if (RightStack.isEmpty())
		{
			if (isEmpty())
				throw "queue is empty!";
			while (!LeftStack.isEmpty())
				RightStack.push(LeftStack.pop());
		}
		return RightStack.get_top();
	}

	bool isEmpty() noexcept
	{
		return (LeftStack.isEmpty() && RightStack.isEmpty());
	}

	size_t get_size() noexcept
	{
		return LeftStack.stack_size();
	}

	int get_tail_pos() noexcept
	{
		return tail;
	}

	~Queue() = default;
};

#endif 




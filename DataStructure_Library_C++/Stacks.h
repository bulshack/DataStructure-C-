#pragma once
#include "Libraries.h"
template< class T>
class stacks 
{
	 LinkedList<T> List;

public:
	
	void push(T value)
	{
		List.insert_node(value);
	}

	void pop()
	{

	}

	void peek()
	{

	}
};
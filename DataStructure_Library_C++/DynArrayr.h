#pragma once
#include "Libraries.h"

template <class T>
class smart_Array
{
private:
	const int GROW_FACTOR = 2;

	size_t p_size, p_capacity;

	T* data = nullptr;

public:
	smart_Array()
	{
		p_capacity = p_size = 0;

		data = nullptr;
	}

	smart_Array(int size)
	{
		p_size = size;

		p_capacity = size;

		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = NULL;
		}
	}

	~smart_Array()
	{
		delete[] data;
	}

	bool is_empty();
	T& operator[](int);
	int size() const;
	int capaciy() const;
	T getFront() const;
	T getBack() const;
	void set(int index, T value);
	T getAt(size_t index);
	void resize();
	void setCapacity(int value);
	void push(T value);
	void printArray();
	void printstatus();
	T pop();
	void Erase(int index);
	void ReverseArray();
};

template <class T>
bool smart_Array<T>::is_empty()
{
	if (p_size == 0)
		return true;
	else
		return false;
}

template <class T>
T& smart_Array<T>::operator[](int index)
{
	return data[index];
}

template <class T>
int smart_Array<T>::size() const
{
	return p_size;
}

template <class T>
int smart_Array<T>::capaciy() const
{
	return p_capacity;
}

template <class T>
void smart_Array<T>::set(int index, T value)
{
	if (p_size > index)
		data[index] = value;
}

template <class T>
T smart_Array<T>::getAt(size_t index)
{
	return data[index];
}

template <class T>
void smart_Array<T>::resize()
{
	if (p_size >= p_capacity)
		p_capacity *= GROW_FACTOR;

	T* temp = new T[p_size * GROW_FACTOR];

	for (int i = 0; i < p_size * GROW_FACTOR; i++)
	{
		if (i <= p_size)
		{
			temp[i] = data[i];
		}
		else
		{
			temp[i] = NULL;
		}
	}

	if (data != nullptr)
		delete[] data;

	data = temp;
}

template <class T>
void smart_Array<T>::setCapacity(int value)
{
	if (value > p_size)
	{
		T* temp = new T[value];

		for (size_t i = 0; i < p_size; i++)
		{
			if (i <= p_size)
				temp[i] = data[i];
			else
				temp[i] = NULL;
		}

		if (data != nullptr)
			delete[] data;

		data = temp;
	}
	else
		std::cout << "This array is null, the action coud not be done. Set Capacity Fail" << std::endl;
}

template <class T>
void smart_Array<T>::push(T value)
{
	if (data != nullptr)
	{
		if (p_size >= p_capacity)
			resize();

		data[p_size - 1] = value;
	}
}

template <class T>
T smart_Array<T>::pop()
{
	T temp = data[p_size - 1];

	data[p_size - 1] = NULL;

	p_size -= 1;

	return temp;
}

template <class T>
void smart_Array<T>::printArray()
{
	if (data != nullptr)
	{
		for (size_t i = 0; i < p_size; i++)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
}

template <class T>
void smart_Array<T>::printstatus()
{
	if (data != nullptr)
	{
		std::cout << "Current Capacity: " << p_capacity << std::endl;
		std::cout << "Current Size: " << p_size << std::endl;
	}
}

template <class T>
void smart_Array<T>::Erase(int index)
{
	if (index >= 0 && index < p_size)
	{
		data[index] = NULL;

		for (size_t i = index; i < p_size; i++)
		{
			data[i] = data[i + 1];
		}

		data[p_size - 1] = NULL;
		p_size -= 1;
	}
}

template <class T>
void smart_Array<T>::ReverseArray()
{
	int number = p_size - 1;
	T* temp = new T[p_capacity];

	for (size_t i = p_size - 1; i >= 0; i--)
	{
		temp[number - i] = data[i];

		if (i == 0)
		{
			break;
		}
	}

	if (data != nullptr)
	{
		delete[] data;
	}

	data = temp;
}

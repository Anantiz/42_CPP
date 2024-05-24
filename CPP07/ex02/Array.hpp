#pragma once

#include <string>
#include <iostream>

template<typename T>
class Array
{
private:

	unsigned int	_size;
	T				*_data;

	Array() {} // Not allowed

public:

	~Array()
	{
		delete [] _data;
	}

// Operators

	const T	&operator[](unsigned int i) const
	{
		if (i >= _size)
			throw std::exception();
		else
			return _data[i];
	}

	T	&operator[](unsigned int i)
	{
		if (i >= _size)
			throw std::exception();
		else
			return _data[i];
	}

	Array	&operator=(const Array &right)
	{
		_data = new T[right._size];
		_size = right._size;

		return *this;
	}

// Constructors

	Array(const Array &cpy)
	{
		*this = cpy;
	}

	Array(unsigned int n)
	{
		_data = new T[n];
		_size = n;
	}

// Member functions

	unsigned int size() const { return _size; }

};
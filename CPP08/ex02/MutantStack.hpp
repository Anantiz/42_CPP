#pragma once

#include <stack>
#include <deque>

// Since Stack is actually not a container
// We Have to instantiate it using a container (default is deque)
// So it looks weird but that's cpp.

template <typename T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
private:

public:

	MutantStack() {};
	~MutantStack() {};

	MutantStack(const MutantStack& other)
	{
		*this = other;
	}
	MutantStack& operator=(const MutantStack& other)
	{
		this->c = other.c;
		return *this;
	}

	// Because we want to call MutantStack<int>::iterator
	// and not MutantStack<int>::Container::iterator
	typedef typename Container::iterator iterator;
	// We write `typename` to tell the compiler that `Container::iterator`
	// is a type and not a static member of a `Container` class


	// Here we return the iterator of the container used by the stack
	iterator begin()
	{
		return this->c.begin();
	}

	// Guess what this does :)
	iterator end()
	{
		return this->c.end();
	}

};
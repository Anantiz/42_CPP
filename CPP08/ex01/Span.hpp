#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

void	ft_quicksort(ssize_t *list, ssize_t low_index, ssize_t high_index);

class Span
{
private:

	unsigned int			_N;
	std::vector<ssize_t>	_v;

	Span( void );

public:

// Constructors && operators

	Span(unsigned int N);
	~Span();

	Span(Span const &other);
	Span &operator=(Span const &other);

// Methods

	void addNumber(ssize_t n);

	ssize_t shortestSpan();
	ssize_t longestSpan();

	void fill();
};
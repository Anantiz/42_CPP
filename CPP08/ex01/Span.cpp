#include "Span.hpp"

Span::Span() {} // Illegal

Span::~Span() {} // No dynamic allocation


Span::Span(unsigned int N) : _N(N) {
	_v.reserve(N);
}

Span::Span(Span const &other) {
	*this = other;
}

// Deep copy of the vector
Span &Span::operator=(Span const &other) {
	_N = other._N;
	_v = other._v;
	return *this;
}

void Span::addNumber(ssize_t n) {
	if (_v.size() >= _N)
		throw std::runtime_error("Span is full");
	_v.push_back(n);
}

/*
	Sort the vector and comapare each neighbour
*/
ssize_t Span::shortestSpan() {

	ssize_t diff;
	ssize_t min = LONG_MAX;

	if (_v.size() <= 1)
		throw std::runtime_error("Not enough elements");
	ft_quicksort(_v.data(), 0, _v.size() - 1);

	for (size_t i = 0; i < _v.size() - 1; i++) {

		diff = static_cast<ssize_t>(std::abs(_v[i + 1] - _v[i]));
		if (diff < min)
			min = diff;
	}
	return min;
}

ssize_t Span::longestSpan() {

	if (_v.size() <= 1)
		throw std::runtime_error("Not enough elements");
	ft_quicksort(_v.data(), 0, _v.size() - 1);
	return static_cast<ssize_t>(std::abs(_v[0] - _v[_v.size() - 1]));
}

void Span::fill()
{
	if (_v.size() == _N)
		throw std::runtime_error("Span is full");

	std::list<ssize_t>    l( _N - _v.size());	// Create list with remaining space
	std::srand( time ( NULL ) );				// Seed rng
	// Apply rand to each element of the list
	std::generate( l.begin(), l.end(), std::rand );

	_v.insert(_v.end(), l.begin(), l.end());


}


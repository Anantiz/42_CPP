#include "Span.hpp"

int main() {


	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Known list:\n\tShortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "\tLongest span:  " << sp.longestSpan() << std::endl;

	// Create a Span with 10000 elements

	Span sp2 = Span(100);
	sp2.fill();
	std::cout << "Random list:\n\tShortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "\tLongest span:  " << sp2.longestSpan() << std::endl;

	return 0;
}
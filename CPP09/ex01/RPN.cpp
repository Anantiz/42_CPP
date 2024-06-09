#include "RPN.hpp"

#define SUPER_LONG_STRING "Invalid expression, number is either multi-digit or \
stuck to an operator without a space in between (Subject said to only handle si\
ngle digits, it makes parsing easier so of course I will comply lmao)"

RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(std::string expression) : _expression(expression)
{

	validate();
	std::cout << "Result: " << compute() << std::endl;
}

// Check if the expression is valid
void	RPN::validate( void )
{
	if (_expression.empty())
		throw std::invalid_argument("Empty expression");
	// Look at that function name lmao, next well have `do_exactly_this_and_like_nothing_else_except_for_that_one_exception_and_that_other_one_too()`
	if (_expression.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::invalid_argument("Invalid character in expression");
}

ssize_t	RPN::compute( void )
{
	ssize_t	pos = 0;
	bool	was = false;

	while (_expression[pos])
	{
		char c = _expression[pos];

		if (c == ' ') {was = false;} // Skip spaces
		else if (std::isdigit(c))
		{
			if (was)
				throw std::invalid_argument(SUPER_LONG_STRING);
			_stack.push(c - '0'); was = true;
		}
		else
		{
			if (was)
				throw std::invalid_argument(SUPER_LONG_STRING);
			if (_stack.size() < 2)
				throw std::invalid_argument("Invalid expression, not enough numbers for operator");
			ssize_t n = _stack.top(); _stack.pop();
			n = doOp(c, _stack.top(), n);
			_stack.top() = n;
			if (n < 0)
				throw std::invalid_argument("ERROR: Overflow detected");
		}
		pos++;
	}
	if (_stack.size() != 1)
		throw std::invalid_argument("Invalid expression, too many numbers");
	return _stack.top();
}

inline static ssize_t rpnadd(ssize_t a, ssize_t b) {return a + b;}
inline static ssize_t rpnsub(ssize_t a, ssize_t b) {return a - b;}
inline static ssize_t rpnmul(ssize_t a, ssize_t b) {return a * b;}
inline static ssize_t rpndiv(ssize_t a, ssize_t b) {return a / b;}

ssize_t RPN::doOp(char op, ssize_t a, ssize_t b) const
{
	switch (op)
	{
		case '+': return rpnadd(a, b);
		case '-': return rpnsub(a, b);
		case '*': return rpnmul(a, b);
		case '/': return rpndiv(a, b);
		default: throw std::invalid_argument("Invalid operator");
	}
}

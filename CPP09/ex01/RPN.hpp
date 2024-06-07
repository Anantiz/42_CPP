#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <sys/types.h>


class RPN
{
private:


	std::string		_expression;
	std::stack<ssize_t>	_stack;

	RPN( void);
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);

	ssize_t doOp(char op, ssize_t a, ssize_t b) const;

public:

	RPN(std::string expression);
	~RPN();

	void		validate( void);
	ssize_t			compute( void);
};


/*
Input examples:

So fun ! Much wow ! So Exciting ! I love RPN !

	(a + b) * 3                 === a b + 3 *
	(a + b) * (c + d)           === a b + c d + *
	(a + b) * (c + d) * (e + f) === a b + c d + e f + * *

*/
#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

#include <cctype>
#include <limits>
#include <cmath>
#include <iomanip>

/*

*/
class ScalarConverter
{
private:

	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &cpy);
	ScalarConverter	&operator=(const ScalarConverter &right);

public:

	static bool convert(std::string str);

};
#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

#include <cctype>
#include <limits>
#include <limits.h>
#include <cmath>
#include <iomanip>
#include <string.h>

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

bool 	validate_input(std::string str);
double	convert_input_nd(std::string str, bool &status);
float	convert_input_nf(std::string str, bool &status);
int		convert_input_ni(std::string str, bool &status);
void	init_others(int &ni, float &nf, double &nd, bool valid[3]);

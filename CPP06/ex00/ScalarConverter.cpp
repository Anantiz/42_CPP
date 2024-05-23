#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	(void)cpy;
}
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &right)
{
	(void)right;
	return *this;
}

static void	print_char(char n, bool possible)
{
	std::cout << "char:   ";
	if (!possible)
		std::cout << "Imposible";
	else if (!isprint(n))
		std::cout << "Non displayable";
	else
		std::cout << "\'" << n << "\'";
	std::cout << std::endl;
}

static void	print_int(int n, bool possible)
{
	std::cout << "int:    ";
	if (!possible)
		std::cout << "Imposible";
	else
		std::cout << n;
	std::cout << std::endl;
}

static void print_float(float n, bool possible)
{
	std::string	f = "f";

	std::cout << "float:  ";
	if (!possible)
		std::cout << "Imposible";
	else
		std::cout << std::fixed << std::setprecision(1) << n << f;
	std::cout << std::endl;

}

static void print_double(double n, bool possible)
{
	std::cout << "double: ";
	if (!possible)
		std::cout << "Imposible";
	else
		std::cout << std::fixed << std::setprecision(1) << n;
	std::cout << std::endl;
}


/*
Output in stdin the representation of a value (Given as the input string) in different formats
	- Char
	- Int
	- Float
	- double
*/
bool ScalarConverter::convert(std::string str)
{
	double	nd;
	float	nf;
	int		ni;
	bool	valid[] = {false, false, false, false};

	if (!validate_input(str))
		return (false);

	ni = convert_input_ni(str, valid[0]);
	if (!valid[0])
	{
		nf = convert_input_nf(str, valid[1]);
		if (!valid[1])
			nd = convert_input_nd(str, valid[2]);
	}
	init_others(ni, nf, nd, valid);

	// A char is an int, do be annoying
	print_char(static_cast<char>(ni), valid[3]);
	print_int(ni, valid[0]);
	print_float(nf, valid[1]);
	print_double(nd, valid[2]);
	return (true);
}
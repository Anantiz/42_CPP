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

// Checks if there is only one word
static bool validate_input(std::string str)
{
	int i=0;
	while (str[i] && isspace(str[i]))
		i++;
	while (str[i] && !isspace(str[i]))
		i++;
	while (str[i] && isspace(str[i]))
		i++;
	if (str[i])
		return (false);
	return (true);
}

double	convert_input(std::string str)
{
	if (str == "+inf")
		return (std::numeric_limits<double>::infinity());
	if (str == "-inf")
		return (-std::numeric_limits<double>::infinity());

	if (str == "+inff")
		return (std::numeric_limits<float>::infinity());
	if (str == "-inff")
		return (-std::numeric_limits<float>::infinity());

	if (str == "nan" || str == "nanf")
		return (std::numeric_limits<double>::quiet_NaN());

	return (atof(str.c_str()));
}

static void	print_char(double n)
{
	if (std::isnan(n))
	{
		std::cout << "char: " << "Impossible" << std::endl;
		return ;
	}
	else
		n = floor(n);


	if (n < 0 || n > 126)
		std::cout << "char:   " << "Impossible" << std::endl;
	else if (!isprint(  static_cast<char>(n)))
		std::cout << "char:   " << "Non displayable" << std::endl;
	else
		std::cout << "char:   \'" << static_cast<char>(n) << "\'" << std::endl;
}

static void	print_int(double n)
{
	if (std::isnan(n))
	{
		std::cout << "int:    " << "Impossible" << std::endl;
		return ;
	}
	else
		n = floor(n);


	if (n < -2147483648 || n > 2147483647)
		std::cout << "int:    " << "Impossible" << std::endl;
	else
		std::cout << "int:    " << static_cast<int>(n) << std::endl;

}

static void print_float(std::string str, double n2)
{
	std::string	f = "f";
	float		n;
	(void)str;

	if (std::isnan(n2) || n2 < __FLT_MIN__ || n2 > __FLT_MAX__ )
	{
		f = "";
		n = static_cast<float>(n2);
	}
	else
	{
		n = static_cast<float>(n2);
		// Actually implement a way to keep this gfloat accurate
	}

	std::cout << std::fixed << std::setprecision(1) << "float:  " << n << f << std::endl;
}

static void print_double(double n)
{
	std::cout << std::fixed << std::setprecision(1) << "double: " << n << std::endl;
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
	double	n;

	if (!validate_input(str))
		return (false);

	n = convert_input(str);

	print_char(n);
	print_int(n);
	print_float(str, n);
	print_double(n);
	return (true);
}
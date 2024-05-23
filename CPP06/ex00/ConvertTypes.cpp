#include "ScalarConverter.hpp"

// Checks if there is only one word
bool validate_input(std::string str)
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

double	convert_input_nd(std::string str, bool &status)
{

	status = true;
	if (str == "+inf")
		return (std::numeric_limits<double>::infinity());
	if (str == "-inf")
		return (-std::numeric_limits<double>::infinity());
	if (str == "nan")
		return (std::numeric_limits<double>::quiet_NaN());

	bool	is_point = false;
	int		i = -1;

	if (str[0] && (str[0] == '+' || str[0] == '-'))
		i++;
	while (str[++i])
	{
		if (isdigit(str[i]))
			continue ;
		if (str[i] == '.')
		{
			if (is_point)
			{
				status = false;
				return 0.0;
			}
			is_point = true;
		}
		else
			break ;
	}
	if (!str[i] && i > 0)
		i--;
	char last_char = str[i];
	if (isdigit(last_char))
		i++;
	// Skip trailing spaces
	while (str[i] && isspace(str[i]))
		i++;
	if (str[i] || !isdigit(last_char)) // If not the end of the string, fuck off !
	{
		status = false;
		return 0.0f;
	}

	return (atof(str.c_str()));
}

float	convert_input_nf(std::string str, bool &status)
{
	status = true;
	if (str == "+inff")
		return (std::numeric_limits<float>::infinity());
	if (str == "-inff")
		return (-std::numeric_limits<float>::infinity());
	if (str == "nanf")
		return (std::numeric_limits<float>::quiet_NaN());

	bool	is_point = false;
	int		i = -1;

	// Skip sign
	if (str[0] && (str[0] == '+' || str[0] == '-'))
		i++;
	// Get Number
	while (str[++i])
	{
		if (isdigit(str[i]))
			continue ;
		else if (str[i] == '.')
		{
			if (is_point)
			{
				status = false;
				return 0.0f;
			}
			is_point = true;
		}
		else
			break;
	}
	if (!str[i] && i > 0)
		i--;
	char last_char = str[i];
	if (isdigit(last_char) || str[i] == 'f')
		i++;
	// Skip trailing spaces
	while (str[i] && isspace(str[i]))
		i++;
	// If doesn't end with f it's not a float
	if (last_char != 'f' || str[i])
	{
		status = false;
		return 0.0f;
	}

	double n = atof(str.c_str());
	if (n < -__FLT_MAX__ || n > __FLT_MAX__)
	{
		status = false;
		return 0.0f;
	}
	return (atof(str.c_str()));// FIX THIS SO IT RETURNS A FLOAT
}

int		convert_input_ni(std::string str, bool &status)
{
	double	n = atof(str.c_str());

	if (n < INT_MIN || n > INT_MAX)
	{
		status = false;
		return 0;
	}
	status = true;
	int i=0; // Checks if there are only the acceptec characters
	while (str[i] && isspace(str[i]))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] && isdigit(str[i]))
		i++;
	while (str[i] && isspace(str[i]))
		i++;
	if (str[i])
	{
		status = false;
		return (0);
	}
	return (atoi(str.c_str()));
}

void	init_others(int &ni, float &nf, double &nd, bool valid[4])
{
	if (valid[0]) // It is an int
	{
		nf = static_cast<float>(ni);
		nd = static_cast<double>(ni);
		if (floor(nd) > INT_MAX || floor(nd) < INT_MIN)
			valid[0] = false;
		else
			valid[0] = true;
		valid[1] = true;
		valid[2] = true;
	}
	else if (valid[1]) // It is a float
	{
		ni = static_cast<int>(nf);
		nd = static_cast<double>(nf);
		if (floor(nd) > INT_MAX || floor(nd) < INT_MIN || std::isnan(nf))
			valid[0] = false;
		else
			valid[0] = true;
		valid[1] = true;
		valid[2] = true;
	}
	else if (valid[2]) // It is a double
	{
		ni = static_cast<int>(nd);
		nf = static_cast<float>(nd);
		if (floor(nd) > INT_MAX || floor(nd) < INT_MIN || std::isnan(nf))
			valid[0] = false;
		else
			valid[0] = true;
		valid[1] = true;
		valid[2] = true;
	}

	if (!valid[0] || ni < 0 || ni > 127)
		valid[3] = false; // Not a char
	else
		valid[3] = true;
}

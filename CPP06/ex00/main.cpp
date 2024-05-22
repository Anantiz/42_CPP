#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Invalid input, this program takes a unique argument" << std::endl;
		return (EXIT_SUCCESS); // Exit success so that makes continue it's tests
	}

	int	i=0;
	while (av[1][i] && isspace(av[1][i]))
		i++;
	if (!av[1][i])
	{
		std::cout << "Invalid input, empty string" << std::endl;
		return (EXIT_SUCCESS);
	}
	if (ScalarConverter::convert(std::string(&av[1][i])) == false)
	{
		std::cout << "Invalid input, multiple words where found" << std::endl;
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
#include <iostream>
#include "phonebook.hpp"
#include "contact.hpp"
#include <limits>
#include <string>

int	main()
{
	PhoneBook	phonebook;
	std::string	command;

	while (1)
	{
		std::cout << "\033[4mEnter a command\033[0m: ";
		if (!std::getline(std::cin, command))
			break;
		std::cout.clear();
		if (command == "ADD")
			phonebook.parse_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			break;
		else{
			std::cout << "\t\033[31mInvalid command\n\t\t-ADD\n\t\t-SEARCH\n\t\t-EXIT\033[0m" << std::endl;
		}
		std::cout.clear();
	}
	return (0);
}

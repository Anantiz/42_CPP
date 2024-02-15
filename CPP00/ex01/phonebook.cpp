#include "phonebook.hpp"
#include "contact.hpp"
#include <limits>
#include <string>

PhoneBook::PhoneBook()
{
	this->_nb_contacts = 0;
}

PhoneBook::PhoneBook(const PhoneBook &other)
{
	*this = other;
}

PhoneBook::~PhoneBook()
{
}

PhoneBook&	PhoneBook::operator=(const PhoneBook &other)
{
	this->_nb_contacts = other._nb_contacts;
	for (int i = 0; i < 8; i++)
		this->_contacts[i] = other._contacts[i];
	return (*this);
}

void	PhoneBook::add_contact(Contact contact)
{
	if (this->_nb_contacts > 8)
	{
		std::cout << "The phonebook is full, deleting contact number" \
		<< (this->_nb_contacts % 8) << std::endl;
	}
	this->_contacts[this->_nb_contacts++ % 8] = contact;
}

static bool	ft_is_numeric(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}


static bool	ft_is_alpha(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isalpha(str[i]))
			return (false);
	}
	return (true);
}

/*
	Reads the user input and adds a new contact to the phonebook
	Handle invalid input ad all
*/
void	PhoneBook::parse_contact()
{
	std::string		first_name;
	std::string		last_name;
	std::string		nickname;
	std::string		phone_number;
	std::string		darkest_secret;

	std::cout << "Enter the first name: ";
	if (!std::getline(std::cin, first_name))
	{
		std::cout << "\033[31m\nEOF, EXITING...\033[0m" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	if (first_name.empty() || !ft_is_alpha(first_name))
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	std::cout << "Enter the last name: ";
	if (!std::getline(std::cin, last_name))
	{
		std::cout << "\033[31m\nEOF, EXITING...\033[0m" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	if (last_name.empty() || !ft_is_alpha(last_name))
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	std::cout << "Enter the nickname: ";
	if (!std::getline(std::cin, nickname))
	{
		std::cout << "\033[31m\nEOF, EXITING...\033[0m" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	if (nickname.empty())
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	std::cout << "Enter the phone number: ";
	if (!std::getline(std::cin, phone_number))
	{
		std::cout << "\033[31m\nEOF, EXITING...\033[0m" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	if (phone_number.empty() || !ft_is_numeric(phone_number))
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	std::cout << "Enter the darkest secret: ";
	if (!std::getline(std::cin, darkest_secret))
	{
		std::cout << "\033[31m\nEOF, EXITING...\033[0m" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	if (darkest_secret.empty())
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	this->add_contact(Contact(first_name, last_name, nickname, phone_number, darkest_secret));
}

static std::string get_field(Contact& contact, int field)
{
	std::string str;

	switch (field)
	{
		case 0:
			str = contact.get_first_name();
			break;
		case 1:
			str = contact.get_last_name();
			break;
		case 2:
			str = contact.get_nickname();
			break;
	}
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}

void PhoneBook::print_phonebook()
{
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|";
		for (int j = 0; j < 3; j++)
		{
			std::cout << std::setw(10);
			std::cout << get_field(this->_contacts[i], j);
		}
		std::cout << std::endl;
	}
}

/*
	Display the Phone-Book
	Wait for user input (contact index)
	Display the contact
*/
void	PhoneBook::search_contact()
{
	std::string	index;

	print_phonebook();
	std::cout << "Enter the index of the contact: ";
	if (!std::getline(std::cin, index))
	{
		std::cout << "\033[31m\nEOF, EXITING...\033[0m" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	if (index.size() != 1 || !ft_is_numeric(index) || (int)index[0] - 48 > this->_nb_contacts - 1 || (int)index[0] - 48 < 0)
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	this->_contacts[(int)index[0] - 48].print_contact();
}

#include "phonebook.hpp"
#include "contact.hpp"
#include <limits>

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

// static bool	ft_is_numeric(std::string str)
// {
// 	for (size_t i = 0; i < str.length(); i++)
// 	{
// 		if (!std::isdigit(str[i]))
// 			return (false);
// 	}
// 	return (true);
// }


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
	// std::string		last_name;
	// std::string		nickname;
	// std::string		phone_number;
	// std::string		darkest_secret;

	bool loop = false;

	do {
		loop = false;
		first_name.clear();
		std::cout << "\033[4mEnter the first name\033[0m: ";
		std::cin.ignore(4096, '\n');
		if (!std::getline(std::cin, first_name)){
			std::cout << "\033[91mError reading input\033[0m" << std::endl;
			loop = true;
		}
		else if (first_name.empty() || ft_is_alpha(first_name) == false){
			std::cout << "\033[96m\tInput must be only letters and non empty\033[0m" << std::endl;
			loop = true;
		}
		std::cin.clear();
		std::cout << "Name is::" << first_name << "." << std::endl;
	}while (loop);

	// do {
	// 	last_name.clear();
	// 	loop = false;
	// 	std::cout << "Enter the last name: ";
	// 	std::cin >> last_name;
	// 	if (last_name.empty() || ft_is_alpha(last_name) == false){
	// 		loop = true;
	// 		std::cout << "Input must be only letters and non empty" << std::endl;
	// 	}
	// } while (loop);

	// do{
	// 	nickname.clear();
	// 	loop = false;
	// 	std::cout << "Enter the nickname: ";
	// 	std::getline(std::cin, nickname);
	// 	std::cout << std::endl;
	// 	if (nickname.empty()){
	// 		loop = true;
	// 		std::cout << "Input must be non empty" << std::endl;
	// 	}
	// } while (loop);

	// do{
	// 	loop = false;
	// 	std::cout << "Enter the phone number: ";
	// 	std::getline(std::cin, phone_number);
	// 	std::cout << std::endl;
	// 	if (nickname.empty() || ft_is_numeric(phone_number) == false){
	// 		loop = true;
	// 		std::cout << "Input must be only numbers and non empty" << std::endl;
	// 	}
	// } while (loop);

	// do{
	// 	std::cout << "Enter the darkest secret: ";
	// 	std::getline(std::cin, darkest_secret);
	// 	std::cout << std::endl;
	// } while (darkest_secret.empty());
	// this->add_contact(Contact(first_name, last_name, nickname, phone_number, darkest_secret));
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
		std::cout << std::setw(9) << i << "|";
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
	print_phonebook();
}

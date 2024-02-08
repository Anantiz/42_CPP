#include <iostream>
#include <string>
#include <algorithm>

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->_nb_contacts = 0;
};

PhoneBook::PhoneBook(const PhoneBook &other)
{
	*this = other;
};

PhoneBook&	PhoneBook::operator=(const PhoneBook &other)
{
	this->_nb_contacts = other._nb_contacts;
	for (int i = 0; i < 8; i++)
		this->_contacts[i] = other._contacts[i];
};

PhoneBook::~PhoneBook()
{
};

void	PhoneBook::add_contact(Contact contact)
{
	if (this->_nb_contacts > 8)
	{
		std::cout << "The phonebook is full, deleting contact number" \
		<< (this->_nb_contacts % 8) << std::endl;
	}
	this->_contacts[this->_nb_contacts++ % 8] = contact;
};

static bool	ft_is_numeric(std::string str)
{
	bool isNumeric = \
	std::all_of(str.begin(), str.end(), \
	[](unsigned char c){ \
		return std::isdigit(c);
	});
	return (isNumeric);
};

static bool	ft_is_alpha(std::string str)
{
	bool isAlpha = \
	std::all_of(str.begin(), str.end(), \
	[](unsigned char c){ \
		return std::isalpha(c);
	});
	return (isAlpha);
};

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

// Ugly copy pasting lmao
	bool loop;
	do {
		loop = false;
		std::cout << "Enter the first name: ";
		std::getline(std::cin, first_name);
		std::cout << std::endl;
		if (first_name.empty() || ft_is_alpha(first_name) == false){
			loop = true;
			std::cout << "Input must be only letters and non empty" << std::endl;
		}
	} while (loop);

	do {
		loop = false;
		std::cout << "Enter the last name: ";
		std::getline(std::cin, last_name);
		std::cout << std::endl;
		if (last_name.empty() || ft_is_alpha(last_name) == false){
			loop = true;
			std::cout << "Input must be only letters and non empty" << std::endl;
		}
	} while (loop);

	do{
		loop = false;
		std::cout << "Enter the nickname: ";
		std::getline(std::cin, nickname);
		std::cout << std::endl;
		if (nickname.empty()){
			loop = true;
			std::cout << "Input must be non empty" << std::endl;
		}
	} while (loop);

	do{
		loop = false;
		std::cout << "Enter the phone number: ";
		std::getline(std::cin, phone_number);
		std::cout << std::endl;
		if (nickname.empty() || ft_is_numeric(phone_number) == false){
			loop = true;
			std::cout << "Input must be only numbers and non empty" << std::endl;
		}
	} while (loop);

	do{
		std::cout << "Enter the darkest secret: ";
		std::getline(std::cin, darkest_secret);
		std::cout << std::endl;
	} while (darkest_secret.empty());
	this->add_contact(Contact(first_name, last_name, nickname, phone_number, darkest_secret));
};

void	PhoneBook::search_contact()
{
	
}
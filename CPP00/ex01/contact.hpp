/*
	Orthodox Canonical Class Form
		- Empty constructor
		- Default constructor
		- Copy constructor
		- Assignation operator overload
		- Destructor
*/
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

class Contact
{
	std::string		_first_name;
	std::string		_last_name;
	std::string		_nickname;
	std::string		_phone_number;
	std::string		_darkest_secret;

	public:
		Contact();
		Contact(const Contact &other);
		Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);

		Contact& operator=(const Contact &other);
		~Contact();

		// stupid getters
		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		std::string	get_phone_number();
		std::string	get_darkest_secret();
};
#endif
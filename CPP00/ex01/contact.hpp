#ifndef CONTACT_HPP
# define CONTACT_HPP

/*
	Orthodox Canonical Class Form
		- Empty constructor
		- Default constructor
		- Copy constructor
		- Assignation operator overload
		- Destructor
*/

#include <string>

class Contact
{
	std::string		_first_name;
	std::string		_last_name;
	std::string		_nickname;
	std::string		_phone_number;
	std::string		_darkest_secret;

	public:
		// Useless one , like what's the point of this
		Contact();

		// Usefull one
		Contact(std::string first_name, std::string last_name, std::string nickname, \
		std::string phone_number, std::string darkest_secret);

		// Copy constructor
		Contact(const Contact &other);

		Contact&	operator=(const Contact &other);

		~Contact();
};
#endif
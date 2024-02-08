#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include "contact.hpp"

class PhoneBook
{
	Contact		_contacts[8];
	int			_nb_contacts;

	public:
		PhoneBook();

		PhoneBook(const PhoneBook &other);

		PhoneBook&	operator=(const PhoneBook &other);

		void	add_contact(Contact contact);
		void	parse_contact();
		void	search_contact();
		void	exit();

		~PhoneBook();
};

#endif
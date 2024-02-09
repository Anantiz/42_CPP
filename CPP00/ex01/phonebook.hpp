#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include "contact.hpp"

class PhoneBook
{
	private:
		Contact		_contacts[8];
		int			_nb_contacts;

	public:
		PhoneBook();
		PhoneBook(const PhoneBook &other);

		PhoneBook&	operator=(const PhoneBook &other);
		~PhoneBook();

		void	search_contact();
		void	parse_contact();

	private:
		void	print_phonebook();
		void	add_contact(Contact contact);
};

#endif
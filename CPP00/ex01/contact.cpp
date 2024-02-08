#include "contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, \
	std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nickname = nickname;
	this->_phone_number = phone_number;
	this->_darkest_secret = darkest_secret;
}

Contact::Contact(const Contact &other)
{
	*this = other;
}

Contact&	Contact::operator=(const Contact &other)
{
	this->_first_name = other._first_name;
	this->_last_name = other._last_name;
	this->_nickname = other._nickname;
	this->_phone_number = other._phone_number;
	this->_darkest_secret = other._darkest_secret;
}

// Wtf is canonic form for 	??
Contact::~Contact()
{

};

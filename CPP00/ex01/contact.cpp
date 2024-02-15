#include "contact.hpp"

Contact::Contact(){
	;
}

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
	return (*this);
}

// Wtf is canonic form for 	??
Contact::~Contact(){
};

std::string	Contact::get_first_name(){
	return (this->_first_name);
}

std::string	Contact::get_last_name(){
	return (this->_last_name);
}

std::string	Contact::get_nickname(){
	return (this->_nickname);
}

std::string	Contact::get_phone_number(){
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(){
	return (this->_darkest_secret);
}

void Contact::print_contact(void){
	std::cout << "First name: " << this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phone_number << std::endl;
	std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
}

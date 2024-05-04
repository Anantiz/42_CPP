/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:43:26 by aurban            #+#    #+#             */
/*   Updated: 2024/04/16 17:04:18 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wrong.hpp"

/*

	ANIMAL



*/

WrongAnimal::WrongAnimal() : _type("WrongDefault"){
	std::cout << "\033[31m" << "WrongAnimal Default constructor called" << "\033[0m" << std::endl;
};

WrongAnimal::WrongAnimal(std::string type) : _type(type){
	std::cout << "\033[31m" << "WrongAnimal constructor called" << "\033[0m"  << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &copy){	*this = copy;}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &right){
	if (this == &right)
		return *this;
	_type = right._type;
	return *this;
};

WrongAnimal::~WrongAnimal(){
	std::cout << "\033[31m" << "WrongAnimal destructor called" << "\033[0m"  << std::endl;
};

std::string WrongAnimal::getType() const {return _type;}

void WrongAnimal::makeSound() const {
	std::cout << "\033[31m" << "Random WrongAnimal sound" << "\033[0m"  << std::endl;
}

/*

	CAT

*/


WrongCat::WrongCat() : WrongAnimal("WrongCat"){
	std::cout << "\033[91m" << "WrongCat Default constructor called" << "\033[0m"  << std::endl;
};

WrongCat::~WrongCat(){
	std::cout << "\033[91m" << "WrongCat destructor called" << "\033[0m"  << std::endl;
};

void WrongCat::makeSound() const {
	std::cout << "\033[91m" << "WRONG Meow" << "\033[0m"  << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy){};

WrongCat &WrongCat::operator=(const WrongCat &right){
	if (this == &right)
		return *this;
	WrongAnimal::operator=(right);
	return *this;
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:29:01 by aurban            #+#    #+#             */
/*   Updated: 2024/04/13 10:31:51 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Default"){
	std::cout << "Animal Default constructor called" << std::endl;
};

Animal::Animal(std::string type) : _type(type){
	std::cout << "Animal constructor called" << std::endl;
};

Animal::Animal(const Animal &copy){	*this = copy;}

Animal &Animal::operator=(const Animal &right){
	if (this == &right)
		return *this;
	_type = right._type;
	return *this;
};

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
};

std::string Animal::getType() const {return _type;}

void Animal::makeSound() const {
	std::cout << "Random Animal sound" << std::endl;
}
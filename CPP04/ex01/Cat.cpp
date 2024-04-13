/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:19:39 by aurban            #+#    #+#             */
/*   Updated: 2024/04/13 11:23:53 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	_brain = new Brain();
	std::cout << "\033[33m" << "Cat constructor called" << "\033[0m" << std::endl;
};

Cat::~Cat(){
	delete _brain;
	std::cout << "\033[33m" << "Cat destructor called" << "\033[0m"  << std::endl;
};

void Cat::makeSound() const {
	std::cout << "\033[33m" << "Meow meow" << "\033[0m" << std::endl;
};

Cat	&Cat::operator=(const Cat &copy){
	if (this == &copy)
		return *this;
	_type = copy._type;
	_brain = new Brain(*copy._brain);
	return *this;
};

Cat::Cat(const Cat &copy) : Animal("Cat"){
	std::cout << "\033[33m" << "Cat copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
};

std::string Cat::getIdea(int i) const {
	return _brain->getIdea(i);
};

void Cat::setIdea(int i, std::string idea){
	_brain->setIdea(i, idea);
};
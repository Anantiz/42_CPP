/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:17:26 by aurban            #+#    #+#             */
/*   Updated: 2024/04/13 11:23:48 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	_brain = new Brain();
	std::cout << "\033[32m" << "Dog constructor called" << "\033[0m" << std::endl;
};

Dog::~Dog(){
	delete _brain;
	std::cout << "\033[32m" << "Dog destructor called" << "\033[0m" << std::endl;
};

void	Dog::makeSound() const {
	std::cout << "\033[32m" << "Woof woof" << "\033[0m" << std::endl;
};

Dog	&Dog::operator=(const Dog &copy){
	if (this == &copy)
		return *this;
	_type = copy._type;
	_brain = new Brain(*copy._brain);
	return *this;
};

Dog::Dog(const Dog &copy) : Animal("Dog"){
	*this = copy;
};

std::string Dog::getIdea(int i) const {
	return _brain->getIdea(i);
};

void Dog::setIdea(int i, std::string idea){
	_brain->setIdea(i, idea);
};
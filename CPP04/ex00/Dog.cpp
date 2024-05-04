/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:17:26 by aurban            #+#    #+#             */
/*   Updated: 2024/04/16 17:03:28 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "\033[32m" << "Dog constructor called" << "\033[0m" << std::endl;
};

Dog::~Dog(){
	std::cout << "\033[32m" << "Dog destructor called" << "\033[0m" << std::endl;
};

void	Dog::makeSound() const {
	std::cout << "\033[32m" << "Woof woof" << "\033[0m" << std::endl;
};

Dog::Dog(Dog const &right) : Animal(right){
	std::cout << "\033[32m" << "Dog copy constructor called" << "\033[0m" << std::endl;
};

Dog &Dog::operator=(Dog const &right){
	std::cout << "\033[32m" << "Dog assignation operator called" << "\033[0m" << std::endl;
	if (this != &right)
		Animal::operator=(right);
	return *this;
};
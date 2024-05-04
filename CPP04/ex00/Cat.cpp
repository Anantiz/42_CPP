/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:19:39 by aurban            #+#    #+#             */
/*   Updated: 2024/04/16 17:03:48 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "\033[33m" << "Cat constructor called" << "\033[0m" << std::endl;
};

Cat::~Cat(){
	std::cout << "\033[33m" << "Cat destructor called" << "\033[0m"  << std::endl;
};

void Cat::makeSound() const {
	std::cout << "\033[33m" << "Meow meow" << "\033[0m" << std::endl;
};

Cat::Cat(Cat const &right) : Animal(right){
	std::cout << "\033[33m" << "Cat copy constructor called" << "\033[0m" << std::endl;
};

Cat &Cat::operator=(Cat const &right){
	std::cout << "\033[33m" << "Cat assignation operator called" << "\033[0m" << std::endl;
	if (this != &right)
		Animal::operator=(right);
	return *this;
};
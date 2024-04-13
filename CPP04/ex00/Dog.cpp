/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:17:26 by aurban            #+#    #+#             */
/*   Updated: 2024/04/13 10:33:27 by aurban           ###   ########.fr       */
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
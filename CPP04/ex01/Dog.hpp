/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:17:35 by aurban            #+#    #+#             */
/*   Updated: 2024/04/16 17:05:41 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:

	Brain	*_brain;

public:

	Dog();
	~Dog();

	Dog(const Dog &copy);
	Dog	&operator=(const Dog &copy);

	void makeSound() const;
	std::string getIdea(int i) const ;
	void setIdea(int i, std::string idea);
};
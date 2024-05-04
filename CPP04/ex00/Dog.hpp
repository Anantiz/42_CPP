/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:17:35 by aurban            #+#    #+#             */
/*   Updated: 2024/04/16 17:03:07 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
public:

	Dog();
	~Dog();

	//Canonical:
	Dog(Dog const &right);
	Dog &operator=(Dog const &right);

	void makeSound() const;
};
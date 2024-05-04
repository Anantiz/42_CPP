/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:19:13 by aurban            #+#    #+#             */
/*   Updated: 2024/04/16 17:03:40 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
public:

	Cat();
	~Cat();

	//Canonical:
	Cat(Cat const &right);
	Cat &operator=(Cat const &right);

	void makeSound() const;
};
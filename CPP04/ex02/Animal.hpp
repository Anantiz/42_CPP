/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:19:32 by aurban            #+#    #+#             */
/*   Updated: 2024/04/13 11:29:25 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
protected:

	std::string _type;


public:

	Animal();
	Animal(std::string type);
	Animal(const Animal &copy);

	virtual ~Animal();
	virtual Animal &operator=(const Animal &copy);

	std::string getType() const;
	virtual void makeSound() const = 0;
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:42:23 by aurban            #+#    #+#             */
/*   Updated: 2024/04/13 10:48:27 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string _type;

public:

	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &cpy);
	~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &cpy);

	std::string getType() const;
	void makeSound() const;

};

class WrongCat : public WrongAnimal
{
public:

	WrongCat();
	~WrongCat();

	void makeSound() const;
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:19:13 by aurban            #+#    #+#             */
/*   Updated: 2024/04/13 11:13:50 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:

	Brain	*_brain;

public:

	Cat();
	Cat(const Cat &copy);
	~Cat();

	Cat	&operator=(const Cat &copy);

	void makeSound() const;

	std::string getIdea(int i) const ;
	void setIdea(int i, std::string idea);
};
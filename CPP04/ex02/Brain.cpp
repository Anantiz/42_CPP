/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:59:04 by aurban            #+#    #+#             */
/*   Updated: 2024/04/13 11:16:42 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\033[36m" << "Brain constructor called" << "\033[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "\033[36m" << "Brain copy constructor called" << "\033[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
}

Brain::~Brain(){
	std::cout << "\033[36m" << "Brain destructor called" << "\033[0m" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
	return *this;
}

std::string Brain::getIdea(int i) const {return ideas[i];}

void Brain::setIdea(int i, std::string idea){ideas[i] = idea;}

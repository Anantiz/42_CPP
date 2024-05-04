/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:02:46 by aurban            #+#    #+#             */
/*   Updated: 2024/04/16 17:49:52 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

/*

	Concrete class that implements the IMateriaSource interface.

*/

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	*this = src;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &src) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = src._inventory[i]->clone();
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m){
		std::cout << "Invalid materia" << std::endl;
		return;
	}
	// Check if the materia is already in the inventory
	for (int i = 0; i < 4; i++)
		if (_inventory[i] == m) {
			std::cout << "Materia already learned" << std::endl;
			return;
		}

	for (int i = 0; i < 4; i++)
		if (!_inventory[i]) {
			_inventory[i] = m;
			std::cout << "Materia learned" << std::endl;
			return;
		}
	std::cout << "Inventory full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++)
		if (_inventory[i] && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	std::cout << "Materia not found" << std::endl;
	return NULL;
}
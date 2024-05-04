/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:10:41 by aurban            #+#    #+#             */
/*   Updated: 2024/04/16 17:46:30 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"

/*

	Concrete class

*/

Character::Character(std::string const & name) : ICharacter() {
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const & src) {*this = src;}

Character::~Character() {
	std::cout << "Character " << _name << " destroyed" << std::endl;
	std::cout << "\t(Deleting inventory, do not re-delete the items if they had an other pointer "<<
	"in memory, items existing in 2 different inventory will create a double free() too, not my fault)" << std::endl;

	for (int i = 0; i < 4; i++)
		if (_inventory[i]){
			delete _inventory[i];
		}
}

/* Deep copy*/
Character	&Character::operator=(Character const &src) {
	_name = src._name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = src._inventory[i]->clone();
	return *this;
}

std::string const & Character::getName() const {return _name;}

void Character::equip(AMateria* m) {
	std::cout << this->_name << ": ";

	if (!m) {
		std::cout << "Invalid materia" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == m) {
			std::cout << "Already equipped" << std::endl;
			return;
		}
	}

	int i;
	for (i = 0; i < 4; i++)
	{
		if (!_inventory[i]) {
			_inventory[i] = m;
			break;
		}
	}
	if (i == 4)
		std::cout << "\tFAILURE Inventory full" << std::endl;
	else
		std::cout << "\tSUCCES Equipped " << m->getType() << std::endl;
}

void Character::unequip(int idx) {
	std::cout << this->_name << ": ";
	if (idx < 0 || idx > 3){
		std::cout << "Invalid index" << std::endl;
		return;
	}
	std::cout << "Unequipped " << _inventory[idx]->getType() << std::endl;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	std::cout << this->_name << ": ";
	if (idx < 0 || idx > 3){
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "Empty slot" << std::endl;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:10:41 by aurban            #+#    #+#             */
/*   Updated: 2024/04/13 18:43:01 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"

ICharacter::ICharacter(){} // Not allowed

std::string const &ICharacter::getName() const {return _name;}

void ICharacter::equip(AMateria* m) {
	int i;
	for (i = 0; i < 4; i++)
	{
		if (!_inventory[i]) {
			_inventory[i] = m;
			break;
		}
		else
		{
			std::cout << "Slot " << i << " is already occupied by: " << _inventory[i]->getType() << std::endl;

		}

	}
	if (i == 4)
		std::cout << "Inventory full" << std::endl;
	else
		std::cout << "Equipped " << m->getType() << std::endl;
}

void ICharacter::unequip(int idx) {
	if (idx < 0 || idx > 3){
		std::cout << "Invalid index" << std::endl;
		return;
	}
	_inventory[idx] = NULL;
}

void ICharacter::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3){
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "Empty slot" << std::endl;
}

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
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
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
	ICharacter::equip(m);
}

/* Currently causes a leak */
void Character::unequip(int idx) {ICharacter::unequip(idx);}

void Character::use(int idx, ICharacter& target) {
	std::cout << this->_name << ": ";
	ICharacter::use(idx, target);
}


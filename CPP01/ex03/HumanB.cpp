/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:58:05 by aurban            #+#    #+#             */
/*   Updated: 2024/02/20 15:16:16 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	_name = "Unnamed";
	_weapon = NULL;
}

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
}

HumanB::HumanB(HumanB const &cpy) : _name(cpy._name), _weapon(cpy._weapon)
{
}

HumanB::HumanB(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon)
{
}

HumanB::~HumanB()
{
}

HumanB &HumanB::operator=(HumanB const &cpy)
{
	_name = cpy._name;
	_weapon = cpy._weapon;
	return *this;
}

void HumanB::attack()
{
	if (_weapon == NULL)
	{
		std::cout << _name << " has no weapon to attack with" << std::endl;
		return ;
	}
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}


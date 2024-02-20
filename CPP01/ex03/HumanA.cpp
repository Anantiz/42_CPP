/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:50:11 by aurban            #+#    #+#             */
/*   Updated: 2024/02/20 15:14:59 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(HumanA const &cpy) : _name(cpy._name), _weapon(cpy._weapon)
{
}

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

HumanA &HumanA::operator=(HumanA const &cpy)
{
	this->_name = cpy._name;
	this->_weapon = cpy._weapon;
	return *this;
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
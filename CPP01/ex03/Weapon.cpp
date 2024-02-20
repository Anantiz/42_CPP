/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:54:13 by aurban            #+#    #+#             */
/*   Updated: 2024/02/20 15:05:44 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	_type = "Thermo-Nuclear Cluster Warhead";
}

Weapon::Weapon(Weapon const &cpy)
{
	*this = cpy;
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::~Weapon()
{
}

Weapon &Weapon::operator=(Weapon const &cpy)
{
	_type = cpy._type;
	return *this;
}

const std::string &Weapon::getType() const
{
	return _type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}

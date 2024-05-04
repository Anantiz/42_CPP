/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:27:06 by aurban            #+#    #+#             */
/*   Updated: 2024/04/16 18:11:12 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cmath>

class ClapTrap
{
private:

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

	//Canonical form:
	ClapTrap();

public:

	//Canonical form:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &cpy);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &cpy);

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	unsigned int	getDamage() const;
};
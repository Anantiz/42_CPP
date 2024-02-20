/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:56:44 by aurban            #+#    #+#             */
/*   Updated: 2024/02/20 15:05:18 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;

	public:
		HumanB();
		HumanB(HumanB const &cpy);
		HumanB(std::string name);
		HumanB(std::string name, Weapon &weapon);
		~HumanB();
		HumanB &operator=(HumanB const &cpy);

		void attack();
		void setWeapon(Weapon &weapon);
};
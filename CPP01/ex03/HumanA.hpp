/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:24:58 by aurban            #+#    #+#             */
/*   Updated: 2024/02/20 15:05:35 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon &_weapon;

	public:
		HumanA(void);
		HumanA(HumanA const &cpy);
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		HumanA &operator=(HumanA const &cpy);

		void attack();
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:50:42 by aurban            #+#    #+#             */
/*   Updated: 2024/02/20 15:18:54 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main()
{
	Weapon w1 = Weapon("Thermo-Nuclear Cluster Warhead");

	HumanA bob("Bob", w1);
	bob.attack();
	w1.setType("SlingShot");
	bob.attack();

	Weapon w2 = Weapon("Stone");
	HumanB jim("Jim");
	jim.setWeapon(w2);
	jim.attack();
	w2.setType("Paper");
	jim.attack();

	HumanB jim2("Jim the Second");
	jim2.attack();
	
	return 0;
}
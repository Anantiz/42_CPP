/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:26:00 by aurban            #+#    #+#             */
/*   Updated: 2024/02/20 14:00:40 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(Zombie const &cpy);
		Zombie();
		Zombie(std::string name);
		~Zombie();
		Zombie &operator=(Zombie const &cpy);

		void	announce();
		void	setName(std::string name);
};

Zombie	*newZombie(std::string name);
Zombie	*zombieHorde(int N, std::string name);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:48:45 by aurban            #+#    #+#             */
/*   Updated: 2024/02/20 15:04:46 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon();
		Weapon(Weapon const &cpy);
		Weapon(std::string type);
		~Weapon();
		Weapon &operator=(Weapon const &cpy);

		const std::string	&getType() const;
		void				setType(std::string type);
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:08:54 by aurban            #+#    #+#             */
/*   Updated: 2024/04/13 18:29:40 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AMateria; // Forward declaration

class ICharacter
{
protected:

	std::string 	_name;
	AMateria	 	*_inventory[4];

	ICharacter();

public:

	virtual ~ICharacter() {}

	virtual std::string const 	&getName() const = 0;

	virtual void				equip(AMateria* m) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void				use(int idx, ICharacter& target) = 0;
};

/*

	Concrete class

*/

class Character : public ICharacter
{
private:

	Character(); // Not allowed

public:

	Character(std::string const & name);
	Character(Character const & src);
	~Character();

	Character	&operator=(Character const &src);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};
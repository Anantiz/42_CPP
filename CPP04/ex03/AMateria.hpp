/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:07:43 by aurban            #+#    #+#             */
/*   Updated: 2024/04/16 17:09:43 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class AMateria
{
protected:

	std::string 	_type;

	AMateria();

public:

	//Canonical:
	virtual ~AMateria();
	AMateria(AMateria const & src);
	AMateria&operator=(AMateria const &src);

	AMateria(std::string const & type);

	//Functions:

	std::string const &getType() const;

	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter& target);
};

class Ice : public AMateria
{
public:

	//Canonical:
	Ice();
	~Ice();
	Ice(Ice const & src);
	Ice	&operator=(Ice const &src);

	AMateria	*clone() const;
	void		use(ICharacter& target);
};

class Cure : public AMateria
{
public:

	//Canonical:
	Cure();
	~Cure();
	Cure(Cure const & src);
	Cure	&operator=(Cure const &src);

	AMateria	*clone() const;
	void		use(ICharacter& target);
};
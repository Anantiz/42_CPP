/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:23:42 by aurban            #+#    #+#             */
/*   Updated: 2024/05/23 20:38:28 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Flow chart:

	AMateria --> IMateriaSource --> MateriaSource (Finally a usable thing)

	Just seems like "MaterialSource" with extra steps.
	(Oop-Inheritence is clinically braindead, I swear to god.)

*/

#pragma once

#include "AMateria.hpp"

class IMateriaSource
{
public:

	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

/*

	Concrete class that implements the IMateriaSource interface.

*/

class MateriaSource : public IMateriaSource
{
private:

	AMateria	*_inventory[4];

public:

	MateriaSource();
	MateriaSource(MateriaSource const & src);
	~MateriaSource();
	MateriaSource &operator=(MateriaSource const & src);

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);

};

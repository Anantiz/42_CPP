/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:02:20 by aurban            #+#    #+#             */
/*   Updated: 2024/04/13 18:33:18 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {_type = "default";}
AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(AMateria const & src) {
	*this = src;
}

AMateria::~AMateria() {}

/* Deep copy (No pointers to copy to copy)*/
AMateria	&AMateria::operator=(AMateria const &src) {
	_type = src._type;
	return *this;
}

std::string const &AMateria::getType() const {
	return _type;
}

/*To come once I understand the bullshit they ask for*/
void	AMateria::use(ICharacter& target) {
	std::cout << "Used on " << target.getName() << std::endl;
}

/*

	Ice (Real thing, not an impostor)

*/

Ice::Ice() : AMateria("ice") {}
Ice::Ice(Ice const & src) : AMateria("ice"){
	*this = src;
}
Ice::~Ice() {}

Ice	&Ice::operator=(Ice const &src) {
	_type = src._type;
	return *this;
}

AMateria	*Ice::clone() const {
	return new Ice(*this);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/*

	Cure (Legit too, I love composition so much more than inheritence)

*/

Cure::Cure() : AMateria("cure") {}
Cure::Cure(Cure const & src) : AMateria("cure") {
	*this = src;}
Cure::~Cure() {}

Cure	&Cure::operator=(Cure const &src) {
	_type = src._type;
	return *this;
}

AMateria	*Cure::clone() const {
	return new Cure(*this);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}


#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(std::string("Default")), _hitPoints(10), _energyPoints(10), _attackDamage(0){};
ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad) : _name(name), _hitPoints(hp), _energyPoints(ep), _attackDamage(ad){};
ClapTrap::ClapTrap(ClapTrap const &cpy) : _name(cpy._name), _hitPoints(cpy._hitPoints), _energyPoints(cpy._energyPoints), _attackDamage(cpy._attackDamage){};
ClapTrap::~ClapTrap(){};


ClapTrap &ClapTrap::operator=(const ClapTrap &cpy)
{
	if (this == &cpy)
		return (*this);

	this->_name = cpy._name;
	this->_hitPoints = cpy._hitPoints;
	this->_energyPoints = cpy._energyPoints;
	this->_attackDamage = cpy._attackDamage;
	return (*this);

}

void ClapTrap::attack(std::string const &target){
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_hitPoints >= 10){
		std::cout << "ClapTrap " << this->_name << " is already at full health!" << std::endl;
		return;
	}
	int	to_heal = 10 - _hitPoints;
	int	used_enregy = amount - to_heal;
	if

	std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << std::endl;
}
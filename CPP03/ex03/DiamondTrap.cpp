#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;


	std::cout << "\033[96m" << "DiamondTrap " << this->_name << " is born !" << "\033[0m" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[96m" << "DiamondTrap " << this->_name << " Vanished" << "\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &right)
: ClapTrap(right._name + "_clap_name"), ScavTrap(right._name), FragTrap(right._name)
{
	this->_name = right._name;
	this->_hitPoints = right._hitPoints;
	this->_energyPoints = right._energyPoints;
	this->_attackDamage = right._attackDamage;
	std::cout << "\033[96m" << "DiamondTrap " << this->_name << " is born by copy cstr!" << "\033[0m" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &right)
{
	if (this == &right)
		return *this;
	this->_name = right._name;
	this->_hitPoints = right._hitPoints;
	this->_energyPoints = right._energyPoints;
	this->_attackDamage = right._attackDamage;
	std::cout << "\033[96m" << "DiamondTrap " << this->_name << " is born by assignation!" << "\033[0m" << std::endl;
	return *this;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "\033[96m" << "DiamondTrap: Who am I, " << this->_name << " or " << this->ClapTrap::_name << "? \033[0m" << std::endl;
}
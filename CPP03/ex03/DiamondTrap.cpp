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

void DiamondTrap::whoAmI(void)
{
	std::cout << "\033[96m" << "DiamondTrap: Who am I, " << this->_name << " or " << this->ClapTrap::_name << "? \033[0m" << std::endl;
}
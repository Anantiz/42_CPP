#pragma once

#include <iostream>
#include <string>
#include <cmath>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:

	ScavTrap();

public:

	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(ScavTrap const &right);
	ScavTrap	&operator=(ScavTrap const &right);

	void attack(std::string const &target);
	void guardGate();

};
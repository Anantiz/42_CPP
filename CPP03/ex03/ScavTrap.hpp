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

	void attack(std::string const &target);
	void guardGate();

};
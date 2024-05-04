#pragma once

#include <iostream>
#include <string>
#include <cmath>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:

	//Canonical form:
	FragTrap();

public:

	//Canonical form:
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(FragTrap const &right);
	FragTrap	&operator=(FragTrap const &right);

	void highFivesGuys(void);

};
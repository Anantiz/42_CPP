#pragma once

#include <iostream>
#include <string>
#include <cmath>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:

	FragTrap();

public:

	FragTrap(std::string name);
	~FragTrap();
	FragTrap(FragTrap const &right);
	FragTrap	&operator=(FragTrap const &right);

	void highFivesGuys(void);

};
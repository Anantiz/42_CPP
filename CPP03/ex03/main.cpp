#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	robot5("Diamond");
	robot5.whoAmI();
	robot5.attack("Carl");


	std::cout << "\nCopy constructor and assignment operator tests\n" << std::endl;
	// Copy constructor test for DiamondTrap
	DiamondTrap	robot5_cpy = robot5;
	robot5_cpy.whoAmI();
	robot5_cpy.attack("Carl");
	// Assignment operator test for DiamondTrap
	DiamondTrap	robot6("Diamond");
	robot6 = robot5;
}

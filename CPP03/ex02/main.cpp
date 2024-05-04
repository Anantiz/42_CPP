#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	robot("Carl");
	ClapTrap	robot2("Miguel");

	robot.attack("Miguel");
	robot2.takeDamage(robot.getDamage());
	robot2.beRepaired(1);
	robot2.beRepaired(100);

	ScavTrap	robot3("Scav");

	robot3.attack("Carl");
	robot3.guardGate();

	FragTrap	robot4("Frag");

	robot4.attack("Carl");
	robot4.highFivesGuys();

	std::cout << "\nCopy constructor and assignment operator tests\n" << std::endl;
	// Copy constructor test for FragTrap
	FragTrap	robot4_cpy = robot4;
	robot4_cpy.attack("Carl");
	robot4_cpy.highFivesGuys();
	// Assignment operator test for FragTrap
	FragTrap	robot5("Frag");
	robot5 = robot4;
	robot5.attack("Carl");
	robot5.highFivesGuys();

}
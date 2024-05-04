#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	robot("Carl");
	ClapTrap	robot2("Miguel");

	robot.attack("Miguel");
	robot2.takeDamage(robot.getDamage());
	robot2.beRepaired(1);
	robot2.takeDamage(robot.getDamage());
	robot2.beRepaired(100);
	robot2.takeDamage(robot.getDamage());
	robot2.takeDamage(robot.getDamage());
	robot2.attack("Carl");
	robot2.takeDamage(robot.getDamage());

	std::cout << "\nCopy constructor and assignment operator tests\n" << std::endl;

	// Copy constructor test
	ClapTrap	robot3(robot2);
	robot3.attack("Carl");
	// Assignment operator test
	ClapTrap	robot4("Miguel");
	robot4 = robot3;
}
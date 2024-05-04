#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	robot("Carl");
	ClapTrap	robot2("Miguel");

	robot.attack("Miguel");
	robot2.takeDamage(robot.getDamage());
	robot2.beRepaired(1);
	robot2.beRepaired(100);

	std::cout << "\nCopy constructor and assignment operator tests\n" << std::endl;


	ScavTrap	robot3("Scav");
	robot3.attack("Carl");
	robot3.guardGate();

	ScavTrap	robot3_cpy = robot3;
	robot3_cpy.guardGate();

}
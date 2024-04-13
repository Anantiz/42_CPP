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

	ScavTrap	robot3("Scav");

	robot3.attack("Carl");
	robot3.guardGate();
}
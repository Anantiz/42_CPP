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

}
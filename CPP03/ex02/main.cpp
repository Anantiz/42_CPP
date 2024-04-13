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
}
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default", 100, 50, 20) {
	std::cout << "\033[94m" << "ScavTrap " << this->_name << " is born!" << "\033[0m" << std::endl;
};

ScavTrap::ScavTrap(std::string name) :  ClapTrap(name, 100, 50, 20)  {
	std::cout << "\033[94m" << "ScavTrap " << this->_name << " is born!" << "\033[0m" << std::endl;
};

ScavTrap::~ScavTrap(){
	std::cout << "\033[94m" << "ScavTrap " << this->_name << " Vanished !" << "\033[0m" << std::endl;
};

void	ScavTrap::attack(std::string const &target){
	std::cout << "\033[94m" << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << "\033[0m" << std::endl;
};

void	ScavTrap::guardGate(){
	std::cout << "\033[94m" << "ScavTrap " << this->_name << " has entered in Gate keeper mode!" << "\033[0m" << std::endl;
};


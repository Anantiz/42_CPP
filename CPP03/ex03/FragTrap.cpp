#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default", 100, 100, 30) {
	std::cout << "\033[92m" << "FragTrap " << this->_name << " is born!" << "\033[0m" << std::endl;
};

FragTrap::FragTrap(std::string name) :  ClapTrap(name, 100, 100, 30)  {
	std::cout << "\033[92m" << "FragTrap " << this->_name << " is born!" << "\033[0m" << std::endl;
};

FragTrap::FragTrap(FragTrap const &right) : ClapTrap(right){
	std::cout << "\033[92m" << "FragTrap " << this->_name << " is born by copy!" << "\033[0m" << std::endl;
};

FragTrap	&FragTrap::operator=(FragTrap const &right){
	if (this == &right)
		return *this;
	this->_name = right._name;
	this->_hitPoints = right._hitPoints;
	this->_energyPoints = right._energyPoints;
	this->_attackDamage = right._attackDamage;
	std::cout << "\033[92m" << "FragTrap " << this->_name << " is born by assignation!" << "\033[0m" << std::endl;
	return *this;
};

FragTrap::~FragTrap(){
	std::cout << "\033[92m" << "FragTrap " << this->_name << " Vanished !" << "\033[0m" << std::endl;
};

void	FragTrap::highFivesGuys(){
	std::cout << "\033[92m" << "FragTrap " << this->_name << " Positive High five request" << "\033[0m" << std::endl;
};


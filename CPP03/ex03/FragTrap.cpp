#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default", 100, 100, 30) {
	std::cout << "\033[92m" << "FragTrap " << this->_name << " is born!" << "\033[0m" << std::endl;
};

FragTrap::FragTrap(std::string name) :  ClapTrap(name, 100, 100, 30)  {
	std::cout << "\033[92m" << "FragTrap " << this->_name << " is born!" << "\033[0m" << std::endl;
};

FragTrap::~FragTrap(){
	std::cout << "\033[92m" << "FragTrap " << this->_name << " Vanished !" << "\033[0m" << std::endl;
};

void	FragTrap::highFivesGuys(){
	std::cout << "\033[92m" << "FragTrap " << this->_name << " Positive High five request" << "\033[0m" << std::endl;
};


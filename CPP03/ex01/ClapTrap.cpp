#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(std::string("Default")), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " is born!" << std::endl;
};
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " is born!" << std::endl;
};

ClapTrap::ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage)
	: _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	std::cout << "ClapTrap " << this->_name << " is born!" << std::endl;
};

ClapTrap::ClapTrap(ClapTrap const &cpy) : _name(cpy._name), _hitPoints(cpy._hitPoints), _energyPoints(cpy._energyPoints), _attackDamage(cpy._attackDamage) { std::cout << "ClapTrap " << this->_name << " is born!" << std::endl; };

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " Vanished !" << std::endl;
};

ClapTrap &ClapTrap::operator=(const ClapTrap &cpy)
{
	if (this == &cpy)
		return (*this);

	this->_name = cpy._name;
	this->_hitPoints = cpy._hitPoints;
	this->_energyPoints = cpy._energyPoints;
	this->_attackDamage = cpy._attackDamage;
	return (*this);
}

unsigned int ClapTrap::getDamage() const { return _attackDamage; }

void ClapTrap::attack(std::string const &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " I'm dead bro !" << std::endl;
		return;
	}

	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " I'm already dead bro !" << std::endl;
		return;
	}
	unsigned int taken_damage = fmin(amount, _hitPoints);
	_hitPoints -= taken_damage;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " I'm dead bro !" << std::endl;
		return;
	}

	if (_hitPoints >= 10)
	{
		std::cout << "ClapTrap " << this->_name << " is already at full health!" << std::endl;
		return;
	}

	unsigned int used_amount = fmin(_hitPoints, fmin(amount, _energyPoints));

	_hitPoints += used_amount;
	_energyPoints -= used_amount;
	std::cout << "ClapTrap " << this->_name << " is repaired for " << used_amount << " points of health!" << std::endl;
}
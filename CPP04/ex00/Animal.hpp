#pragma once

#include <iostream>
#include <string>

class Animal
{
protected:

	std::string type;

	Animal();

public:

	Animal(std::string type);
	Animal(const Animal &copy);
	~Animal();
	Animal &operator=(const Animal &copy);

	std::string getType();
	void makeSound();
};
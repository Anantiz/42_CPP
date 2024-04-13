#include "Animal.hpp"

Animal::Animal() : type("Default"){
	std::cout << "Animal Default constructor called" << std::endl;
};

Animal::Animal(std::string type) : type(type){
	std::cout << "Animal constructor called" << std::endl;
};

Animal::Animal(const Animal &copy){	*this = copy;}

Animal &Animal::operator=(const Animal &right){
	if (this == &right)
		return *this;
	type = right.type;
	return *this;
};

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
};

void	Animal::makeSound() const{
	std::cout << "Random Animal sound" << std::endl;
};

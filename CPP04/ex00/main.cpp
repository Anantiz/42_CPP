#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong.hpp"

int main()
{
	const Animal	*animal = new Animal();
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();
	std::cout << std::endl;


	std::cout << "Type (def): " << animal->getType() << std::endl;
	animal->makeSound();
	delete animal;
	std::cout << std::endl;

	std::cout << "Type (dog): " << dog->getType() << std::endl;
	dog->makeSound();
	delete dog;
	std::cout << std::endl;

	std::cout << "Type (cat): " << cat->getType() << std::endl;
	cat->makeSound();
	delete cat;
	std::cout << std::endl;

	const WrongAnimal	*wrongAnimal = new WrongAnimal();
	const WrongAnimal	*wrongCat = new WrongCat();
	std::cout << std::endl;

	std::cout << "Type (def): " << wrongAnimal->getType() << std::endl;
	wrongAnimal->makeSound();
	delete wrongAnimal;
	std::cout << std::endl;

	std::cout << "Type (cat): " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	delete wrongCat;
	std::cout << std::endl;
}
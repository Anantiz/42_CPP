/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:00:21 by aurban            #+#    #+#             */
/*   Updated: 2024/04/13 11:25:03 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong.hpp"

int main()
{
	std::cout << "=====================" << std::endl;
	std::cout << "      DEEP COPY      " << std::endl;
	std::cout << "=====================\n" << std::endl;

	Cat *c1 = new Cat();
	c1->setIdea(0, "Thuna");
	std::cout << "C1 Idea 0: " << c1->getIdea(0) << std::endl;
	std::cout << std::endl;

	Cat *c2 = new Cat(*c1);
	std::cout << "C2 Copied, Deleting C1" << std::endl;
	delete c1;
	std::cout << std::endl;
	std::cout << "C2 Idea 0: " << c2->getIdea(0) << std::endl;
	delete c2;
	std::cout << "\n=====================\n" << std::endl;



	Animal	*a[4];

	a[0] = new Cat();
	std::cout << std::endl;
	a[1] = new Cat();
	std::cout << std::endl;
	a[2] = new Dog();
	std::cout << std::endl;
	a[3] = new Dog();
	std::cout << "\n=====================\n" << std::endl;

	for (int i = 0; i < 4; i++)	{
		delete a[i];
		std::cout << std::endl;
	}
}
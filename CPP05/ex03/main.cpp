/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:58:09 by aurban            #+#    #+#             */
/*   Updated: 2024/05/09 18:19:20 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main()
{
	Bureaucrat		uvuvwevwevwe_onyetenyevwe ("uvuvwevwevwe_onyetenyevwe ", 50);
	AForm			*form = NULL;

	Intern			dish_washer = Intern();

	std::cout << "Valid value" << std::endl;
	std::cout << std::endl;
	try{
		form = dish_washer.makeForm("presidential pardon", "target");
		if (form)
		{
			uvuvwevwevwe_onyetenyevwe.signForm(*form);
		}
	}catch(const std::exception &e) // does not work
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr << "Unknown exception (I am just lazy actually)" << std::endl;
	}
	delete form;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Bullshit value" << std::endl;
	std::cout << std::endl;

	try{
		form = dish_washer.makeForm("dasadasda pardasdasdasdaddon", "target");
		if (form)
		{
			uvuvwevwevwe_onyetenyevwe.signForm(*form);
		}
	}catch(const std::exception &e) // does not work
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr << "Unknown exception (I am just lazy actually)" << std::endl;
	}
	return 0;
}
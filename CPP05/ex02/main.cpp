/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:58:09 by aurban            #+#    #+#             */
/*   Updated: 2024/05/09 17:37:55 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main()
{
	Bureaucrat		Bush("Bush", 1);
	Bureaucrat		Biden("Biden", 150);

	PresidentialPardonForm	pardon("Bob");


	std::cout << std::endl;
	std::cout << "PARDON + BAD GRADE TEST" << std::endl;
	std::cout << std::endl;

	// Signing work, execution not
	std::cout << pardon << std::endl;
	try{
		pardon.beSigned(Bush);
		pardon.beExecuted(Biden);
	}catch (const AForm::GradeTooLowException & e){
		std::cout << e.what() << std::endl;
	}catch (const Bureaucrat::GradeTooLowException & e){
		std::cout << e.what() << std::endl;
	}
	pardon.beExecuted(Bush); // Execution works



	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "ROBOTOMY + NOT SIGNED TEST" << std::endl;
	std::cout << std::endl;

	RobotomyRequestForm	robot("Bender");
	try {
		robot.beExecuted(Bush);
	}catch (const Bureaucrat::FormNotSigned & e){
		std::cout << e.what() << std::endl;
	}
	robot.beSigned(Bush);
	robot.beExecuted(Bush);
	robot.beExecuted(Bush);
	robot.beExecuted(Bush);



	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "SHRUBBERY TEST" << std::endl;
	std::cout << std::endl;

	ShrubberyCreationForm	shrubbery("Ni");
	shrubbery.beSigned(Bush);
	shrubbery.beExecuted(Bush);

	return 0;
}
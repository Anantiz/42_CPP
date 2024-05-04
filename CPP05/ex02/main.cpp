/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:58:09 by aurban            #+#    #+#             */
/*   Updated: 2024/05/04 22:06:41 by aurban           ###   ########.fr       */
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

	PresidentialPardonForm	pardon("Obama");

	std::cout << pardon << std::endl;
	try{
		pardon.beSigned(Bush);
		pardon.beExecuted(Biden);
	}catch (const AForm::GradeTooLowException & e){
		std::cout << e.what() << std::endl;
	}catch (const Bureaucrat::GradeTooLowException & e){
		std::cout << e.what() << std::endl;
	}
	pardon.beExecuted(Bush);

	std::cout << std::endl;

	ShrubberyCreationForm	shrubbery("Ni");
	shrubbery.beSigned(Bush);
	shrubbery.beExecuted(Bush);
	std::cout << std::endl;

	ShrubberyCreationForm	banned_op = shrubbery;
	std::cout << banned_op << std::endl;
	return 0;
}
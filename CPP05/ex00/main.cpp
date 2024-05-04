/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:58:09 by aurban            #+#    #+#             */
/*   Updated: 2024/05/04 02:25:26 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	Bureaucrat	john("John", 50);

	Bureaucrat	john2(john);

	john.incrementGrade();

	std::cout << "John  grade: " << john.getGrade() << std::endl;
	std::cout << "John2 grade: " << john2.getGrade() << std::endl;

	try {
		Bureaucrat	fucker("Fucker", 0);
	}catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
}
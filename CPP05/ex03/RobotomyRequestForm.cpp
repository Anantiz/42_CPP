/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:58:42 by aurban            #+#    #+#             */
/*   Updated: 2024/05/09 17:35:16 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) \
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

// No need to implement this function, as it is a warcrime
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm & right)
{
	(void)right;
	return (*this);
}

void RobotomyRequestForm::beExecuted(const Bureaucrat &executor)
{
	executor.executeForm(*this);
	std::cout << "*Drill noises* ";
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << " has not been robotomized" << std::endl;
}
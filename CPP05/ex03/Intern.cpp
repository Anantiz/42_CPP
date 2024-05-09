/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:44:07 by aurban            #+#    #+#             */
/*   Updated: 2024/05/09 18:15:21 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &i)
{
	(void)i;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &i)
{
	(void)i;
	return (*this);
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	static const std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i=0; i < 3; i++)
	{
		if (form == forms[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			switch (i)
			{
				case 0:
					return (new PresidentialPardonForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new ShrubberyCreationForm(target));
			}
		}
	}
	std::cout << "Form not found" << std::endl;
	return (NULL);
}
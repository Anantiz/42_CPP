/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:59:57 by aurban            #+#    #+#             */
/*   Updated: 2024/05/04 21:02:48 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) \
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm & right)
{
	(void)right;
	return (*this);
}

void PresidentialPardonForm::beExecuted(const Bureaucrat &executor)
{
	executor.executeForm(*this);
	std::cout << _target << " Has been pardoned by Zaphod Beeblerox" << std::endl;
}
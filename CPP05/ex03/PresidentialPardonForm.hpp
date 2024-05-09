/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:00:05 by aurban            #+#    #+#             */
/*   Updated: 2024/05/04 21:02:23 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:

		const std::string _target;

		PresidentialPardonForm() : AForm() {};
		PresidentialPardonForm &operator=(const PresidentialPardonForm & right);

	public:

		PresidentialPardonForm(std::string target);

		void beExecuted(const Bureaucrat &executor);
};
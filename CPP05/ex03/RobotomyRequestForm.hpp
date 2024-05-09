/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:57:19 by aurban            #+#    #+#             */
/*   Updated: 2024/05/04 21:02:17 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:

		const std::string _target;

		RobotomyRequestForm() : AForm() {};
		RobotomyRequestForm &operator=(const RobotomyRequestForm & right);

	public:

		RobotomyRequestForm(std::string target);

		void beExecuted(const Bureaucrat &executor);
};
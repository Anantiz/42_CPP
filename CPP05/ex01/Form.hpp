/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:38:32 by aurban            #+#    #+#             */
/*   Updated: 2024/05/04 16:52:04 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_status;


		Form(); // Not allowed
		Form &operator=(const Form &right); // Not allowed, can't copy _name

	public:

		Form(std::string name, int gsign, int gexec);
		Form(const Form &right);
		~Form();

		const std::string &getName() const;
		int		getGexec() const;
		int		getGsign() const;
		bool	getStatus() const;

		class GradeTooHighException : std::exception
		{
			public:
				virtual const char *what() const \
				_GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW { return ("Grade too high");}
		};

		class GradeTooLowException : std::exception
		{
			public:
				virtual const char *what() const \
				_GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW { return ("Grade too low");}
		};

		void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream&   operator<<(std::ostream &os, const Form &f);
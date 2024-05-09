/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:38:32 by aurban            #+#    #+#             */
/*   Updated: 2024/05/09 17:32:50 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:

		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_status;

		virtual AForm &operator=(const AForm &right); // Not allowed, can't copy _name

	protected:

		AForm(); // Not allowed

	public:

		AForm(std::string name, int gsign, int gexec);
		AForm(const AForm &right);
		virtual ~AForm(); // Pure virtual destructor

		virtual const std::string &getName() const;
		virtual int		getGexec() const;
		virtual int		getGsign() const;
		virtual bool	getStatus() const;
		virtual void	setStatus(bool status);

		inline void		gradeCheck(int current, int required) const;

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

		virtual void beSigned(const Bureaucrat &bureaucrat);
		virtual void beExecuted(const Bureaucrat &executor) = 0;
};

std::ostream&	operator<<(std::ostream &os, const AForm &f);
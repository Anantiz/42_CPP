#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat &right) : _name(right._name), _grade(right._grade) {}

// Stupid filling to comply with canonical form
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &right)
{
	(void)right;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade > 2)
		_grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os,const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << " Bureaucrat is grade " << bureaucrat.getGrade();
	return os;
}

void Bureaucrat::signForm(AForm &form) const
{
	if (form.getStatus())
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
	{
		std::cout << _name << " could not sign " << form.getName() \
		<< " because grade to low." << std::endl;
		throw GradeTooLowException();
	}
}

void Bureaucrat::executeForm(AForm &form) const
{
	if (form.getStatus() && _grade < form.getGexec())
		std::cout << _name << " executed " << form.getName() << std::endl;
	else
	{
		std::cout << _name << " could not execute " << form.getName() << std::endl;
		throw GradeTooLowException();
	}
}

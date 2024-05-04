#include "Form.hpp"

//Stupid requirement, because of const (Who the fuck use `const')
Form::Form() : _name("None"), _gradeSign(-1),  _gradeExec(-1), _status(false)
{
}

Form::Form(std::string name, int gsign, int gexec) : \
_name(name), _gradeSign(gexec), _gradeExec(gsign), _status(false)
{
	if (gexec < 1 || gsign < 1)
		throw GradeTooHighException();
	if (gexec > 150 || gsign > 150)
		throw GradeTooLowException();
}

Form &Form::operator=(const Form &right)
{
	(void)right;
	return *this;
}

Form::Form(const Form &right) : _name(right._name), _gradeSign(right._gradeSign), \
_gradeExec(right._gradeExec), _status(right._status)
{
}

Form::~Form() {}

/* Getters */

const std::string &Form::getName() const
{
	return _name;
}

int	Form::getGexec() const
{
	return _gradeExec;
}

int Form::getGsign() const
{
	return _gradeSign;
}

bool Form::getStatus() const
{
	return _status;
}

/* Promotion */

std::ostream&   operator<<(std::ostream& os, const Form& f)
{
	os << "Form " << f.getName() << "  Grade to sign: " << f.getGsign() \
	<< "  Grade to execute: " << f.getGexec();
	return os;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign)
		_status = true;
	bureaucrat.signForm(*this);
	if (!_status)
		throw GradeTooLowException();
}
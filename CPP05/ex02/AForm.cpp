#include "AForm.hpp"

//Stupid requirement, because of const (Who the fuck use `const')
AForm::AForm() : _name("None"), _gradeSign(-1),  _gradeExec(-1), _status(false)
{
}

AForm::AForm(std::string name, int gsign, int gexec) : \
_name(name), _gradeSign(gexec), _gradeExec(gsign), _status(false)
{
	if (gexec < 1 || gsign < 1)
		throw GradeTooHighException();
	if (gexec > 150 || gsign > 150)
		throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &right)
{
	(void)right;
	std::cout << "Illegal op called" << std::endl;
	return *this;
}

AForm::AForm(const AForm &right) : _name(right._name), _gradeSign(right._gradeSign), \
_gradeExec(right._gradeExec), _status(right._status)
{
}

AForm::~AForm() {}

/* Getters */

const std::string &AForm::getName() const
{
	return _name;
}

int	AForm::getGexec() const
{
	return _gradeExec;
}

int AForm::getGsign() const
{
	return _gradeSign;
}

bool AForm::getStatus() const
{
	return _status;
}

inline void AForm::gradeCheck(int current, int required) const {
	if (current > required)
		throw AForm::GradeTooLowException();
}

/* Promotion */

std::ostream&   operator<<(std::ostream& os, const AForm& f)
{
	os << "Form " << f.getName() << "  Grade to sign: " << f.getGsign() \
	<< "  Grade to execute: " << f.getGexec();
	return os;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign) // Check error and change status
		_status = true;
	bureaucrat.signForm(*this);
}

void AForm::beExecuted(const Bureaucrat &bureaucrat)
{
	bureaucrat.executeForm(*this);
}
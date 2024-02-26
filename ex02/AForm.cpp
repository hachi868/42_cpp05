#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

const std::string RESET = "\033[0m";
const std::string DEBUG = "\033[90m";
const std::string STATE = "\033[36m";
const std::string ALERT = "\033[31m";
const std::string MSG = "\033[34m";

AForm::AForm() : name_("default"), isSigned_(false), gradeToExecute_(GRADE_MIN), gradeToSign_(GRADE_MIN)
{
	std::cout << DEBUG << "[AForm] constructor called (default)" << RESET << std::endl;
}
AForm::AForm(const std::string &name, int gradeToExecute, int gradeToSign) : name_(name), isSigned_(false), gradeToExecute_(gradeToExecute), gradeToSign_(gradeToSign)
{
	std::cout << DEBUG << "[Form] constructor called (name, gradeToExecute, gradeToSign)" << RESET << std::endl;
	if (gradeToExecute < GRADE_MAX || gradeToSign < GRADE_MAX)
		throw GradeTooHighException();
	if (gradeToExecute > GRADE_MIN || gradeToSign > GRADE_MIN)
		throw GradeTooLowException();
}
AForm::AForm(const Form &obj) : name_(obj.name_), isSigned_(obj.isSigned_), gradeToExecute_(obj.gradeToExecute_), gradeToSign_(obj.gradeToSign_)
{
	std::cout << DEBUG << "[Form] copy constructor called" << RESET << std::endl;
}
AForm &AForm::operator = (const Form &obj)
{
	std::cout << DEBUG << "[Form] assignation operator called" << RESET << std::endl;
	if (this != &obj)
	{
		this->name_ = obj.name_;
		this->isSigned_ = obj.isSigned_;
		this->gradeToExecute_ = obj.gradeToExecute_;
		this->gradeToSign_ = obj.gradeToSign_;
	}
	return (*this);
}
AForm::~AForm()
{
	std::cout << DEBUG << "[Form] destructor called" << RESET << std::endl;
}

//accessor
std::string	AForm::getName() const
{
	return (this->name_);
}
bool		AForm::getIsSigned() const
{
	return (this->isSigned_);
}
int			AForm::getGradeToExecute() const
{
	return (this->gradeToExecute_);
}
int			AForm::getGradeToSign() const
{
	return (this->gradeToSign_);
}

//wrapper functionのBureaucrat::signForm()のtry内で呼び出す
void		AForm::beSigned(const Bureaucrat &bur)
{
	if (this->isSigned_)
		throw AForm::FormAlreadySigned();
	if (bur.getGrade() > this->gradeToSign_)
		throw AForm::GradeTooLowException();
	this->isSigned_ = true;
}

//throw
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}
const char* AForm::FormAlreadySigned::what() const throw()
{
	return ("FormAlreadySigned");
}
const char* AForm::FormNotSigned::what() const throw()
{
	return ("FormNotSigned");
}

//operator
std::ostream &operator << (std::ostream &os, const AForm &form)
{
	os << STATE << "name_: " << form.getName() << " / isSigned_: " << form.getIsSigned() << " / gradeToExecute_: " << form.getGradeToExecute() << " / gradeToSign_: " << form.getGradeToSign() << RESET;
	return (os);
}
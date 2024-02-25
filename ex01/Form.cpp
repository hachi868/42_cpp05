#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

const std::string RESET = "\033[0m";
const std::string DEBUG = "\033[90m";
const std::string STATE = "\033[36m";
const std::string ALERT = "\033[31m";
const std::string MSG = "\033[34m";

Form::Form() : name_("default"), isSigned_(false), gradeToExecute_(GRADE_MIN), gradeToSign_(GRADE_MIN)
{
	std::cout << DEBUG << "[Form] constructor called (default)" << RESET << std::endl;
}
Form::Form(const std::string &name, int gradeToExecute, int gradeToSign) : name_(name), isSigned_(false), gradeToExecute_(gradeToExecute), gradeToSign_(gradeToSign)
{
	std::cout << DEBUG << "[Form] constructor called (name, gradeToExecute, gradeToSign)" << RESET << std::endl;
	if (gradeToExecute < GRADE_MAX || gradeToSign < GRADE_MAX)
		throw GradeTooHighException();
	if (gradeToExecute > GRADE_MIN || gradeToSign > GRADE_MIN)
		throw GradeTooLowException();
}
Form::Form(const Form &obj) : name_(obj.name_), isSigned_(obj.isSigned_), gradeToExecute_(obj.gradeToExecute_), gradeToSign_(obj.gradeToSign_)
{
	std::cout << DEBUG << "[Form] copy constructor called" << RESET << std::endl;
}
Form &Form::operator = (const Form &obj)
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
Form::~Form()
{
	std::cout << DEBUG << "[Form] destructor called" << RESET << std::endl;
}

//accessor
std::string	Form::getName() const
{
	return (this->name_);
}
bool		Form::getIsSigned() const
{
	return (this->isSigned_);
}
int			Form::getGradeToExecute() const
{
	return (this->gradeToExecute_);
}
int			Form::getGradeToSign() const
{
	return (this->gradeToSign_);
}

void		Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > this->gradeToSign_)
		throw Form::GradeTooLowException();
	this->isSigned_ = true;
}

//throw
const char* Form::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}
const char* Form::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

//operator
std::ostream &operator << (std::ostream &os, const Form &form)
{
	os << STATE << form.getName() << ", isSigned_ " << form.getIsSigned() << "." << form.getGradeToExecute() << "." << form.getGradeToExecute() << RESET;
	return (os);
}
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

const std::string RESET = "\033[0m";
const std::string DEBUG = "\033[90m";
const std::string STATE = "\033[36m";
const std::string ALERT = "\033[31m";
const std::string MSG = "\033[34m";

Form::Form() : _name("default"), _isSigned(false), _gradeToExecute(GRADE_MIN), _gradeToSign(GRADE_MIN)
{
	std::cout << DEBUG << "[Form] constructor called (default)" << RESET << std::endl;
}
Form::Form(const std::string &name, int gradeToExecute, int gradeToSign) : _name(name), _isSigned(false), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign)
{
	std::cout << DEBUG << "[Form] constructor called (name, gradeToExecute, gradeToSign)" << RESET << std::endl;
	if (gradeToExecute < GRADE_MAX || gradeToSign < GRADE_MAX)
		throw GradeTooHighException();
	if (gradeToExecute > GRADE_MIN || gradeToSign > GRADE_MIN)
		throw GradeTooLowException();
}
Form::Form(const Form &obj) : _name(obj._name), _isSigned(obj._isSigned), _gradeToExecute(obj._gradeToExecute), _gradeToSign(obj._gradeToSign)
{
	std::cout << DEBUG << "[Form] copy constructor called" << RESET << std::endl;
}
Form &Form::operator = (const Form &obj)
{
	std::cout << DEBUG << "[Form] assignation operator called" << RESET << std::endl;
	if (this != &obj)
	{
		//this->_name = obj._name;
		this->_isSigned = obj._isSigned;
		//this->_gradeToExecute = obj._gradeToExecute;
		//this->_gradeToSign = obj._gradeToSign;
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
	return (this->_name);
}
bool		Form::getIsSigned() const
{
	return (this->_isSigned);
}
int			Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}
int			Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

void		Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
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
std::ostream &operator << (std::ostream &c_out, const Form &form)
{
	c_out << STATE << form.getName() << ", _isSigned " << form.getIsSigned() << "." << form.getGradeToExecute() << "." << form.getGradeToExecute() << RESET;
	return (c_out);
}
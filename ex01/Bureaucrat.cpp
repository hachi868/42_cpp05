#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

const std::string RESET = "\033[0m";
const std::string DEBUG = "\033[90m";
const std::string STATE = "\033[36m";
const std::string ALERT = "\033[31m";
const std::string MSG = "\033[34m";

Bureaucrat::Bureaucrat() : _name("default"), _grade(GRADE_MIN)
{
	std::cout << DEBUG << "[Bureaucrat] constructor called (default)" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	std::cout << DEBUG << "[Bureaucrat] constructor called (name, grade)" << RESET << std::endl;
	if (grade < GRADE_MAX)
		throw GradeTooHighException();
	if (grade > GRADE_MIN)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name), _grade(obj._grade)
{
	std::cout << DEBUG << "[Bureaucrat] copy constructor called" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &obj)
{
	std::cout << DEBUG << "[Bureaucrat] assignation operator called" << RESET << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_grade = obj._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << DEBUG << "[Bureaucrat] destructor called" << RESET << std::endl;
}

void	Bureaucrat::signForm(const Bureaucrat &bur, Form &form)
{
	try
	{
		form.beSigned(bur);
		std::cout << STATE << bur.getName() << " signed " << form.getName() << "/" << form.getIsSigned() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << ALERT << bur.getName() << " couldn’t sign " << form.getName()
		<< " because " << e.what() << RESET << std::endl;
	}
}
std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::upGrade(int ranks)
{
	if (ranks < 0 || ranks >= GRADE_MIN)
		throw GradeTooHighException();
	this->_grade -= ranks;
	if (this->_grade < GRADE_MAX)
		throw GradeTooHighException();
}

void	Bureaucrat::downGrade(int ranks)
{
	if (ranks < 0 || ranks >= GRADE_MIN)
		throw GradeTooHighException();
	this->_grade += ranks;
	if (this->_grade > GRADE_MIN)
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

std::ostream &operator << (std::ostream &c_out, const Bureaucrat &bur)
{
	c_out << STATE << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << RESET;
	return (c_out);
}
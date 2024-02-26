#include <iostream>
#include "Bureaucrat.hpp"

const std::string RESET = "\033[0m";
const std::string DEBUG = "\033[90m";
const std::string STATE = "\033[36m";
const std::string ALERT = "\033[31m";
const std::string MSG = "\033[34m";

Bureaucrat::Bureaucrat() : name_("default"), grade_(GRADE_MIN)
{
	std::cout << DEBUG << "[Bureaucrat] constructor called (default)" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : name_(name), grade_(grade)
{
	std::cout << DEBUG << "[Bureaucrat] constructor called (name, grade)" << RESET << std::endl;
	if (grade < GRADE_MAX)
		throw GradeTooHighException();
	if (grade > GRADE_MIN)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name_(obj.name_), grade_(obj.grade_)
{
	std::cout << DEBUG << "[Bureaucrat] copy constructor called" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &obj)
{
	std::cout << DEBUG << "[Bureaucrat] assignation operator called" << RESET << std::endl;
	if (this != &obj)
		this->grade_ = obj.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << DEBUG << "[Bureaucrat] destructor called" << RESET << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (this->name_);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade_);
}

void	Bureaucrat::upGrade(int ranks)
{
	if (ranks < 0 || ranks >= GRADE_MIN)
		throw GradeTooHighException();
	this->grade_ -= ranks;
	if (this->grade_ < GRADE_MAX)
		throw GradeTooHighException();
}

void	Bureaucrat::downGrade(int ranks)
{
	if (ranks < 0 || ranks >= GRADE_MIN)
		throw GradeTooHighException();
	this->grade_ += ranks;
	if (this->grade_ > GRADE_MIN)
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

std::ostream &operator << (std::ostream &os, const Bureaucrat &bur)
{
	os << STATE << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << RESET;
	return (os);
}
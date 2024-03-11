#include "Bureaucrat.hpp"

const int Bureaucrat::gradeMax_ = 1;
const int Bureaucrat::gradeMin_ = 150;

const std::string Bureaucrat::RESET = "\033[0m";
const std::string Bureaucrat::DEBUG = "\033[90m";
const std::string Bureaucrat::STATE = "\033[36m";
const std::string Bureaucrat::ALERT = "\033[31m";
const std::string Bureaucrat::MSG = "\033[34m";

Bureaucrat::Bureaucrat() : name_("default"), grade_(150)
{
	std::cout << this->DEBUG << "[Bureaucrat] constructor called (default)" << this->RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : name_(name), grade_(grade)
{
	std::cout << this->DEBUG << "[Bureaucrat] constructor called (name, grade)" << this->RESET << std::endl;
	if (grade < this->gradeMax_)
		throw GradeTooHighException();
	if (grade > this->gradeMin_)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name_(obj.name_), grade_(obj.grade_)
{
	std::cout << this->DEBUG << "[Bureaucrat] copy constructor called" << this->RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &obj)
{
	std::cout << this->DEBUG << "[Bureaucrat] assignation operator called" << this->RESET << std::endl;
	if (this != &obj)
		this->grade_ = obj.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->DEBUG << "[Bureaucrat] destructor called" << this->RESET << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (this->name_);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade_);
}

void	Bureaucrat::upGrade(int ranks=1)
{
	if (ranks < 0)
		throw GradeTooLowException();
	if (ranks >= this->gradeMin_ || this->grade_ - ranks < this->gradeMax_)
		throw GradeTooHighException();
	this->grade_ -= ranks;
}

void	Bureaucrat::downGrade(int ranks=1)
{
	if (ranks < 0)
		throw GradeTooHighException();
	if (ranks >= this->gradeMin_ || this->grade_ + ranks > this->gradeMin_)
		throw GradeTooLowException();
	this->grade_ += ranks;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

std::ostream &operator << (std::ostream &os, const Bureaucrat &obj)
{
	os << obj.STATE << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << obj.RESET;
	return (os);
}

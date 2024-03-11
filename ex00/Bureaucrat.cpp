#include "Bureaucrat.hpp"

const int Bureaucrat::gradeMax_ = 1;
const int Bureaucrat::gradeMin_ = 150;

const std::string Bureaucrat::RESET = "\033[0m";
const std::string Bureaucrat::DEBUG = "\033[90m";
const std::string Bureaucrat::STATE = "\033[36m";
const std::string Bureaucrat::ALERT = "\033[31m";
const std::string Bureaucrat::MSG = "\033[34m";

Bureaucrat::Bureaucrat() : name_("default"), grade_(Bureaucrat::gradeMin_)
{
	std::cout << Bureaucrat::DEBUG << "[Bureaucrat] constructor called (default)" << Bureaucrat::RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : name_(name), grade_(grade)
{
	std::cout << Bureaucrat::DEBUG << "[Bureaucrat] constructor called (name, grade)" << Bureaucrat::RESET << std::endl;
	if (grade < Bureaucrat::gradeMax_)
		throw GradeTooHighException();
	if (grade > Bureaucrat::gradeMin_)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name_(obj.name_), grade_(obj.grade_)
{
	std::cout << Bureaucrat::DEBUG << "[Bureaucrat] copy constructor called" << Bureaucrat::RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &obj)
{
	std::cout << Bureaucrat::DEBUG << "[Bureaucrat] assignation operator called" << Bureaucrat::RESET << std::endl;
	if (this != &obj)
		this->grade_ = obj.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << Bureaucrat::DEBUG << "[Bureaucrat] destructor called" << Bureaucrat::RESET << std::endl;
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
	if (ranks >= Bureaucrat::gradeMin_ || this->grade_ - ranks < Bureaucrat::gradeMax_)
		throw GradeTooHighException();
	this->grade_ -= ranks;
}

void	Bureaucrat::downGrade(int ranks=1)
{
	if (ranks < 0)
		throw GradeTooHighException();
	if (ranks >= Bureaucrat::gradeMin_ || this->grade_ + ranks > Bureaucrat::gradeMin_)
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

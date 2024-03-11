#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static AForm *constructShrubberyCreation(const std::string &targetForm)
{
	return (new ShrubberyCreationForm(targetForm));
}

static AForm *constructRobotomyRequest(const std::string &targetForm)
{
	return (new RobotomyRequestForm(targetForm));
}

static AForm *constructPresidentialPardon(const std::string &targetForm)
{
	return (new PresidentialPardonForm(targetForm));
}


Intern::Intern()
{
	std::cout << Bureaucrat::DEBUG << "[Intern] constructor called (default)" << Bureaucrat::RESET << std::endl;
}

Intern::Intern(const Intern &obj)
{
	(void)obj;
	std::cout << Bureaucrat::DEBUG << "[Intern] copy constructor called" << Bureaucrat::RESET << std::endl;
}

Intern &Intern::operator = (const Intern &obj)
{
	(void)obj;
	std::cout << Bureaucrat::DEBUG << "[Intern] assignation operator called" << Bureaucrat::RESET << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << Bureaucrat::DEBUG << "[Intern] destructor called" << Bureaucrat::RESET << std::endl;
}

AForm *Intern::makeForm(const std::string &nameForm, const std::string &targetForm)
{
	const char	*listFormNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	FuncPointer listFormFunc[] = {constructShrubberyCreation, constructRobotomyRequest, constructPresidentialPardon};

	int	i = 0;
	while(i < 3)
	{
		if (listFormNames[i] == nameForm)
		{
			std::cout << Bureaucrat::STATE << "Intern creates " << nameForm << "." << Bureaucrat::RESET << std::endl;
			return (listFormFunc[i](targetForm));
		}
		i++;
	}
	throw FormNameMismatchException();
}

const char* Intern::FormNameMismatchException::what() const throw()
{
	return ("nameForm is missing from form list");
}
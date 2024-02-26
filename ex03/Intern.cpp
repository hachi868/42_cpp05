#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const std::string RESET = "\033[0m";
const std::string DEBUG = "\033[90m";
const std::string STATE = "\033[36m";
const std::string ALERT = "\033[31m";
const std::string MSG = "\033[34m";

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


AForm *Intern::makeForm(const std::string &nameForm, const std::string &targetForm)
{
	const char	*listFormNames[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	FuncPointer listFormFunc[] = {constructShrubberyCreation, constructRobotomyRequest, constructPresidentialPardon};

	int	i = 0;
	while(i < 3)
	{
		if (listFormNames[i] == nameForm)
		{
			std::cout << STATE << "Intern creates " << nameForm << "." << RESET << std::endl;
			return (listFormFunc[i](targetForm));
		}
		i++;
	}
	std::cout << ALERT << nameForm << " couldn’t creates because nameForm is missing from form list." << RESET << std::endl;
	return (NULL);
}

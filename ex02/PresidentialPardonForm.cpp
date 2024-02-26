#include <iostream>
#include "PresidentialPardonForm.hpp"

const std::string RESET = "\033[0m";
const std::string DEBUG = "\033[90m";
const std::string STATE = "\033[36m";
const std::string ALERT = "\033[31m";
const std::string MSG = "\033[34m";

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential_Pardon", GRADE_TO_EXE_PP, GRADE_TO_SIGN_PP, "target")
{
	std::cout << DEBUG << "[PresidentialPardonForm] constructor called (default)" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &name, const int gradeToExecute, const int gradeToSign, const std::string &target)
	: AForm(name, GRADE_TO_EXE_PP, GRADE_TO_SIGN_PP, target)
{
	(void)gradeToExecute;
	(void)gradeToSign;
	std::cout << DEBUG << "[PresidentialPardonForm] constructor called (name, gradeToExecute, gradeToSign)" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
	: AForm(obj.getName(), GRADE_TO_EXE_PP, GRADE_TO_SIGN_PP, obj.getTarget())
{
	std::cout << DEBUG << "[PresidentialPardonForm] copy constructor called" << RESET << std::endl;
}
PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &obj)
{
	std::cout << DEBUG << "[PresidentialPardonForm] assignation operator called" << RESET << std::endl;
	if (this != &obj)
		AForm::operator = (obj);
	return (*this);
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
		: AForm("Presidential_Pardon", GRADE_TO_EXE_PP, GRADE_TO_SIGN_PP, target)
{
	std::cout << DEBUG << "[PresidentialPardonForm] constructor called (target)" << RESET << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << DEBUG << "[PresidentialPardonForm] destructor called" << RESET << std::endl;
}

//func
void	PresidentialPardonForm::executeConcreteAction() const
{
	std::cout << STATE << PresidentialPardonForm::getTarget() << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
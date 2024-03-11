#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

const int PresidentialPardonForm::gradeToExePP_ = 5;
const int PresidentialPardonForm::gradeToSignPP_ = 25;

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential_Pardon", PresidentialPardonForm::gradeToExePP_, PresidentialPardonForm::gradeToSignPP_, "target")
{
	std::cout << Bureaucrat::DEBUG << "[PresidentialPardonForm] constructor called (default)" << Bureaucrat::RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name, const int gradeToExecute, const int gradeToSign, const std::string &target)
	: AForm(name, PresidentialPardonForm::gradeToExePP_, PresidentialPardonForm::gradeToSignPP_, target)
{
	(void)gradeToExecute;
	(void)gradeToSign;
	std::cout << Bureaucrat::DEBUG << "[PresidentialPardonForm] constructor called (name, gradeToExecute, gradeToSign)" << Bureaucrat::RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
	: AForm(obj.getName(), PresidentialPardonForm::gradeToExePP_, PresidentialPardonForm::gradeToSignPP_, obj.getTarget())
{
	std::cout << Bureaucrat::DEBUG << "[PresidentialPardonForm] copy constructor called" << Bureaucrat::RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &obj)
{
	std::cout << Bureaucrat::DEBUG << "[PresidentialPardonForm] assignation operator called" << Bureaucrat::RESET << std::endl;
	if (this != &obj)
		AForm::operator = (obj);
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
		: AForm("Presidential_Pardon", PresidentialPardonForm::gradeToExePP_, PresidentialPardonForm::gradeToSignPP_, target)
{
	std::cout << Bureaucrat::DEBUG << "[PresidentialPardonForm] constructor called (target)" << Bureaucrat::RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << Bureaucrat::DEBUG << "[PresidentialPardonForm] destructor called" << Bureaucrat::RESET << std::endl;
}

//func
void	PresidentialPardonForm::executeConcreteAction() const
{
	std::cout << Bureaucrat::STATE << PresidentialPardonForm::getTarget() << " has been pardoned by Zaphod Beeblebrox." << Bureaucrat::RESET << std::endl;
}
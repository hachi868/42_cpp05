#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

const int ShrubberyCreationForm::gradeToExeSC_ = 137;
const int ShrubberyCreationForm::gradeToSignSC_ = 145;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery_Creation", ShrubberyCreationForm::gradeToExeSC_, ShrubberyCreationForm::gradeToSignSC_, "target")
{
	std::cout << Bureaucrat::DEBUG << "[ShrubberyCreationForm] constructor called (default)" << Bureaucrat::RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name, const int gradeToExecute, const int gradeToSign, const std::string &target)
	: AForm(name, ShrubberyCreationForm::gradeToExeSC_, ShrubberyCreationForm::gradeToSignSC_, target)
{
	(void)gradeToExecute;
	(void)gradeToSign;
	std::cout << Bureaucrat::DEBUG << "[ShrubberyCreationForm] constructor called (name, gradeToExecute, gradeToSign)" << Bureaucrat::RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
	: AForm(obj.getName(), ShrubberyCreationForm::gradeToExeSC_, ShrubberyCreationForm::gradeToSignSC_, obj.getTarget())
{
	std::cout << Bureaucrat::DEBUG << "[ShrubberyCreationForm] copy constructor called" << Bureaucrat::RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &obj)
{
	std::cout << Bureaucrat::DEBUG << "[ShrubberyCreationForm] assignation operator called" << Bureaucrat::RESET << std::endl;
	if (this != &obj)
		AForm::operator = (obj);
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
		: AForm("Shrubbery_Creation", ShrubberyCreationForm::gradeToExeSC_, ShrubberyCreationForm::gradeToSignSC_, target)
{
	std::cout << Bureaucrat::DEBUG << "[ShrubberyCreationForm] constructor called (target)" << Bureaucrat::RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << Bureaucrat::DEBUG << "[ShrubberyCreationForm] destructor called" << Bureaucrat::RESET << std::endl;
}

//func
void	ShrubberyCreationForm::executeConcreteAction() const
{
	try
	{
		std::string fileOutfile = getTarget() + "_shrubbery";
		std::ofstream file(fileOutfile);
		if (!file.is_open())
			throw ShrubberyCreationForm::CouldntOpenFile();
		file << "    ^   " << std::endl;
		file << "   / \\  " << std::endl;
		file << "  /   \\ " << std::endl;
		file << " /_____\\" << std::endl;
		file << "   |||   " << std::endl;
		file.close();
	}
	catch (std::exception &e)
	{
		std::cerr << Bureaucrat::ALERT << e.what() << "." << Bureaucrat::RESET << std::endl;
	}
}

const char* ShrubberyCreationForm::CouldntOpenFile::what() const throw()
{
	return ("Couldn’t open file");
}
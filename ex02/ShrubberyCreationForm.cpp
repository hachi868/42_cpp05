#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

const std::string RESET = "\033[0m";
const std::string DEBUG = "\033[90m";
const std::string STATE = "\033[36m";
const std::string ALERT = "\033[31m";
const std::string MSG = "\033[34m";

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery_Creation", GRADE_TO_EXE_SC, GRADE_TO_SIGN_SC, "target")
{
	std::cout << DEBUG << "[ShrubberyCreationForm] constructor called (default)" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name, const int gradeToExecute, const int gradeToSign, const std::string &target)
	: AForm(name, GRADE_TO_EXE_SC, GRADE_TO_SIGN_SC, target)
{
	(void)gradeToExecute;
	(void)gradeToSign;
	std::cout << DEBUG << "[ShrubberyCreationForm] constructor called (name, gradeToExecute, gradeToSign)" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
	: AForm(obj.getName(), GRADE_TO_EXE_SC, GRADE_TO_SIGN_SC, obj.getTarget())
{
	std::cout << DEBUG << "[ShrubberyCreationForm] copy constructor called" << RESET << std::endl;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &obj)
{
	std::cout << DEBUG << "[ShrubberyCreationForm] assignation operator called" << RESET << std::endl;
	if (this != &obj)
		AForm::operator = (obj);
	return (*this);
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
		: AForm("Shrubbery_Creation", GRADE_TO_EXE_SC, GRADE_TO_SIGN_SC, target)
{
	std::cout << DEBUG << "[ShrubberyCreationForm] constructor called (target)" << RESET << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << DEBUG << "[ShrubberyCreationForm] destructor called" << RESET << std::endl;
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
		std::cout << ALERT << e.what() << "." << RESET << std::endl;
	}
}

const char* ShrubberyCreationForm::CouldntOpenFile::what() const throw()
{
	return ("Couldn’t open file");
}
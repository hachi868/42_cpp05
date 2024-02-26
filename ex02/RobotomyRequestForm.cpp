#include <iostream>
#include <cstdlib> // for rand(), srand()
#include <ctime>   // for time()
#include "RobotomyRequestForm.hpp"

const std::string RESET = "\033[0m";
const std::string DEBUG = "\033[90m";
const std::string STATE = "\033[36m";
const std::string ALERT = "\033[31m";
const std::string MSG = "\033[34m";

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy_Request", GRADE_TO_EXE_RR, GRADE_TO_SIGN_RR, "target")
{
	std::cout << DEBUG << "[RobotomyRequestForm] constructor called (default)" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name, const int gradeToExecute, const int gradeToSign, const std::string &target)
	: AForm(name, GRADE_TO_EXE_RR, GRADE_TO_SIGN_RR, target)
{
	(void)gradeToExecute;
	(void)gradeToSign;
	std::cout << DEBUG << "[RobotomyRequestForm] constructor called (name, gradeToExecute, gradeToSign)" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
	: AForm(obj.getName(), GRADE_TO_EXE_RR, GRADE_TO_SIGN_RR, obj.getTarget())
{
	std::cout << DEBUG << "[RobotomyRequestForm] copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &obj)
{
	std::cout << DEBUG << "[RobotomyRequestForm] assignation operator called" << RESET << std::endl;
	if (this != &obj)
		AForm::operator = (obj);
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
		: AForm("Robotomy_Request", GRADE_TO_EXE_RR, GRADE_TO_SIGN_RR, target)
{
	std::cout << DEBUG << "[RobotomyRequestForm] constructor called (target)" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << DEBUG << "[RobotomyRequestForm] destructor called" << RESET << std::endl;
}

//func
void	RobotomyRequestForm::executeConcreteAction() const
{
	//シード値を毎回変更する
	srand(static_cast<unsigned int>(time(0)));
	std::cout << MSG << "(((((( wreeeeeeee wreeeeeeee wreeeeeeee ))))))" << RESET << std::endl;
	if (rand() % 2)
		std::cout << STATE << RobotomyRequestForm::getTarget() << " successfully underwent robotomy." << RESET << std::endl;
	else
		std::cout << STATE << "Robotomy of " << RobotomyRequestForm::getTarget() << " failed." << RESET << std::endl;
}
#include <cstdlib> // for rand(), srand()
#include <sys/time.h>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

const int RobotomyRequestForm::gradeToExeRR_ = 45;
const int RobotomyRequestForm::gradeToSignRR_ = 72;

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy_Request", RobotomyRequestForm::gradeToExeRR_, RobotomyRequestForm::gradeToSignRR_, "target")
{
	std::cout << Bureaucrat::DEBUG << "[RobotomyRequestForm] constructor called (default)" << Bureaucrat::RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name, const int gradeToExecute, const int gradeToSign, const std::string &target)
	: AForm(name, RobotomyRequestForm::gradeToExeRR_, RobotomyRequestForm::gradeToSignRR_, target)
{
	(void)gradeToExecute;
	(void)gradeToSign;
	std::cout << Bureaucrat::DEBUG << "[RobotomyRequestForm] constructor called (name, gradeToExecute, gradeToSign)" << Bureaucrat::RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
	: AForm(obj.getName(), RobotomyRequestForm::gradeToExeRR_, RobotomyRequestForm::gradeToSignRR_, obj.getTarget())
{
	std::cout << Bureaucrat::DEBUG << "[RobotomyRequestForm] copy constructor called" << Bureaucrat::RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &obj)
{
	std::cout << Bureaucrat::DEBUG << "[RobotomyRequestForm] assignation operator called" << Bureaucrat::RESET << std::endl;
	if (this != &obj)
		AForm::operator = (obj);
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
		: AForm("Robotomy_Request", RobotomyRequestForm::gradeToExeRR_, RobotomyRequestForm::gradeToSignRR_, target)
{
	std::cout << Bureaucrat::DEBUG << "[RobotomyRequestForm] constructor called (target)" << Bureaucrat::RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << Bureaucrat::DEBUG << "[RobotomyRequestForm] destructor called" << Bureaucrat::RESET << std::endl;
}

//func
void	RobotomyRequestForm::executeConcreteAction() const
{
	//シード値を毎回変更する
	struct timeval tv;
	gettimeofday(&tv, NULL);
	srand(static_cast<unsigned int>(tv.tv_usec));
	std::cout << Bureaucrat::MSG << "(((((( wreeeeeeee wreeeeeeee wreeeeeeee ))))))" << Bureaucrat::RESET << std::endl;
	if (rand() % 2)
		std::cout << Bureaucrat::STATE << RobotomyRequestForm::getTarget() << " successfully underwent robotomy." << Bureaucrat::RESET << std::endl;
	else
		std::cout << Bureaucrat::ALERT << "Robotomy of " << RobotomyRequestForm::getTarget() << " failed." << Bureaucrat::RESET << std::endl;
}
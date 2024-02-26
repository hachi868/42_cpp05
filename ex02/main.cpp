#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const std::string RESET = "\033[0m";
const std::string DEBUG = "\033[90m";
const std::string STATE = "\033[36m";
const std::string ALERT = "\033[31m";
const std::string MSG = "\033[34m";

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex02");
}

int	main(void)
{
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test ShrubberyCreationForm]" << std::endl;
		Bureaucrat bur0a("bur0a", 135);
		Bureaucrat bur0b("bur0b", 140);
		Bureaucrat bur0c("bur0c", 148);
		ShrubberyCreationForm form0("test0");
		// unable to exec(FormNotSigned)
		bur0a.executeForm(form0);
		// unable to sign(GradeTooLowException)
		bur0c.signForm(form0);
		// able to sign
		bur0b.signForm(form0);
		// unable to exec(GradeTooLowException)
		bur0b.executeForm(form0);
		// unable to sign(FormAlreadySigned)
		bur0a.signForm(form0);
		// able to exec
		bur0a.executeForm(form0);
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test RobotomyRequestForm]" << std::endl;
		Bureaucrat bur1a("bur1a", 40);
		Bureaucrat bur1b("bur1b", 60);
		Bureaucrat bur1c("bur1c", 80);
		RobotomyRequestForm form1("test1");
		// unable to exec(FormNotSigned)
		bur1a.executeForm(form1);
		// unable to sign(GradeTooLowException)
		bur1c.signForm(form1);
		// able to sign
		bur1b.signForm(form1);
		// unable to exec(GradeTooLowException)
		bur1b.executeForm(form1);
		// unable to sign(FormAlreadySigned)
		bur1a.signForm(form1);
		// able to exec
		bur1a.executeForm(form1);
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test PresidentialPardonForm]" << std::endl;
		Bureaucrat bur2a("bur2a", 3);
		Bureaucrat bur2b("bur2b", 20);
		Bureaucrat bur2c("bur2c", 30);
		PresidentialPardonForm form2("test2");
		// unable to exec(FormNotSigned)
		bur2a.executeForm(form2);
		// unable to sign(GradeTooLowException)
		bur2c.signForm(form2);
		// able to sign
		bur2b.signForm(form2);
		// unable to exec(GradeTooLowException)
		bur2b.executeForm(form2);
		// unable to sign(FormAlreadySigned)
		bur2a.signForm(form2);
		// able to exec
		bur2a.executeForm(form2);
	}

	return (0);
}

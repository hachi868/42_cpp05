#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex03");
}

int	main(void)
{
	{
		std::cout << "[test0] shrubbery creation(success)" << std::endl;
		try {
			Intern intern0;
			AForm* form0;
			form0 = intern0.makeForm("shrubbery creation", "form_sc");
			std::cout << *form0 << std::endl;
			delete form0;
		} catch (std::exception& e) {
			std::cerr << Bureaucrat::ALERT << "[Exception caught] " << e.what() << "." << Bureaucrat::RESET << std::endl;
		}
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test1] robotomy request(success)" << std::endl;
		try {
			Intern intern1;
			AForm* form1;
			form1 = intern1.makeForm("robotomy request", "form_rr");
			std::cout << *form1 << std::endl;
			delete form1;
		} catch (std::exception& e) {
			std::cerr << Bureaucrat::ALERT << "[Exception caught] " << e.what() << "." << Bureaucrat::RESET << std::endl;
		}
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test2] presidential pardon(success)" << std::endl;
		try {
			Intern intern2;
			AForm* form2;
			form2 = intern2.makeForm("presidential pardon", "form_pp");
			std::cout << *form2 << std::endl;
			delete form2;
		} catch (std::exception& e) {
			std::cerr << Bureaucrat::ALERT << "[Exception caught] " << e.what() << "." << Bureaucrat::RESET << std::endl;
		}
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test3] Shrubbery Creation(fail)" << std::endl;
		try {
			Intern intern3;
			AForm* form3;
			form3 = intern3.makeForm("Shrubbery Creation", "form_sc_fail");
			std::cout << *form3 << std::endl;
			delete form3;
		} catch (std::exception& e) {
			std::cerr << Bureaucrat::ALERT << "[Exception caught] " << e.what() << "." << Bureaucrat::RESET << std::endl;
		}
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	return (0);
}

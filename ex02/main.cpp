#include <iostream>
#include "Bureaucrat.hpp"
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
	AForm		*presidential = new PresidentialPardonForm("Correcteur");
	Bureaucrat	me3("Lucie", 4);

	me3.executeForm(*presidential);
	me3.signForm(*presidential);
	me3.executeForm(*presidential);
	delete presidential;

	return (0);
}

#include <iostream>
#include "Bureaucrat.hpp"

const std::string RESET = "\033[0m";
const std::string DEBUG = "\033[90m";
const std::string STATE = "\033[36m";
const std::string ALERT = "\033[31m";
const std::string MSG = "\033[34m";

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex01");
}

int main()
{
	{
		std::cout << "[test Form 0] constructor" << std::endl;
		// tryで呼び出した関数内部の例外をcatchで捕捉
		try {
			Form form0a;
			std::cout << STATE << form0a << RESET << std::endl;
			Form form0b(form0a);
			std::cout << STATE << form0b << RESET << std::endl;
			Form form0c = form0a;
			std::cout << STATE << form0c << RESET << std::endl;
			form0c = form0a;
			std::cout << STATE << form0c << RESET << std::endl;
			Form form0d("form0d", 160, 10);
			std::cout << STATE << form0d << RESET << std::endl;
			Form form0e("form0e", 4, 10);
			std::cout << form0e << std::endl;
			Form* form0f = new Form("form0f", 1, 2);
			std::cout << STATE << *form0f << RESET << std::endl;
			delete form0f;
		} catch (std::exception& e) {
			std::cout << ALERT << "[Exception caught] " << e.what() << "." << RESET << std::endl;
		}
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test Form 1] displayInfo" << std::endl;
		try {
			Form form1a("form1a", 100, 10);
			Form form1b("form1b", 10, 100);
			std::cout << STATE << form1a.getName() << " / " << form1a.getIsSigned() << " / " << form1a.getGradeToExecute() << " / " << form1a.getGradeToSign() << RESET << std::endl;
			std::cout << STATE << form1b.getName() << " / " << form1b.getIsSigned() << " / " << form1b.getGradeToExecute() << " / " << form1b.getGradeToSign() << RESET << std::endl;
		} catch (std::exception& e) {
			std::cout << ALERT << "[Exception caught] " << e.what() << "." << RESET << std::endl;
		}
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test Form 2] able to sign." << std::endl;
		Bureaucrat bur2("bur", 10);
		Form form2("form", 100, 100);
		bur2.signForm(form2);
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test Form 3] unable to sign.(low rank)" << std::endl;
		Bureaucrat bur3("bur", 100);
		Form form3("form", 10, 10);
		bur3.signForm(form3);
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test Form 4] unable to sign.(already signed)" << std::endl;
		//例外throwはサイン済みかが優先度高い
		Bureaucrat bur4a("bur", 20);
		Bureaucrat bur4b("bur", 10);
		Bureaucrat bur4c("bur", 101);
		Form form4("form", 100, 100);
		bur4c.signForm(form4);
		bur4a.signForm(form4);
		bur4b.signForm(form4);
		bur4c.signForm(form4);
	}
	return (0);
}

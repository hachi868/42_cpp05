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
		std::cout << "[test0] constructor" << std::endl;
		try {
			Bureaucrat bur1;
			Bureaucrat bur1a(bur1);
			Bureaucrat bur2 = bur1a;
			bur1 = bur2;
			Bureaucrat bur3("bur3", 100);
			Bureaucrat bur4("bur4", 4);
			Bureaucrat* bur5 = new Bureaucrat("bur5", 1);
			std::cout << STATE << bur1 << RESET << std::endl;
			std::cout << STATE << bur1a << RESET << std::endl;
			std::cout << STATE << bur2 << RESET << std::endl;
			std::cout << STATE << bur3 << RESET << std::endl;
			std::cout << bur4 << std::endl;
			std::cout << STATE << *bur5 << RESET << std::endl;
			delete bur5;
		} catch (std::exception& e) {
			std::cout << ALERT << e.what() << RESET << std::endl;
		}
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test2] displayInfo" << std::endl;
		try {
			Bureaucrat bur6("bur6", 100);
			Bureaucrat bur7("bur7", 10);
			std::cout << STATE << bur6.getName() << " / " << bur6.getGrade() << RESET << std::endl;
			std::cout << STATE << bur7.getName() << " / " << bur7.getGrade() << RESET << std::endl;
		} catch (std::exception& e) {
			std::cout << ALERT << e.what() << RESET << std::endl;
		}
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test3] grade up" << std::endl;
		try {
			Bureaucrat bur8("bur8", 3);
			int i = 0;
			while (i < 5)
			{
				std::cout << bur8 << std::endl;
				bur8.upGrade(1);
				i++;
			}
		} catch (std::exception& e) {
			std::cout << ALERT << e.what() << RESET << std::endl;
		}
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test3] grade down" << std::endl;
		try {
			Bureaucrat bur9("bur9", 148);
			int i = 0;
			while (i < 5)
			{
				std::cout << bur9 << std::endl;
				bur9.downGrade(1);
				i++;
			}
		} catch (std::exception& e) {
			std::cout << ALERT << e.what() << RESET << std::endl;
		}
	}
	return (0);
}

#include <iostream>
#include "Bureaucrat.hpp"

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex00");
}

int main()
{
	{
		std::cout << "[test0] constructor" << std::endl;
		// tryで呼び出した関数内部の例外をcatchで捕捉
		try {
			Bureaucrat bur1;
			std::cout << Bureaucrat::STATE << bur1 << Bureaucrat::RESET << std::endl;
			Bureaucrat bur1a(bur1);
			std::cout << Bureaucrat::STATE << bur1a << Bureaucrat::RESET << std::endl;
			Bureaucrat bur2 = bur1a;
			std::cout << Bureaucrat::STATE << bur2 << Bureaucrat::RESET << std::endl;
			bur1 = bur2;
			std::cout << Bureaucrat::STATE << bur1 << Bureaucrat::RESET << std::endl;
			Bureaucrat bur3("bur3", 100);
			std::cout << Bureaucrat::STATE << bur3 << Bureaucrat::RESET << std::endl;
			Bureaucrat bur4("bur4", 4);
			std::cout << bur4 << std::endl;
			Bureaucrat* bur5 = new Bureaucrat("bur5", 1);
			std::cout << Bureaucrat::STATE << *bur5 << Bureaucrat::RESET << std::endl;
			delete bur5;
		} catch (std::exception& e) {
			std::cerr << Bureaucrat::ALERT << "[Exception caught] " << e.what() << "." << Bureaucrat::RESET << std::endl;
		}
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test1] displayInfo" << std::endl;
		try {
			Bureaucrat bur6("bur6", 100);
			Bureaucrat bur7("bur7", 10);
			std::cout << Bureaucrat::STATE << bur6.getName() << " / " << bur6.getGrade() << Bureaucrat::RESET << std::endl;
			std::cout << Bureaucrat::STATE << bur7.getName() << " / " << bur7.getGrade() << Bureaucrat::RESET << std::endl;
		} catch (std::exception& e) {
			std::cerr << Bureaucrat::ALERT << "[Exception caught] " << e.what() << "." << Bureaucrat::RESET << std::endl;
		}
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test2] grade up" << std::endl;
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
			std::cerr << Bureaucrat::ALERT << "[Exception caught] " << e.what() << "." << Bureaucrat::RESET << std::endl;
		}
		std::cout << "---" << std::endl;
		//UPするランク数0はOK
		try {
			Bureaucrat bur8("bur8", 3);
			bur8.upGrade(0);
		} catch (std::exception& e) {
			std::cerr << Bureaucrat::ALERT << "[Exception caught] " << e.what() << "." << Bureaucrat::RESET << std::endl;
		}
		std::cout << "---" << std::endl;
		//UPするランク数 Bureaucrat::gradeMin_はNG
		try {
			Bureaucrat bur8("bur8", 3);
			bur8.upGrade(Bureaucrat::gradeMin_);
		} catch (std::exception& e) {
			std::cerr << Bureaucrat::ALERT << "[Exception caught] " << e.what() << "." << Bureaucrat::RESET << std::endl;
		}
		std::cout << "---" << std::endl;
		//UPするランク数 < 0 はNG
		try {
			Bureaucrat bur8("bur8", 3);
			bur8.upGrade(-1);
		} catch (std::exception& e) {
			std::cerr << Bureaucrat::ALERT << "[Exception caught] " << e.what() << "." << Bureaucrat::RESET << std::endl;
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
			std::cerr << Bureaucrat::ALERT << "[Exception caught] " << e.what() << "." << Bureaucrat::RESET << std::endl;
		}
		std::cout << "---" << std::endl;
		//DOWNするランク数0はOK
		try {
			Bureaucrat bur8("bur8", 3);
			bur8.downGrade(0);
		} catch (std::exception& e) {
			std::cerr << Bureaucrat::ALERT << "[Exception caught] " << e.what() << "." << Bureaucrat::RESET << std::endl;
		}
		std::cout << "---" << std::endl;
		//DOWNするランク数 Bureaucrat::gradeMin_はNG
		try {
			Bureaucrat bur8("bur8", 3);
			bur8.downGrade(Bureaucrat::gradeMin_);
		} catch (std::exception& e) {
			std::cerr << Bureaucrat::ALERT << "[Exception caught] " << e.what() << "." << Bureaucrat::RESET << std::endl;
		}
		std::cout << "---" << std::endl;
		//DOWNするランク数 < 0 はNG
		try {
			Bureaucrat bur8("bur8", 3);
			bur8.downGrade(-1);
		} catch (std::exception& e) {
			std::cerr << Bureaucrat::ALERT << "[Exception caught] " << e.what() << "." << Bureaucrat::RESET << std::endl;
		}
	}
	return (0);
}

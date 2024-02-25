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
	/*
	{
		std::cout << "[test Bureaucrat 0] constructor" << std::endl;
		// tryで呼び出した関数内部の例外をcatchで捕捉
		try {
			Bureaucrat bur1;
			std::cout << STATE << bur1 << RESET << std::endl;
			Bureaucrat bur1a(bur1);
			std::cout << STATE << bur1a << RESET << std::endl;
			Bureaucrat bur2 = bur1a;
			std::cout << STATE << bur2 << RESET << std::endl;
			bur1 = bur2;
			std::cout << STATE << bur1 << RESET << std::endl;
			Bureaucrat bur3("bur3", 100);
			std::cout << STATE << bur3 << RESET << std::endl;
			Bureaucrat bur4("bur4", 4);
			std::cout << bur4 << std::endl;
			Bureaucrat* bur5 = new Bureaucrat("bur5", 1);
			std::cout << STATE << *bur5 << RESET << std::endl;
			delete bur5;
		} catch (std::exception& e) {
			std::cout << ALERT << e.what() << RESET << std::endl;
		}
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test Bureaucrat 1] displayInfo" << std::endl;
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
		std::cout << "[test Bureaucrat 2] grade up" << std::endl;
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
		std::cout << "---" << std::endl;
		//UPするランク数0はOK
		try {
			Bureaucrat bur8("bur8", 3);
			bur8.upGrade(0);
		} catch (std::exception& e) {
			std::cout << ALERT << e.what() << RESET << std::endl;
		}
		std::cout << "---" << std::endl;
		//UPするランク数 GRADE_MINはNG
		try {
			Bureaucrat bur8("bur8", 3);
			bur8.upGrade(GRADE_MIN);
		} catch (std::exception& e) {
			std::cout << ALERT << e.what() << RESET << std::endl;
		}
		std::cout << "---" << std::endl;
		//UPするランク数 < 0 はNG
		try {
			Bureaucrat bur8("bur8", 3);
			bur8.upGrade(-1);
		} catch (std::exception& e) {
			std::cout << ALERT << e.what() << RESET << std::endl;
		}
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test Bureaucrat 3] grade down" << std::endl;
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
		std::cout << "---" << std::endl;
		//DOWNするランク数0はOK
		try {
			Bureaucrat bur8("bur8", 3);
			bur8.downGrade(0);
		} catch (std::exception& e) {
			std::cout << ALERT << e.what() << RESET << std::endl;
		}
		std::cout << "---" << std::endl;
		//DOWNするランク数 GRADE_MINはNG
		try {
			Bureaucrat bur8("bur8", 3);
			bur8.downGrade(GRADE_MIN);
		} catch (std::exception& e) {
			std::cout << ALERT << e.what() << RESET << std::endl;
		}
		std::cout << "---" << std::endl;
		//DOWNするランク数 < 0 はNG
		try {
			Bureaucrat bur8("bur8", 3);
			bur8.downGrade(-1);
		} catch (std::exception& e) {
			std::cout << ALERT << e.what() << RESET << std::endl;
		}
	}
	*/
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
			Form form0d("form0d", 100, 10);
			std::cout << STATE << form0d << RESET << std::endl;
			Form form0e("form0e", 4, 10);
			std::cout << form0e << std::endl;
			Form* form0f = new Form("form0f", 1, 2);
			std::cout << STATE << *form0f << RESET << std::endl;
			delete form0f;
		} catch (std::exception& e) {
			std::cout << ALERT << e.what() << RESET << std::endl;
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
			std::cout << ALERT << e.what() << RESET << std::endl;
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

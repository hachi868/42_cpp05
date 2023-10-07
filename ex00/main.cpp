#include <iostream>
#include "Bureaucrat.hpp"
#define RESET "\033[m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BOLD "\033[1m"
__attribute__((destructor))
static void destructor() {
	system("leaks -q ex00");
}

int main()
{
	{
		std::cout << "[test0] Bureaucrat" << std::endl;

		//Bureaucrat* d = new Bureaucrat("me", 1);
		//ポインタでインスタンスにできない？
		try {
			Bureaucrat d("bur1", 1);
			std::cout << d << std::endl;
		} catch (std::exception& e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
//		Bureaucrat Bureaucrat("bur2", 100);
//		Bureaucrat Bureaucrat("bur3", 1000);

		Bureaucrat a;
		Bureaucrat b(a);
		Bureaucrat c = b;
		a = c;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	return (0);
}

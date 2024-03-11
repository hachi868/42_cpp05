#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &obj);
	Intern &operator = (const Intern &obj);
	~Intern();

	//func
	AForm *makeForm(const std::string &nameForm, const std::string &targetForm);
	typedef AForm *(*FuncPointer)(const std::string &);

	//throw
	class FormNameMismatchException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};
#endif //INTERN_HPP

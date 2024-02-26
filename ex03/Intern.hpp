#ifndef __INTERN_H__
#define __INTERN_H__

# include "AForm.hpp"

class Intern {
public:
	Intern();
//	Intern(const std::string &name, const int grade);
//	Intern(const Bureaucrat &obj);
//	Intern &operator = (const Bureaucrat &obj);
	~Intern();

	//func
	AForm *makeForm(const std::string &nameForm, const std::string &targetForm);

	//throw

private:
};
typedef AForm *(*FuncPointer)(const std::string &);
#endif //__INTERN_H__

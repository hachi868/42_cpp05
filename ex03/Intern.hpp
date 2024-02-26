#ifndef __INTERN_H__
#define __INTERN_H__

# include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &obj);
	Intern &operator = (const Intern &obj);
	~Intern();

	//func
	AForm *makeForm(const std::string &nameForm, const std::string &targetForm);

	//throw
};
typedef AForm *(*FuncPointer)(const std::string &);
#endif //__INTERN_H__

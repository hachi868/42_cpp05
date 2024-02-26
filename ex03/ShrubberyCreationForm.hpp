#ifndef __SHRUBBERY_CREATION_FORM_H__
#define __SHRUBBERY_CREATION_FORM_H__

#include "Bureaucrat.hpp"

# define GRADE_TO_EXE_SC	137
# define GRADE_TO_SIGN_SC	145

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &name, const int gradeToExecute, const int gradeToSign, const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &obj);
	ShrubberyCreationForm &operator = (const ShrubberyCreationForm &obj);
	ShrubberyCreationForm(const std::string &target);
	virtual ~ShrubberyCreationForm();

private:
	virtual void	executeConcreteAction() const;

	class CouldntOpenFile : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif //__SHRUBBERY_CREATION_FORM_H__

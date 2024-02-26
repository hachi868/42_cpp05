#ifndef __PRESIDENTIAL_PARDON_FORM_H__
#define __PRESIDENTIAL_PARDON_FORM_H__

#include "Bureaucrat.hpp"

# define GRADE_TO_EXE_PP	5
# define GRADE_TO_SIGN_PP	25

class Bureaucrat;

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &name, const int gradeToExecute, const int gradeToSign, const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &obj);
	PresidentialPardonForm &operator = (const PresidentialPardonForm &obj);
	PresidentialPardonForm(const std::string &target);
	virtual ~PresidentialPardonForm();

private:
	virtual void	executeConcreteAction() const;
};

#endif //__PRESIDENTIAL_PARDON_FORM_H__

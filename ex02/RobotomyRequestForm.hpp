#ifndef __ROBOTOMY_REQUEST_FORM_H__
#define __ROBOTOMY_REQUEST_FORM_H__

#include "Bureaucrat.hpp"

# define GRADE_TO_EXE_RR	45
# define GRADE_TO_SIGN_RR	72

class Bureaucrat;

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &name, const int gradeToExecute, const int gradeToSign, const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &obj);
	RobotomyRequestForm &operator = (const RobotomyRequestForm &obj);
	RobotomyRequestForm(const std::string &target);
	virtual ~RobotomyRequestForm();

private:
	virtual void	executeConcreteAction() const;
};

#endif //__ROBOTOMY_REQUEST_FORM_H__

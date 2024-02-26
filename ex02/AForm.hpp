#ifndef __AFORM_H__
#define __AFORM_H__

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {
public:
	AForm();
	AForm(const std::string &name, const int gradeToExecute, const int gradeToSign, const std::string &target);
	AForm(const AForm &obj);
	AForm &operator = (const AForm &obj);
	virtual ~AForm();

	//accessor
	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeToExecute() const;
	int			getGradeToSign() const;
	std::string	getTarget() const;

	//func
	void	beSigned(const Bureaucrat &bur);
	void	execute(const Bureaucrat &bur) const;

	//throw
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class FormAlreadySigned : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class FormNotSigned : public std::exception {
	public:
		virtual const char* what() const throw();
	};

protected:
	virtual void	executeConcreteAction() const = 0;

private:
	std::string	name_;
	bool		isSigned_;
	int			gradeToExecute_;
	int			gradeToSign_;
	std::string	target_;
};

std::ostream &operator << (std::ostream &os, const AForm &form);

#endif //__AFORM_H__

#ifndef __FORM_H__
#define __FORM_H__

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
public:
	Form();
	Form(const std::string &name, int gradeToExecute, int gradeToSign);
	Form(const Form &obj);
	Form &operator = (const Form &obj);
	~Form();

	//accessor
	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeToExecute() const;
	int			getGradeToSign() const;

	//func
	//「Bureaucrat」をパラメーターとして受け取り、
	// その成績がgetGradeToSign以上ならフォームのisSigned_をtrueにする
	void		beSigned(const Bureaucrat &bur);

	//throw
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	std::string	name_;
	bool		isSigned_;
	int			gradeToExecute_;
	int			gradeToSign_;
};

std::ostream &operator << (std::ostream &os, const Form &form);

#endif //__FORM_H__

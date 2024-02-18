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
	// その成績がgetGradeToSign以上ならフォームの_isSignedをtrueにする
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
	std::string const	_name;
	bool				_isSigned;
	int const			_gradeToExecute;
	int const			_gradeToSign;
};

std::ostream &operator << (std::ostream &c_out, const Form &form);

#endif //__FORM_H__

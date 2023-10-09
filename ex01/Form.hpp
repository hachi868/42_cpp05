#ifndef __FORM_H__
#define __FORM_H__


class Form {
public:
	Form();
	Form(const std::string &name, int gradeToExecute, int gradeToSign);
	Form(const Form &obj);
	Form &operator = (const Form &obj);
	virtual ~Form();
	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeToExecute() const;
	int			getGradeToSign() const;
	void		beSigned(const Bureaucrat &bur);
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
	bool				_signed;
	int const			_gradeToExecute;
	int const			_gradeToSign;
};

std::ostream &operator << (std::ostream &os, const Form &form);


#endif //__FORM_H__

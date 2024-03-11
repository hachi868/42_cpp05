#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name_("default"), isSigned_(false), gradeToExecute_(Bureaucrat::gradeMin_), gradeToSign_(Bureaucrat::gradeMin_)
{
	std::cout << Bureaucrat::DEBUG << "[Form] constructor called (default)" << Bureaucrat::RESET << std::endl;
}

Form::Form(const std::string &name, const int gradeToExecute, const int gradeToSign)
	: name_(name), isSigned_(false), gradeToExecute_(gradeToExecute), gradeToSign_(gradeToSign)
{
	std::cout << Bureaucrat::DEBUG << "[Form] constructor called (name, gradeToExecute, gradeToSign)" << Bureaucrat::RESET << std::endl;
	if (gradeToExecute < Bureaucrat::gradeMax_ || gradeToSign < Bureaucrat::gradeMax_)
		throw GradeTooHighException();
	if (gradeToExecute > Bureaucrat::gradeMin_ || gradeToSign > Bureaucrat::gradeMin_)
		throw GradeTooLowException();
}

Form::Form(const Form &obj) : name_(obj.name_), isSigned_(obj.isSigned_), gradeToExecute_(obj.gradeToExecute_), gradeToSign_(obj.gradeToSign_)
{
	std::cout << Bureaucrat::DEBUG << "[Form] copy constructor called" << Bureaucrat::RESET << std::endl;
}

Form &Form::operator = (const Form &obj)
{
	std::cout << Bureaucrat::DEBUG << "[Form] assignation operator called" << Bureaucrat::RESET << std::endl;
	if (this != &obj)
		this->isSigned_ = obj.isSigned_;
	return (*this);
}

Form::~Form()
{
	std::cout << Bureaucrat::DEBUG << "[Form] destructor called" << Bureaucrat::RESET << std::endl;
}

//accessor
std::string	Form::getName() const
{
	return (this->name_);
}

bool		Form::getIsSigned() const
{
	return (this->isSigned_);
}

int			Form::getGradeToExecute() const
{
	return (this->gradeToExecute_);
}

int			Form::getGradeToSign() const
{
	return (this->gradeToSign_);
}

//wrapper functionのBureaucrat::signForm()のtry内で呼び出す
void		Form::beSigned(const Bureaucrat &bur)
{
	if (this->isSigned_)
		throw Form::FormAlreadySigned();
	if (bur.getGrade() > this->gradeToSign_)
		throw Form::GradeTooLowException();
	this->isSigned_ = true;
}

//throw
const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char* Form::FormAlreadySigned::what() const throw()
{
	return ("already signed");
}

//operator
std::ostream &operator << (std::ostream &os, const Form &form)
{
	os << Bureaucrat::STATE << "name_: " << form.getName() << " / isSigned_: " << form.getIsSigned() << " / gradeToExecute_: " << form.getGradeToExecute() << " / gradeToSign_: " << form.getGradeToSign() << Bureaucrat::RESET;
	return (os);
}
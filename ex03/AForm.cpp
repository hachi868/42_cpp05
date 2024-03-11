#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name_("default"), isSigned_(false), gradeToExecute_(Bureaucrat::gradeMin_), gradeToSign_(Bureaucrat::gradeMin_), target_("default")
{
	std::cout << Bureaucrat::DEBUG << "[AForm] constructor called (default)" << Bureaucrat::RESET << std::endl;
}

AForm::AForm(const std::string &name, const int gradeToExecute, const int gradeToSign, const std::string &target)
	: name_(name), isSigned_(false), gradeToExecute_(gradeToExecute), gradeToSign_(gradeToSign), target_(target)
{
	std::cout << Bureaucrat::DEBUG << "[AForm] constructor called (name, gradeToExecute, gradeToSign)" << Bureaucrat::RESET << std::endl;
	if (gradeToExecute < Bureaucrat::gradeMax_ || gradeToSign < Bureaucrat::gradeMax_)
		throw GradeTooHighException();
	if (gradeToExecute > Bureaucrat::gradeMin_ || gradeToSign > Bureaucrat::gradeMin_)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &obj) : name_(obj.name_), isSigned_(obj.isSigned_), gradeToExecute_(obj.gradeToExecute_), gradeToSign_(obj.gradeToSign_), target_(obj.target_)
{
	std::cout << Bureaucrat::DEBUG << "[AForm] copy constructor called" << Bureaucrat::RESET << std::endl;
}

AForm &AForm::operator = (const AForm &obj)
{
	std::cout << Bureaucrat::DEBUG << "[AForm] assignation operator called" << Bureaucrat::RESET << std::endl;
	if (this != &obj)
		this->isSigned_ = obj.isSigned_;
	return (*this);
}

AForm::~AForm()
{
	std::cout << Bureaucrat::DEBUG << "[AForm] destructor called" << Bureaucrat::RESET << std::endl;
}

//accessor
std::string	AForm::getName() const
{
	return (this->name_);
}

bool		AForm::getIsSigned() const
{
	return (this->isSigned_);
}

int			AForm::getGradeToExecute() const
{
	return (this->gradeToExecute_);
}

int			AForm::getGradeToSign() const
{
	return (this->gradeToSign_);
}

std::string	AForm::getTarget() const
{
	return (this->target_);
}

//wrapper functionのBureaucrat::signForm()のtry内で呼び出す
void		AForm::beSigned(const Bureaucrat &bur)
{
	if (this->isSigned_)
		throw AForm::FormAlreadySigned();
	if (bur.getGrade() > this->gradeToSign_)
		throw AForm::GradeTooLowException();
	this->isSigned_ = true;
}

void	AForm::execute(const Bureaucrat &bur) const
{
	if (!this->isSigned_)
		throw AForm::FormNotSigned();
	if (bur.getGrade() > this->gradeToExecute_)
		throw AForm::GradeTooLowException();
	executeConcreteAction();
}

//throw
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char* AForm::FormAlreadySigned::what() const throw()
{
	return ("already signed");
}

const char* AForm::FormNotSigned::what() const throw()
{
	return ("form is not signed");
}

//operator
std::ostream &operator << (std::ostream &os, const AForm &form)
{
	os << Bureaucrat::STATE << "name_: " << form.getName() << " / isSigned_: " << form.getIsSigned() << " / gradeToExecute_: " << form.getGradeToExecute() << " / gradeToSign_: " << form.getGradeToSign() << Bureaucrat::RESET;
	return (os);
}
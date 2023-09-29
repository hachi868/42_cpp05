#include "Bureaucrat.hpp"

//try
//{
///* do some stuff with bureaucrats */
//}
//catch (std::exception & e)
//{
///* handle exception */
//}

Bureaucrat::Bureaucrat(const std::string &name, int &grade) : _name(name)
{
	if (Bureaucrat::judgeGrade(grade))
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{

}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &obj)
{

}

Bureaucrat::~Bureaucrat()
{

}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::upGrade(int ranks)
{
	this->_grade += ranks;
	if (this->_grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::downGrade(int ranks)
{
	this->_grade -= ranks;
	if (this->_grade < 1)
		throw GradeTooLowException();
}

bool	Bureaucrat::judgeGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (true);
}

const char* Bureaucrat::GradeTooHighException::what() const throw();
{
	return ("GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw();
{
	return ("GradeTooLowException");
}

std::ostream &operator << (std::ostream &c_out, const Bureaucrat &bur)
{
	c_out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
	return (c_out);
}

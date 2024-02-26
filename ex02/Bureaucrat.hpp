#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include "AForm.hpp"
class AForm;

# define GRADE_MAX	1
# define GRADE_MIN	150

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, const int grade);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat &operator = (const Bureaucrat &obj);
	~Bureaucrat();

	//accessor
	std::string	getName() const;
	int			getGrade() const;
	void		upGrade(int ranks);
	void		downGrade(int ranks);

	//func
	void	signForm(AForm &form);
	void	executeForm(const AForm &form)

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
	int	grade_;
};

std::ostream &operator << (std::ostream &os, const Bureaucrat &bur);

//標準例外クラス
//namespace std {
//	class exception {
//	public:
//		exception() noexcept = default;
//		exception(const exception&) noexcept = default;
//		exception& operator=(const exception&) noexcept = default;
//		virtual ~exception() noexcept = default;
//
//		virtual const char* what() const noexcept {
//			return "An exception occurred.";
//		}
//	};
//}
// noexcept その関数が例外を投げないことを示す
// what() 例外を説明するエラーメッセージのための関数

#endif //__BUREAUCRAT_H__

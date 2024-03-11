#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, const int grade);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat &operator = (const Bureaucrat &obj);
	~Bureaucrat();

	const static int gradeMax_;
	const static int gradeMin_;

	const static std::string RESET;
	const static std::string DEBUG;
	const static std::string STATE;
	const static std::string ALERT;
	const static std::string MSG;

	//accessor
	std::string	getName() const;
	int			getGrade() const;
	void		upGrade(int ranks);
	void		downGrade(int ranks);

	//throw
	//Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
	//either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	const std::string	name_;
	int					grade_;
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

#endif //BUREAUCRAT_HPP

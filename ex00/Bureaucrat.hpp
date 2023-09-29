#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

class Bureaucrat {
public:
	Bureaucrat(const std::string &name, int &grade);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat &operator = (const Bureaucrat &obj);
	~Bureaucrat();
	std::string	getName() const;
	int	getGrade() const;
	void	upGrade(int ranks);
	void	downGrade(int ranks);
	bool	judgeGrade(int grade);
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	Bureaucrat();
	std::string	_name;
	int	_grade;
};

std::ostream &operator << (std::ostream &os, const Bureaucrat &bur);

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

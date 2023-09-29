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

private:
	Bureaucrat();
	std::string	_name;
	int	_grade;
};

std::ostream &operator << (std::ostream &os, const Bureaucrat &bur);

#endif //__BUREAUCRAT_H__

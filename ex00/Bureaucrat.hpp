#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string name);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat &operator = (const Bureaucrat &obj);
	virtual ~Bureaucrat();
	std::string	getName() const;
	int	getGrade() const;
	void	upGrade(int ranks);
	void	downGrade(int ranks);

private:
	std::string	_name;
	int	_grade;
};

std::ostream &operator << (std::ostream &os, const Bureaucrat &bur);

#endif //__BUREAUCRAT_H__
